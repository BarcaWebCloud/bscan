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
#include <filesystem>
#include "WMIwrapper.h"
#include "hwares/scan_net.h"
#include "utils/stringutils.h"

#include <windows.h>

#include <stdio.h>

#include <wbemidl.h>
#pragma comment(lib,"wbemuuid")
#include <iostream>
using namespace std;

namespace bscan {

char* BSTRtoChar(BSTR String) {
    int n, i;
    char* FinalChar;
    n = SysStringLen(String); // length of input
    FinalChar = (char*) malloc(n+1);
    for (i = 0; i < n; i++)
    {
        FinalChar[i] = (char) String[i];
    }
    FinalChar[i] = 0;
    return FinalChar;
}
std::vector<Net> getAllNets() {
  std::vector<Net> nets;
  std::vector<const wchar_t*> res{};

  int n, i;
  char* mychar;
  string net_name;
  string net_gateway;
  string net_ipaddress;
  string net_subnet;
  string net_mac;
  string net_dns;
  string net_db_path;
  string net_service_name;

  CoInitializeEx(0, 0);
  CoInitializeSecurity(0, -1, 0, 0, 0, 3, 0, 0, 0);
  IWbemLocator *locator = 0;
  CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (void **)&locator);
  IWbemServices * services = 0;
  wchar_t *name = L"root\\cimv2";
  if (SUCCEEDED(locator->ConnectServer(name, 0, 0, 0, 0, 0, 0, &services))){
    // get system information
    CoSetProxyBlanket(services, 10, 0, 0, 3, 3, 0, 0);
    wchar_t *language = L"WQL";
    wchar_t *query = L"SELECT * from Win32_NetworkAdapterConfiguration where IPEnabled ='TRUE'";
    IEnumWbemClassObject *e = 0;
    if (SUCCEEDED(services->ExecQuery(language, query, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 0, &e))){
      
      IWbemClassObject *object = 0;
      ULONG u = 0;
      // lets enumerate all data from this table
      while (e){
          e->Next(WBEM_INFINITE, 1, &object, &u);
          if (!u) break;//no more data,end enumeration
          VARIANT data;
          // network adapter name
          if (SUCCEEDED(object->Get(L"Caption", 0, &data, 0, 0))){
            if (V_VT(&data) == VT_BSTR)
              // convert BSTR to CHAR
              n = SysStringLen(data.bstrVal);
              mychar = (char*) malloc(n+1);
              mychar=BSTRtoChar(data.bstrVal);
              // split char
              std::string delimiter = "] ";
              std::vector<std::string> val = split(mychar, delimiter);
              net_name = val[1].c_str();

              nets.push_back(Net());
              nets.back()._name = net_name;
          }
          // default gateway (Router)
          if (SUCCEEDED(object->Get(L"DefaultIPGateway", 0, &data, 0, 0))) {
            //VT_ARRAY|VT_BSTR = 8200
            SAFEARRAY *safe = NULL;
            safe = V_ARRAY(&data);
            BSTR element;
            long i = 0;
            SafeArrayGetElement(safe, &i, (void*)&element);
            // convert BSTR to CHAR
            n = SysStringLen(element);
            mychar = (char*) malloc(n+1);
             
            mychar=BSTRtoChar(element);
            net_gateway = mychar;

            nets.back()._gateway = net_gateway;

          }
          // ip address
          if (SUCCEEDED(object->Get(L"IpAddress", 0, &data, 0, 0))){
            //Or if you don't want to use the SAFEARRAY method :))
            // convert BSTR to CHAR
            n = SysStringLen(((BSTR*)(data.parray->pvData))[0]);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(((BSTR*)(data.parray->pvData))[0]);

            net_ipaddress = mychar;
            nets.back()._ipAddress = net_ipaddress;
          }
          // subnet
          if (SUCCEEDED(object->Get(L"IPSubnet", 0, &data, 0, 0))){
            // convert BSTR to CHAR
            n = SysStringLen(((BSTR*)(data.parray->pvData))[0]);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(((BSTR*)(data.parray->pvData))[0]);

            net_subnet = mychar;
            nets.back()._subnet = net_subnet;
          }
          // MAC address
          if (SUCCEEDED(object->Get(L"MACAddress", 0, &data, 0, 0))){
            // convert BSTR to CHAR
            n = SysStringLen(data.bstrVal);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(data.bstrVal);
            net_mac = mychar;

            cout << "MAC: " << net_mac << endl;
            nets.back()._macAddress = net_mac;
          }
          //DNS HostName
          if (SUCCEEDED(object->Get(L"DNSHostName", 0, &data, 0, 0))){
            // convert BSTR to CHAR
            n = SysStringLen(data.bstrVal);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(data.bstrVal);
            net_dns = mychar;

            nets.back()._dnsHostname = net_dns;
          }
          // db Path
          if (SUCCEEDED(object->Get(L"DatabasePath", 0, &data, 0, 0))){
            // convert BSTR to CHAR
            n = SysStringLen(data.bstrVal);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(data.bstrVal);
            net_db_path = mychar;

            nets.back()._driverPath = net_db_path;
          }
          // service name
          if (SUCCEEDED(object->Get(L"ServiceName", 0, &data, 0, 0))){
            // convert BSTR to CHAR
            n = SysStringLen(data.bstrVal);
            mychar = (char*) malloc(n+1);
            mychar=BSTRtoChar(data.bstrVal);
            net_service_name = mychar;

            nets.back()._serviceName = net_service_name;
          }
          VariantClear(&data);
        }
      }
      else
        printf("error executing query!\n");
  }
  else
    printf("connection error!\n");

  services->Release();
  locator->Release();
  CoUninitialize();

  return nets;
}

};

#endif  // END BSCAN_WINDOWS
