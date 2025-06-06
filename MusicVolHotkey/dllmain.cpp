#include "pch.h"
#include <Windows.h>
#include "sUserData.h"

DWORD WINAPI dll_thread(HMODULE hDll) {
    while (true) {
        if ((GetAsyncKeyState('B') & 0x8000) &&
            (GetAsyncKeyState('G') & 0x8000)) {
            const auto user_data = sUserData::Get();

            if (GetAsyncKeyState('0') & 0x8000) {
                if (user_data->at<u8>(0x104) != 100) {
                    user_data->at<u8>(0x104) = 100;
                }
                else {
                    user_data->at<u8>(0x104) = 0;
                }
            }
            else if (GetAsyncKeyState('9') & 0x8000) {
                user_data->at<u8>(0x104) = 90;
            }
            else if (GetAsyncKeyState('8') & 0x8000) {
                user_data->at<u8>(0x104) = 80;
            }
            else if (GetAsyncKeyState('7') & 0x8000) {
                user_data->at<u8>(0x104) = 70;
            }
            else if (GetAsyncKeyState('6') & 0x8000) {
                user_data->at<u8>(0x104) = 60;
            }
            else if (GetAsyncKeyState('5') & 0x8000) {
                user_data->at<u8>(0x104) = 50;
            }
            else if (GetAsyncKeyState('4') & 0x8000) {
                user_data->at<u8>(0x104) = 40;
            }
            else if (GetAsyncKeyState('3') & 0x8000) {
                user_data->at<u8>(0x104) = 30;
            }
            else if (GetAsyncKeyState('2') & 0x8000) {
                user_data->at<u8>(0x104) = 20;
            }
            else if (GetAsyncKeyState('1') & 0x8000) {
                user_data->at<u8>(0x104) = 10;
            }
            else if (GetAsyncKeyState(VK_OEM_MINUS) & 0x8000) {
                user_data->at<u8>(0x104) = 0;
            }

            Sleep(200);
        }
        Sleep(20);
    }
}


BOOL APIENTRY DllMain(HMODULE hDll,
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