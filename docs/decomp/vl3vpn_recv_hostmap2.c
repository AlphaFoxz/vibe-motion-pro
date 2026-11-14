// decompiled by DumpAnchors for program: vl3vpn.dll

// ===================== FUN_1007e0f0 @ 1007e0f0  anchors: [open speed tunnel] =====================

undefined4 FUN_1007e0f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  u_short uVar3;
  undefined8 *_Memory;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0xd4,"open speed tunnel, send clientid: [%s]\n",in_ECX + 0x261c);
  }
  _Memory = _malloc(0x39);
  FUN_10093d10(_Memory,0,0x39);
  *_Memory = 0x14000045;
  *(undefined4 *)(_Memory + 1) = 0xff00;
  *(undefined1 *)((int)_Memory + 3) = 0x34;
  uVar3 = htons(4);
  *(u_short *)((int)_Memory + 0xc) = uVar3;
  *(undefined2 *)((int)_Memory + 0xe) = 0;
  uVar3 = htons(0x34);
  *(u_short *)((int)_Memory + 2) = uVar3;
  uVar5 = *(undefined4 *)(in_ECX + 0x2620);
  uVar1 = *(undefined4 *)(in_ECX + 0x2624);
  uVar2 = *(undefined4 *)(in_ECX + 0x2628);
  *(undefined4 *)(_Memory + 2) = *(undefined4 *)(in_ECX + 0x261c);
  *(undefined4 *)((int)_Memory + 0x14) = uVar5;
  *(undefined4 *)(_Memory + 3) = uVar1;
  *(undefined4 *)((int)_Memory + 0x1c) = uVar2;
  uVar5 = *(undefined4 *)(in_ECX + 0x2630);
  uVar1 = *(undefined4 *)(in_ECX + 0x2634);
  uVar2 = *(undefined4 *)(in_ECX + 0x2638);
  *(undefined4 *)(_Memory + 4) = *(undefined4 *)(in_ECX + 0x262c);
  *(undefined4 *)((int)_Memory + 0x24) = uVar5;
  *(undefined4 *)(_Memory + 5) = uVar1;
  *(undefined4 *)((int)_Memory + 0x2c) = uVar2;
  *(undefined4 *)(_Memory + 6) = *(undefined4 *)(in_ECX + 0x263c);
  uVar3 = ntohs(uVar3);
  iVar4 = SSL_write(*(undefined4 *)(in_ECX + 0x34),_Memory,uVar3);
  if (0 < iVar4) {
    uVar3 = ntohs(*(u_short *)((int)_Memory + 2));
    FUN_10065150(uVar3,0);
    if (*(int *)(in_ECX + 0x40) == 0) {
      FID_conflict__free(_Memory);
      return 0;
    }
    *(undefined4 *)(in_ECX + 0x44) = 0x29;
    FID_conflict__free(_Memory);
    return 0x29;
  }
  if (DAT_10106410 < 4) {
    uVar5 = SSL_get_error(*(undefined4 *)(in_ECX + 0x34),iVar4);
    array_vpn_logprint(3,"..\\l3vpn\\udp_tunnel.c",0xe6,"failed to send clientid to server, error %d\n",uVar5);
  }
  FID_conflict__free(_Memory);
  return 3;
}


// ----- caller: FUN_100659b0 @ 100659b0

int FUN_100659b0(void)

{
  code *pcVar1;
  SOCKET SVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  LSTATUS LVar6;
  int in_ECX;
  char *pcVar7;
  uint uVar8;
  undefined4 *in_EDX;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_30 = in_ECX;
  local_20 = in_EDX;
  if ((DAT_10106410 < 2) &&
     (array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7eb,"l3vpn_tunnel: begin to get vpn configuration: type: %d\n",
                         *(undefined4 *)(in_ECX + 0x88)), DAT_10106410 < 2)) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x711,"get_vpn_config: dev_type: AG_VPN_DEVICE\n");
  }
  iVar3 = FUN_1005cc10();
  iVar4 = DAT_10106410;
  if (*(int *)(local_30 + 0x40) != 0) goto LAB_10065a3d;
  if (((iVar3 == 0x29) || (iVar3 == 6)) || (iVar3 == 7)) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x7f0,
                         "failed to get configuration. session invalid or session timeout or interrupted ret:%d.\n",
                         iVar3);
    }
    *(int *)(local_30 + 0x44) = iVar3;
    return iVar3;
  }
  if (iVar3 != 0) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x7f4,"failed to get configuration, l3vpn addr:%x, ret:%d\n",&local_30,
                         iVar3);
    }
    *(undefined4 *)(local_30 + 0x44) = 0x28;
    return iVar3;
  }
  *(undefined4 *)(local_30 + 0x6808) = 0;
  if (iVar4 < 2) {
    pcVar7 = "enable";
    if (*(char *)(local_30 + 0x5b7d) == '\0') {
      pcVar7 = "disable";
    }
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7fb,"speed tunnel in server: %s\n",pcVar7);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7fc,"speed tunnel in client: %d(0:TCP, 1:UDP, 10:Default)\n",
                         *(undefined4 *)(local_30 + 0x53a4));
    }
  }
  if (((DAT_1011e8a8 == 0) && (*(int *)(local_30 + 0x59d4) != 0)) &&
     ((*(char *)(local_30 + 0x5b7d) != '\0' && (*(int *)(local_30 + 0x53a4) != 0)))) {
    if (*(char *)(local_30 + 0x5197) == '\x01') {
      FUN_10058190();
      if (DAT_10106410 < 2) {
        uVar11 = 0x802;
        goto LAB_10065be2;
      }
      goto LAB_10065bf1;
    }
    iVar4 = FUN_1007e0f0();
    if (iVar4 != 0) {
      if (3 < DAT_10106410) goto LAB_10065bf1;
      pcVar7 = "failed to send clientid to server, disable speed tunnel!\n";
      uVar11 = 0x80b;
      uVar10 = 3;
      goto LAB_10065be9;
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x808,"send udp clientid successfully.\n");
    }
  }
  else {
    FUN_10058190();
    if (DAT_10106410 < 2) {
      uVar11 = 0x812;
LAB_10065be2:
      pcVar7 = "speed tunnel is disabled.\n";
      uVar10 = 1;
LAB_10065be9:
      array_vpn_logprint(uVar10,"..\\l3vpn\\l3vpn.c",uVar11,pcVar7);
    }
LAB_10065bf1:
    FUN_1007dbd0();
  }
  if (*(int *)(local_30 + 0x40) == 0) {
    local_28 = 4;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x819,"sdk VPN_CB_CONFIG_REQUEST start...\n");
    }
    iVar3 = local_30;
    iVar9 = 0;
    iVar4 = local_30 + 0x59d4;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",6,0);
    }
    local_1c = 0;
    if ((*(byte *)(iVar3 + 0x2644) & 3) != 0) {
      FUN_1006ff20();
    }
    if (*(code **)(iVar3 + 0x2648) != (code *)0x0) {
      iVar9 = (**(code **)(iVar3 + 0x2648))(6,0,iVar4,0xe24,iVar3 + 0x6800,&local_28);
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x81b,"sdk VPN_CB_CONFIG_REQUEST finished, ret=%d.\n",iVar9);
    }
    if (iVar9 == 0x87) {
      DAT_1011e8a8 = 2;
      return 0x87;
    }
    if (*(int *)(local_30 + 0x40) == 0) {
      uVar8 = *(uint *)(local_30 + 0x2644) & 0x200;
      if ((uVar8 != 0) && (*(int *)(local_30 + 0x6800) == -1)) {
        if (DAT_10106410 < 4) {
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x824,"failed to configure l3vpn.\n");
        }
        *(undefined4 *)(local_30 + 0x44) = 0x27;
        return 0x27;
      }
      if ((uVar8 == 0) || (((byte)DAT_10ab3970 & 4) != 0)) {
        *(undefined4 *)(local_30 + 0x6800) = 0xffffffff;
        iVar4 = pipe(&local_18);
        if ((iVar4 == -1) && (DAT_10106410 < 4)) {
          piVar5 = __errno();
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x82e,"pipe failed, error %d\n",*piVar5);
        }
        *(undefined4 *)(local_30 + 0x67f8) = local_18;
        *(undefined4 *)(local_30 + 0x67fc) = local_14;
      }
      else {
        *(undefined4 *)(local_30 + 0x67f8) = 0xffffffff;
        *(undefined4 *)(local_30 + 0x67fc) = 0xffffffff;
        *(undefined4 *)(local_30 + 0x6804) = 0xffffffff;
      }
      iVar4 = DAT_10106410;
      *(undefined4 *)(local_30 + 0x2500) = 2;
      *(undefined4 *)(local_30 + 0x44) = 0;
      if (iVar4 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x850,"sdk VPN_CB_CONNECTED start...\n");
      }
      iVar4 = local_30;
      iVar3 = 0;
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",3,0);
      }
      uStack_2c = 0;
      LVar6 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","ErrorCode",4,&uStack_2c,4);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1bf,
                           "vpncallback:: Connect successfully, iRet = %d, Set Error code to Reg, Error code=%d\n",LVar6
                           ,uStack_2c);
      }
      if ((((*(byte *)(iVar4 + 0x2644) & 3) == 0) || (iVar3 = FUN_10062060(), iVar3 == 0)) &&
         (pcVar1 = *(code **)(iVar4 + 0x2648), pcVar1 != (code *)0x0)) {
        iVar3 = (*pcVar1)(3,0,0,0,0,0);
      }
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x852,"sdk VPN_CB_CONNECTED finished\n");
      }
      iVar4 = DAT_10106410;
      if (iVar3 == 0) {
        *(undefined1 *)(local_30 + 0x5195) = 0;
        if (iVar4 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x857,
                             "l3vpn tunnel is ready now, set l3vpn->sess.reconn_now to 0 at the same time\n");
        }
        FUN_10062ab0();
        uStack_24 = 0;
        LVar6 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","tun_device_thread_exit",4,&uStack_24,4);
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x85d,
                             "SHSetValueA: set HKCU VPN-VPN2-tun_device_thread_exit to 0, iRet = %d\n",LVar6);
        }
        iVar3 = FUN_1008f51d(&uStack_10,FUN_10065350,local_30);
        if (iVar3 == 0) {
          iVar3 = FUN_100640d0();
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x868,"before thrd_join\n");
          }
          FUN_1008f62d(uStack_10,uStack_c,0);
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x86a,"after thrd_join\n");
          }
          uStack_c = 0;
          if (1 < DAT_10106410) goto LAB_1006602d;
          pcVar7 = "after thrd_set_null\n";
          uVar10 = 0x86c;
          uVar11 = 1;
        }
        else {
          if (3 < DAT_10106410) goto LAB_1006602d;
          pcVar7 = "create tun thread failed.\n";
          uVar10 = 0x863;
          uVar11 = 3;
        }
        array_vpn_logprint(uVar11,"..\\l3vpn\\l3vpn.c",uVar10,pcVar7);
      }
LAB_1006602d:
      if (local_20 != (undefined4 *)0x0) {
        *local_20 = 1;
      }
      if ((iVar3 == 6) || (iVar3 == 7)) {
        *(undefined1 *)(local_30 + 0x290) = 0;
      }
      FUN_1007ee20();
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x876,"finished stop_udp_open_thread\n");
      }
      SVar2 = *(SOCKET *)(local_30 + 0x67f8);
      if ((SVar2 != 0) && (SVar2 != 0xffffffff)) {
        closesocket(SVar2);
      }
      *(undefined4 *)(local_30 + 0x67f8) = 0xffffffff;
      SVar2 = *(SOCKET *)(local_30 + 0x67fc);
      if ((SVar2 != 0) && (SVar2 != 0xffffffff)) {
        closesocket(SVar2);
      }
      *(undefined4 *)(local_30 + 0x67fc) = 0xffffffff;
      SVar2 = *(SOCKET *)(local_30 + 0x6804);
      if ((SVar2 != 0) && (SVar2 != 0xffffffff)) {
        closesocket(SVar2);
      }
      iVar4 = DAT_10106410;
      *(undefined4 *)(local_30 + 0x6804) = 0xffffffff;
      if (iVar4 < 3) {
        array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x87e,"l3vpn tunnel stop, return code %d\n",iVar3);
        return iVar3;
      }
      return iVar3;
    }
  }
LAB_10065a3d:
  *(undefined4 *)(local_30 + 0x44) = 0x29;
  return 0x29;
}


// ----- callee: array_vpn_logprint @ 10047f50

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void array_vpn_logprint(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  CHAR *pCVar8;
  char *pcVar9;
  _SYSTEMTIME local_101c;
  CHAR local_100c [4093];
  undefined1 local_f [7];
  undefined4 local_8;
  
                    /* 0x47f50  60  array_vpn_logprint */
  local_8 = DAT_101052f0 ^ (uint)(local_f + 0xb);
  pCVar8 = local_100c;
  if (DAT_10106410 <= param_1) {
    if ((DAT_10106418 & 4) != 0) {
      GetLocalTime(&local_101c);
      iVar2 = FUN_100907eb(pCVar8,0x80,"%02d-%02d-%02d %02d-%02d-%02d.%03d ",local_101c.wYear,local_101c.wMonth,
                           local_101c.wDay,local_101c.wHour,local_101c.wMinute,local_101c.wSecond,
                           local_101c.wMilliseconds);
      pCVar8 = pCVar8 + iVar2;
    }
    if (param_1 == 0) {
      pcVar9 = "(DEBUG): ";
    }
    else if (param_1 == 2) {
      pcVar9 = "(WARNING): ";
    }
    else if (param_1 == 3) {
      pcVar9 = "(ERROR): ";
    }
    else {
      pcVar9 = "(INFO): ";
    }
    iVar2 = FUN_100907eb(pCVar8,0x20,&DAT_100e861c,pcVar9);
    pCVar8 = pCVar8 + iVar2;
    DVar3 = GetCurrentThreadId();
    DVar4 = GetCurrentProcessId();
    iVar2 = FUN_100907eb(pCVar8,0x40,"P-%u, T-%u ",DVar4,DVar3);
    pCVar8 = pCVar8 + iVar2;
    iVar2 = FUN_100907eb(pCVar8,0x80,"%s:%u ",param_2,param_3);
    pcVar9 = &DAT_1011c800;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (pcVar9 == &DAT_1011c801) {
      FUN_10047eb0();
    }
    iVar5 = FUN_100907eb(pCVar8 + iVar2,0x80,"<%s> ",&DAT_1011c800);
    pCVar8 = pCVar8 + iVar2 + iVar5;
    puVar6 = (undefined1 *)FUN_1009c02f(pCVar8,local_f + -(int)pCVar8,param_4,&param_5);
    if ((int)puVar6 < 1) {
      piVar7 = __errno();
      if (*piVar7 != 0x22) {
        piVar7 = __errno();
        FUN_10091a4e("logprint: vsnprintf return %d, error %d\n",puVar6,*piVar7);
        FUN_1008fc07();
        return;
      }
      puVar6 = local_f + -(int)pCVar8;
    }
    pCVar8 = pCVar8 + (int)puVar6;
    if (pCVar8[-1] != '\n') {
      pCVar8[0] = '\r';
      pCVar8[1] = '\n';
      pCVar8 = pCVar8 + 2;
    }
    *pCVar8 = '\0';
    if (((DAT_10106418 & 0x20) != 0) && (DAT_10106414 != -1)) {
      FUN_10092152(DAT_10106414,local_100c,(int)pCVar8 - (int)local_100c);
    }
    if ((DAT_10106418 & 8) != 0) {
      OutputDebugStringA(local_100c);
    }
    if ((DAT_10106418 & 1) != 0) {
      FUN_10091a4e(&DAT_100e3ff8,local_100c);
    }
    if (DAT_1010c484 != (code *)0x0) {
      (*DAT_1010c484)(param_1,local_100c);
    }
  }
  FUN_1008fc07();
  return;
}


// ----- callee: WS2_32.DLL::ntohs @ EXTERNAL:00000024
// decompile failed: Exception while decompiling EXTERNAL:00000024: Cannot marshal address space: EXTERNAL

// ----- callee: _malloc @ 100903b4

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2012 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  size_t dwBytes;
  
  if (_Size < 0xffffffe1) {
    do {
      if (DAT_1010b758 == (HANDLE)0x0) {
        __FF_MSGBANNER();
        FUN_1009bcf9(0x1e);
        ___crtExitProcess(0xff);
      }
      if (_Size == 0) {
        dwBytes = 1;
      }
      else {
        dwBytes = _Size;
      }
      pvVar1 = HeapAlloc(DAT_1010b758,0,dwBytes);
      if (pvVar1 != (LPVOID)0x0) goto LAB_10090443;
      if (DAT_1010bd90 == 0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        break;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  else {
    __callnewh(_Size);
    piVar3 = __errno();
    *piVar3 = 0xc;
    pvVar1 = (void *)0x0;
  }
LAB_10090443:
  return pvVar1;
}


// ----- callee: SSLEAY32.DLL::SSL_write @ EXTERNAL:00000058
// decompile failed: Exception while decompiling EXTERNAL:00000058: Cannot marshal address space: EXTERNAL

// ----- callee: FID_conflict:_free @ 1009033c

/* Library Function - Multiple Matches With Different Base Names
    __free_base
    _free
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019
   Release */

void __cdecl FID_conflict__free(void *_Memory)

{
  BOOL BVar1;
  int *piVar2;
  DWORD DVar3;
  int iVar4;
  
  if (_Memory != (void *)0x0) {
    BVar1 = HeapFree(DAT_1010b758,0,_Memory);
    if (BVar1 == 0) {
      piVar2 = __errno();
      DVar3 = GetLastError();
      iVar4 = __get_errno_from_oserr(DVar3);
      *piVar2 = iVar4;
    }
  }
  return;
}


// ----- callee: FUN_10093d10 @ 10093d10

uint * FUN_10093d10(uint *param_1,byte param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = (uint)param_2;
  if ((DAT_1010bd98 >> 1 & 1) == 0) {
    if ((0x7f < (int)param_3) && ((DAT_10105a90 >> 1 & 1) != 0)) {
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      }
      puVar4 = param_1;
      if (((uint)param_1 & 0xf) != 0) {
        uVar2 = 0x10 - ((uint)param_1 & 0xf);
        param_3 = param_3 - uVar2;
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
        }
        for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
      }
      for (uVar3 = param_3 >> 7; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4[1] = uVar1;
        puVar4[2] = uVar1;
        puVar4[3] = uVar1;
        puVar4[4] = uVar1;
        puVar4[5] = uVar1;
        puVar4[6] = uVar1;
        puVar4[7] = uVar1;
        puVar4[8] = uVar1;
        puVar4[9] = uVar1;
        puVar4[10] = uVar1;
        puVar4[0xb] = uVar1;
        puVar4[0xc] = uVar1;
        puVar4[0xd] = uVar1;
        puVar4[0xe] = uVar1;
        puVar4[0xf] = uVar1;
        puVar4[0x10] = uVar1;
        puVar4[0x11] = uVar1;
        puVar4[0x12] = uVar1;
        puVar4[0x13] = uVar1;
        puVar4[0x14] = uVar1;
        puVar4[0x15] = uVar1;
        puVar4[0x16] = uVar1;
        puVar4[0x17] = uVar1;
        puVar4[0x18] = uVar1;
        puVar4[0x19] = uVar1;
        puVar4[0x1a] = uVar1;
        puVar4[0x1b] = uVar1;
        puVar4[0x1c] = uVar1;
        puVar4[0x1d] = uVar1;
        puVar4[0x1e] = uVar1;
        puVar4[0x1f] = uVar1;
        puVar4 = puVar4 + 0x20;
      }
      if ((param_3 & 0x7f) != 0) {
        for (uVar3 = (param_3 & 0x7f) >> 4; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4[1] = uVar1;
          puVar4[2] = uVar1;
          puVar4[3] = uVar1;
          puVar4 = puVar4 + 4;
        }
        if ((param_3 & 0xf) != 0) {
          for (uVar3 = (param_3 & 0xf) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
          }
          for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
            *(byte *)puVar4 = param_2;
            puVar4 = (uint *)((int)puVar4 + 1);
          }
        }
      }
      return param_1;
    }
    puVar4 = param_1;
    if (3 < param_3) {
      uVar2 = -(int)param_1 & 3;
      uVar3 = param_3;
      if (uVar2 != 0) {
        uVar3 = param_3 - uVar2;
        do {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      uVar1 = uVar1 * 0x1010101;
      param_3 = uVar3 & 3;
      uVar3 = uVar3 >> 2;
      if (uVar3 != 0) {
        for (; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
        if (param_3 == 0) {
          return param_1;
        }
      }
    }
    do {
      *(char *)puVar4 = (char)uVar1;
      puVar4 = (uint *)((int)puVar4 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  else {
    puVar4 = param_1;
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(byte *)puVar4 = param_2;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
  }
  return param_1;
}


// ----- callee: WS2_32.DLL::htons @ EXTERNAL:00000005
// decompile failed: Exception while decompiling EXTERNAL:00000005: Cannot marshal address space: EXTERNAL

// ----- callee: SSLEAY32.DLL::SSL_get_error @ EXTERNAL:0000005d
// decompile failed: Exception while decompiling EXTERNAL:0000005d: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_10065150 @ 10065150

void FUN_10065150(uint param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) && (param_1 == 0)) {
LAB_1006517c:
    if ((param_2 != 0) || (499 < param_1)) goto LAB_10065189;
LAB_100651a2:
    if ((param_2 == 0) && (param_1 < 900)) goto LAB_100651bb;
  }
  else {
    if ((param_2 == 0) && (param_1 < 500)) {
      bVar1 = 0xfffffffe < DAT_10aea020;
      DAT_10aea020 = DAT_10aea020 + 1;
      DAT_10aea024 = DAT_10aea024 + (uint)bVar1;
      goto LAB_1006517c;
    }
LAB_10065189:
    if ((param_2 == 0) && (param_1 < 900)) {
      bVar1 = 0xfffffffe < DAT_10aea018;
      DAT_10aea018 = DAT_10aea018 + 1;
      DAT_10aea01c = DAT_10aea01c + (uint)bVar1;
      goto LAB_100651a2;
    }
  }
  bVar1 = 0xfffffffe < DAT_10aea010;
  DAT_10aea010 = DAT_10aea010 + 1;
  DAT_10aea014 = DAT_10aea014 + (uint)bVar1;
LAB_100651bb:
  bVar1 = CARRY4(DAT_10ae9ff0,param_1);
  DAT_10ae9ff0 = DAT_10ae9ff0 + param_1;
  DAT_10ae9ff4 = DAT_10ae9ff4 + param_2 + (uint)bVar1;
  return;
}



// ===================== FUN_1007e240 @ 1007e240  anchors: [open speed tunnel, udp_recv_not_encrypt] =====================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007e240(void)

{
  char cVar1;
  byte bVar2;
  u_short uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  byte *pbVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  bool bVar11;
  undefined1 auStack_754 [4];
  int local_750 [5];
  undefined1 uStack_73c;
  undefined1 uStack_73b;
  undefined1 uStack_73a;
  char local_738 [64];
  CHAR local_6f8;
  undefined1 local_6f7 [263];
  undefined4 local_5f0;
  undefined2 local_5ec;
  uint local_c;
  
  local_c = DAT_101052f0 ^ (uint)auStack_754;
  local_738[0] = '\0';
  FUN_10093d10(local_738 + 1,0,0x3f);
  local_750[0] = 0;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0xff,"open speed tunnel\n");
  }
  if (DAT_10aefb1e == '\0') {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x105,"speed tunnel will not be encrypted\n");
    }
    DAT_10aef34c = DAT_10aef348;
  }
  else {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x102,"speed tunnel will be encrypted.\n");
    }
    DAT_10aef34c = 1;
  }
  _DAT_10aef358 = 0;
  uRam10aef35c = 0;
  uRam10aef360 = 0;
  _DAT_10aef354 = 2;
  uVar3 = htons(DAT_10aef350);
  _DAT_10aef354 = CONCAT22(uVar3,_DAT_10aef354);
  _DAT_10aef358 = DAT_10ae9fa8;
  FUN_1008fdb3(local_738,"%s%d%d",&DAT_10aec5bc,DAT_10aef34c,DAT_10aef960);
  pcVar9 = local_738;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  iVar10 = (int)pcVar9 - (int)(local_738 + 1);
  DAT_10aef340 = socket(2,2,0);
  if ((int)DAT_10aef340 < 0) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\udp_tunnel.c",0x113,"failed to create udp socket\n");
    }
    FUN_1008fc07();
    return;
  }
  FUN_1008fdb3(&local_5f0,&DAT_100e6460,DAT_10aef340);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x11a,"open speed tunnel: request [%s]\n",local_738);
  }
  iVar8 = 0;
  do {
    if (DAT_10ae9fe0 != 0) break;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x11f,"speed tunnel: accetmp:%d\n",iVar8 + 1);
    }
    if (DAT_10106410 < 1) {
      array_vpn_logprint(0,"..\\l3vpn\\udp_tunnel.c",0x62,"speed tunnel write plain data %d bytes\n",iVar10);
    }
    iVar4 = FUN_1007dc70(iVar10);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x121,"udp_send_not_encrypt send finished, ret:%d\n",iVar4);
    }
    if (iVar4 == 0) {
      FUN_10065150(iVar10,0);
      FUN_10093d10(&local_5f0,0,0x5dc);
      iVar4 = FUN_1007de80(extraout_ECX,local_750);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x12e,"udp_recv_not_encrypt finished, ret:%d\n",iVar4);
      }
      if (iVar4 == 0) {
        FUN_100650d0(local_750[0],local_750[0] >> 0x1f);
        uStack_73a = 0;
        local_750[4] = local_5f0;
        uStack_73c = (undefined1)local_5ec;
        uStack_73b = (undefined1)((ushort)local_5ec >> 8);
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x13a,"speed tunnel handshake response = [%s]\n",local_750 + 4)
          ;
        }
        pcVar9 = (char *)&local_5f0;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        if ((int)pcVar9 - ((int)&local_5f0 + 1) == 6) {
          pbVar7 = &DAT_100fb3dc;
          pbVar5 = (byte *)&local_5f0;
          do {
            bVar2 = *pbVar5;
            bVar11 = bVar2 < *pbVar7;
            if (bVar2 != *pbVar7) {
LAB_1007e620:
              uVar6 = -(uint)bVar11 | 1;
              goto LAB_1007e625;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar5[1];
            bVar11 = bVar2 < pbVar7[1];
            if (bVar2 != pbVar7[1]) goto LAB_1007e620;
            pbVar5 = pbVar5 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar2 != 0);
          uVar6 = 0;
LAB_1007e625:
          if (uVar6 == 0) {
            DAT_10af07a8 = 1;
            break;
          }
        }
      }
      else {
        if ((DAT_10ae9fe0 != 0) || (iVar4 == 0x29)) break;
        if (DAT_10106410 < 3) {
          array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0x132,"wait speed tunnel open response failed\n");
        }
      }
    }
    else {
      if ((DAT_10ae9fe0 != 0) || (iVar4 == 0x29)) break;
      if (DAT_10106410 < 3) {
        array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0x125,"send speed tunnel open request failed\n");
      }
      Sleep(1000);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
  if (DAT_10af07a8 == 1) {
    FUN_10058190();
    local_750[1] = 0;
    local_750[3] = 1;
    local_6f8 = '\0';
    FUN_10093d10(local_6f7,0,0x103);
    FUN_1008fdb3(&local_6f8,"SOFTWARE\\VPN\\Keepalive\\L3UDPTunnel");
    local_750[2] = 0;
    SHSetValueA((HKEY)0x80000001,&local_6f8,"Running",4,local_750 + 3,4);
    SHSetValueA((HKEY)0x80000001,&local_6f8,"SendTimes",4,local_750 + 2,4);
    SHSetValueA((HKEY)0x80000001,&local_6f8,"TimeofLatestSend",4,local_750 + 1,4);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x147,"speed tunnel is ready now\n");
    }
    FUN_10063d70();
    FUN_10063f70();
  }
  else {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\udp_tunnel.c",0x14b,"failed to establish speed tunnel\n");
    }
    FUN_100629c0();
  }
  FUN_1008f605(DAT_1011f13c,DAT_1011f140);
  DAT_1011f140 = 0;
  FUN_1008fc07();
  return;
}


// ----- callee: array_vpn_logprint @ 10047f50

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void array_vpn_logprint(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  CHAR *pCVar8;
  char *pcVar9;
  _SYSTEMTIME local_101c;
  CHAR local_100c [4093];
  undefined1 local_f [7];
  undefined4 local_8;
  
                    /* 0x47f50  60  array_vpn_logprint */
  local_8 = DAT_101052f0 ^ (uint)(local_f + 0xb);
  pCVar8 = local_100c;
  if (DAT_10106410 <= param_1) {
    if ((DAT_10106418 & 4) != 0) {
      GetLocalTime(&local_101c);
      iVar2 = FUN_100907eb(pCVar8,0x80,"%02d-%02d-%02d %02d-%02d-%02d.%03d ",local_101c.wYear,local_101c.wMonth,
                           local_101c.wDay,local_101c.wHour,local_101c.wMinute,local_101c.wSecond,
                           local_101c.wMilliseconds);
      pCVar8 = pCVar8 + iVar2;
    }
    if (param_1 == 0) {
      pcVar9 = "(DEBUG): ";
    }
    else if (param_1 == 2) {
      pcVar9 = "(WARNING): ";
    }
    else if (param_1 == 3) {
      pcVar9 = "(ERROR): ";
    }
    else {
      pcVar9 = "(INFO): ";
    }
    iVar2 = FUN_100907eb(pCVar8,0x20,&DAT_100e861c,pcVar9);
    pCVar8 = pCVar8 + iVar2;
    DVar3 = GetCurrentThreadId();
    DVar4 = GetCurrentProcessId();
    iVar2 = FUN_100907eb(pCVar8,0x40,"P-%u, T-%u ",DVar4,DVar3);
    pCVar8 = pCVar8 + iVar2;
    iVar2 = FUN_100907eb(pCVar8,0x80,"%s:%u ",param_2,param_3);
    pcVar9 = &DAT_1011c800;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (pcVar9 == &DAT_1011c801) {
      FUN_10047eb0();
    }
    iVar5 = FUN_100907eb(pCVar8 + iVar2,0x80,"<%s> ",&DAT_1011c800);
    pCVar8 = pCVar8 + iVar2 + iVar5;
    puVar6 = (undefined1 *)FUN_1009c02f(pCVar8,local_f + -(int)pCVar8,param_4,&param_5);
    if ((int)puVar6 < 1) {
      piVar7 = __errno();
      if (*piVar7 != 0x22) {
        piVar7 = __errno();
        FUN_10091a4e("logprint: vsnprintf return %d, error %d\n",puVar6,*piVar7);
        FUN_1008fc07();
        return;
      }
      puVar6 = local_f + -(int)pCVar8;
    }
    pCVar8 = pCVar8 + (int)puVar6;
    if (pCVar8[-1] != '\n') {
      pCVar8[0] = '\r';
      pCVar8[1] = '\n';
      pCVar8 = pCVar8 + 2;
    }
    *pCVar8 = '\0';
    if (((DAT_10106418 & 0x20) != 0) && (DAT_10106414 != -1)) {
      FUN_10092152(DAT_10106414,local_100c,(int)pCVar8 - (int)local_100c);
    }
    if ((DAT_10106418 & 8) != 0) {
      OutputDebugStringA(local_100c);
    }
    if ((DAT_10106418 & 1) != 0) {
      FUN_10091a4e(&DAT_100e3ff8,local_100c);
    }
    if (DAT_1010c484 != (code *)0x0) {
      (*DAT_1010c484)(param_1,local_100c);
    }
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_1007dc70 @ 1007dc70

void FUN_1007dc70(int param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  SOCKET *in_ECX;
  byte *in_EDX;
  undefined4 local_810;
  undefined1 local_80c [2048];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_101052f0 ^ (uint)(auStack_8 + 4);
  if ((char)in_ECX[0x189] != '\0') {
    bVar1 = (byte)((int)(param_1 + 0xc + (param_1 + 0xc >> 0x1f & 7U)) >> 3);
    param_1 = param_1 + 4;
    DAT_10156ab0 = CONCAT13(in_EDX[3] ^ *in_EDX ^ bVar1,
                            CONCAT12(in_EDX[3] ^ *in_EDX,CONCAT11(bVar1,(char)in_ECX[0x189])));
    local_810 = DAT_10156ab0;
    FUN_10093f20(local_80c);
    in_EDX = (byte *)&local_810;
  }
  iVar2 = sendto(*in_ECX,(char *)in_EDX,param_1,0,(sockaddr *)(in_ECX + 5),0x10);
  if (-1 < iVar2) {
    FUN_1008fc07();
    return;
  }
  if (DAT_10106410 < 4) {
    piVar3 = __errno();
    array_vpn_logprint(3,"..\\l3vpn\\udp_tunnel.c",0x55,"udp send failed, error %d\n",*piVar3);
  }
  __errno();
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10093d10 @ 10093d10

uint * FUN_10093d10(uint *param_1,byte param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = (uint)param_2;
  if ((DAT_1010bd98 >> 1 & 1) == 0) {
    if ((0x7f < (int)param_3) && ((DAT_10105a90 >> 1 & 1) != 0)) {
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      }
      puVar4 = param_1;
      if (((uint)param_1 & 0xf) != 0) {
        uVar2 = 0x10 - ((uint)param_1 & 0xf);
        param_3 = param_3 - uVar2;
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
        }
        for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
      }
      for (uVar3 = param_3 >> 7; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4[1] = uVar1;
        puVar4[2] = uVar1;
        puVar4[3] = uVar1;
        puVar4[4] = uVar1;
        puVar4[5] = uVar1;
        puVar4[6] = uVar1;
        puVar4[7] = uVar1;
        puVar4[8] = uVar1;
        puVar4[9] = uVar1;
        puVar4[10] = uVar1;
        puVar4[0xb] = uVar1;
        puVar4[0xc] = uVar1;
        puVar4[0xd] = uVar1;
        puVar4[0xe] = uVar1;
        puVar4[0xf] = uVar1;
        puVar4[0x10] = uVar1;
        puVar4[0x11] = uVar1;
        puVar4[0x12] = uVar1;
        puVar4[0x13] = uVar1;
        puVar4[0x14] = uVar1;
        puVar4[0x15] = uVar1;
        puVar4[0x16] = uVar1;
        puVar4[0x17] = uVar1;
        puVar4[0x18] = uVar1;
        puVar4[0x19] = uVar1;
        puVar4[0x1a] = uVar1;
        puVar4[0x1b] = uVar1;
        puVar4[0x1c] = uVar1;
        puVar4[0x1d] = uVar1;
        puVar4[0x1e] = uVar1;
        puVar4[0x1f] = uVar1;
        puVar4 = puVar4 + 0x20;
      }
      if ((param_3 & 0x7f) != 0) {
        for (uVar3 = (param_3 & 0x7f) >> 4; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4[1] = uVar1;
          puVar4[2] = uVar1;
          puVar4[3] = uVar1;
          puVar4 = puVar4 + 4;
        }
        if ((param_3 & 0xf) != 0) {
          for (uVar3 = (param_3 & 0xf) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
          }
          for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
            *(byte *)puVar4 = param_2;
            puVar4 = (uint *)((int)puVar4 + 1);
          }
        }
      }
      return param_1;
    }
    puVar4 = param_1;
    if (3 < param_3) {
      uVar2 = -(int)param_1 & 3;
      uVar3 = param_3;
      if (uVar2 != 0) {
        uVar3 = param_3 - uVar2;
        do {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      uVar1 = uVar1 * 0x1010101;
      param_3 = uVar3 & 3;
      uVar3 = uVar3 >> 2;
      if (uVar3 != 0) {
        for (; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
        if (param_3 == 0) {
          return param_1;
        }
      }
    }
    do {
      *(char *)puVar4 = (char)uVar1;
      puVar4 = (uint *)((int)puVar4 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  else {
    puVar4 = param_1;
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(byte *)puVar4 = param_2;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
  }
  return param_1;
}


// ----- callee: KERNEL32.DLL::Sleep @ EXTERNAL:000000ec
// decompile failed: Exception while decompiling EXTERNAL:000000ec: Cannot marshal address space: EXTERNAL

// ----- callee: WS2_32.DLL::htons @ EXTERNAL:00000005
// decompile failed: Exception while decompiling EXTERNAL:00000005: Cannot marshal address space: EXTERNAL

// ----- callee: SHLWAPI.DLL::SHSetValueA @ EXTERNAL:0000011f
// decompile failed: Exception while decompiling EXTERNAL:0000011f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_1007de80 @ 1007de80

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1007de80(undefined4 param_1,int *param_2)

{
  SOCKET SVar1;
  int iVar2;
  int *piVar3;
  SOCKET *in_ECX;
  char *in_EDX;
  undefined4 uVar4;
  char *pcVar5;
  timeval local_10a8;
  int local_10a0;
  char *local_109c;
  fd_set local_1098 [15];
  sockaddr local_90 [8];
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x1007de8d;
  local_c = DAT_101052f0 ^ (uint)(local_90[8].sa_data + 10);
  local_10a0 = 0x80;
  local_10a8.tv_sec = 2;
  local_10a8.tv_usec = 0;
  SVar1 = *in_ECX;
  local_1098[0].fd_count = 0;
  if (SVar1 != 0xffffffff) {
    local_1098[0].fd_count = 1;
    local_109c = in_EDX;
    local_1098[0].fd_array[0] = SVar1;
    if (DAT_10106410 < 1) {
      array_vpn_logprint(0,"..\\l3vpn\\udp_tunnel.c",0xa4,"udp recv not encrypt\n");
    }
    iVar2 = select(SVar1 + 1,local_1098,(fd_set *)0x0,(fd_set *)0x0,&local_10a8);
    if (iVar2 < 0) {
      piVar3 = __errno();
      if (*piVar3 != 4) {
        if (DAT_10106410 < 3) {
          piVar3 = __errno();
          array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0xa9,"udp recv select failed error [%d]\n",*piVar3);
        }
        FUN_1008fc07();
        return;
      }
      if (2 < DAT_10106410) goto LAB_1007df99;
      pcVar5 = "udp recv failed, interrupted\n";
      uVar4 = 0xac;
    }
    else {
      if (iVar2 == 0) {
        if (DAT_10106410 < 3) {
          array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0xb1,"select timeout in udp socket.\n");
        }
        FUN_1008fc07();
        return;
      }
      if (*in_ECX == 0xffffffff) goto LAB_1007df99;
      iVar2 = __WSAFDIsSet(*in_ECX,local_1098);
      if (iVar2 == 0) {
LAB_1007e0d5:
        FUN_1008fc07();
        return;
      }
      iVar2 = recvfrom(*in_ECX,local_109c,0x5dc,0,local_90,&local_10a0);
      if (-1 < iVar2) {
        if (iVar2 != 0) {
          *param_2 = iVar2;
          goto LAB_1007e0d5;
        }
        if (DAT_10106410 < 4) {
          piVar3 = __errno();
          array_vpn_logprint(3,"..\\l3vpn\\udp_tunnel.c",0xc3,
                             "recv from udp socket failed, socket is closed, error %d\n",*piVar3);
          FUN_1008fc07();
          return;
        }
LAB_1007e060:
        FUN_1008fc07();
        return;
      }
      piVar3 = __errno();
      if (*piVar3 != 4) {
        if (DAT_10106410 < 3) {
          piVar3 = __errno();
          array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0xbb,"recv from udp socket failed, error [%d]\n",*piVar3);
        }
        goto LAB_1007e060;
      }
      if (2 < DAT_10106410) goto LAB_1007df99;
      pcVar5 = "recv from udp socket failed, interrupted\n";
      uVar4 = 0xbe;
    }
    array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",uVar4,pcVar5);
  }
LAB_1007df99:
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_1008fc07 @ 1008fc07

void FUN_1008fc07(void)

{
  int in_ECX;
  
  if (in_ECX != DAT_101052f0) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_100629c0 @ 100629c0

void FUN_100629c0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  u_short local_10;
  undefined2 local_e;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (int)register0x00000010 - 4U;
  local_1c = 0x14000045;
  local_18 = 0;
  local_14 = 0xff00;
  local_10 = htons(5);
  local_e = 0;
  local_c = 0;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x29f,"speed tunnel will be closed, switch to ssl tunnel.");
  }
  iVar1 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&local_1c,0x14);
  if (*(int *)(in_ECX + 0x40) != 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0x29;
    FUN_1008fc07();
    return;
  }
  if (0 < iVar1) {
    FUN_10065150(iVar1,iVar1 >> 0x1f);
    FUN_1008fc07();
    return;
  }
  if (DAT_10106410 < 4) {
    array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x2a4,"send close speed tunnel packet failed.");
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_1008fdb3 @ 1008fdb3

undefined4 FUN_1008fdb3(undefined1 *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_24 = (undefined1 *)0x0;
  piVar1 = &local_20;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  if ((param_2 == 0) || (param_1 == (undefined1 *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_10099e24();
    uVar2 = 0xffffffff;
  }
  else {
    local_1c = param_1;
    local_24 = param_1;
    local_20 = 0x7fffffff;
    local_18 = 0x42;
    uVar2 = FUN_1009aec7(&local_24,param_2,0,&param_3);
    local_20 = local_20 + -1;
    if (local_20 < 0) {
      FUN_1009ac39(0,&local_24);
    }
    else {
      *local_24 = 0;
    }
  }
  return uVar2;
}


// ----- callee: FUN_10063f70 @ 10063f70

void FUN_10063f70(void)

{
  int iVar1;
  int in_ECX;
  int in_EDX;
  bool bVar2;
  _SYSTEMTIME local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  u_short local_24;
  ushort local_22;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  u_short local_10;
  undefined2 local_e;
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (int)register0x00000010 - 4U;
  local_1c = 0x14000045;
  local_18 = 0;
  local_14 = 0xff00;
  local_10 = htons(1);
  local_e = 0;
  local_c = 0;
  local_30 = 0x14000045;
  local_2c = 0;
  local_28 = 0xff00;
  local_24 = htons(1);
  local_20 = 0;
  if (in_EDX == 1) {
    local_e = 1;
  }
  local_22 = (ushort)(in_EDX == 1);
  GetLocalTime(&local_40);
  local_20 = ((uint)local_40.wSecond + ((uint)local_40.wMinute + (uint)local_40.wHour * 0x3c) * 0x3c) * 1000 +
             (uint)local_40.wMilliseconds;
  local_c = local_20;
  if (*(int *)(in_ECX + 0x6808) != 0) {
    iVar1 = FUN_1007dd70(0x14);
    if (iVar1 != 0) {
      iVar1 = FUN_1007dd70(0x14);
      if (iVar1 != 0) {
        if (DAT_10106410 < 4) {
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x514,"failed to send speed tunnel keep alive, error %d\n",iVar1);
        }
        FUN_1007dbd0();
        FUN_100629c0();
        FUN_1008fc07();
        return;
      }
    }
    bVar2 = 0xfffffffe < DAT_10aea020;
    DAT_10aea020 = DAT_10aea020 + 1;
    DAT_10aea024 = DAT_10aea024 + (uint)bVar2;
    bVar2 = 0xffffffeb < DAT_10ae9ff0;
    DAT_10ae9ff0 = DAT_10ae9ff0 + 0x14;
    DAT_10ae9ff4 = DAT_10ae9ff4 + (uint)bVar2;
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10063d70 @ 10063d70

void FUN_10063d70(void)

{
  LPCSTR pszSubKey;
  int iVar1;
  int in_ECX;
  int in_EDX;
  bool bVar2;
  undefined4 *pvData;
  undefined4 local_248;
  undefined4 local_244;
  _SYSTEMTIME local_240;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  u_short local_224;
  undefined2 local_222;
  int local_220;
  CHAR local_21c;
  undefined1 local_21b [263];
  CHAR local_114;
  undefined1 local_113 [267];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_113 + 0x10f);
  local_230 = 0x14000045;
  local_22c = 0;
  local_228 = 0xff00;
  local_224 = htons(1);
  local_220 = 0;
  local_222 = 0;
  if (0 < in_EDX) {
    local_222 = (short)in_EDX;
  }
  if (in_EDX == 2) {
    local_244 = 1;
    local_114 = '\0';
    FUN_10093d10(local_113,0,0x103);
    FUN_1008fdb3(&local_114,"SOFTWARE\\VPN\\Keepalive\\L3WGTunnel");
    pvData = &local_244;
    pszSubKey = &local_114;
  }
  else {
    local_248 = 0;
    local_21c = '\0';
    FUN_10093d10(local_21b,0,0x103);
    FUN_1008fdb3(&local_21c,"SOFTWARE\\VPN\\Keepalive\\L3WGTunnel");
    pvData = &local_248;
    pszSubKey = &local_21c;
  }
  SHSetValueA((HKEY)0x80000001,pszSubKey,"running",4,pvData,4);
  GetLocalTime(&local_240);
  local_220 = ((uint)local_240.wSecond + ((uint)local_240.wMinute + (uint)local_240.wHour * 0x3c) * 0x3c) * 1000 +
              (uint)local_240.wMilliseconds;
  iVar1 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&local_230,0x14);
  if (*(int *)(in_ECX + 0x40) != 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0x29;
    FUN_1008fc07();
    return;
  }
  if (0 < iVar1) {
    bVar2 = 0xfffffffe < DAT_10aea020;
    DAT_10aea020 = DAT_10aea020 + 1;
    DAT_10aea024 = DAT_10aea024 + (uint)bVar2;
    bVar2 = 0xffffffeb < DAT_10ae9ff0;
    DAT_10ae9ff0 = DAT_10ae9ff0 + 0x14;
    DAT_10ae9ff4 = DAT_10ae9ff4 + (uint)bVar2;
    FUN_1008fc07();
    return;
  }
  if (DAT_10106410 < 4) {
    array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x4e2,"send tcp tunnel keep alive failed.\n");
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_100650d0 @ 100650d0

void FUN_100650d0(uint param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) && (param_1 == 0)) {
LAB_100650fc:
    if ((param_2 != 0) || (499 < param_1)) goto LAB_10065109;
LAB_10065122:
    if ((param_2 == 0) && (param_1 < 900)) goto LAB_1006513b;
  }
  else {
    if ((param_2 == 0) && (param_1 < 500)) {
      bVar1 = 0xfffffffe < DAT_10aea008;
      DAT_10aea008 = DAT_10aea008 + 1;
      DAT_10aea00c = DAT_10aea00c + (uint)bVar1;
      goto LAB_100650fc;
    }
LAB_10065109:
    if ((param_2 == 0) && (param_1 < 900)) {
      bVar1 = 0xfffffffe < DAT_10aea000;
      DAT_10aea000 = DAT_10aea000 + 1;
      DAT_10aea004 = DAT_10aea004 + (uint)bVar1;
      goto LAB_10065122;
    }
  }
  bVar1 = 0xfffffffe < DAT_10ae9ff8;
  DAT_10ae9ff8 = DAT_10ae9ff8 + 1;
  DAT_10ae9ffc = DAT_10ae9ffc + (uint)bVar1;
LAB_1006513b:
  bVar1 = CARRY4(DAT_10ae9fe8,param_1);
  DAT_10ae9fe8 = DAT_10ae9fe8 + param_1;
  DAT_10ae9fec = DAT_10ae9fec + param_2 + (uint)bVar1;
  return;
}


// ----- callee: FUN_10058190 @ 10058190

void FUN_10058190(void)

{
  LSTATUS LVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined1 local_118 [4];
  CHAR local_114 [268];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_114 + 0x110);
  local_114[0] = '\0';
  FUN_10093d10(local_114 + 1,0,0x103);
  puVar4 = (undefined4 *)(local_118 + 3);
  do {
    pcVar3 = (char *)((int)puVar4 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  } while (*pcVar3 != '\0');
  pcVar3 = "Software\\VPN\\Install Manager\\{5091C97F-0EA4-43b5-864E-390BB412DF95}";
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    puVar4 = puVar4 + 1;
  }
  LVar1 = SHSetValueA((HKEY)0x80000001,local_114,"UDPTunnelStatus",4,local_118,4);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\common.c",0x24e9,"set_udp_tunnel_running_status: dwValue:%d,dwRet=%d\n",local_118,
                       LVar1);
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_1008f605 @ 1008f605

int FUN_1008f605(HANDLE param_1)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle(param_1);
  return (-(uint)(BVar1 != 0) & 0xfffffffc) + 4;
}


// ----- callee: WS2_32.DLL::socket @ EXTERNAL:0000001d
// decompile failed: Exception while decompiling EXTERNAL:0000001d: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_10065150 @ 10065150

void FUN_10065150(uint param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) && (param_1 == 0)) {
LAB_1006517c:
    if ((param_2 != 0) || (499 < param_1)) goto LAB_10065189;
LAB_100651a2:
    if ((param_2 == 0) && (param_1 < 900)) goto LAB_100651bb;
  }
  else {
    if ((param_2 == 0) && (param_1 < 500)) {
      bVar1 = 0xfffffffe < DAT_10aea020;
      DAT_10aea020 = DAT_10aea020 + 1;
      DAT_10aea024 = DAT_10aea024 + (uint)bVar1;
      goto LAB_1006517c;
    }
LAB_10065189:
    if ((param_2 == 0) && (param_1 < 900)) {
      bVar1 = 0xfffffffe < DAT_10aea018;
      DAT_10aea018 = DAT_10aea018 + 1;
      DAT_10aea01c = DAT_10aea01c + (uint)bVar1;
      goto LAB_100651a2;
    }
  }
  bVar1 = 0xfffffffe < DAT_10aea010;
  DAT_10aea010 = DAT_10aea010 + 1;
  DAT_10aea014 = DAT_10aea014 + (uint)bVar1;
LAB_100651bb:
  bVar1 = CARRY4(DAT_10ae9ff0,param_1);
  DAT_10ae9ff0 = DAT_10ae9ff0 + param_1;
  DAT_10ae9ff4 = DAT_10ae9ff4 + param_2 + (uint)bVar1;
  return;
}



// ===================== FUN_1005a1b0 @ 1005a1b0  anchors: [get_ag_hostmap: data len] =====================

void FUN_1005a1b0(void)

{
  void *pvVar1;
  int iVar2;
  _union_1226 *p_Var3;
  _struct_1227 _Var4;
  char *pcVar5;
  int in_ECX;
  int in_EDX;
  u_long uVar6;
  int iVar7;
  bool bVar8;
  uint local_120;
  _struct_1227 local_118;
  u_long local_114;
  int local_110;
  undefined1 local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_10c + 0x108);
  local_10c[0] = 0;
  FUN_10093d10(local_10c + 1,0,0xff);
  local_120 = 0x20;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x56,"get_ag_hostmap: data len [%u]\n");
  }
  if (in_EDX == 0) {
    FUN_1008fc07();
    return;
  }
  *(undefined4 *)(in_ECX + 0x5bb0) = 0;
  pvVar1 = _malloc(0x80);
  *(void **)(in_ECX + 0x5bb8) = pvVar1;
  if (in_EDX == 0) {
    FUN_1008fc07();
    return;
  }
  do {
    if (local_120 <= *(uint *)(in_ECX + 0x5bb0)) {
      local_120 = *(uint *)(in_ECX + 0x5bb0) + 0x10;
      pvVar1 = _realloc(*(void **)(in_ECX + 0x5bb8),local_120 * 4);
      *(void **)(in_ECX + 0x5bb8) = pvVar1;
    }
    iVar7 = 0;
    do {
      iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x34),local_10c + iVar7 + -0xc,8 - iVar7);
      if ((iVar2 < 1) || (*(int *)(in_ECX + 0x40) != 0)) {
        iVar7 = -1;
        goto LAB_1005a2db;
      }
      iVar7 = iVar7 + iVar2;
    } while (iVar7 < 8);
    iVar7 = 8;
LAB_1005a2db:
    if (*(int *)(in_ECX + 0x40) != 0) {
LAB_1005a53f:
      *(undefined4 *)(in_ECX + 0x44) = 0x29;
      FUN_1008fc07();
      return;
    }
    if ((iVar7 < 1) || (iVar7 != 8)) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x65,
                           "get_ag_hostmap: failed to read ip from ssl tunnel, ret: %d\n",iVar7);
      }
      FUN_1008fc07();
      return;
    }
    local_110 = in_EDX + -8;
    bVar8 = 0xfffffffe < DAT_10aea008;
    DAT_10aea008 = DAT_10aea008 + 1;
    DAT_10aea00c = DAT_10aea00c + (uint)bVar8;
    bVar8 = 0xfffffff7 < DAT_10ae9fe8;
    DAT_10ae9fe8 = DAT_10ae9fe8 + 8;
    DAT_10ae9fec = DAT_10ae9fec + (uint)bVar8;
    local_114 = ntohl(local_114);
    if ((0xff < local_114) && (DAT_10106410 < 4)) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x6e,"get_ag_hostmap: host name length is too long.\n");
    }
    p_Var3 = _malloc(local_114 + 8);
    uVar6 = local_114;
    _Var4 = local_118;
    if (local_118 == (_struct_1227)0x0) {
      _Var4 = *(_struct_1227 *)(in_ECX + 8);
    }
    p_Var3->S_un_b = _Var4;
    iVar7 = 0;
    if (0 < (int)local_114) {
      do {
        iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x34),local_10c + iVar7,uVar6 - iVar7);
        if ((iVar2 < 1) || (*(int *)(in_ECX + 0x40) != 0)) {
          uVar6 = 0xffffffff;
          break;
        }
        iVar7 = iVar7 + iVar2;
      } while (iVar7 < (int)uVar6);
    }
    if (*(int *)(in_ECX + 0x40) != 0) goto LAB_1005a53f;
    if ((int)uVar6 < 1) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x79,"get_ag_hostmap: failed to read host from ssl tunnel\n");
      }
      FUN_1008fc07();
      return;
    }
    local_110 = local_110 - uVar6;
    if (((int)uVar6 < 0) || (uVar6 != 0)) {
      if ((-1 < (int)uVar6) && (uVar6 < 500)) {
        bVar8 = 0xfffffffe < DAT_10aea008;
        DAT_10aea008 = DAT_10aea008 + 1;
        DAT_10aea00c = DAT_10aea00c + (uint)bVar8;
        goto LAB_1005a3f1;
      }
LAB_1005a3fe:
      if ((-1 < (int)uVar6) && (uVar6 < 900)) {
        bVar8 = 0xfffffffe < DAT_10aea000;
        DAT_10aea000 = DAT_10aea000 + 1;
        DAT_10aea004 = DAT_10aea004 + (uint)bVar8;
        goto LAB_1005a417;
      }
LAB_1005a422:
      bVar8 = 0xfffffffe < DAT_10ae9ff8;
      DAT_10ae9ff8 = DAT_10ae9ff8 + 1;
      DAT_10ae9ffc = DAT_10ae9ffc + (uint)bVar8;
    }
    else {
LAB_1005a3f1:
      if (((int)uVar6 < 0) || (499 < uVar6)) goto LAB_1005a3fe;
LAB_1005a417:
      if (((int)uVar6 < 0) || (899 < uVar6)) goto LAB_1005a422;
    }
    bVar8 = CARRY4(DAT_10ae9fe8,uVar6);
    DAT_10ae9fe8 = DAT_10ae9fe8 + uVar6;
    DAT_10ae9fec = DAT_10ae9fec + ((int)uVar6 >> 0x1f) + (uint)bVar8;
    FUN_10093f20(p_Var3 + 1,local_10c,local_114);
    *(_struct_1227 **)(*(int *)(in_ECX + 0x5bb8) + *(int *)(in_ECX + 0x5bb0) * 4) = &p_Var3->S_un_b;
    *(int *)(in_ECX + 0x5bb0) = *(int *)(in_ECX + 0x5bb0) + 1;
    _Var4 = local_118;
    if (local_118 == (_struct_1227)0x0) {
      _Var4 = *(_struct_1227 *)(in_ECX + 8);
    }
    if (DAT_10106410 < 2) {
      pcVar5 = inet_ntoa((in_addr)_Var4);
      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x89,"hostmap: [%s] <--> [%s]\n",local_10c,pcVar5);
    }
    if (local_110 == 0) {
      FUN_1008fc07();
      return;
    }
    in_EDX = local_110;
  } while( true );
}


// ----- caller: FUN_1005cc10 @ 1005cc10

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1005cc10(void)

{
  undefined1 *puVar1;
  char cVar2;
  size_t sVar3;
  u_short uVar4;
  LSTATUS LVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  u_long uVar10;
  int iVar11;
  ulong uVar12;
  undefined4 *in_ECX;
  char *pcVar13;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  char *pcVar14;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  uint uVar15;
  uint uVar16;
  code *pcVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  DWORD aDStack_101d8 [5];
  char *pcStack_101c4;
  int iStack_101c0;
  void *pvStack_101bc;
  char acStack_101b8 [12];
  size_t sStack_101ac;
  undefined4 uStack_101a8;
  undefined4 uStack_101a4;
  undefined4 uStack_101a0;
  undefined4 uStack_1019c;
  undefined1 auStack_10198 [12];
  undefined4 uStack_1018c;
  undefined4 uStack_10188;
  undefined4 uStack_10184;
  undefined4 uStack_10180;
  undefined1 uStack_10170;
  undefined1 uStack_1016f;
  undefined1 uStack_1016e;
  undefined1 uStack_1016d;
  undefined1 uStack_1016c;
  undefined1 uStack_1016b;
  undefined1 auStack_10168 [4];
  uint uStack_10164;
  undefined4 uStack_10160;
  undefined1 uStack_10134;
  undefined1 uStack_10133;
  uint auStack_10130 [9];
  char cStack_1010c;
  undefined1 auStack_1010b [65535];
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_10c + 0x108);
  cStack_1010c = '\0';
  FUN_10093d10(auStack_1010b,0,0xfffe);
  iStack_101c0 = 0;
  local_10c[0] = '\0';
  FUN_10093d10(local_10c + 1,0,0xff);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4c0,"get_ag_l3vpn_config start...\n");
  }
  iVar7 = DAT_10106410;
  FUN_10093d10(&cStack_1010c,0,0xffff);
  if (iVar7 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4c9,"get_ag_l3vpn_config start open tunnel\n");
  }
  aDStack_101d8[0] = 1;
  aDStack_101d8[1] = 0x100;
  LVar5 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","VPNMachineCPUID",aDStack_101d8,local_10c,aDStack_101d8 + 1
                     );
  if (LVar5 == 0) {
    pcVar13 = local_10c;
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    if ((int)pcVar13 - (int)(local_10c + 1) == 0) goto LAB_1005cd50;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4d3,"MotionPro windows get cpuid len=%d.\n",
                         (int)pcVar13 - (int)(local_10c + 1));
    }
  }
  else {
LAB_1005cd50:
    pcVar13 = (char *)(in_ECX + 0x987);
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    _strncpy(local_10c,(char *)(in_ECX + 0x987),(int)pcVar13 - ((int)in_ECX + 0x261d));
  }
  uVar4 = ntohs(*(u_short *)((int)in_ECX + 6));
  pcStack_101c4 = (char *)(uint)uVar4;
  pcVar13 = (char *)(in_ECX + 99);
  do {
    cVar2 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar2 != '\0');
  pcVar14 = (char *)(in_ECX + 0xa4);
  if (pcVar13 == (char *)((int)in_ECX + 0x18d)) {
    if (uVar4 != 0x1bb) {
      puVar6 = in_ECX + 0x23;
      goto LAB_1005ce3b;
    }
    pvStack_101bc =
         (void *)FUN_1008fdb3(&cStack_1010c,
                              "GET %s/vpntunnel HTTP/1.1\r\nHost: %s\r\nCookie: ANStandalone=true;%s\r\nx-devtype: %d\r\nappid: SSPVPN\r\nclientid: %s\r\ncpuid: %s\r\nhostname: %s\r\nPAYLOAD-IP-VERSION: 6\r\n\r\n"
                              ,"/prx/000/http/localhost",in_ECX + 0x23,pcVar14,1,in_ECX + 0x987,local_10c,
                              (int)in_ECX + 0x1df5);
  }
  else if (uVar4 == 0x1bb) {
    pvStack_101bc =
         (void *)FUN_1008fdb3(&cStack_1010c,
                              "GET %s/vpntunnel HTTP/1.1\r\nHost: %s\r\nCookie: ANStandalone=true;%s\r\nx-devtype: %d\r\nappid: SSPVPN\r\nclientid: %s\r\ncpuid: %s\r\nhostname: %s\r\nPAYLOAD-IP-VERSION: 6\r\n\r\n"
                              ,"/prx/000/http/localhost",in_ECX + 99);
  }
  else {
    puVar6 = in_ECX + 99;
LAB_1005ce3b:
    pvStack_101bc =
         (void *)FUN_1008fdb3(&cStack_1010c,
                              "GET %s/vpntunnel HTTP/1.1\r\nHost: %s:%u\r\nCookie: ANStandalone=true;%s\r\nx-devtype: %d\r\nappid: SSPVPN\r\nclientid: %s\r\ncpuid: %s\r\nhostname: %s\r\nPAYLOAD-IP-VERSION: 6\r\n\r\n"
                              ,"/prx/000/http/localhost",puVar6,uVar4,pcVar14,1,in_ECX + 0x987,local_10c,
                              (int)in_ECX + 0x1df5);
  }
  aDStack_101d8[4] = 0;
  aDStack_101d8[3] = 4;
  aDStack_101d8[2] = 4;
  LVar5 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Install Manager","EnablePrintRequest",aDStack_101d8 + 3,
                      aDStack_101d8 + 4,aDStack_101d8 + 2);
  if ((LVar5 == 0) && (aDStack_101d8[4] == 0x2704)) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4f6,"open tunnel req: [%s]\n",&cStack_1010c);
    }
  }
  else if (DAT_10106410 < 2) {
    do {
      cVar2 = *pcVar14;
      pcVar14 = pcVar14 + 1;
    } while (cVar2 != '\0');
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4fa,
                       "open tunnel req: GET %s/vpntunnel HTTP/1.1\r\nHost: %s:%u\r\nCookie len: %d\r\nx-devtype: %d\r\nappid: SSPVPN\r\nclientid: %s\r\ncpuid: %s\r\nhostname: %s\r\nPAYLOAD-IP-VERSION: 6\n"
                       ,"/prx/000/http/localhost",in_ECX + 99,(uint)pcStack_101c4 & 0xffff,
                       (int)pcVar14 - ((int)in_ECX + 0x291),1,in_ECX + 0x987,local_10c,(int)in_ECX + 0x1df5);
  }
  iVar7 = SSL_write(in_ECX[0xd],&cStack_1010c,pvStack_101bc);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x4fe,"SSL_write finished: ret:%d\n",iVar7);
  }
  if (in_ECX[0x10] != 0) goto LAB_1005cf79;
  if (iVar7 < 1) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x501,
                         "get_ag_config: failed to write to ssl tunnel to open tunnel\n");
    }
LAB_1005cfbe:
    FUN_1008fc07();
    return;
  }
  FUN_10065150(iVar7,iVar7 >> 0x1f);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x507,"write open tunnel request to ssl tunnel\n");
  }
  FUN_10093d10(&cStack_1010c,0,0xffff);
  iVar7 = FUN_100484d0(&cStack_1010c,0xfffe,&pcStack_101c4);
  if (iVar7 != 0) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x50c,"get_ag_config: failed to recv response from ag\n");
      FUN_1008fc07();
      return;
    }
    goto LAB_1005e6c9;
  }
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x510,"open tunnel response: [%s]\n",&cStack_1010c);
  }
  iVar7 = __strnicmp(&cStack_1010c,"HTTP/1.1 302 Redirect",0x15);
  if (iVar7 == 0) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x513,"get_ag_config: invalid response [%s]\n",&cStack_1010c);
    }
    FUN_1008fc07();
    return;
  }
  iVar7 = __strnicmp(&cStack_1010c,"HTTP/1.1 200 OK",0xf);
  if (iVar7 != 0) {
    iVar8 = __strnicmp(&cStack_1010c,"HTTP/1.1 201 OK",0xf);
    iVar7 = DAT_10106410;
    if (iVar8 != 0) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x51f,"get_ag_config: response is invalid:\n[%s]\n",&cStack_1010c
                          );
      }
      goto LAB_1005d223;
    }
    in_ECX[0xb9e] = 1;
    if ((iVar7 < 2) &&
       (array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x51c,"get_ag_config: response is json protocol\n"),
       DAT_10106410 < 2)) {
      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x51d,"get_ag_config: buf: %s.\n",&cStack_1010c);
    }
  }
  uStack_101a4 = 0;
  uStack_101a0 = 0;
  uStack_1019c = 0;
  uStack_101a8 = 0x50;
  iVar7 = SSL_write(in_ECX[0xd],&uStack_101a8,0x10);
  if (in_ECX[0x10] != 0) {
LAB_1005cf79:
    in_ECX[0x11] = 0x29;
    FUN_1008fc07();
    return;
  }
  if (iVar7 < 1) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x52b,"get_ag_config: failed to send common config request\n");
      FUN_1008fc07();
      return;
    }
    goto LAB_1005cfbe;
  }
  FUN_10065150(iVar7,iVar7 >> 0x1f);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x531,"write common config request to ssl tunnel\n");
  }
  iVar7 = 0;
  uVar16 = 0;
  do {
    iVar8 = SSL_read(in_ECX[0xd],acStack_101b8 + iVar7,0x10 - iVar7);
    if ((iVar8 < 1) || (in_ECX[0x10] != 0)) {
      iVar7 = -1;
      goto LAB_1005d2a7;
    }
    iVar7 = iVar7 + iVar8;
  } while (iVar7 < 0x10);
  iVar7 = 0x10;
LAB_1005d2a7:
  if (in_ECX[0x10] != 0) goto LAB_1005cf79;
  if (iVar7 < 1) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x536,"get_ag_config: failed to get common config head\n");
    }
    FUN_1008fc07();
    return;
  }
  FUN_100650d0(iVar7,iVar7 >> 0x1f);
  sVar3 = sStack_101ac;
  if (acStack_101b8[0] != 'Q') {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x53e,
                         "get_ag_config: invalid common config response, msg type: %d\n",acStack_101b8[0]);
      FUN_1008fc07();
      return;
    }
LAB_1005d223:
    FUN_1008fc07();
    return;
  }
  pvVar9 = _malloc(sStack_101ac);
  pvStack_101bc = pvVar9;
  if (pvVar9 == (void *)0x0) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x545,"failed to allocate memory\n");
      pvVar9 = pvStack_101bc;
    }
    goto LAB_1005d380;
  }
  if (in_ECX[0xb9e] == 1) {
    FUN_10093d10(pvVar9,0,sVar3);
    uVar18 = extraout_ECX;
    if (sStack_101ac != 0) {
      do {
        iVar7 = SSL_read(in_ECX[0xd],(int)pvVar9 + uVar16,sStack_101ac - uVar16);
        if (in_ECX[0x10] != 0) goto LAB_1005d97c;
        if (iVar7 < 1) {
          if (DAT_10106410 < 4) {
            array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x54f,"get_ag_config: failed to get common config data\n");
          }
          goto LAB_1005e6aa;
        }
        FUN_100650d0(iVar7,iVar7 >> 0x1f);
        uVar16 = uVar16 + iVar7;
        uVar18 = extraout_ECX_00;
        pvVar9 = pvStack_101bc;
      } while (uVar16 < sStack_101ac);
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x557,"datalen %d, offset is %d, common cfg is:\n%s\n",sStack_101ac
                         ,uVar16,pvVar9);
      uVar18 = extraout_ECX_01;
    }
    iStack_101c0 = FUN_10044ba0(uVar18);
    if (iStack_101c0 == 0) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x55c,"get_ag_config: failed to parse common config, error: %s\n"
                           ,DAT_1011f158);
      }
    }
    else {
      iVar7 = FUN_10045010();
      if (iVar7 != 0) {
        uStack_10164 = *(uint *)(iVar7 + 0x14);
      }
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x566,"get_ag_config: netpool flags: [0x%x]\n",uStack_10164);
      }
      if ((uStack_10164 & 0x100) == 0) {
        if (DAT_10106410 < 4) {
          uVar10 = ntohl(uStack_10164);
          array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x569,"get_ag_config: l3vpn is not enabled, flags: [%x], %x\n",
                             uStack_10164,uVar10);
        }
      }
      else {
        in_ECX[0x16f1] = uStack_10164;
        iVar8 = FUN_10045010();
        iVar7 = DAT_10106410;
        if (iVar8 != 0) {
          uStack_10160 = *(undefined4 *)(iVar8 + 0x14);
          in_ECX[0x1678] = uStack_10160;
          if (iVar7 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x574,"keep alive interval: [%d]\n",uStack_10160);
          }
        }
        iVar7 = FUN_10045010();
        if (iVar7 != 0) {
          uStack_10134 = *(undefined1 *)(iVar7 + 0x14);
        }
        iVar7 = FUN_10045010();
        if (iVar7 != 0) {
          uStack_10133 = *(undefined1 *)(iVar7 + 0x14);
        }
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x582,"speed tunnel: [%d], encrypt: [%d]\n",uStack_10134,
                             uStack_10133);
        }
        iVar7 = (int)in_ECX + 0x61ed;
        *(undefined1 *)((int)in_ECX + 0x5b7d) = uStack_10134;
        *(undefined1 *)((int)in_ECX + 0x5b7e) = uStack_10133;
        FUN_10093d10(iVar7,0,0x104);
        iVar8 = FUN_10045010();
        if (iVar8 != 0) {
          pcVar14 = *(char **)(iVar8 + 0x10);
          pcVar13 = pcVar14;
          do {
            cVar2 = *pcVar13;
            pcVar13 = pcVar13 + 1;
          } while (cVar2 != '\0');
          pcVar13 = pcVar13 + (1 - (int)(pcVar14 + 1));
          if (0x104 < (int)pcVar13) {
            pcVar13 = (char *)0x104;
          }
          FUN_10093f20(iVar7,pcVar14,pcVar13);
        }
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x58c,"get_ag_config: get current access mode:%s.\n",iVar7);
        }
        iVar7 = (int)in_ECX + 0x63f5;
        FUN_10093d10(iVar7,0,0x400);
        iVar8 = (int)in_ECX + 0x62f1;
        FUN_10093d10(iVar8,0,0x104);
        iVar11 = FUN_10045010();
        if (iVar11 != 0) {
          pcVar14 = *(char **)(iVar11 + 0x10);
          pcStack_101c4 = pcVar14 + 1;
          pcVar13 = pcVar14;
          do {
            cVar2 = *pcVar13;
            pcVar13 = pcVar13 + 1;
          } while (cVar2 != '\0');
          pcVar13 = pcVar13 + (1 - (int)pcStack_101c4);
          if (0x400 < (int)pcVar13) {
            pcVar13 = (char *)0x400;
          }
          FUN_10093f20(iVar7,pcVar14,pcVar13);
        }
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x596,"get_ag_config: get current redirect_url:%s.\n",iVar7);
        }
        iVar7 = FUN_10045010();
        if (iVar7 != 0) {
          pcVar14 = *(char **)(iVar7 + 0x10);
          pcVar13 = pcVar14;
          do {
            cVar2 = *pcVar13;
            pcVar13 = pcVar13 + 1;
          } while (cVar2 != '\0');
          pcVar13 = pcVar13 + (1 - (int)(pcVar14 + 1));
          if (0x104 < (int)pcVar13) {
            pcVar13 = (char *)0x104;
          }
          FUN_10093f20(iVar8,pcVar14,pcVar13);
        }
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x59d,"get_ag_config: get current redirect_browser:%s.\n",iVar8
                            );
        }
        iVar7 = (int)in_ECX + 0x5be5;
        *(undefined1 *)(in_ECX + 0x16f9) = 0;
        FUN_10093d10(iVar7,0,0x400);
        FUN_10093d10((int)in_ECX + 0x5fe5,0,0x104);
        FUN_10093d10((int)in_ECX + 0x60e9,0,0x104);
        iVar8 = FUN_10045010();
        if (iVar8 != 0) {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5a7,"speed tunnel: get call home switch finish.\n");
          }
          iVar8 = FUN_10090450(*(undefined4 *)(iVar8 + 0x10),&DAT_100f0e1c);
          if (iVar8 != 0) {
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5aa,"speed tunnel: get call home switch result is on.\n")
              ;
            }
            *(undefined1 *)(in_ECX + 0x16f9) = 1;
            iVar8 = FUN_10045010();
            if (iVar8 != 0) {
              pcVar13 = *(char **)(iVar8 + 0x10);
              pcVar14 = pcVar13;
              do {
                cVar2 = *pcVar14;
                pcVar14 = pcVar14 + 1;
              } while (cVar2 != '\0');
              FUN_10093f20(iVar7,pcVar13,pcVar14 + (1 - (int)(pcVar13 + 1)));
            }
            iVar8 = FUN_10045010();
            if (iVar8 != 0) {
              pcVar13 = *(char **)(iVar8 + 0x10);
              pcVar14 = pcVar13;
              do {
                cVar2 = *pcVar14;
                pcVar14 = pcVar14 + 1;
              } while (cVar2 != '\0');
              FUN_10093f20((int)in_ECX + 0x5fe5,pcVar13,pcVar14 + (1 - (int)(pcVar13 + 1)));
            }
            iVar8 = FUN_10045010();
            if (iVar8 != 0) {
              pcVar13 = *(char **)(iVar8 + 0x10);
              pcVar14 = pcVar13;
              do {
                cVar2 = *pcVar14;
                pcVar14 = pcVar14 + 1;
              } while (cVar2 != '\0');
              FUN_10093f20((int)in_ECX + 0x60e9,pcVar13,pcVar14 + (1 - (int)(pcVar13 + 1)));
            }
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5bf,
                                 "speed tunnel: get call home switch result, callhomeurl:%s, server_info:%s, callhome_xx:%s.\n"
                                 ,iVar7,(int)in_ECX + 0x5fe5,(int)in_ECX + 0x60e9);
            }
          }
        }
        FUN_1005b330();
        FUN_1005b7a0(1);
        FUN_1005b7a0(0);
LAB_1005daed:
        FUN_10093d10(auStack_10198,0,0x30);
        auStack_10198[0] = 0x54;
        uStack_1018c = 0x20;
        if (in_ECX[0x1675] != 0) {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5f4,
                               "get_ag_config: current virtual ip is %d.%d.%d.%d, must ignore it.\n",
                               *(undefined1 *)(in_ECX + 0x1675),*(undefined1 *)((int)in_ECX + 0x59d5),
                               *(undefined1 *)((int)in_ECX + 0x59d6),*(undefined1 *)((int)in_ECX + 22999));
          }
          iVar7 = DAT_1011e8a8;
          uStack_10184 = in_ECX[0x1675];
          in_ECX[0x1675] = 0;
          if ((iVar7 == 1) || (iVar7 == 2)) {
            DAT_1011e8a8 = 1;
            uStack_10180 = 1;
          }
        }
        uStack_10188 = get_local_address(&uStack_10184,5);
        iVar7 = 0;
        do {
          if ((*(int *)(auStack_10168 + iVar7 * 4 + -0x1c) != 0) && (DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x604,"get_ag_config: get local adapter ip: %d.%d.%d.%d\n",
                               auStack_10168[iVar7 * 4 + -0x1c],auStack_10168[iVar7 * 4 + -0x1b],
                               auStack_10168[iVar7 * 4 + -0x1a],auStack_10168[iVar7 * 4 + -0x19]);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 5);
        iVar7 = get_local_mac_address_forwin32(*in_ECX);
        if (iVar7 == 0) {
          if (DAT_10106410 < 2) {
            pcVar13 = "get_ag_config: get local mac finished\n";
            uVar19 = 0x618;
            uVar18 = 1;
            goto LAB_1005dc4f;
          }
        }
        else if (DAT_10106410 < 4) {
          pcVar13 = "get_ag_config: failed to get local mac address\n";
          uVar19 = 0x616;
          uVar18 = 3;
LAB_1005dc4f:
          array_vpn_logprint(uVar18,"..\\l3vpn\\get_config.c",uVar19,pcVar13);
        }
        uStack_10170 = (undefined1)DAT_10e2a120;
        uStack_1016f = (undefined1)DAT_10e2a124;
        uStack_1016e = DAT_10e2a128;
        uStack_1016d = DAT_10e2a12c;
        uStack_1016c = DAT_10e2a130;
        uStack_1016b = DAT_10e2a134;
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x61f,
                             "Found ether card for MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",(undefined1)DAT_10e2a120,
                             (undefined1)DAT_10e2a124,DAT_10e2a128,DAT_10e2a12c,DAT_10e2a130,DAT_10e2a134);
        }
        iVar7 = SSL_write(in_ECX[0xd],auStack_10198,0x30);
        if (in_ECX[0x10] == 0) {
          if (iVar7 < 1) {
            if (DAT_10106410 < 4) {
              array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x625,
                                 "get_ag_config: failed to send netwrok config request\n");
            }
          }
          else {
            FUN_10065150(iVar7,iVar7 >> 0x1f);
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x62b,"write net config request to ssl tunnel\n");
            }
            pcVar17 = SSL_read_exref;
            iVar7 = 0;
            do {
              iVar8 = SSL_read(in_ECX[0xd],acStack_101b8 + iVar7,0x10 - iVar7);
              if ((iVar8 < 1) || (in_ECX[0x10] != 0)) {
                iVar7 = -1;
                goto LAB_1005dda4;
              }
              iVar7 = iVar7 + iVar8;
            } while (iVar7 < 0x10);
            iVar7 = 0x10;
LAB_1005dda4:
            if (in_ECX[0x10] == 0) {
              if (iVar7 < 1) {
                if (DAT_10106410 < 4) {
                  array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x630,
                                     "get_ag_config: failed to get network config response head: %d\n",iVar7);
                }
              }
              else {
                FUN_100650d0(iVar7,iVar7 >> 0x1f);
                if (acStack_101b8[0] == 'U') {
                  FID_conflict__free(pvStack_101bc);
                  sVar3 = sStack_101ac;
                  pvStack_101bc = _malloc(sStack_101ac);
                  if (pvStack_101bc == (void *)0x0) {
                    pvVar9 = (void *)0x0;
                    if (DAT_10106410 < 4) {
                      array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x644,"failed to allocate memory");
                      FUN_1008fc07();
                      return;
                    }
LAB_1005d380:
                    pvStack_101bc = pvVar9;
                    FUN_1008fc07();
                    return;
                  }
                  if (in_ECX[0xb9e] == 1) {
                    FUN_10093d10(pvStack_101bc,0,sVar3);
                    uVar16 = 0;
                    uVar18 = extraout_ECX_02;
                    if (sStack_101ac != 0) {
                      do {
                        iVar7 = (*pcVar17)(in_ECX[0xd],(int)pvStack_101bc + uVar16,sStack_101ac - uVar16);
                        if (in_ECX[0x10] != 0) goto LAB_1005d97c;
                        if (iVar7 < 1) {
                          if (DAT_10106410 < 4) {
                            array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x64f,
                                               "get_ag_config: failed to get common config data\n");
                          }
                          goto LAB_1005e6aa;
                        }
                        FUN_100650d0(iVar7,iVar7 >> 0x1f);
                        uVar16 = uVar16 + iVar7;
                        uVar18 = extraout_ECX_03;
                        pcVar17 = SSL_read_exref;
                      } while (uVar16 < sStack_101ac);
                    }
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x658,"datalen %d, offset %d, netconfig is:\n%s\n",
                                         sStack_101ac,uVar16,pvStack_101bc);
                      uVar18 = extraout_ECX_04;
                    }
                    iStack_101c0 = FUN_10044ba0(uVar18);
                    if (iStack_101c0 == 0) {
                      if (DAT_10106410 < 4) {
                        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x65d,
                                           "get_ag_config: failed to parse l3vpn config, error: %s\n",DAT_1011f158);
                      }
                      goto LAB_1005e6aa;
                    }
                    iVar7 = FUN_10045010();
                    if (iVar7 != 0) {
                      in_ECX[0x16f2] = *(undefined4 *)(iVar7 + 0x14);
                    }
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x667,"l3vpn resource flags: %d\n",in_ECX[0x16f2]);
                    }
                    iVar7 = DAT_10106410;
                    if ((*(byte *)(in_ECX + 0x16f2) & 1) != 0) {
                      if (DAT_10106410 < 2) {
                        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x66a,"tunnel mode: full tunnel\n");
                      }
                      iVar7 = DAT_10106410;
                      *(undefined1 *)(in_ECX + 0x16df) = 1;
                    }
                    if (((*(byte *)(in_ECX + 0x16f2) & 2) != 0) && (iVar7 < 2)) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x66f,"client subnet: enable\n");
                    }
                    iVar7 = FUN_10045010();
                    if (iVar7 != 0) {
                      in_ECX[0x1675] = *(undefined4 *)(iVar7 + 0x14);
                    }
                    iVar7 = FUN_10045010();
                    if (iVar7 != 0) {
                      in_ECX[0x1676] = *(undefined4 *)(iVar7 + 0x14);
                    }
                    iVar7 = FUN_10045010();
                    if (iVar7 != 0) {
                      pcVar13 = *(char **)(iVar7 + 0x10);
                      pcVar14 = pcVar13;
                      do {
                        cVar2 = *pcVar14;
                        pcVar14 = pcVar14 + 1;
                      } while (cVar2 != '\0');
                      FUN_10093f20(in_ECX + 0x1679,pcVar13,pcVar14 + (1 - (int)(pcVar13 + 1)));
                    }
                    iVar7 = FUN_10045010();
                    if (iVar7 != 0) {
                      pcVar13 = *(char **)(iVar7 + 0x10);
                      pcVar14 = pcVar13;
                      do {
                        cVar2 = *pcVar14;
                        pcVar14 = pcVar14 + 1;
                      } while (cVar2 != '\0');
                      FUN_10093f20(in_ECX + 0x169b,pcVar13,pcVar14 + (1 - (int)(pcVar13 + 1)));
                    }
                    if (in_ECX[0x1675] != 0) {
                      uVar10 = ntohl(in_ECX[0x1676] & in_ECX[0x1675]);
                      uVar10 = htonl(uVar10 + 1);
                      iVar7 = DAT_10106410;
                      in_ECX[0x1677] = uVar10;
                      if (iVar7 < 2) {
                        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x688,"IPv4:%d.%d.%d.%d, mask: %d.%d.%d.%d\n",
                                           *(undefined1 *)(in_ECX + 0x1675),*(undefined1 *)((int)in_ECX + 0x59d5),
                                           *(undefined1 *)((int)in_ECX + 0x59d6),*(undefined1 *)((int)in_ECX + 22999),
                                           *(undefined1 *)(in_ECX + 0x1676),*(undefined1 *)((int)in_ECX + 0x59d9),
                                           *(undefined1 *)((int)in_ECX + 0x59da),*(undefined1 *)((int)in_ECX + 0x59db));
                      }
                    }
                    pcVar13 = (char *)(in_ECX + 0x1679);
                    pcVar14 = pcVar13;
                    do {
                      cVar2 = *pcVar14;
                      pcVar14 = pcVar14 + 1;
                    } while (cVar2 != '\0');
                    if (pcVar14 == (char *)((int)in_ECX + 0x59e5)) {
LAB_1005e1e2:
                      if (DAT_10106410 < 2) {
                        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x690,"Include network list:\n");
                      }
                    }
                    else {
                      array_vpn_get_ipv6_net(pcVar13,in_ECX + 0x169b,0,in_ECX + 0x16bd);
                      if (DAT_10106410 < 2) {
                        uVar18 = array_vpn_get_ipv6_prefix(in_ECX + 0x169b);
                        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x68d,"IPv6:%s/%d\n",pcVar13,uVar18);
                        goto LAB_1005e1e2;
                      }
                    }
                    FUN_1005bd70(1);
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x692,"Exclude network list:\n");
                    }
                    FUN_1005bd70(0);
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x694,"parse_ag_network finished\n");
                    }
                    FUN_1005c520();
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x696,"parse_ag_inside_proxy finished\n");
                    }
                    FUN_1005c670();
                    if (DAT_10106410 < 2) {
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x698,"parse_ag_dns finished\n");
                    }
                    FUN_1005c9d0();
                    if (DAT_10106410 < 2) {
                      pcVar13 = "parse_ag_search_domain finished\n";
                      uVar18 = 0x69a;
LAB_1005e595:
                      array_vpn_logprint(1,"..\\l3vpn\\get_config.c",uVar18,pcVar13);
                    }
LAB_1005e5a4:
                    iVar7 = 0;
                    pcVar13 = (char *)(in_ECX + 0x1466);
                    do {
                      cVar2 = *pcVar13;
                      pcVar13 = pcVar13 + 1;
                    } while (cVar2 != '\0');
                    if (pcVar13 == (char *)((int)in_ECX + 0x5199)) {
                      if ((in_ECX[0x16ee] != 0) && (uVar16 = 0, in_ECX[0x16ec] != 0)) {
                        do {
                          if (DAT_10106410 < 2) {
                            puVar1 = *(undefined1 **)(in_ECX[0x16ee] + uVar16 * 4);
                            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6e2,
                                               "hostmap config: index[%d], %s, %d.%d.%d.%d.\n",uVar16,puVar1 + 4,*puVar1
                                               ,puVar1[1],puVar1[2],puVar1[3]);
                          }
                          uVar10 = htonl(**(u_long **)(in_ECX[0x16ee] + uVar16 * 4));
                          if (((uVar10 == 7) &&
                              (iVar8 = FUN_10090450(*(int *)(in_ECX[0x16ee] + uVar16 * 4) + 4,&DAT_100f1404), iVar8 == 0
                              )) && (iVar8 = FUN_10090450(*(int *)(in_ECX[0x16ee] + uVar16 * 4) + 4,&DAT_100f1408),
                                    iVar8 == 0)) {
                            iVar7 = iVar7 + 1;
                            if (0x10 < iVar7) {
                              iVar7 = 0x10;
                              goto LAB_1005e649;
                            }
                            if (iVar7 == 1) {
                              if (DAT_10106410 < 2) {
                                array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6ef,
                                                   "hostmap config: netpool dns, need clear old dns first.\n");
                              }
                              uVar15 = 0;
                              if (in_ECX[0x16e8] != 0) {
                                do {
                                  *(undefined4 *)(in_ECX[0x16ea] + uVar15 * 4) = 0;
                                  uVar15 = uVar15 + 1;
                                } while (uVar15 < (uint)in_ECX[0x16e8]);
                              }
                            }
                            if (DAT_10106410 < 2) {
                              array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6f6,
                                                 "hostmap config: netpool dns add to dns config, index=%d, dns server=%s.\n"
                                                 ,iVar7,*(int *)(in_ECX[0x16ee] + uVar16 * 4) + 4);
                            }
                            uVar12 = inet_addr((char *)(*(int *)(in_ECX[0x16ee] + uVar16 * 4) + 4));
                            *(ulong *)(in_ECX[0x16ea] + -4 + iVar7 * 4) = uVar12;
                          }
                          uVar16 = uVar16 + 1;
                        } while (uVar16 < (uint)in_ECX[0x16ec]);
                        goto LAB_1005e645;
                      }
                    }
                    else {
                      if (DAT_10106410 < 2) {
                        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6ca,
                                           "custom dns config: netpool dns, need clear old dns first.\n");
                      }
                      uVar16 = 0;
                      if (in_ECX[0x16e8] != 0) {
                        do {
                          *(undefined4 *)(in_ECX[0x16ea] + uVar16 * 4) = 0;
                          uVar16 = uVar16 + 1;
                        } while (uVar16 < (uint)in_ECX[0x16e8]);
                      }
                      pcVar13 = (char *)FUN_1009315e(in_ECX + 0x1466,&DAT_100e3994);
                      if (pcVar13 != (char *)0x0) {
                        do {
                          uVar12 = inet_addr(pcVar13);
                          *(ulong *)(in_ECX[0x16ea] + iVar7 * 4) = uVar12;
                          iVar7 = iVar7 + 1;
                          pcVar13 = (char *)FUN_1009315e(0,&DAT_100e3994);
                          if (iVar7 == 0x10) break;
                        } while (pcVar13 != (char *)0x0);
LAB_1005e645:
                        if (0 < iVar7) {
LAB_1005e649:
                          in_ECX[0x16e8] = iVar7;
                        }
                      }
                    }
                    uVar16 = 0;
                    if (in_ECX[0x16e8] != 0) {
                      do {
                        if (DAT_10106410 < 2) {
                          puVar1 = (undefined1 *)(in_ECX[0x16ea] + uVar16 * 4);
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x704,"dns config: index[%d], %d.%d.%d.%d.\n",
                                             uVar16,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
                        }
                        uVar16 = uVar16 + 1;
                      } while (uVar16 < (uint)in_ECX[0x16e8]);
                    }
                  }
                  else {
                    auStack_10130[8] = 0;
                    auStack_10130[0] = 0;
                    auStack_10130[1] = 0;
                    auStack_10130[2] = 0;
                    auStack_10130[3] = 0;
                    iVar7 = 0;
                    auStack_10130[4] = 0;
                    auStack_10130[5] = 0;
                    auStack_10130[6] = 0;
                    auStack_10130[7] = 0;
                    do {
                      iVar8 = SSL_read(in_ECX[0xd],(int)auStack_10130 + iVar7,0x24 - iVar7);
                      if ((iVar8 < 1) || (in_ECX[0x10] != 0)) {
                        iVar7 = -1;
                        goto LAB_1005e338;
                      }
                      iVar7 = iVar7 + iVar8;
                    } while (iVar7 < 0x24);
                    iVar7 = 0x24;
LAB_1005e338:
                    if (in_ECX[0x10] == 0) {
                      if (0 < iVar7) {
                        FUN_100650d0(iVar7,iVar7 >> 0x1f);
                        in_ECX[0x16f2] = auStack_10130[0];
                        if ((auStack_10130[0] & 1) != 0) {
                          if (DAT_10106410 < 2) {
                            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6ab,"tunnel mode: full tunnel\n");
                          }
                          *(undefined1 *)(in_ECX + 0x16df) = 1;
                        }
                        if (((auStack_10130[0] & 2) != 0) && (DAT_10106410 < 2)) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6af,"client subnet: enable\n");
                        }
                        in_ECX[0x1676] = auStack_10130[5];
                        in_ECX[0x1675] = auStack_10130[4];
                        uVar10 = ntohl(auStack_10130[5] & auStack_10130[4]);
                        uVar10 = htonl(uVar10 + 1);
                        iVar7 = DAT_10106410;
                        in_ECX[0x1677] = uVar10;
                        if ((iVar7 < 2) &&
                           (array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6b6,"IP:%d.%d.%d.%d, mask: %d.%d.%d.%d\n",
                                               auStack_10130[4] & 0xff,auStack_10130[4] >> 8 & 0xff,
                                               auStack_10130[4] >> 0x10 & 0xff,auStack_10130[4] >> 0x18,
                                               auStack_10130[5] & 0xff,auStack_10130[5] >> 8 & 0xff,
                                               auStack_10130[5] >> 0x10 & 0xff,auStack_10130[5] >> 0x18),
                           DAT_10106410 < 2)) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6b8,"Include network list:\n");
                        }
                        FUN_1005a900(1);
                        if (DAT_10106410 < 2) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6ba,"Exclude network list:\n");
                        }
                        FUN_1005a900(0);
                        FUN_1005aca0();
                        if (DAT_10106410 < 2) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6be,"get_ag_inside_proxy finished\n");
                        }
                        FUN_1005ae50();
                        if (DAT_10106410 < 2) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6c0,"get_ag_dns finished\n");
                        }
                        FUN_1005b090();
                        if (DAT_10106410 < 2) {
                          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x6c2,"get_ag_wins finished\n");
                        }
                        FUN_1005b220();
                        if (DAT_10106410 < 2) {
                          pcVar13 = "get_ag_search_domain finished\n";
                          uVar18 = 0x6c4;
                          goto LAB_1005e595;
                        }
                        goto LAB_1005e5a4;
                      }
                      if (DAT_10106410 < 4) {
                        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x6a1,
                                           "get_ag_config: failed to get network config data\n");
                      }
                    }
                    else {
                      in_ECX[0x11] = 0x29;
                    }
                  }
                }
                else if (DAT_10106410 < 4) {
                  array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x638,
                                     "get_ag_config: invalid network config response, msg type: %d\n",acStack_101b8[0]);
                }
              }
            }
            else {
              in_ECX[0x11] = 0x29;
            }
          }
        }
        else {
          in_ECX[0x11] = 0x29;
        }
      }
    }
  }
  else {
    iVar7 = 0;
    do {
      iVar8 = SSL_read(in_ECX[0xd],auStack_10168 + iVar7,0x38 - iVar7);
      if ((iVar8 < 1) || (in_ECX[0x10] != 0)) {
        iVar7 = -1;
        goto LAB_1005d977;
      }
      iVar7 = iVar7 + iVar8;
    } while (iVar7 < 0x38);
    iVar7 = 0x38;
LAB_1005d977:
    if (in_ECX[0x10] == 0) {
      if (iVar7 < 1) {
        if (DAT_10106410 < 4) {
          array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x5cd,"get_ag_config: failed to get common config data\n");
        }
      }
      else {
        FUN_100650d0(iVar7,iVar7 >> 0x1f);
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5d4,"get_ag_config: netpool flags: [0x%x]\n",uStack_10164);
        }
        iVar7 = DAT_10106410;
        if ((uStack_10164 & 0x100) != 0) {
          in_ECX[0x16f1] = uStack_10164;
          in_ECX[0x1678] = uStack_10160;
          if ((iVar7 < 2) &&
             (array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5df,"keep alive interval: [%d]\n",uStack_10160),
             DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x5e2,"speed tunnel: [%d], encrypt: [%d]\n",uStack_10134,
                               uStack_10133);
          }
          *(undefined1 *)((int)in_ECX + 0x5b7d) = uStack_10134;
          *(undefined1 *)((int)in_ECX + 0x5b7e) = uStack_10133;
          FUN_1005a1b0();
          FUN_1005a560(1);
          FUN_1005a560(0);
          goto LAB_1005daed;
        }
        if (DAT_10106410 < 4) {
          uVar10 = ntohl(uStack_10164);
          array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0x5d7,"get_ag_config: l3vpn is not enabled, flags: [%x], %x\n",
                             uStack_10164,uVar10);
        }
      }
    }
    else {
LAB_1005d97c:
      in_ECX[0x11] = 0x29;
    }
  }
LAB_1005e6aa:
  FID_conflict__free(pvStack_101bc);
  if (iStack_101c0 != 0) {
    FUN_100446c0();
  }
LAB_1005e6c9:
  FUN_1008fc07();
  return;
}


// ----- callee: array_vpn_logprint @ 10047f50

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void array_vpn_logprint(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 *puVar6;
  int *piVar7;
  CHAR *pCVar8;
  char *pcVar9;
  _SYSTEMTIME local_101c;
  CHAR local_100c [4093];
  undefined1 local_f [7];
  undefined4 local_8;
  
                    /* 0x47f50  60  array_vpn_logprint */
  local_8 = DAT_101052f0 ^ (uint)(local_f + 0xb);
  pCVar8 = local_100c;
  if (DAT_10106410 <= param_1) {
    if ((DAT_10106418 & 4) != 0) {
      GetLocalTime(&local_101c);
      iVar2 = FUN_100907eb(pCVar8,0x80,"%02d-%02d-%02d %02d-%02d-%02d.%03d ",local_101c.wYear,local_101c.wMonth,
                           local_101c.wDay,local_101c.wHour,local_101c.wMinute,local_101c.wSecond,
                           local_101c.wMilliseconds);
      pCVar8 = pCVar8 + iVar2;
    }
    if (param_1 == 0) {
      pcVar9 = "(DEBUG): ";
    }
    else if (param_1 == 2) {
      pcVar9 = "(WARNING): ";
    }
    else if (param_1 == 3) {
      pcVar9 = "(ERROR): ";
    }
    else {
      pcVar9 = "(INFO): ";
    }
    iVar2 = FUN_100907eb(pCVar8,0x20,&DAT_100e861c,pcVar9);
    pCVar8 = pCVar8 + iVar2;
    DVar3 = GetCurrentThreadId();
    DVar4 = GetCurrentProcessId();
    iVar2 = FUN_100907eb(pCVar8,0x40,"P-%u, T-%u ",DVar4,DVar3);
    pCVar8 = pCVar8 + iVar2;
    iVar2 = FUN_100907eb(pCVar8,0x80,"%s:%u ",param_2,param_3);
    pcVar9 = &DAT_1011c800;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (pcVar9 == &DAT_1011c801) {
      FUN_10047eb0();
    }
    iVar5 = FUN_100907eb(pCVar8 + iVar2,0x80,"<%s> ",&DAT_1011c800);
    pCVar8 = pCVar8 + iVar2 + iVar5;
    puVar6 = (undefined1 *)FUN_1009c02f(pCVar8,local_f + -(int)pCVar8,param_4,&param_5);
    if ((int)puVar6 < 1) {
      piVar7 = __errno();
      if (*piVar7 != 0x22) {
        piVar7 = __errno();
        FUN_10091a4e("logprint: vsnprintf return %d, error %d\n",puVar6,*piVar7);
        FUN_1008fc07();
        return;
      }
      puVar6 = local_f + -(int)pCVar8;
    }
    pCVar8 = pCVar8 + (int)puVar6;
    if (pCVar8[-1] != '\n') {
      pCVar8[0] = '\r';
      pCVar8[1] = '\n';
      pCVar8 = pCVar8 + 2;
    }
    *pCVar8 = '\0';
    if (((DAT_10106418 & 0x20) != 0) && (DAT_10106414 != -1)) {
      FUN_10092152(DAT_10106414,local_100c,(int)pCVar8 - (int)local_100c);
    }
    if ((DAT_10106418 & 8) != 0) {
      OutputDebugStringA(local_100c);
    }
    if ((DAT_10106418 & 1) != 0) {
      FUN_10091a4e(&DAT_100e3ff8,local_100c);
    }
    if (DAT_1010c484 != (code *)0x0) {
      (*DAT_1010c484)(param_1,local_100c);
    }
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10093f20 @ 10093f20

/* WARNING: Control flow encountered bad instruction data */

undefined8 * FUN_10093f20(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined8 *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined8 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  
  if ((param_2 < param_1) && (param_1 < (undefined8 *)(param_3 + (int)param_2))) {
    puVar20 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar21 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar21 & 3) == 0) {
      uVar16 = param_3 >> 2;
      param_3 = param_3 & 3;
      if (7 < uVar16) {
        for (; uVar16 != 0; uVar16 = uVar16 - 1) {
          *puVar21 = *puVar20;
          puVar20 = puVar20 + -1;
          puVar21 = puVar21 + -1;
        }
        switch(param_3) {
        case 0:
          return param_1;
        case 2:
          goto switchD_100942c7_caseD_2;
        case 3:
          goto switchD_100942c7_caseD_3;
        }
        goto switchD_100942c7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_100942c7_caseD_0;
      case 1:
        goto switchD_100942c7_caseD_1;
      case 2:
        goto switchD_100942c7_caseD_2;
      case 3:
        goto switchD_100942c7_caseD_3;
      default:
        uVar16 = param_3 - ((uint)puVar21 & 3);
        switch((uint)puVar21 & 3) {
        case 1:
          param_3 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          puVar20 = (undefined4 *)((int)puVar20 + -1);
          uVar16 = uVar16 >> 2;
          puVar21 = (undefined4 *)((int)puVar21 - 1);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_100942c7_caseD_2;
            case 3:
              goto switchD_100942c7_caseD_3;
            }
            goto switchD_100942c7_caseD_1;
          }
          break;
        case 2:
          param_3 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          uVar16 = uVar16 >> 2;
          *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
          puVar20 = (undefined4 *)((int)puVar20 + -2);
          puVar21 = (undefined4 *)((int)puVar21 - 2);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_100942c7_caseD_2;
            case 3:
              goto switchD_100942c7_caseD_3;
            }
            goto switchD_100942c7_caseD_1;
          }
          break;
        case 3:
          param_3 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
          uVar16 = uVar16 >> 2;
          *(undefined1 *)((int)puVar21 + 1) = *(undefined1 *)((int)puVar20 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + -3);
          puVar21 = (undefined4 *)((int)puVar21 - 3);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(param_3) {
            case 0:
              return param_1;
            case 2:
              goto switchD_100942c7_caseD_2;
            case 3:
              goto switchD_100942c7_caseD_3;
            }
            goto switchD_100942c7_caseD_1;
          }
        }
      }
    }
    switch(uVar16) {
    case 7:
      puVar21[7 - uVar16] = puVar20[7 - uVar16];
    case 6:
      puVar21[6 - uVar16] = puVar20[6 - uVar16];
    case 5:
      puVar21[5 - uVar16] = puVar20[5 - uVar16];
    case 4:
      puVar21[4 - uVar16] = puVar20[4 - uVar16];
    case 3:
      puVar21[3 - uVar16] = puVar20[3 - uVar16];
    case 2:
      puVar21[2 - uVar16] = puVar20[2 - uVar16];
    case 1:
      puVar21[1 - uVar16] = puVar20[1 - uVar16];
      puVar20 = puVar20 + -uVar16;
      puVar21 = puVar21 + -uVar16;
    }
    switch(param_3) {
    case 1:
switchD_100942c7_caseD_1:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      return param_1;
    case 2:
switchD_100942c7_caseD_2:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
      return param_1;
    case 3:
switchD_100942c7_caseD_3:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
      *(undefined1 *)((int)puVar21 + 1) = *(undefined1 *)((int)puVar20 + 1);
      return param_1;
    }
switchD_100942c7_caseD_0:
    return param_1;
  }
  puVar15 = param_1;
  if ((DAT_1010bd98 >> 1 & 1) != 0) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)puVar15 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      puVar15 = (undefined8 *)((int)puVar15 + 1);
    }
    return param_1;
  }
  if (param_3 < 0x80) {
LAB_1009412b:
    if (((uint)param_1 & 3) == 0) goto LAB_10094133;
LAB_10094148:
    switch(param_3) {
    case 0:
      goto switchD_10094140_caseD_0;
    case 1:
      goto switchD_10094140_caseD_1;
    case 2:
      goto switchD_10094140_caseD_2;
    case 3:
      goto switchD_10094140_caseD_3;
    default:
      uVar16 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        param_3 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar16 = uVar16 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined8 *)((int)param_2 + 3);
        puVar15 = (undefined8 *)((int)param_1 + 3);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10094140_caseD_2;
          case 3:
            goto switchD_10094140_caseD_3;
          }
          goto switchD_10094140_caseD_1;
        }
        break;
      case 2:
        param_3 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar16 = uVar16 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined8 *)((int)param_2 + 2);
        puVar15 = (undefined8 *)((int)param_1 + 2);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10094140_caseD_2;
          case 3:
            goto switchD_10094140_caseD_3;
          }
          goto switchD_10094140_caseD_1;
        }
        break;
      case 3:
        param_3 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined8 *)((int)param_2 + 1);
        uVar16 = uVar16 >> 2;
        puVar15 = (undefined8 *)((int)param_1 + 1);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(param_3) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10094140_caseD_2;
          case 3:
            goto switchD_10094140_caseD_3;
          }
          goto switchD_10094140_caseD_1;
        }
      }
    }
  }
  else {
    if (((((uint)param_1 ^ (uint)param_2) & 0xf) == 0) && ((DAT_10105a90 >> 1 & 1) != 0)) {
      if (((uint)param_2 & 0xf) != 0) {
        uVar17 = 0x10 - ((uint)param_2 & 0xf);
        param_3 = param_3 - uVar17;
        for (uVar16 = uVar17 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined1 *)puVar15 = *(undefined1 *)param_2;
          param_2 = (undefined8 *)((int)param_2 + 1);
          puVar15 = (undefined8 *)((int)puVar15 + 1);
        }
        for (uVar17 = uVar17 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)puVar15 = *(undefined4 *)param_2;
          param_2 = (undefined8 *)((int)param_2 + 4);
          puVar15 = (undefined8 *)((int)puVar15 + 4);
        }
      }
      for (uVar16 = param_3 >> 7; uVar16 != 0; uVar16 = uVar16 - 1) {
        uVar22 = *(undefined4 *)((int)param_2 + 4);
        uVar23 = *(undefined4 *)(param_2 + 1);
        uVar24 = *(undefined4 *)((int)param_2 + 0xc);
        uVar2 = *(undefined4 *)(param_2 + 2);
        uVar3 = *(undefined4 *)((int)param_2 + 0x14);
        uVar4 = *(undefined4 *)(param_2 + 3);
        uVar5 = *(undefined4 *)((int)param_2 + 0x1c);
        uVar6 = *(undefined4 *)(param_2 + 4);
        uVar7 = *(undefined4 *)((int)param_2 + 0x24);
        uVar8 = *(undefined4 *)(param_2 + 5);
        uVar9 = *(undefined4 *)((int)param_2 + 0x2c);
        uVar10 = *(undefined4 *)(param_2 + 6);
        uVar11 = *(undefined4 *)((int)param_2 + 0x34);
        uVar12 = *(undefined4 *)(param_2 + 7);
        uVar13 = *(undefined4 *)((int)param_2 + 0x3c);
        *(undefined4 *)puVar15 = *(undefined4 *)param_2;
        *(undefined4 *)((int)puVar15 + 4) = uVar22;
        *(undefined4 *)(puVar15 + 1) = uVar23;
        *(undefined4 *)((int)puVar15 + 0xc) = uVar24;
        *(undefined4 *)(puVar15 + 2) = uVar2;
        *(undefined4 *)((int)puVar15 + 0x14) = uVar3;
        *(undefined4 *)(puVar15 + 3) = uVar4;
        *(undefined4 *)((int)puVar15 + 0x1c) = uVar5;
        *(undefined4 *)(puVar15 + 4) = uVar6;
        *(undefined4 *)((int)puVar15 + 0x24) = uVar7;
        *(undefined4 *)(puVar15 + 5) = uVar8;
        *(undefined4 *)((int)puVar15 + 0x2c) = uVar9;
        *(undefined4 *)(puVar15 + 6) = uVar10;
        *(undefined4 *)((int)puVar15 + 0x34) = uVar11;
        *(undefined4 *)(puVar15 + 7) = uVar12;
        *(undefined4 *)((int)puVar15 + 0x3c) = uVar13;
        uVar22 = *(undefined4 *)((int)param_2 + 0x44);
        uVar23 = *(undefined4 *)(param_2 + 9);
        uVar24 = *(undefined4 *)((int)param_2 + 0x4c);
        uVar2 = *(undefined4 *)(param_2 + 10);
        uVar3 = *(undefined4 *)((int)param_2 + 0x54);
        uVar4 = *(undefined4 *)(param_2 + 0xb);
        uVar5 = *(undefined4 *)((int)param_2 + 0x5c);
        uVar6 = *(undefined4 *)(param_2 + 0xc);
        uVar7 = *(undefined4 *)((int)param_2 + 100);
        uVar8 = *(undefined4 *)(param_2 + 0xd);
        uVar9 = *(undefined4 *)((int)param_2 + 0x6c);
        uVar10 = *(undefined4 *)(param_2 + 0xe);
        uVar11 = *(undefined4 *)((int)param_2 + 0x74);
        uVar12 = *(undefined4 *)(param_2 + 0xf);
        uVar13 = *(undefined4 *)((int)param_2 + 0x7c);
        *(undefined4 *)(puVar15 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)((int)puVar15 + 0x44) = uVar22;
        *(undefined4 *)(puVar15 + 9) = uVar23;
        *(undefined4 *)((int)puVar15 + 0x4c) = uVar24;
        *(undefined4 *)(puVar15 + 10) = uVar2;
        *(undefined4 *)((int)puVar15 + 0x54) = uVar3;
        *(undefined4 *)(puVar15 + 0xb) = uVar4;
        *(undefined4 *)((int)puVar15 + 0x5c) = uVar5;
        *(undefined4 *)(puVar15 + 0xc) = uVar6;
        *(undefined4 *)((int)puVar15 + 100) = uVar7;
        *(undefined4 *)(puVar15 + 0xd) = uVar8;
        *(undefined4 *)((int)puVar15 + 0x6c) = uVar9;
        *(undefined4 *)(puVar15 + 0xe) = uVar10;
        *(undefined4 *)((int)puVar15 + 0x74) = uVar11;
        *(undefined4 *)(puVar15 + 0xf) = uVar12;
        *(undefined4 *)((int)puVar15 + 0x7c) = uVar13;
        param_2 = param_2 + 0x10;
        puVar15 = puVar15 + 0x10;
      }
      if ((param_3 & 0x7f) != 0) {
        for (uVar16 = (param_3 & 0x7f) >> 4; uVar16 != 0; uVar16 = uVar16 - 1) {
          uVar22 = *(undefined4 *)((int)param_2 + 4);
          uVar23 = *(undefined4 *)(param_2 + 1);
          uVar24 = *(undefined4 *)((int)param_2 + 0xc);
          *(undefined4 *)puVar15 = *(undefined4 *)param_2;
          *(undefined4 *)((int)puVar15 + 4) = uVar22;
          *(undefined4 *)(puVar15 + 1) = uVar23;
          *(undefined4 *)((int)puVar15 + 0xc) = uVar24;
          param_2 = param_2 + 2;
          puVar15 = puVar15 + 2;
        }
        if ((param_3 & 0xf) != 0) {
          for (uVar16 = (param_3 & 0xf) >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
            *(undefined1 *)puVar15 = *(undefined1 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 1);
            puVar15 = (undefined8 *)((int)puVar15 + 1);
          }
        }
      }
      return param_1;
    }
    if ((DAT_1010bd98 & 1) == 0) goto LAB_1009412b;
    if (((uint)param_1 & 3) != 0) goto LAB_10094148;
    if (((uint)param_2 & 3) == 0) {
      if (((uint)param_1 >> 2 & 1) != 0) {
        uVar22 = *(undefined4 *)param_2;
        param_3 = param_3 - 4;
        param_2 = (undefined8 *)((int)param_2 + 4);
        *(undefined4 *)param_1 = uVar22;
        param_1 = (undefined8 *)((int)param_1 + 4);
      }
      if (((uint)param_1 >> 3 & 1) != 0) {
        uVar1 = *param_2;
        param_3 = param_3 - 8;
        param_2 = param_2 + 1;
        *param_1 = uVar1;
        param_1 = param_1 + 1;
      }
      if (((uint)param_2 & 7) == 0) {
        puVar15 = param_2 + -1;
        uVar22 = *(undefined4 *)param_2;
        uVar23 = *(undefined4 *)((int)param_2 + 4);
        do {
          puVar19 = puVar15;
          uVar3 = *(undefined4 *)(puVar19 + 2);
          uVar4 = *(undefined4 *)((int)puVar19 + 0x14);
          param_3 = param_3 - 0x30;
          uVar5 = *(undefined4 *)(puVar19 + 3);
          uVar6 = *(undefined4 *)((int)puVar19 + 0x1c);
          uVar7 = *(undefined4 *)(puVar19 + 4);
          uVar8 = *(undefined4 *)((int)puVar19 + 0x24);
          uVar24 = *(undefined4 *)(puVar19 + 7);
          uVar2 = *(undefined4 *)((int)puVar19 + 0x3c);
          uVar9 = *(undefined4 *)(puVar19 + 5);
          uVar10 = *(undefined4 *)((int)puVar19 + 0x2c);
          uVar11 = *(undefined4 *)(puVar19 + 6);
          uVar12 = *(undefined4 *)((int)puVar19 + 0x34);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar23;
          *(undefined4 *)(param_1 + 1) = uVar3;
          *(undefined4 *)((int)param_1 + 0xc) = uVar4;
          *(undefined4 *)(param_1 + 2) = uVar5;
          *(undefined4 *)((int)param_1 + 0x14) = uVar6;
          *(undefined4 *)(param_1 + 3) = uVar7;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar8;
          *(undefined4 *)(param_1 + 4) = uVar9;
          *(undefined4 *)((int)param_1 + 0x24) = uVar10;
          *(undefined4 *)(param_1 + 5) = uVar11;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar12;
          param_1 = param_1 + 6;
          puVar15 = puVar19 + 6;
          uVar22 = uVar24;
          uVar23 = uVar2;
        } while (0x2f < (int)param_3);
        puVar19 = puVar19 + 7;
      }
      else if (((uint)param_2 >> 3 & 1) == 0) {
        iVar14 = (int)param_2 + -4;
        uVar22 = *(undefined4 *)param_2;
        uVar23 = *(undefined4 *)((int)param_2 + 4);
        uVar24 = *(undefined4 *)(param_2 + 1);
        do {
          iVar18 = iVar14;
          uVar5 = *(undefined4 *)(iVar18 + 0x10);
          param_3 = param_3 - 0x30;
          uVar6 = *(undefined4 *)(iVar18 + 0x14);
          uVar7 = *(undefined4 *)(iVar18 + 0x18);
          uVar8 = *(undefined4 *)(iVar18 + 0x1c);
          uVar9 = *(undefined4 *)(iVar18 + 0x20);
          uVar2 = *(undefined4 *)(iVar18 + 0x34);
          uVar3 = *(undefined4 *)(iVar18 + 0x38);
          uVar4 = *(undefined4 *)(iVar18 + 0x3c);
          uVar10 = *(undefined4 *)(iVar18 + 0x24);
          uVar11 = *(undefined4 *)(iVar18 + 0x28);
          uVar12 = *(undefined4 *)(iVar18 + 0x2c);
          uVar13 = *(undefined4 *)(iVar18 + 0x30);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar23;
          *(undefined4 *)(param_1 + 1) = uVar24;
          *(undefined4 *)((int)param_1 + 0xc) = uVar5;
          *(undefined4 *)(param_1 + 2) = uVar6;
          *(undefined4 *)((int)param_1 + 0x14) = uVar7;
          *(undefined4 *)(param_1 + 3) = uVar8;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar9;
          *(undefined4 *)(param_1 + 4) = uVar10;
          *(undefined4 *)((int)param_1 + 0x24) = uVar11;
          *(undefined4 *)(param_1 + 5) = uVar12;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar13;
          param_1 = param_1 + 6;
          iVar14 = iVar18 + 0x30;
          uVar22 = uVar2;
          uVar23 = uVar3;
          uVar24 = uVar4;
        } while (0x2f < (int)param_3);
        puVar19 = (undefined8 *)(iVar18 + 0x34);
      }
      else {
        iVar14 = (int)param_2 + -0xc;
        uVar22 = *(undefined4 *)param_2;
        do {
          iVar18 = iVar14;
          uVar24 = *(undefined4 *)(iVar18 + 0x10);
          uVar2 = *(undefined4 *)(iVar18 + 0x14);
          uVar3 = *(undefined4 *)(iVar18 + 0x18);
          param_3 = param_3 - 0x30;
          uVar4 = *(undefined4 *)(iVar18 + 0x1c);
          uVar5 = *(undefined4 *)(iVar18 + 0x20);
          uVar6 = *(undefined4 *)(iVar18 + 0x24);
          uVar7 = *(undefined4 *)(iVar18 + 0x28);
          uVar23 = *(undefined4 *)(iVar18 + 0x3c);
          uVar8 = *(undefined4 *)(iVar18 + 0x2c);
          uVar9 = *(undefined4 *)(iVar18 + 0x30);
          uVar10 = *(undefined4 *)(iVar18 + 0x34);
          uVar11 = *(undefined4 *)(iVar18 + 0x38);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar24;
          *(undefined4 *)(param_1 + 1) = uVar2;
          *(undefined4 *)((int)param_1 + 0xc) = uVar3;
          *(undefined4 *)(param_1 + 2) = uVar4;
          *(undefined4 *)((int)param_1 + 0x14) = uVar5;
          *(undefined4 *)(param_1 + 3) = uVar6;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar7;
          *(undefined4 *)(param_1 + 4) = uVar8;
          *(undefined4 *)((int)param_1 + 0x24) = uVar9;
          *(undefined4 *)(param_1 + 5) = uVar10;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar11;
          param_1 = param_1 + 6;
          iVar14 = iVar18 + 0x30;
          uVar22 = uVar23;
        } while (0x2f < (int)param_3);
        puVar19 = (undefined8 *)(iVar18 + 0x3c);
      }
      for (; 0xf < (int)param_3; param_3 = param_3 - 0x10) {
        uVar22 = *(undefined4 *)puVar19;
        uVar23 = *(undefined4 *)((int)puVar19 + 4);
        uVar24 = *(undefined4 *)(puVar19 + 1);
        uVar2 = *(undefined4 *)((int)puVar19 + 0xc);
        puVar19 = puVar19 + 2;
        *(undefined4 *)param_1 = uVar22;
        *(undefined4 *)((int)param_1 + 4) = uVar23;
        *(undefined4 *)(param_1 + 1) = uVar24;
        *(undefined4 *)((int)param_1 + 0xc) = uVar2;
        param_1 = param_1 + 2;
      }
      if ((param_3 >> 2 & 1) != 0) {
        uVar22 = *(undefined4 *)puVar19;
        param_3 = param_3 - 4;
        puVar19 = (undefined8 *)((int)puVar19 + 4);
        *(undefined4 *)param_1 = uVar22;
        param_1 = (undefined8 *)((int)param_1 + 4);
      }
      if ((param_3 >> 3 & 1) != 0) {
        param_3 = param_3 - 8;
        *param_1 = *puVar19;
      }
                    /* WARNING: Could not recover jumptable at 0x10094129. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar15 = (undefined8 *)(*(code *)(&switchD_10094140::switchdataD_10094258)[param_3])();
      return puVar15;
    }
LAB_10094133:
    uVar16 = param_3 >> 2;
    param_3 = param_3 & 3;
    if (7 < uVar16) {
      for (; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)puVar15 = *(undefined4 *)param_2;
        param_2 = (undefined8 *)((int)param_2 + 4);
        puVar15 = (undefined8 *)((int)puVar15 + 4);
      }
      switch(param_3) {
      case 0:
        return param_1;
      case 2:
        goto switchD_10094140_caseD_2;
      case 3:
        goto switchD_10094140_caseD_3;
      }
      goto switchD_10094140_caseD_1;
    }
  }
  switch(uVar16) {
  case 7:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x1c) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x1c);
  case 6:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x18) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x18);
  case 5:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x14) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x14);
  case 4:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x10) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x10);
  case 3:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0xc) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -0xc);
  case 2:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -8) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -8);
  case 1:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -4) = *(undefined4 *)((int)param_2 + uVar16 * 4 + -4);
    param_2 = (undefined8 *)((int)param_2 + uVar16 * 4);
    puVar15 = (undefined8 *)((int)puVar15 + uVar16 * 4);
  }
  switch(param_3) {
  case 0:
switchD_10094140_caseD_0:
    return param_1;
  case 2:
switchD_10094140_caseD_2:
    *(undefined1 *)puVar15 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar15 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_10094140_caseD_3:
    *(undefined1 *)puVar15 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar15 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar15 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_10094140_caseD_1:
  *(undefined1 *)puVar15 = *(undefined1 *)param_2;
  return param_1;
}


// ----- callee: FUN_1008fc07 @ 1008fc07

void FUN_1008fc07(void)

{
  int in_ECX;
  
  if (in_ECX != DAT_101052f0) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: SSLEAY32.DLL::SSL_read @ EXTERNAL:00000056
// decompile failed: Exception while decompiling EXTERNAL:00000056: Cannot marshal address space: EXTERNAL

// ----- callee: _malloc @ 100903b4

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2012 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  size_t dwBytes;
  
  if (_Size < 0xffffffe1) {
    do {
      if (DAT_1010b758 == (HANDLE)0x0) {
        __FF_MSGBANNER();
        FUN_1009bcf9(0x1e);
        ___crtExitProcess(0xff);
      }
      if (_Size == 0) {
        dwBytes = 1;
      }
      else {
        dwBytes = _Size;
      }
      pvVar1 = HeapAlloc(DAT_1010b758,0,dwBytes);
      if (pvVar1 != (LPVOID)0x0) goto LAB_10090443;
      if (DAT_1010bd90 == 0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        break;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  else {
    __callnewh(_Size);
    piVar3 = __errno();
    *piVar3 = 0xc;
    pvVar1 = (void *)0x0;
  }
LAB_10090443:
  return pvVar1;
}


// ----- callee: _realloc @ 100920a7

/* Library Function - Single Match
    _realloc
   
   Library: Visual Studio 2012 Release */

void * __cdecl _realloc(void *_Memory,size_t _NewSize)

{
  void *pvVar1;
  LPVOID pvVar2;
  int iVar3;
  int *piVar4;
  DWORD DVar5;
  
  if (_Memory == (void *)0x0) {
    pvVar1 = _malloc(_NewSize);
    return pvVar1;
  }
  if (_NewSize == 0) {
    FID_conflict__free(_Memory);
  }
  else {
    do {
      if (0xffffffe0 < _NewSize) {
        __callnewh(_NewSize);
        piVar4 = __errno();
        *piVar4 = 0xc;
        return (void *)0x0;
      }
      if (_NewSize == 0) {
        _NewSize = 1;
      }
      pvVar2 = HeapReAlloc(DAT_1010b758,0,_Memory,_NewSize);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
      if (DAT_1010bd90 == 0) {
        piVar4 = __errno();
        DVar5 = GetLastError();
        iVar3 = __get_errno_from_oserr(DVar5);
        *piVar4 = iVar3;
        return (void *)0x0;
      }
      iVar3 = __callnewh(_NewSize);
    } while (iVar3 != 0);
    piVar4 = __errno();
    DVar5 = GetLastError();
    iVar3 = __get_errno_from_oserr(DVar5);
    *piVar4 = iVar3;
  }
  return (void *)0x0;
}


// ----- callee: WS2_32.DLL::ntohl @ EXTERNAL:00000012
// decompile failed: Exception while decompiling EXTERNAL:00000012: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_10093d10 @ 10093d10

uint * FUN_10093d10(uint *param_1,byte param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return param_1;
  }
  uVar1 = (uint)param_2;
  if ((DAT_1010bd98 >> 1 & 1) == 0) {
    if ((0x7f < (int)param_3) && ((DAT_10105a90 >> 1 & 1) != 0)) {
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
      }
      puVar4 = param_1;
      if (((uint)param_1 & 0xf) != 0) {
        uVar2 = 0x10 - ((uint)param_1 & 0xf);
        param_3 = param_3 - uVar2;
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
        }
        for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
      }
      for (uVar3 = param_3 >> 7; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = uVar1;
        puVar4[1] = uVar1;
        puVar4[2] = uVar1;
        puVar4[3] = uVar1;
        puVar4[4] = uVar1;
        puVar4[5] = uVar1;
        puVar4[6] = uVar1;
        puVar4[7] = uVar1;
        puVar4[8] = uVar1;
        puVar4[9] = uVar1;
        puVar4[10] = uVar1;
        puVar4[0xb] = uVar1;
        puVar4[0xc] = uVar1;
        puVar4[0xd] = uVar1;
        puVar4[0xe] = uVar1;
        puVar4[0xf] = uVar1;
        puVar4[0x10] = uVar1;
        puVar4[0x11] = uVar1;
        puVar4[0x12] = uVar1;
        puVar4[0x13] = uVar1;
        puVar4[0x14] = uVar1;
        puVar4[0x15] = uVar1;
        puVar4[0x16] = uVar1;
        puVar4[0x17] = uVar1;
        puVar4[0x18] = uVar1;
        puVar4[0x19] = uVar1;
        puVar4[0x1a] = uVar1;
        puVar4[0x1b] = uVar1;
        puVar4[0x1c] = uVar1;
        puVar4[0x1d] = uVar1;
        puVar4[0x1e] = uVar1;
        puVar4[0x1f] = uVar1;
        puVar4 = puVar4 + 0x20;
      }
      if ((param_3 & 0x7f) != 0) {
        for (uVar3 = (param_3 & 0x7f) >> 4; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4[1] = uVar1;
          puVar4[2] = uVar1;
          puVar4[3] = uVar1;
          puVar4 = puVar4 + 4;
        }
        if ((param_3 & 0xf) != 0) {
          for (uVar3 = (param_3 & 0xf) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
          }
          for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
            *(byte *)puVar4 = param_2;
            puVar4 = (uint *)((int)puVar4 + 1);
          }
        }
      }
      return param_1;
    }
    puVar4 = param_1;
    if (3 < param_3) {
      uVar2 = -(int)param_1 & 3;
      uVar3 = param_3;
      if (uVar2 != 0) {
        uVar3 = param_3 - uVar2;
        do {
          *(byte *)puVar4 = param_2;
          puVar4 = (uint *)((int)puVar4 + 1);
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      uVar1 = uVar1 * 0x1010101;
      param_3 = uVar3 & 3;
      uVar3 = uVar3 >> 2;
      if (uVar3 != 0) {
        for (; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        }
        if (param_3 == 0) {
          return param_1;
        }
      }
    }
    do {
      *(char *)puVar4 = (char)uVar1;
      puVar4 = (uint *)((int)puVar4 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  else {
    puVar4 = param_1;
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(byte *)puVar4 = param_2;
      puVar4 = (uint *)((int)puVar4 + 1);
    }
  }
  return param_1;
}


// ----- callee: WS2_32.DLL::inet_ntoa @ EXTERNAL:00000010
// decompile failed: Exception while decompiling EXTERNAL:00000010: Cannot marshal address space: EXTERNAL

