#include "pch.h"
#include <Windows.h>
#include "sUserData.h"

DWORD WINAPI dll_thread(HMODULE hDll) {
    while (true) {
        if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) &&
            (GetAsyncKeyState(VK_SHIFT) & 0x8000) &&
            (GetAsyncKeyState('B') & 0x8000)) {
            const auto user_data = sUserData::Get();

            if (user_data->at<u8>(0x104) == 0) {
                user_data->at<u8>(0x104) = 20;
            }
            else if (user_data->at<u8>(0x104) == 20) {
                user_data->at<u8>(0x104) = 40;
            }
            else if (user_data->at<u8>(0x104) == 40) {
                user_data->at<u8>(0x104) = 60;
            }
            else if (user_data->at<u8>(0x104) == 60) {
                user_data->at<u8>(0x104) = 80;
            }
            else if (user_data->at<u8>(0x104) == 80) {
                user_data->at<u8>(0x104) = 100;
            }
            else if (user_data->at<u8>(0x104) == 100) {
                user_data->at<u8>(0x104) = 0;
            }
            else if ((user_data->at<u8>(0x104) != 0) 
                && (user_data->at<u8>(0x104) != 20) 
                && (user_data->at<u8>(0x104) != 40) 
                && (user_data->at<u8>(0x104) != 60) 
                && (user_data->at<u8>(0x104) != 80) 
                && (user_data->at<u8>(0x104) != 100)) {
                user_data->at<u8>(0x104) = 0;
            }
           
            Sleep(200);
        }
        Sleep(20);
    }
}


BOOL APIENTRY DllMain( HMODULE hDll,
                       DWORD  dwReason,
                       LPVOID lpReserved
                     )
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)dll_thread, hDll, 0, NULL);
    }
    return TRUE;
}

