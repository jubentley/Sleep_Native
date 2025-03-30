// Sleep ~ Justin Bentley ~ 2025

// Trigger Monitor Down Power State

#include <Windows.h>

#pragma comment(linker, "/SUBSYSTEM:WINDOWS") // use winmain, not main, echo off

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Sleep(1000);
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
    return 0;
}
