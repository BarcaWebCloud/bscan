add_library(BScan
        scan_battery.cpp
        scan_cpu.cpp
        scan_gpu.cpp
        scan_ram.cpp
        scan_os.cpp
        scan_mainboard.cpp
        scan_temperature.cpp
        scan_bios.cpp
        scan_disk.cpp
        scan_net.cpp
        scan_browser.cpp
        scan_datasource.cpp
        # apple OS
        apple/scan_battery.cpp
        apple/scan_cpu.cpp
        apple/scan_gpu.cpp
        apple/scan_ram.cpp
        apple/scan_os.cpp
        apple/scan_mainboard.cpp
        apple/scan_disk.cpp
        # linux OS
        linux/scan_battery.cpp
        linux/scan_cpu.cpp
        linux/scan_gpu.cpp
        linux/scan_ram.cpp
        linux/scan_os.cpp
        linux/scan_mainboard.cpp
        linux/scan_net.cpp
        linux/scan_disk.cpp
        # windows OS
        windows/scan_battery.cpp
        windows/scan_cpu.cpp
        windows/scan_gpu.cpp
        windows/scan_temperature.cpp
        windows/scan_ram.cpp
        windows/scan_bios.cpp
        windows/scan_os.cpp
        windows/scan_mainboard.cpp
        windows/scan_net.cpp
        windows/scan_disk.cpp
        windows/scan_browser.cpp
        windows/scan_net.cpp
        windows/scan_datasource.cpp
        )

add_library(${PROJECT_NAME}::BScan ALIAS BScan)