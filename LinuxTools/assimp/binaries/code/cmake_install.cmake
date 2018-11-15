# Install script for directory: /media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/binaries/code/libassimp.so.4.1.0"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/binaries/code/libassimp.so.4"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/binaries/code/libassimp.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/anim.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/ai_assert.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/camera.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/color4.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/color4.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/binaries/code/../include/assimp/config.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/defs.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Defines.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/cfileio.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/light.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/material.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/material.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/matrix3x3.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/matrix3x3.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/matrix4x4.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/matrix4x4.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/mesh.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/postprocess.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/quaternion.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/quaternion.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/scene.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/metadata.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/texture.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/types.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/vector2.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/vector2.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/vector3.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/vector3.inl"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/version.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/cimport.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/importerdesc.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Importer.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/IOStream.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/IOSystem.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Logger.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/LogStream.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/NullLogger.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/cexport.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Exporter.hpp"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/DefaultIOStream.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/SceneCombiner.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

