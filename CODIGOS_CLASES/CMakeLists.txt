project( JUEGO_HEAD_SOCCER C CXX)

if(POLICY CMP0043)
   cmake_policy(SET CMP0043 OLD)
endif()

###################################################
# ALMACENA LOS ARCHIVOS .CPP EN SourceFiles
# ALMACENA LOS ARCHIVOS .CPP EN HeaderFiles 
###################################################
file( GLOB SourceFiles "*.cpp" "*.c" )
file( GLOB HeaderFiles "*.hpp" "*.h"  )		

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(LIBRARIES "")

#"Debug;Release" 
###################################################
# Set suffix execute file
###################################################
include( CheckTypeSize )

check_type_size( "void*" SIZE_OF_VOID_POINTER )
message(STATUS "SIZE_OF_VOID_POINTER = ${SIZE_OF_VOID_POINTER}")

set(  _ARCH "" )
if( SIZE_OF_VOID_POINTER EQUAL 4 )
  set( _ARCH x86 )
else( SIZE_OF_VOID_POINTER EQUAL 4 )
  if( SIZE_OF_VOID_POINTER EQUAL 8 )
    set( _ARCH x64 )
  endif( SIZE_OF_VOID_POINTER EQUAL 8 )
endif( SIZE_OF_VOID_POINTER EQUAL 4 )

set( _COMPILER "" )
if( WIN32 )
  if( MSVC )
    add_definitions( -D_CRT_SECURE_NO_WARNINGS )
	  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
    if( MSVC80 )
      set( _COMPILER vc80 )
    endif( MSVC80 )
    if( MSVC90 )
      set( _COMPILER vc90 )
    endif( MSVC90 )
    if( MSVC10 )
      set( _COMPILER vc10 )
    endif( MSVC10 )
	if( MSVC11 )
      set( _COMPILER vc11 )
    endif( MSVC11 )
	if( MSVC12 )
      set( _COMPILER vc12 )
    endif( MSVC12 )
	if( MSVC13 )
      set( _COMPILER vc13 )
    endif( MSVC13 )
	if( MSVC15 )
      set( _COMPILER vc15 )
    endif( MSVC15 )
  endif( MSVC )

  if( MINGW )
    set( _COMPILER mingw )
  endif( MINGW )
else( WIN32 )
  if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
    set( _COMPILER gcc )
  endif( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
endif( WIN32 )

message(STATUS "ARCH = ${_ARCH}")

#########################################################
# FIND GLFW
#########################################################
# Requires GLFW libraries
set( GLFW_SDK_PATH  ${CMAKE_SOURCE_DIR}/dependencies/glfw_sdk )

if(GLFW_SDK_PATH)
  set( GLFW_INCLUDE_DIRS ${GLFW_SDK_PATH}/include )
	file( GLOB GLFW_SRC_DIRS "${GLFW_SDK_PATH}/include/*.cpp" "${GLFW_SDK_PATH}/include/*.c" )

  if( WIN32 )

		if( MSVC )
			set( GLFW_LIBRARY_DIRS ${GLFW_SDK_PATH}/lib/x64/windows/vc14 )
			set( GLFW_LIBRARY_RELEASE optimized ${GLFW_LIBRARY_DIRS}/Release/glfw3.lib	)
			set( GLFW_LIBRARY_DEBUG debug ${GLFW_LIBRARY_DIRS}/Debug/glfw3.lib	)	
		endif( MSVC )

		if( MINGW )
			set( GLFW_LIBRARY_DIRS ${GLFW_SDK_PATH}/lib/x64/windows/mingw )
			set( GLFW_LIBRARY_RELEASE optimized ${GLFW_LIBRARY_DIRS}/libglfw3.a	)
			set( GLFW_LIBRARY_DEBUG debug ${GLFW_LIBRARY_DIRS}/libglfw3.a	)
		endif( MINGW )

  else( WIN32 ) #Testing  to linux

   	find_library(MATH_LIBRARY m)
    if( MATH_LIBRARY )
      message(STATUS "MATH_LIBRARIES = ${MATH_LIBRARY}")
      list(APPEND LIBRARIES "${MATH_LIBRARY}")
    endif()

    find_package(X11 REQUIRED)
    if( X11_FOUND )
      message(STATUS "X11_FOUND = ${X11_FOUND}")
      message(STATUS "X11_INCLUDE_DIR = ${X11_INCLUDE_DIR}")
      message(STATUS "X11_LIBRARIES = ${X11_LIBRARIES}")
      include_directories(${X11_INCLUDE_DIR})
      list(APPEND LIBRARIES "${X11_LIBRARIES}" )
    endif()

    find_package(Threads REQUIRED)
    if (CMAKE_THREAD_LIBS_INIT)
      message(STATUS "CMAKE_THREAD_LIBS_INIT = ${CMAKE_THREAD_LIBS_INIT}")
      list(APPEND LIBRARIES "${CMAKE_THREAD_LIBS_INIT}")
    endif()

    find_library(RT_LIBRARY REQUIRED)
    if (RT_LIBRARY)
      message(STATUS "RT_LIBRARY = ${RT_LIBRARY}")
      list(APPEND LIBRARIES "${RT_LIBRARY}")
    endif()

    if (CMAKE_DL_LIBS)
      message(STATUS "CMAKE_DL_LIBS = ${CMAKE_DL_LIBS}")
      list(APPEND LIBRARIES "${CMAKE_DL_LIBS}")
    endif()

    set( GLFW_LIBRARY_DIRS ${GLFW_SDK_PATH}/lib/x64/linux )
	  set( GLFW_LIBRARY_RELEASE optimized ${GLFW_LIBRARY_DIRS}/libglfw3.a	)
	  set( GLFW_LIBRARY_DEBUG debug ${GLFW_LIBRARY_DIRS}/libglfw3.a	)
  endif( WIN32 )

	message(STATUS "GLFW_INCLUDE_DIRS = ${GLFW_INCLUDE_DIRS}" )
	message(STATUS "GLFW_LIBRARY_DIRS = ${GLFW_LIBRARY_DIRS}" )
	message(STATUS "GLFW_LIBRARY_RELEASE = ${GLFW_LIBRARY_RELEASE}" )
	message(STATUS "GLFW_LIBRARY_DEBUG = ${GLFW_LIBRARY_DEBUG}" )
		
	set(INFO_USE_GLFW_SDK "Yes")
	message( STATUS "\nINFO_USE_GLFW_SDK => YES" )

else(GLFW_SDK_PATH)
		set(INFO_USE_GLFW_SDK "\nNo (SDK not found)")
		message("\nINFO_USE_GLFW_SDK => NO (SDK not found)" )
endif(GLFW_SDK_PATH)   	

message(STATUS "LIBRARIES = ${LIBRARIES}" )

###################################################
# Set suffix : compiler  + architecture
###################################################
set( BIN_PATH_SUFIX _${_COMPILER}_${_ARCH} )

include_directories( ${GLFW_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME}${BIN_PATH_SUFIX} 
    ${HeaderFiles}
	  ${SourceFiles}

	  ${GLFW_SRC_DIRS}
)

target_link_libraries( ${PROJECT_NAME}${BIN_PATH_SUFIX} 
	${GLFW_LIBRARY_RELEASE}
	${GLFW_LIBRARY_DEBUG}
  ${LIBRARIES}
)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin )
set(RUNTIME_OUTPUT_BINARY ${CMAKE_SOURCE_DIR}/bin )

set_target_properties( 
${PROJECT_NAME}${BIN_PATH_SUFIX}  PROPERTIES DEBUG_POSTFIX d 
                RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release"
                RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug" )
