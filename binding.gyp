{
  "targets": [
    {
      "target_name": "bscan",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions",  "-std=c++17" ],
      "cflags_cc": [ "-std=c++17" ],
      # sources:  arquivoc C/C++  a ser compilados
      "sources": [
        "./src/libs/info/scan_battery.cpp",
        "./src/libs/info/scan_cpu.cpp",
        "./src/libs/info/scan_disk.cpp",
        "./src/libs/info/scan_gpu.cpp",
        "./src/libs/info/scan_mainboard.cpp",
        "./src/libs/info/scan_os.cpp",
        "./src/libs/info/scan_ram.cpp",
        "./src/libs/info/scan_system.cpp",
        # to apple OS
        "./src/libs/info/apple/scan_battery.cpp",
        "./src/libs/info/apple/scan_cpu.cpp",
        "./src/libs/info/apple/scan_disk.cpp",
        "./src/libs/info/apple/scan_gpu.cpp",
        "./src/libs/info/apple/scan_mainboard.cpp",
        "./src/libs/info/apple/scan_os.cpp",
        "./src/libs/info/apple/scan_ram.cpp",
        # to linux OS
        "./src/libs/info/linux/scan_battery.cpp",
        "./src/libs/info/linux/scan_cpu.cpp",
        "./src/libs/info/linux/scan_disk.cpp",
        "./src/libs/info/linux/scan_gpu.cpp",
        "./src/libs/info/linux/scan_mainboard.cpp",
        "./src/libs/info/linux/scan_os.cpp",
        "./src/libs/info/linux/scan_ram.cpp",
        # to windows OS
        "./src/libs/info/windows/scan_battery.cpp",
        "./src/libs/info/windows/scan_cpu.cpp",
        "./src/libs/info/windows/scan_disk.cpp",
        "./src/libs/info/windows/scan_gpu.cpp",
        "./src/libs/info/windows/scan_mainboard.cpp",
        "./src/libs/info/windows/scan_os.cpp",
        "./src/libs/info/windows/scan_ram.cpp",
        # index bscan
        "./src/libs/info/bscan.cpp",
      ],
      #  localizando include
      "include_dirs": [
        "include",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'conditions': [
        ['OS=="linux"', 
          {
            'defines': [
              
            ]
          }
        ],
        ['OS=="win"', 
          {
            'msvs_settings': {
              'VCCLCompilerTool': {
                "AdditionalOptions": [
                  "-std:c++17",
                ], 
                'WarningLevel': 4,
                'BufferSecurityCheck': 'true',
                'WarnAsError': 'false',
                'ExceptionHandling': 1,
                'DisableSpecificWarnings': [
                    4100, 4127, 4201, 4244, 4267, 4506, 4611, 4714, 4512
                ]
              },
              'VCLibrarianTool': {
              },
              'VCLinkerTool': {
                  'GenerateDebugInformation': 'true',
                  "AdditionalOptions": [ '/ignore:4267' ], 
                  'DisableSpecificWarnings': [ '4990', '4530' ],
              },
          },
          'defines': [
            'WINDOWS_SPECIFIC_DEFINE',
          ],
          }
        ],
        ['OS=="mac"', 
          {
            'xcode_settings': {
              'OTHER_LDFLAGS': [
                  '-fsanitize=address', 
                  '-Wl,-bind_at_load'
              ], 
              'GCC_ENABLE_CPP_RTTI': 'YES',
              'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
              'MACOSX_DEPLOYMENT_TARGET':'10.8',
              'CLANG_CXX_LIBRARY': 'libc++',
              'CLANG_CXX_LANGUAGE_STANDARD':'c++17',
              'GCC_VERSION': 'com.apple.compilers.llvm.clang.1_0'
            },
            'defines': [
              'NON_WINDOWS_DEFINE',
            ],
          }
        ],
      ]
    }
  ]
}