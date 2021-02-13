#include "Header.h"

void ErasePEHeaderFromMemory()
{

    // ErasePEHeaderFromMemory will delete images prevint a successful image
    DWORD OldProtect = 0;

    // gets base
    char* pBaseAddr = (char*)GetModuleHandle(NULL);

  
    VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
        PAGE_READWRITE, &OldProtect);

    // delete the header
    ZeroMemory(pBaseAddr, 4096);
}



void SizeOfImage()
{
    __asm
    {
        mov eax, fs: [0x30]				// PEB
        mov eax, [eax + 0x0c]			 // PEB_LDR_DATA
        mov eax, [eax + 0x0c]			// InOrderModuleList
        mov dword ptr[eax + 20h], 20000h // SizeOfImage    
    }
}
