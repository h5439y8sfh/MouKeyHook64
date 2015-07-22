#if! defined(_STEALTH_MOUSE_HOOK_H_INCLUDED_)
#define _STEALTH_MOUSE_HOOK_H_INCLUDED_

// Include Files
#include <NTddk.h> 
//#include "ioctl.h" 


typedef NTSTATUS(__fastcall *mouinput)(void *a1, void *a2, void *a3, void *a4, void *a5);
typedef void(__fastcall *MouseServiceDpc)(PDEVICE_OBJECT mou, PMOUSE_INPUT_DATA a1, PMOUSE_INPUT_DATA a2, PULONG a3);

// Create Keyboard Hook Create.
NTSTATUS Mouse_Create(IN PDRIVER_OBJECT driverObject);
NTSTATUS Mouse_Close(IN PDRIVER_OBJECT driverObject);
NTSTATUS Mouse_Hook(IN PDRIVER_OBJECT driverObject);
NTSTATUS Mouse_UnHook(IN PDRIVER_OBJECT driverObject);


NTSTATUS Mouse_HookProc(IN PDEVICE_OBJECT DeviceObject,IN PIRP Irp);
NTSTATUS Mouse_IO_InternalIoctl(PDEVICE_OBJECT device, PIRP irp);

int GetMouseState(int key);
void SynthesizeMouse(PMOUSE_INPUT_DATA a1);


#endif//_STEALTH_MOUSE_HOOK_H_INCLUDED_
