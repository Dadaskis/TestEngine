# Install script for directory: /media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/src/Bullet3OpenCL

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
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBullet3OpenCL_clew.so.2.87"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBullet3OpenCL_clew.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3OpenCL/libBullet3OpenCL_clew.so.2.87"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3OpenCL/libBullet3OpenCL_clew.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBullet3OpenCL_clew.so.2.87"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBullet3OpenCL_clew.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/LinearMath:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3Dynamics:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3Collision:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3Geometry:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3Common:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bullet" TYPE DIRECTORY FILES "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/src/Bullet3OpenCL" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/\\.svn$" EXCLUDE REGEX "/CMakeFiles$" EXCLUDE)
endif()

