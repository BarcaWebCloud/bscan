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
# Barca, Inc., Vitória/ES, BRA |  email: opensource@barca.com  | GitHub: @BarcaWebCloud

cmake_minimum_required(VERSION 3.16)
project(bscan VERSION 0.2.0 DESCRIPTION "A library for collecting information about a computing device's Hardware & Software" HOMEPAGE_URL "https://store.barca.com/overview/modules/bscan" LANGUAGES CXX C)

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
  set(CMAKE_CXX_FLAGS "-utf-8")
  foreach(def IN ITEMS
    -D_HAS_EXCEPTIONS=0
    -DWIN32_LEAN_AND_MEAN
    -DNOMINMAX
    -D_CRT_SECURE_NO_WARNINGS)
      add_definitions(${def})
  endforeach()
  
  foreach(dir IN ITEMS
    "$ENV{USERPROFILE}\\AppData\\Local\\Temp\\${PROJECT_NAME}jhkyo"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\bin"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\cmd"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\cache"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\lib"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\logs"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\etc"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\etc\\scripts"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\etc\\profile"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\etc\\ssh"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage\\cache"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\storage\\mamutedb"
    "$ENV{USERPROFILE}\\AppData\\Local\\Barca\\packages\\${PROJECT_NAME}\\${PROJECT_VERSION}\\data"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}-v${PROJECT_VERSION}\\win32"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}-v${PROJECT_VERSION}\\win32\\cache"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}-v${PROJECT_VERSION}\\win32\\bin"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}-v${PROJECT_VERSION}\\win32\\lib"
    "$ENV{USERPROFILE}\\.bwc\\pkgs\\${PROJECT_NAME}-v${PROJECT_VERSION}\\win32\\www")
      if (EXISTS ${dir})
        message(STATUS "directory exist")
      else()
        make_directory(${dir})
      endif()
  endforeach()
  FILE(WRITE ${PROJECT_SOURCE_DIR}/include/bscan.config.h.in
    "#ifndef CONFIG_H_IN\n"
    "#define CONFIG_H_IN\n"
    "#define PROJECT_NAME \"@PROJECT_NAME@\"\n"
    "#define PROJECT_DESCRIPTION \"@PROJECT_DESCRIPTION@\"\n"
    "#define PROJECT_VERSION \"@PROJECT_VERSION@\"\n"
    "#define SYSTEM_PROCESSOR \"@CMAKE_SYSTEM_PROCESSOR@\"\n"
    "#define GENERATOR \"@CMAKE_GENERATOR@\"\n"
    "#define CXX_VERSION \"@CMAKE_CXX_STANDARD@\"\n"
    "#define C_VERSION \"@CMAKE_C_STANDARD@\"\n"
    "#define MINIMUM_VERSION \"@CMAKE_MINIMUM_REQUIRED_VERSION@\"\n"
    "#define MINIMUM_VERSION \"@CMAKE_MINIMUM_REQUIRED_VERSION@\"\n"
    "#define PROJECT_VERSION_MAJOR \"@PROJECT_VERSION_MAJOR@\"\n"
    "#define URL_HOMEPAGE \"@HOMEPAGE_URL@\"\n"
    "#define SOURCE_PROJECT \"@PROJECT_SOURCE_DIR@\"\n"
    "#define SOURCE_BIN \"@CMAKE_CURRENT_BINARY_DIR@\"\n"
    "#define PLATFORM_NAME \"@CMAKE_SYSTEM_NAME@\"\n"
    "#define NINJA_OUTPUT_PATH_PREFIX \"@CMAKE_NINJA_OUTPUT_PATH_PREFIX@\"\n"
    "#define TYPE_BUILD \"@CMAKE_BUILD_TYPE@\"\n"
    "#endif // CONFIG_H_IN\n"
    )

  FILE(WRITE $ENV{USERPROFILE}/AppData/Local/Barca/packages/${PROJECT_NAME}/${PROJECT_VERSION}/etc/scripts/apps_installed.ps1
    "function Analyze( $p, $f) {\n"
    "  Get-ItemProperty $p |foreach {\n"
    "     if (($_.DisplayName) -or ($_.version)) {\n"
    "        [PSCustomObject]@{\n"
    "            From = $f;\n"
      
    "            Name = $_.DisplayName;\n"

    "            Version = $_.DisplayVersion;\n"

    "            Date = $_.InstallDate;\n"

    "            UrlHelp = $_.HelpLink;\n"

    "            UrlAbout= $_.URLInfoAbout;\n"

    "            UrlUpdate = $_.URLUpdateInfo;\n"

    "            Company = $_.Publisher;\n"

    "            Phone = $_.HelpTelephone;\n"

    "            Contact = $_.Contact;\n"

    "            Location= $_.InstallLocation;\n"

    "            Origin= $_.InstallSource;\n"

    "            VersionMajor= $_.VersionMajor;\n"

    "            VersionMinor= $_.VersionMinor;\n"

    "            Uninstall= $_.UninstallString;\n"

    "            Size = $_.EstimatedSize;\n"

    "            Readme = $_.Readme;\n"
    "        }\n"
    "    }\n"
    "  }\n"
    "}\n"
    "$s = @()\n"
    "$s += Analyze 'HKLM:\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\*' 64\n"
    "$s += Analyze 'HKLM:\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\*' 32\n"
    "$s | Sort-Object -Property Name |Export-csv $ENV{TEMP}\\binstalrkop\n"
    )

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

configure_file ("include/bscan.config.h.in" ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h @ONLY)
# check if header files exist in include directory
find_path(_check_include
          NAMES 
            platform.h,
            WMIwrapper.h,
            bscan.h,
            bscan.config.h.in,
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
            "swares/scan_datasource.h",
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