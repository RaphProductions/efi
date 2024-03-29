#ifndef EFI_PROTOCOLS_LOADED_IMAGE_H
#define EFI_PROTOCOLS_LOADED_IMAGE_H

#define EFI_LOADED_IMAGE_PROTOCOL_GUID {0x5b1b31a1,0x9562,0x11d2, {0x8e,0x3f,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

#define EFI_LOADED_IMAGE_PROTOCOL_VERSION 0x1000

typedef struct _EFI_LOADED_IMAGE_PROTOCOL EFI_LOADED_IMAGE_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD)(
	IN EFI_HANDLE ImageHandle
);

typedef struct _EFI_LOADED_IMAGE_PROTOCOL {
	UINT32 Revision;
	EFI_HANDLE ParentHandle;
	EFI_SYSTEM_TABLE *SystemTable;

	// Source location of the image
	EFI_HANDLE DeviceHandle;
	EFI_DEVICE_PATH_PROTOCOL *FilePath;
	VOID *Reserved;

	UINT32 LoadOptionsSize;
	VOID *LoadOptions;

	VOID *ImageBase;
	UINT64 ImageSize;
	EFI_MEMORY_TYPE ImageCodeType;
	EFI_MEMORY_TYPE ImageDataType;
	EFI_IMAGE_UNLOAD Unload;
} EFI_LOADED_IMAGE_PROTOCOL;

#endif /* EFI_PROTOCOLS_LOADED_IMAGE_H */
