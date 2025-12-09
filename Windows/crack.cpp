#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <string>

#define ID 0x00007FF6852B1503 //You may need to change it. I used x64dbg to get it. 

DWORD ProcId = 0;

void Get_proces_id(const char* _proces_Name);

int main()
{
    const char* _process_name = "ckme.exe";
    Get_proces_id(_process_name);

    BYTE _byte_new = 0x75;

    HANDLE _process = OpenProcess(PROCESS_ALL_ACCESS, false, ProcId);
    if (_process == NULL) {
        std::cerr << "Error al abrir el proceso." << std::endl;
        return 1;
    }

    if (!WriteProcessMemory(_process, (LPVOID)ID, &_byte_new, sizeof(_byte_new), NULL)) {
        std::cerr << "Error al escribir en la memoria del proceso." << std::endl;
    }

    CloseHandle(_process);
    return 0;
}

void Get_proces_id(const char* _proces_Name) {
    PROCESSENTRY32W pe32;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create snapshot" << std::endl;
        return;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(hSnapshot, &pe32)) {
        do {

            char processName[260];
            WideCharToMultiByte(CP_ACP, 0, pe32.szExeFile, -1, processName, sizeof(processName), NULL, NULL);

            if (_stricmp(processName, _proces_Name) == 0) {
                ProcId = pe32.th32ProcessID;
                break;
            }
        } while (Process32NextW(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    std::cout << "Process ID: " << ProcId << std::endl;
}
