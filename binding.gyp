{
  "targets": [
    {
      "target_name": "bscan",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
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
      ],
      #  localizando node-api
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}