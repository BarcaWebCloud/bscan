/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 *    Project: BSCAN to scanner MotherBoards. CPU, Memory Ram, SO and more
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://project-barca.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#include "platform.h"
#ifdef BSCAN_WINDOWS
#include "hwares/scan_monitor.h"
#include <iostream>   
#include <string>  
#include <windows.h>    
#include <stdio.h>  
#include <vector>
#include <cstdio>
#include <stdlib.h>  

namespace bscan {

  std::vector<Monitor> getAllMonitors() {
    MONITORINFO target = { sizeof(target) };
    target.cbSize = sizeof(MONITORINFO);
    HMONITOR hMon = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY);
    GetMonitorInfo(hMon, &target);
    DISPLAY_DEVICE dd;
    ZeroMemory(&dd, sizeof(dd));
    dd.cb = sizeof(dd);

    std::vector<Monitor> monitors;

    for (int i = 0; EnumDisplayDevices(NULL, i, &dd, 0); i++) {
      monitors.push_back(Monitor());

      DISPLAY_DEVICE dd2;
      ZeroMemory(&dd2, sizeof(dd2));
      dd2.cb = sizeof(dd2);
      EnumDisplayDevices(dd.DeviceName, 0, &dd2, 0);
      
      monitors.back()._model = dd2.DeviceID;
      monitors.back()._key = dd2.DeviceKey;
      monitors.back()._name = dd2.DeviceName;
    }


    return monitors;
  }

};

#endif  // END BSCAN_WINDOWS