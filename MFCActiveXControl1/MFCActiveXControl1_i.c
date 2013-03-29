

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Tue Mar 26 16:53:23 2013
 */
/* Compiler settings for MFCActiveXControl1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MFCActiveXControl1Lib,0x015B41D4,0x81A8,0x420D,0x9E,0x71,0xF7,0xD6,0x7C,0x5C,0x53,0x00);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1,0xD963BBD5,0x0743,0x4B07,0x88,0xD8,0xE8,0xBE,0xA4,0x68,0x40,0x08);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1Events,0x63BB3A9F,0x856B,0x4C92,0x83,0x1C,0xDB,0x19,0x98,0xB3,0x3A,0xCE);


MIDL_DEFINE_GUID(CLSID, CLSID_MFCActiveXControl1,0x474A7D8B,0xB74D,0x4E47,0x9A,0xBE,0xDF,0xCC,0x5C,0x25,0x89,0xCB);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



