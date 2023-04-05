#           Copyright (C) 2021 - 2023, Barca, Inc.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 2.0,
# as published by the Free Software Foundation.
#
# This program is also distributed with certain software (including
# but not limited to OpenSSL) that is licensed under separate terms,
# as designated in a particular file or component or in included license
# documentation.  The authors of BSCAN hereby grant you an additional
# permission to link the program and your derivative works with the
# separately licensed software.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License, version 2.0, for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# 
# Barca, Inc., Serra/ES, BRA |  email: opensource@barca.com  | GitHub: @BarcaWebCloud

cmake_minimum_required(VERSION 3.16)
project(bscan VERSION 0.1.9 DESCRIPTION "A library for collecting information about a computing device's Hardware & Software" HOMEPAGE_URL "https://store.barca.com/overview/modules/bscan" LANGUAGES CXX C)

message(STATUS "cmake version ${CMAKE_VERSION}\n\nproject: ${PROJECT_NAME}\nversion: ${PROJECT_VERSION}\ndescription: ${PROJECT_DESCRIPTION}\n${PROJECT_NAME}-api: https://api.bwc-${PROJECT_NAME}.com/v${PROJECT_VERSION_MAJOR}/")

# UNIX, LINUX, WIN32, WINDOWS_PHONE, APPLE, ANDROID, IOS and more...
if(UNIX)
  # minimum version cmake on linux
  cmake_minimum_required (VERSION 3.18)
  message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(WIN32)
  # minimum version cmake on windows
  cmake_minimum_required (VERSION 3.16)

  EXECUTE_PROCESS(COMMAND wmic os get version
    OUTPUT_VARIABLE OS_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
    RESULT_VARIABLE WMIC_RESULT
  )
  if(WMIC_RESULT EQUAL 0)
    string(REPLACE "\r" "" OS_VERSION "${OS_VERSION}")
    string(REPLACE "\n" "" OS_VERSION "${OS_VERSION}")
    string(REGEX MATCH "Version[ ]+([0-9\.]+)" V_NUM "${OS_VERSION}")
    message("BSCAN To Windows ${CMAKE_MATCH_1}")
  endif()

  # check generator makefile
  if(CMAKE_GENERATOR STREQUAL "MinGW Makefiles")
    message(WARNING "MinGW does not support wbem libraries for windows. It will probably not be possible to use some methods")
    if (EXISTS "C:/MinGW/bin/gcc.exe")
        set(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)
        set(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)
    else()
        message(WARNING "MinGW not found installed in default directory: 'C:/MinGW'")
    endif()
    
  elseif(CMAKE_GENERATOR STREQUAL "NMake Makefiles")
    message("to do")
  elseif(CMAKE_GENERATOR STREQUAL "MSYS Makefiles")
    message("to do")
  elseif(CMAKE_GENERATOR STREQUAL "Borland Makefiles")
    message("to do")
  endif()
  
  #set(CMAKE_GENERATOR_CC gcc)
  set(CMAKE_CXX_FLAGS "-utf-8")
  foreach(def IN ITEMS
    -D_HAS_EXCEPTIONS=0
    -DWIN32_LEAN_AND_MEAN
    -DNOMINMAX
    -D_CRT_SECURE_NO_WARNINGS)
      add_definitions(${def})
  endforeach()
  
  foreach(dir IN ITEMS
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\readme.md"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\cache"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\logs"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\logs\\${PROJECT_VERSION}.log"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage\\cache"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage\\${PROJECT_VERSION}.txt"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage\\db\\${PROJECT_VERSION}.db"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\settings"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\settings\\${PROJECT_VERSION}.default.conf"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\settings\\${PROJECT_VERSION}-preferences.conf"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}\\win32"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}\\win32\\v${PROJECT_VERSION}"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}\\win32\\v${PROJECT_VERSION}\\bin"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}\\win32\\v${PROJECT_VERSION}\\lib"
    "$ENV{USERPROFILE}\\.${PROJECT_NAME}\\win32\\v${PROJECT_VERSION}\\www")
      if (EXISTS ${dir})
        message(STATUS "directory exist")
      else()
        make_directory(${dir})
      endif()
  endforeach()

elseif(WINDOWS_PHONE)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(WINCE)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(WINRT)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(APPLE)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(IOS)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(GHSMULTI)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(CYGWIN)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(MINGW)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(MSVC)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(MSYS)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(ANDROID)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(LINUX)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(BSD)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.18)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
elseif(XCODE)
    # minimum version cmake on apple
    cmake_minimum_required (VERSION 3.14)
    message("BSCAN To ${CMAKE_SYSTEM_NAME}")
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

# check if header files exist in include directory
find_path(_check_include
          NAMES 
            platform.h,
            WMIwrapper.h,
            bscan.h,
            dirent.h,
            config.h,
            sqlite3.h,
            "utils/directory.h",
            "utils/string.h",
            "utils/stringutils.h",
            "utils/subprocess.h",
            # hardwares header
            "hwares/hwares.h",
            "hwares/scan_battery.h",
            "hwares/scan_cpu.h",
            "hwares/scan_cpuid.h",
            "hwares/scan_disk.h",
            "hwares/scan_gpu.h",
            "hwares/scan_mainboard.h",
            "hwares/scan_monitor.h",
            "hwares/scan_network.h",
            "hwares/scan_ram.h",
            # softwares header
            "swares/swares.h",
            "swares/scan_browser.h",
            "swares/scan_os.h",
            "swares/scan_system.h"
          PATHS "${CMAKE_SOURCE_DIR}/include"
          NO_DEFAULT_PATH)
if(_check_include)
    message(STATUS "OK check all files in include directory")
    include_directories(${PROJECT_SOURCE_DIR}/include/)
else()
    message(WARNING "NOT There was a problem trying to include the header files. There must be some file missing! \nFiles in include path: ${_check_include}")
endif()


add_subdirectory(src/libs/info)

add_executable(bscan index.cpp "include/bscan.h")

add_library(sqlite3 "src/libs/sqlite3/sqlite3.c")

if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND
    ${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER_EQUAL "8" AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS "9.1") OR
("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND
    ${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER_EQUAL "7" AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS "9"))
    target_link_libraries(BScan PUBLIC "stdc++fs")
endif()

target_link_libraries(bscan PUBLIC bscan::BScan)
target_link_libraries(bscan PRIVATE sqlite3)