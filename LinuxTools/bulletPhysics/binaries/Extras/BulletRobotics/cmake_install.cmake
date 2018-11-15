# Install script for directory: /media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/bullet" TYPE FILE FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsClientC_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsClientSharedMemory_C_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsClientSharedMemory2_C_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsDirectC_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsClientUDP_C_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/PhysicsClientTCP_C_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/SharedMemoryInProcessPhysicsC_API.h"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/Extras/BulletRobotics/../../examples/SharedMemory/SharedMemoryPublic.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBulletRobotics.so.2.87"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBulletRobotics.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/Extras/BulletRobotics/libBulletRobotics.so.2.87"
    "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/Extras/BulletRobotics/libBulletRobotics.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBulletRobotics.so.2.87"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libBulletRobotics.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/Extras/InverseDynamics:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/Extras/Serialize/BulletWorldImporter:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/Extras/Serialize/BulletFileLoader:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/BulletSoftBody:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/BulletDynamics:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/BulletCollision:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/BulletInverseDynamics:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/LinearMath:/media/dadaskis/E210CC0110CBDAA5/C++_Projects/TestEngine/LinuxTools/bulletPhysics/binaries/src/Bullet3Common:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

