// full decompile of vpnd.exe

// ===== FUN_00401100 @ 00401100 =====

void FUN_00401100(void)

{
  return;
}



// ===== FUN_00401110 @ 00401110 =====

void * __fastcall FUN_00401110(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  if (param_3 == 0) {
    return param_1;
  }
  pvVar1 = memcpy(param_1,param_2,param_3);
  return pvVar1;
}



// ===== FUN_00401130 @ 00401130 =====

void * __fastcall FUN_00401130(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  if (param_3 == 0) {
    return param_1;
  }
  pvVar1 = memmove(param_1,param_2,param_3);
  return pvVar1;
}



// ===== FUN_00401150 @ 00401150 =====

undefined4 * __thiscall FUN_00401150(void *this,byte param_1)

{
  *(undefined ***)this = std::error_category::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===== FUN_00401180 @ 00401180 =====

void __thiscall FUN_00401180(void *this,undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = this;
  return;
}



// ===== FUN_004011a0 @ 004011a0 =====

uint __thiscall FUN_004011a0(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  undefined1 local_c [8];
  
  piVar1 = (int *)(**(code **)(*(int *)this + 0xc))(local_c,param_1);
  if ((piVar1[1] == param_2[1]) && (piVar1 = (int *)*piVar1, piVar1 == (int *)*param_2)) {
    return CONCAT31((int3)((uint)piVar1 >> 8),1);
  }
  return (uint)piVar1 & 0xffffff00;
}



// ===== FUN_004011e0 @ 004011e0 =====

uint __thiscall FUN_004011e0(void *this,int *param_1,int param_2)

{
  if ((this == (void *)param_1[1]) && (param_1 = (int *)*param_1, param_1 == (int *)param_2)) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  return (uint)param_1 & 0xffffff00;
}



// ===== FUN_00401200 @ 00401200 =====

char * FUN_00401200(void)

{
  return "generic";
}



// ===== FUN_00401210 @ 00401210 =====

undefined1 * FUN_00401210(undefined1 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)std::_Syserror_map(param_2);
  piVar3 = (int *)"unknown error";
  if (piVar2 != (int *)0x0) {
    piVar3 = piVar2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if ((char)*piVar3 == '\0') {
    FUN_00401f80(param_1,piVar3,0);
    return param_1;
  }
  piVar2 = piVar3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00401f80(param_1,piVar3,(int)piVar2 - ((int)piVar3 + 1));
  return param_1;
}



// ===== FUN_00401290 @ 00401290 =====

char * FUN_00401290(void)

{
  return "iostream";
}



// ===== FUN_004012a0 @ 004012a0 =====

undefined1 * FUN_004012a0(undefined1 *param_1,int param_2)

{
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_00401f80(param_1,(int *)"iostream stream error",0x15);
    return param_1;
  }
  FUN_00401210(param_1,param_2);
  return param_1;
}



// ===== FUN_004012f0 @ 004012f0 =====

char * FUN_004012f0(void)

{
  return "system";
}



// ===== FUN_00401300 @ 00401300 =====

undefined1 * FUN_00401300(undefined1 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)std::_Winerror_map(param_2);
  piVar3 = (int *)"unknown error";
  if (piVar2 != (int *)0x0) {
    piVar3 = piVar2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if ((char)*piVar3 == '\0') {
    FUN_00401f80(param_1,piVar3,0);
    return param_1;
  }
  piVar2 = piVar3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00401f80(param_1,piVar3,(int)piVar2 - ((int)piVar3 + 1));
  return param_1;
}



// ===== FUN_00401380 @ 00401380 =====

void FUN_00401380(int *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = std::_Syserror_map(param_2);
  *param_1 = param_2;
  if (pcVar1 == (char *)0x0) {
    param_1[1] = (int)&PTR_vftable_00428020;
    return;
  }
  param_1[1] = (int)&PTR_vftable_00428024;
  return;
}



// ===== FUN_004013c0 @ 004013c0 =====

void __fastcall FUN_004013c0(undefined4 *param_1)

{
  *param_1 = Json::StyledWriter::vftable;
  if (0xf < (uint)param_1[0xf]) {
    operator_delete((void *)param_1[10]);
  }
  param_1[0xf] = 0xf;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  if (0xf < (uint)param_1[9]) {
    operator_delete((void *)param_1[4]);
  }
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    FUN_00402250((undefined4 *)param_1[1],(undefined4 *)param_1[2]);
    operator_delete((void *)param_1[1]);
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  *param_1 = Json::Writer::vftable;
  return;
}



// ===== FUN_00401450 @ 00401450 =====

undefined4 * __thiscall FUN_00401450(void *this,byte param_1)

{
  FUN_004013c0(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===== FUN_00401480 @ 00401480 =====

void __fastcall FUN_00401480(int param_1)

{
  sockaddr *addr;
  u_short uVar1;
  SOCKET SVar2;
  u_long uVar3;
  int iVar4;
  LSTATUS LVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint local_10 [3];
  
  local_10[2] = DAT_00428000 ^ (uint)(local_10 + 3);
  SVar2 = socket(2,1,6);
  *(SOCKET *)(param_1 + 0x30) = SVar2;
  if (SVar2 == 0xffffffff) {
    FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
    return;
  }
  addr = (sockaddr *)(param_1 + 4);
  addr->sa_family = 0;
  addr->sa_data[0] = '\0';
  addr->sa_data[1] = '\0';
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  addr->sa_family = 2;
  uVar3 = htonl(0x7f000001);
  *(u_long *)(param_1 + 8) = uVar3;
  uVar1 = htons(0xff98);
  *(u_short *)(param_1 + 6) = uVar1;
  iVar4 = bind(*(SOCKET *)(param_1 + 0x30),addr,0x10);
  if (iVar4 == -1) {
    *(undefined2 *)(param_1 + 6) = 0;
    iVar4 = bind(*(SOCKET *)(param_1 + 0x30),addr,0x10);
    if (iVar4 == -1) {
      pcVar7 = "failed to bind port\n";
      uVar6 = 0xb4;
      goto LAB_00401543;
    }
  }
  local_10[1] = 0x10;
  iVar4 = getsockname(*(SOCKET *)(param_1 + 0x30),addr,(int *)(local_10 + 1));
  if (iVar4 != -1) {
    uVar1 = ntohs(*(u_short *)(param_1 + 6));
    local_10[0] = (uint)uVar1;
    LVar5 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","tcp_port",4,local_10,4);
    array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",1,LVar5
                      );
    FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
    return;
  }
  pcVar7 = "failed to get bind port\n";
  uVar6 = 0xbc;
LAB_00401543:
  array_vpn_logprint(3,"..\\common\\ipc.cpp",uVar6,pcVar7);
  closesocket(*(SOCKET *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
  return;
}



// ===== FUN_004015e0 @ 004015e0 =====

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_004015e0(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  SOCKET SVar5;
  uint uVar6;
  int iStack_1000c;
  char acStack_10008 [65540];
  
  uVar3 = DAT_00428000 ^ (uint)(acStack_10008 + 0x10004);
  iStack_1000c = 0x10;
  array_vpn_logprint(1,"..\\common\\ipc.cpp",0xe5,"ipc server thread begin to run\n");
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  iVar4 = listen(*(SOCKET *)(param_1 + 0x30),5);
  if (iVar4 == -1) {
    array_vpn_logprint(3,"..\\common\\ipc.cpp",0xe9,"ipc server thread listen failed\n");
    FUN_0041c21c(uVar3 ^ (uint)(acStack_10008 + 0x10004));
    return;
  }
  array_vpn_logprint(1,"..\\common\\ipc.cpp",0xee,"ipc server thread listen success\n");
  SVar5 = accept(*(SOCKET *)(param_1 + 0x30),(sockaddr *)(param_1 + 0x14),&iStack_1000c);
  *(SOCKET *)(param_1 + 0x34) = SVar5;
  do {
    if (SVar5 == 0xffffffff) {
      array_vpn_logprint(1,"..\\common\\ipc.cpp",0xf9,"ipc server thread accept failed\n");
LAB_00401718:
      array_vpn_logprint(1,"..\\common\\ipc.cpp",0x10a,"ipc server thread exit\n");
      FUN_0041c21c(uVar3 ^ (uint)(acStack_10008 + 0x10004));
      return;
    }
    uVar6 = recv(*(SOCKET *)(param_1 + 0x34),acStack_10008,0xffff,0);
    if ((int)uVar6 < 1) {
      array_vpn_logprint(3,"..\\common\\ipc.cpp",0xfe,"recvfrom return %d\n",uVar6);
      goto LAB_00401718;
    }
    if (0xffff < uVar6) {
      ___report_rangecheckfailure();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x2c);
    acStack_10008[uVar6] = '\0';
    if ((puVar1 != (undefined4 *)0x0) && (iVar4 = (**(code **)*puVar1)(acStack_10008), iVar4 == 2)) goto LAB_00401718;
    SVar5 = accept(*(SOCKET *)(param_1 + 0x30),(sockaddr *)(param_1 + 0x14),&iStack_1000c);
    *(SOCKET *)(param_1 + 0x34) = SVar5;
  } while( true );
}



// ===== FUN_00401760 @ 00401760 =====

void __fastcall FUN_00401760(SOCKET *param_1)

{
  LSTATUS LVar1;
  code *pcVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  FUN_004019b0(param_1);
  pcVar2 = closesocket_exref;
  if (param_1[0x1a] != 0xffffffff) {
    closesocket(param_1[0x1a]);
    param_1[0x1a] = 0xffffffff;
  }
  if ((char)param_1[0xd] == '\0') {
    local_c = 0;
    LVar1 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","tcp_port",4,&local_c,4);
    array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",1,LVar1
                      );
    local_c = 0;
    LVar1 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","port",4,&local_c,4);
    array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",0,LVar1
                      );
    pcVar2 = closesocket_exref;
  }
  if (param_1[0x1a] != 0xffffffff) {
    (*pcVar2)(param_1[0x1a]);
    param_1[0x1a] = 0xffffffff;
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00401840 @ 00401840 =====

void __fastcall FUN_00401840(SOCKET *param_1)

{
  sockaddr *addr;
  u_short uVar1;
  SOCKET SVar2;
  u_long uVar3;
  int iVar4;
  LSTATUS LVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint local_10 [3];
  
  local_10[2] = DAT_00428000 ^ (uint)(local_10 + 3);
  param_1[0x1c] = 1;
  FUN_00401480((int)(param_1 + 0xe));
  SVar2 = socket(2,2,0);
  *param_1 = SVar2;
  if (SVar2 == 0xffffffff) {
    FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
    return;
  }
  addr = (sockaddr *)(param_1 + 2);
  addr->sa_family = 0;
  addr->sa_data[0] = '\0';
  addr->sa_data[1] = '\0';
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  addr->sa_family = 2;
  uVar3 = htonl(0x7f000001);
  param_1[3] = uVar3;
  uVar1 = htons((u_short)param_1[1]);
  *(u_short *)((int)param_1 + 10) = uVar1;
  iVar4 = bind(*param_1,addr,0x10);
  if (iVar4 == -1) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    iVar4 = bind(*param_1,addr,0x10);
    if (iVar4 == -1) {
      pcVar7 = "failed to bind port\n";
      uVar6 = 0x154;
      goto LAB_00401910;
    }
  }
  local_10[1] = 0x10;
  iVar4 = getsockname(*param_1,addr,(int *)(local_10 + 1));
  if (iVar4 != -1) {
    uVar1 = ntohs(*(u_short *)((int)param_1 + 10));
    *(u_short *)(param_1 + 1) = uVar1;
    if ((char)param_1[0xd] == '\0') {
      local_10[0] = (uint)uVar1;
      LVar5 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","port",4,local_10,4);
      array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",0,
                         LVar5);
    }
    FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
    return;
  }
  pcVar7 = "failed to get bind port\n";
  uVar6 = 0x15c;
LAB_00401910:
  array_vpn_logprint(3,"..\\common\\ipc.cpp",uVar6,pcVar7);
  closesocket(*param_1);
  *param_1 = 0xffffffff;
  FUN_0041c21c(local_10[2] ^ (uint)(local_10 + 3));
  return;
}



// ===== FUN_004019b0 @ 004019b0 =====

void __fastcall FUN_004019b0(SOCKET *param_1)

{
  SOCKET *pSVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00428000 ^ (uint)&local_10;
  if ((param_1[0x1c] == 1) && (param_1[0x1a] != 0xffffffff)) {
    closesocket(param_1[0x1a]);
    param_1[0x1a] = 0xffffffff;
  }
  if (*param_1 != 0xffffffff) {
    closesocket(*param_1);
    *param_1 = 0xffffffff;
  }
  pSVar1 = param_1 + 10;
  iVar2 = thrd_is_null(*pSVar1,param_1[0xb]);
  if (iVar2 == 0) {
    _Thrd_detach(*pSVar1,param_1[0xb]);
    thrd_set_null(pSVar1);
  }
  if ((char)param_1[0xd] == '\0') {
    local_10 = 0;
    LVar3 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","tcp_port",4,&local_10,4);
    array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",1,LVar3
                      );
    local_10 = 0;
    LVar3 = SHSetValueA((HKEY)0x80000001,"Software\\MotionPro\\L3VPN","port",4,&local_10,4);
    array_vpn_logprint(1,"..\\common\\ipc.cpp",0x4d,"SaveBindPort, SHSetValueA finished for port: %d, ret: %d\n",0,LVar3
                      );
  }
  FUN_0041c21c(local_c ^ (uint)&local_10);
  return;
}



// ===== FUN_00401ac0 @ 00401ac0 =====

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_00401ac0(SOCKET *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  DWORD DVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  int iStack_1000c;
  char acStack_10008 [65540];
  
  uVar2 = DAT_00428000 ^ (uint)(acStack_10008 + 0x10004);
  iStack_1000c = 0x10;
  array_vpn_logprint(1,"..\\common\\ipc.cpp",0x1af,"ipc server thread begin to run\n");
  do {
    while (uVar3 = recvfrom(*param_1,acStack_10008,0xffff,0,(sockaddr *)(param_1 + 6),&iStack_1000c), (int)uVar3 < 1) {
      DVar4 = GetLastError();
      if (DVar4 != 0x2746) {
        uVar5 = win_errno();
        pcVar7 = array_vpn_logprint_exref;
        array_vpn_logprint(3,"..\\common\\ipc.cpp",0x1ba,"recvfrom return %d, error %u\n",uVar3,uVar5);
LAB_00401b97:
        (*pcVar7)(1,"..\\common\\ipc.cpp",0x1c6,"ipc server thread exit\n");
        FUN_0041c21c(uVar2 ^ (uint)(acStack_10008 + 0x10004));
        return;
      }
    }
    if (0xffff < uVar3) {
      ___report_rangecheckfailure();
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    puVar1 = (undefined4 *)param_1[0xc];
    acStack_10008[uVar3] = '\0';
  } while ((puVar1 == (undefined4 *)0x0) || (iVar6 = (**(code **)*puVar1)(acStack_10008), iVar6 != 2));
  pcVar7 = array_vpn_logprint_exref;
  goto LAB_00401b97;
}



// ===== FUN_00401bd0 @ 00401bd0 =====

void __thiscall FUN_00401bd0(void *this,char *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x10);
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  FUN_00401bf0(this,param_1,*piVar1);
  return;
}



// ===== FUN_00401bf0 @ 00401bf0 =====

undefined4 __thiscall FUN_00401bf0(void *this,char *param_1,int param_2)

{
  u_short uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(SOCKET *)this == 0xffffffff) {
    return 9;
  }
  iVar2 = sendto(*(SOCKET *)this,param_1,param_2,0,(sockaddr *)((int)this + 0x18),0x10);
  if (iVar2 == param_2) {
    return 0;
  }
  uVar3 = win_errno();
  uVar1 = ntohs(*(u_short *)((int)this + 0x1a));
  array_vpn_logprint(3,"..\\common\\ipc.cpp",0x1d9,"send data to %u failed, error %u\n",uVar1,uVar3);
  return 0xf;
}



// ===== FUN_00401c60 @ 00401c60 =====

void __thiscall FUN_00401c60(void *this,char *param_1,int param_2,u_short param_3)

{
  u_short uVar1;
  u_long uVar2;
  int iVar3;
  undefined4 uVar4;
  sockaddr local_1c;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  if (*(int *)this == -1) {
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  local_1c.sa_data[0] = '\0';
  local_1c.sa_data[1] = '\0';
  local_1c.sa_data[2] = '\0';
  local_1c.sa_data[3] = '\0';
  local_1c.sa_data[4] = '\0';
  local_1c.sa_data[5] = '\0';
  local_1c.sa_data[6] = '\0';
  local_1c.sa_data[7] = '\0';
  local_1c.sa_data[8] = '\0';
  local_1c.sa_data[9] = '\0';
  local_1c.sa_data[10] = '\0';
  local_1c.sa_data[0xb] = '\0';
  local_1c.sa_data[0xc] = '\0';
  local_1c.sa_data[0xd] = '\0';
  local_1c.sa_family = 2;
  uVar2 = htonl(0x7f000001);
  local_1c.sa_data._2_2_ = SUB42(uVar2,0);
  local_1c.sa_data._4_2_ = SUB42(uVar2 >> 0x10,0);
  local_1c.sa_data._0_2_ = htons(param_3);
  iVar3 = sendto(*(SOCKET *)this,param_1,param_2,0,&local_1c,0x10);
  if (iVar3 == param_2) {
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  uVar4 = win_errno();
  uVar1 = ntohs(local_1c.sa_data._0_2_);
  array_vpn_logprint(3,"..\\common\\ipc.cpp",0x1ef,"send data to %u failed, error %u\n",uVar1,uVar4);
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_00401d40 @ 00401d40 =====

undefined1 * __thiscall FUN_00401d40(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  if ((char)*param_1 == '\0') {
    FUN_00401f80(this,param_1,0);
    return this;
  }
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00401f80(this,param_1,(int)piVar2 - ((int)param_1 + 1));
  return this;
}



// ===== FUN_00401da0 @ 00401da0 =====

void __fastcall FUN_00401da0(undefined4 *param_1)

{
  if (0xf < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// ===== FUN_00401dd0 @ 00401dd0 =====

void __thiscall FUN_00401dd0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((char)*param_1 == '\0') {
    FUN_00401f80(this,param_1,0);
    return;
  }
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00401f80(this,param_1,(int)piVar2 - ((int)param_1 + 1));
  return;
}



// ===== FUN_00401e10 @ 00401e10 =====

void __fastcall FUN_00401e10(undefined4 *param_1)

{
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    FUN_00402250((undefined4 *)*param_1,(undefined4 *)param_1[1]);
    operator_delete((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}



// ===== FUN_00401e50 @ 00401e50 =====

int * __thiscall FUN_00401e50(void *this,int *param_1,uint param_2,uint param_3)

{
  void *_Dst;
  uint uVar1;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  uVar1 = param_1[4] - param_2;
  if (param_3 < uVar1) {
    uVar1 = param_3;
  }
  if (this == param_1) {
    uVar1 = uVar1 + param_2;
    if (*(uint *)((int)this + 0x10) < uVar1) {
                    /* WARNING: Subroutine does not return */
      std::_Xout_of_range("invalid string position");
    }
    *(uint *)((int)this + 0x10) = uVar1;
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)((int)this + uVar1) = 0;
      FUN_004020c0(this,0,param_2);
      return this;
    }
    *(undefined1 *)(*(int *)this + uVar1) = 0;
    FUN_004020c0(this,0,param_2);
    return this;
  }
  if (uVar1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < uVar1) {
    FUN_004022a0(this,uVar1,*(size_t *)((int)this + 0x10));
    if (uVar1 == 0) {
      return this;
    }
  }
  else if (uVar1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)this = 0;
      return this;
    }
    **(undefined1 **)this = 0;
    return this;
  }
  if (0xf < (uint)param_1[5]) {
    param_1 = (int *)*param_1;
  }
  if (*(uint *)((int)this + 0x14) < 0x10) {
    _Dst = this;
  }
  else {
    _Dst = *(void **)this;
  }
  if (uVar1 != 0) {
    memcpy(_Dst,(void *)((int)param_1 + param_2),uVar1);
  }
  *(uint *)((int)this + 0x10) = uVar1;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + uVar1) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + uVar1) = 0;
  return this;
}



// ===== FUN_00401f70 @ 00401f70 =====

undefined4 * __fastcall FUN_00401f70(undefined4 *param_1)

{
  if ((uint)param_1[5] < 0x10) {
    return param_1;
  }
  return (undefined4 *)*param_1;
}



// ===== FUN_00401f80 @ 00401f80 =====

int * __thiscall FUN_00401f80(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  void *pvVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    if (uVar1 < 0x10) {
      piVar2 = this;
    }
    else {
      piVar2 = *(int **)this;
    }
    if (piVar2 <= param_1) {
      if (uVar1 < 0x10) {
        pvVar3 = this;
      }
      else {
        pvVar3 = *(void **)this;
      }
      if (param_1 < (int *)(*(int *)((int)this + 0x10) + (int)pvVar3)) {
        if (uVar1 < 0x10) {
          piVar2 = FUN_00401e50(this,this,(int)param_1 - (int)this,param_2);
          return piVar2;
        }
        piVar2 = FUN_00401e50(this,this,(int)param_1 - *(int *)this,param_2);
        return piVar2;
      }
    }
  }
  if (param_2 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_2) {
    FUN_004022a0(this,param_2,*(size_t *)((int)this + 0x10));
    if (param_2 == 0) {
      return this;
    }
  }
  else if (param_2 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)this = 0;
      return this;
    }
    **(undefined1 **)this = 0;
    return this;
  }
  if (*(uint *)((int)this + 0x14) < 0x10) {
    pvVar3 = this;
  }
  else {
    pvVar3 = *(void **)this;
  }
  if (param_2 != 0) {
    memcpy(pvVar3,param_1,param_2);
  }
  *(uint *)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + param_2) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + param_2) = 0;
  return this;
}



// ===== FUN_00402080 @ 00402080 =====

int * __thiscall FUN_00402080(void *this,uint param_1)

{
  if (*(uint *)((int)this + 0x10) < param_1) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  *(uint *)((int)this + 0x10) = param_1;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + param_1) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return this;
}



// ===== FUN_004020c0 @ 004020c0 =====

int * __thiscall FUN_004020c0(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  if (uVar1 - param_1 <= param_2) {
    *(uint *)((int)this + 0x10) = param_1;
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)((int)this + param_1) = 0;
      return this;
    }
    *(undefined1 *)(*(int *)this + param_1) = 0;
    return this;
  }
  if (param_2 != 0) {
    if (*(uint *)((int)this + 0x14) < 0x10) {
      pvVar2 = this;
    }
    else {
      pvVar2 = *(void **)this;
    }
    iVar3 = uVar1 - param_2;
    if (iVar3 - param_1 != 0) {
      memmove((void *)((int)pvVar2 + param_1),(void *)((int)((int)pvVar2 + param_1) + param_2),iVar3 - param_1);
    }
    *(int *)((int)this + 0x10) = iVar3;
    if (0xf < *(uint *)((int)this + 0x14)) {
      *(undefined1 *)(*(int *)this + iVar3) = 0;
      return this;
    }
    *(undefined1 *)((int)this + iVar3) = 0;
  }
  return this;
}



// ===== FUN_00402160 @ 00402160 =====

void __thiscall FUN_00402160(void *this,int param_1)

{
  *(int *)((int)this + 0x10) = param_1;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + param_1) = 0;
    return;
  }
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}



// ===== FUN_00402190 @ 00402190 =====

bool __thiscall FUN_00402190(void *this,uint param_1,char param_2)

{
  uint uVar1;
  void *_Src;
  uint _Size;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  uVar1 = *(uint *)((int)this + 0x14);
  if (uVar1 < param_1) {
    FUN_004022a0(this,param_1,*(size_t *)((int)this + 0x10));
    return param_1 != 0;
  }
  if ((param_2 == '\0') || (0xf < param_1)) {
    if (param_1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (0xf < uVar1) {
        this = *(void **)this;
      }
      *(undefined1 *)this = 0;
    }
    return param_1 != 0;
  }
  _Size = *(uint *)((int)this + 0x10);
  if (param_1 < *(uint *)((int)this + 0x10)) {
    _Size = param_1;
  }
  if (0xf < uVar1) {
    _Src = *(void **)this;
    if (_Size != 0) {
      memcpy(this,_Src,_Size);
    }
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x10) = _Size;
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined1 *)(_Size + (int)this) = 0;
  return param_1 != 0;
}



// ===== FUN_00402240 @ 00402240 =====

undefined4 __fastcall FUN_00402240(undefined4 param_1)

{
  return param_1;
}



// ===== FUN_00402250 @ 00402250 =====

void FUN_00402250(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    if (0xf < (uint)param_1[5]) {
      operator_delete((void *)*param_1);
    }
    param_1[5] = 0xf;
    param_1[4] = 0;
    *(undefined1 *)param_1 = 0;
  }
  return;
}



// ===== FUN_004022a0 @ 004022a0 =====

void __thiscall FUN_004022a0(void *this,uint param_1,size_t param_2)

{
  uint uVar1;
  uint uVar2;
  void *_Src;
  uint uVar3;
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041d250;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 0xf;
  if (uVar3 == 0xffffffff) {
    uVar3 = param_1;
  }
  else {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    if ((uVar3 / 3 < uVar2) && (uVar3 = uVar2 + uVar1, -uVar2 - 2 < uVar1)) {
      uVar3 = 0xfffffffe;
    }
  }
  local_8 = 0;
  local_18 = (void *)0x0;
  if ((uVar3 + 1 != 0) && (local_18 = operator_new(uVar3 + 1), local_18 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  if (param_2 != 0) {
    if (*(uint *)((int)this + 0x14) < 0x10) {
      _Src = this;
    }
    else {
      _Src = *(void **)this;
    }
    if (param_2 != 0) {
      memcpy(local_18,_Src,param_2);
    }
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
    operator_delete(*(void **)this);
  }
  *(undefined1 *)this = 0;
  *(void **)this = local_18;
  *(uint *)((int)this + 0x14) = uVar3;
  *(size_t *)((int)this + 0x10) = param_2;
  if (0xf < uVar3) {
    this = local_18;
  }
  *(undefined1 *)((int)this + param_2) = 0;
  ExceptionList = local_10;
  return;
}



// ===== Catch_All@00402337 @ 00402337 =====

undefined * Catch_All_00402337(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_004023f0(iVar1 + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  return &DAT_00402354;
}



// ===== Catch_All@00402371 @ 00402371 =====

void Catch_All_00402371(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (0xf < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 0xf;
  puVar1[4] = 0;
  *(undefined1 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_004023f0 @ 004023f0 =====

void * FUN_004023f0(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if ((param_1 != 0) && (pvVar1 = operator_new(param_1), pvVar1 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  return pvVar1;
}



// ===== FUN_00402420 @ 00402420 =====

void FUN_00402420(void)

{
  return;
}



// ===== FUN_00402430 @ 00402430 =====

uint __fastcall FUN_00402430(byte *param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  if (param_3 != 0) {
    while (uVar1 = param_3 - 4, 3 < param_3) {
      if (*(int *)param_1 != *(int *)param_2) goto LAB_00402456;
      param_1 = param_1 + 4;
      param_2 = param_2 + 4;
      param_3 = uVar1;
    }
    if (uVar1 != 0xfffffffc) {
LAB_00402456:
      bVar2 = *param_1 < *param_2;
      if ((*param_1 != *param_2) ||
         ((uVar1 != 0xfffffffd &&
          ((bVar2 = param_1[1] < param_2[1], param_1[1] != param_2[1] ||
           ((uVar1 != 0xfffffffe &&
            ((bVar2 = param_1[2] < param_2[2], param_1[2] != param_2[2] ||
             ((uVar1 != 0xffffffff && (bVar2 = param_1[3] < param_2[3], param_1[3] != param_2[3])))))))))))) {
        return -(uint)bVar2 | 1;
      }
    }
  }
  return 0;
}



// ===== FUN_00402490 @ 00402490 =====

exception * __thiscall FUN_00402490(void *this,byte param_1)

{
  std::exception::~exception(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===== FUN_004024d0 @ 004024d0 =====

exception * __thiscall FUN_004024d0(void *this,exception *param_1)

{
  std::exception::exception(this,param_1);
  *(undefined ***)this = std::runtime_error::vftable;
  return this;
}



// ===== FUN_004024f0 @ 004024f0 =====

void __cdecl FUN_004024f0(int param_1)

{
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffff9ff | 0x800;
  return;
}



// ===== FUN_00402510 @ 00402510 =====

void __cdecl FUN_00402510(int param_1)

{
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 4;
  return;
}



// ===== FUN_00402520 @ 00402520 =====

int * __fastcall FUN_00402520(int *param_1,uint param_2)

{
  byte bVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar2 = ExceptionList;
  puStack_c = &LAB_0041d289;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  local_8 = 0;
  piVar3 = param_1;
  if (param_2 < 0x80) {
    if (param_1[4] == 0) {
      FUN_00409420(param_1,1,'\0');
    }
    else {
      param_1[4] = 1;
      if ((uint)param_1[5] < 0x10) {
        *(undefined1 *)((int)param_1 + 1) = 0;
      }
      else {
        *(undefined1 *)(*param_1 + 1) = 0;
      }
    }
    if (0xf < (uint)param_1[5]) {
      piVar3 = (int *)*param_1;
    }
  }
  else {
    bVar1 = (byte)param_2;
    if (param_2 < 0x800) {
      if ((uint)param_1[4] < 2) {
        FUN_00409420(param_1,2 - param_1[4],'\0');
      }
      else {
        param_1[4] = 2;
        if ((uint)param_1[5] < 0x10) {
          *(undefined1 *)((int)param_1 + 2) = 0;
        }
        else {
          *(undefined1 *)(*param_1 + 2) = 0;
        }
      }
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 1) = bVar1 & 0x3f | 0x80;
      if ((uint)param_1[5] < 0x10) {
        param_2 = (uint)((byte)(param_2 >> 6) & 0x1f | 0xc0);
      }
      else {
        param_2 = (uint)((byte)(param_2 >> 6) & 0x1f | 0xc0);
        piVar3 = (int *)*param_1;
      }
    }
    else if (param_2 < 0x10000) {
      if ((uint)param_1[4] < 3) {
        FUN_00409420(param_1,3 - param_1[4],'\0');
      }
      else {
        param_1[4] = 3;
        if ((uint)param_1[5] < 0x10) {
          *(undefined1 *)((int)param_1 + 3) = 0;
        }
        else {
          *(undefined1 *)(*param_1 + 3) = 0;
        }
      }
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 2) = bVar1 & 0x3f | 0x80;
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 1) = (byte)(param_2 >> 6) & 0x3f | 0x80;
      if ((uint)param_1[5] < 0x10) {
        param_2 = (uint)((byte)(param_2 >> 0xc) & 0xf | 0xe0);
      }
      else {
        param_2 = (uint)((byte)(param_2 >> 0xc) & 0xf | 0xe0);
        piVar3 = (int *)*param_1;
      }
    }
    else {
      if (0x10ffff < param_2) {
        ExceptionList = pvVar2;
        return param_1;
      }
      FUN_00408410(param_1,4);
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 3) = bVar1 & 0x3f | 0x80;
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 2) = (byte)(param_2 >> 6) & 0x3f | 0x80;
      if ((uint)param_1[5] < 0x10) {
        piVar4 = param_1;
      }
      else {
        piVar4 = (int *)*param_1;
      }
      *(byte *)((int)piVar4 + 1) = (byte)(param_2 >> 0xc) & 0x3f | 0x80;
      if (0xf < (uint)param_1[5]) {
        piVar3 = (int *)*param_1;
      }
      param_2 = (uint)((byte)(param_2 >> 0x12) & 7 | 0xf0);
    }
  }
  *(char *)piVar3 = (char)param_2;
  ExceptionList = local_10;
  return param_1;
}



// ===== FUN_00402750 @ 00402750 =====

undefined1 __fastcall FUN_00402750(char *param_1,char *param_2)

{
  while( true ) {
    if (param_2 <= param_1) {
      return 0;
    }
    if ((*param_1 == '\n') || (*param_1 == '\r')) break;
    param_1 = param_1 + 1;
  }
  return 1;
}



// ===== FUN_00402770 @ 00402770 =====

undefined4 * __fastcall FUN_00402770(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d2b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  *param_1 = puVar1;
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined4 **)*param_1 = param_1;
  local_8 = 0;
  puVar1 = param_1 + 5;
  *puVar1 = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  *puVar1 = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  *(undefined4 **)*puVar1 = puVar1;
  param_1[0xf] = 0xf;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x1a] = 0xf;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  param_1[0x1b] = 1;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  ExceptionList = local_10;
  return param_1;
}



// ===== FUN_004028a0 @ 004028a0 =====

void __fastcall FUN_004028a0(undefined4 *param_1)

{
  FUN_00409ae0((int)param_1);
  operator_delete((void *)*param_1);
  *param_1 = 0;
  return;
}



// ===== FUN_004028c0 @ 004028c0 =====

void __thiscall FUN_004028c0(void *this,undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  void *local_44 [5];
  uint local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  void *local_8;
  
  local_8 = (void *)0xffffffff;
  puStack_c = &LAB_0041d2e8;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_44 + 0x10);
  ExceptionList = &local_10;
  local_20 = param_1;
  *(undefined4 *)((int)this + 0x40) = param_1;
  *(undefined4 *)((int)this + 0x48) = param_1;
  local_1c = param_2;
  local_18 = param_3;
  *(undefined4 *)((int)this + 0x44) = param_2;
  *(bool *)((int)this + 0x70) = *(char *)((int)this + 0x6c) != '\0';
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  FUN_00401f80((void *)((int)this + 0x54),(int *)&DAT_0041f7b1,0);
  FUN_00409cd0((int)this + 0x14);
  if (*(int *)((int)this + 0x10) != 0) {
    iVar1 = *(int *)((int)this + 0x10);
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  FUN_00409a50(this,&local_18);
  FUN_00402a10(this);
  FUN_00402e40(this,&local_2c);
  if ((*(char *)((int)this + 0x70) != '\0') && (*(int *)((int)this + 100) != 0)) {
    FUN_00406990(param_3,(char *)((int)this + 0x54),2);
  }
  if (((*(char *)((int)this + 0x6d) != '\0') && (*(char *)((int)param_3 + 8) != '\x06')) &&
     (*(char *)((int)param_3 + 8) != '\a')) {
    local_28 = local_20;
    local_2c = 0xd;
    local_24 = local_1c;
    FUN_00401d40(local_44,(int *)"A valid JSON document must be either an array or an object value.");
    local_8 = (void *)0x0;
    FUN_00404d50(this,local_44,(undefined8 *)&local_2c,0);
    if (0xf < local_30) {
      operator_delete(local_44[0]);
    }
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_44 + 0x10));
  return;
}



// ===== FUN_00402a10 @ 00402a10 =====

undefined1 __fastcall FUN_00402a10(void *param_1)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 in_stack_ffffff68;
  undefined4 uVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_6c [3];
  char local_60 [8];
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [3];
  undefined4 local_3c [3];
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0041d338;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar8 = 0x402a48;
  FUN_00402e40(param_1,&local_78);
  uVar1 = 1;
  if ((*(char *)((int)param_1 + 0x70) != '\0') && (*(int *)((int)param_1 + 100) != 0)) {
    pcVar10 = (char *)((int)param_1 + 0x54);
    iVar2 = FUN_00409590(pcVar10,in_stack_ffffff68,uVar8,2);
    if (iVar2 == -1) {
      *(undefined4 *)((int)param_1 + 100) = 0;
      if (*(uint *)((int)param_1 + 0x68) < 0x10) {
        pcVar3 = pcVar10;
      }
      else {
        pcVar3 = *(char **)pcVar10;
      }
      *pcVar3 = '\0';
    }
    else {
      FUN_00402080(pcVar10,iVar2 + 1);
    }
    puVar9 = local_6c;
    pvVar4 = (void *)FUN_0040a080(param_1,(undefined4 *)local_60);
    piVar5 = (int *)FUN_0040a250(pvVar4,puVar9);
    iVar2 = 0;
    if ((int *)*piVar5 != (int *)0x0) {
      iVar2 = *(int *)*piVar5;
    }
    FUN_00406990(*(void **)(*(int *)(*(int *)(iVar2 + 4) + (*(int *)(iVar2 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                           (piVar5[2] & 3U) * 4),pcVar10,0);
    FUN_00401f80(pcVar10,(int *)&DAT_0041f7b1,0);
  }
  switch(local_78) {
  case 1:
    uVar1 = FUN_004035c0(param_1,(int)&local_78);
    break;
  default:
switchD_00402afc_caseD_2:
    puVar9 = local_3c;
    pvVar4 = (void *)FUN_0040a080(param_1,local_48);
    piVar5 = (int *)FUN_0040a250(pvVar4,puVar9);
    if ((int *)*piVar5 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)*piVar5;
    }
    *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + (*(int *)(iVar2 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                     (piVar5[2] & 3U) * 4) + 0x10) = local_74 - *(int *)((int)param_1 + 0x40);
    pcVar10 = local_60;
    pvVar4 = (void *)FUN_0040a080(param_1,local_6c);
    piVar5 = (int *)FUN_0040a250(pvVar4,(undefined4 *)pcVar10);
    iVar2 = 0;
    if ((int *)*piVar5 != (int *)0x0) {
      iVar2 = *(int *)*piVar5;
    }
    *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + (*(int *)(iVar2 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                     (piVar5[2] & 3U) * 4) + 0x14) = local_70 - *(int *)((int)param_1 + 0x40);
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    FUN_00401f80(local_30,(int *)"Syntax error: value, object or array expected.",0x2e);
    local_c = 6;
    uVar1 = FUN_00404d50(param_1,local_30,(undefined8 *)&local_78,0);
    if (local_1c < 0x10) {
      ExceptionList = local_14;
      return uVar1;
    }
    operator_delete(local_30[0]);
    ExceptionList = local_14;
    return uVar1;
  case 3:
    uVar1 = FUN_00403b20(param_1,(int)&local_78);
    break;
  case 5:
    uVar1 = FUN_00404560(param_1,(undefined8 *)&local_78);
    goto LAB_00402cb2;
  case 6:
    uVar1 = FUN_00403e00(param_1,(undefined8 *)&local_78);
    goto LAB_00402cb2;
  case 7:
    local_58 = local_58 & 0xfffffe05 | 5;
    local_60[0] = '\x01';
    local_c = 0;
    goto LAB_00402b87;
  case 8:
    local_58 = local_58 & 0xfffffe05 | 5;
    local_60[0] = '\0';
    local_c = 1;
    goto LAB_00402b87;
  case 9:
    local_58 = local_58 & 0xfffffe00;
    local_c = 3;
LAB_00402b87:
    local_4c = 0;
    local_50 = 0;
    local_54 = 0;
    pcVar10 = local_60;
    pvVar4 = (void *)FUN_00404f00(param_1);
    FUN_00405560(pvVar4,pcVar10);
    local_c = 0xffffffff;
    FUN_004054d0((undefined4 *)local_60);
    iVar2 = *(int *)((int)param_1 + 0x40);
    iVar7 = FUN_00404f00(param_1);
    *(int *)(iVar7 + 0x10) = local_74 - iVar2;
    goto LAB_00402ca5;
  case 10:
    if (*(char *)((int)param_1 + 0x6e) == '\0') goto switchD_00402afc_caseD_2;
    *(int *)((int)param_1 + 0x48) = *(int *)((int)param_1 + 0x48) + -1;
    local_58 = local_58 & 0xfffffe00;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    pcVar10 = local_60;
    local_c = 5;
    pvVar4 = (void *)FUN_00404f00(param_1);
    FUN_00405560(pvVar4,pcVar10);
    local_c = 0xffffffff;
    FUN_004054d0((undefined4 *)local_60);
    iVar2 = *(int *)((int)param_1 + 0x48);
    iVar7 = *(int *)((int)param_1 + 0x40);
    iVar6 = FUN_00404f00(param_1);
    *(int *)(iVar6 + 0x10) = (iVar2 - iVar7) + -1;
    uVar1 = 1;
  }
  local_70 = *(int *)((int)param_1 + 0x48);
LAB_00402ca5:
  iVar2 = *(int *)((int)param_1 + 0x40);
  iVar7 = FUN_00404f00(param_1);
  *(int *)(iVar7 + 0x14) = local_70 - iVar2;
LAB_00402cb2:
  if (*(char *)((int)param_1 + 0x70) == '\0') {
    ExceptionList = local_14;
    return uVar1;
  }
  *(undefined4 *)((int)param_1 + 0x4c) = *(undefined4 *)((int)param_1 + 0x48);
  puVar9 = local_48;
  pvVar4 = (void *)FUN_0040a080(param_1,local_3c);
  piVar5 = (int *)FUN_0040a250(pvVar4,puVar9);
  iVar2 = 0;
  if ((int *)*piVar5 != (int *)0x0) {
    iVar2 = *(int *)*piVar5;
  }
  *(undefined4 *)((int)param_1 + 0x50) =
       *(undefined4 *)
        (*(int *)(*(int *)(iVar2 + 4) + (*(int *)(iVar2 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) + (piVar5[2] & 3U) * 4);
  ExceptionList = local_14;
  return uVar1;
}



// ===== FUN_00402e40 @ 00402e40 =====

void __thiscall FUN_00402e40(void *this,int *param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  
  if (*(char *)((int)this + 0x6c) == '\0') {
    FUN_004030b0(this,param_1);
    return;
  }
  do {
    pcVar1 = *(char **)((int)this + 0x48);
    while (pcVar1 != *(char **)((int)this + 0x44)) {
      cVar4 = **(char **)((int)this + 0x48);
      if ((((cVar4 != ' ') && (cVar4 != '\t')) && (cVar4 != '\r')) && (cVar4 != '\n')) break;
      pcVar1 = *(char **)((int)this + 0x48) + 1;
      *(char **)((int)this + 0x48) = pcVar1;
    }
    param_1[1] = *(int *)((int)this + 0x48);
    puVar2 = *(undefined1 **)((int)this + 0x48);
    if (puVar2 == *(undefined1 **)((int)this + 0x44)) {
      uVar6 = 0;
    }
    else {
      uVar6 = *puVar2;
      *(undefined1 **)((int)this + 0x48) = puVar2 + 1;
    }
    switch(uVar6) {
    case 0:
      *param_1 = 0;
      break;
    default:
      goto switchD_00402ea6_caseD_1;
    case 0x22:
      *param_1 = 5;
      cVar4 = FUN_00403580((int)this);
      goto LAB_00402ee9;
    case 0x2c:
      *param_1 = 10;
      break;
    case 0x2d:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      *param_1 = 6;
      FUN_00403540((int)this);
      break;
    case 0x2f:
      *param_1 = 0xc;
      uVar5 = FUN_00403350(this);
      cVar4 = (char)uVar5;
LAB_00402ee9:
      if (cVar4 == '\0') {
switchD_00402ea6_caseD_1:
        *param_1 = 0xd;
      }
      break;
    case 0x3a:
      *param_1 = 0xb;
      break;
    case 0x5b:
      *param_1 = 3;
      break;
    case 0x5d:
      *param_1 = 4;
      break;
    case 0x66:
      *param_1 = 8;
      iVar3 = *(int *)((int)this + 0x48);
      if (*(int *)((int)this + 0x44) - iVar3 < 4) goto switchD_00402ea6_caseD_1;
      iVar8 = 4;
      do {
        iVar7 = iVar8 + -1;
        if (*(char *)(iVar3 + -1 + iVar8) != (&UNK_0041f833)[iVar8]) goto switchD_00402ea6_caseD_1;
        iVar8 = iVar7;
      } while (iVar7 != 0);
      *(int *)((int)this + 0x48) = iVar3 + 4;
      break;
    case 0x6e:
      *param_1 = 9;
      iVar3 = *(int *)((int)this + 0x48);
      if (*(int *)((int)this + 0x44) - iVar3 < 3) goto switchD_00402ea6_caseD_1;
      iVar8 = 3;
      do {
        iVar7 = iVar8 + -1;
        if (*(char *)(iVar3 + -1 + iVar8) != (&UNK_0041f83b)[iVar8]) goto switchD_00402ea6_caseD_1;
        iVar8 = iVar7;
      } while (iVar7 != 0);
      *(int *)((int)this + 0x48) = iVar3 + 3;
      break;
    case 0x74:
      *param_1 = 7;
      iVar3 = *(int *)((int)this + 0x48);
      if (*(int *)((int)this + 0x44) - iVar3 < 3) goto switchD_00402ea6_caseD_1;
      iVar8 = 3;
      do {
        iVar7 = iVar8 + -1;
        if (*(char *)(iVar3 + -1 + iVar8) != (&UNK_0041f82f)[iVar8]) goto switchD_00402ea6_caseD_1;
        iVar8 = iVar7;
      } while (iVar7 != 0);
      *(int *)((int)this + 0x48) = iVar3 + 3;
      break;
    case 0x7b:
      *param_1 = 1;
      break;
    case 0x7d:
      *param_1 = 2;
    }
    param_1[2] = *(int *)((int)this + 0x48);
    if (*param_1 != 0xc) {
      return;
    }
  } while( true );
}



// ===== FUN_004030b0 @ 004030b0 =====

undefined4 __thiscall FUN_004030b0(void *this,undefined4 *param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined *puVar7;
  int iVar8;
  
  pcVar1 = *(char **)((int)this + 0x48);
  while (pcVar1 != *(char **)((int)this + 0x44)) {
    cVar3 = **(char **)((int)this + 0x48);
    if ((((cVar3 != ' ') && (cVar3 != '\t')) && (cVar3 != '\r')) && (cVar3 != '\n')) break;
    pcVar1 = *(char **)((int)this + 0x48) + 1;
    *(char **)((int)this + 0x48) = pcVar1;
  }
  param_1[1] = *(undefined4 *)((int)this + 0x48);
  puVar2 = *(undefined1 **)((int)this + 0x48);
  if (puVar2 == *(undefined1 **)((int)this + 0x44)) {
    uVar6 = 0;
  }
  else {
    uVar6 = *puVar2;
    *(undefined1 **)((int)this + 0x48) = puVar2 + 1;
  }
  switch(uVar6) {
  case 0:
    *param_1 = 0;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  default:
    goto switchD_0040310d_caseD_1;
  case 0x22:
    *param_1 = 5;
    cVar3 = FUN_00403580((int)this);
    goto LAB_004031d4;
  case 0x2c:
    *param_1 = 10;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x2d:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    *param_1 = 6;
    FUN_00403540((int)this);
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x2f:
    *param_1 = 0xc;
    uVar4 = FUN_00403350(this);
    cVar3 = (char)uVar4;
    goto LAB_004031d4;
  case 0x3a:
    *param_1 = 0xb;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x5b:
    *param_1 = 3;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x5d:
    *param_1 = 4;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x66:
    iVar8 = 4;
    *param_1 = 8;
    puVar7 = &DAT_0041f834;
    break;
  case 0x6e:
    iVar8 = 3;
    *param_1 = 9;
    puVar7 = &DAT_0041f83c;
    break;
  case 0x74:
    iVar8 = 3;
    *param_1 = 7;
    puVar7 = &DAT_0041f830;
    break;
  case 0x7b:
    *param_1 = 1;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  case 0x7d:
    *param_1 = 2;
    uVar4 = *(undefined4 *)((int)this + 0x48);
    param_1[2] = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  }
  uVar5 = FUN_004032f0(this,(uint)puVar7,iVar8);
  cVar3 = (char)uVar5;
LAB_004031d4:
  if (cVar3 == '\0') {
switchD_0040310d_caseD_1:
    *param_1 = 0xd;
  }
  uVar4 = *(undefined4 *)((int)this + 0x48);
  param_1[2] = uVar4;
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}



// ===== FUN_004032f0 @ 004032f0 =====

uint __thiscall FUN_004032f0(void *this,uint param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)((int)this + 0x48);
  uVar2 = *(int *)((int)this + 0x44) - iVar5;
  if ((int)uVar2 < param_2) {
LAB_00403307:
    return uVar2 & 0xffffff00;
  }
  if (param_2 != 0) {
    pcVar3 = (char *)(param_1 + param_2);
    uVar2 = param_1;
    iVar4 = param_2;
    do {
      pcVar1 = pcVar3 + (iVar5 - param_1) + -1;
      uVar2 = CONCAT31((int3)(uVar2 >> 8),*pcVar1);
      pcVar3 = pcVar3 + -1;
      iVar4 = iVar4 + -1;
      if (*pcVar1 != *pcVar3) goto LAB_00403307;
    } while (iVar4 != 0);
    iVar5 = *(int *)((int)this + 0x48);
  }
  *(int *)((int)this + 0x48) = iVar5 + param_2;
  return CONCAT31((int3)((uint)(iVar5 + param_2) >> 8),1);
}



// ===== FUN_00403350 @ 00403350 =====

uint __fastcall FUN_00403350(void *param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  char cVar4;
  char *pcVar5;
  undefined3 extraout_var;
  int *piVar6;
  int iVar7;
  
  pcVar5 = *(char **)((int)param_1 + 0x48);
  piVar1 = (int *)(pcVar5 + -1);
  if (pcVar5 != *(char **)((int)param_1 + 0x44)) {
    cVar4 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    *(char **)((int)param_1 + 0x48) = pcVar5;
    if (cVar4 == '*') {
      bVar3 = FUN_004034f0((int)param_1);
      pcVar5 = (char *)CONCAT31(extraout_var,bVar3);
      if (bVar3) {
LAB_004033aa:
        if (*(char *)((int)param_1 + 0x70) != '\0') {
          piVar6 = *(int **)((int)param_1 + 0x4c);
          iVar7 = 0;
          if (piVar6 != (int *)0x0) {
            for (; piVar6 < piVar1; piVar6 = (int *)((int)piVar6 + 1)) {
              if (((char)*piVar6 == '\n') || ((char)*piVar6 == '\r')) goto LAB_004033e9;
            }
            if ((cVar4 != '*') || (cVar4 = FUN_00402750((char *)piVar1,*(char **)((int)param_1 + 0x48)), cVar4 == '\0'))
            {
              iVar7 = 1;
            }
          }
LAB_004033e9:
          pcVar5 = (char *)FUN_00403400(param_1,piVar1,*(int **)((int)param_1 + 0x48),iVar7);
        }
        return CONCAT31((int3)((uint)pcVar5 >> 8),1);
      }
    }
    else if (cVar4 == '/') {
      while (pcVar5 != *(char **)((int)param_1 + 0x44)) {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *(char **)((int)param_1 + 0x48) = pcVar5;
        if ((cVar2 == '\r') || (cVar2 == '\n')) break;
      }
      goto LAB_004033aa;
    }
  }
  return (uint)pcVar5 & 0xffffff00;
}



// ===== FUN_00403400 @ 00403400 =====

void __thiscall FUN_00403400(void *this,int *param_1,int *param_2,int param_3)

{
  void *pvVar1;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d370;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_3 == 1) {
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    if (param_1 != param_2) {
      FUN_00401f80(local_2c,param_1,(int)param_2 - (int)param_1);
    }
    local_8 = 0;
    FUN_00406990(*(void **)((int)this + 0x50),(char *)local_2c,1);
    if (local_18 < 0x10) {
      ExceptionList = local_10;
      return;
    }
    pvVar1 = local_2c[0];
  }
  else {
    if (*(int *)((int)this + 100) != 0) {
      FUN_00409330((void *)((int)this + 0x54),(int *)&DAT_0041f840,1);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44[0] = (void *)((uint)local_44[0] & 0xffffff00);
    if (param_1 != param_2) {
      FUN_00401f80(local_44,param_1,(int)param_2 - (int)param_1);
    }
    local_8 = 1;
    FUN_00409270((void *)((int)this + 0x54),local_44,0,0xffffffff);
    if (local_30 < 0x10) {
      ExceptionList = local_10;
      return;
    }
    pvVar1 = local_44[0];
  }
  operator_delete(pvVar1);
  ExceptionList = local_10;
  return;
}



// ===== FUN_004034f0 @ 004034f0 =====

bool __fastcall FUN_004034f0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x48);
  do {
    if (pcVar2 == *(char **)(param_1 + 0x44)) break;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *(char **)(param_1 + 0x48) = pcVar2;
  } while ((cVar1 != '*') || (*pcVar2 != '/'));
  pcVar2 = *(char **)(param_1 + 0x48);
  if (pcVar2 == *(char **)(param_1 + 0x44)) {
    return false;
  }
  cVar1 = *pcVar2;
  *(char **)(param_1 + 0x48) = pcVar2 + 1;
  return cVar1 == '/';
}



// ===== FUN_00403540 @ 00403540 =====

void __fastcall FUN_00403540(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x48);
  while( true ) {
    if (pcVar2 == *(char **)(param_1 + 0x44)) {
      return;
    }
    cVar1 = **(char **)(param_1 + 0x48);
    if ((((cVar1 < '0') || ('9' < cVar1)) && (cVar1 != '.')) &&
       (((cVar1 != 'e' && (cVar1 != 'E')) && ((cVar1 != '+' && (cVar1 != '-')))))) break;
    pcVar2 = *(char **)(param_1 + 0x48) + 1;
    *(char **)(param_1 + 0x48) = pcVar2;
  }
  return;
}



// ===== FUN_00403580 @ 00403580 =====

bool __fastcall FUN_00403580(int param_1)

{
  char *pcVar1;
  char cVar2;
  
  cVar2 = '\0';
  pcVar1 = *(char **)(param_1 + 0x48);
  while (pcVar1 != *(char **)(param_1 + 0x44)) {
    cVar2 = *pcVar1;
    *(char **)(param_1 + 0x48) = pcVar1 + 1;
    if (cVar2 == '\\') {
      if (pcVar1 + 1 != *(char **)(param_1 + 0x44)) {
        *(char **)(param_1 + 0x48) = pcVar1 + 2;
      }
    }
    else if (cVar2 == '\"') break;
    pcVar1 = *(char **)(param_1 + 0x48);
  }
  return cVar2 == '\"';
}



// ===== FUN_004035c0 @ 004035c0 =====

void __thiscall FUN_004035c0(void *this,int param_1)

{
  undefined8 *puVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  char *****pppppcVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_a8 [3];
  undefined4 local_9c [3];
  void *local_90 [5];
  uint local_7c;
  undefined4 local_78;
  int local_74 [3];
  int local_68 [3];
  int local_5c [3];
  undefined8 *local_50;
  undefined1 local_49;
  char *****local_48 [4];
  char ****local_38;
  char ****local_34;
  undefined8 *local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined8 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  char ****local_8;
  
  puStack_c = &LAB_0041d3cc;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_48 + 0x11);
  ExceptionList = &local_10;
  local_34 = (char ****)0xf;
  local_38 = (char ****)0x0;
  local_48[0] = (char *****)((uint)local_48[0] & 0xffffff00);
  local_8 = (char ****)0x0;
  pvStack_24 = (void *)0x0;
  uStack_28 = uStack_28 & 0xfffffe07 | 7;
  local_20 = 0;
  local_30 = operator_new(8);
  local_8._0_1_ = 1;
  local_50 = local_30;
  if (local_30 == (undefined8 *)0x0) {
    local_30 = (undefined8 *)0x0;
  }
  else {
    *local_30 = 0;
    *(undefined4 *)local_30 = 0;
    *(undefined4 *)((int)local_30 + 4) = 0;
    uVar3 = FUN_0040a290();
    *(undefined4 *)local_30 = uVar3;
  }
  piVar5 = local_74;
  local_8._0_1_ = 2;
  pvVar4 = (void *)FUN_0040a080(this,local_68);
  piVar5 = (int *)FUN_0040a250(pvVar4,piVar5);
  if ((int *)*piVar5 == (int *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)*piVar5;
  }
  FUN_00405560(*(void **)(*(int *)(*(int *)(iVar8 + 4) + (*(int *)(iVar8 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                         (piVar5[2] & 3U) * 4),(char *)&local_30);
  local_8 = (char ****)((uint)local_8._1_3_ << 8);
  FUN_004054d0(&local_30);
  piVar5 = local_74;
  pvVar4 = (void *)FUN_0040a080(this,local_68);
  piVar5 = (int *)FUN_0040a250(pvVar4,piVar5);
  iVar8 = 0;
  if ((int *)*piVar5 != (int *)0x0) {
    iVar8 = *(int *)*piVar5;
  }
  *(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + (*(int *)(iVar8 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                   (piVar5[2] & 3U) * 4) + 0x10) = *(int *)(param_1 + 4) - *(int *)((int)this + 0x40);
  uVar3 = FUN_004030b0(this,local_5c);
  if ((char)uVar3 == '\0') {
LAB_00403a05:
    local_20 = 0xf00000000;
    local_30 = (undefined8 *)((uint)local_30 & 0xffffff00);
    FUN_00401f80(&local_30,(int *)"Missing \'}\' or object member name",0x21);
    local_8 = (char ****)CONCAT31(local_8._1_3_,7);
    uVar6 = FUN_00404ea0(this,&local_30,(undefined8 *)local_5c,2);
    local_49 = (undefined1)uVar6;
    if (0xf < local_20._4_4_) {
      operator_delete(local_30);
    }
    local_20 = 0xf00000000;
    local_30 = (undefined8 *)((uint)local_30 & 0xffffff00);
LAB_00403a62:
    if ((char ****)0xf < local_34) {
      operator_delete(local_48[0]);
    }
    ExceptionList = local_10;
    FUN_0041c21c(local_18 ^ (uint)(local_48 + 0x11));
    return;
  }
  do {
    uVar3 = 1;
    if (local_5c[0] == 0xc) {
      do {
        if ((char)uVar3 == '\0') goto LAB_00403a05;
        uVar3 = FUN_004030b0(this,local_5c);
      } while (local_5c[0] == 0xc);
      if ((char)uVar3 == '\0') goto LAB_00403a05;
    }
    iVar8 = local_5c[0];
    if ((local_5c[0] == 2) && (local_38 == (char ****)0x0)) {
LAB_00403a94:
      local_49 = 1;
      goto LAB_00403a62;
    }
    FUN_00401f80(local_48,(int *)&DAT_0041f7b1,0);
    if (iVar8 == 5) {
      cVar2 = FUN_00404710(this,(undefined8 *)local_5c,local_48);
      if (cVar2 == '\0') {
        uVar6 = FUN_00404e50(this,2);
        local_49 = (undefined1)uVar6;
        goto LAB_00403a62;
      }
    }
    else {
      if ((iVar8 != 6) || (*(char *)((int)this + 0x6f) == '\0')) goto LAB_00403a05;
      local_30 = (undefined8 *)0x0;
      uStack_2c = 0;
      pvStack_24 = (void *)0x0;
      local_20 = 0;
      uStack_28 = 0;
      local_8._0_1_ = 4;
      cVar2 = FUN_00403f90(this,(undefined8 *)local_5c,&local_30);
      if (cVar2 == '\0') {
        uVar6 = FUN_00404e50(this,2);
        local_49 = (undefined1)uVar6;
        local_8 = (char ****)((uint)local_8._1_3_ << 8);
        FUN_004054d0(&local_30);
        goto LAB_00403a62;
      }
      pppppcVar7 = (char *****)FUN_00405660(&local_30,(undefined1 *)local_90);
      if (local_48 != (char ******)pppppcVar7) {
        if ((char ****)0xf < local_34) {
          operator_delete(local_48[0]);
        }
        local_34 = (char ****)0xf;
        local_38 = (char ****)0x0;
        local_48[0] = (char *****)((uint)local_48[0] & 0xffffff00);
        if (pppppcVar7[5] < (char ****)0x10) {
          if ((int)pppppcVar7[4] + 1U != 0) {
            memmove(local_48,pppppcVar7,(int)pppppcVar7[4] + 1U);
          }
        }
        else {
          local_48[0] = (char *****)*pppppcVar7;
          *pppppcVar7 = (char ****)0x0;
        }
        local_38 = pppppcVar7[4];
        local_34 = pppppcVar7[5];
        pppppcVar7[5] = (char ****)0xf;
        pppppcVar7[4] = (char ****)0x0;
        *(undefined1 *)pppppcVar7 = 0;
      }
      if (0xf < local_7c) {
        operator_delete(local_90[0]);
      }
      puVar1 = local_30;
      local_8 = (char ****)((uint)local_8._1_3_ << 8);
      if ((char)uStack_28 == 4) {
        if (((uStack_28 & 0x100) != 0) && (local_30 != (undefined8 *)0x0)) {
          free(local_30);
        }
      }
      else if (((int)(char)uStack_28 - 6U < 2) && (local_30 != (undefined8 *)0x0)) {
        FUN_004096a0(local_30,&local_78,(int *)**(int **)local_30,*(int **)local_30);
        operator_delete(*(void **)puVar1);
        operator_delete(puVar1);
      }
      if (pvStack_24 != (void *)0x0) {
        pvVar4 = (void *)((int)pvStack_24 + -4);
        _eh_vector_destructor_iterator_
                  (pvStack_24,4,*(int *)((int)pvStack_24 + -4),(_func_void_void_ptr *)&LAB_00405090);
        operator_delete__(pvVar4);
      }
    }
    uVar3 = FUN_004030b0(this,local_74);
    if (((char)uVar3 == '\0') || (local_74[0] != 0xb)) {
      FUN_00401d40(&local_30,(int *)"Missing \':\' after object member name");
      local_8 = (char ****)CONCAT31(local_8._1_3_,5);
      piVar5 = local_74;
LAB_00403ad0:
      uVar6 = FUN_00404ea0(this,&local_30,(undefined8 *)piVar5,2);
      local_49 = (undefined1)uVar6;
      if (0xf < local_20._4_4_) {
        operator_delete(local_30);
      }
      goto LAB_00403a62;
    }
    puVar9 = local_9c;
    pvVar4 = (void *)FUN_0040a080(this,local_a8);
    piVar5 = (int *)FUN_0040a250(pvVar4,puVar9);
    if ((int *)*piVar5 == (int *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)*piVar5;
    }
    pppppcVar7 = (char *****)local_48;
    if ((char ****)0xf < local_34) {
      pppppcVar7 = local_48[0];
    }
    local_50 = (undefined8 *)
               FUN_004062c0(*(void **)(*(int *)(*(int *)(iVar8 + 4) +
                                               (*(int *)(iVar8 + 8) - 1U & (uint)piVar5[2] >> 2) * 4) +
                                      (piVar5[2] & 3U) * 4),(char *)pppppcVar7);
    FUN_00409a50(this,&local_50);
    cVar2 = FUN_00402a10(this);
    piVar5 = (int *)((int)this + 0x10);
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    if (cVar2 == '\0') {
      uVar6 = FUN_00404e50(this,2);
      local_49 = (undefined1)uVar6;
      goto LAB_00403a62;
    }
    uVar3 = FUN_004030b0(this,local_68);
    if (((char)uVar3 == '\0') || (((local_68[0] != 2 && (local_68[0] != 10)) && (local_68[0] != 0xc)))) {
      FUN_00401d40(&local_30,(int *)"Missing \',\' or \'}\' in object declaration");
      local_8 = (char ****)CONCAT31(local_8._1_3_,6);
      piVar5 = local_68;
      goto LAB_00403ad0;
    }
    cVar2 = '\x01';
    while ((local_68[0] == 0xc && (cVar2 != '\0'))) {
      uVar3 = FUN_004030b0(this,local_68);
      cVar2 = (char)uVar3;
    }
    if (local_68[0] == 2) goto LAB_00403a94;
    uVar3 = FUN_004030b0(this,local_5c);
    if ((char)uVar3 == '\0') goto LAB_00403a05;
  } while( true );
}



// ===== FUN_00403b20 @ 00403b20 =====

void __thiscall FUN_00403b20(void *this,int param_1)

{
  char *pcVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined ***pppuVar9;
  undefined4 *puVar10;
  undefined4 local_74 [3];
  void *local_68 [4];
  undefined4 local_58;
  uint local_54;
  char *local_50 [2];
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [3];
  int local_28 [3];
  char *local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d41c;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_28 + 9);
  ExceptionList = &local_10;
  local_44 = 0;
  local_48 = local_48 & 0xfffffe06 | 6;
  local_40 = 0;
  local_3c = 0;
  local_50[0] = operator_new(8);
  local_8 = 0;
  local_1c = local_50[0];
  if (local_50[0] == (char *)0x0) {
    local_50[0] = (char *)0x0;
  }
  else {
    local_50[0][0] = '\0';
    local_50[0][1] = '\0';
    local_50[0][2] = '\0';
    local_50[0][3] = '\0';
    local_50[0][4] = '\0';
    local_50[0][5] = '\0';
    local_50[0][6] = '\0';
    local_50[0][7] = '\0';
    local_50[0][0] = '\0';
    local_50[0][1] = '\0';
    local_50[0][2] = '\0';
    local_50[0][3] = '\0';
    local_50[0][4] = '\0';
    local_50[0][5] = '\0';
    local_50[0][6] = '\0';
    local_50[0][7] = '\0';
    uVar4 = FUN_0040a290();
    *(undefined4 *)local_50[0] = uVar4;
  }
  pppuVar9 = local_34;
  local_8 = 1;
  pvVar5 = (void *)FUN_0040a080(this,local_28);
  piVar6 = (int *)FUN_0040a250(pvVar5,pppuVar9);
  if ((int *)*piVar6 == (int *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)*piVar6;
  }
  FUN_00405560(*(void **)(*(int *)(*(int *)(iVar8 + 4) + (*(int *)(iVar8 + 8) - 1U & (uint)piVar6[2] >> 2) * 4) +
                         (piVar6[2] & 3U) * 4),(char *)local_50);
  local_8 = 0xffffffff;
  FUN_004054d0(local_50);
  pppuVar9 = local_34;
  pvVar5 = (void *)FUN_0040a080(this,local_28);
  piVar6 = (int *)FUN_0040a250(pvVar5,pppuVar9);
  iVar8 = 0;
  if ((int *)*piVar6 != (int *)0x0) {
    iVar8 = *(int *)*piVar6;
  }
  *(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + (*(int *)(iVar8 + 8) - 1U & (uint)piVar6[2] >> 2) * 4) +
                   (piVar6[2] & 3U) * 4) + 0x10) = *(int *)(param_1 + 4) - *(int *)((int)this + 0x40);
  pcVar1 = *(char **)((int)this + 0x48);
  while (pcVar1 != *(char **)((int)this + 0x44)) {
    cVar3 = **(char **)((int)this + 0x48);
    if ((((cVar3 != ' ') && (cVar3 != '\t')) && (cVar3 != '\r')) && (cVar3 != '\n')) break;
    pcVar1 = *(char **)((int)this + 0x48) + 1;
    *(char **)((int)this + 0x48) = pcVar1;
  }
  if (**(char **)((int)this + 0x48) == ']') {
    FUN_004030b0(this,local_34);
  }
  else {
    uVar7 = 0;
    do {
      puVar10 = local_74;
      pvVar5 = (void *)FUN_0040a080(this,&local_44);
      piVar6 = (int *)FUN_0040a250(pvVar5,puVar10);
      iVar8 = 0;
      if ((int *)*piVar6 != (int *)0x0) {
        iVar8 = *(int *)*piVar6;
      }
      if ((int)uVar7 < 0) {
        local_1c = "in Json::Value::operator[](int index): index cannot be negative";
        std::exception::exception((exception *)local_34,&local_1c);
        local_34[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_34,(ThrowInfo *)&DAT_0042665c);
      }
      local_38 = FUN_00405fd0(*(void **)(*(int *)(*(int *)(iVar8 + 4) +
                                                 (*(int *)(iVar8 + 8) - 1U & (uint)piVar6[2] >> 2) * 4) +
                                        (piVar6[2] & 3U) * 4),uVar7);
      uVar7 = uVar7 + 1;
      FUN_00409a50(this,&local_38);
      cVar3 = FUN_00402a10(this);
      piVar6 = (int *)((int)this + 0x10);
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        *(undefined4 *)((int)this + 0xc) = 0;
      }
      if (cVar3 == '\0') {
        FUN_00404e50(this,4);
        break;
      }
      uVar4 = FUN_004030b0(this,local_28);
      cVar3 = (char)uVar4;
      while ((local_28[0] == 0xc && (cVar3 = '\0', (char)uVar4 != '\0'))) {
        uVar4 = FUN_004030b0(this,local_28);
        cVar3 = (char)uVar4;
      }
      if ((local_28[0] == 10) || (local_28[0] == 4)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((cVar3 == '\0') || (bVar2)) {
        local_54 = 0xf;
        local_58 = 0;
        local_68[0] = (void *)((uint)local_68[0] & 0xffffff00);
        FUN_00401f80(local_68,(int *)"Missing \',\' or \']\' in array declaration",0x27);
        local_8 = 2;
        FUN_00404ea0(this,local_68,(undefined8 *)local_28,4);
        if (0xf < local_54) {
          operator_delete(local_68[0]);
        }
        break;
      }
    } while (local_28[0] != 4);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_28 + 9));
  return;
}



// ===== FUN_00403e00 @ 00403e00 =====

void __thiscall FUN_00403e00(void *this,undefined8 *param_1)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_50 [3];
  undefined4 local_44 [3];
  undefined8 *local_38;
  undefined1 local_31;
  char local_30 [8];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined8 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041d458;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_30 + 0x2c);
  ExceptionList = &local_10;
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = '\0';
  local_30[5] = '\0';
  local_30[6] = '\0';
  local_30[7] = '\0';
  local_38 = param_1;
  uStack_24 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_8 = 1;
  cVar1 = FUN_00403f90(this,param_1,local_30);
  if (cVar1 == '\0') {
    local_31 = 0;
  }
  else {
    puVar5 = local_44;
    pvVar2 = (void *)FUN_0040a080(this,local_50);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar5);
    if ((int *)*piVar3 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)*piVar3;
    }
    FUN_00405560(*(void **)(*(int *)(*(int *)(iVar4 + 4) + (*(int *)(iVar4 + 8) - 1U & (uint)piVar3[2] >> 2) * 4) +
                           (piVar3[2] & 3U) * 4),local_30);
    puVar5 = local_50;
    pvVar2 = (void *)FUN_0040a080(this,local_44);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar5);
    iVar4 = 0;
    if ((int *)*piVar3 != (int *)0x0) {
      iVar4 = *(int *)*piVar3;
    }
    *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + (*(int *)(iVar4 + 8) - 1U & (uint)piVar3[2] >> 2) * 4) +
                     (piVar3[2] & 3U) * 4) + 0x10) = *(int *)((int)local_38 + 4) - *(int *)((int)this + 0x40);
    puVar5 = local_50;
    pvVar2 = (void *)FUN_0040a080(this,local_44);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar5);
    iVar4 = 0;
    if ((int *)*piVar3 != (int *)0x0) {
      iVar4 = *(int *)*piVar3;
    }
    local_31 = 1;
    *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + (*(int *)(iVar4 + 8) - 1U & (uint)piVar3[2] >> 2) * 4) +
                     (piVar3[2] & 3U) * 4) + 0x14) = *(int *)(local_38 + 1) - *(int *)((int)this + 0x40);
  }
  local_8 = 0xffffffff;
  FUN_004054d0((undefined4 *)local_30);
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_30 + 0x2c));
  return;
}



// ===== FUN_00403f90 @ 00403f90 =====

/* WARNING: Removing unreachable block (ram,0x004040a2) */

undefined1 __thiscall FUN_00403f90(void *this,undefined8 *param_1,void *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  void **ppvVar6;
  int *piVar7;
  void *pvVar8;
  int *piVar9;
  bool bVar10;
  ulonglong uVar11;
  void *local_7c [4];
  undefined4 local_6c;
  uint local_68;
  void *local_64 [4];
  undefined4 local_54;
  uint local_50;
  void *local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  void *local_34;
  uint local_30;
  undefined8 local_2c;
  uint local_24;
  uint local_20;
  void *local_1c;
  uint local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d4b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar10 = false;
  piVar9 = *(int **)((int)param_1 + 4);
  piVar7 = piVar9;
  local_34 = this;
  if (piVar9 != *(int **)(param_1 + 1)) {
    do {
      if (((((bVar10) || (cVar1 = (char)*piVar7, cVar1 == '.')) || (cVar1 == 'e')) || ((cVar1 == 'E' || (cVar1 == '+')))
          ) || ((cVar1 == '-' && (piVar7 != piVar9)))) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
      piVar7 = (int *)((int)piVar7 + 1);
    } while (piVar7 != *(int **)(param_1 + 1));
    if (bVar10) {
      uVar5 = FUN_004042f0(this,param_1,param_2);
      ExceptionList = local_10;
      return uVar5;
    }
  }
  local_11 = (char)*piVar9 == '-';
  if ((bool)local_11) {
    piVar9 = (int *)((int)piVar9 + 1);
    local_24 = 0x80000000;
    local_20 = 0;
  }
  else {
    local_20 = 0xffffffff;
    local_24 = 0xffffffff;
  }
  uVar11 = __aulldiv(local_20,local_24,10,0);
  local_30 = (uint)(uVar11 >> 0x20);
  local_1c = (void *)uVar11;
  piVar7 = *(int **)(param_1 + 1);
  local_2c = 0;
  local_2c._4_4_ = 0;
  local_2c._0_4_ = (void *)0x0;
  pvVar8 = (void *)local_2c;
  local_48 = local_2c._4_4_;
  if (piVar9 < piVar7) {
    do {
      cVar1 = (char)*piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      local_2c = ZEXT48(piVar9) << 0x20;
      if ((cVar1 < '0') || ('9' < cVar1)) {
        local_38 = 0xf;
        local_3c = 0;
        local_4c = (void *)((uint)local_4c & 0xffffff00);
        piVar9 = *(int **)((int)param_1 + 4);
        if (piVar9 != piVar7) {
          FUN_00401f80(&local_4c,piVar9,(int)piVar7 - (int)piVar9);
          uVar11 = CONCAT44(local_30,local_1c);
        }
        local_30 = (uint)(uVar11 >> 0x20);
        local_1c = (void *)uVar11;
        local_8 = 0;
        piVar9 = FUN_0040a2c0((int *)local_7c,(int *)&DAT_0041f8f8,&local_4c);
        local_8._0_1_ = 1;
        ppvVar6 = (void **)FUN_0040a350((int *)local_64,piVar9,(int *)"\' is not a number.");
        local_8 = CONCAT31(local_8._1_3_,2);
        uVar5 = FUN_00404d50(local_34,ppvVar6,param_1,0);
        if (0xf < local_50) {
          operator_delete(local_64[0]);
        }
        local_50 = 0xf;
        local_54 = 0;
        local_64[0] = (void *)((uint)local_64[0] & 0xffffff00);
        if (0xf < local_68) {
          operator_delete(local_7c[0]);
        }
        local_68 = 0xf;
        local_6c = 0;
        local_7c[0] = (void *)((uint)local_7c[0] & 0xffffff00);
        if (0xf < local_38) {
          operator_delete(local_4c);
        }
        ExceptionList = local_10;
        return uVar5;
      }
      local_18 = (int)cVar1 - 0x30;
      if ((local_30 <= local_48) &&
         ((local_30 < local_48 ||
          ((local_1c <= pvVar8 &&
           (((uVar11 < CONCAT44(local_48,pvVar8) || (piVar9 != piVar7)) ||
            ((local_24 -
              ((local_30 + (local_30 << 2 | (uint)local_1c >> 0x1e) + (uint)CARRY4((uint)local_1c,(int)local_1c * 4)) *
               2 | (uint)((int)local_1c * 5) >> 0x1f) == (uint)(local_20 < (uint)((int)local_1c * 10)) &&
             (local_20 + (int)local_1c * -10 < local_18)))))))))) {
        uVar5 = FUN_004042f0(local_34,param_1,param_2);
        ExceptionList = local_10;
        return uVar5;
      }
      uVar2 = (uint)pvVar8 >> 0x1e;
      bVar10 = CARRY4((uint)pvVar8,(int)pvVar8 * 4);
      uVar3 = (int)pvVar8 * 5;
      piVar7 = *(int **)(param_1 + 1);
      uVar4 = (int)pvVar8 * 10;
      pvVar8 = (void *)(uVar4 + local_18);
      local_48 = ((local_48 + (local_48 << 2 | uVar2) + (uint)bVar10) * 2 | uVar3 >> 0x1f) +
                 (uint)CARRY4(uVar4,local_18);
    } while (piVar9 < piVar7);
  }
  if (local_11 == '\0') {
    local_4c = pvVar8;
    if ((local_48 == 0) && (pvVar8 < (void *)0x80000000)) {
      local_44 = local_44 & 0xfffffe01 | 1;
      local_8 = 4;
    }
    else {
      local_44 = local_44 & 0xfffffe02 | 2;
      local_8 = 5;
    }
  }
  else {
    local_44 = local_44 & 0xfffffe01 | 1;
    local_48 = -(local_48 + (pvVar8 != (void *)0x0));
    local_8 = 3;
    local_4c = (void *)-(int)pvVar8;
  }
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  FUN_00405560(param_2,(char *)&local_4c);
  local_8 = 0xffffffff;
  FUN_004054d0(&local_4c);
  ExceptionList = local_10;
  return 1;
}



// ===== FUN_004042f0 @ 004042f0 =====

void __thiscall FUN_004042f0(void *this,undefined8 *param_1,void *param_2)

{
  uint uVar1;
  int iVar2;
  int *_Src;
  ulonglong *_Src_00;
  int *piVar3;
  void **ppvVar4;
  int *extraout_ECX;
  uint _Size;
  void *local_84 [4];
  undefined4 local_74;
  uint local_70;
  void *local_6c;
  void *local_68;
  ulonglong local_64;
  char local_58 [4];
  ulonglong local_54;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  char local_38 [8];
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  void *local_8;
  
  local_8 = (void *)0xffffffff;
  puStack_c = &LAB_0041d4f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (uint)(local_30 + 0xb);
  ExceptionList = &local_10;
  local_6c = param_2;
  local_64 = 0;
  piVar3 = *(int **)(param_1 + 1);
  _Src = *(int **)((int)param_1 + 4);
  _Size = (int)piVar3 - (int)_Src;
  local_68 = this;
  local_14 = uVar1;
  if ((int)_Size < 0) {
    local_40 = 0xf;
    local_44 = 0;
    local_54 = local_54 & 0xffffffffffffff00;
    FUN_00401f80(&local_54,(int *)"Unable to parse token length",0x1c);
    local_8 = (void *)0x0;
    FUN_00404d50(this,(void **)&local_54,param_1,0);
    if (0xf < local_40) {
      operator_delete((ulonglong *)local_54);
    }
    goto LAB_0040453a;
  }
  builtin_strncpy(local_58,"%lf",4);
  if ((int)_Size < 0x21) {
    memcpy(local_38,_Src,_Size);
    if (0x20 < _Size) {
      _Src = (int *)___report_rangecheckfailure();
      piVar3 = extraout_ECX;
      goto LAB_004043d6;
    }
    local_38[_Size] = '\0';
    iVar2 = sscanf(local_38,local_58,&local_64,uVar1);
  }
  else {
LAB_004043d6:
    local_40 = 0xf;
    local_44 = 0;
    local_54 = local_54 & 0xffffffffffffff00;
    if (_Src == piVar3) {
LAB_00404401:
      _Src_00 = &local_54;
    }
    else {
      FUN_00401f80(&local_54,_Src,(int)piVar3 - (int)_Src);
      _Src_00 = (ulonglong *)local_54;
      if (local_40 < 0x10) goto LAB_00404401;
    }
    iVar2 = sscanf((char *)_Src_00,local_58,&local_64,uVar1);
    if (0xf < local_40) {
      operator_delete((ulonglong *)local_54);
    }
  }
  local_44 = 0;
  if (iVar2 == 1) {
    local_4c = local_4c & 0xfffffe03 | 3;
    local_48 = 0;
    local_40 = 0;
    local_54 = local_64;
    local_8 = (void *)0x4;
    FUN_00405560(local_6c,(char *)&local_54);
    local_8 = (void *)0xffffffff;
    FUN_004054d0((undefined4 *)&local_54);
  }
  else {
    piVar3 = *(int **)((int)param_1 + 4);
    local_40 = 0xf;
    local_54 = local_54 & 0xffffffffffffff00;
    if (piVar3 != *(int **)(param_1 + 1)) {
      FUN_00401f80(&local_54,piVar3,(int)*(int **)(param_1 + 1) - (int)piVar3);
    }
    local_8 = (void *)0x1;
    piVar3 = FUN_0040a2c0((int *)local_30,(int *)&DAT_0041f8f8,&local_54);
    local_8._0_1_ = 2;
    ppvVar4 = (void **)FUN_0040a350((int *)local_84,piVar3,(int *)"\' is not a number.");
    local_8 = (void *)CONCAT31(local_8._1_3_,3);
    FUN_00404d50(local_68,ppvVar4,param_1,0);
    if (0xf < local_70) {
      operator_delete(local_84[0]);
    }
    local_70 = 0xf;
    local_74 = 0;
    local_84[0] = (void *)((uint)local_84[0] & 0xffffff00);
    if (0xf < local_1c) {
      operator_delete(local_30[0]);
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
    if (0xf < local_40) {
      operator_delete((ulonglong *)local_54);
    }
  }
LAB_0040453a:
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_30 + 0xb));
  return;
}



// ===== FUN_00404560 @ 00404560 =====

void __thiscall FUN_00404560(void *this,undefined8 *param_1)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  char ****ppppcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_68 [3];
  undefined4 local_5c [3];
  undefined4 local_50 [2];
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 *local_34;
  char ****local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  char ***local_8;
  
  puStack_c = &LAB_0041d530;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_30 + 0xb);
  ExceptionList = &local_10;
  local_34 = param_1;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
  local_8 = (char ***)0x0;
  cVar1 = FUN_00404710(this,param_1,local_30);
  if (cVar1 != '\0') {
    local_48 = local_48 & 0xffffff04 | 0x104;
    local_44 = 0;
    ppppcVar4 = (char ****)local_30;
    if (0xf < local_1c) {
      ppppcVar4 = local_30[0];
    }
    local_40 = 0;
    local_3c = 0;
    local_50[0] = FUN_00404fd0((char *)ppppcVar4,local_20);
    puVar6 = local_68;
    local_8._0_1_ = 1;
    pvVar2 = (void *)FUN_0040a080(this,local_5c);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar6);
    iVar5 = 0;
    if ((int *)*piVar3 != (int *)0x0) {
      iVar5 = *(int *)*piVar3;
    }
    FUN_00405560(*(void **)(*(int *)(*(int *)(iVar5 + 4) + (*(int *)(iVar5 + 8) - 1U & (uint)piVar3[2] >> 2) * 4) +
                           (piVar3[2] & 3U) * 4),(char *)local_50);
    local_8 = (char ***)((uint)local_8._1_3_ << 8);
    FUN_004054d0(local_50);
    puVar6 = local_5c;
    pvVar2 = (void *)FUN_0040a080(this,local_68);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar6);
    iVar5 = 0;
    if ((int *)*piVar3 != (int *)0x0) {
      iVar5 = *(int *)*piVar3;
    }
    *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + ((uint)piVar3[2] >> 2 & *(int *)(iVar5 + 8) - 1U) * 4) +
                     (piVar3[2] & 3U) * 4) + 0x10) = *(int *)((int)local_34 + 4) - *(int *)((int)this + 0x40);
    puVar6 = local_5c;
    pvVar2 = (void *)FUN_0040a080(this,local_68);
    piVar3 = (int *)FUN_0040a250(pvVar2,puVar6);
    iVar5 = 0;
    if ((int *)*piVar3 != (int *)0x0) {
      iVar5 = *(int *)*piVar3;
    }
    *(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + ((uint)piVar3[2] >> 2 & *(int *)(iVar5 + 8) - 1U) * 4) +
                     (piVar3[2] & 3U) * 4) + 0x14) = *(int *)(local_34 + 1) - *(int *)((int)this + 0x40);
  }
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_30 + 0xb));
  return;
}



// ===== FUN_00404710 @ 00404710 =====

undefined1 __thiscall FUN_00404710(void *this,undefined8 *param_1,undefined4 *param_2)

{
  uint uVar1;
  size_t sVar2;
  bool bVar3;
  char cVar4;
  undefined1 uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  void *local_58 [5];
  uint local_44;
  void *local_40 [4];
  undefined4 local_30;
  uint local_2c;
  char *local_28;
  uint local_24;
  char *local_20;
  undefined8 *local_1c;
  void *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d578;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1;
  uVar1 = param_2[4];
  uVar6 = (*(int *)(param_1 + 1) - *(int *)((int)param_1 + 4)) - 2;
  local_18 = this;
  if (((uVar1 <= uVar6) && (param_2[5] != uVar6)) && (bVar3 = FUN_00402190(param_2,uVar6,'\x01'), bVar3)) {
    param_2[4] = uVar1;
    if ((uint)param_2[5] < 0x10) {
      puVar8 = param_2;
    }
    else {
      puVar8 = (undefined4 *)*param_2;
    }
    *(undefined1 *)((int)puVar8 + uVar1) = 0;
  }
  pcVar9 = (char *)(*(int *)((int)param_1 + 4) + 1);
  local_28 = (char *)(*(int *)(param_1 + 1) + -1);
  if (pcVar9 != local_28) {
    do {
      local_11 = *pcVar9;
      pcVar10 = pcVar9 + 1;
      if (local_11 == '\"') {
        ExceptionList = local_10;
        return 1;
      }
      if (local_11 == '\\') {
        if (pcVar10 == local_28) {
          FUN_00401d40(local_40,(int *)"Empty escape sequence in string");
          local_8 = 0;
          uVar5 = FUN_00404d50(local_18,local_40,param_1,pcVar10);
          if (0xf < local_2c) {
            operator_delete(local_40[0]);
          }
          ExceptionList = local_10;
          return uVar5;
        }
        pcVar9 = pcVar9 + 2;
        local_20 = pcVar9;
        switch(*pcVar10) {
        case '\"':
          FUN_00409420(param_2,1,'\"');
          break;
        default:
          local_2c = 0xf;
          local_30 = 0;
          local_40[0] = (void *)((uint)local_40[0] & 0xffffff00);
          FUN_00401f80(local_40,(int *)"Bad escape sequence in string",0x1d);
          local_8 = 2;
          uVar5 = FUN_00404d50(local_18,local_40,param_1,pcVar9);
          if (local_2c < 0x10) {
            ExceptionList = local_10;
            return uVar5;
          }
          operator_delete(local_40[0]);
          ExceptionList = local_10;
          return uVar5;
        case '/':
          FUN_00409420(param_2,1,'/');
          break;
        case '\\':
          FUN_00409420(param_2,1,'\\');
          break;
        case 'b':
          FUN_00409420(param_2,1,'\b');
          break;
        case 'f':
          FUN_00409420(param_2,1,'\f');
          break;
        case 'n':
          FUN_00409420(param_2,1,'\n');
          break;
        case 'r':
          FUN_00409420(param_2,1,'\r');
          break;
        case 't':
          FUN_00409420(param_2,1,'\t');
          break;
        case 'u':
          cVar4 = FUN_00404a90(local_18,param_1,(int *)&local_20,(int)local_28,&local_24);
          if (cVar4 == '\0') {
            ExceptionList = local_10;
            return 0;
          }
          piVar7 = FUN_00402520((int *)local_58,local_24);
          local_8 = 1;
          FUN_00409270(param_2,piVar7,0,0xffffffff);
          local_8 = 0xffffffff;
          if (0xf < local_44) {
            operator_delete(local_58[0]);
          }
          pcVar9 = local_20;
        }
      }
      else {
        sVar2 = param_2[4];
        if ((-sVar2 - 1 < 2) || (uVar1 = sVar2 + 1, uVar1 == 0xffffffff)) {
                    /* WARNING: Subroutine does not return */
          std::_Xlength_error("string too long");
        }
        if ((uint)param_2[5] < uVar1) {
          FUN_004022a0(param_2,uVar1,sVar2);
          if (uVar1 != 0) {
LAB_004048dd:
            if ((uint)param_2[5] < 0x10) {
              puVar8 = param_2;
            }
            else {
              puVar8 = (undefined4 *)*param_2;
            }
            *(char *)((int)puVar8 + param_2[4]) = local_11;
            param_2[4] = uVar1;
            if ((uint)param_2[5] < 0x10) {
              puVar8 = param_2;
            }
            else {
              puVar8 = (undefined4 *)*param_2;
            }
            *(undefined1 *)((int)puVar8 + uVar1) = 0;
          }
        }
        else {
          if (uVar1 != 0) goto LAB_004048dd;
          param_2[4] = 0;
          if ((uint)param_2[5] < 0x10) {
            *(undefined1 *)param_2 = 0;
          }
          else {
            *(undefined1 *)*param_2 = 0;
          }
        }
        param_1 = local_1c;
        pcVar9 = pcVar10;
      }
    } while (pcVar9 != local_28);
  }
  ExceptionList = local_10;
  return 1;
}



// ===== FUN_00404a90 @ 00404a90 =====

undefined1 __thiscall FUN_00404a90(void *this,undefined8 *param_1,int *param_2,int param_3,uint *param_4)

{
  char *pcVar1;
  uint *puVar2;
  char cVar3;
  undefined1 uVar4;
  void *local_44 [6];
  void *local_2c [6];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar2 = param_4;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d5b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = this;
  cVar3 = FUN_00404c00(this,param_1,param_2,param_3,(int *)param_4);
  if (cVar3 == '\0') {
    ExceptionList = local_10;
    return 0;
  }
  if ((0xd7ff < *puVar2) && (*puVar2 < 0xdc00)) {
    pcVar1 = (char *)*param_2;
    if (param_3 - (int)pcVar1 < 6) {
      FUN_00401d40(local_2c,(int *)"additional six characters expected to parse unicode surrogate pair.");
      local_8 = 0;
      uVar4 = FUN_00404d50(local_14,local_2c,param_1,*param_2);
      FUN_00401da0(local_2c);
      ExceptionList = local_10;
      return uVar4;
    }
    cVar3 = *pcVar1;
    *param_2 = (int)(pcVar1 + 1);
    if ((cVar3 != '\\') || (cVar3 = pcVar1[1], *param_2 = (int)(pcVar1 + 2), cVar3 != 'u')) {
      FUN_00401d40(local_44,(int *)"expecting another \\u token to begin the second half of a unicode surrogate pair");
      local_8 = 1;
      uVar4 = FUN_00404d50(local_14,local_44,param_1,*param_2);
      FUN_00401da0(local_44);
      ExceptionList = local_10;
      return uVar4;
    }
    cVar3 = FUN_00404c00(local_14,param_1,param_2,param_3,(int *)&param_4);
    if (cVar3 == '\0') {
      ExceptionList = local_10;
      return 0;
    }
    *puVar2 = ((*puVar2 & 0x3ff) + 0x40) * 0x400 + ((uint)param_4 & 0x3ff);
  }
  ExceptionList = local_10;
  return 1;
}



// ===== FUN_00404c00 @ 00404c00 =====

undefined1 __thiscall FUN_00404c00(void *this,undefined8 *param_1,int *param_2,int param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar6 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d5b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = this;
  if (param_3 - *param_2 < 4) {
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    FUN_00401f80(local_2c,(int *)"Bad unicode escape sequence in string: four digits expected.",0x3c);
    local_8 = 0;
    uVar3 = FUN_00404d50(this,local_2c,param_1,*param_2);
    if (0xf < local_18) {
      pvVar6 = local_2c[0];
LAB_00404d31:
      operator_delete(pvVar6);
    }
    ExceptionList = local_10;
    return uVar3;
  }
  iVar5 = 0;
  *param_4 = 0;
  do {
    cVar1 = *(char *)*param_2;
    *param_2 = (int)((char *)*param_2 + 1);
    iVar2 = *param_4;
    *param_4 = iVar2 * 0x10;
    if ((byte)(cVar1 - 0x30U) < 10) {
      iVar4 = cVar1 + -0x30;
    }
    else if ((byte)(cVar1 + 0x9fU) < 6) {
      iVar4 = cVar1 + -0x57;
    }
    else {
      if (5 < (byte)(cVar1 + 0xbfU)) {
        local_30 = 0xf;
        local_34 = 0;
        local_44[0] = (void *)((uint)local_44[0] & 0xffffff00);
        FUN_00401f80(local_44,(int *)"Bad unicode escape sequence in string: hexadecimal digit expected.",0x42);
        local_8 = 1;
        uVar3 = FUN_00404d50(local_14,local_44,param_1,*param_2);
        if (local_30 < 0x10) {
          ExceptionList = local_10;
          return uVar3;
        }
        pvVar6 = local_44[0];
        goto LAB_00404d31;
      }
      iVar4 = cVar1 + -0x37;
    }
    iVar5 = iVar5 + 1;
    *param_4 = iVar4 + iVar2 * 0x10;
    if (3 < iVar5) {
      ExceptionList = pvVar6;
      return 1;
    }
  } while( true );
}



// ===== FUN_00404d50 @ 00404d50 =====

void __thiscall FUN_00404d50(void *this,void **param_1,undefined8 *param_2,undefined4 param_3)

{
  undefined8 local_40;
  undefined4 uStack_38;
  void *pvStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined8 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041d5d8;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pvStack_34 = (void *)0x0;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  local_20 = 0xf;
  local_8 = 0;
  local_40 = *param_2;
  uStack_38 = *(undefined4 *)(param_2 + 1);
  if (&pvStack_34 != param_1) {
    FUN_00401e50(&pvStack_34,(int *)param_1,0,0xffffffff);
  }
  local_20 = CONCAT44(param_3,(uint)local_20);
  FUN_00408890((void *)((int)this + 0x14),&local_40);
  if (0xf < (uint)local_20) {
    operator_delete(pvStack_34);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00404e20 @ 00404e20 =====

void __fastcall FUN_00404e20(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x20)) {
    operator_delete(*(void **)(param_1 + 0xc));
  }
  *(undefined4 *)(param_1 + 0x20) = 0xf;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}



// ===== FUN_00404e50 @ 00404e50 =====

uint __thiscall FUN_00404e50(void *this,int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int local_10 [3];
  
  uVar2 = *(uint *)((int)this + 0x24);
  do {
    uVar1 = FUN_004030b0(this,local_10);
    if ((char)uVar1 == '\0') {
      FUN_004087b0((void *)((int)this + 0x14),uVar2);
    }
  } while ((local_10[0] != param_1) && (local_10[0] != 0));
  uVar2 = FUN_004087b0((void *)((int)this + 0x14),uVar2);
  return uVar2 & 0xffffff00;
}



// ===== FUN_00404ea0 @ 00404ea0 =====

uint __thiscall FUN_00404ea0(void *this,void **param_1,undefined8 *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int local_10 [3];
  
  FUN_00404d50(this,param_1,param_2,0);
  uVar2 = *(uint *)((int)this + 0x24);
  do {
    uVar1 = FUN_004030b0(this,local_10);
    if ((char)uVar1 == '\0') {
      FUN_004087b0((void *)((int)this + 0x14),uVar2);
    }
  } while ((local_10[0] != param_3) && (local_10[0] != 0));
  uVar2 = FUN_004087b0((void *)((int)this + 0x14),uVar2);
  return uVar2 & 0xffffff00;
}



// ===== FUN_00404f00 @ 00404f00 =====

undefined4 __fastcall FUN_00404f00(void *param_1)

{
  void *this;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_1c [3];
  undefined4 local_10 [3];
  
  puVar3 = local_10;
  this = (void *)FUN_0040a080(param_1,local_1c);
  piVar1 = (int *)FUN_0040a250(this,puVar3);
  iVar2 = 0;
  if ((int *)*piVar1 != (int *)0x0) {
    iVar2 = *(int *)*piVar1;
  }
  return *(undefined4 *)
          (*(int *)(*(int *)(iVar2 + 4) + ((uint)piVar1[2] >> 2 & *(int *)(iVar2 + 8) - 1U) * 4) + (piVar1[2] & 3U) * 4)
  ;
}



// ===== FUN_00404f50 @ 00404f50 =====

void __fastcall FUN_00404f50(undefined4 *param_1)

{
  if (0xf < (uint)param_1[0x1a]) {
    operator_delete((void *)param_1[0x15]);
  }
  param_1[0x1a] = 0xf;
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  if (0xf < (uint)param_1[0xf]) {
    operator_delete((void *)param_1[10]);
  }
  param_1[0xf] = 0xf;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  FUN_00409cd0((int)(param_1 + 5));
  operator_delete((void *)param_1[5]);
  param_1[5] = 0;
  FUN_00409ae0((int)param_1);
  operator_delete((void *)*param_1);
  *param_1 = 0;
  return;
}



// ===== FUN_00404fd0 @ 00404fd0 =====

void __fastcall FUN_00404fd0(char *param_1,uint param_2)

{
  char cVar1;
  void *_Dst;
  char *pcVar2;
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  if (param_2 == 0xffffffff) {
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    param_2 = (int)pcVar2 - (int)(param_1 + 1);
  }
  if (0x7ffffffe < param_2) {
    param_2 = 0x7ffffffe;
  }
  _Dst = malloc(-(uint)(0xfffffffe < param_2) | param_2 + 1);
  if (_Dst == (void *)0x0) {
    local_c = "in Json::Value::duplicateStringValue(): Failed to allocate string value buffer";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  }
  memcpy(_Dst,param_1,param_2);
  *(undefined1 *)(param_2 + (int)_Dst) = 0;
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_004050a0 @ 004050a0 =====

void __thiscall FUN_004050a0(void *this,char *param_1)

{
  undefined4 uVar1;
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  if (*(void **)this != (void *)0x0) {
    free(*(void **)this);
  }
  if ((*param_1 != '\0') && (*param_1 != '/')) {
    local_c = "in Json::Value::setComment(): Comments must start with /";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  }
  uVar1 = FUN_00404fd0(param_1,0xffffffff);
  *(undefined4 *)this = uVar1;
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_00405120 @ 00405120 =====

void __fastcall FUN_00405120(undefined4 *param_1)

{
  if (((void *)*param_1 != (void *)0x0) && (param_1[1] == 1)) {
    free((void *)*param_1);
  }
  return;
}



// ===== FUN_00405140 @ 00405140 =====

bool __thiscall FUN_00405140(void *this,undefined4 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = *(byte **)this;
  if (pbVar3 == (byte *)0x0) {
    return *(int *)((int)this + 4) == param_1[1];
  }
  pbVar2 = (byte *)*param_1;
  while( true ) {
    bVar1 = *pbVar3;
    bVar4 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return true;
    }
    bVar1 = pbVar3[1];
    bVar4 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    pbVar3 = pbVar3 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return true;
    }
  }
  return (-(uint)bVar4 | 1) == 0;
}



// ===== FUN_004051a0 @ 004051a0 =====

undefined4 * __thiscall FUN_004051a0(void *this,undefined4 param_1)

{
  *(undefined1 *)((int)this + 8) = 2;
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffeff;
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  return this;
}



// ===== FUN_004051e0 @ 004051e0 =====

int * __thiscall FUN_004051e0(void *this,int param_1)

{
  *(undefined1 *)((int)this + 8) = 1;
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffeff;
  *(int *)this = param_1;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(int *)((int)this + 4) = param_1 >> 0x1f;
  return this;
}



// ===== FUN_00405220 @ 00405220 =====

undefined4 * __thiscall FUN_00405220(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined1 *)((int)this + 8) = 2;
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffeff;
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return this;
}



// ===== FUN_00405260 @ 00405260 =====

undefined4 * __thiscall FUN_00405260(void *this,char *param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)((int)this + 8) = 4;
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) | 0x100;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  uVar1 = FUN_00404fd0(param_1,0xffffffff);
  *(undefined4 *)this = uVar1;
  return this;
}



// ===== FUN_004052a0 @ 004052a0 =====

undefined4 * __thiscall FUN_004052a0(void *this,char *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  
  *(undefined1 *)((int)this + 8) = 4;
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) | 0x100;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  puVar1 = (uint *)(param_1 + 0x10);
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  uVar2 = FUN_00404fd0(param_1,*puVar1);
  *(undefined4 *)this = uVar2;
  return this;
}



// ===== FUN_004052f0 @ 004052f0 =====

void __thiscall FUN_004052f0(void *this,char *param_1)

{
  char *pcVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined **local_28 [3];
  undefined8 *local_1c;
  char *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined **local_8;
  
  local_8 = (undefined **)0xffffffff;
  puStack_c = &LAB_0041d618;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_28 + 9);
  ExceptionList = &local_10;
  local_18 = param_1;
  *(char *)((int)this + 8) = param_1[8];
  *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffeff;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  switch((char)*(uint *)((int)this + 8)) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x05':
    *(undefined4 *)this = *(undefined4 *)param_1;
    *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
    break;
  case '\x04':
    if (*(char **)param_1 == (char *)0x0) {
      *(undefined4 *)this = 0;
      *(uint *)((int)this + 8) = *(uint *)((int)this + 8) & 0xfffffeff;
    }
    else {
      uVar3 = FUN_00404fd0(*(char **)param_1,0xffffffff);
      *(uint *)((int)this + 8) = *(uint *)((int)this + 8) | 0x100;
      *(undefined4 *)this = uVar3;
    }
    break;
  case '\x06':
  case '\a':
    puVar2 = operator_new(8);
    local_8 = (undefined **)0x0;
    local_1c = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
      puVar2 = (undefined8 *)0x0;
    }
    else {
      *puVar2 = 0;
      FUN_00409600(puVar2,*(int **)param_1);
    }
    local_8 = (undefined **)0xffffffff;
    *(undefined8 **)this = puVar2;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    local_1c = (undefined8 *)FUN_0041c1dc(0x10);
    local_8 = (undefined **)0x1;
    if (local_1c == (undefined8 *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (int)local_1c + 4;
      *(undefined4 *)local_1c = 3;
      FUN_0041c675(iVar4,4,3,&LAB_00405080);
    }
    local_8 = (undefined **)0xffffffff;
    *(int *)((int)this + 0xc) = iVar4;
    iVar4 = 0;
    while( true ) {
      pcVar1 = *(char **)(*(int *)(param_1 + 0xc) + iVar4);
      if (pcVar1 != (char *)0x0) {
        local_1c = (undefined8 *)(*(int *)((int)this + 0xc) + iVar4);
        if (*(void **)local_1c != (void *)0x0) {
          free(*(void **)local_1c);
        }
        if ((*pcVar1 != '\0') && (*pcVar1 != '/')) {
          local_18 = "in Json::Value::setComment(): Comments must start with /";
          std::exception::exception((exception *)local_28,&local_18);
          local_28[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_28,(ThrowInfo *)&DAT_0042665c);
        }
        uVar3 = FUN_00404fd0(pcVar1,0xffffffff);
        *(undefined4 *)local_1c = uVar3;
      }
      iVar4 = iVar4 + 4;
      if (0xb < iVar4) break;
      param_1 = local_18;
    }
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_28 + 9));
  return;
}



// ===== FUN_004054d0 @ 004054d0 =====

void __fastcall FUN_004054d0(undefined4 *param_1)

{
  undefined4 *this;
  void *pvVar1;
  undefined4 *local_8;
  
  local_8 = param_1;
  if (*(char *)(param_1 + 2) == 4) {
    if (((param_1[2] & 0x100) != 0) && ((void *)*param_1 != (void *)0x0)) {
      free((void *)*param_1);
    }
  }
  else if (((int)*(char *)(param_1 + 2) - 6U < 2) && (this = (undefined4 *)*param_1, this != (undefined4 *)0x0)) {
    FUN_004096a0(this,&local_8,*(int **)*this,(int *)*this);
    operator_delete((void *)*this);
    operator_delete(this);
  }
  pvVar1 = (void *)param_1[3];
  if (pvVar1 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar1,4,*(int *)((int)pvVar1 + -4),(_func_void_void_ptr *)&LAB_00405090);
    operator_delete__((void *)((int)pvVar1 + -4));
  }
  return;
}



// ===== FUN_00405560 @ 00405560 =====

void __thiscall FUN_00405560(void *this,char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined8 local_18;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  local_18 = 0;
  local_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  FUN_004052f0(&local_28,param_1);
  cVar1 = *(char *)((int)this + 8);
  *(undefined1 *)((int)this + 8) = (undefined1)uStack_20;
  uVar2 = *(undefined4 *)((int)this + 4);
  uVar3 = *(undefined4 *)this;
  uStack_20 = uStack_20 ^ (uStack_20 ^ (int)cVar1) & 0xff;
  *(undefined4 *)this = local_28;
  *(undefined4 *)((int)this + 4) = uStack_24;
  uVar4 = *(uint *)((int)this + 8);
  *(uint *)((int)this + 8) = (uVar4 ^ uStack_20) & 0x100 ^ uVar4;
  uVar5 = *(undefined4 *)((int)this + 0x10);
  uStack_20 = uStack_20 ^ (((int)(uVar4 << 0x17) >> 0x1f) << 8 ^ uStack_20) & 0x100;
  *(undefined4 *)((int)this + 0x10) = (undefined4)local_18;
  uVar6 = *(undefined4 *)((int)this + 0x14);
  *(undefined4 *)((int)this + 0x14) = local_18._4_4_;
  local_18 = CONCAT44(uVar6,uVar5);
  local_28 = uVar3;
  uStack_24 = uVar2;
  FUN_004054d0(&local_28);
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_00405620 @ 00405620 =====

void FUN_00405620(void)

{
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  local_c = "in Json::Value::asCString(): requires stringValue";
  std::exception::exception((exception *)local_18,&local_c);
  local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
}



// ===== FUN_00405660 @ 00405660 =====

void __thiscall FUN_00405660(void *this,undefined1 *param_1)

{
  char *pcVar1;
  undefined **local_20 [3];
  undefined4 local_14;
  char *local_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  local_14 = 0;
  switch(*(undefined1 *)((int)this + 8)) {
  case 0:
    pcVar1 = &DAT_0041f7b1;
    break;
  case 1:
    FUN_00406ad0(param_1,*(int *)this,*(int *)((int)this + 4));
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  case 2:
    FUN_00406bb0(param_1,*(undefined4 *)this,*(undefined4 *)((int)this + 4));
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  case 3:
    FUN_00406c50(param_1);
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  case 4:
    pcVar1 = &DAT_0041f7b1;
    if (*(int **)this != (int *)0x0) {
      pcVar1 = (char *)*(int **)this;
    }
    break;
  case 5:
    pcVar1 = &DAT_0041f7ac;
    if (*(char *)this == '\0') {
      pcVar1 = "false";
    }
    break;
  default:
    local_10 = "Type is not convertible to string";
    std::exception::exception((exception *)local_20,&local_10);
    local_20[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_20,(ThrowInfo *)&DAT_0042665c);
  }
  FUN_00401d40(param_1,(int *)pcVar1);
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_00405780 @ 00405780 =====

void __fastcall FUN_00405780(double *param_1)

{
  uint uVar1;
  undefined **local_30 [3];
  undefined **local_24 [3];
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 1:
    uVar1 = FUN_004067d0(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestInt out of Int range";
      std::exception::exception((exception *)local_24,&local_c);
      local_24[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_0042665c);
    }
    break;
  case 2:
    uVar1 = FUN_004067d0(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestUInt out of Int range";
      std::exception::exception((exception *)local_30,&local_c);
      local_30[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_30,(ThrowInfo *)&DAT_0042665c);
    }
    break;
  case 3:
    if ((-2147483648.0 <= *param_1) && (*param_1 <= 2147483647.0)) {
      FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
      return;
    }
    local_c = "double out of Int range";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  default:
    local_c = "Value is not convertible to Int.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case 5:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_004058f0 @ 004058f0 =====

void __fastcall FUN_004058f0(double *param_1)

{
  uint uVar1;
  undefined **local_30 [3];
  undefined **local_24 [3];
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 1:
    uVar1 = FUN_00406850(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestInt out of UInt range";
      std::exception::exception((exception *)local_24,&local_c);
      local_24[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_0042665c);
    }
    break;
  case 2:
    uVar1 = FUN_00406850(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestUInt out of UInt range";
      std::exception::exception((exception *)local_30,&local_c);
      local_30[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_30,(ThrowInfo *)&DAT_0042665c);
    }
    break;
  case 3:
    if ((0.0 <= *param_1) && (*param_1 <= 4294967295.0)) {
      FUN_0041d03f();
      FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
      return;
    }
    local_c = "double out of UInt range";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  default:
    local_c = "Value is not convertible to UInt.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case 5:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_00405a60 @ 00405a60 =====

void __fastcall FUN_00405a60(double *param_1)

{
  uint uVar1;
  double in_XMM0_Qa;
  undefined **local_24 [3];
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 2:
    uVar1 = FUN_004068c0(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestUInt out of Int64 range";
      std::exception::exception((exception *)local_24,&local_c);
      local_24[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_0042665c);
    }
  case 1:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 3:
    break;
  default:
    local_c = "Value is not convertible to Int64.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case 5:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  FUN_0041d1fd(0,0x80000000);
  if ((in_XMM0_Qa <= *param_1) && (FUN_0041d1fd(-1,0x7fffffff), *param_1 <= in_XMM0_Qa)) {
    FUN_0041d05d();
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  local_c = "double out of Int64 range";
  std::exception::exception((exception *)local_18,&local_c);
  local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
}



// ===== FUN_00405bb0 @ 00405bb0 =====

void __fastcall FUN_00405bb0(double *param_1)

{
  uint uVar1;
  double dVar2;
  undefined **local_24 [3];
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 1:
    uVar1 = FUN_00406930(param_1);
    if ((char)uVar1 == '\0') {
      local_c = "LargestInt out of UInt64 range";
      std::exception::exception((exception *)local_24,&local_c);
      local_24[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_24,(ThrowInfo *)&DAT_0042665c);
    }
  case 2:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case 3:
    break;
  default:
    local_c = "Value is not convertible to UInt64.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case 5:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  dVar2 = *param_1;
  if ((0.0 <= dVar2) && (FUN_0041d16c(0xffffffff,0xffffffff), *param_1 <= dVar2)) {
    FUN_0041d04e();
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  local_c = "double out of UInt64 range";
  std::exception::exception((exception *)local_18,&local_c);
  local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
}



// ===== FUN_00405cf0 @ 00405cf0 =====

void __fastcall FUN_00405cf0(int *param_1)

{
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch((char)param_1[2]) {
  case '\0':
    goto switchD_00405d09_caseD_0;
  case '\x01':
    FUN_0041d1fd(*param_1,param_1[1]);
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case '\x02':
    FUN_0041d16c(*param_1,param_1[1]);
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  case '\x03':
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  default:
    local_c = "Value is not convertible to double.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case '\x05':
    if ((char)*param_1 != '\0') {
      FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
      return;
    }
switchD_00405d09_caseD_0:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
}



// ===== FUN_00405dc0 @ 00405dc0 =====

void __fastcall FUN_00405dc0(double *param_1)

{
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    break;
  case 1:
  case 2:
    if (*(int *)param_1 != 0 || *(int *)((int)param_1 + 4) != 0) {
      FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
      return;
    }
    break;
  case 3:
    if (*param_1 != 0.0) {
      FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
      return;
    }
    break;
  default:
    local_c = "Value is not convertible to bool.";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  case 5:
    FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
    return;
  }
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_00405e80 @ 00405e80 =====

void __fastcall FUN_00405e80(int *param_1)

{
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  switch((char)param_1[2]) {
  case '\x06':
    if (((int *)*param_1)[1] != 0) {
      local_c = *(int *)*param_1;
      FUN_004099f0(&local_c);
      FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
      return;
    }
    break;
  case '\a':
    FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
    return;
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00405f10 @ 00405f10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405f10(void)

{
  int *piVar1;
  undefined **local_18 [3];
  char *local_c;
  undefined **local_8;
  
  piVar1 = DAT_0042e2e0;
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_18 + 5));
  if (((DAT_0042e2e8 != '\0') && (DAT_0042e2e8 != '\x06')) && (DAT_0042e2e8 != '\a')) {
    local_c = "in Json::Value::clear(): requires complex value";
    std::exception::exception((exception *)local_18,&local_c);
    local_18[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_0042665c);
  }
  _DAT_0042e2f0 = 0;
  _DAT_0042e2f4 = 0;
  if ((int)DAT_0042e2e8 - 6U < 2) {
    FUN_00409760(*(int **)(*DAT_0042e2e0 + 4));
    *(int *)(*piVar1 + 4) = *piVar1;
    *(int *)*piVar1 = *piVar1;
    *(int *)(*piVar1 + 8) = *piVar1;
    piVar1[1] = 0;
  }
  FUN_0041c21c((uint)local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_00405fd0 @ 00405fd0 =====

void __thiscall FUN_00405fd0(void *this,uint param_1)

{
  void *this_00;
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  char *local_54;
  void *local_50;
  uint local_4c;
  undefined4 local_48 [6];
  char *local_30 [2];
  uint local_28;
  undefined **local_24;
  longlong local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  char *local_8;
  
  local_8 = (char *)0xffffffff;
  puStack_c = &LAB_0041d674;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_30 + 0xb);
  ExceptionList = &local_10;
  if (*(char *)((int)this + 8) == '\0') {
    local_24 = (undefined **)0x0;
    local_28 = local_28 & 0xfffffe06 | 6;
    local_20 = 0;
    local_30[0] = operator_new(8);
    local_8 = (char *)0x0;
    local_54 = local_30[0];
    if (local_30[0] == (char *)0x0) {
      local_30[0] = (char *)0x0;
    }
    else {
      local_30[0][0] = '\0';
      local_30[0][1] = '\0';
      local_30[0][2] = '\0';
      local_30[0][3] = '\0';
      local_30[0][4] = '\0';
      local_30[0][5] = '\0';
      local_30[0][6] = '\0';
      local_30[0][7] = '\0';
      local_30[0][0] = '\0';
      local_30[0][1] = '\0';
      local_30[0][2] = '\0';
      local_30[0][3] = '\0';
      local_30[0][4] = '\0';
      local_30[0][5] = '\0';
      local_30[0][6] = '\0';
      local_30[0][7] = '\0';
      uVar2 = FUN_0040a290();
      *(undefined4 *)local_30[0] = uVar2;
    }
    local_8 = (char *)0x1;
    FUN_00405560(this,(char *)local_30);
    local_8 = (char *)0xffffffff;
    FUN_004054d0(local_30);
  }
  else if (*(char *)((int)this + 8) != '\x06') {
    local_54 = "in Json::Value::operator[](ArrayIndex): requires arrayValue";
    std::exception::exception((exception *)&local_24,&local_54);
    local_24 = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_24,(ThrowInfo *)&DAT_0042665c);
  }
  local_20 = (ulonglong)param_1 << 0x20;
  local_8 = (char *)0x2;
  piVar4 = *(int **)this;
  piVar3 = FUN_00409800(piVar4,(undefined4 *)&local_20);
  if ((piVar3 == (int *)*piVar4) || (bVar1 = FUN_00405140(piVar3 + 4,(undefined4 *)&local_20), !bVar1)) {
    local_50 = (void *)0x0;
    local_4c = param_1;
    local_8._0_1_ = 3;
    FUN_004052f0(local_48,&DAT_0042e2a0);
    local_8._0_1_ = 4;
    this_00 = *(void **)this;
    piVar4 = FUN_0040a8a0(this_00,(int *)&local_50);
    FUN_0040a960(this_00,&local_54,piVar3,(byte *)(piVar4 + 4),piVar4);
    local_8 = (char *)CONCAT31(local_8._1_3_,5);
    FUN_004054d0(local_48);
    if ((local_50 != (void *)0x0) && (local_4c == 1)) {
      free(local_50);
    }
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_30 + 0xb));
  return;
}



// ===== FUN_00406180 @ 00406180 =====

void __fastcall FUN_00406180(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041d6a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004054d0(param_1 + 2);
  if (((void *)*param_1 != (void *)0x0) && (param_1[1] == 1)) {
    free((void *)*param_1);
  }
  ExceptionList = local_10;
  return;
}



// ===== FUN_004061e0 @ 004061e0 =====

void __thiscall FUN_004061e0(void *this,uint param_1)

{
  int *piVar1;
  char *local_1c;
  undefined **local_18;
  undefined8 local_14;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  if (*(char *)((int)this + 8) != '\0') {
    if (*(char *)((int)this + 8) != '\x06') {
      local_1c = "in Json::Value::operator[](ArrayIndex)const: requires arrayValue";
      std::exception::exception((exception *)&local_18,&local_1c);
      local_18 = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_18,(ThrowInfo *)&DAT_0042665c);
    }
    local_14 = (ulonglong)param_1 << 0x20;
    piVar1 = FUN_00408720(*(void **)this,(int *)&local_1c,(undefined4 *)&local_14);
    if (*piVar1 != **(int **)this) {
      if (((void *)local_14 != (void *)0x0) && (local_14._4_4_ == 1)) {
        free((void *)local_14);
      }
      FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
      return;
    }
    if (((void *)local_14 != (void *)0x0) && (local_14._4_4_ == 1)) {
      free((void *)local_14);
    }
  }
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_004062c0 @ 004062c0 =====

void __thiscall FUN_004062c0(void *this,char *param_1)

{
  void *this_00;
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined8 *local_64 [2];
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  char *local_48;
  void *local_44;
  int local_40;
  undefined4 local_3c [7];
  undefined **local_20;
  char *local_1c;
  undefined8 *puStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d704;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_3c + 0xe);
  ExceptionList = &local_10;
  local_48 = this;
  if (*(char *)((int)this + 8) == '\0') {
    local_58 = 0;
    local_5c = local_5c & 0xfffffe07 | 7;
    local_54 = 0;
    local_50 = 0;
    local_64[0] = operator_new(8);
    _local_1c = CONCAT44(local_64[0],local_1c);
    local_8 = 0;
    if (local_64[0] == (undefined8 *)0x0) {
      local_64[0] = (undefined8 *)0x0;
    }
    else {
      *local_64[0] = 0;
      *(undefined4 *)local_64[0] = 0;
      *(undefined4 *)((int)local_64[0] + 4) = 0;
      uVar2 = FUN_0040a290();
      *(undefined4 *)local_64[0] = uVar2;
    }
    local_8 = 1;
    FUN_00405560(this,(char *)local_64);
    local_8 = 0xffffffff;
    FUN_004054d0(local_64);
  }
  else if (*(char *)((int)this + 8) != '\a') {
    local_48 = "in Json::Value::resolveReference(): requires objectValue";
    std::exception::exception((exception *)&local_20,&local_48);
    local_20 = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_0042665c);
  }
  _local_1c = CONCAT44(2,param_1);
  local_8 = 2;
  piVar4 = *(int **)this;
  piVar3 = FUN_00409800(piVar4,&local_1c);
  if ((piVar3 == (int *)*piVar4) || (bVar1 = FUN_00405140(piVar3 + 4,&local_1c), !bVar1)) {
    if (param_1 == (char *)0x0) {
      local_44 = (void *)0x0;
    }
    else {
      local_44 = (void *)FUN_00404fd0(param_1,0xffffffff);
    }
    local_40 = 2 - (uint)(param_1 != (char *)0x0);
    local_8._0_1_ = 3;
    FUN_004052f0(local_3c,&DAT_0042e2a0);
    local_8._0_1_ = 4;
    this_00 = *(void **)local_48;
    piVar4 = FUN_0040a8a0(this_00,(int *)&local_44);
    FUN_0040a960(this_00,&local_48,piVar3,(byte *)(piVar4 + 4),piVar4);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004054d0(local_3c);
    if ((local_44 != (void *)0x0) && (local_40 == 1)) {
      free(local_44);
    }
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_3c + 0xe));
  return;
}



// ===== FUN_00406490 @ 00406490 =====

void __thiscall FUN_00406490(void *this,uint param_1)

{
  int *piVar1;
  char *local_1c;
  undefined **local_18;
  undefined8 local_14;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  if (*(char *)((int)this + 8) != '\0') {
    if (*(char *)((int)this + 8) != '\a') {
      local_1c = "in Json::Value::operator[](char const*)const: requires objectValue";
      std::exception::exception((exception *)&local_18,&local_1c);
      local_18 = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_18,(ThrowInfo *)&DAT_0042665c);
    }
    local_14 = (ulonglong)param_1;
    piVar1 = FUN_00408720(*(void **)this,(int *)&local_1c,(undefined4 *)&local_14);
    if (*piVar1 != **(int **)this) {
      if (((void *)local_14 != (void *)0x0) && (local_14._4_4_ == 1)) {
        free((void *)local_14);
      }
      FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
      return;
    }
    if (((void *)local_14 != (void *)0x0) && (local_14._4_4_ == 1)) {
      free((void *)local_14);
    }
  }
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_00406570 @ 00406570 =====

void __thiscall FUN_00406570(void *this,char *param_1)

{
  uint uVar1;
  void *this_00;
  
  uVar1 = FUN_00405e80(this);
  this_00 = (void *)FUN_00405fd0(this,uVar1);
  FUN_00405560(this_00,param_1);
  return;
}



// ===== FUN_004065a0 @ 004065a0 =====

void __thiscall FUN_004065a0(void *this,char *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  void *local_40 [4];
  undefined4 local_30;
  uint local_2c;
  char *local_28;
  undefined8 local_24;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  void *local_8;
  
  local_8 = (void *)0xffffffff;
  puStack_c = &LAB_0041d740;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_40 + 0xf);
  ExceptionList = &local_10;
  local_28 = param_1;
  if (*(char *)((int)this + 8) == '\0') {
    param_1[0] = '\0';
    param_1[1] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
  }
  else {
    if (*(char *)((int)this + 8) != '\a') {
      local_28 = "in Json::Value::getMemberNames(), value must be objectValue";
      std::exception::exception((exception *)&local_24,&local_28);
      local_24 = CONCAT44(local_24._4_4_,std::runtime_error::vftable);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_24,(ThrowInfo *)&DAT_0042665c);
    }
    local_24 = 0;
    local_1c = 0;
    local_8 = (void *)0x0;
    uVar5 = *(uint *)(*(int *)this + 4);
    if (uVar5 != 0) {
      if (0xaaaaaaa < uVar5) {
                    /* WARNING: Subroutine does not return */
        std::_Xlength_error("vector<T> too long");
      }
      FUN_00409d70(&local_24,uVar5);
    }
    piVar2 = (int *)**(int **)this;
    piVar7 = *(int **)**(int **)this;
    if (piVar7 != piVar2) {
      do {
        piVar3 = (int *)piVar7[4];
        local_2c = 0xf;
        local_30 = 0;
        local_40[0] = (void *)((uint)local_40[0] & 0xffffff00);
        if ((char)*piVar3 == '\0') {
          uVar5 = 0;
        }
        else {
          piVar6 = piVar3;
          do {
            iVar4 = *piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
          } while ((char)iVar4 != '\0');
          uVar5 = (int)piVar6 - ((int)piVar3 + 1);
        }
        FUN_00401f80(local_40,piVar3,uVar5);
        local_8._0_1_ = 1;
        FUN_00408970(&local_24,local_40);
        local_8 = (void *)((uint)local_8._1_3_ << 8);
        if (0xf < local_2c) {
          operator_delete(local_40[0]);
        }
        if (*(char *)((int)piVar7 + 0xd) == '\0') {
          piVar3 = (int *)piVar7[2];
          if (*(char *)((int)piVar3 + 0xd) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0xd);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0xd);
              piVar7 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar7[1] + 0xd);
            piVar6 = (int *)piVar7[1];
            piVar3 = piVar7;
            while ((piVar7 = piVar6, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
              cVar1 = *(char *)(piVar7[1] + 0xd);
              piVar6 = (int *)piVar7[1];
              piVar3 = piVar7;
            }
          }
        }
      } while (piVar7 != piVar2);
      param_1 = local_28;
    }
    *(undefined4 *)param_1 = (undefined4)local_24;
    *(undefined4 *)(param_1 + 4) = local_24._4_4_;
    *(undefined4 *)(param_1 + 8) = local_1c;
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_40 + 0xf));
  return;
}



// ===== FUN_00406770 @ 00406770 =====

void FUN_00406770(void)

{
  double in_XMM0_Qa;
  double local_14;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_14 = modf(in_XMM0_Qa,&local_14);
  if (local_14 == 0.0) {
    FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
    return;
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_004067d0 @ 004067d0 =====

uint __fastcall FUN_004067d0(double *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = (int)*(char *)(param_1 + 1);
  if (iVar4 == 1) {
    uVar1 = *(uint *)param_1;
    uVar2 = *(uint *)((int)param_1 + 4);
    if ((int)uVar2 < -1) {
      return 0;
    }
    if ((0x7fffffff < uVar2) && (uVar1 < 0x80000000)) {
      return 0;
    }
    if (0 < (int)uVar2) {
      return 0;
    }
    if ((int)uVar2 < 0) {
      return 1;
    }
  }
  else {
    if (iVar4 != 2) {
      if (iVar4 - 3U != 0) {
        return iVar4 - 3U & 0xffffff00;
      }
      if (*param_1 < -2147483648.0) {
        return 0;
      }
      if (2147483647.0 < *param_1) {
        return 0;
      }
      cVar3 = FUN_00406770();
      if (cVar3 == '\0') {
        return 0;
      }
      return 1;
    }
    if (*(int *)((int)param_1 + 4) != 0) {
      return 0;
    }
    uVar1 = *(uint *)param_1;
  }
  if (uVar1 < 0x80000000) {
    return 1;
  }
  return 0;
}



// ===== FUN_00406850 @ 00406850 =====

uint __fastcall FUN_00406850(double *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)*(char *)(param_1 + 1);
  if (iVar2 == 1) {
    iVar2 = *(int *)((int)param_1 + 4);
    if (iVar2 < 0) {
      return 0;
    }
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 - 3U != 0) {
        return iVar2 - 3U & 0xffffff00;
      }
      if (*param_1 < 0.0) {
        return 0;
      }
      if (4294967295.0 < *param_1) {
        return 0;
      }
      cVar1 = FUN_00406770();
      if (cVar1 == '\0') {
        return 0;
      }
      return 1;
    }
    iVar2 = *(int *)((int)param_1 + 4);
  }
  if (iVar2 == 0) {
    return 1;
  }
  return 0;
}



// ===== FUN_004068c0 @ 004068c0 =====

uint __fastcall FUN_004068c0(double *param_1)

{
  char cVar1;
  int iVar2;
  double in_XMM0_Qa;
  
  iVar2 = (int)*(char *)(param_1 + 1);
  if (iVar2 == 1) {
    return 1;
  }
  if (iVar2 == 2) {
    if (*(uint *)((int)param_1 + 4) < 0x80000000) {
      return 1;
    }
  }
  else {
    if (iVar2 - 3U != 0) {
      return iVar2 - 3U & 0xffffff00;
    }
    FUN_0041d1fd(0,0x80000000);
    if (((in_XMM0_Qa <= *param_1) && (FUN_0041d1fd(-1,0x7fffffff), *param_1 < in_XMM0_Qa)) &&
       (cVar1 = FUN_00406770(), cVar1 != '\0')) {
      return 1;
    }
  }
  return 0;
}



// ===== FUN_00406930 @ 00406930 =====

uint __fastcall FUN_00406930(double *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (int)*(char *)(param_1 + 1);
  if (iVar2 == 1) {
    if (-1 < *(int *)((int)param_1 + 4)) {
      return 1;
    }
  }
  else {
    if (iVar2 == 2) {
      return 1;
    }
    if (iVar2 - 3U != 0) {
      return iVar2 - 3U & 0xffffff00;
    }
    if (((0.0 <= *param_1) && (*param_1 < 1.8446744073709552e+19)) && (cVar1 = FUN_00406770(), cVar1 != '\0')) {
      return 1;
    }
  }
  return 0;
}



// ===== FUN_00406990 @ 00406990 =====

void __thiscall FUN_00406990(void *this,char *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d77c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(char **)param_1;
  }
  if (*(int *)((int)this + 0xc) == 0) {
    puVar1 = (undefined4 *)FUN_0041c1dc(0x10);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = puVar1 + 1;
      *puVar1 = 3;
      FUN_0041c675(puVar2,4,3,&LAB_00405080);
    }
    *(undefined4 **)((int)this + 0xc) = puVar2;
  }
  local_8 = 0xffffffff;
  FUN_004050a0((void *)(*(int *)((int)this + 0xc) + param_2 * 4),param_1);
  ExceptionList = local_10;
  return;
}



// ===== FUN_00406a30 @ 00406a30 =====

undefined1 * __thiscall FUN_00406a30(void *this,undefined1 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)((int)this + 0xc) == 0) ||
     (piVar1 = *(int **)(*(int *)((int)this + 0xc) + param_2 * 4), piVar1 == (int *)0x0)) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
    FUN_00401f80(param_1,(int *)&DAT_0041f7b1,0);
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if ((char)*piVar1 == '\0') {
    FUN_00401f80(param_1,piVar1,0);
    return param_1;
  }
  piVar3 = piVar1;
  do {
    iVar2 = *piVar3;
    piVar3 = (int *)((int)piVar3 + 1);
  } while ((char)iVar2 != '\0');
  FUN_00401f80(param_1,piVar1,(int)piVar3 - ((int)piVar1 + 1));
  return param_1;
}



// ===== FUN_00406ad0 @ 00406ad0 =====

void __thiscall FUN_00406ad0(void *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  longlong lVar6;
  int local_2c;
  undefined1 local_e [2];
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_e + 10);
  local_2c = param_1;
  if ((param_2 < 1) && (param_2 < 0)) {
    local_2c = -param_1;
    bVar1 = true;
    param_2 = -(param_2 + (uint)(param_1 != 0));
  }
  else {
    bVar1 = false;
  }
  lVar6 = CONCAT44(param_2,local_2c);
  local_c._0_1_ = 0;
  piVar5 = &local_c;
  do {
    piVar4 = piVar5;
    piVar5 = (int *)((int)piVar4 + -1);
    lVar6 = __aulldiv((uint)lVar6,(uint)((ulonglong)lVar6 >> 0x20),10,0);
    *(char *)piVar5 = (char)local_2c + (char)lVar6 * -10 + '0';
    local_2c = (int)lVar6;
  } while (lVar6 != 0);
  if (bVar1) {
    piVar5 = (int *)((int)piVar4 + -2);
    *(char *)piVar5 = '-';
  }
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  if ((char)*piVar5 == '\0') {
    uVar3 = 0;
  }
  else {
    piVar4 = piVar5;
    do {
      iVar2 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar2 != '\0');
    uVar3 = (int)piVar4 - ((int)piVar5 + 1);
  }
  FUN_00401f80(this,piVar5,uVar3);
  FUN_0041c21c(local_8 ^ (uint)(local_e + 10));
  return;
}



// ===== FUN_00406bb0 @ 00406bb0 =====

void __thiscall FUN_00406bb0(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  longlong lVar6;
  undefined4 local_28;
  undefined1 local_d;
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  lVar6 = CONCAT44(param_2,param_1);
  local_28 = param_1;
  local_c._0_1_ = 0;
  piVar5 = &local_c;
  do {
    piVar4 = piVar5;
    piVar5 = (int *)((int)piVar4 + -1);
    lVar6 = __aulldiv((uint)lVar6,(uint)((ulonglong)lVar6 >> 0x20),10,0);
    *(char *)piVar5 = (char)local_28 + (char)lVar6 * -10 + '0';
    local_28 = (int)lVar6;
  } while (lVar6 != 0);
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  uVar3 = 0;
  if (*(char *)piVar5 != '\0') {
    piVar2 = piVar5;
    do {
      iVar1 = *piVar2;
      piVar2 = (int *)((int)piVar2 + 1);
    } while ((char)iVar1 != '\0');
    uVar3 = (int)piVar2 - (int)piVar4;
  }
  FUN_00401f80(this,piVar5,uVar3);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00406c50 @ 00406c50 =====

void __fastcall FUN_00406c50(undefined1 *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 local_28;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  sprintf_s((char *)&local_28,0x20,"%.16g");
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if ((char)local_28 == '\0') {
    uVar2 = 0;
  }
  else {
    pcVar3 = (char *)&local_28;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar2 = (int)pcVar3 - ((int)&local_28 + 1);
  }
  FUN_00401f80(param_1,&local_28,uVar2);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00406ce0 @ 00406ce0 =====

undefined1 * __fastcall FUN_00406ce0(undefined1 *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_0041f7ac;
  if (param_2 == '\0') {
    pcVar3 = "false";
  }
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  if ((char)*(int *)pcVar3 == '\0') {
    FUN_00401f80(param_1,(int *)pcVar3,0);
    return param_1;
  }
  piVar2 = (int *)pcVar3;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00401f80(param_1,(int *)pcVar3,(int)piVar2 - ((int)pcVar3 + 1));
  return param_1;
}



// ===== FUN_00406d50 @ 00406d50 =====

void __fastcall FUN_00406d50(int *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined4 ****ppppuVar8;
  basic_ostream<char,std::char_traits<char>_> *this;
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar9;
  undefined4 *puVar10;
  code *pcVar11;
  code *pcVar12;
  void *local_f4 [2];
  undefined1 local_ec [8];
  undefined4 local_e4;
  uint local_e0;
  void *local_dc [4];
  undefined4 local_cc;
  uint local_c8;
  int local_c4;
  basic_streambuf<char,std::char_traits<char>_> local_c0 [4];
  basic_ostream<char,std::char_traits<char>_> local_bc [72];
  basic_ios<char,std::char_traits<char>_> local_74 [72];
  undefined4 ****local_2c [4];
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 ***local_8;
  
  local_8 = (undefined4 ***)0xffffffff;
  puStack_c = &LAB_0041d7d4;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_2c + 10);
  ExceptionList = &local_10;
  if (param_2 == (int *)0x0) {
    param_1[5] = 0xf;
    param_1[4] = 0;
    *(undefined1 *)param_1 = 0;
    FUN_00401f80(param_1,(int *)&DAT_0041f7b1,0);
  }
  else {
    pcVar5 = strpbrk((char *)param_2,"\"\\\b\f\n\r\t");
    if (pcVar5 == (char *)0x0) {
      cVar2 = (char)*param_2;
      piVar7 = param_2;
      while (cVar2 != '\0') {
        iVar3 = *piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        if ((byte)((char)iVar3 - 1U) < 0x1f) goto LAB_00406e79;
        cVar2 = *(char *)piVar7;
      }
      puVar6 = FUN_00401d40(local_dc,(int *)&DAT_0041ff70);
      local_8 = (undefined4 ***)0x0;
      piVar7 = FUN_0040a350((int *)local_f4,puVar6,param_2);
      local_8 = (undefined4 ***)CONCAT31(local_8._1_3_,1);
      FUN_0040a350(param_1,piVar7,(int *)&DAT_0041ff70);
      if (0xf < local_e0) {
        operator_delete(local_f4[0]);
      }
      local_e0 = 0xf;
      local_e4 = 0;
      local_f4[0] = (void *)((uint)local_f4[0] & 0xffffff00);
      if (0xf < local_c8) {
        operator_delete(local_dc[0]);
      }
    }
    else {
LAB_00406e79:
      piVar7 = param_2;
      do {
        iVar3 = *piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
      } while ((char)iVar3 != '\0');
      local_18 = 0xf;
      local_1c = 0;
      local_2c[0] = (undefined4 ****)((uint)local_2c[0] & 0xffffff00);
      uVar1 = ((int)piVar7 - ((int)param_2 + 1)) * 2 + 3;
      local_8 = (undefined4 ***)0x2;
      if ((uVar1 != 0xf) && (bVar4 = FUN_00402190(local_2c,uVar1,'\x01'), bVar4)) {
        local_1c = 0;
        ppppuVar8 = local_2c;
        if (0xf < local_18) {
          ppppuVar8 = local_2c[0];
        }
        *(undefined1 *)ppppuVar8 = 0;
      }
      FUN_00409330(local_2c,(int *)&DAT_0041ff70,1);
      cVar2 = (char)*param_2;
      while (cVar2 != '\0') {
        cVar2 = (char)*param_2;
        switch(cVar2) {
        case '\b':
          FUN_00409330(local_2c,(int *)&DAT_0041ff7c,2);
          break;
        case '\t':
          FUN_00409330(local_2c,(int *)&DAT_0041ff8c,2);
          break;
        case '\n':
          FUN_00409330(local_2c,(int *)&DAT_0041ff84,2);
          break;
        default:
          if ((byte)(cVar2 - 1U) < 0x1f) {
            memset(&local_c4,0,0x98);
            FUN_00408ab0((basic_ostream<char,std::char_traits<char>_> *)&local_c4);
            pcVar12 = FUN_00402510;
            pcVar11 = FUN_004024f0;
            local_8._0_1_ = 3;
            this = FUN_0040a3f0((basic_ostream<char,std::char_traits<char>_> *)&local_c4);
            pbVar9 = std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,pcVar11);
            pbVar9 = std::basic_ostream<char,std::char_traits<char>_>::operator<<
                               ((basic_ostream<char,std::char_traits<char>_> *)pbVar9,pcVar12);
            pbVar9[*(int *)(*(int *)pbVar9 + 4) + 0x40] = (basic_ostream<char,struct_std::char_traits<char>_>)0x30;
            puVar10 = (undefined4 *)std::setw(CONCAT44(4,local_ec));
            (*(code *)*puVar10)(pbVar9 + *(int *)(*(int *)pbVar9 + 4),puVar10[2],puVar10[3]);
            std::basic_ostream<char,std::char_traits<char>_>::operator<<
                      ((basic_ostream<char,std::char_traits<char>_> *)pbVar9,(int)(char)*param_2);
            puVar10 = FUN_00408b60(&local_c4,local_dc);
            local_8 = (undefined4 ***)CONCAT31(local_8._1_3_,4);
            FUN_00409270(local_2c,puVar10,0,0xffffffff);
            if (0xf < local_c8) {
              operator_delete(local_dc[0]);
            }
            local_8 = (undefined4 ***)CONCAT31(local_8._1_3_,2);
            local_c8 = 0xf;
            local_cc = 0;
            local_dc[0] = (void *)((uint)local_dc[0] & 0xffffff00);
            *(undefined ***)(local_c0 + *(int *)(local_c4 + 4) + -4) =
                 std::basic_ostringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
            *(int *)((int)local_dc + *(int *)(local_c4 + 4) + 0x14) = *(int *)(local_c4 + 4) + -0x50;
            FUN_00408b80(local_c0);
            std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>(local_bc);
            std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_74);
          }
          else {
            FUN_00409420(local_2c,1,cVar2);
          }
          break;
        case '\f':
          FUN_00409330(local_2c,(int *)&DAT_0041ff80,2);
          break;
        case '\r':
          FUN_00409330(local_2c,(int *)&DAT_0041ff88,2);
          break;
        case '\"':
          FUN_00409330(local_2c,(int *)&DAT_0041ff74,2);
          break;
        case '\\':
          FUN_00409330(local_2c,(int *)&DAT_0041ff78,2);
        }
        param_2 = (int *)((int)param_2 + 1);
        cVar2 = *(char *)param_2;
      }
      FUN_00409330(local_2c,(int *)&DAT_0041ff70,1);
      param_1[5] = 0xf;
      param_1[4] = 0;
      *(undefined1 *)param_1 = 0;
      if (local_18 < 0x10) {
        if (local_1c + 1U != 0) {
          memmove(param_1,local_2c,local_1c + 1U);
        }
      }
      else {
        *param_1 = (int)local_2c[0];
      }
      param_1[4] = local_1c;
      param_1[5] = local_18;
    }
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_2c + 10));
  return;
}



// ===== FUN_004071d0 @ 004071d0 =====

void __fastcall FUN_004071d0(int *param_1)

{
  basic_ios<char,std::char_traits<char>_> *this;
  
  this = (basic_ios<char,std::char_traits<char>_> *)(param_1 + 0x14);
  *(undefined ***)(this + *(int *)(*param_1 + 4) + -0x50) =
       std::basic_ostringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(this + *(int *)(*param_1 + 4) + -0x54) = *(int *)(*param_1 + 4) + -0x50;
  FUN_00408b80((basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 1));
  std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>
            ((basic_ostream<char,std::char_traits<char>_> *)(param_1 + 2));
                    /* WARNING: Could not recover jumptable at 0x00407202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(this);
  return;
}



// ===== FUN_00407210 @ 00407210 =====

undefined4 * __thiscall FUN_00407210(void *this,byte param_1)

{
  *(undefined ***)this = Json::Writer::vftable;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===== FUN_00407240 @ 00407240 =====

undefined4 * __fastcall FUN_00407240(undefined4 *param_1)

{
  *param_1 = Json::StyledWriter::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[0xf] = 0xf;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[0x10] = 0x4a;
  param_1[0x11] = 3;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return param_1;
}



// ===== FUN_004072a0 @ 004072a0 =====

undefined1 * __thiscall FUN_004072a0(void *this,undefined1 *param_1,double *param_2)

{
  int *this_00;
  
  this_00 = (int *)((int)this + 0x10);
  FUN_00401f80(this_00,(int *)&DAT_0041f7b1,0);
  *(undefined1 *)((int)this + 0x48) = 0;
  FUN_00401f80((void *)((int)this + 0x28),(int *)&DAT_0041f7b1,0);
  FUN_00407d90(this,param_2);
  FUN_00407330(this,param_2);
  FUN_00407fa0(this,param_2);
  FUN_00409330(this_00,(int *)&DAT_0041f840,1);
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00401e50(param_1,this_00,0,0xffffffff);
  return param_1;
}



// ===== FUN_00407330 @ 00407330 =====

void __thiscall FUN_00407330(void *this,double *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  double *pdVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  double *local_11c;
  void *local_118 [4];
  undefined4 local_108;
  uint local_104;
  int local_100 [6];
  undefined4 local_e8 [6];
  int local_d0 [6];
  int local_b8 [6];
  undefined4 local_a0 [6];
  undefined4 local_88 [6];
  undefined4 local_70 [6];
  undefined4 local_58 [6];
  int local_40 [6];
  undefined8 local_28;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0041d86a;
  local_14 = ExceptionList;
  local_1c = DAT_00428000 ^ (uint)&local_11c;
  ExceptionList = &local_14;
  local_11c = param_1;
  switch(*(char *)(param_1 + 1)) {
  case '\0':
    FUN_00401d40(local_100,(int *)&DAT_0041ff94);
    local_c = 0;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),local_100,0,0xffffffff);
      FUN_00401da0(local_100);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),local_100);
      FUN_00401da0(local_100);
    }
    break;
  case '\x01':
    uVar6 = FUN_00405a60(param_1);
    piVar2 = (int *)FUN_00406ad0(local_a0,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    local_c = 1;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),piVar2,0,0xffffffff);
      FUN_00401da0(local_a0);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),piVar2);
      FUN_00401da0(local_a0);
    }
    break;
  case '\x02':
    uVar6 = FUN_00405bb0(param_1);
    piVar2 = (int *)FUN_00406bb0(local_70,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    local_c = 2;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),piVar2,0,0xffffffff);
      FUN_00401da0(local_70);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),piVar2);
      FUN_00401da0(local_70);
    }
    break;
  case '\x03':
    FUN_00405cf0((int *)param_1);
    piVar2 = (int *)FUN_00406c50((undefined1 *)local_88);
    local_c = 3;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),piVar2,0,0xffffffff);
      FUN_00401da0(local_88);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),piVar2);
      FUN_00401da0(local_88);
    }
    break;
  case '\x04':
    if (*(char *)(param_1 + 1) == '\x04') {
      piVar2 = *(int **)param_1;
    }
    else {
      piVar2 = (int *)FUN_00405620();
    }
    piVar2 = (int *)FUN_00406d50(local_40,piVar2);
    local_c = 4;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),piVar2,0,0xffffffff);
      FUN_00401da0(local_40);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),piVar2);
      FUN_00401da0(local_40);
    }
    break;
  case '\x05':
    cVar1 = FUN_00405dc0(param_1);
    piVar2 = (int *)FUN_00406ce0((undefined1 *)local_58,cVar1);
    local_c = 5;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),piVar2,0,0xffffffff);
      FUN_00401da0(local_58);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),piVar2);
      FUN_00401da0(local_58);
    }
    break;
  case '\x06':
    FUN_004077d0(this,(int *)param_1);
    break;
  case '\a':
    local_20 = 0;
    local_28 = 0;
    FUN_004065a0(param_1,(char *)&local_28);
    local_c = 6;
    piVar2 = (int *)local_28;
    if ((int *)local_28 == local_28._4_4_) {
      FUN_00401d40(local_d0,(int *)&DAT_0041ffb0);
      local_c = CONCAT31(local_c._1_3_,7);
      FUN_00407c50(this,local_d0);
      piVar2 = local_d0;
    }
    else {
      FUN_00401d40(local_e8,(int *)&DAT_0041ffa8);
      local_c._0_1_ = 8;
      FUN_00407c80(this,local_e8);
      local_c._0_1_ = 6;
      FUN_00401da0(local_e8);
      FUN_00407ce0((int)this);
      while( true ) {
        if ((uint)piVar2[5] < 0x10) {
          piVar3 = piVar2;
        }
        else {
          piVar3 = (int *)*piVar2;
        }
        pdVar4 = (double *)FUN_00406490(param_1,(uint)piVar3);
        FUN_00407d90(this,pdVar4);
        if ((uint)piVar2[5] < 0x10) {
          piVar3 = piVar2;
        }
        else {
          piVar3 = (int *)*piVar2;
        }
        puVar5 = (undefined4 *)FUN_00406d50((int *)local_118,piVar3);
        local_c._0_1_ = 9;
        FUN_00407c80(this,puVar5);
        local_c._0_1_ = 6;
        if (0xf < local_104) {
          operator_delete(local_118[0]);
        }
        local_104 = 0xf;
        local_108 = 0;
        local_118[0] = (void *)((uint)local_118[0] & 0xffffff00);
        FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffb4,3);
        FUN_00407330(this,pdVar4);
        piVar2 = piVar2 + 6;
        if (piVar2 == local_28._4_4_) break;
        FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffa0,1);
        FUN_00407fa0(this,pdVar4);
        param_1 = local_11c;
      }
      FUN_00407fa0(this,pdVar4);
      FUN_00407d60((int)this);
      FUN_00401d40(local_b8,(int *)&DAT_0041ffac);
      local_c = CONCAT31(local_c._1_3_,10);
      FUN_00407c80(this,local_b8);
      piVar2 = local_b8;
    }
    FUN_00401da0(piVar2);
    FUN_00401e10((undefined4 *)&local_28);
  }
  ExceptionList = local_14;
  FUN_0041c21c(local_1c ^ (uint)&local_11c);
  return;
}



// ===== FUN_004077d0 @ 004077d0 =====

void __thiscall FUN_004077d0(void *this,int *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  void *local_58 [4];
  undefined4 local_48;
  uint local_44;
  void *local_40 [4];
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  double *local_20;
  int local_1c;
  char local_15;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d8b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = FUN_00405e80(param_1);
  local_28 = uVar3;
  if (uVar3 == 0) {
    local_2c = 0xf;
    local_40[0] = (void *)((uint)local_40[0] & 0xffffff00);
    local_30 = uVar3;
    FUN_00401f80(local_40,(int *)&DAT_0041ffb8,2);
    local_8 = uVar3;
    if (*(char *)((int)this + 0x48) == '\0') {
      FUN_00409270((void *)((int)this + 0x10),local_40,0,0xffffffff);
    }
    else {
      FUN_004089f0((void *)((int)this + 4),(int *)local_40);
    }
    if (0xf < local_2c) {
      operator_delete(local_40[0]);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    cVar2 = FUN_00407ae0(this,param_1);
    if (cVar2 != '\0') {
      local_2c = 0xf;
      local_30 = 0;
      local_40[0] = (void *)((uint)local_40[0] & 0xffffff00);
      FUN_00401f80(local_40,(int *)&DAT_0041ff9c,1);
      local_8 = 1;
      FUN_00407c80(this,local_40);
      local_8 = 0xffffffff;
      if (0xf < local_2c) {
        operator_delete(local_40[0]);
      }
      FUN_00407ce0((int)this);
      local_15 = *(int *)((int)this + 4) != *(int *)((int)this + 8);
      uVar3 = 0;
      local_24 = 0;
      local_1c = 0;
      do {
        iVar6 = local_1c;
        local_20 = (double *)FUN_004061e0(param_1,uVar3);
        FUN_00407d90(this,local_20);
        if (local_15 == '\0') {
          if (*(int *)((int)this + 0x20) == 0) {
LAB_0040798c:
            FUN_00409270((void *)((int)this + 0x10),(undefined4 *)((int)this + 0x28),0,0xffffffff);
          }
          else {
            puVar5 = (undefined4 *)((int)this + 0x10);
            if (*(uint *)((int)this + 0x24) < 0x10) {
              puVar4 = puVar5;
            }
            else {
              puVar4 = (void *)*puVar5;
            }
            cVar2 = *(char *)((int)puVar4 + *(int *)((int)this + 0x20) + -1);
            if (cVar2 != ' ') {
              if (cVar2 != '\n') {
                FUN_00409420(puVar5,1,'\n');
              }
              goto LAB_0040798c;
            }
          }
          FUN_00407330(this,local_20);
        }
        else {
          iVar1 = *(int *)((int)this + 4);
          if (*(int *)((int)this + 0x20) == 0) {
LAB_0040793c:
            FUN_00409270((void *)((int)this + 0x10),(undefined4 *)((int)this + 0x28),0,0xffffffff);
          }
          else {
            puVar5 = (undefined4 *)((int)this + 0x10);
            if (*(uint *)((int)this + 0x24) < 0x10) {
              puVar4 = puVar5;
            }
            else {
              puVar4 = (void *)*puVar5;
            }
            cVar2 = *(char *)((int)puVar4 + *(int *)((int)this + 0x20) + -1);
            if (cVar2 != ' ') {
              if (cVar2 != '\n') {
                FUN_00409420(puVar5,1,'\n');
              }
              goto LAB_0040793c;
            }
          }
          FUN_00409270((void *)((int)this + 0x10),(undefined4 *)(iVar1 + iVar6),0,0xffffffff);
          uVar3 = local_24;
        }
        local_1c = local_1c + 0x18;
        uVar3 = uVar3 + 1;
        local_24 = uVar3;
        if (uVar3 == local_28) {
          FUN_00407fa0(this,local_20);
          puVar5 = (undefined4 *)((int)this + 0x28);
          uVar3 = *(int *)((int)this + 0x38) - *(int *)((int)this + 0x44);
          if (*(uint *)((int)this + 0x38) < uVar3) {
            FUN_00409420(puVar5,uVar3 - *(uint *)((int)this + 0x38),'\0');
          }
          else {
            *(uint *)((int)this + 0x38) = uVar3;
            if (0xf < *(uint *)((int)this + 0x3c)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            *(undefined1 *)((int)puVar5 + uVar3) = 0;
          }
          local_44 = 0xf;
          local_48 = 0;
          local_58[0] = (void *)((uint)local_58[0] & 0xffffff00);
          FUN_00401f80(local_58,(int *)&DAT_0041ffa4,1);
          local_8 = 2;
          FUN_00407c80(this,local_58);
          if (local_44 < 0x10) {
            ExceptionList = local_10;
            return;
          }
          operator_delete(local_58[0]);
          ExceptionList = local_10;
          return;
        }
        FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffa0,1);
        FUN_00407fa0(this,local_20);
      } while( true );
    }
    FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffbc,2);
    uVar7 = 0;
    if (uVar3 != 0) {
      iVar6 = 0;
      do {
        if (uVar7 != 0) {
          FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffc0,2);
        }
        FUN_00409270((void *)((int)this + 0x10),(undefined4 *)(*(int *)((int)this + 4) + iVar6),0,0xffffffff);
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 0x18;
      } while (uVar7 < local_28);
    }
    FUN_00409330((void *)((int)this + 0x10),(int *)&DAT_0041ffc4,2);
  }
  ExceptionList = local_10;
  return;
}



// ===== FUN_00407ae0 @ 00407ae0 =====

void __thiscall FUN_00407ae0(void *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  double *pdVar5;
  char **ppcVar6;
  uint uVar7;
  undefined **local_28 [3];
  int *local_1c;
  int *local_18;
  void *local_14;
  char *local_10;
  char *local_c;
  undefined **local_8;
  
  local_8 = (undefined **)(DAT_00428000 ^ (uint)(local_28 + 9));
  local_1c = param_1;
  local_14 = this;
  uVar2 = FUN_00405e80(param_1);
  bVar1 = *(int *)((int)this + 0x40) <= (int)(uVar2 * 3);
  local_18 = (int *)((int)this + 4);
  FUN_00402250(*(undefined4 **)((int)this + 4),*(undefined4 **)((int)this + 8));
  *(int *)((int)this + 8) = *(int *)((int)this + 4);
  uVar7 = 0;
  if (0 < (int)uVar2) {
    do {
      if (bVar1) goto LAB_00407bff;
      if ((int)uVar7 < 0) {
        local_c = "in Json::Value::operator[](int index) const: index cannot be negative";
        ppcVar6 = &local_c;
        goto LAB_00407c2a;
      }
      piVar3 = (int *)FUN_004061e0(local_1c,uVar7);
      if ((((char)piVar3[2] == '\x06') || ((char)piVar3[2] == '\a')) && (iVar4 = FUN_00405e80(piVar3), iVar4 != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)uVar2);
  }
  if (!bVar1) {
    if ((uint)((local_18[2] - *local_18) / 0x18) < uVar2) {
      if (0xaaaaaaa < uVar2) {
                    /* WARNING: Subroutine does not return */
        std::_Xlength_error("vector<T> too long");
      }
      FUN_00409d70(local_18,uVar2);
    }
    local_c = (char *)(uVar2 * 2 + 2);
    uVar7 = 0;
    *(undefined1 *)((int)local_14 + 0x48) = 1;
    if (0 < (int)uVar2) {
      iVar4 = 0;
      do {
        if ((int)uVar7 < 0) {
          local_10 = "in Json::Value::operator[](int index) const: index cannot be negative";
          ppcVar6 = &local_10;
LAB_00407c2a:
          std::exception::exception((exception *)local_28,ppcVar6);
          local_28[0] = std::runtime_error::vftable;
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_28,(ThrowInfo *)&DAT_0042665c);
        }
        pdVar5 = (double *)FUN_004061e0(local_1c,uVar7);
        FUN_00407330(local_14,pdVar5);
        uVar7 = uVar7 + 1;
        local_c = local_c + *(int *)(iVar4 + 0x10 + *local_18);
        iVar4 = iVar4 + 0x18;
      } while ((int)uVar7 < (int)uVar2);
    }
    *(undefined1 *)((int)local_14 + 0x48) = 0;
  }
LAB_00407bff:
  FUN_0041c21c((uint)local_8 ^ (uint)(local_28 + 9));
  return;
}



// ===== FUN_00407c50 @ 00407c50 =====

void __thiscall FUN_00407c50(void *this,int *param_1)

{
  if (*(char *)((int)this + 0x48) == '\0') {
    FUN_00409270((void *)((int)this + 0x10),param_1,0,0xffffffff);
    return;
  }
  FUN_004089f0((void *)((int)this + 4),param_1);
  return;
}



// ===== FUN_00407c80 @ 00407c80 =====

void __thiscall FUN_00407c80(void *this,undefined4 *param_1)

{
  undefined4 *this_00;
  char cVar1;
  undefined4 *puVar2;
  
  if (*(int *)((int)this + 0x20) != 0) {
    this_00 = (undefined4 *)((int)this + 0x10);
    if (*(uint *)((int)this + 0x24) < 0x10) {
      puVar2 = this_00;
    }
    else {
      puVar2 = (void *)*this_00;
    }
    cVar1 = *(char *)((int)puVar2 + *(int *)((int)this + 0x20) + -1);
    if (cVar1 == ' ') goto LAB_00407cc6;
    if (cVar1 != '\n') {
      FUN_00409420(this_00,1,'\n');
    }
  }
  FUN_00409270((void *)((int)this + 0x10),(undefined4 *)((int)this + 0x28),0,0xffffffff);
LAB_00407cc6:
  FUN_00409270((void *)((int)this + 0x10),param_1,0,0xffffffff);
  return;
}



// ===== FUN_00407ce0 @ 00407ce0 =====

void __fastcall FUN_00407ce0(int param_1)

{
  void *local_28 [4];
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d8e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0xf;
  local_18 = 0;
  local_28[0] = (void *)((uint)local_28[0] & 0xffffff00);
  FUN_004094d0(local_28,*(uint *)(param_1 + 0x44));
  local_8 = 0;
  FUN_00409270((void *)(param_1 + 0x28),local_28,0,0xffffffff);
  if (0xf < local_14) {
    operator_delete(local_28[0]);
  }
  ExceptionList = local_10;
  return;
}



// ===== FUN_00407d60 @ 00407d60 =====

void __fastcall FUN_00407d60(int param_1)

{
  uint uVar1;
  undefined4 *this;
  
  uVar1 = *(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x44);
  this = (undefined4 *)(param_1 + 0x28);
  if (*(uint *)(param_1 + 0x38) < uVar1) {
    FUN_00409420(this,uVar1 - *(uint *)(param_1 + 0x38),'\0');
    return;
  }
  *(uint *)(param_1 + 0x38) = uVar1;
  if (0xf < *(uint *)(param_1 + 0x3c)) {
    this = (undefined4 *)*this;
  }
  *(undefined1 *)((int)this + uVar1) = 0;
  return;
}



// ===== FUN_00407d90 @ 00407d90 =====

void __thiscall FUN_00407d90(void *this,void *param_1)

{
  undefined4 *this_00;
  uint uVar1;
  char cVar2;
  size_t sVar3;
  void *pvVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char ****ppppcVar7;
  char ****ppppcVar8;
  void *local_50 [4];
  undefined4 local_40;
  uint local_3c;
  void *local_38;
  char local_31;
  char ****local_30 [4];
  int local_20;
  uint local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  char ***local_8;
  
  local_8 = (char ***)0xffffffff;
  puStack_c = &LAB_0041d920;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_30 + 0xb);
  ExceptionList = &local_10;
  local_38 = this;
  if ((*(int **)((int)param_1 + 0xc) == (int *)0x0) || (**(int **)((int)param_1 + 0xc) == 0)) goto LAB_00407f79;
  this_00 = (undefined4 *)((int)this + 0x10);
  FUN_00409330(this_00,(int *)&DAT_0041f840,1);
  if (*(int *)((int)this + 0x20) == 0) {
LAB_00407e12:
    FUN_00409270(this_00,(undefined4 *)((int)this + 0x28),0,0xffffffff);
  }
  else {
    if (*(uint *)((int)this + 0x24) < 0x10) {
      puVar6 = this_00;
    }
    else {
      puVar6 = (undefined4 *)*this_00;
    }
    cVar2 = *(char *)((int)puVar6 + *(int *)((int)this + 0x20) + -1);
    if (cVar2 != ' ') {
      if (cVar2 != '\n') {
        FUN_00409420(this_00,1,'\n');
      }
      goto LAB_00407e12;
    }
  }
  pcVar5 = FUN_00406a30(param_1,(undefined1 *)local_50,0);
  local_8 = (char ***)0x0;
  FUN_00408150(local_30,pcVar5);
  local_8 = (char ***)CONCAT31(local_8._1_3_,2);
  if (0xf < local_3c) {
    operator_delete(local_50[0]);
  }
  local_3c = 0xf;
  ppppcVar8 = (char ****)local_30;
  if (0xf < local_1c) {
    ppppcVar8 = local_30[0];
  }
  local_40 = 0;
  local_50[0] = (void *)((uint)local_50[0] & 0xffffff00);
  while( true ) {
    ppppcVar7 = (char ****)local_30;
    if (0xf < local_1c) {
      ppppcVar7 = local_30[0];
    }
    if (ppppcVar8 == (char ****)((int)ppppcVar7 + local_20)) break;
    sVar3 = *(size_t *)((int)this + 0x20);
    local_31 = *(char *)ppppcVar8;
    if ((-sVar3 - 1 < 2) || (uVar1 = sVar3 + 1, uVar1 == 0xffffffff)) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x24) < uVar1) {
      FUN_004022a0(this_00,uVar1,sVar3);
      if (uVar1 != 0) {
LAB_00407ec3:
        if (*(uint *)((int)this + 0x24) < 0x10) {
          puVar6 = this_00;
        }
        else {
          puVar6 = (undefined4 *)*this_00;
        }
        *(char *)((int)puVar6 + *(int *)((int)this + 0x20)) = local_31;
        *(uint *)((int)this + 0x20) = uVar1;
        if (*(uint *)((int)this + 0x24) < 0x10) {
          puVar6 = this_00;
        }
        else {
          puVar6 = (undefined4 *)*this_00;
        }
        *(undefined1 *)((int)puVar6 + uVar1) = 0;
      }
    }
    else {
      if (uVar1 != 0) goto LAB_00407ec3;
      *(undefined4 *)((int)this + 0x20) = 0;
      if (*(uint *)((int)this + 0x24) < 0x10) {
        *(undefined1 *)this_00 = 0;
      }
      else {
        *(undefined1 *)*this_00 = 0;
      }
    }
    pvVar4 = local_38;
    if ((*(char *)ppppcVar8 == '\n') && (*(char *)((int)ppppcVar8 + 1) == '/')) {
      if (*(int *)((int)local_38 + 0x20) != 0) {
        if (*(uint *)((int)this + 0x24) < 0x10) {
          puVar6 = this_00;
        }
        else {
          puVar6 = (undefined4 *)*this_00;
        }
        cVar2 = *(char *)((int)puVar6 + *(int *)((int)local_38 + 0x20) + -1);
        if (cVar2 == ' ') goto LAB_00407f48;
        if (cVar2 != '\n') {
          FUN_00409420(this_00,1,'\n');
        }
      }
      FUN_00409270(this_00,(undefined4 *)((int)pvVar4 + 0x28),0,0xffffffff);
    }
LAB_00407f48:
    ppppcVar8 = (char ****)((int)ppppcVar8 + 1);
  }
  FUN_00409330(this_00,(int *)&DAT_0041f840,1);
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
LAB_00407f79:
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_30 + 0xb));
  return;
}



// ===== FUN_00407fa0 @ 00407fa0 =====

void __thiscall FUN_00407fa0(void *this,void *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *this_00;
  void *local_8c [5];
  uint local_78;
  void *local_74 [4];
  undefined4 local_64;
  uint local_60;
  void *local_5c [4];
  undefined4 local_4c;
  uint local_48;
  void *local_44 [4];
  undefined4 local_34;
  uint local_30;
  void *local_2c [4];
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d97b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)((int)param_1 + 0xc) != 0) && (*(int *)(*(int *)((int)param_1 + 0xc) + 4) != 0)) {
    pcVar1 = FUN_00406a30(param_1,(undefined1 *)local_8c,1);
    local_8 = 0;
    puVar2 = FUN_00408150(local_44,pcVar1);
    local_8._0_1_ = 1;
    piVar3 = FUN_0040a2c0((int *)local_2c,(int *)&DAT_0041ffc8,puVar2);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00409270((void *)((int)this + 0x10),piVar3,0,0xffffffff);
    if (0xf < local_18) {
      operator_delete(local_2c[0]);
    }
    local_18 = 0xf;
    local_1c = 0;
    local_2c[0] = (void *)((uint)local_2c[0] & 0xffffff00);
    if (0xf < local_30) {
      operator_delete(local_44[0]);
    }
    local_8 = 0xffffffff;
    local_30 = 0xf;
    local_34 = 0;
    local_44[0] = (void *)((uint)local_44[0] & 0xffffff00);
    if (0xf < local_78) {
      operator_delete(local_8c[0]);
    }
  }
  if ((*(int *)((int)param_1 + 0xc) != 0) && (*(int *)(*(int *)((int)param_1 + 0xc) + 8) != 0)) {
    this_00 = (void *)((int)this + 0x10);
    FUN_00409330(this_00,(int *)&DAT_0041f840,1);
    pcVar1 = FUN_00406a30(param_1,(undefined1 *)local_74,2);
    local_8 = 3;
    puVar2 = FUN_00408150(local_5c,pcVar1);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00409270(this_00,puVar2,0,0xffffffff);
    if (0xf < local_48) {
      operator_delete(local_5c[0]);
    }
    local_8 = 0xffffffff;
    local_48 = 0xf;
    local_4c = 0;
    local_5c[0] = (void *)((uint)local_5c[0] & 0xffffff00);
    if (0xf < local_60) {
      operator_delete(local_74[0]);
    }
    local_60 = 0xf;
    local_64 = 0;
    local_74[0] = (void *)((uint)local_74[0] & 0xffffff00);
    FUN_00409330(this_00,(int *)&DAT_0041f840,1);
  }
  ExceptionList = local_10;
  return;
}



// ===== FUN_00408150 @ 00408150 =====

undefined4 * __fastcall FUN_00408150(undefined4 *param_1,char *param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  size_t sVar4;
  char *pcVar5;
  bool bVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  uint uVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041d9b9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  local_8 = 0;
  puVar1 = (uint *)(param_2 + 0x10);
  uVar3 = *puVar1;
  uVar10 = param_1[4];
  if (((uVar10 <= uVar3) && (param_1[5] != uVar3)) && (bVar6 = FUN_00402190(param_1,uVar3,'\x01'), bVar6)) {
    param_1[4] = uVar10;
    if ((uint)param_1[5] < 0x10) {
      puVar8 = param_1;
    }
    else {
      puVar8 = (undefined4 *)*param_1;
    }
    *(undefined1 *)((int)puVar8 + uVar10) = 0;
  }
  if (0xf < *(uint *)(param_2 + 0x14)) {
    param_2 = *(char **)param_2;
  }
  uVar3 = *puVar1;
  pcVar5 = param_2;
joined_r0x004081ee:
  if (pcVar5 == param_2 + uVar3) {
    ExceptionList = local_10;
    return param_1;
  }
  cVar2 = *pcVar5;
  pcVar9 = pcVar5 + 1;
  if (cVar2 != '\r') {
    sVar4 = param_1[4];
    if ((-sVar4 - 1 < 2) || (uVar10 = sVar4 + 1, uVar10 == 0xffffffff)) goto LAB_004082ec;
    uVar7 = param_1[5];
    if (uVar7 < uVar10) goto code_r0x0040827c;
    if (uVar10 == 0) goto LAB_0040829d;
    goto LAB_0040828c;
  }
  if (*pcVar9 == '\n') {
    pcVar9 = pcVar5 + 2;
  }
  sVar4 = param_1[4];
  if ((-sVar4 - 1 < 2) || (uVar10 = sVar4 + 1, uVar10 == 0xffffffff)) {
LAB_004082ec:
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  uVar7 = param_1[5];
  if (uVar7 < uVar10) {
    FUN_004022a0(param_1,uVar10,sVar4);
    pcVar5 = pcVar9;
    if (uVar10 == 0) goto joined_r0x004081ee;
  }
  else if (uVar10 == 0) {
LAB_0040829d:
    param_1[4] = 0;
    pcVar5 = pcVar9;
    if (uVar7 < 0x10) {
      *(undefined1 *)param_1 = 0;
    }
    else {
      *(undefined1 *)*param_1 = 0;
    }
    goto joined_r0x004081ee;
  }
  if ((uint)param_1[5] < 0x10) {
    puVar8 = param_1;
  }
  else {
    puVar8 = (undefined4 *)*param_1;
  }
  *(undefined1 *)((int)puVar8 + param_1[4]) = 10;
  param_1[4] = uVar10;
  if ((uint)param_1[5] < 0x10) goto LAB_004082c9;
  puVar8 = (undefined4 *)*param_1;
  goto LAB_004082cb;
code_r0x0040827c:
  FUN_004022a0(param_1,uVar10,sVar4);
  pcVar5 = pcVar9;
  if (uVar10 != 0) {
LAB_0040828c:
    if ((uint)param_1[5] < 0x10) {
      puVar8 = param_1;
    }
    else {
      puVar8 = (undefined4 *)*param_1;
    }
    *(char *)((int)puVar8 + param_1[4]) = cVar2;
    param_1[4] = uVar10;
    if ((uint)param_1[5] < 0x10) {
LAB_004082c9:
      puVar8 = param_1;
    }
    else {
      puVar8 = (undefined4 *)*param_1;
    }
LAB_004082cb:
    *(undefined1 *)((int)puVar8 + uVar10) = 0;
    pcVar5 = pcVar9;
  }
  goto joined_r0x004081ee;
}



// ===== FUN_00408300 @ 00408300 =====

undefined4 * __thiscall FUN_00408300(void *this,undefined4 *param_1)

{
  *(undefined4 *)((int)this + 0x14) = 0xf;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)this = 0;
  if ((uint)param_1[5] < 0x10) {
    if (param_1[4] + 1 != 0) {
      memmove(this,param_1,param_1[4] + 1);
    }
  }
  else {
    *(undefined4 *)this = *param_1;
    *param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = param_1[4];
  *(undefined4 *)((int)this + 0x14) = param_1[5];
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return this;
}



// ===== FUN_00408370 @ 00408370 =====

undefined4 * __thiscall FUN_00408370(void *this,undefined4 *param_1)

{
  if (this != param_1) {
    if (0xf < *(uint *)((int)this + 0x14)) {
      operator_delete(*(void **)this);
    }
    *(undefined4 *)((int)this + 0x14) = 0xf;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined1 *)this = 0;
    FUN_00409210(this,param_1);
  }
  return this;
}



// ===== FUN_004083b0 @ 004083b0 =====

int * __thiscall FUN_004083b0(void *this,int *param_1)

{
  if (this != param_1) {
    FUN_00401e50(this,param_1,0,0xffffffff);
  }
  return this;
}



// ===== FUN_004083d0 @ 004083d0 =====

void __thiscall FUN_004083d0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((char)*param_1 == '\0') {
    FUN_00409330(this,param_1,0);
    return;
  }
  piVar2 = param_1;
  do {
    iVar1 = *piVar2;
    piVar2 = (int *)((int)piVar2 + 1);
  } while ((char)iVar1 != '\0');
  FUN_00409330(this,param_1,(int)piVar2 - ((int)param_1 + 1));
  return;
}



// ===== FUN_00408410 @ 00408410 =====

void __thiscall FUN_00408410(void *this,uint param_1)

{
  if (*(uint *)((int)this + 0x10) < param_1) {
    FUN_00409420(this,param_1 - *(uint *)((int)this + 0x10),'\0');
    return;
  }
  *(uint *)((int)this + 0x10) = param_1;
  if (0xf < *(uint *)((int)this + 0x14)) {
    this = *(void **)this;
  }
  *(undefined1 *)((int)this + param_1) = 0;
  return;
}



// ===== FUN_00408440 @ 00408440 =====

undefined4 * __thiscall FUN_00408440(void *this,undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar4 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041d9e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004099a0((int *)&param_2);
  piVar6 = (int *)*piVar4;
  if (*(char *)((int)piVar6 + 0xd) == '\0') {
    if (*(char *)(piVar4[2] + 0xd) == '\0') {
      piVar8 = (int *)param_2[2];
      if (param_2 != piVar4) {
        piVar6[1] = (int)param_2;
        *param_2 = *piVar4;
        if (param_2 == (int *)piVar4[2]) {
          piVar6 = param_2;
        }
        else {
          piVar6 = (int *)param_2[1];
          if (*(char *)((int)piVar8 + 0xd) == '\0') {
            piVar8[1] = (int)piVar6;
          }
          *piVar6 = (int)piVar8;
          param_2[2] = piVar4[2];
          *(int **)(piVar4[2] + 4) = param_2;
        }
        if (*(int **)(*(int *)this + 4) == piVar4) {
          *(int **)(*(int *)this + 4) = param_2;
        }
        else {
          piVar5 = (int *)piVar4[1];
          if ((int *)*piVar5 == piVar4) {
            *piVar5 = (int)param_2;
          }
          else {
            piVar5[2] = (int)param_2;
          }
        }
        param_2[1] = piVar4[1];
        iVar3 = param_2[3];
        *(char *)(param_2 + 3) = (char)piVar4[3];
        *(char *)(piVar4 + 3) = (char)iVar3;
        goto LAB_00408587;
      }
    }
    else {
      piVar8 = piVar6;
    }
  }
  else {
    piVar8 = (int *)piVar4[2];
  }
  piVar6 = (int *)piVar4[1];
  if (*(char *)((int)piVar8 + 0xd) == '\0') {
    piVar8[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)this + 4) == piVar4) {
    *(int **)(*(int *)this + 4) = piVar8;
  }
  else if ((int *)*piVar6 == piVar4) {
    *piVar6 = (int)piVar8;
  }
  else {
    piVar6[2] = (int)piVar8;
  }
  piVar5 = *(int **)this;
  if ((int *)*piVar5 == piVar4) {
    if (*(char *)((int)piVar8 + 0xd) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0xd);
      piVar5 = (int *)*piVar8;
      piVar7 = piVar8;
      while (piVar2 = piVar5, cVar1 == '\0') {
        piVar5 = (int *)*piVar2;
        cVar1 = *(char *)((int)piVar5 + 0xd);
        piVar7 = piVar2;
      }
      piVar5 = *(int **)this;
    }
    else {
      piVar7 = piVar6;
    }
    *piVar5 = (int)piVar7;
  }
  if (*(int **)(*(int *)this + 8) == piVar4) {
    if (*(char *)((int)piVar8 + 0xd) == '\0') {
      cVar1 = *(char *)(piVar8[2] + 0xd);
      piVar5 = (int *)piVar8[2];
      piVar7 = piVar8;
      while (piVar2 = piVar5, cVar1 == '\0') {
        piVar5 = (int *)piVar2[2];
        cVar1 = *(char *)((int)piVar5 + 0xd);
        piVar7 = piVar2;
      }
      *(int **)(*(int *)this + 8) = piVar7;
    }
    else {
      *(int **)(*(int *)this + 8) = piVar6;
    }
  }
LAB_00408587:
  if ((char)piVar4[3] == '\x01') {
    if (piVar8 != *(int **)(*(int *)this + 4)) {
      do {
        piVar5 = piVar6;
        if ((char)piVar8[3] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar8 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[3] == '\0') {
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(piVar5 + 3) = 0;
            FUN_00409880(this,(int)piVar5);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0xd) == '\0') {
            if ((*(char *)(*piVar6 + 0xc) != '\x01') || (*(char *)(piVar6[2] + 0xc) != '\x01')) {
              if (*(char *)(piVar6[2] + 0xc) == '\x01') {
                *(undefined1 *)(*piVar6 + 0xc) = 1;
                *(undefined1 *)(piVar6 + 3) = 0;
                FUN_004098e0(this,piVar6);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 3) = (char)piVar5[3];
              *(undefined1 *)(piVar5 + 3) = 1;
              *(undefined1 *)(piVar6[2] + 0xc) = 1;
              FUN_00409880(this,(int)piVar5);
              break;
            }
LAB_0040864f:
            *(undefined1 *)(piVar6 + 3) = 0;
          }
        }
        else {
          if ((char)piVar6[3] == '\0') {
            *(undefined1 *)(piVar6 + 3) = 1;
            *(undefined1 *)(piVar5 + 3) = 0;
            FUN_004098e0(this,piVar5);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0xd) == '\0') {
            if ((*(char *)(piVar6[2] + 0xc) == '\x01') && (*(char *)(*piVar6 + 0xc) == '\x01')) goto LAB_0040864f;
            if (*(char *)(*piVar6 + 0xc) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0xc) = 1;
              *(undefined1 *)(piVar6 + 3) = 0;
              FUN_00409880(this,(int)piVar6);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 3) = (char)piVar5[3];
            *(undefined1 *)(piVar5 + 3) = 1;
            *(undefined1 *)(*piVar6 + 0xc) = 1;
            FUN_004098e0(this,piVar5);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar8 = piVar5;
      } while (piVar5 != *(int **)(*(int *)this + 4));
    }
    *(undefined1 *)(piVar8 + 3) = 1;
  }
  local_8 = 0;
  FUN_004054d0(piVar4 + 6);
  if (((void *)piVar4[4] != (void *)0x0) && (piVar4[5] == 1)) {
    free((void *)piVar4[4]);
  }
  operator_delete(piVar4);
  if (*(int *)((int)this + 4) == 0) {
    *param_1 = param_2;
    ExceptionList = local_10;
    return param_1;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  *param_1 = param_2;
  ExceptionList = local_10;
  return param_1;
}



// ===== FUN_00408720 @ 00408720 =====

int * __thiscall FUN_00408720(void *this,int *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  undefined4 *local_8;
  
  local_8 = FUN_00409800(this,param_2);
  if (local_8 != *(undefined4 **)this) {
    pbVar2 = (byte *)*param_2;
    if (pbVar2 == (byte *)0x0) {
      bVar4 = (uint)param_2[1] < (uint)local_8[5];
    }
    else {
      pbVar3 = (byte *)local_8[4];
      do {
        bVar1 = *pbVar2;
        bVar4 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_0040876f:
          bVar4 = (int)(-(uint)bVar4 | 1) < 0;
          goto LAB_00408787;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar4 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_0040876f;
        pbVar2 = pbVar2 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      bVar4 = false;
    }
LAB_00408787:
    if (!bVar4) goto LAB_00408791;
  }
  local_8 = *(undefined4 **)this;
LAB_00408791:
  *param_1 = (int)local_8;
  return param_1;
}



// ===== FUN_004087b0 @ 004087b0 =====

void __thiscall FUN_004087b0(void *this,uint param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  uVar4 = *(uint *)((int)this + 0x10);
  if (uVar4 < param_1) {
    do {
      if (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 1U) {
        FUN_00409b50((int)this);
      }
      uVar4 = *(int *)((int)this + 8) - 1;
      *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & uVar4;
      iVar2 = (*(int *)((int)this + 0x10) + *(int *)((int)this + 0xc) & uVar4) * 4;
      if (*(int *)(iVar2 + *(int *)((int)this + 4)) == 0) {
        pvVar3 = operator_new(0x28);
        if (pvVar3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::_Xbad_alloc();
        }
        *(void **)(iVar2 + *(int *)((int)this + 4)) = pvVar3;
      }
      iVar2 = *(int *)(iVar2 + *(int *)((int)this + 4));
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x20) = 0xf;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        *(undefined1 *)(iVar2 + 0xc) = 0;
      }
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
    } while (*(uint *)((int)this + 0x10) < param_1);
    uVar4 = *(uint *)((int)this + 0x10);
  }
  while (param_1 < uVar4) {
    iVar2 = *(int *)(*(int *)((int)this + 4) +
                    (*(int *)((int)this + 0xc) + *(int *)((int)this + 0x10) + -1 & *(int *)((int)this + 8) - 1U) * 4);
    if (0xf < *(uint *)(iVar2 + 0x20)) {
      operator_delete(*(void **)(iVar2 + 0xc));
    }
    *(undefined4 *)(iVar2 + 0x20) = 0xf;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined1 *)(iVar2 + 0xc) = 0;
    piVar1 = (int *)((int)this + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    uVar4 = *(uint *)((int)this + 0x10);
  }
  return;
}



// ===== FUN_00408890 @ 00408890 =====

void __thiscall FUN_00408890(void *this,undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041da15;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 1U) {
    FUN_00409b50((int)this);
  }
  uVar4 = *(int *)((int)this + 8) - 1;
  *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & uVar4;
  iVar1 = (uVar4 & *(int *)((int)this + 0x10) + *(int *)((int)this + 0xc)) * 4;
  if (*(int *)(iVar1 + *(int *)((int)this + 4)) == 0) {
    pvVar3 = operator_new(0x28);
    if (pvVar3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_alloc();
    }
    *(void **)(iVar1 + *(int *)((int)this + 4)) = pvVar3;
  }
  puVar2 = *(undefined8 **)(iVar1 + *(int *)((int)this + 4));
  local_8 = 0;
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = *param_1;
    *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(param_1 + 1);
    *(undefined4 *)(puVar2 + 4) = 0xf;
    *(undefined4 *)((int)puVar2 + 0x1c) = 0;
    *(undefined1 *)((int)puVar2 + 0xc) = 0;
    FUN_00401e50((undefined1 *)((int)puVar2 + 0xc),(int *)((int)param_1 + 0xc),0,0xffffffff);
    *(undefined4 *)((int)puVar2 + 0x24) = *(undefined4 *)((int)param_1 + 0x24);
  }
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  ExceptionList = local_10;
  return;
}



// ===== FUN_00408970 @ 00408970 =====

void __thiscall FUN_00408970(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar1) && (puVar2 = *(undefined4 **)this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_00409e10(this);
    }
    if (*(void **)((int)this + 4) != (void *)0x0) {
      FUN_00408300(*(void **)((int)this + 4),(undefined4 *)(*(int *)this + (((int)param_1 - (int)puVar2) / 0x18) * 0x18)
                  );
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x18;
      return;
    }
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_00409e10(this);
    }
    if (*(void **)((int)this + 4) != (void *)0x0) {
      FUN_00408300(*(void **)((int)this + 4),param_1);
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x18;
  return;
}



// ===== FUN_004089f0 @ 004089f0 =====

void __thiscall FUN_004089f0(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined1 *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041da3a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)((int)this + 4);
  if ((param_1 < piVar1) && (piVar2 = *(int **)this, piVar2 <= param_1)) {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_00409e10(this);
    }
    param_1 = (int *)(*(int *)this + (((int)param_1 - (int)piVar2) / 0x18) * 0x18);
    this_00 = *(undefined1 **)((int)this + 4);
    local_8 = 0;
    if (this_00 == (undefined1 *)0x0) goto LAB_00408a99;
  }
  else {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_00409e10(this);
    }
    this_00 = *(undefined1 **)((int)this + 4);
    local_8 = 1;
    if (this_00 == (undefined1 *)0x0) goto LAB_00408a99;
  }
  *(undefined4 *)(this_00 + 0x14) = 0xf;
  *(undefined4 *)(this_00 + 0x10) = 0;
  *this_00 = 0;
  FUN_00401e50(this_00,param_1,0,0xffffffff);
LAB_00408a99:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x18;
  ExceptionList = local_10;
  return;
}



// ===== FUN_00408ab0 @ 00408ab0 =====

basic_ostream<char,std::char_traits<char>_> * __fastcall
FUN_00408ab0(basic_ostream<char,std::char_traits<char>_> *param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041da92;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined **)param_1 = &DAT_00420110;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(param_1 + 0x50));
  this = (basic_streambuf<char,std::char_traits<char>_> *)(param_1 + 4);
  local_8 = 0;
  std::basic_ostream<char,std::char_traits<char>_>::basic_ostream<char,std::char_traits<char>_>(param_1,this,false);
  local_8 = 1;
  *(undefined ***)(param_1 + *(int *)(*(int *)param_1 + 4)) =
       std::basic_ostringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + -4) = *(int *)(*(int *)param_1 + 4) + -0x50;
  std::basic_streambuf<char,std::char_traits<char>_>::basic_streambuf<char,std::char_traits<char>_>(this);
  *(undefined ***)this = std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 4;
  ExceptionList = local_10;
  return param_1;
}



// ===== FUN_00408b60 @ 00408b60 =====

undefined4 * __thiscall FUN_00408b60(void *this,undefined4 *param_1)

{
  FUN_00409eb0((void *)((int)this + 4),param_1);
  return param_1;
}



// ===== FUN_00408b80 @ 00408b80 =====

void __fastcall FUN_00408b80(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  *(undefined ***)param_1 = std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  if (((byte)param_1[0x3c] & 1) != 0) {
    operator_delete((void *)**(undefined4 **)(param_1 + 0xc));
  }
  **(undefined4 **)(param_1 + 0xc) = 0;
  **(undefined4 **)(param_1 + 0x1c) = 0;
  **(undefined4 **)(param_1 + 0x2c) = 0;
  **(undefined4 **)(param_1 + 0x10) = 0;
  **(undefined4 **)(param_1 + 0x20) = 0;
  **(undefined4 **)(param_1 + 0x30) = 0;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x00408be1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>(param_1);
  return;
}



// ===== FUN_00408bf0 @ 00408bf0 =====

int __thiscall FUN_00408bf0(void *this,int param_1)

{
  byte bVar1;
  void *_Src;
  void *_Dst;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)((int)this + 0x3c) & 2) != 0) {
    return -1;
  }
  if (param_1 == -1) {
    return 0;
  }
  if ((*(uint *)((int)this + 0x3c) & 8) != 0) {
    uVar6 = **(uint **)((int)this + 0x20);
    if ((uVar6 != 0) && (uVar3 = *(uint *)((int)this + 0x38), uVar6 < uVar3)) {
      iVar5 = **(int **)((int)this + 0x30);
      **(uint **)((int)this + 0x20) = uVar3;
      **(int **)((int)this + 0x30) = (iVar5 + uVar6) - uVar3;
    }
  }
  uVar6 = **(uint **)((int)this + 0x20);
  if (uVar6 == 0) {
LAB_00408c5b:
    uVar6 = 0;
  }
  else {
    if (uVar6 < **(int **)((int)this + 0x30) + uVar6) goto LAB_00408d87;
    if (uVar6 == 0) goto LAB_00408c5b;
    uVar6 = (**(int **)((int)this + 0x30) - **(int **)((int)this + 0xc)) + uVar6;
  }
  uVar3 = uVar6 >> 1;
  if (uVar3 < 0x20) {
    uVar3 = 0x20;
  }
  else if (uVar3 == 0) {
    return -1;
  }
  do {
    if (uVar6 <= 0x7fffffff - uVar3) break;
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  if (uVar3 == 0) {
    return -1;
  }
  uVar3 = uVar3 + uVar6;
  _Dst = FUN_004023f0(uVar3);
  _Src = (void *)**(undefined4 **)((int)this + 0xc);
  if ((uVar6 == 0) || (memcpy(_Dst,_Src,uVar6), uVar6 == 0)) {
    *(void **)((int)this + 0x38) = _Dst;
    **(undefined4 **)((int)this + 0x10) = _Dst;
    **(undefined4 **)((int)this + 0x20) = _Dst;
    **(uint **)((int)this + 0x30) = uVar3;
    bVar1 = *(byte *)((int)this + 0x3c);
    **(undefined4 **)((int)this + 0xc) = _Dst;
    if ((bVar1 & 4) == 0) {
      **(undefined4 **)((int)this + 0x1c) = _Dst;
      **(undefined4 **)((int)this + 0x2c) = 1;
    }
    else {
      **(undefined4 **)((int)this + 0x1c) = 0;
      **(undefined4 **)((int)this + 0x2c) = _Dst;
    }
  }
  else {
    *(int *)((int)this + 0x38) = (int)_Dst + (*(int *)((int)this + 0x38) - (int)_Src);
    iVar5 = (**(int **)((int)this + 0x20) - (int)_Src) + (int)_Dst;
    **(int **)((int)this + 0x10) = (int)_Dst + (**(int **)((int)this + 0x10) - (int)_Src);
    **(int **)((int)this + 0x20) = iVar5;
    **(int **)((int)this + 0x30) = (int)_Dst + (uVar3 - iVar5);
    if ((*(byte *)((int)this + 0x3c) & 4) == 0) {
      iVar5 = **(int **)((int)this + 0x20);
      iVar4 = (**(int **)((int)this + 0x1c) - (int)_Src) + (int)_Dst;
      **(undefined4 **)((int)this + 0xc) = _Dst;
      **(int **)((int)this + 0x1c) = iVar4;
      **(int **)((int)this + 0x2c) = (iVar5 - iVar4) + 1;
    }
    else {
      **(undefined4 **)((int)this + 0xc) = _Dst;
      **(undefined4 **)((int)this + 0x1c) = 0;
      **(undefined4 **)((int)this + 0x2c) = _Dst;
    }
  }
  if ((*(byte *)((int)this + 0x3c) & 1) != 0) {
    operator_delete(_Src);
  }
  *(uint *)((int)this + 0x3c) = *(uint *)((int)this + 0x3c) | 1;
LAB_00408d87:
  pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::_Pninc(this);
  *pcVar2 = (char)param_1;
  return param_1;
}



// ===== FUN_00408da0 @ 00408da0 =====

int __thiscall FUN_00408da0(void *this,int param_1)

{
  uint uVar1;
  
  uVar1 = **(uint **)((int)this + 0x1c);
  if ((uVar1 != 0) && (**(uint **)((int)this + 0xc) < uVar1)) {
    if ((param_1 == -1) || (((char)param_1 == *(char *)(uVar1 - 1) || ((*(byte *)((int)this + 0x3c) & 2) == 0)))) {
      **(int **)((int)this + 0x2c) = **(int **)((int)this + 0x2c) + 1;
      **(int **)((int)this + 0x1c) = **(int **)((int)this + 0x1c) + -1;
      if (param_1 == -1) {
        return 0;
      }
      *(char *)**(undefined4 **)((int)this + 0x1c) = (char)param_1;
      return param_1;
    }
  }
  return -1;
}



// ===== FUN_00408e00 @ 00408e00 =====

uint __fastcall FUN_00408e00(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)**(int **)(param_1 + 0x1c);
  if (pbVar1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (pbVar1 < pbVar1 + **(int **)(param_1 + 0x2c)) {
    return (uint)*pbVar1;
  }
  if ((((*(byte *)(param_1 + 0x3c) & 4) != 0) ||
      (pbVar2 = (byte *)**(undefined4 **)(param_1 + 0x20), pbVar2 == (byte *)0x0)) ||
     ((pbVar2 <= pbVar1 && (*(byte **)(param_1 + 0x38) <= pbVar1)))) {
    return 0xffffffff;
  }
  if (*(byte **)(param_1 + 0x38) < pbVar2) {
    *(byte **)(param_1 + 0x38) = pbVar2;
  }
  **(int **)(param_1 + 0x2c) = *(int *)(param_1 + 0x38) - **(int **)(param_1 + 0x1c);
  return (uint)*(byte *)**(undefined4 **)(param_1 + 0x1c);
}



// ===== FUN_00408e60 @ 00408e60 =====

void __thiscall FUN_00408e60(void *this,uint *param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  uVar3 = **(uint **)((int)this + 0x20);
  if ((uVar3 != 0) && (*(uint *)((int)this + 0x38) < uVar3)) {
    *(uint *)((int)this + 0x38) = uVar3;
  }
  if (((param_5 & 1) == 0) || (iVar5 = **(int **)((int)this + 0x1c), iVar5 == 0)) {
    if (((param_5 & 2) == 0) || (uVar3 = **(uint **)((int)this + 0x20), uVar3 == 0)) {
      if (param_2 == 0 && param_3 == 0) goto LAB_00408ffb;
    }
    else {
      if (param_4 == 2) {
        uVar4 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 == 1) {
        uVar4 = uVar3 - **(int **)((int)this + 0xc);
        bVar7 = CARRY4(param_2,uVar4);
        param_2 = param_2 + uVar4;
        param_3 = param_3 + ((int)uVar4 >> 0x1f) + (uint)bVar7;
      }
      else if (param_4 != 0) {
        param_2 = *(uint *)_BADOFF_exref;
        param_3 = *(uint *)(_BADOFF_exref + 4);
      }
      if (-1 < (int)param_3) {
        uVar4 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)param_3 <= iVar5) && (((int)param_3 < iVar5 || (param_2 <= uVar4)))) {
          iVar5 = (**(int **)((int)this + 0xc) - uVar3) + param_2;
          **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar5;
          **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar5;
          goto LAB_00408ffb;
        }
      }
    }
  }
  else {
    if (param_4 == 2) {
      uVar3 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
      bVar7 = CARRY4(param_2,uVar3);
      param_2 = param_2 + uVar3;
      param_3 = param_3 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
    }
    else if (param_4 == 1) {
      if ((param_5 & 2) != 0) goto LAB_00408ed5;
      uVar3 = iVar5 - **(int **)((int)this + 0xc);
      bVar7 = CARRY4(param_2,uVar3);
      param_2 = param_2 + uVar3;
      param_3 = param_3 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
    }
    else if (param_4 != 0) {
LAB_00408ed5:
      param_2 = *(uint *)_BADOFF_exref;
      param_3 = *(uint *)(_BADOFF_exref + 4);
    }
    if (-1 < (int)param_3) {
      uVar3 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
      iVar6 = (int)uVar3 >> 0x1f;
      if (((int)param_3 <= iVar6) && (((int)param_3 < iVar6 || (param_2 <= uVar3)))) {
        iVar5 = (**(int **)((int)this + 0xc) - iVar5) + param_2;
        **(int **)((int)this + 0x2c) = **(int **)((int)this + 0x2c) - iVar5;
        **(int **)((int)this + 0x1c) = **(int **)((int)this + 0x1c) + iVar5;
        if (((param_5 & 2) != 0) && (piVar1 = *(int **)((int)this + 0x20), *piVar1 != 0)) {
          iVar5 = **(int **)((int)this + 0x30);
          iVar6 = *piVar1;
          iVar2 = **(int **)((int)this + 0x1c);
          *piVar1 = iVar2;
          **(int **)((int)this + 0x30) = (iVar5 + iVar6) - iVar2;
        }
        goto LAB_00408ffb;
      }
    }
  }
  param_2 = *(uint *)_BADOFF_exref;
  param_3 = *(uint *)(_BADOFF_exref + 4);
LAB_00408ffb:
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// ===== FUN_00409030 @ 00409030 =====

void __thiscall
FUN_00409030(void *this,uint *param_1,uint param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
            undefined4 param_7,uint param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_2 + param_4;
  uVar6 = param_3 + param_5 + (uint)CARRY4(param_2,param_4);
  uVar4 = **(uint **)((int)this + 0x20);
  if ((uVar4 != 0) && (*(uint *)((int)this + 0x38) < uVar4)) {
    *(uint *)((int)this + 0x38) = uVar4;
  }
  if ((uVar7 != *(uint *)_BADOFF_exref) || (uVar6 != *(uint *)(_BADOFF_exref + 4))) {
    if (((param_8 & 1) == 0) || (**(int **)((int)this + 0x1c) == 0)) {
      if ((((param_8 & 2) != 0) && (**(int **)((int)this + 0x20) != 0)) && (-1 < (int)uVar6)) {
        uVar4 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
        iVar5 = (int)uVar4 >> 0x1f;
        if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= uVar4)))) {
          iVar5 = (**(int **)((int)this + 0xc) - **(int **)((int)this + 0x20)) + uVar7;
          **(int **)((int)this + 0x30) = **(int **)((int)this + 0x30) - iVar5;
          **(int **)((int)this + 0x20) = **(int **)((int)this + 0x20) + iVar5;
          goto LAB_0040913a;
        }
      }
    }
    else if (-1 < (int)uVar6) {
      uVar4 = *(int *)((int)this + 0x38) - **(int **)((int)this + 0xc);
      iVar5 = (int)uVar4 >> 0x1f;
      if (((int)uVar6 <= iVar5) && (((int)uVar6 < iVar5 || (uVar7 <= uVar4)))) {
        iVar5 = (**(int **)((int)this + 0xc) - **(int **)((int)this + 0x1c)) + uVar7;
        **(int **)((int)this + 0x2c) = **(int **)((int)this + 0x2c) - iVar5;
        **(int **)((int)this + 0x1c) = **(int **)((int)this + 0x1c) + iVar5;
        if (((param_8 & 2) != 0) && (piVar1 = *(int **)((int)this + 0x20), *piVar1 != 0)) {
          iVar5 = **(int **)((int)this + 0x30);
          iVar2 = *piVar1;
          iVar3 = **(int **)((int)this + 0x1c);
          *piVar1 = iVar3;
          **(int **)((int)this + 0x30) = (iVar5 + iVar2) - iVar3;
        }
        goto LAB_0040913a;
      }
    }
    uVar6 = *(uint *)(_BADOFF_exref + 4);
    uVar7 = *(uint *)_BADOFF_exref;
  }
LAB_0040913a:
  *param_1 = uVar7;
  param_1[1] = uVar6;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



// ===== FUN_00409170 @ 00409170 =====

void __fastcall FUN_00409170(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



// ===== FUN_00409180 @ 00409180 =====

basic_ios<char,std::char_traits<char>_> * __thiscall FUN_00409180(void *this,byte param_1)

{
  basic_ios<char,std::char_traits<char>_> *pbVar1;
  
  pbVar1 = (basic_ios<char,std::char_traits<char>_> *)((int)this + -0x50);
  *(undefined ***)(pbVar1 + *(int *)(*(int *)((int)this + -0x50) + 4)) =
       std::basic_ostringstream<char,std::char_traits<char>,std::allocator<char>_>::vftable;
  *(int *)(pbVar1 + *(int *)(*(int *)pbVar1 + 4) + -4) = *(int *)(*(int *)pbVar1 + 4) + -0x50;
  FUN_00408b80((basic_streambuf<char,std::char_traits<char>_> *)((int)this + -0x4c));
  std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>
            ((basic_ostream<char,std::char_traits<char>_> *)((int)this + -0x48));
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(this);
  if ((param_1 & 1) != 0) {
    operator_delete(pbVar1);
  }
  return pbVar1;
}



// ===== FUN_004091e0 @ 004091e0 =====

basic_streambuf<char,std::char_traits<char>_> * __thiscall FUN_004091e0(void *this,byte param_1)

{
  FUN_00408b80(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



// ===== FUN_00409210 @ 00409210 =====

void __thiscall FUN_00409210(void *this,undefined4 *param_1)

{
  if ((uint)param_1[5] < 0x10) {
    if (param_1[4] + 1 != 0) {
      memmove(this,param_1,param_1[4] + 1);
    }
  }
  else {
    if (this != (void *)0x0) {
      *(undefined4 *)this = *param_1;
    }
    *param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = param_1[4];
  *(undefined4 *)((int)this + 0x14) = param_1[5];
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  return;
}



// ===== FUN_00409270 @ 00409270 =====

int * __thiscall FUN_00409270(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  iVar4 = *(int *)((int)this + 0x10);
  if (uVar2 < param_3) {
    param_3 = uVar2;
  }
  if (-iVar4 - 1U <= param_3) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_3 != 0) {
    bVar1 = FUN_00402190(this,iVar4 + param_3,'\0');
    if (bVar1) {
      if (0xf < (uint)param_1[5]) {
        param_1 = (undefined4 *)*param_1;
      }
      if (*(uint *)((int)this + 0x14) < 0x10) {
        pvVar3 = this;
      }
      else {
        pvVar3 = *(void **)this;
      }
      if (param_3 != 0) {
        memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar3),(void *)(param_2 + (int)param_1),param_3);
      }
      iVar4 = iVar4 + param_3;
      *(int *)((int)this + 0x10) = iVar4;
      if (0xf < *(uint *)((int)this + 0x14)) {
        *(undefined1 *)(*(int *)this + iVar4) = 0;
        return this;
      }
      *(undefined1 *)((int)this + iVar4) = 0;
    }
  }
  return this;
}



// ===== FUN_00409330 @ 00409330 =====

int * __thiscall FUN_00409330(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    if (uVar1 < 0x10) {
      piVar3 = this;
    }
    else {
      piVar3 = *(int **)this;
    }
    if (piVar3 <= param_1) {
      if (uVar1 < 0x10) {
        pvVar4 = this;
      }
      else {
        pvVar4 = *(void **)this;
      }
      if (param_1 < (int *)(*(int *)((int)this + 0x10) + (int)pvVar4)) {
        if (uVar1 < 0x10) {
          piVar3 = FUN_00409270(this,this,(int)param_1 - (int)this,param_2);
          return piVar3;
        }
        piVar3 = FUN_00409270(this,this,(int)param_1 - *(int *)this,param_2);
        return piVar3;
      }
    }
  }
  iVar5 = *(int *)((int)this + 0x10);
  if (-iVar5 - 1U <= param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_2 != 0) {
    bVar2 = FUN_00402190(this,iVar5 + param_2,'\0');
    if (bVar2) {
      if (*(uint *)((int)this + 0x14) < 0x10) {
        pvVar4 = this;
      }
      else {
        pvVar4 = *(void **)this;
      }
      if (param_2 != 0) {
        memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),param_1,param_2);
      }
      iVar5 = iVar5 + param_2;
      *(int *)((int)this + 0x10) = iVar5;
      if (0xf < *(uint *)((int)this + 0x14)) {
        *(undefined1 *)(*(int *)this + iVar5) = 0;
        return this;
      }
      *(undefined1 *)((int)this + iVar5) = 0;
    }
  }
  return this;
}



// ===== FUN_00409420 @ 00409420 =====

int * __thiscall FUN_00409420(void *this,uint param_1,char param_2)

{
  uint uVar1;
  size_t sVar2;
  
  sVar2 = *(size_t *)((int)this + 0x10);
  if (-sVar2 - 1 <= param_1) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_1 != 0) {
    uVar1 = sVar2 + param_1;
    if (uVar1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("string too long");
    }
    if (*(uint *)((int)this + 0x14) < uVar1) {
      FUN_004022a0(this,uVar1,sVar2);
      if (uVar1 == 0) {
        return this;
      }
    }
    else if (uVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
      if (*(uint *)((int)this + 0x14) < 0x10) {
        *(undefined1 *)this = 0;
        return this;
      }
      **(undefined1 **)this = 0;
      return this;
    }
    FUN_0040a040(this,*(int *)((int)this + 0x10),param_1,param_2);
    *(uint *)((int)this + 0x10) = uVar1;
    if (0xf < *(uint *)((int)this + 0x14)) {
      *(undefined1 *)(*(int *)this + uVar1) = 0;
      return this;
    }
    *(undefined1 *)((int)this + uVar1) = 0;
  }
  return this;
}



// ===== FUN_004094d0 @ 004094d0 =====

int * __thiscall FUN_004094d0(void *this,uint param_1)

{
  void *_Dst;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_004022a0(this,param_1,*(size_t *)((int)this + 0x10));
    if (param_1 == 0) {
      return this;
    }
  }
  else if (param_1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)this = 0;
      return this;
    }
    **(undefined1 **)this = 0;
    return this;
  }
  if (param_1 == 1) {
    if (*(uint *)((int)this + 0x14) < 0x10) {
      *(undefined1 *)this = 0x20;
    }
    else {
      **(undefined1 **)this = 0x20;
    }
  }
  else {
    if (*(uint *)((int)this + 0x14) < 0x10) {
      _Dst = this;
    }
    else {
      _Dst = *(void **)this;
    }
    memset(_Dst,0x20,param_1);
  }
  *(uint *)((int)this + 0x10) = param_1;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined1 *)((int)this + param_1) = 0;
    return this;
  }
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return this;
}



// ===== FUN_00409590 @ 00409590 =====

/* WARNING: Removing unreachable block (ram,0x004095a4) */

int __thiscall FUN_00409590(void *this,undefined4 param_1,undefined4 param_2,size_t param_3)

{
  void *pvVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*(int *)((int)this + 0x10) != 0) {
    pvVar1 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      pvVar1 = *(void **)this;
    }
    pcVar3 = (char *)((int)pvVar1 + *(int *)((int)this + 0x10) + -1);
    while( true ) {
      if ((param_3 == 0) || (pvVar1 = memchr(&DAT_0041f7fc,(int)*pcVar3,param_3), pvVar1 == (void *)0x0)) {
        if (0xf < *(uint *)((int)this + 0x14)) {
          this = *(void **)this;
        }
        return (int)pcVar3 - (int)this;
      }
      pcVar2 = (char *)FUN_00401f70(this);
      if (pcVar3 == pcVar2) break;
      pcVar3 = pcVar3 + -1;
    }
  }
  return -1;
}



// ===== FUN_00409600 @ 00409600 =====

undefined4 * __thiscall FUN_00409600(void *this,int *param_1)

{
  undefined4 uVar1;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041dab8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  uVar1 = FUN_0040a290();
  *(undefined4 *)this = uVar1;
  local_8 = 1;
  local_18 = local_18 & 0xffffff00;
  FUN_0040a610(this,param_1,local_18);
  ExceptionList = local_10;
  return this;
}



// ===== Catch_All@00409676 @ 00409676 =====

void Catch_All_00409676(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = (int *)**(undefined4 **)(unaff_EBP + -0x18);
  FUN_004096a0(*(undefined4 **)(unaff_EBP + -0x18),(undefined4 *)(unaff_EBP + 8),(int *)*piVar1,piVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_004096a0 @ 004096a0 =====

undefined4 * __thiscall FUN_004096a0(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *local_8;
  
  piVar2 = *(int **)this;
  local_8 = this;
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {
    FUN_00409760((int *)piVar2[1]);
    *(int *)(*(int *)this + 4) = *(int *)this;
    *(undefined4 *)*(undefined4 *)this = *(undefined4 *)this;
    *(int *)(*(int *)this + 8) = *(int *)this;
    *(undefined4 *)((int)this + 4) = 0;
    *param_1 = **(undefined4 **)this;
    return param_1;
  }
  while (piVar3 != param_3) {
    param_2 = piVar3;
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      param_2 = (int *)piVar3[2];
      if (*(char *)((int)param_2 + 0xd) == '\0') {
        cVar1 = *(char *)(*param_2 + 0xd);
        piVar2 = (int *)*param_2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0xd);
          param_2 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0xd);
        piVar4 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((param_2 = piVar4, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {
          cVar1 = *(char *)(param_2[1] + 0xd);
          piVar4 = (int *)param_2[1];
          piVar2 = param_2;
        }
      }
    }
    FUN_00408440(this,&local_8,piVar3);
    piVar3 = param_2;
  }
  *param_1 = piVar3;
  return param_1;
}



// ===== FUN_00409760 @ 00409760 =====

void FUN_00409760(int *param_1)

{
  char cVar1;
  int *piVar2;
  void **ppvVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041dae8;
  cVar1 = *(char *)((int)param_1 + 0xd);
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar3, cVar1 == '\0') {
    FUN_00409760((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    local_8 = 0;
    FUN_004054d0(param_1 + 6);
    local_8 = 0xffffffff;
    if (((void *)param_1[4] != (void *)0x0) && (param_1[5] == 1)) {
      free((void *)param_1[4]);
    }
    operator_delete(param_1);
    ppvVar3 = ExceptionList;
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  ExceptionList = local_10;
  return;
}



// ===== FUN_00409800 @ 00409800 =====

undefined4 * __thiscall FUN_00409800(void *this,undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  puVar7 = (undefined4 *)(*(undefined4 **)this)[1];
  cVar1 = *(char *)((int)puVar7 + 0xd);
  puVar3 = *(undefined4 **)this;
  do {
    if (cVar1 != '\0') {
      return puVar3;
    }
    pbVar4 = (byte *)puVar7[4];
    if (pbVar4 == (byte *)0x0) {
      bVar8 = (uint)puVar7[5] < (uint)param_1[1];
    }
    else {
      pbVar5 = (byte *)*param_1;
      do {
        bVar2 = *pbVar4;
        bVar8 = bVar2 < *pbVar5;
        if (bVar2 != *pbVar5) {
LAB_00409845:
          bVar8 = (int)(-(uint)bVar8 | 1) < 0;
          goto LAB_0040985a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar8 = bVar2 < pbVar5[1];
        if (bVar2 != pbVar5[1]) goto LAB_00409845;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar2 != 0);
      bVar8 = false;
    }
LAB_0040985a:
    if (bVar8) {
      puVar6 = (undefined4 *)puVar7[2];
      puVar7 = puVar3;
    }
    else {
      puVar6 = (undefined4 *)*puVar7;
    }
    cVar1 = *(char *)((int)puVar6 + 0xd);
    puVar3 = puVar7;
    puVar7 = puVar6;
  } while( true );
}



// ===== FUN_00409880 @ 00409880 =====

void __thiscall FUN_00409880(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0xd) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)this + 4)) {
    *(int **)(*(int *)this + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}



// ===== FUN_004098e0 @ 004098e0 =====

void __thiscall FUN_004098e0(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0xd) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)this + 4)) {
    *(int *)(*(int *)this + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}



// ===== FUN_00409940 @ 00409940 =====

bool FUN_00409940(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  
  pbVar3 = (byte *)*param_1;
  if (pbVar3 == (byte *)0x0) {
    return (uint)param_1[1] < (uint)param_2[1];
  }
  pbVar2 = (byte *)*param_2;
  while( true ) {
    bVar1 = *pbVar3;
    bVar4 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar3[1];
    bVar4 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    pbVar3 = pbVar3 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)(-(uint)bVar4 | 1) < 0;
}



// ===== FUN_004099a0 @ 004099a0 =====

int * __fastcall FUN_004099a0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0xd) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0xd) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0xd);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0xd);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return param_1;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0xd);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0xd);
    }
    *param_1 = iVar2;
  }
  return param_1;
}



// ===== FUN_004099f0 @ 004099f0 =====

int * __fastcall FUN_004099f0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)*param_1;
  if (*(char *)((int)puVar2 + 0xd) != '\0') {
    *param_1 = puVar2[2];
    return param_1;
  }
  piVar5 = (int *)*puVar2;
  if (*(char *)((int)piVar5 + 0xd) == '\0') {
    iVar3 = piVar5[2];
    if (*(char *)(piVar5[2] + 0xd) == '\0') {
      do {
        iVar4 = iVar3;
        iVar3 = *(int *)(iVar4 + 8);
      } while (*(char *)(iVar3 + 0xd) == '\0');
      *param_1 = iVar4;
      return param_1;
    }
  }
  else {
    piVar5 = (int *)puVar2[1];
    cVar1 = *(char *)((int)piVar5 + 0xd);
    while ((cVar1 == '\0' && (*param_1 == *piVar5))) {
      *param_1 = (int)piVar5;
      piVar5 = (int *)piVar5[1];
      cVar1 = *(char *)((int)piVar5 + 0xd);
    }
    if (*(char *)(*param_1 + 0xd) != '\0') {
      return param_1;
    }
  }
  *param_1 = (int)piVar5;
  return param_1;
}



// ===== FUN_00409a50 @ 00409a50 =====

void __thiscall FUN_00409a50(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  if (((*(int *)((int)this + 0xc) + *(int *)((int)this + 0x10) & 3U) == 0) &&
     (*(uint *)((int)this + 8) <= *(int *)((int)this + 0x10) + 4U >> 2)) {
    FUN_0040a0a0((int)this);
  }
  *(uint *)((int)this + 0xc) = *(uint *)((int)this + 0xc) & *(int *)((int)this + 8) * 4 - 1U;
  uVar4 = *(int *)((int)this + 0x10) + *(int *)((int)this + 0xc);
  iVar2 = (*(int *)((int)this + 8) - 1U & uVar4 >> 2) * 4;
  if (*(int *)(iVar2 + *(int *)((int)this + 4)) == 0) {
    pvVar3 = operator_new(0x10);
    if (pvVar3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_alloc();
    }
    *(void **)(iVar2 + *(int *)((int)this + 4)) = pvVar3;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)((int)this + 4) + iVar2) + (uVar4 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  return;
}



// ===== FUN_00409ae0 @ 00409ae0 =====

void __fastcall FUN_00409ae0(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  iVar2 = *(int *)(param_1 + 8);
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    pvVar1 = *(void **)(*(int *)(param_1 + 4) + iVar2 * 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// ===== FUN_00409b50 @ 00409b50 =====

void __fastcall FUN_00409b50(int param_1)

{
  size_t sVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar6 = 1;
  if (uVar2 != 0) {
    uVar6 = uVar2;
  }
  for (; (uVar6 == uVar2 || (uVar6 < 8)); uVar6 = uVar6 * 2) {
    if (0x6666666 - uVar6 < uVar6) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("deque<T> too long");
    }
  }
  uVar4 = *(uint *)(param_1 + 0xc);
  uVar6 = uVar6 - uVar2;
  local_8 = (undefined4 *)0x0;
  uVar2 = uVar2 + uVar6;
  if ((uVar2 != 0) && ((0x3fffffff < uVar2 || (local_8 = operator_new(uVar2 * 4), local_8 == (undefined4 *)0x0)))) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  pvVar3 = (void *)(*(int *)(param_1 + 4) + uVar4 * 4);
  sVar1 = ((*(int *)(param_1 + 8) * 4 - (int)pvVar3) + *(int *)(param_1 + 4) >> 2) * 4;
  pvVar3 = memmove(local_8 + uVar4,pvVar3,sVar1);
  pvVar3 = (void *)(sVar1 + (int)pvVar3);
  if (uVar6 < uVar4) {
    memmove(pvVar3,*(void **)(param_1 + 4),uVar6 * 4);
    pvVar3 = (void *)(uVar6 * 4 + *(int *)(param_1 + 4));
    sVar1 = ((int)((uVar4 * 4 - (int)pvVar3) + *(int *)(param_1 + 4)) >> 2) * 4;
    pvVar3 = memmove(local_8,pvVar3,sVar1);
    puVar7 = (undefined4 *)(sVar1 + (int)pvVar3);
    if (uVar6 == 0) goto LAB_00409ca0;
    uVar4 = uVar6;
  }
  else {
    iVar5 = uVar6 - uVar4;
    sVar1 = ((int)(uVar4 * 4) >> 2) * 4;
    pvVar3 = memmove(pvVar3,*(void **)(param_1 + 4),sVar1);
    if (iVar5 != 0) {
      puVar7 = (undefined4 *)(sVar1 + (int)pvVar3);
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    if (uVar4 == 0) goto LAB_00409ca0;
    puVar7 = local_8;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
LAB_00409ca0:
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar6;
  *(undefined4 **)(param_1 + 4) = local_8;
  return;
}



// ===== FUN_00409cd0 @ 00409cd0 =====

void __fastcall FUN_00409cd0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  while (iVar3 != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 4) +
                    (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc) + -1 & *(int *)(param_1 + 8) - 1U) * 4);
    if (0xf < *(uint *)(iVar3 + 0x20)) {
      operator_delete(*(void **)(iVar3 + 0xc));
    }
    *(undefined4 *)(iVar3 + 0x20) = 0xf;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    *(undefined1 *)(iVar3 + 0xc) = 0;
    piVar1 = (int *)(param_1 + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iVar3 = *(int *)(param_1 + 0x10);
  }
  iVar3 = *(int *)(param_1 + 8);
  while (iVar3 != 0) {
    iVar3 = iVar3 + -1;
    pvVar2 = *(void **)(*(int *)(param_1 + 4) + iVar3 * 4);
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
  }
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// ===== FUN_00409d70 @ 00409d70 =====

void __thiscall FUN_00409d70(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (param_1 == 0) {
LAB_00409da6:
    FUN_0040b100(*(int **)this,*(int **)((int)this + 4),piVar3);
    iVar1 = *(int *)((int)this + 4);
    iVar2 = *(int *)this;
    if (*(undefined4 **)this != (undefined4 *)0x0) {
      FUN_00402250(*(undefined4 **)this,*(undefined4 **)((int)this + 4));
      operator_delete(*(void **)this);
    }
    *(int **)this = piVar3;
    *(int **)((int)this + 8) = piVar3 + param_1 * 6;
    *(int **)((int)this + 4) = piVar3 + ((iVar1 - iVar2) / 0x18) * 6;
    return;
  }
  if (param_1 < 0xaaaaaab) {
    piVar3 = operator_new(param_1 * 0x18);
    if (piVar3 != (int *)0x0) goto LAB_00409da6;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}



// ===== FUN_00409e10 @ 00409e10 =====

void __fastcall FUN_00409e10(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_1[2] - param_1[1];
  iVar1 = iVar3 >> 0x1f;
  if (iVar3 / 0x18 + iVar1 == iVar1) {
    iVar1 = (param_1[1] - *param_1) / 0x18;
    if (iVar1 == 0xaaaaaaa) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("vector<T> too long");
    }
    uVar4 = iVar1 + 1;
    uVar2 = (param_1[2] - *param_1) / 0x18;
    if (0xaaaaaaa - (uVar2 >> 1) < uVar2) {
      uVar2 = 0;
      if (uVar4 != 0) {
        uVar2 = uVar4;
      }
      FUN_00409d70(param_1,uVar2);
      return;
    }
    uVar2 = uVar2 + (uVar2 >> 1);
    if (uVar2 < uVar4) {
      uVar2 = uVar4;
    }
    FUN_00409d70(param_1,uVar2);
  }
  return;
}



// ===== FUN_00409eb0 @ 00409eb0 =====

/* WARNING: Removing unreachable block (ram,0x00409fed) */

void __thiscall FUN_00409eb0(void *this,undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  void *local_24 [4];
  undefined4 local_14;
  uint local_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  if (((*(uint *)((int)this + 0x3c) & 2) == 0) && (uVar1 = **(uint **)((int)this + 0x20), uVar1 != 0)) {
    uVar2 = *(uint *)((int)this + 0x38);
    if (*(uint *)((int)this + 0x38) < uVar1) {
      uVar2 = uVar1;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (void *)((uint)local_24[0]._1_3_ << 8);
    FUN_00401f80(local_24,(int *)**(undefined4 **)((int)this + 0x10),uVar2 - (int)**(undefined4 **)((int)this + 0x10));
    FUN_00408300(param_1,local_24);
    if (0xf < local_10) {
      operator_delete(local_24[0]);
      FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
      return;
    }
  }
  else if (((*(uint *)((int)this + 0x3c) & 4) == 0) && (**(int **)((int)this + 0x1c) != 0)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (void *)((uint)local_24[0]._1_3_ << 8);
    FUN_00401f80(local_24,(int *)**(undefined4 **)((int)this + 0xc),
                 (**(int **)((int)this + 0x2c) + **(int **)((int)this + 0x1c)) - (int)**(undefined4 **)((int)this + 0xc)
                );
    FUN_00408300(param_1,local_24);
    if (0xf < local_10) {
      operator_delete(local_24[0]);
      FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
      return;
    }
  }
  else {
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (void *)((uint)local_24[0]._1_3_ << 8);
    param_1[5] = 0xf;
    param_1[4] = 0;
    *(undefined1 *)param_1 = 0;
    memmove(param_1,local_24,1);
    param_1[4] = local_14;
    param_1[5] = local_10;
  }
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_0040a010 @ 0040a010 =====

void __fastcall FUN_0040a010(int *param_1)

{
  int *piVar1;
  bool bVar2;
  
  bVar2 = std::uncaught_exception();
  if (!bVar2) {
    std::basic_ostream<char,std::char_traits<char>_>::_Osfx((basic_ostream<char,std::char_traits<char>_> *)*param_1);
  }
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040a037. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 8))();
  return;
}



// ===== FUN_0040a040 @ 0040a040 =====

void __thiscall FUN_0040a040(void *this,int param_1,size_t param_2,char param_3)

{
  if (param_2 == 1) {
    if (0xf < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    *(char *)((int)this + param_1) = param_3;
    return;
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
    this = *(void **)this;
  }
  memset((void *)((int)this + param_1),(int)param_3,param_2);
  return;
}



// ===== FUN_0040a080 @ 0040a080 =====

void __thiscall FUN_0040a080(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)((int)this + 0x10);
  iVar2 = *(int *)((int)this + 0xc);
  uVar3 = *(undefined4 *)this;
  param_1[1] = 0;
  *param_1 = uVar3;
  param_1[2] = iVar1 + iVar2;
  return;
}



// ===== FUN_0040a0a0 @ 0040a0a0 =====

void __fastcall FUN_0040a0a0(int param_1)

{
  size_t sVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar5 = 1;
  if (uVar2 != 0) {
    uVar5 = uVar2;
  }
  for (; (uVar5 == uVar2 || (uVar5 < 8)); uVar5 = uVar5 * 2) {
    if (0xfffffff - uVar5 < uVar5) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("deque<T> too long");
    }
  }
  uVar5 = uVar5 - uVar2;
  uVar6 = *(uint *)(param_1 + 0xc) >> 2;
  local_8 = (undefined4 *)0x0;
  uVar2 = uVar2 + uVar5;
  if ((uVar2 != 0) && ((0x3fffffff < uVar2 || (local_8 = operator_new(uVar2 * 4), local_8 == (undefined4 *)0x0)))) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  pvVar3 = (void *)(uVar6 * 4 + *(int *)(param_1 + 4));
  sVar1 = ((*(int *)(param_1 + 8) * 4 - (int)pvVar3) + *(int *)(param_1 + 4) >> 2) * 4;
  pvVar3 = memmove(local_8 + uVar6,pvVar3,sVar1);
  pvVar3 = (void *)(sVar1 + (int)pvVar3);
  if (uVar5 < uVar6) {
    memmove(pvVar3,*(void **)(param_1 + 4),uVar5 * 4);
    pvVar3 = (void *)(uVar5 * 4 + *(int *)(param_1 + 4));
    sVar1 = ((int)((uVar6 * 4 - (int)pvVar3) + *(int *)(param_1 + 4)) >> 2) * 4;
    pvVar3 = memmove(local_8,pvVar3,sVar1);
    puVar7 = (undefined4 *)(sVar1 + (int)pvVar3);
    if (uVar5 == 0) goto LAB_0040a1f3;
    uVar6 = uVar5;
  }
  else {
    iVar4 = uVar5 - uVar6;
    sVar1 = ((int)(uVar6 * 4) >> 2) * 4;
    pvVar3 = memmove(pvVar3,*(void **)(param_1 + 4),sVar1);
    if (iVar4 != 0) {
      puVar7 = (undefined4 *)(sVar1 + (int)pvVar3);
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
    }
    if (uVar6 == 0) goto LAB_0040a1f3;
    puVar7 = local_8;
  }
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
LAB_0040a1f3:
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar5;
  *(undefined4 **)(param_1 + 4) = local_8;
  return;
}



// ===== FUN_0040a230 @ 0040a230 =====

void __fastcall FUN_0040a230(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(*(int *)*param_1 + 4) + 0x38 + *param_1);
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040a241. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 8))();
  return;
}



// ===== FUN_0040a250 @ 0040a250 =====

void __thiscall FUN_0040a250(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if ((*(int **)this != (int *)0x0) && (puVar1 = (undefined4 *)**(int **)this, puVar1 != (undefined4 *)0x0)) {
    piVar3 = (int *)*puVar1;
  }
  iVar2 = *(int *)((int)this + 8);
  *param_1 = 0;
  param_1[1] = 0;
  if ((piVar3 != (int *)0x0) && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
    *param_1 = *(undefined4 *)*piVar3;
  }
  param_1[2] = iVar2 + -1;
  return;
}



// ===== FUN_0040a290 @ 0040a290 =====

void FUN_0040a290(void)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0040a29f. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
    std::_Xbad_alloc();
    return;
  }
  *(void **)pvVar1 = pvVar1;
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 8) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 8) = pvVar1;
  }
  *(undefined2 *)((int)pvVar1 + 0xc) = 0x101;
  return;
}



// ===== FUN_0040a2c0 @ 0040a2c0 =====

int * __fastcall FUN_0040a2c0(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  
  if ((char)*param_2 == '\0') {
    uVar3 = 0;
    piVar2 = param_1;
  }
  else {
    piVar2 = (int *)((int)param_2 + 1);
    piVar4 = param_2;
    do {
      iVar1 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
    } while ((char)iVar1 != '\0');
    uVar3 = (int)piVar4 - (int)piVar2;
  }
  piVar2 = FUN_0040a690(param_3,piVar2,param_2,uVar3);
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  if ((uint)piVar2[5] < 0x10) {
    if (piVar2[4] + 1U != 0) {
      memmove(param_1,piVar2,piVar2[4] + 1U);
    }
  }
  else {
    *param_1 = *piVar2;
    *piVar2 = 0;
  }
  param_1[4] = piVar2[4];
  param_1[5] = piVar2[5];
  piVar2[5] = 0xf;
  piVar2[4] = 0;
  *(undefined1 *)piVar2 = 0;
  return param_1;
}



// ===== FUN_0040a350 @ 0040a350 =====

int * __fastcall FUN_0040a350(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if ((char)*param_3 == '\0') {
    uVar3 = 0;
  }
  else {
    piVar2 = param_3;
    do {
      iVar1 = *piVar2;
      piVar2 = (int *)((int)piVar2 + 1);
    } while ((char)iVar1 != '\0');
    uVar3 = (int)piVar2 - ((int)param_3 + 1);
  }
  piVar2 = FUN_00409330(param_2,param_3,uVar3);
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  if ((uint)piVar2[5] < 0x10) {
    if (piVar2[4] + 1U != 0) {
      memmove(param_1,piVar2,piVar2[4] + 1U);
    }
  }
  else {
    *param_1 = *piVar2;
    *piVar2 = 0;
  }
  param_1[4] = piVar2[4];
  param_1[5] = piVar2[5];
  piVar2[5] = 0xf;
  piVar2[4] = 0;
  *(undefined1 *)piVar2 = 0;
  return param_1;
}



// ===== FUN_0040a3f0 @ 0040a3f0 =====

basic_ostream<char,std::char_traits<char>_> * __fastcall
FUN_0040a3f0(basic_ostream<char,std::char_traits<char>_> *param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  basic_ostream<char,std::char_traits<char>_> *pbVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar6;
  int extraout_ECX_01;
  bool bVar7;
  __int64 _Var8;
  int local_2c;
  int iStack_28;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041db20;
  local_10 = ExceptionList;
  uVar3 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  bVar2 = false;
  iVar6 = *(int *)(*(int *)param_1 + 4);
  iStack_28 = *(int *)(param_1 + iVar6 + 0x24);
  uVar1 = *(uint *)(param_1 + iVar6 + 0x20);
  if ((iStack_28 < 0) || ((iStack_28 < 1 && (((uVar1 == 0 || (iStack_28 < 0)) || ((iStack_28 < 1 && (uVar1 < 3)))))))) {
    iStack_28 = 0;
    local_2c = 0;
  }
  else {
    local_2c = uVar1 - 2;
    iStack_28 = iStack_28 - (uint)(uVar1 < 2);
  }
  if (*(int **)(param_1 + iVar6 + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + iVar6 + 0x38) + 4))();
  }
  local_8 = 0;
  if (((*(int *)(param_1 + *(int *)(*(int *)param_1 + 4) + 0xc) == 0) &&
      (pbVar5 = *(basic_ostream<char,std::char_traits<char>_> **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x3c),
      pbVar5 != (basic_ostream<char,std::char_traits<char>_> *)0x0)) && (pbVar5 != param_1)) {
    std::basic_ostream<char,std::char_traits<char>_>::flush(pbVar5);
  }
  iVar6 = *(int *)(*(int *)param_1 + 4);
  local_8 = 1;
  if (*(int *)(param_1 + iVar6 + 0xc) != 0) {
    std::basic_ios<char,std::char_traits<char>_>::setstate
              ((basic_ios<char,std::char_traits<char>_> *)(param_1 + *(int *)(*(int *)param_1 + 4)),4,false);
    local_8 = 0xffffffff;
    bVar2 = std::uncaught_exception();
    if (!bVar2) {
      std::basic_ostream<char,std::char_traits<char>_>::_Osfx(param_1);
    }
    if (*(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38) + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_8 = 2;
  if ((*(uint *)(param_1 + iVar6 + 0x14) & 0x1c0) != 0x40) {
    while( true ) {
      if ((iStack_28 < 0) || ((iStack_28 < 1 && (local_2c == 0)))) goto LAB_0040a501;
      iVar4 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]);
      iVar6 = extraout_ECX;
      if (iVar4 == -1) break;
      bVar7 = local_2c != 0;
      local_2c = local_2c + -1;
      iStack_28 = iStack_28 + -1 + (uint)bVar7;
    }
    bVar2 = true;
LAB_0040a501:
    if (bVar2) goto LAB_0040a571;
  }
  _Var8 = std::basic_streambuf<char,std::char_traits<char>_>::sputn
                    (*(basic_streambuf<char,std::char_traits<char>_> **)(param_1 + *(int *)(*(int *)param_1 + 4) + 0x38)
                     ,"\\u",(ulonglong)uVar3 << 0x20);
  iVar6 = extraout_ECX_00;
  if (_Var8 == 2) {
    while ((-1 < iStack_28 && ((0 < iStack_28 || (local_2c != 0))))) {
      iVar4 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (param_1 + *(int *)(*(int *)param_1 + 4) + 0x38),
                         (char)param_1[*(int *)(*(int *)param_1 + 4) + 0x40]);
      iVar6 = extraout_ECX_01;
      if (iVar4 == -1) break;
      bVar2 = local_2c != 0;
      local_2c = local_2c + -1;
      iStack_28 = iStack_28 + -1 + (uint)bVar2;
    }
  }
LAB_0040a571:
  iVar4 = *(int *)(*(int *)param_1 + 4);
  *(undefined4 *)(param_1 + iVar4 + 0x20) = 0;
  *(undefined4 *)(param_1 + iVar4 + 0x24) = 0;
  pbVar5 = (basic_ostream<char,std::char_traits<char>_> *)FUN_0040a5a8(iVar6,(int *)param_1);
  return pbVar5;
}



// ===== Catch_All@0040a588 @ 0040a588 =====

undefined * Catch_All_0040a588(void)

{
  int unaff_EBP;
  
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)
             (*(int *)(**(int **)(unaff_EBP + -0x14) + 4) + (int)*(int **)(unaff_EBP + -0x14)),4,true);
  return &DAT_0040a5a2;
}



// ===== FUN_0040a5a8 @ 0040a5a8 =====

undefined4 __fastcall FUN_0040a5a8(undefined4 param_1,int *param_2)

{
  basic_ostream<char,std::char_traits<char>_> *this;
  bool bVar1;
  int unaff_EBX;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)(*(int *)(*param_2 + 4) + (int)param_2),unaff_EBX,false);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  bVar1 = std::uncaught_exception();
  this = *(basic_ostream<char,std::char_traits<char>_> **)(unaff_EBP + -0x28);
  if (!bVar1) {
    std::basic_ostream<char,std::char_traits<char>_>::_Osfx(this);
  }
  if (*(int **)(this + *(int *)(*(int *)this + 4) + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(this + *(int *)(*(int *)this + 4) + 0x38) + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}



// ===== FUN_0040a610 @ 0040a610 =====

void __thiscall FUN_0040a610(void *this,int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  iVar2 = *(int *)this;
  puVar7 = FUN_0040ab40(this,*(undefined4 **)(*param_1 + 4),iVar2,param_2);
  *(undefined4 **)(iVar2 + 4) = puVar7;
  piVar3 = *(int **)this;
  *(int *)((int)this + 4) = param_1[1];
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0xd) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)this + 8) = *(int *)this;
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0xd);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0xd);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)this + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0xd);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)this + 8) = iVar2;
  return;
}



// ===== FUN_0040a690 @ 0040a690 =====

int * __thiscall FUN_0040a690(void *this,undefined4 param_1,int *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  
  if (param_2 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    if (uVar1 < 0x10) {
      piVar3 = this;
    }
    else {
      piVar3 = *(int **)this;
    }
    if (piVar3 <= param_2) {
      if (uVar1 < 0x10) {
        pvVar5 = this;
      }
      else {
        pvVar5 = *(void **)this;
      }
      if (param_2 < (int *)(*(int *)((int)this + 0x10) + (int)pvVar5)) {
        if (uVar1 < 0x10) {
          piVar3 = FUN_0040a790(this,uVar1,this,(int)param_2 - (int)this,param_3);
          return piVar3;
        }
        piVar3 = FUN_0040a790(this,uVar1,this,(int)param_2 - *(int *)this,param_3);
        return piVar3;
      }
    }
  }
  if (-*(int *)((int)this + 0x10) - 1U <= param_3) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_3 != 0) {
    uVar1 = *(int *)((int)this + 0x10) + param_3;
    bVar2 = FUN_00402190(this,uVar1,'\0');
    if (bVar2) {
      if (*(uint *)((int)this + 0x14) < 0x10) {
        pvVar4 = this;
        pvVar5 = this;
      }
      else {
        pvVar4 = *(void **)this;
        pvVar5 = *(void **)this;
      }
      if (*(size_t *)((int)this + 0x10) != 0) {
        memmove((void *)((int)pvVar4 + param_3),pvVar5,*(size_t *)((int)this + 0x10));
      }
      if (*(uint *)((int)this + 0x14) < 0x10) {
        pvVar5 = this;
      }
      else {
        pvVar5 = *(void **)this;
      }
      if (param_3 != 0) {
        memcpy(pvVar5,param_2,param_3);
      }
      FUN_00402160(this,uVar1);
    }
  }
  return this;
}



// ===== FUN_0040a790 @ 0040a790 =====

int * __thiscall FUN_0040a790(void *this,undefined4 param_1,int *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  
  if ((uint)param_2[4] < param_3) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  uVar2 = param_2[4] - param_3;
  if (uVar2 < param_4) {
    param_4 = uVar2;
  }
  if (-*(int *)((int)this + 0x10) - 1U <= param_4) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (param_4 != 0) {
    uVar2 = *(int *)((int)this + 0x10) + param_4;
    bVar1 = FUN_00402190(this,uVar2,'\0');
    if (bVar1) {
      if (*(uint *)((int)this + 0x14) < 0x10) {
        pvVar3 = this;
        pvVar4 = this;
      }
      else {
        pvVar3 = *(void **)this;
        pvVar4 = *(void **)this;
      }
      if (*(size_t *)((int)this + 0x10) != 0) {
        memmove((void *)(param_4 + (int)pvVar3),pvVar4,*(size_t *)((int)this + 0x10));
      }
      if (this == param_2) {
        if (param_3 != 0) {
          param_3 = param_3 + param_4;
        }
        if (*(uint *)((int)this + 0x14) < 0x10) {
          FUN_00401130(this,(void *)((int)this + param_3),param_4);
        }
        else {
          FUN_00401130(*(void **)this,(void *)(*(int *)this + param_3),param_4);
        }
      }
      else {
        if (0xf < (uint)param_2[5]) {
          param_2 = (int *)*param_2;
        }
        if (*(uint *)((int)this + 0x14) < 0x10) {
          pvVar4 = this;
        }
        else {
          pvVar4 = *(void **)this;
        }
        FUN_00401110(pvVar4,(void *)((int)param_2 + param_3),param_4);
      }
      FUN_00402160(this,uVar2);
    }
  }
  return this;
}



// ===== FUN_0040a8a0 @ 0040a8a0 =====

undefined4 * __thiscall FUN_0040a8a0(void *this,int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041db4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = FUN_0040ac70(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  local_8 = 1;
  if (puVar1 + 4 != (int *)0x0) {
    if ((param_1[1] == 0) || ((char *)*param_1 == (char *)0x0)) {
      iVar2 = *param_1;
    }
    else {
      iVar2 = FUN_00404fd0((char *)*param_1,0xffffffff);
    }
    puVar1[4] = iVar2;
    if (*param_1 == 0) {
      uVar3 = param_1[1];
    }
    else {
      uVar3 = (uint)(param_1[1] != 0);
    }
    puVar1[5] = uVar3;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_004052f0(puVar1 + 6,(char *)(param_1 + 2));
  }
  ExceptionList = local_10;
  return puVar1;
}



// ===== Catch_All@0040a948 @ 0040a948 =====

void Catch_All_0040a948(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_0040a960 @ 0040a960 =====

void __thiscall FUN_0040a960(void *this,undefined4 *param_1,int *param_2,byte *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 uVar5;
  uint uStack_40;
  undefined4 local_30;
  int *local_2c;
  undefined4 *local_28;
  void *local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041db70;
  local_10 = ExceptionList;
  uStack_40 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_14 = (undefined1 *)&uStack_40;
  ExceptionList = &local_10;
  local_8 = 0;
  local_28 = param_1;
  local_20 = param_4;
  local_2c = param_4;
  local_24 = this;
  local_18 = uStack_40;
  if (*(int *)((int)this + 4) == 0) {
    local_14 = (undefined1 *)&uStack_40;
    FUN_0040acb0(this,param_1,'\x01',*(undefined4 **)this,param_4,param_4);
  }
  else {
    piVar1 = *(int **)this;
    if (param_2 == (int *)*piVar1) {
      local_14 = (undefined1 *)&uStack_40;
      bVar3 = FUN_00409940((undefined4 *)param_3,param_2 + 4);
      uVar5 = extraout_ECX;
      if (bVar3) {
        FUN_0040acb0(local_24,param_1,'\x01',param_2,extraout_ECX,local_20);
        goto LAB_0040ab1c;
      }
    }
    else if (param_2 == piVar1) {
      puVar4 = (undefined4 *)piVar1[2];
      local_14 = (undefined1 *)&uStack_40;
      bVar3 = FUN_00409940(puVar4 + 4,(undefined4 *)param_3);
      uVar5 = extraout_ECX_00;
      if (bVar3) {
        FUN_0040acb0(local_24,param_1,'\0',puVar4,extraout_ECX_00,local_20);
        goto LAB_0040ab1c;
      }
    }
    else {
      bVar3 = FUN_00409940((undefined4 *)param_3,param_2 + 4);
      if (bVar3) {
        local_1c = param_2;
        FUN_004099f0((int *)&local_1c);
        piVar2 = local_1c;
        bVar3 = FUN_00409940(local_1c + 4,(undefined4 *)param_3);
        if (bVar3) {
          if (*(char *)(piVar2[2] + 0xd) == '\0') {
            FUN_0040acb0(local_24,local_28,'\x01',param_2,extraout_ECX_01,local_20);
          }
          else {
            FUN_0040acb0(local_24,local_28,'\0',piVar2,extraout_ECX_01,local_20);
          }
          goto LAB_0040ab1c;
        }
      }
      bVar3 = FUN_00409940(param_2 + 4,(undefined4 *)param_3);
      uVar5 = extraout_ECX_02;
      if (bVar3) {
        local_1c = param_2;
        FUN_004099a0((int *)&local_1c);
        piVar2 = local_1c;
        uVar5 = extraout_ECX_03;
        if ((local_1c == piVar1) ||
           (bVar3 = FUN_00409940((undefined4 *)param_3,local_1c + 4), uVar5 = extraout_ECX_04, bVar3)) {
          if (*(char *)(param_2[2] + 0xd) == '\0') {
            FUN_0040acb0(local_24,local_28,'\x01',piVar2,uVar5,local_20);
          }
          else {
            FUN_0040acb0(local_24,local_28,'\0',param_2,uVar5,local_20);
          }
          goto LAB_0040ab1c;
        }
      }
    }
    local_8 = 0xffffffff;
    puVar4 = (undefined4 *)FUN_0040af20(local_24,&local_30,uVar5,param_3,local_20);
    *local_28 = *puVar4;
  }
LAB_0040ab1c:
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== Catch_All@0040aae8 @ 0040aae8 =====

void Catch_All_0040aae8(void)

{
  int unaff_EBP;
  
  FUN_0040ac00(*(void **)(unaff_EBP + -0x28));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_0040ab40 @ 0040ab40 =====

undefined4 * __thiscall FUN_0040ab40(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041dba0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = *(undefined4 **)this;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    puVar1 = FUN_0040a8a0(this,param_1 + 4);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 3);
    local_8 = 0;
    if (*(char *)((int)puVar3 + 0xd) != '\0') {
      puVar3 = puVar1;
    }
    puVar2 = FUN_0040ab40(this,(undefined4 *)*param_1,puVar1,param_3);
    *puVar1 = puVar2;
    puVar2 = FUN_0040ab40(this,(undefined4 *)param_1[2],puVar1,param_3);
    puVar1[2] = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}



// ===== Catch_All@0040abdf @ 0040abdf =====

void Catch_All_0040abdf(void)

{
  int unaff_EBP;
  
  FUN_00409760(*(int **)(unaff_EBP + 0xc));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_0040ac00 @ 0040ac00 =====

void FUN_0040ac00(void *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dbc8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004054d0((undefined4 *)((int)param_1 + 0x18));
  if ((*(void **)((int)param_1 + 0x10) != (void *)0x0) && (*(int *)((int)param_1 + 0x14) == 1)) {
    free(*(void **)((int)param_1 + 0x10));
  }
  operator_delete(param_1);
  ExceptionList = local_10;
  return;
}



// ===== FUN_0040ac70 @ 0040ac70 =====

undefined4 * __fastcall FUN_0040ac70(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x30);
  if (puVar1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  *puVar1 = *param_1;
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}



// ===== FUN_0040acb0 @ 0040acb0 =====

void __thiscall
FUN_0040acb0(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,int *param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dbf8;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  if (0x5555553 < *(uint *)((int)this + 4)) {
    local_8 = 0;
    FUN_004054d0(param_5 + 6);
    local_8 = 0xffffffff;
    if (((void *)param_5[4] != (void *)0x0) && (param_5[5] == 1)) {
      free((void *)param_5[4]);
    }
    operator_delete(param_5);
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  cVar1 = *(char *)(param_5[1] + 0xc);
  piVar4 = param_5;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      *unaff_FS_OFFSET = local_10;
      return;
    }
    piVar6 = (int *)piVar4[1];
    piVar5 = *(int **)piVar6[1];
    if (piVar6 == piVar5) {
      piVar5 = (int *)((undefined4 *)piVar6[1])[2];
      if ((char)piVar5[3] != '\0') {
        if (piVar4 == (int *)piVar6[2]) {
          piVar4 = (int *)piVar6[2];
          piVar6[2] = *piVar4;
          if (*(char *)(*piVar4 + 0xd) == '\0') {
            *(int **)(*piVar4 + 4) = piVar6;
          }
          piVar4[1] = piVar6[1];
          if (piVar6 == *(int **)(*(int *)this + 4)) {
            *(int **)(*(int *)this + 4) = piVar4;
          }
          else {
            piVar5 = (int *)piVar6[1];
            if (piVar6 == (int *)*piVar5) {
              *piVar5 = (int)piVar4;
            }
            else {
              piVar5[2] = (int)piVar4;
            }
          }
          *piVar4 = (int)piVar6;
          piVar6[1] = (int)piVar4;
          piVar4 = piVar6;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar6 = *(int **)(piVar4[1] + 4);
        piVar5 = (int *)*piVar6;
        *piVar6 = piVar5[2];
        if (*(char *)(piVar5[2] + 0xd) == '\0') {
          *(int **)(piVar5[2] + 4) = piVar6;
        }
        piVar5[1] = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int **)(*(int *)this + 4) = piVar5;
          piVar5[2] = (int)piVar6;
        }
        else {
          piVar2 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar2[2]) {
            piVar2[2] = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
          else {
            *piVar2 = (int)piVar5;
            piVar5[2] = (int)piVar6;
          }
        }
        goto LAB_0040aeea;
      }
LAB_0040ae41:
      *(undefined1 *)(piVar6 + 3) = 1;
      *(undefined1 *)(piVar5 + 3) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar4 = *(int **)(piVar4[1] + 4);
    }
    else {
      if ((char)piVar5[3] == '\0') goto LAB_0040ae41;
      if (piVar4 == (int *)*piVar6) {
        iVar3 = *piVar6;
        *piVar6 = *(int *)(iVar3 + 8);
        if (*(char *)(*(int *)(iVar3 + 8) + 0xd) == '\0') {
          *(int **)(*(int *)(iVar3 + 8) + 4) = piVar6;
        }
        *(int *)(iVar3 + 4) = piVar6[1];
        if (piVar6 == *(int **)(*(int *)this + 4)) {
          *(int *)(*(int *)this + 4) = iVar3;
        }
        else {
          piVar4 = (int *)piVar6[1];
          if (piVar6 == (int *)piVar4[2]) {
            piVar4[2] = iVar3;
          }
          else {
            *piVar4 = iVar3;
          }
        }
        *(int **)(iVar3 + 8) = piVar6;
        piVar6[1] = iVar3;
        piVar4 = piVar6;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      piVar6 = *(int **)(piVar4[1] + 4);
      piVar5 = (int *)piVar6[2];
      piVar6[2] = *piVar5;
      if (*(char *)(*piVar5 + 0xd) == '\0') {
        *(int **)(*piVar5 + 4) = piVar6;
      }
      piVar5[1] = piVar6[1];
      if (piVar6 == *(int **)(*(int *)this + 4)) {
        *(int **)(*(int *)this + 4) = piVar5;
      }
      else {
        piVar2 = (int *)piVar6[1];
        if (piVar6 == (int *)*piVar2) {
          *piVar2 = (int)piVar5;
        }
        else {
          piVar2[2] = (int)piVar5;
        }
      }
      *piVar5 = (int)piVar6;
LAB_0040aeea:
      piVar6[1] = (int)piVar5;
    }
    cVar1 = *(char *)(piVar4[1] + 0xc);
  } while( true );
}



// ===== FUN_0040af20 @ 0040af20 =====

void __thiscall FUN_0040af20(void *this,undefined4 *param_1,undefined4 param_2,byte *param_3,int *param_4)

{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  int *piVar7;
  int *unaff_FS_OFFSET;
  bool bVar8;
  uint uStack_40;
  bool local_2c;
  int *local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  undefined1 *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dc28;
  local_10 = *unaff_FS_OFFSET;
  uStack_40 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_14 = (undefined1 *)&uStack_40;
  *unaff_FS_OFFSET = (int)&local_10;
  local_8 = 0;
  piVar2 = *(int **)this;
  local_20 = param_4;
  local_2c = true;
  local_24 = piVar2;
  if (*(char *)(piVar2[1] + 0xd) == '\0') {
    piVar7 = (int *)piVar2[1];
    do {
      local_24 = piVar7;
      if (*(byte **)param_3 == (byte *)0x0) {
        local_2c = *(uint *)(param_3 + 4) < (uint)local_24[5];
      }
      else {
        pbVar6 = (byte *)local_24[4];
        pbVar4 = *(byte **)param_3;
        do {
          bVar1 = *pbVar4;
          bVar8 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_0040afbe:
            local_2c = (int)(-(uint)bVar8 | 1) < 0;
            goto LAB_0040afd6;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar8 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_0040afbe;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        local_2c = false;
      }
LAB_0040afd6:
      if (local_2c == false) {
        piVar7 = (int *)local_24[2];
      }
      else {
        piVar7 = (int *)*local_24;
      }
    } while (*(char *)((int)piVar7 + 0xd) == '\0');
  }
  local_1c = local_24;
  local_18 = uStack_40;
  puVar3 = &uStack_40;
  if (local_2c == false) {
LAB_0040b041:
    local_14 = (undefined1 *)puVar3;
    piVar2 = local_1c;
    pbVar6 = (byte *)local_1c[4];
    if (pbVar6 == (byte *)0x0) {
      bVar8 = (uint)local_1c[5] < *(uint *)(param_3 + 4);
    }
    else {
      param_3 = *(byte **)param_3;
      do {
        bVar1 = *pbVar6;
        bVar8 = bVar1 < *param_3;
        if (bVar1 != *param_3) {
LAB_0040b075:
          bVar8 = (int)(-(uint)bVar8 | 1) < 0;
          goto LAB_0040b08a;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar8 = bVar1 < param_3[1];
        if (bVar1 != param_3[1]) goto LAB_0040b075;
        pbVar6 = pbVar6 + 2;
        param_3 = param_3 + 2;
      } while (bVar1 != 0);
      bVar8 = false;
    }
LAB_0040b08a:
    if (!bVar8) {
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_004054d0(param_4 + 6);
      if (((void *)param_4[4] != (void *)0x0) && (param_4[5] == 1)) {
        free((void *)param_4[4]);
      }
      operator_delete(local_20);
      *param_1 = piVar2;
      *(undefined1 *)(param_1 + 1) = 0;
      goto LAB_0040b016;
    }
    puVar5 = (undefined4 *)FUN_0040acb0(this,&local_20,local_2c,local_24,param_3,param_4);
    *param_1 = *puVar5;
  }
  else {
    if (local_24 != (int *)*piVar2) {
      FUN_004099f0((int *)&local_1c);
      puVar3 = (uint *)local_14;
      goto LAB_0040b041;
    }
    local_14 = (undefined1 *)&uStack_40;
    puVar5 = (undefined4 *)FUN_0040acb0(this,&local_20,'\x01',local_24,local_24,param_4);
    *param_1 = *puVar5;
  }
  *(undefined1 *)(param_1 + 1) = 1;
LAB_0040b016:
  *unaff_FS_OFFSET = local_10;
  FUN_0041c21c(local_18 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== Catch_All@0040b0ea @ 0040b0ea =====

void Catch_All_0040b0ea(void)

{
  int unaff_EBP;
  
  FUN_0040ac00(*(void **)(unaff_EBP + -0x2c));
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_0040b100 @ 0040b100 =====

int * __fastcall FUN_0040b100(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  piVar2 = param_1 + 4;
  do {
    if (param_3 != (int *)0x0) {
      param_3[5] = 0xf;
      param_3[4] = 0;
      *(undefined1 *)param_3 = 0;
      if ((uint)piVar2[1] < 0x10) {
        if (*piVar2 + 1U != 0) {
          memmove(param_3,piVar2 + -4,*piVar2 + 1U);
        }
      }
      else {
        *param_3 = piVar2[-4];
        piVar2[-4] = 0;
      }
      param_3[4] = *piVar2;
      param_3[5] = piVar2[1];
      piVar2[1] = 0xf;
      *piVar2 = 0;
      *(undefined1 *)(piVar2 + -4) = 0;
    }
    param_3 = param_3 + 6;
    piVar1 = piVar2 + 2;
    piVar2 = piVar2 + 6;
  } while (piVar1 != param_2);
  return param_3;
}



// ===== FUN_0040b185 @ 0040b185 =====

void __thiscall FUN_0040b185(void *this,byte param_1)

{
  FUN_00409180((void *)((int)this - *(int *)((int)this + -4)),param_1);
  return;
}



// ===== FUN_0040b190 @ 0040b190 =====

void __fastcall FUN_0040b190(u_short param_1,SOCKET *param_2)

{
  u_short uVar1;
  SOCKET s;
  int iVar2;
  sockaddr local_18;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)((&local_18)[1].sa_data + 2);
  s = socket(2,1,0);
  if (s == 0xffffffff) {
    FUN_0041c21c(local_8 ^ (uint)((&local_18)[1].sa_data + 2));
    return;
  }
  local_18.sa_data[2] = '\0';
  local_18.sa_data[3] = '\0';
  local_18.sa_data[4] = '\0';
  local_18.sa_data[5] = '\0';
  local_18.sa_data[6] = '\0';
  local_18.sa_data[7] = '\0';
  local_18.sa_data[8] = '\0';
  local_18.sa_data[9] = '\0';
  local_18.sa_data[10] = '\0';
  local_18.sa_data[0xb] = '\0';
  local_18.sa_data[0xc] = '\0';
  local_18.sa_data[0xd] = '\0';
  local_18.sa_family = 2;
  local_18.sa_data[0] = '\0';
  local_18.sa_data[1] = '\0';
  local_18.sa_data._2_4_ = htonl(0x7f000001);
  uVar1 = htons(param_1);
  local_18.sa_data[0] = (char)uVar1;
  local_18.sa_data[1] = (char)(uVar1 >> 8);
  iVar2 = connect(s,&local_18,0x10);
  if (iVar2 == -1) {
    array_vpn_logprint(3,"..\\common\\longpoll.cpp",0x15,"failed to connect\n");
    closesocket(s);
    FUN_0041c21c(local_8 ^ (uint)((&local_18)[1].sa_data + 2));
    return;
  }
  *param_2 = s;
  FUN_0041c21c(local_8 ^ (uint)((&local_18)[1].sa_data + 2));
  return;
}



// ===== FUN_0040b260 @ 0040b260 =====

void __fastcall FUN_0040b260(SOCKET param_1,uint param_2)

{
  uint len;
  int iVar1;
  char local_108 [256];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_108 + 0x104);
  while( true ) {
    if (param_2 == 0) {
      FUN_0041c21c(local_8 ^ (uint)(local_108 + 0x104));
      return;
    }
    len = param_2;
    if (0x100 < param_2) {
      len = 0x100;
    }
    iVar1 = recv(param_1,local_108,len,0);
    if (iVar1 < 1) break;
    param_2 = param_2 - iVar1;
  }
  FUN_0041c21c(local_8 ^ (uint)(local_108 + 0x104));
  return;
}



// ===== FUN_0040b2e0 @ 0040b2e0 =====

int __thiscall FUN_0040b2e0(void *this,char *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar7 = (char *)0x0;
  bVar1 = false;
  pcVar6 = (char *)0x3ff;
  *param_3 = 0;
  while( true ) {
    iVar2 = recv((SOCKET)this,param_1 + (int)pcVar7,(int)pcVar6 - (int)pcVar7,0);
    if (iVar2 < 0) {
      piVar5 = _errno();
      array_vpn_logprint(3,"..\\common\\longpoll.cpp",0x51,"read failed, ret: %d, errno: %d\n",iVar2,*piVar5);
      return 0xb;
    }
    if (iVar2 == 0) break;
    if ((!bVar1) && (pcVar3 = strstr(param_1,"\r\n\r\n"), pcVar3 != (char *)0x0)) {
      bVar1 = true;
      pcVar6 = strstr(param_1,"Content-Length:");
      if (pcVar6 == (char *)0x0) {
        array_vpn_logprint(0,"..\\common\\longpoll.cpp",0x22,"http_get_content_length: content length not found\n");
        iVar4 = 0;
      }
      else {
        iVar4 = strtol(pcVar6 + 0xf,(char **)0x0,10);
      }
      pcVar6 = pcVar3 + iVar4 + (4 - (int)param_1);
      array_vpn_logprint(0,"..\\common\\longpoll.cpp",0x5d,"http_get_page: total length: [%u]\n",pcVar6);
      *param_3 = pcVar6;
      if ((char *)0x3ff < pcVar6) {
        array_vpn_logprint(0,"..\\common\\longpoll.cpp",0x61,
                           "http_get_page: buffer too small, buffer length %u, page length %u\n",0x3ff,pcVar6);
        iVar2 = FUN_0040b260((SOCKET)this,(uint)(pcVar6 + (-(int)pcVar7 - iVar2)));
        if (iVar2 == 0) {
          return 0x17;
        }
        array_vpn_logprint(3,"..\\common\\longpoll.cpp",100,"http_get_page: dummy read failed\n");
        return iVar2;
      }
    }
    pcVar7 = pcVar7 + iVar2;
    if (pcVar6 <= pcVar7) {
      *param_3 = pcVar7;
      return 0;
    }
  }
  array_vpn_logprint(3,"..\\common\\longpoll.cpp",0x55,"http_get_page: server close connection\n");
  return 0xc;
}



// ===== FUN_0040b490 @ 0040b490 =====

undefined4 FUN_0040b490(void)

{
  printf("LongPollClient::OnLongPollMsg\n");
  return 0;
}



// ===== FUN_0040b4b0 @ 0040b4b0 =====

void __cdecl FUN_0040b4b0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 extraout_ECX;
  uint uVar6;
  int *piVar7;
  undefined4 ****ppppuVar8;
  int *piVar9;
  undefined1 auStack_4e8 [7];
  char local_4e1;
  undefined4 *local_4e0;
  uint local_4dc;
  void *local_4d8 [4];
  undefined4 local_4c8;
  uint local_4c4;
  undefined4 local_4c0;
  undefined4 uStack_4bc;
  undefined4 uStack_4b8;
  undefined4 uStack_4b4;
  undefined8 local_4b0;
  undefined4 local_4a0 [10];
  undefined4 ****local_478 [4];
  int local_468;
  uint local_464;
  char local_428 [1028];
  uint local_24;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0041dc71;
  local_1c = ExceptionList;
  local_24 = DAT_00428000 ^ (uint)auStack_4e8;
  ExceptionList = &local_1c;
  local_4e0 = param_1;
  memset(local_4a0,0,0x74);
  FUN_00402770(local_4a0);
  local_4c0 = 0;
  uStack_4bc = 0;
  uStack_4b4 = 0;
  uStack_4b8 = 0;
  local_4b0 = 0;
  local_14 = 2;
  iVar3 = FUN_0040b190(*(u_short *)(param_1 + 7),param_1 + 10);
  puVar2 = local_4e0;
  if (iVar3 == 0) {
    do {
      do {
        do {
          memset(local_428,0,0x400);
          if ((uint)puVar2[6] < 0x10) {
            puVar4 = puVar2 + 1;
          }
          else {
            puVar4 = (undefined4 *)puVar2[1];
          }
          _snprintf(local_428,0x3ff,"GET /channel/vpn?sender=%s HTTP/1.1\r\nHost:127.0.0.1\r\n\r\n",puVar4);
          puVar4 = local_4e0;
          pcVar5 = local_428;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar3 = send(local_4e0[10],local_428,(int)pcVar5 - (int)(local_428 + 1),0);
          if ((iVar3 < 1) || (iVar3 = FUN_0040b2e0((void *)puVar4[10],local_428,extraout_ECX,&local_4dc), iVar3 != 0))
          goto LAB_0040b734;
          if (0x3ff < local_4dc) {
            ___report_rangecheckfailure();
            goto LAB_0040b734;
          }
          local_428[local_4dc] = '\0';
          pcVar5 = strstr(local_428,"\r\n\r\n");
          piVar9 = (int *)(pcVar5 + 4);
        } while (piVar9 == (int *)0x0);
        local_4c4 = 0xf;
        local_4c8 = 0;
        local_4d8[0] = (void *)((uint)local_4d8[0] & 0xffffff00);
        if ((char)*piVar9 == '\0') {
          uVar6 = 0;
        }
        else {
          piVar7 = piVar9;
          do {
            iVar3 = *piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
          } while ((char)iVar3 != '\0');
          uVar6 = (int)piVar7 - (int)(pcVar5 + 5);
        }
        FUN_00401f80(local_4d8,piVar9,uVar6);
        local_14._0_1_ = 3;
        FUN_00401e50(local_478,(int *)local_4d8,0,0xffffffff);
        ppppuVar8 = local_478;
        if (0xf < local_464) {
          ppppuVar8 = local_478[0];
        }
        local_4e1 = FUN_004028c0(local_4a0,ppppuVar8,local_468 + (int)ppppuVar8,&local_4c0);
        local_14 = CONCAT31(local_14._1_3_,2);
        if (0xf < local_4c4) {
          operator_delete(local_4d8[0]);
        }
      } while (local_4e1 == '\0');
      printf("pull msg, got [%s]\n",piVar9);
      iVar3 = (**(code **)*local_4e0)(&local_4c0);
    } while (iVar3 != 2);
LAB_0040b734:
    puVar2 = local_4e0;
    if (local_4e0[10] != 0xffffffff) {
      closesocket(local_4e0[10]);
      puVar2[10] = 0xffffffff;
    }
  }
  else {
    *(undefined1 *)(local_4e0 + 0xb) = 0;
  }
  local_14 = local_14 & 0xffffff00;
  FUN_004054d0(&local_4c0);
  FUN_00404f50(local_4a0);
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)auStack_4e8);
  return;
}



// ===== FUN_0040b790 @ 0040b790 =====

void __thiscall FUN_0040b790(void *this,undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  SOCKET local_414;
  char local_410 [1028];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  local_410[0] = '\0';
  memset(local_410 + 1,0,0x3ff);
  if (*(char *)((int)this + 0x2c) == '\0') {
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  iVar2 = FUN_0040b190(*(u_short *)((int)this + 0x1c),&local_414);
  if (iVar2 == 0) {
    memset(local_410,0,0x400);
    if ((uint)param_1[5] < 0x10) {
      puVar3 = param_1;
    }
    else {
      puVar3 = (undefined4 *)*param_1;
    }
    _snprintf(local_410,0x3ff,
              "POST /channel/vpn HTTP/1.1\r\nContent-Type: application/jsonHost:127.0.0.1\r\nContent-Length:%lu\r\n\r\n%s"
              ,param_1[4],puVar3);
    pcVar4 = local_410;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    send(local_414,local_410,(int)pcVar4 - (int)(local_410 + 1),0);
    if (local_414 != 0xffffffff) {
      closesocket(local_414);
    }
  }
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_0040b890 @ 0040b890 =====

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0040b890(void)

{
  undefined1 auStack_24 [32];
  
  FUN_0041c21c(DAT_00428000 ^ (uint)(auStack_24 + 0x20) ^ (uint)(auStack_24 + 0x20));
  return;
}



// ===== FUN_0040b940 @ 0040b940 =====

BSTR __fastcall FUN_0040b940(LPCSTR param_1)

{
  int cchWideChar;
  BSTR lpWideCharStr;
  int iVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    return (BSTR)0x0;
  }
  cchWideChar = MultiByteToWideChar(3,0,param_1,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,cchWideChar - 1);
  if (lpWideCharStr != (BSTR)0x0) {
    iVar1 = MultiByteToWideChar(3,0,param_1,-1,lpWideCharStr,cchWideChar);
    if (iVar1 != cchWideChar) {
      SysFreeString(lpWideCharStr);
      lpWideCharStr = (BSTR)0x0;
    }
  }
  return lpWideCharStr;
}



// ===== FUN_0040b9a0 @ 0040b9a0 =====

void FUN_0040b9a0(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&param_1,(ThrowInfo *)&DAT_004266b8);
}



// ===== FUN_0040b9c0 @ 0040b9c0 =====

void FUN_0040b9c0(void)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (0 < (int)DVar1) {
    DVar1 = DVar1 & 0xffff | 0x80070000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0040b9a0(DVar1);
}



// ===== FUN_0040b9e0 @ 0040b9e0 =====

uint __fastcall FUN_0040b9e0(LPCRITICAL_SECTION param_1)

{
  BOOL BVar1;
  uint uVar2;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,0);
  if (BVar1 == 0) {
    uVar2 = GetLastError();
    if (0 < (int)uVar2) {
      return uVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// ===== FUN_0040ba10 @ 0040ba10 =====

undefined4 * __thiscall FUN_0040ba10(void *this,LPCSTR param_1)

{
  BSTR pOVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    pOVar1 = FUN_0040b940(param_1);
    *(BSTR *)this = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
  }
  return this;
}



// ===== FUN_0040ba50 @ 0040ba50 =====

void __fastcall FUN_0040ba50(undefined4 *param_1)

{
  SysFreeString((BSTR)*param_1);
  return;
}



// ===== FUN_0040ba60 @ 0040ba60 =====

void __fastcall FUN_0040ba60(VARIANTARG *param_1)

{
  VariantClear(param_1);
  return;
}



// ===== FUN_0040ba70 @ 0040ba70 =====

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_0040ba70(void *this,LPCSTR param_1)

{
  char *pcVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  HRESULT HVar5;
  undefined4 *_Memory;
  int iVar6;
  OLECHAR *psz;
  BSTR pOVar7;
  LPCSTR pCVar8;
  undefined4 *puVar9;
  uint local_38;
  LPWSTR local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dca8;
  local_10 = ExceptionList;
  uVar4 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  puVar9 = (undefined4 *)0x0;
  local_8 = 0;
  local_38 = uVar4;
  HVar5 = VariantClear(this);
  if (HVar5 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(HVar5);
  }
  *(undefined2 *)this = 8;
  if (param_1 != (LPCSTR)0x0) {
    pCVar8 = param_1;
    do {
      cVar3 = *pCVar8;
      pCVar8 = pCVar8 + 1;
    } while (cVar3 != '\0');
    pcVar1 = pCVar8 + (1 - (int)(param_1 + 1));
    uVar2 = (int)pcVar1 * 2;
    if ((((int)pcVar1 >> 0x1f) << 1 | (uint)pcVar1 >> 0x1f) + (uint)(0x7fffffff < uVar2) == 0) {
      if (((int)uVar2 < 0x401) && (cVar3 = FUN_0040b890(), cVar3 != '\0')) {
        local_20 = (LPWSTR)&local_38;
        _Memory = puVar9;
      }
      else {
        if ((int)pcVar1 * -2 - 1U < 8) {
                    /* WARNING: Subroutine does not return */
          FUN_0040b9a0(0x80070216);
        }
        _Memory = malloc(uVar2 + 8);
        if (_Memory == (undefined4 *)0x0) goto LAB_0040bb7d;
        *_Memory = 0;
        local_20 = (LPWSTR)(_Memory + 2);
      }
      puVar9 = _Memory;
      if (local_20 != (LPWSTR)0x0) {
        *local_20 = L'\0';
        iVar6 = MultiByteToWideChar(3,0,param_1,-1,local_20,(uint)pcVar1 & 0x7fffffff);
        psz = (OLECHAR *)(-(uint)(iVar6 != 0) & (uint)local_20);
        goto LAB_0040bb7f;
      }
    }
  }
LAB_0040bb7d:
  _Memory = puVar9;
  psz = (OLECHAR *)0x0;
LAB_0040bb7f:
  pOVar7 = SysAllocString(psz);
  *(BSTR *)((int)this + 8) = pOVar7;
  if ((pOVar7 == (BSTR)0x0) && (param_1 != (LPCSTR)0x0)) {
    *(undefined4 *)((int)this + 8) = 0x8007000e;
    *(undefined2 *)this = 10;
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  while (_Memory != (undefined4 *)0x0) {
    puVar9 = (undefined4 *)*_Memory;
    free(_Memory);
    _Memory = puVar9;
  }
  ExceptionList = local_10;
  FUN_0041c21c(uVar4 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040bbf0 @ 0040bbf0 =====

void __thiscall FUN_0040bbf0(void *this,int param_1,VARIANTARG *param_2)

{
  HRESULT HVar1;
  LONG local_10;
  LONG local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_c = 0;
  HVar1 = SafeArrayGetLBound(*(SAFEARRAY **)this,1,&local_c);
  if (HVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(HVar1);
  }
  if (local_c <= param_1) {
    local_10 = 0;
    HVar1 = SafeArrayGetUBound(*(SAFEARRAY **)this,1,&local_10);
    if (HVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(HVar1);
    }
    if (param_1 <= local_10) {
      VariantCopyInd((VARIANT *)((param_1 - local_c) * 0x10 + *(int *)(*(int *)this + 0xc)),param_2);
      FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
      return;
    }
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040bca0 @ 0040bca0 =====

void FUN_0040bca0(void)

{
  HMODULE hModule;
  int iVar1;
  char *lpProcName;
  undefined4 local_124;
  undefined1 local_120 [280];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_120 + 0x11c);
  memset(local_120,0,0x118);
  local_124 = 0x11c;
  if ((DAT_0042e400 & 1) == 0) {
    lpProcName = "RtlGetVersion";
    DAT_0042e400 = DAT_0042e400 | 1;
    hModule = GetModuleHandleW(L"ntdll.dll");
    DAT_0042e404 = GetProcAddress(hModule,lpProcName);
  }
  if ((DAT_0042e404 == (FARPROC)0x0) || (iVar1 = (*DAT_0042e404)(&local_124), iVar1 != 0)) {
    FUN_0041c21c(local_8 ^ (uint)(local_120 + 0x11c));
    return;
  }
  FUN_0041c21c(local_8 ^ (uint)(local_120 + 0x11c));
  return;
}



// ===== FUN_0040bd50 @ 0040bd50 =====

void FUN_0040bd50(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 local_210;
  int local_20c;
  char local_208;
  undefined1 local_207 [255];
  char local_108;
  undefined1 local_107 [255];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_107 + 0x103);
  local_210 = 0;
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","status",4,&local_210,4);
  array_vpn_logprint(1,"route.cpp",0x14a,"AddDefaultRoute: vsite:%s, vsitev6:%s\n",&DAT_00428790,&DAT_004296f8);
  local_108 = '\0';
  memset(local_107,0,0xff);
  local_208 = '\0';
  memset(local_207,0,0xff);
  local_20c = 0;
  array_vpn_get_proxy(&local_20c,0);
  pcVar2 = &DAT_00428790;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (pcVar2 != &DAT_00428791) {
    pcVar2 = &DAT_004294f0;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != &DAT_004294f1) {
      array_vpn_logprint(1,"route.cpp",0x152,"add default route: v4 site\n");
      if (local_20c == 0) {
        FUN_00414930(&local_108,"route add %s MASK 255.255.255.255 %s METRIC 1",-0x70);
        FUN_00414930(&local_208,"%s",-0x70);
      }
      else {
        FUN_00414930(&local_108,"route add %d.%d.%d.%d MASK 255.255.255.255 %s METRIC 1",(char)local_20c);
        FUN_00414930(&local_208,"%d.%d.%d.%d",(char)local_20c);
      }
      goto LAB_0040bf7a;
    }
  }
  pcVar2 = &DAT_004296f8;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (pcVar2 != &DAT_004296f9) {
    pcVar2 = &DAT_004293f0;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar2 != &DAT_004293f1) {
      array_vpn_logprint(1,"route.cpp",0x15c,"add default route: v6 site\n");
      FUN_00414930(&local_108,"route -6 add %s/128 %s METRIC 1",-8);
      FUN_00414930(&local_208,"%s/128",-8);
      goto LAB_0040bf7a;
    }
  }
  array_vpn_logprint(1,"route.cpp",0x161,"add default route: parameter is invalid\n");
LAB_0040bf7a:
  array_vpn_logprint(1,"route.cpp",0x166,"AddDefaultRoute: %s\n",&local_108);
  FUN_0040c040(1,&local_108);
  FUN_0040d290((int)&local_208);
  FUN_0041c21c(local_8 ^ (uint)(local_107 + 0x103));
  return;
}



// ===== FUN_0040bfd0 @ 0040bfd0 =====

bool FUN_0040bfd0(void)

{
  HANDLE hObject;
  int iVar1;
  
  hObject = (HANDLE)FUN_00412e50("ArrayWGClient.exe");
  if (hObject == (HANDLE)0x0) {
    iVar1 = FUN_0040c040(0xb,"ArrayWGClient.exe");
    return iVar1 == 0;
  }
  CloseHandle(hObject);
  return true;
}



// ===== FUN_0040c000 @ 0040c000 =====

bool FUN_0040c000(void)

{
  HANDLE hObject;
  int iVar1;
  
  if (DAT_004296b4 == 0) {
    hObject = (HANDLE)FUN_00412e50("ArrayWGClient.exe");
    if (hObject == (HANDLE)0x0) {
      iVar1 = FUN_0040c040(0xb,"ArrayWGClient.exe");
      return iVar1 == 0;
    }
    CloseHandle(hObject);
  }
  return true;
}



// ===== FUN_0040c040 @ 0040c040 =====

void __fastcall FUN_0040c040(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  HRESULT HVar2;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dcd8;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar1;
  HVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
  if (HVar2 != 0) {
    if (HVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      HVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
    }
    if (HVar2 != 0) goto LAB_0040c0da;
  }
  (**(code **)(*local_18 + 0x6c))(local_18,param_1,param_2,uVar1);
LAB_0040c0da:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040c110 @ 0040c110 =====

void __fastcall FUN_0040c110(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



// ===== FUN_0040c120 @ 0040c120 =====

void FUN_0040c120(void)

{
  LSTATUS LVar1;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  if (DAT_0042e288 != 0) {
    FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
    return;
  }
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","VPNRealConnected",local_14,local_14 + 2,local_14 + 1);
  if ((LVar1 == 0) && (local_14[2] == 1)) {
    array_vpn_logprint(1,"route.cpp",0x1a6,"IsEnableVPNRealConnected:user enable vpn real connected.\n");
  }
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_0040c1c0 @ 0040c1c0 =====

void FUN_0040c1c0(void)

{
  int *piVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041dd38;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  array_vpn_logprint(1,"route.cpp",0x1bf,"This is vpnd, set MP status:%d\n",1,local_14);
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
    }
    if (iVar2 != 0) goto LAB_0040c37a;
  }
  piVar1 = local_18;
  pOVar3 = SysAllocString(L"");
  if (pOVar3 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 1;
  pOVar4 = FUN_0040b940("MPStatus");
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 2;
  pOVar5 = FUN_0040b940("SOFTWARE\\VPN\\VPN2");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,4,pOVar5,pOVar4,pOVar3,1);
  SysFreeString(pOVar5);
  SysFreeString(pOVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar3);
  piVar1 = local_18;
  pOVar3 = SysAllocString(L"");
  if (pOVar3 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 4;
  pOVar4 = FUN_0040b940("MPStatus");
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 5;
  pOVar5 = FUN_0040b940("SOFTWARE\\Wow6432Node\\VPN\\VPN2");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,4,pOVar5,pOVar4,pOVar3,1);
  SysFreeString(pOVar5);
  SysFreeString(pOVar4);
  SysFreeString(pOVar3);
LAB_0040c37a:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040c3b0 @ 0040c3b0 =====

void __cdecl FUN_0040c3b0(char *param_1)

{
  undefined1 *puVar1;
  SAFEARRAY *pSVar2;
  SAFEARRAY *pSVar3;
  SAFEARRAY *pSVar4;
  LPSTR pCVar5;
  int iVar6;
  BSTR lpWideCharStr;
  BSTR lpWideCharStr_00;
  char *pcVar7;
  uint uVar8;
  code *pcVar9;
  char cVar10;
  undefined1 auStack_6e4 [4];
  BSTR local_6e0;
  undefined1 local_6d9;
  _union_2683 local_6d8;
  int *local_6c8;
  BSTR local_6c4;
  _union_2683 local_6c0;
  _union_2683 local_6b0;
  _union_2683 local_6a0;
  _union_2683 local_690;
  SAFEARRAY *local_67c;
  undefined4 local_678;
  undefined4 local_674;
  SAFEARRAY *local_670;
  SAFEARRAY *local_66c;
  int *local_668;
  SAFEARRAY *local_664;
  char local_660 [64];
  char local_620;
  undefined1 local_61f [255];
  undefined1 local_520;
  undefined1 local_51f [255];
  char local_420;
  undefined1 local_41f [511];
  char local_220;
  undefined1 local_21f [515];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0041dde4;
  local_14 = ExceptionList;
  local_1c = DAT_00428000 ^ (uint)auStack_6e4;
  ExceptionList = &local_14;
  local_420 = '\0';
  memset(local_41f,0,0x1ff);
  local_620 = '\0';
  memset(local_61f,0,0xff);
  local_220 = '\0';
  memset(local_21f,0,0x1ff);
  local_660[0] = '\0';
  memset(local_660 + 1,0,0x3f);
  local_678 = 0;
  local_520 = 0;
  memset(local_51f,0,0xff);
  pcVar9 = array_vpn_logprint_exref;
  array_vpn_logprint(1,"route.cpp",0x1e0,
                     "adapter_config_thread: start *******************************************************************\n"
                    );
  array_vpn_get_server_port(&DAT_0042e3e4);
  array_vpn_get_local_ip(&local_678,&local_520,0x100);
  if ((param_1[500] & 2U) != 0) {
    array_vpn_logprint(1,"route.cpp",0x1e7,"client subnet: enable\n");
  }
  FUN_00414950(local_660,"%d.%d.%d.%d",*param_1);
  pcVar7 = local_660;
  do {
    cVar10 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar10 != '\0');
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","virtualip",1,local_660,
              (DWORD)(pcVar7 + (1 - (int)(local_660 + 1))));
  local_674 = 0;
  array_vpn_get_proxy(&local_674,0);
  local_6d9 = 1;
  if ((*(uint *)(param_1 + 0x1f0) & 0x20000000) == 0) {
    array_vpn_logprint(1,"route.cpp",0x1f8,"vpnd: AG server enable dnsproxy\n");
  }
  else {
    array_vpn_logprint(1,"route.cpp",499,"vpnd: AG server disable dnsproxy\n");
    local_6d9 = 0;
  }
  FUN_00413540();
  local_67c = (SAFEARRAY *)0x41f7a4;
  if (*(int *)(param_1 + 0x20c) == 0) {
    ntohs(DAT_0042e3e4);
    FUN_00414970(&local_420,
                 "virtualip=%d.%d.%d.%d@virtualmask=%d.%d.%d.%d@virtualgateway=%d.%d.%d.%d@wireguard=%d@vsiteip=%s@vsitedomain=%s@vsiteport=%d@localip=%d.%d.%d.%d@localaccess=%s@dnsproxy=%s@proxyip=%d.%d.%d.%d@insideproxytype=-1@insideproxyserver=@"
                 ,*param_1);
  }
  else {
    ntohs(DAT_0042e3e4);
    FUN_00414970(&local_420,
                 "virtualip=%d.%d.%d.%d@virtualmask=%d.%d.%d.%d@virtualgateway=%d.%d.%d.%d@wireguard=%d@vsiteip=%s@vsitedomain=%s@vsiteport=%d@localip=%d.%d.%d.%d@localaccess=%s@dnsproxy=%s@proxyip=%d.%d.%d.%d@insideproxytype=%d@insideproxyserver=%s@"
                 ,*param_1);
  }
  if (*(int *)(param_1 + 0x1ec) != 0) {
    FUN_00414970(&local_220,"%s",(char)*(int *)(param_1 + 0x1ec));
  }
  local_670 = (SAFEARRAY *)0x0;
  local_664 = (SAFEARRAY *)0x0;
  local_66c = (SAFEARRAY *)0x0;
  local_67c = (SAFEARRAY *)0x0;
  local_c = 3;
  FUN_00414300((int *)&local_670);
  FUN_00414300((int *)&local_664);
  FUN_00414300((int *)&local_66c);
  FUN_00414300((int *)&local_67c);
  if (param_1[0x1a8] != '\0') {
    memset(&local_620,0,0x100);
    cVar10 = '\x01';
    array_vpn_logprint(1,"route.cpp",0x21f,"Include Zone:ip=0.0.0.0, mask=0.0.0.0, this is full tunnel\n");
    FUN_00414930(&local_620,"virip=0.0.0.0@mask=0.0.0.0",cVar10);
    local_6d8.n2.vt = 0;
    FUN_0040ba70(&local_6d8,&local_620);
    local_c._0_1_ = 4;
    FUN_00414210(&local_670,(VARIANTARG *)&local_6d8.n2);
    local_c = CONCAT31(local_c._1_3_,3);
    VariantClear((VARIANTARG *)&local_6d8.n2);
  }
  local_6e0 = (BSTR)0x0;
  if (*(int *)(param_1 + 0x1ac) != 0) {
    uVar8 = 0;
    do {
      memset(&local_620,0,0x100);
      FUN_00414930(&local_620,"virip=%d.%d.%d.%d@mask=%d.%d.%d.%d",*(char *)(*(int *)(param_1 + 0x1b4) + uVar8 * 8));
      local_6d8.n2.vt = 0;
      FUN_0040ba70(&local_6d8,&local_620);
      local_c._0_1_ = 5;
      FUN_00414210(&local_670,(VARIANTARG *)&local_6d8.n2);
      local_c = CONCAT31(local_c._1_3_,3);
      VariantClear((VARIANTARG *)&local_6d8.n2);
      uVar8 = uVar8 + 1;
      local_6e0 = (BSTR)((int)local_6e0 + 1);
    } while (uVar8 < *(uint *)(param_1 + 0x1ac));
    pcVar9 = array_vpn_logprint_exref;
  }
  (*pcVar9)(1,"route.cpp",0x22b,"Include Zone: number: %d\n",local_6e0);
  local_6e0 = (BSTR)0x0;
  if (*(int *)(param_1 + 0x1bc) != 0) {
    uVar8 = 0;
    do {
      memset(&local_620,0,0x100);
      FUN_00414930(&local_620,"virip=%d.%d.%d.%d@mask=%d.%d.%d.%d",*(char *)(*(int *)(param_1 + 0x1c4) + uVar8 * 8));
      local_6d8.n2.vt = 0;
      FUN_0040ba70(&local_6d8,&local_620);
      local_c._0_1_ = 6;
      FUN_00414210(&local_664,(VARIANTARG *)&local_6d8.n2);
      local_c = CONCAT31(local_c._1_3_,3);
      VariantClear((VARIANTARG *)&local_6d8.n2);
      uVar8 = uVar8 + 1;
      local_6e0 = (BSTR)((int)local_6e0 + 1);
    } while (uVar8 < *(uint *)(param_1 + 0x1bc));
    pcVar9 = array_vpn_logprint_exref;
  }
  (*pcVar9)(1,"route.cpp",0x235,"Exclude Zone: number: %d\n",local_6e0);
  if (*(int *)(param_1 + 0x1cc) != 0) {
    uVar8 = 0;
    do {
      memset(&local_620,0,0x100);
      puVar1 = (undefined1 *)(*(int *)(param_1 + 0x1d4) + uVar8 * 4);
      (*pcVar9)(1,"route.cpp",0x23a,"DNS list:ip=%d.%d.%d.%d\n",*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      FUN_00414930(&local_620,"%d.%d.%d.%d",*(char *)(*(int *)(param_1 + 0x1d4) + uVar8 * 4));
      pCVar5 = StrStrIA(&local_620,"127.0.0.");
      if (pCVar5 == (LPSTR)0x0) {
        (*pcVar9)(1,"route.cpp",0x23e,"add dns to VPNService:%s\n",&local_620);
        local_6d8.n2.vt = 0;
        FUN_0040ba70(&local_6d8,&local_620);
        local_c._0_1_ = 7;
        FUN_00414210(&local_66c,(VARIANTARG *)&local_6d8.n2);
        local_c = CONCAT31(local_c._1_3_,3);
        VariantClear((VARIANTARG *)&local_6d8.n2);
      }
      else {
        (*pcVar9)(1,"route.cpp",0x243,"No need add dns 127.0.0.x\n");
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 0x1cc));
  }
  uVar8 = 0;
  if (*(int *)(param_1 + 0x1dc) != 0) {
    do {
      memset(&local_620,0,0x100);
      puVar1 = *(undefined1 **)(*(int *)(param_1 + 0x1e4) + uVar8 * 4);
      (*pcVar9)(1,"route.cpp",0x24a,"Hostmap:host=%s, ip=%d.%d.%d.%d\n",puVar1 + 4,*puVar1,puVar1[1],puVar1[2],puVar1[3]
               );
      FUN_00414930(&local_620,"host=%s@ip=%d.%d.%d.%d",
                   (char)*(undefined4 *)(*(int *)(param_1 + 0x1e4) + uVar8 * 4) + '\x04');
      local_6d8.n2.vt = 0;
      FUN_0040ba70(&local_6d8,&local_620);
      local_c._0_1_ = 8;
      FUN_00414210(&local_67c,(VARIANTARG *)&local_6d8.n2);
      local_c = CONCAT31(local_c._1_3_,3);
      VariantClear((VARIANTARG *)&local_6d8.n2);
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 0x1dc));
  }
  FUN_00413300(3,0x19,0);
  VariantInit((VARIANTARG *)&local_6b0.n2);
  VariantInit((VARIANTARG *)&local_6c0.n2);
  VariantInit((VARIANTARG *)&local_6a0.n2);
  VariantInit((VARIANTARG *)&local_690.n2);
  pSVar2 = local_670;
  SafeArrayUnlock(local_670);
  pSVar4 = local_664;
  local_6b0._8_4_ = pSVar2;
  local_670 = (SAFEARRAY *)0x0;
  local_6b0.n2.vt = 0x200c;
  SafeArrayUnlock(local_664);
  pSVar3 = local_66c;
  local_6c0._8_4_ = pSVar4;
  local_664 = (SAFEARRAY *)0x0;
  local_6c0.n2.vt = 0x200c;
  SafeArrayUnlock(local_66c);
  pSVar2 = local_67c;
  local_6a0._8_4_ = pSVar3;
  local_66c = (SAFEARRAY *)0x0;
  local_6a0.n2.vt = 0x200c;
  SafeArrayUnlock(local_67c);
  local_67c = (SAFEARRAY *)0x0;
  local_690.n2.vt = 0x200c;
  local_690._8_4_ = pSVar2;
  FUN_0040c1c0();
  local_668 = (int *)0x0;
  local_c = CONCAT31(local_c._1_3_,9);
  iVar6 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_668);
  if (iVar6 != 0) {
    if (iVar6 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar6 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_668);
    }
    if (iVar6 != 0) goto LAB_0040cf09;
  }
  (*pcVar9)(1,"route.cpp",0x276,"start call interface ConfigAdapterForMotionPro\n");
  local_6c8 = local_668;
  local_6e0 = (BSTR)MultiByteToWideChar(3,0,&local_220,-1,(LPWSTR)0x0,0);
  lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,(int)local_6e0 - 1);
  if ((lpWideCharStr != (BSTR)0x0) &&
     (iVar6 = MultiByteToWideChar(3,0,&local_220,-1,lpWideCharStr,(int)local_6e0), (BSTR)iVar6 != local_6e0)) {
    SysFreeString(lpWideCharStr);
    lpWideCharStr = (BSTR)0x0;
  }
  local_6c4 = lpWideCharStr;
  if (lpWideCharStr == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_c = CONCAT31(local_c._1_3_,10);
  local_6e0 = (BSTR)MultiByteToWideChar(3,0,&local_420,-1,(LPWSTR)0x0,0);
  lpWideCharStr_00 = SysAllocStringLen((OLECHAR *)0x0,(int)local_6e0 - 1);
  if ((lpWideCharStr_00 != (BSTR)0x0) &&
     (iVar6 = MultiByteToWideChar(3,0,&local_420,-1,lpWideCharStr_00,(int)local_6e0), (BSTR)iVar6 != local_6e0)) {
    SysFreeString(lpWideCharStr_00);
    lpWideCharStr_00 = (BSTR)0x0;
  }
  local_6e0 = lpWideCharStr_00;
  if (lpWideCharStr_00 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_c = CONCAT31(local_c._1_3_,0xb);
  (**(code **)(*local_6c8 + 0xb8))(local_6c8,lpWideCharStr_00,lpWideCharStr,&local_6a0,&local_690,&local_6b0,&local_6c0)
  ;
  SysFreeString(lpWideCharStr_00);
  SysFreeString(lpWideCharStr);
LAB_0040cf09:
  if (DAT_0042e288 == 0) {
    FUN_00413300(2,0x19,1);
  }
  (*pcVar9)(1,"route.cpp",0x27e,
            "adapter_config_thread: finished *******************************************************************\n");
  _endthread();
  local_c = CONCAT31(local_c._1_3_,3);
  if (local_668 != (int *)0x0) {
    (**(code **)(*local_668 + 8))(local_668);
  }
  ExceptionList = local_14;
  FUN_0041c21c(local_1c ^ (uint)auStack_6e4);
  return;
}



// ===== FUN_0040cf80 @ 0040cf80 =====

void FUN_0040cf80(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_c = 0;
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","MPWebNoSession",4,&local_c,4);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040cfd0 @ 0040cfd0 =====

void __fastcall FUN_0040cfd0(undefined4 param_1,int param_2)

{
  char *pcVar1;
  LSTATUS LVar2;
  int iVar3;
  DWORD local_14 [3];
  DWORD local_8;
  
  pcVar1 = DAT_0042e294;
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  if (DAT_0042e288 == 0) {
    memset(&DAT_0042dd00,0,0x588);
    local_14[1] = 4;
    local_14[2] = 0;
    local_14[0] = 4;
    LVar2 = SHGetValueA((HKEY)0x80000002,"Software\\VPN\\VPN2","ProxyScriptNoRewrite",local_14 + 1,local_14 + 2,local_14
                       );
    if ((LVar2 == 0) && (local_14[2] == 1)) {
      array_vpn_logprint(1,"route.cpp",0x29d,"release_config: ProxyScriptNoRewrite is 1, no need resume proxy script.\n"
                         ,1);
    }
    else {
      local_14[1] = 4;
      local_14[2] = 0;
      local_14[0] = 4;
      LVar2 = SHGetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","SetInsideProxy",local_14 + 1,local_14 + 2,local_14);
      if ((LVar2 == 0) && ((local_14[2] == 1 || (local_14[2] == 2)))) {
        array_vpn_logprint(1,"route.cpp",0x2a5,"release_config: Get inside proxy flag:%d, ret:%d\n",local_14[2],0);
        FUN_0040f270(pcVar1);
        SHDeleteValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","SetInsideProxy");
        FUN_004131f0();
      }
      else {
        FUN_0040f990();
      }
    }
  }
  else {
    iVar3 = 5;
    if (param_2 == 0) {
      iVar3 = 2;
    }
    FUN_004108f0(iVar3,(BSTR)0x0,2);
    memset(&DAT_0042dd00,0,0x588);
  }
  _beginthread(FUN_0040d150,0,(void *)0x0);
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_0040d150 @ 0040d150 =====

void FUN_0040d150(void)

{
  uint uVar1;
  int iVar2;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041de28;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_14 = uVar1;
  array_vpn_logprint(1,"route.cpp",0x2b4,
                     "release_config_thread: start *******************************************************************\n"
                     ,uVar1);
  if (DAT_0042e288 != 1) {
    FUN_00413300(1,0x19,0);
  }
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
    }
    if (iVar2 != 0) goto LAB_0040d229;
  }
  array_vpn_logprint(1,"route.cpp",0x2c7,"start call interface ReleaseAdapterForMotionPro\n",uVar1);
  (**(code **)(*local_18 + 0xbc))(local_18);
LAB_0040d229:
  SHDeleteValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","virtualip");
  FUN_0040d3e0();
  array_vpn_logprint(1,"route.cpp",0x2cd,
                     "release_config_thread: finished *******************************************************************\n"
                    );
  _endthread();
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040d290 @ 0040d290 =====

void __fastcall FUN_0040d290(int param_1)

{
  char cVar1;
  LSTATUS LVar2;
  char *pcVar3;
  DWORD local_c10 [2];
  char local_c08 [2048];
  char local_408 [1024];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_408 + 0x404);
  if (param_1 == 0) goto LAB_0040d3c8;
  local_408[0] = '\0';
  memset(local_408 + 1,0,0x3ff);
  local_c08[0] = '\0';
  memset(local_c08 + 1,0,0x7ff);
  local_c10[0] = 0x400;
  local_c10[1] = 1;
  LVar2 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","routelist",local_c10 + 1,local_408,local_c10);
  if (LVar2 == 0) {
    pcVar3 = local_408;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (pcVar3 == local_408 + 1) goto LAB_0040d359;
    FUN_00414990(local_c08,"%s;%s",(char)local_408);
  }
  else {
LAB_0040d359:
    FUN_00414990(local_c08,"%s",(char)param_1);
  }
  pcVar3 = local_c08;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  LVar2 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","routelist",1,local_c08,
                      (DWORD)(pcVar3 + (1 - (int)(local_c08 + 1))));
  if (LVar2 != 0) {
    array_vpn_logprint(1,"route.cpp",0x2e7,"AddRouteToReg failed for %s, ret is %d\n",local_c08,LVar2);
  }
LAB_0040d3c8:
  FUN_0041c21c(local_8 ^ (uint)(local_408 + 0x404));
  return;
}



// ===== FUN_0040d3e0 @ 0040d3e0 =====

void FUN_0040d3e0(void)

{
  char cVar1;
  LSTATUS LVar2;
  char *pcVar3;
  char *local_918;
  DWORD local_914;
  DWORD local_910;
  undefined2 local_90c [2];
  char local_908 [2048];
  char local_108;
  undefined1 local_107 [255];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_107 + 0x103);
  local_908[0] = '\0';
  memset(local_908 + 1,0,0x7ff);
  local_914 = 0x800;
  local_910 = 1;
  LVar2 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","routelist",&local_910,local_908,&local_914);
  if (LVar2 == 0) {
    pcVar3 = local_908;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (pcVar3 != local_908 + 1) {
      local_108 = cVar1;
      memset(local_107,0,0xff);
      pcVar3 = strstr(local_908,";");
      if (pcVar3 == (char *)0x0) {
        FUN_00414930(&local_108,"route delete %s",(char)local_908);
        FUN_0040c040(1,&local_108);
      }
      else {
        local_90c[0] = 0x3b;
        pcVar3 = strtok_s(local_908,(char *)local_90c,&local_918);
        while (pcVar3 != (char *)0x0) {
          array_vpn_logprint(1,"route.cpp",0x2fe,"route is \"%s\"\n",pcVar3);
          memset(&local_108,0,0x100);
          FUN_00414930(&local_108,"route delete %s",(char)pcVar3);
          FUN_0040c040(1,&local_108);
          pcVar3 = strstr(&local_108,"::/0");
          if (pcVar3 != (char *)0x0) {
            memset(&local_108,0,0x100);
            FUN_00414930(&local_108,"route -p add ::/0 %s metric 1",-0x10);
            FUN_0040c040(1,&local_108);
          }
          pcVar3 = strtok_s((char *)0x0,(char *)local_90c,&local_918);
        }
      }
      SHDeleteValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","routelist");
    }
  }
  FUN_0041c21c(local_8 ^ (uint)(local_107 + 0x103));
  return;
}



// ===== FUN_0040d5f0 @ 0040d5f0 =====

void __fastcall FUN_0040d5f0(int param_1,LPCSTR param_2,char *param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  if (param_1 == 0) {
    pcVar2 = param_3;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome",param_2,1,param_3,(DWORD)(pcVar2 + (1 - (int)(param_3 + 1))))
    ;
    pcVar2 = "SaveCallHomeMsg: save call home message finish, keyname=%s, message=%s.\n";
    uVar3 = 0x31a;
  }
  else {
    if (param_1 != 1) goto LAB_0040d67f;
    local_c = param_4;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome",param_2,4,&local_c,4);
    pcVar2 = "SaveCallHomeMsg: save call home message finish, keyname=%s, message=%d.\n";
    uVar3 = 0x321;
    param_3 = param_4;
  }
  array_vpn_logprint(1,"route.cpp",uVar3,pcVar2,param_2,param_3);
LAB_0040d67f:
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040d690 @ 0040d690 =====

void __fastcall FUN_0040d690(int *param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  CHAR *pCVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  void *local_180 [4];
  undefined4 local_170;
  uint local_16c;
  void *local_168 [4];
  undefined4 local_158;
  uint local_154;
  void *local_150 [4];
  undefined4 local_140;
  uint local_13c;
  void *local_138 [4];
  undefined4 local_128;
  uint local_124;
  CHAR local_120;
  undefined1 local_11f [263];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041de71;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_11f + 0x11b);
  ExceptionList = &local_10;
  array_vpn_logprint(1,"route.cpp",0x328,
                     "LaunchCallHomeProcess: launch call home process start, url:%s, server_info:%s, callhome_xx:%s\n",
                     param_1,param_2,param_3,local_18);
  local_16c = 0xf;
  local_170 = 0;
  local_180[0] = (void *)((uint)local_180[0] & 0xffffff00);
  if ((char)*param_1 == '\0') {
    uVar5 = 0;
  }
  else {
    piVar6 = param_1;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
    } while ((char)iVar2 != '\0');
    uVar5 = (int)piVar6 - ((int)param_1 + 1);
  }
  FUN_00401f80(local_180,param_1,uVar5);
  local_8 = 0;
  local_13c = 0xf;
  local_140 = 0;
  local_150[0] = (void *)((uint)local_150[0] & 0xffffff00);
  FUN_00401f80(local_150,(int *)&DAT_0041f7b1,0);
  local_8._0_1_ = 1;
  local_124 = 0xf;
  local_128 = 0;
  local_138[0] = (void *)((uint)local_138[0] & 0xffffff00);
  FUN_00401f80(local_138,(int *)&DAT_0041f7b1,0);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_154 = 0xf;
  local_158 = 0;
  local_168[0] = (void *)((uint)local_168[0] & 0xffffff00);
  FUN_00401f80(local_168,(int *)&DAT_0041f7b1,0);
  local_120 = '\0';
  memset(local_11f,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_120,0x104);
  PathRemoveFileSpecA(&local_120);
  PathAddBackslashA(&local_120);
  array_vpn_logprint(1,"route.cpp",0x330,"LaunchCallHomeProcess: current dir:%s\n",&local_120);
  strcat_s(&local_120,0x104,"MPInit.exe");
  BVar3 = PathFileExistsA(&local_120);
  if (BVar3 == 0) {
    pCVar4 = &local_120;
    pcVar9 = "LaunchCallHomeProcess: file %s is not exist\n";
    uVar8 = 0x334;
  }
  else {
    pcVar9 = param_2;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome","server_info",1,param_2,
                (DWORD)(pcVar9 + (1 - (int)(param_2 + 1))));
    array_vpn_logprint(1,"route.cpp",0x31a,"SaveCallHomeMsg: save call home message finish, keyname=%s, message=%s.\n",
                       "server_info",param_2);
    piVar6 = param_1;
    do {
      iVar2 = *piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
    } while ((char)iVar2 != '\0');
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome","callhome_url",1,param_1,
                (DWORD)((int)piVar6 + (1 - ((int)param_1 + 1))));
    array_vpn_logprint(1,"route.cpp",0x31a,"SaveCallHomeMsg: save call home message finish, keyname=%s, message=%s.\n",
                       "callhome_url",param_1);
    pcVar9 = param_3;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome","callhome_xx",1,param_3,
                (DWORD)(pcVar9 + (1 - (int)(param_3 + 1))));
    array_vpn_logprint(1,"route.cpp",0x31a,"SaveCallHomeMsg: save call home message finish, keyname=%s, message=%s.\n",
                       "callhome_xx",param_3);
    pcVar9 = &DAT_00429530;
    do {
      pcVar7 = pcVar9;
      pcVar9 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome","vsite_domain",1,&DAT_00429530,(DWORD)(pcVar7 + -0x42952f));
    array_vpn_logprint(1,"route.cpp",0x31a,"SaveCallHomeMsg: save call home message finish, keyname=%s, message=%s.\n",
                       "vsite_domain",&DAT_00429530);
    ShellExecuteA((HWND)0x0,"open",&local_120,"-callhome",(LPCSTR)0x0,0);
    pCVar4 = (CHAR *)GetLastError();
    pcVar9 = "LaunchCallHomeProcess: ShellExecuteA finished, error:%d\n";
    uVar8 = 0x33e;
  }
  array_vpn_logprint(1,"route.cpp",uVar8,pcVar9,pCVar4);
  if (0xf < local_154) {
    operator_delete(local_168[0]);
  }
  local_154 = 0xf;
  local_158 = 0;
  local_168[0] = (void *)((uint)local_168[0] & 0xffffff00);
  if (0xf < local_124) {
    operator_delete(local_138[0]);
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138[0] = (void *)((uint)local_138[0] & 0xffffff00);
  if (0xf < local_13c) {
    operator_delete(local_150[0]);
  }
  local_13c = 0xf;
  local_140 = 0;
  local_150[0] = (void *)((uint)local_150[0] & 0xffffff00);
  if (0xf < local_16c) {
    operator_delete(local_180[0]);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_11f + 0x11b));
  return;
}



// ===== FUN_0040daa0 @ 0040daa0 =====

void __fastcall FUN_0040daa0(undefined1 *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *local_530;
  undefined4 local_52c;
  char local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041dec2;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_118 + 0x114);
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00401f80(param_1,(int *)&DAT_0041f7b1,0);
  local_8 = 0;
  local_52c._0_1_ = '\0';
  memset((void *)((int)&local_52c + 1),0,0x410);
  local_118[0] = '\0';
  memset(local_118 + 1,0,0x103);
  FUN_004149b0(local_118,"%s",(char)param_2);
  memset(&local_52c,0,0x411);
  pcVar3 = param_2 + 1;
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  iVar5 = 0;
  iVar4 = 0;
  if (0 < (int)param_2 - (int)pcVar3) {
    local_530 = (char *)&local_52c;
    do {
      sprintf_s(local_530,0x411,"%04x",((int)local_118[iVar4] ^ (&DAT_00420090)[iVar5]) & 0xffff);
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x20) {
        iVar5 = 0;
      }
      iVar4 = iVar4 + 1;
      local_530 = local_530 + 4;
    } while (iVar4 < (int)param_2 - (int)pcVar3);
  }
  if ((char)local_52c == '\0') {
    uVar2 = 0;
  }
  else {
    pcVar3 = (char *)&local_52c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar2 = (int)pcVar3 - ((int)&local_52c + 1);
  }
  FUN_00401f80(param_1,&local_52c,uVar2);
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_118 + 0x114));
  return;
}



// ===== FUN_0040dc40 @ 0040dc40 =====

void FUN_0040dc40(void)

{
  LSTATUS LVar1;
  DWORD DVar2;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\Install Manager","SSTPAdapterPort",local_14,local_14 + 2,
                      local_14 + 1);
  DVar2 = 0xffa3;
  if ((LVar1 == 0) && (local_14[2] != 0)) {
    DVar2 = local_14[2];
  }
  array_vpn_logprint(1,"route.cpp",0x361,"GetSSTPPort: get sstp adapter port finished, port=%d.\n",DVar2);
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_0040dcd0 @ 0040dcd0 =====

void FUN_0040dcd0(void)

{
  _beginthread(FUN_0040e6c0,0,(void *)0x0);
  return;
}



// ===== FUN_0040dcf0 @ 0040dcf0 =====

void FUN_0040dcf0(void)

{
  uint uVar1;
  HRESULT HVar2;
  int local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041def8;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar1;
  HVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
  if (HVar2 != 0) {
    array_vpn_logprint(1,"route.cpp",0x371,"create instance to vpnservice failed, error: %x\n",HVar2,uVar1);
    if (HVar2 != -0x7ffbfe10) goto LAB_0040ddfe;
    CoInitializeEx((LPVOID)0x0,0);
    HVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
    if (HVar2 != 0) {
      array_vpn_logprint(2,"route.cpp",0x378,"create instance to vpnservice failed, error: %x\n",HVar2,uVar1);
      goto LAB_0040ddfe;
    }
  }
  local_1c = -1;
  (**(code **)(*local_18 + 0x40))(local_18,&local_1c);
  array_vpn_logprint(1,"route.cpp",0x382,
                     "detect vnic status is %d(-1,0(no_run), 1:connecting, 2: connected, 3: connect_fail, 4:reconnecting, 5:reconnect_fail, 6:disconnecting, 7: disconnected)\n"
                     ,local_1c,uVar1);
LAB_0040ddfe:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040de30 @ 0040de30 =====

void FUN_0040de30(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  int *local_98;
  char local_94;
  undefined1 local_93 [127];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e075;
  local_10 = ExceptionList;
  uVar2 = DAT_00428000 ^ (uint)(local_93 + 0x8f);
  ExceptionList = &local_10;
  local_98 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar2;
  iVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_98);
  if (iVar3 != 0) {
    if (iVar3 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_98);
    }
    if (iVar3 != 0) {
      array_vpn_logprint(2,"route.cpp",0x3a9,"SaveWireGuardPeer failed: error: %x\n",iVar3,uVar2);
      goto LAB_0040e550;
    }
  }
  local_94 = '\0';
  memset(local_93,0,0x7f);
  FUN_004149d0(&local_94,"%s:%d",'\b');
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&local_94);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 1;
  pOVar5 = SysAllocString(L"Endpoint");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 2;
  pOVar6 = SysAllocString(L"SOFTWARE\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042dd88);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 4;
  pOVar5 = SysAllocString(L"PublicKey");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 5;
  pOVar6 = SysAllocString(L"SOFTWARE\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 6;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042df88);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 7;
  pOVar5 = SysAllocString(L"wg_name");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 8;
  pOVar6 = SysAllocString(L"SOFTWARE\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 9;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042e088);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 10;
  pOVar5 = SysAllocString(L"vsite_name");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0xb;
  pOVar6 = SysAllocString(L"SOFTWARE\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0xc;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042e188);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0xd;
  pOVar5 = SysAllocString(L"session_id");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0xe;
  pOVar6 = SysAllocString(L"SOFTWARE\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0xf;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&local_94);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x10;
  pOVar5 = SysAllocString(L"Endpoint");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x11;
  pOVar6 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x12;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042dd88);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x13;
  pOVar5 = SysAllocString(L"PublicKey");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x14;
  pOVar6 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x15;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042df88);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x16;
  pOVar5 = SysAllocString(L"wg_name");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x17;
  pOVar6 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x18;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042e088);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x19;
  pOVar5 = SysAllocString(L"vsite_name");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x1a;
  pOVar6 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x1b;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_98;
  pOVar4 = FUN_0040b940(&DAT_0042e188);
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x1c;
  pOVar5 = SysAllocString(L"session_id");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 0x1d;
  pOVar6 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,0x1e);
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,1,pOVar6,pOVar5,pOVar4,0);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  SysFreeString(pOVar4);
LAB_0040e550:
  local_8 = 0xffffffff;
  if (local_98 != (int *)0x0) {
    (**(code **)(*local_98 + 8))(local_98);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_93 + 0x8f));
  return;
}



// ===== FUN_0040e590 @ 0040e590 =====

void FUN_0040e590(void)

{
  int *piVar1;
  uint uVar2;
  HRESULT HVar3;
  BSTR bstrString;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e0b0;
  local_10 = ExceptionList;
  uVar2 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar2;
  HVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
  if (HVar3 != 0) {
    array_vpn_logprint(1,"route.cpp",0x3b4,"create instance to vpninstallmanager failed, error: %x\n",HVar3,uVar2);
    if (HVar3 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      HVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
    }
    if (HVar3 != 0) {
      array_vpn_logprint(2,"route.cpp",0x3c2,"create instance to vpninstallmanager failed, error: %x\n",HVar3,uVar2);
      goto LAB_0040e68a;
    }
  }
  piVar1 = local_18;
  bstrString = SysAllocString(L"VPNService.exe");
  if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*piVar1 + 0x60))(piVar1,bstrString);
  SysFreeString(bstrString);
  sleep_sec(1);
LAB_0040e68a:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040e6c0 @ 0040e6c0 =====

void FUN_0040e6c0(void)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_34;
  int local_30;
  DWORD local_2c;
  int *local_28;
  DWORD DStack_24;
  DWORD DStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0041e0e8;
  local_14 = ExceptionList;
  local_1c = DAT_00428000 ^ (uint)&local_34;
  ExceptionList = &local_14;
  array_vpn_logprint(1,"route.cpp",0x3c8,"detect_vni_status_thread: Start......................................\n",
                     DAT_00428000 ^ (int)register0x00000010 - 0x40U);
  iVar4 = 0;
  local_2c = 999;
  local_28 = (int *)0x0;
  local_c = 0;
  local_34 = FUN_00413460();
  iVar5 = 0;
LAB_0040e730:
  Sleep(1000);
  local_30 = iVar5 + 1;
  HVar1 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_28);
  if (HVar1 != 0) {
    array_vpn_logprint(1,"route.cpp",0x3d5,"pIVPNServer.CoCreateInstance failed, error: %x\n",HVar1);
    if (HVar1 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      HVar1 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_28);
    }
    if (HVar1 != 0) {
      array_vpn_logprint(1,"route.cpp",0x3df,"detect_vni_status_thread, run com failed, error: %x\n",HVar1);
      FUN_00410710(1);
      array_vpn_set_status(0);
      FUN_00415970(2,0,(char *)0x0);
      goto LAB_0040eb51;
    }
  }
  local_2c = 999;
  (**(code **)(*local_28 + 0x40))(local_28,&local_2c);
  iVar5 = local_30;
  if (local_2c == 999) {
    if (local_30 < 0x3d) {
      array_vpn_logprint(1,"route.cpp",0x3ec,
                         "detect_vni_status_thread: the vpn status is invalid and continue, times:%d\n",local_30);
      goto LAB_0040e730;
    }
    local_2c = 0xffffffff;
    array_vpn_logprint(1,"route.cpp",0x3f2,"detect_vni_status_thread: the vpn status is invalid and break\n");
  }
  iVar5 = 0;
  if (local_2c != 2) {
    array_vpn_logprint(1,"route.cpp",0x3f8,"detect_vni_status_thread: received current status: %d, iConnectedFlag: %d\n"
                       ,local_2c,iVar4);
  }
  if (local_2c == 4) {
    local_30 = 0;
    DStack_24 = local_2c;
    DStack_20 = local_2c;
    LVar2 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","sslerror",&DStack_20,&local_30,&DStack_24);
    if ((LVar2 == 0) &&
       (array_vpn_logprint(1,"route.cpp",0xb0a,"GetSSLErrorValue finished, ret:%d, value:%d\n",0,local_30),
       local_30 == 0x2711)) {
      uVar6 = 0x400;
LAB_0040e989:
      array_vpn_logprint(1,"route.cpp",uVar6,
                         "it seems current vpnservice is hung status and no clienthello send out, have to resume and restart it\n"
                        );
      FUN_0040e590();
      FUN_00412260();
    }
    else {
LAB_0040e950:
      if (local_2c == 6) {
        if (iVar4 == 1) {
          array_vpn_logprint(1,"route.cpp",0x431,
                             "detect_vni_status_thread: vpn status is disconnecting, send status to vpnd.\n");
          iVar3 = FUN_00413f90();
          if (iVar3 == 0x2711) {
            uVar6 = 0x436;
            goto LAB_0040e989;
          }
          array_vpn_set_status(3);
          FUN_00415970(4,0,(char *)0x0);
        }
      }
      else if (local_2c == 4) {
        if (iVar4 == 1) {
          array_vpn_logprint(1,"route.cpp",0x443,
                             "detect_vni_status_thread: vpn status is reconnecting, send status to vpnd.\n");
          array_vpn_set_status(4);
          FUN_00415970(7,0,(char *)0x0);
          iVar4 = 0;
          FUN_0040f460("-resumeproxyforvnic");
        }
      }
      else {
        if ((local_2c != 2) && (iVar4 == 1)) {
          array_vpn_logprint(1,"route.cpp",0x44d,
                             "detect_vni_status_thread: vpn status(%d) is not connected and the connected flag is 1, stop thread and set vpn status to disconnected\n"
                             ,local_2c);
          array_vpn_set_status(7);
          (**(code **)(*local_28 + 0x58))(local_28,&local_30);
          array_vpn_logprint(1,"route.cpp",0x451,"detect_vni_status_thread: received last error:%d\n",local_30);
          if (local_30 == 0x224) {
            FUN_00415970(5,6,(char *)0x0);
          }
          else {
            FUN_00415970(5,0,(char *)0x0);
          }
          goto LAB_0040eb35;
        }
        if ((local_2c == 0xffffffff) || (local_2c == 0)) {
          array_vpn_set_status(0);
          FUN_00415970(5,0,(char *)0x0);
LAB_0040eb35:
          array_vpn_logprint(1,"route.cpp",0x467,
                             "detect_vni_status_thread: Finish......................................\n");
          _endthread();
LAB_0040eb51:
          local_c = 0xffffffff;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
          ExceptionList = local_14;
          FUN_0041c21c(local_1c ^ (uint)&local_34);
          return;
        }
      }
    }
  }
  else if (local_2c == 1) {
    array_vpn_logprint(1,"route.cpp",0x408,"detect_vni_status_thread: vpn status is connecting...\n");
    array_vpn_set_status(1);
    FUN_00415970(1,0,(char *)0x0);
  }
  else {
    if (local_2c != 2) {
      if (local_2c == 3) {
        array_vpn_logprint(1,"route.cpp",0x421,"detect_vni_status_thread: vpn status is connect failed, stop thread.\n")
        ;
        array_vpn_set_status(0);
        iVar5 = 2;
      }
      else {
        if (local_2c != 5) goto LAB_0040e950;
        array_vpn_logprint(1,"route.cpp",0x428,
                           "detect_vni_status_thread: vpn status is reconnect failed, stop thread.\n");
        array_vpn_set_status(0);
        iVar5 = 5;
      }
      FUN_00415970(iVar5,0,(char *)0x0);
      goto LAB_0040eb35;
    }
    if (iVar4 == 0) {
      array_vpn_logprint(1,"route.cpp",0x411,
                         "detect_vni_status_thread: vpn current status is connected, send status to vpnd.\n");
      array_vpn_set_status(2);
      FUN_00415970(3,0,(char *)0x0);
      if (local_34 < 2) {
        FUN_00410710(2);
      }
      iVar4 = 1;
      FUN_0040f460("-setproxyforvnic");
      FUN_0040ff90();
    }
  }
  goto LAB_0040e730;
}



// ===== FUN_0040eb90 @ 0040eb90 =====

void __cdecl FUN_0040eb90(int param_1)

{
  LSTATUS LVar1;
  code *pcVar2;
  int iVar3;
  char cVar4;
  undefined1 *_Dst;
  int local_258;
  DWORD local_254 [2];
  uint local_24c;
  char local_248;
  undefined1 local_247 [255];
  char local_148;
  undefined1 local_147 [255];
  char local_48;
  undefined1 local_47 [63];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_47 + 0x43);
  local_148 = '\0';
  memset(local_147,0,0xff);
  pcVar2 = array_vpn_logprint_exref;
  array_vpn_logprint(1,"route.cpp",0x475,"route_config_thread: Start......................................\n");
  iVar3 = 0;
  do {
    local_254[1] = 4;
    local_24c = 0;
    local_254[0] = 4;
    LVar1 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","status",local_254 + 1,&local_24c,local_254);
    array_vpn_logprint(1,"route.cpp",0x47d,"iTimes:%d, status:%d\n",iVar3,local_24c);
    if ((LVar1 == 0) && (local_24c == 1)) break;
    Sleep(500);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x3c);
  Sleep(3000);
  if (*(char *)(param_1 + 0x1a8) == '\0') {
    array_vpn_logprint(1,"route.cpp",0x489,"ipv6: split tunnel\n");
    local_24c = 0;
    if (*(int *)(param_1 + 0x1b0) != 0) {
      local_258 = 0;
      do {
        iVar3 = *(int *)(param_1 + 0x1b8) + local_258;
        memset(&local_148,0,0x100);
        array_vpn_get_ipv6_prefix(iVar3 + 0x88);
        cVar4 = (char)iVar3;
        FUN_00414930(&local_148,"route add %s/%d %s METRIC 1",cVar4);
        FUN_0040c040(1,&local_148);
        local_248 = '\0';
        memset(local_247,0,0xff);
        FUN_00414930(&local_248,"%s/%d",cVar4);
        FUN_0040d290((int)&local_248);
        local_24c = local_24c + 1;
        local_258 = local_258 + 0x110;
      } while (local_24c < *(uint *)(param_1 + 0x1b0));
      pcVar2 = array_vpn_logprint_exref;
    }
  }
  else {
    array_vpn_logprint(1,"route.cpp",0x49b,"ipv6: full tunnel\n");
    memset(&local_148,0,0x100);
    cVar4 = (char)param_1 + '\x10';
    FUN_00414930(&local_148,"route delete ::/0",cVar4);
    FUN_0040c040(1,&local_148);
    memset(&local_148,0,0x100);
    FUN_00414930(&local_148,"route add ::/0 %s METRIC 1",cVar4);
    FUN_0040c040(1,&local_148);
    _Dst = local_47;
    local_48 = '\0';
    memset(_Dst,0,0x3f);
    FUN_00414950(&local_48,"::/0",(char)_Dst);
    FUN_0040d290((int)&local_48);
  }
  FUN_00415970(3,0,(char *)0x0);
  DAT_0042dbfc = 2;
  (*pcVar2)(1,"route.cpp",0x4aa,"route_config_thread: finish......................................\n");
  _endthread();
  FUN_0041c21c(local_8 ^ (uint)(local_47 + 0x43));
  return;
}



// ===== FUN_0040ee90 @ 0040ee90 =====

void FUN_0040ee90(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  
  FUN_0040ef60();
  piVar4 = DAT_004288d4;
  if (DAT_004288d4 != (int *)0x0) {
    do {
      for (piVar2 = piVar4 + 0x75; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        strncpy_s(&DAT_004294f0,0x40,(char *)(piVar2 + 1),0x3f);
        pcVar3 = &DAT_004294f0;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        if ((pcVar3 != &DAT_004294f1) && (pcVar3 = strstr(&DAT_004294f0,"0.0.0.0"), pcVar3 == (char *)0x0)) break;
      }
      pcVar3 = &DAT_004294f0;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    } while (((pcVar3 == &DAT_004294f1) || (pcVar3 = strstr(&DAT_004294f0,"0.0.0.0"), pcVar3 != (char *)0x0)) &&
            (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0));
    array_vpn_logprint(1,"route.cpp",0x4c9,"GetGateway finished: %s\n",&DAT_004294f0);
  }
  return;
}



// ===== FUN_0040ef60 @ 0040ef60 =====

void FUN_0040ef60(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  size_t local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_c = 0x288;
  hModule = LoadLibraryA("iphlpapi.dll");
  if (((hModule != (HMODULE)0x0) && (pFVar1 = GetProcAddress(hModule,"GetAdaptersInfo"), pFVar1 != (FARPROC)0x0)) &&
     (DAT_004288d4 = (int)malloc(local_c), (void *)DAT_004288d4 != (void *)0x0)) {
    iVar2 = (*pFVar1)(DAT_004288d4,&local_c);
    if (iVar2 == 0x6f) {
      free((void *)DAT_004288d4);
      DAT_004288d4 = (int)malloc(local_c);
      if ((void *)DAT_004288d4 == (void *)0x0) goto LAB_0040efea;
    }
    (*pFVar1)(DAT_004288d4,&local_c);
  }
LAB_0040efea:
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_0040f000 @ 0040f000 =====

void FUN_0040f000(void)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  NTSTATUS NVar4;
  char *pcVar5;
  byte *******pppppppbVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  code *pcVar10;
  bool bVar11;
  undefined4 local_4c [5];
  uint local_38;
  int local_34;
  PMIB_IPNET_TABLE2 local_30;
  byte *******local_2c [4];
  byte ******local_1c;
  byte ******local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  byte ******local_8;
  
  local_8 = (byte ******)0xffffffff;
  puStack_c = &LAB_0041e118;
  local_10 = ExceptionList;
  uVar3 = DAT_00428000 ^ (uint)(local_2c + 10);
  ExceptionList = &local_10;
  local_30 = (PMIB_IPNET_TABLE2)0x0;
  local_14 = uVar3;
  NVar4 = GetIpNetTable2(0x17,&local_30);
  if (NVar4 == 0) {
    array_vpn_logprint(1,"route.cpp",0x504,"Number of IPv6 table entries: %d\n\n",local_30->NumEntries,uVar3);
    uVar3 = 0;
    if (local_30->NumEntries != 0) {
      local_34 = 0;
      pcVar10 = operator_delete_exref;
      do {
        iVar9 = local_34;
        inet_ntop(0x17,local_30->Table[0].Address.Ipv6.sin6_addr.u.Byte + local_34,&DAT_004293f0,0x100);
        if ((local_30->Table[0].PhysicalAddress[iVar9 + 0x28] & 1) != 0) {
          array_vpn_logprint(1,"route.cpp",0x509,"IPv6 gateway[%d]:\t %s\n",uVar3,&DAT_004293f0);
          local_18 = (byte ******)0xf;
          local_1c = (byte ******)0x0;
          local_2c[0] = (byte *******)((uint)local_2c[0] & 0xffffff00);
          if (DAT_004293f0 == '\0') {
            pcVar5 = (char *)0x0;
          }
          else {
            pcVar2 = &DAT_004293f0;
            do {
              pcVar5 = pcVar2;
              pcVar2 = pcVar5 + 1;
            } while (*pcVar5 != '\0');
            pcVar5 = pcVar5 + -0x4293f0;
          }
          FUN_00401f80(local_2c,(int *)&DAT_004293f0,(uint)pcVar5);
          local_8 = (byte ******)0x0;
          pppppppbVar6 = (byte *******)FUN_00414140(local_2c,(undefined1 *)local_4c,(int)local_1c - 3,0xffffffff);
          if (local_2c != (byte ********)pppppppbVar6) {
            if ((byte ******)0xf < local_18) {
              (*pcVar10)(local_2c[0]);
            }
            local_18 = (byte ******)0xf;
            local_1c = (byte ******)0x0;
            local_2c[0] = (byte *******)((uint)local_2c[0] & 0xffffff00);
            if (pppppppbVar6[5] < (byte ******)0x10) {
              if ((int)pppppppbVar6[4] + 1U != 0) {
                memmove(local_2c,pppppppbVar6,(int)pppppppbVar6[4] + 1U);
              }
            }
            else {
              local_2c[0] = (byte *******)*pppppppbVar6;
              *pppppppbVar6 = (byte ******)0x0;
            }
            local_1c = pppppppbVar6[4];
            local_18 = pppppppbVar6[5];
            pppppppbVar6[5] = (byte ******)0xf;
            pppppppbVar6[4] = (byte ******)0x0;
            *(undefined1 *)pppppppbVar6 = 0;
          }
          if (0xf < local_38) {
            (*pcVar10)(local_4c[0]);
          }
          pcVar10 = operator_delete_exref;
          pbVar8 = &DAT_00421830;
          pppppppbVar6 = (byte *******)local_2c;
          if ((byte ******)0xf < local_18) {
            pppppppbVar6 = local_2c[0];
          }
          do {
            bVar1 = *(byte *)pppppppbVar6;
            bVar11 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_0040f1f3:
              uVar7 = -(uint)bVar11 | 1;
              goto LAB_0040f1f8;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)pppppppbVar6 + 1);
            bVar11 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_0040f1f3;
            pppppppbVar6 = (byte *******)((int)pppppppbVar6 + 2);
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_0040f1f8:
          if (uVar7 == 0) {
            if ((byte ******)0xf < local_18) {
              operator_delete(local_2c[0]);
            }
            break;
          }
          local_8 = (byte ******)0xffffffff;
          if ((byte ******)0xf < local_18) {
            operator_delete(local_2c[0]);
          }
          iVar9 = local_34;
        }
        uVar3 = uVar3 + 1;
        local_34 = iVar9 + 0x58;
      } while (uVar3 < local_30->NumEntries);
    }
    if (local_30 != (PMIB_IPNET_TABLE2)0x0) {
      FreeMibTable(local_30);
    }
  }
  else {
    array_vpn_logprint(1,"route.cpp",0x500,"GetIpNetTable for IPv4 table returned error: %ld\n",NVar4,uVar3);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_2c + 10));
  return;
}



// ===== FUN_0040f270 @ 0040f270 =====

void __fastcall FUN_0040f270(char *param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  _PROCESS_INFORMATION local_274;
  _STARTUPINFOA local_264;
  char local_21c;
  undefined1 local_21b [263];
  CHAR local_114;
  undefined1 local_113 [267];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_113 + 0x10f);
  local_114 = '\0';
  memset(local_113,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_114,0x104);
  PathRemoveFileSpecA(&local_114);
  PathAddBackslashA(&local_114);
  array_vpn_logprint(1,"route.cpp",0x520,"SetInsideProxySettings: current dir:%s\n",&local_114);
  if (param_1 == (char *)0x1) {
    pcVar5 = "InsideProxy.exe";
  }
  else {
    pcVar5 = "InsideProxySplit.exe";
  }
  strcat_s(&local_114,0x104,pcVar5);
  BVar1 = PathFileExistsA(&local_114);
  if (BVar1 == 0) {
    array_vpn_logprint(1,"route.cpp",0x52c,"SetInsideProxySettings: file %s is not exist\n",&local_114);
    FUN_0041c21c(local_8 ^ (uint)(local_113 + 0x10f));
    return;
  }
  local_21c = '\0';
  memset(local_21b,0,0x103);
  FUN_004149b0(&local_21c,"\"%s\" %s",(char)&local_114);
  memset(&local_264,0,0x44);
  local_264.cb = 0x44;
  local_274.hProcess = (HANDLE)0x0;
  local_274.hThread = (HANDLE)0x0;
  local_274.dwProcessId = 0;
  local_274.dwThreadId = 0;
  BVar1 = CreateProcessA((LPCSTR)0x0,&local_21c,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                         (LPCSTR)0x0,&local_264,&local_274);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    param_1 = &local_21c;
    pcVar5 = "CreateProcess %s failed, error is %d\n";
    uVar4 = 0x53b;
    uVar3 = 3;
  }
  else {
    WaitForSingleObject(local_274.hProcess,5000);
    CloseHandle(local_274.hProcess);
    CloseHandle(local_274.hThread);
    DVar2 = GetLastError();
    pcVar5 = "SetInsideProxySettings, fulltunnel(%d): ShellExecuteA finished, error:%d\n";
    uVar4 = 0x544;
    uVar3 = 1;
  }
  array_vpn_logprint(uVar3,"route.cpp",uVar4,pcVar5,param_1,DVar2);
  FUN_0041c21c(local_8 ^ (uint)(local_113 + 0x10f));
  return;
}



// ===== FUN_0040f460 @ 0040f460 =====

void __fastcall FUN_0040f460(LPCSTR param_1)

{
  char cVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  char *pcVar4;
  DWORD DVar5;
  DWORD local_21c [3];
  char local_210;
  undefined1 local_20f [259];
  CHAR local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10c + 0x108);
  local_21c[1] = 4;
  local_21c[2] = 0;
  local_21c[0] = 4;
  LVar2 = SHGetValueA((HKEY)0x80000002,"Software\\VPN\\VPN2","ProxyScriptNoRewrite",local_21c + 1,local_21c + 2,
                      local_21c);
  if ((LVar2 == 0) && (local_21c[2] == 1)) {
    DVar5 = 1;
    pcVar4 = "ChangeProxyScriptForVNIC: ProxyScriptNoRewrite is 1, no need change or resume proxy script.\n";
    uVar3 = 0x54d;
  }
  else {
    local_210 = '\0';
    memset(local_20f,0,0x103);
    local_10c[0] = '\0';
    memset(local_10c + 1,0,0x103);
    GetModuleFileNameA((HMODULE)0x0,local_10c,0x104);
    PathRemoveFileSpecA(local_10c);
    PathAddBackslashA(local_10c);
    pcVar4 = local_10c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    memcpy(&local_210,local_10c,(size_t)(pcVar4 + (-0x15 - (int)(local_10c + 1))));
    strcat_s(&local_210,0x104,"SSL VPN Client\\WebVPN.exe");
    array_vpn_logprint(1,"route.cpp",0x557,"ChangeProxyScriptForVNIC: path:%s, command:%s\n",&local_210,param_1);
    ShellExecuteA((HWND)0x0,"open",&local_210,param_1,(LPCSTR)0x0,0);
    DVar5 = GetLastError();
    pcVar4 = "SetOutSideProxyScript: ShellExecuteA finished, error:%d\n";
    uVar3 = 0x559;
  }
  array_vpn_logprint(1,"route.cpp",uVar3,pcVar4,DVar5);
  FUN_0041c21c(local_8 ^ (uint)(local_10c + 0x108));
  return;
}



// ===== FUN_0040f600 @ 0040f600 =====

void __fastcall FUN_0040f600(int param_1)

{
  char cVar1;
  LSTATUS LVar2;
  BOOL BVar3;
  CHAR *pCVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_41c;
  char local_418;
  undefined1 local_417 [259];
  char local_314;
  undefined1 local_313 [259];
  CHAR local_210;
  undefined1 local_20f [259];
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10c + 0x108);
  local_314 = '\0';
  memset(local_313,0,0x103);
  local_10c[0] = '\0';
  memset(local_10c + 1,0,0x103);
  local_41c = *(undefined4 *)(param_1 + 0x1ac);
  LVar2 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2\\Include","number",4,&local_41c,4);
  array_vpn_logprint(1,"route.cpp",0x564,
                     "adapter_config_thread: save include zone number finished, ret=%d, number=%d.\n",LVar2,local_41c);
  local_41c = *(undefined4 *)(param_1 + 0x1bc);
  SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2\\Exclude","number",4,&local_41c,4);
  uVar6 = 0;
  if (*(int *)(param_1 + 0x1ac) != 0) {
    do {
      memset(local_10c,0,0x104);
      memset(&local_314,0,0x104);
      FUN_004149b0(local_10c,"virip=%d.%d.%d.%d@mask=%d.%d.%d.%d",*(char *)(*(int *)(param_1 + 0x1b4) + uVar6 * 8));
      FUN_004149b0(&local_314,"include_%d",(char)uVar6);
      pcVar5 = local_10c;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\Include",&local_314,1,local_10c,
                  (DWORD)(pcVar5 + (1 - (int)(local_10c + 1))));
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0x1ac));
  }
  uVar6 = 0;
  if (*(int *)(param_1 + 0x1bc) != 0) {
    do {
      memset(local_10c,0,0x104);
      memset(&local_314,0,0x104);
      FUN_004149b0(local_10c,"virip=%d.%d.%d.%d@mask=%d.%d.%d.%d",*(char *)(*(int *)(param_1 + 0x1c4) + uVar6 * 8));
      FUN_004149b0(&local_314,"exclude_%d",(char)uVar6);
      pcVar5 = local_10c;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\Exclude",&local_314,1,local_10c,
                  (DWORD)(pcVar5 + (1 - (int)(local_10c + 1))));
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_1 + 0x1bc));
  }
  local_210 = '\0';
  memset(local_20f,0,0x103);
  local_418 = '\0';
  memset(local_417,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_210,0x104);
  PathRemoveFileSpecA(&local_210);
  PathAddBackslashA(&local_210);
  strcat_s(&local_210,0x104,"MPInit.exe");
  BVar3 = PathFileExistsA(&local_210);
  if (BVar3 == 0) {
    pCVar4 = &local_210;
    pcVar5 = "SetOutSideProxyScript: file %s is not exist\n";
    uVar7 = 0x589;
  }
  else {
    if (*(char *)(param_1 + 0x1a8) == '\0') {
      pcVar5 = "-MPSetOutSideProxyScript SplitTunnel %s";
    }
    else {
      pcVar5 = "-MPSetOutSideProxyScript FullTunnel %s";
    }
    FUN_004149b0(&local_418,pcVar5,-0x48);
    ShellExecuteA((HWND)0x0,"open",&local_210,&local_418,(LPCSTR)0x0,0);
    pCVar4 = (CHAR *)GetLastError();
    pcVar5 = "SetOutSideProxyScript: ShellExecuteA finished, error:%d\n";
    uVar7 = 0x596;
  }
  array_vpn_logprint(1,"route.cpp",uVar7,pcVar5,pCVar4);
  FUN_0041c21c(local_8 ^ (uint)(local_10c + 0x108));
  return;
}



// ===== FUN_0040f990 @ 0040f990 =====

void FUN_0040f990(void)

{
  BOOL BVar1;
  LPCSTR lpFile;
  undefined4 uVar2;
  char *pcVar3;
  CHAR local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10b + 0x107);
  local_10c = '\0';
  memset(local_10b,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_10c,0x104);
  PathRemoveFileSpecA(&local_10c);
  PathAddBackslashA(&local_10c);
  array_vpn_logprint(1,"route.cpp",0x5a1,"ResumeOutSideProxyScript: current dir:%s\n",&local_10c);
  strcat_s(&local_10c,0x104,"MPInit.exe");
  BVar1 = PathFileExistsA(&local_10c);
  lpFile = &local_10c;
  if (BVar1 == 0) {
    pcVar3 = "ResumeOutSideProxyScript: file %s is not exist\n";
    uVar2 = 0x5a5;
  }
  else {
    ShellExecuteA((HWND)0x0,"open",lpFile,"-MPResumeOutSideProxyScript",(LPCSTR)0x0,0);
    lpFile = (LPCSTR)GetLastError();
    pcVar3 = "ResumeOutSideProxyScript: ShellExecuteA finished, error:%d\n";
    uVar2 = 0x5aa;
  }
  array_vpn_logprint(1,"route.cpp",uVar2,pcVar3,lpFile);
  FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
  return;
}



// ===== FUN_0040fa90 @ 0040fa90 =====

void __fastcall FUN_0040fa90(char param_1)

{
  FUN_00414950(&DAT_004296b8,"%s",param_1);
  array_vpn_logprint(1,"route.cpp",0x5b1,"SetSiteHost: vsite host=%s.\n",&DAT_004296b8);
  return;
}



// ===== FUN_0040fac0 @ 0040fac0 =====

void __fastcall FUN_0040fac0(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  CHAR local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10b + 0x107);
  local_10c = '\0';
  memset(local_10b,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_10c,0x104);
  PathRemoveFileSpecA(&local_10c);
  PathAddBackslashA(&local_10c);
  array_vpn_logprint(1,"route.cpp",0x5bc,"RunLaunchCMD: current dir:%s\n",&local_10c);
  strcat_s(&local_10c,0x104,"MPInit.exe");
  BVar1 = PathFileExistsA(&local_10c);
  if (BVar1 == 0) {
    array_vpn_logprint(1,"route.cpp",0x5c0,"RunLaunchCMD: file %s is not exist\n",&local_10c);
    FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
    return;
  }
  if ((DAT_00428dde == '\0') || (param_1 != 1)) {
    array_vpn_logprint(1,"route.cpp",0x5c9,"RunLaunchCMD: no connected launch command config. \n");
  }
  else {
    array_vpn_logprint(1,"route.cpp",0x5c5,"RunLaunchCMD: start run connected command .\n");
    ShellExecuteA((HWND)0x0,"open",&local_10c,"-MPConnectcmd",(LPCSTR)0x0,1);
    DVar2 = GetLastError();
    array_vpn_logprint(1,"route.cpp",0x5c7,"RunLaunchCMD: ShellExecuteA finished, error:%d\n",DVar2);
  }
  if ((DAT_00428ddd == '\0') || (param_1 != 0)) {
    array_vpn_logprint(1,"route.cpp",0x5d2,"RunLaunchCMD: no disconnected launch command config. \n");
    FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
    return;
  }
  array_vpn_logprint(1,"route.cpp",0x5cd,"RunLaunchCMD: start run disconnected command .\n");
  ShellExecuteA((HWND)0x0,"open",&local_10c,"-MPDisconnectcmd",(LPCSTR)0x0,1);
  DVar2 = GetLastError();
  array_vpn_logprint(1,"route.cpp",0x5cf,"RunLaunchCMD: ShellExecuteA finished, error:%d\n",DVar2);
  FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
  return;
}



// ===== FUN_0040fcb0 @ 0040fcb0 =====

void __fastcall FUN_0040fcb0(int param_1)

{
  char cVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  code *pcVar6;
  int local_11c;
  char local_118 [256];
  char local_18 [16];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_18 + 0x14);
  if ((*(int *)(param_1 + 0x1f8) == 0) && (*(int *)(param_1 + 0x200) == 0)) {
    array_vpn_logprint(1,"route.cpp",0x5db,"SaveLaunchCMD: No launch command config setting. No need save.\n");
    FUN_0041c21c(local_8 ^ (uint)(local_18 + 0x14));
    return;
  }
  array_vpn_logprint(1,"route.cpp",0x5e2,
                     "SaveLaunchCMD: start save launch command to Reg, connected launch command number=%d, disconnected launch command number=%d.\n"
                     ,*(int *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x200));
  pcVar6 = SHSetValueA_exref;
  if (*(int *)(param_1 + 0x1f8) == 0) {
    SHDeleteKeyA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD");
  }
  else {
    local_11c = *(int *)(param_1 + 0x1f8);
    LVar2 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD","number",4,&local_11c,4);
    array_vpn_logprint(1,"route.cpp",0x5e9,"SaveLaunchCMD: save connected command number=%d, set value ret=%d.\n",
                       local_11c,LVar2);
    uVar5 = 0;
    if (*(int *)(param_1 + 0x1f8) != 0) {
      do {
        local_18[0] = '\0';
        local_18[1] = '\0';
        local_18[2] = '\0';
        local_18[3] = '\0';
        local_18[4] = '\0';
        local_18[5] = '\0';
        local_18[6] = '\0';
        local_18[7] = '\0';
        local_18[8] = '\0';
        local_18[9] = '\0';
        local_18[10] = '\0';
        local_18[0xb] = '\0';
        local_18[0xc] = '\0';
        local_18[0xd] = '\0';
        local_18[0xe] = '\0';
        local_18[0xf] = '\0';
        memset(local_118,0,0x100);
        FUN_004149f0(local_18,"LaunchCommand%02d",(char)uVar5);
        FUN_00414930(local_118,"%s",(char)*(undefined4 *)(*(int *)(param_1 + 0x1fc) + uVar5 * 4));
        pcVar4 = local_118;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        LVar2 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD",local_18,1,local_118,
                            (DWORD)(pcVar4 + (1 - (int)(local_118 + 1))));
        array_vpn_logprint(1,"route.cpp",0x5f4,
                           "SaveLaunchCMD: save connected command data=%s, reg name=%s, set value ret=%d.\n",local_118,
                           local_18,LVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x1f8));
    }
    pcVar6 = SHSetValueA_exref;
  }
  if (*(int *)(param_1 + 0x200) == 0) {
    SHDeleteKeyA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\DisconnectedCMD");
  }
  else {
    local_11c = *(int *)(param_1 + 0x200);
    uVar3 = (*pcVar6)(0x80000001,"SOFTWARE\\VPN\\VPN2\\DisconnectedCMD","number",4,&local_11c,4);
    array_vpn_logprint(1,"route.cpp",0x600,"SaveLaunchCMD: save disconnected command number=%d, set value ret=%d.\n",
                       local_11c,uVar3);
    uVar5 = 0;
    if (*(int *)(param_1 + 0x200) != 0) {
      do {
        local_18[0] = '\0';
        local_18[1] = '\0';
        local_18[2] = '\0';
        local_18[3] = '\0';
        local_18[4] = '\0';
        local_18[5] = '\0';
        local_18[6] = '\0';
        local_18[7] = '\0';
        local_18[8] = '\0';
        local_18[9] = '\0';
        local_18[10] = '\0';
        local_18[0xb] = '\0';
        local_18[0xc] = '\0';
        local_18[0xd] = '\0';
        local_18[0xe] = '\0';
        local_18[0xf] = '\0';
        memset(local_118,0,0x100);
        FUN_004149f0(local_18,"LaunchCommand%02d",(char)uVar5);
        FUN_00414930(local_118,"%s",(char)*(undefined4 *)(*(int *)(param_1 + 0x204) + uVar5 * 4));
        pcVar4 = local_118;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        LVar2 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\DisconnectedCMD",local_18,1,local_118,
                            (DWORD)(pcVar4 + (1 - (int)(local_118 + 1))));
        array_vpn_logprint(1,"route.cpp",0x60b,
                           "SaveLaunchCMD: save disconnected command data=%s, reg name=%s, set value ret=%d.\n",
                           local_118,local_18,LVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x200));
      FUN_0041c21c(local_8 ^ (uint)(local_18 + 0x14));
      return;
    }
  }
  FUN_0041c21c(local_8 ^ (uint)(local_18 + 0x14));
  return;
}



// ===== FUN_0040ff90 @ 0040ff90 =====

void FUN_0040ff90(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  LSTATUS LVar4;
  char *pcVar5;
  undefined1 *local_1d8;
  undefined1 local_1d4 [132];
  LPCWSTR local_150;
  uint local_14c;
  uint local_148;
  int *local_144;
  char local_140 [256];
  char local_40 [28];
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = local_40 + 0x3c;
  puStack_18 = &LAB_0041e156;
  local_1c = ExceptionList;
  uVar2 = DAT_00428000 ^ (uint)(local_40 + 0x30);
  ExceptionList = &local_1c;
  DAT_00428dde = 0;
  local_144 = (int *)0x0;
  local_14 = 0;
  local_24 = uVar2;
  iVar3 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_144);
  if (iVar3 != 0) {
    if (iVar3 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar3 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_144);
    }
    if (iVar3 != 0) {
      array_vpn_logprint(2,"route.cpp",0x626,"SaveLaunchCMDforVNIC: CoCreateInstance failed with VPNServer: error:%x\n",
                         iVar3);
      goto LAB_0041023f;
    }
  }
  local_148 = 0;
  (**(code **)(*local_144 + 0x30))(local_144,&local_148,uVar2);
  if (local_148 == 0) {
    SHDeleteKeyA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD");
  }
  else {
    if (0x7f < local_148) {
      local_148 = 0x80;
    }
    local_14c = local_148;
    LVar4 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD","number",4,&local_14c,4);
    array_vpn_logprint(1,"route.cpp",0x638,"SaveLaunchCMD: save connected command number: %d, ret: %d.\n",local_14c,
                       LVar4);
    local_140[0] = '\0';
    local_40[0] = '\0';
    local_40[1] = '\0';
    local_40[2] = '\0';
    local_40[3] = '\0';
    local_40[4] = '\0';
    local_40[5] = '\0';
    local_40[6] = '\0';
    local_40[7] = '\0';
    local_40[8] = '\0';
    local_40[9] = '\0';
    local_40[10] = '\0';
    local_40[0xb] = '\0';
    local_40[0xc] = '\0';
    local_40[0xd] = '\0';
    local_40[0xe] = '\0';
    local_40[0xf] = '\0';
    memset(local_140 + 1,0,0xff);
    uVar2 = 0;
    if (local_148 != 0) {
      do {
        local_150 = (LPCWSTR)0x0;
        local_14 = CONCAT31(local_14._1_3_,1);
        (**(code **)(*local_144 + 0x34))(local_144,uVar2,&local_150);
        local_40[0] = '\0';
        local_40[1] = '\0';
        local_40[2] = '\0';
        local_40[3] = '\0';
        local_40[4] = '\0';
        local_40[5] = '\0';
        local_40[6] = '\0';
        local_40[7] = '\0';
        local_40[8] = '\0';
        local_40[9] = '\0';
        local_40[10] = '\0';
        local_40[0xb] = '\0';
        local_40[0xc] = '\0';
        local_40[0xd] = '\0';
        local_40[0xe] = '\0';
        local_40[0xf] = '\0';
        memset(local_140,0,0x100);
        FUN_004149f0(local_40,"LaunchCommand%02d",(char)uVar2);
        local_1d8 = local_1d4;
        FUN_00414430(&local_1d8,local_150,3);
        FUN_00414930(local_140,"%s",(char)local_1d8);
        if (local_1d8 != local_1d4) {
          free(local_1d8);
        }
        pcVar5 = local_140;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        LVar4 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2\\ConnectedCMD",local_40,1,local_140,
                            (DWORD)(pcVar5 + (1 - (int)(local_140 + 1))));
        array_vpn_logprint(1,"route.cpp",0x645,
                           "SaveLaunchCMD: save connected command data=%s, reg name=%s, set value ret=%d.\n",local_140,
                           local_40,LVar4);
        SysFreeString(local_150);
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_148);
    }
    DAT_00428dde = 1;
    FUN_0040fac0(1);
  }
LAB_0041023f:
  local_14 = 0xffffffff;
  if (local_144 != (int *)0x0) {
    (**(code **)(*local_144 + 8))(local_144);
  }
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)(local_40 + 0x30));
  return;
}



// ===== FUN_00410280 @ 00410280 =====

void FUN_00410280(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  HANDLE pvVar2;
  char *lpProcName;
  int *piVar3;
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  if (DAT_0042801c == 0xffffffff) {
    lpProcName = "IsWow64Process";
    local_c = 0;
    hModule = GetModuleHandleA("kernel32");
    pFVar1 = GetProcAddress(hModule,lpProcName);
    if (pFVar1 != (FARPROC)0x0) {
      piVar3 = &local_c;
      pvVar2 = GetCurrentProcess();
      (*pFVar1)(pvVar2,piVar3);
    }
    DAT_0042801c = (uint)(local_c != 0);
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00410300 @ 00410300 =====

void FUN_00410300(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  HANDLE pvVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  LPSTR pCVar5;
  undefined4 uVar6;
  char *pcVar7;
  DWORD *pDVar8;
  HKEY local_11c;
  DWORD local_118 [3];
  BYTE local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10b + 0x107);
  local_10c = '\0';
  memset(local_10b,0,0x103);
  local_11c = (HKEY)0x0;
  local_118[1] = 0x104;
  if (DAT_0042801c == 0xffffffff) {
    pcVar7 = "IsWow64Process";
    local_118[2] = 0;
    hModule = GetModuleHandleA("kernel32");
    pFVar1 = GetProcAddress(hModule,pcVar7);
    if (pFVar1 != (FARPROC)0x0) {
      pDVar8 = local_118 + 2;
      pvVar2 = GetCurrentProcess();
      (*pFVar1)(pvVar2,pDVar8);
    }
    DAT_0042801c = (uint)(local_118[2] != 0);
  }
  if (DAT_0042801c == 1) {
    LVar3 = RegOpenKeyExA((HKEY)0x80000002,"SYSTEM\\CurrentControlSet\\services\\ATP",0,0x20119,&local_11c);
    if (LVar3 == 0) {
LAB_00410425:
      local_118[0] = 1;
      LVar3 = RegQueryValueExA(local_11c,"DisplayName",(LPDWORD)0x0,local_118,&local_10c,local_118 + 1);
      if (LVar3 != 0) {
        DVar4 = GetLastError();
        array_vpn_logprint(3,"route.cpp",0x6a5,"IsArrayVNICAdapterExist:read value failed. Error = %d\n",DVar4);
        RegCloseKey(local_11c);
        FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
        return;
      }
      RegCloseKey(local_11c);
      array_vpn_logprint(1,"route.cpp",0x6aa,"IsArrayVNICAdapterExist: ATP DisplayName: %s\n",&local_10c);
      pCVar5 = StrStrA((LPCSTR)&local_10c,"Array Networks");
      if (pCVar5 != (LPSTR)0x0) {
LAB_004104f4:
        FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
        return;
      }
      pCVar5 = StrStrA((LPCSTR)&local_10c,"SSL VPN Driver");
      if (pCVar5 != (LPSTR)0x0) goto LAB_004104f4;
      goto LAB_004103e6;
    }
    DVar4 = GetLastError();
    pcVar7 = "IsArrayVNICAdapterExist(64):Open key failed. Error = %d\n";
    uVar6 = 0x694;
  }
  else {
    LVar3 = RegOpenKeyExA((HKEY)0x80000002,"SYSTEM\\CurrentControlSet\\services\\ATP",0,0x20019,&local_11c);
    if (LVar3 == 0) goto LAB_00410425;
    DVar4 = GetLastError();
    pcVar7 = "IsArrayVNICAdapterExist(32):Open key failed. Error = %d\n";
    uVar6 = 0x69c;
  }
  array_vpn_logprint(1,"route.cpp",uVar6,pcVar7,DVar4);
LAB_004103e6:
  FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
  return;
}



// ===== FUN_00410510 @ 00410510 =====

void FUN_00410510(void)

{
  LSTATUS LVar1;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000001,"Software\\VPN\\Install Manager","sstp_invalid_status",local_14,local_14 + 2,
                      local_14 + 1);
  if ((LVar1 == 0) && (local_14[2] == 1)) {
    SHDeleteValueA((HKEY)0x80000001,"Software\\VPN\\Install Manager","sstp_invalid_status");
    array_vpn_logprint(1,"route.cpp",0x6bd,
                       "reset_sstp_status to vnic because received lcp terminate request last time\n");
    FUN_00410710(2);
  }
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_004105b0 @ 004105b0 =====

void __fastcall FUN_004105b0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  BSTR bstrString;
  BSTR bstrString_00;
  BSTR bstrString_01;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041e1a0;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  array_vpn_logprint(1,"route.cpp",0x6c4,"SetVNICReconnTimes: %d\n",param_1,local_14);
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar2 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
    }
    if (iVar2 != 0) goto LAB_004106e0;
  }
  piVar1 = local_18;
  bstrString = SysAllocString(L"");
  if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 1;
  bstrString_00 = FUN_0040b940("VPNReconnectTimes");
  if (bstrString_00 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 2;
  bstrString_01 = FUN_0040b940("SOFTWARE\\VPN\\Install Manager");
  if (bstrString_01 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,4,bstrString_01,bstrString_00,bstrString,param_1);
  SysFreeString(bstrString_01);
  SysFreeString(bstrString_00);
  SysFreeString(bstrString);
LAB_004106e0:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00410710 @ 00410710 =====

void __fastcall FUN_00410710(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e208;
  local_10 = ExceptionList;
  uVar2 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar2;
  iVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
  if (iVar3 != 0) {
    if (iVar3 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar3 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_18);
    }
    if (iVar3 != 0) goto LAB_004108b3;
  }
  piVar1 = local_18;
  pOVar4 = SysAllocString(L"");
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 1;
  pOVar5 = FUN_0040b940("AdapterType");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 2;
  pOVar6 = FUN_0040b940("SOFTWARE\\VPN\\Install Manager");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 3;
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,4,pOVar6,pOVar5,pOVar4,param_1);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(pOVar4);
  piVar1 = local_18;
  pOVar4 = SysAllocString(L"");
  if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 4;
  pOVar5 = FUN_0040b940("AdapterType");
  if (pOVar5 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8._0_1_ = 5;
  pOVar6 = FUN_0040b940("SOFTWARE\\Wow6432Node\\VPN\\Install Manager");
  if (pOVar6 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  (**(code **)(*piVar1 + 0x5c))(piVar1,1,4,pOVar6,pOVar5,pOVar4,param_1);
  SysFreeString(pOVar6);
  SysFreeString(pOVar5);
  SysFreeString(pOVar4);
LAB_004108b3:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18,uVar2);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_004108f0 @ 004108f0 =====

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall FUN_004108f0(int param_1,BSTR param_2,int param_3)

{
  char cVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR pOVar4;
  BSTR bstrString;
  LPSTR pCVar5;
  u_long uVar6;
  void *pvVar7;
  undefined4 ****ppppuVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  code *pcVar12;
  uint uVar13;
  bool bVar14;
  int *piVar15;
  int local_4c38;
  undefined4 local_4c30 [2];
  uint local_4c28;
  undefined4 local_4c24;
  undefined4 local_4c20;
  undefined4 local_4c1c;
  undefined **local_4c18;
  undefined4 local_4c14;
  undefined4 local_4c10;
  undefined4 local_4c0c;
  undefined1 local_4c08;
  undefined4 local_4bf8;
  undefined4 local_4bf4;
  undefined1 local_4bf0;
  undefined4 local_4be0;
  undefined4 local_4bdc;
  undefined4 local_4bd8;
  undefined4 local_4bd4;
  undefined1 local_4bd0;
  void *local_4bc8 [4];
  int local_4bb8;
  uint local_4bb4;
  void *local_4bb0 [4];
  int local_4ba0;
  uint local_4b9c;
  undefined4 ****local_4b98 [4];
  undefined4 local_4b88;
  uint local_4b84;
  undefined4 local_4b80;
  undefined4 uStack_4b7c;
  undefined4 uStack_4b78;
  undefined4 uStack_4b74;
  undefined8 local_4b70;
  BSTR local_4b64;
  BSTR local_4b60;
  BSTR local_4b5c;
  BSTR local_4b58;
  BSTR local_4b54;
  char local_4b50 [16648];
  char local_a48;
  undefined1 local_a47 [1023];
  CHAR local_648;
  undefined1 local_647 [263];
  char local_540;
  undefined1 local_53f [263];
  char local_438;
  undefined1 local_437 [255];
  char local_338;
  undefined1 local_337 [255];
  undefined4 local_238;
  undefined4 local_130;
  undefined1 local_24 [9];
  undefined1 local_1b;
  uint local_18;
  undefined4 uStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar12 = array_vpn_logprint_exref;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041e364;
  local_10 = ExceptionList;
  uStack_14 = 0x41090b;
  local_18 = DAT_00428000 ^ (uint)(local_24 + 0x20);
  ExceptionList = &local_10;
  local_4b54 = param_2;
  array_vpn_logprint(1,"route.cpp",0x6ef,"start call interface wireguard, code=%d, errorcode=%d.\n",param_1,param_3,
                     local_18);
  local_4b64 = (BSTR)0x0;
  local_8 = 0;
  iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_4b64);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_4b64);
    }
    if (iVar2 != 0) {
      array_vpn_logprint(1,"route.cpp",0x6fe,"It seems can not call VPNService, error:%x\n",iVar2);
      goto LAB_00412125;
    }
  }
  local_648 = '\0';
  memset(local_647,0,0x103);
  GetModuleFileNameA((HMODULE)0x0,&local_648,0x104);
  PathRemoveFileSpecA(&local_648);
  PathAddBackslashA(&local_648);
  local_540 = '\0';
  memset(local_53f,0,0x103);
  local_a48 = '\0';
  memset(local_a47,0,0x3ff);
  local_4b50[0] = '\0';
  memset(local_4b50 + 1,0,0x4103);
  if (param_1 == 4) {
    array_vpn_logprint(1,"route.cpp",0x70c,"start call interface SwitchWGClient\n");
    array_vpn_logprint(1,"route.cpp",0x70f,"start call interface StartWGClient\n");
    FUN_004149b0(&local_540,"%s wg.conf",'x');
    memset(local_4b50,0,0x4104);
    FUN_00414a10(local_4b50,"%s&Endpoint=%s:%d&PublicKey=%s&wg_name=%s",-8);
    pcVar9 = local_4b50;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (pcVar9 != local_4b50 + 1) {
      array_vpn_logprint(1,"route.cpp",0x717,"before SwitchWGClient, the wg conf info:%s\n",local_4b50);
    }
    local_4b58 = local_4b64;
    pOVar3 = FUN_0040b940(local_4b50);
    local_4b5c = pOVar3;
    if (pOVar3 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 1;
    pOVar4 = FUN_0040b940(&DAT_0042d7f8);
    if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 2;
    local_4b54 = FUN_0040b940(&local_540);
    if (local_4b54 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 3;
    bstrString = FUN_0040b940("ArrayWGClient.exe");
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 4;
    local_4b60 = FUN_0040b940(&local_648);
    if (local_4b60 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    local_4b58 = (BSTR)(**(code **)(*(int *)local_4b58 + 0xd0))
                                 (local_4b58,4,local_4b60,bstrString,local_4b54,pOVar4,pOVar3);
    SysFreeString(local_4b60);
    SysFreeString(bstrString);
    SysFreeString(local_4b54);
    SysFreeString(pOVar4);
    SysFreeString(pOVar3);
    if (local_4b58 == (BSTR)0x0) {
      array_vpn_logprint(1,"route.cpp",0x71c,"vpnd: SwitchWGClient success\n");
    }
    else {
      array_vpn_logprint(3,"route.cpp",0x720,"vpnd: SwitchWGClient failed\n");
    }
    goto LAB_00412125;
  }
  if (param_1 == 1) {
    array_vpn_logprint(1,"route.cpp",0x726,"start call interface StartWGClient\n");
    FUN_004149b0(&local_540,"%s wg.conf",'x');
    FUN_00401d40(local_4bb0,(int *)&DAT_0041f7b1);
    local_8._0_1_ = 6;
    FUN_00401d40(local_4bc8,(int *)&DAT_0041f7b1);
    local_8 = CONCAT31(local_8._1_3_,7);
    if (param_2 == (BSTR)0x0) {
      pcVar9 = &DAT_004297f8;
      do {
        pcVar11 = pcVar9;
        pcVar9 = pcVar11 + 1;
      } while (*pcVar11 != '\0');
      array_vpn_logprint(1,"route.cpp",0x79b,
                         "StartWGClient: this is switch wireguard mode, it seems wg config file len is %d\n",
                         pcVar11 + -0x4297f8);
      if (0 < (int)(pcVar11 + -0x4297f8)) goto LAB_00411228;
      pcVar12 = operator_delete_exref;
    }
    else {
      memset(&DAT_0042dc00,0,0x100);
      FUN_00414930(&DAT_0042dc00,"%d.%d.%d.%d/32",(char)*param_2);
      if ((char)param_2[0xd4] == '\0') {
        local_238._0_1_ = '\0';
        memset((void *)((int)&local_238 + 1),0,0x103);
        local_130._0_1_ = '\0';
        memset((void *)((int)&local_130 + 1),0,0x103);
        uVar13 = 0;
        if (*(int *)(param_2 + 0xd6) != 0) {
          do {
            iVar2 = *(int *)(param_2 + 0xda);
            array_vpn_logprint(1,"route.cpp",0x73b,"StartVPNBySWG Include Zone:ip=%d.%d.%d.%d, mask=%d.%d.%d.%d\n",
                               *(undefined1 *)(iVar2 + uVar13 * 8),*(undefined1 *)(iVar2 + 1 + uVar13 * 8),
                               *(undefined1 *)(iVar2 + 2 + uVar13 * 8),*(undefined1 *)(iVar2 + 3 + uVar13 * 8),
                               *(undefined1 *)(iVar2 + 4 + uVar13 * 8),*(undefined1 *)(iVar2 + 5 + uVar13 * 8),
                               *(undefined1 *)(iVar2 + 6 + uVar13 * 8),*(undefined1 *)(iVar2 + 7 + uVar13 * 8));
            memset(&local_238,0,0x104);
            memset(&local_130,0,0x104);
            FUN_004149b0((char *)&local_238,"%d.%d.%d.%d",*(char *)(*(int *)(param_2 + 0xda) + uVar13 * 8));
            if (local_4ba0 != 0) {
              FUN_004083d0(local_4bb0,(int *)&DAT_0041ffa0);
            }
            if ((char)local_238 == '\0') {
              uVar10 = 0;
            }
            else {
              pcVar9 = (char *)&local_238;
              do {
                cVar1 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar1 != '\0');
              uVar10 = (int)pcVar9 - ((int)&local_238 + 1);
            }
            FUN_00409330(local_4bb0,&local_238,uVar10);
            FUN_004149b0((char *)&local_130,"%d.%d.%d.%d",*(char *)(*(int *)(param_2 + 0xda) + 4 + uVar13 * 8));
            pCVar5 = StrStrIA((LPCSTR)&local_130,"0.0.0.0");
            if (pCVar5 == (LPSTR)0x0) {
              uVar6 = ntohl(*(u_long *)(*(int *)(param_2 + 0xda) + 4 + uVar13 * 8));
              local_4b60 = (BSTR)FUN_004134f0(uVar6);
              iVar2 = *(int *)(param_2 + 0xda);
              uVar6 = ntohl(*(u_long *)(*(int *)(local_4b54 + 0xda) + 4 + uVar13 * 8));
              pOVar3 = local_4b60;
              array_vpn_logprint(1,"route.cpp",0x74c,
                                 "StartVPNBySWG: get wg zone mask len:%d, mask:%d.%d.%d.%d, mask:%x\n",local_4b60,
                                 *(undefined1 *)(iVar2 + 4 + uVar13 * 8),*(undefined1 *)(iVar2 + 5 + uVar13 * 8),
                                 *(undefined1 *)(iVar2 + 6 + uVar13 * 8),*(undefined1 *)(iVar2 + 7 + uVar13 * 8),uVar6);
              if ((int)pOVar3 - 1U < 0x20) {
                local_24[0] = '\0';
                local_1b = 0;
                local_24._1_8_ = 0;
                FUN_00414a30(local_24,"/%d",(char)pOVar3);
                piVar15 = (int *)local_24;
              }
              else {
                pCVar5 = StrStrIA((LPCSTR)&local_130,".0.0.0");
                if (pCVar5 == (LPSTR)0x0) {
                  pCVar5 = StrStrIA((LPCSTR)&local_130,".0.0");
                  if (pCVar5 == (LPSTR)0x0) {
                    pCVar5 = StrStrIA((LPCSTR)&local_130,".0");
                    if (pCVar5 == (LPSTR)0x0) {
                      piVar15 = (int *)&DAT_00422518;
                    }
                    else {
                      piVar15 = (int *)&DAT_00422514;
                    }
                  }
                  else {
                    piVar15 = (int *)&DAT_0042250c;
                  }
                }
                else {
                  piVar15 = (int *)&DAT_00422500;
                }
              }
              FUN_004083d0(local_4bb0,piVar15);
              param_2 = local_4b54;
            }
            else {
              FUN_004083d0(local_4bb0,(int *)&DAT_004224ac);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < *(uint *)(param_2 + 0xd6));
        }
        pcVar12 = array_vpn_logprint_exref;
      }
      else {
        array_vpn_logprint(1,"route.cpp",0x733,"StartVPNBySWG Include Zone: 0.0.0.0/0\n");
        FUN_00401dd0(local_4bb0,(int *)"0.0.0.0/0");
      }
      bVar14 = (*(uint *)(param_2 + 0xf8) & 0x20000000) == 0;
      if (bVar14) {
        (*pcVar12)(1,"route.cpp",0x772,"vpnd: AG server enable dnsproxy\n");
      }
      else {
        (*pcVar12)(1,"route.cpp",0x76d,"vpnd: AG server disable dnsproxy\n");
      }
      iVar2 = FUN_00413540();
      if (iVar2 == 1) {
        bVar14 = true;
      }
      else if (iVar2 == 0) {
        bVar14 = false;
      }
      if (((char)param_2[0xd4] != '\0') || (!bVar14)) {
        uVar13 = 0;
        if (*(int *)(param_2 + 0xe6) != 0) {
          do {
            memset(&local_130,0,0x104);
            iVar2 = *(int *)(param_2 + 0xea);
            array_vpn_logprint(1,"route.cpp",0x78c,"DNS list:ip=%d.%d.%d.%d\n",*(undefined1 *)(iVar2 + uVar13 * 4),
                               *(undefined1 *)(iVar2 + 1 + uVar13 * 4),*(undefined1 *)(iVar2 + 2 + uVar13 * 4),
                               *(undefined1 *)(iVar2 + 3 + uVar13 * 4));
            FUN_004149b0((char *)&local_130,"%d.%d.%d.%d",*(char *)(*(int *)(param_2 + 0xea) + uVar13 * 4));
            if (local_4bb8 != 0) {
              FUN_00409330(local_4bc8,(int *)&DAT_0041ffa0,1);
            }
            if ((char)local_130 == '\0') {
              uVar10 = 0;
            }
            else {
              pcVar9 = (char *)&local_130;
              do {
                cVar1 = *pcVar9;
                pcVar9 = pcVar9 + 1;
              } while (cVar1 != '\0');
              uVar10 = (int)pcVar9 - ((int)&local_130 + 1);
            }
            FUN_00409330(local_4bc8,&local_130,uVar10);
            uVar13 = uVar13 + 1;
          } while (uVar13 < *(uint *)(param_2 + 0xe6));
        }
        pcVar12 = array_vpn_logprint_exref;
      }
      else {
        FUN_00401dd0(local_4bc8,(int *)"127.0.0.1");
      }
      memset(&DAT_004297f8,0,0x4000);
      FUN_00414a50(&DAT_004297f8,"Address=%d.%d.%d.%d/32&AllowedIPs=%s&DNS=%s",(char)*param_2);
LAB_00411228:
      memset(local_4b50,0,0x4104);
      FUN_00414a10(local_4b50,"%s&Endpoint=%s:%d&PublicKey=%s&wg_name=%s",-8);
      local_338 = '\0';
      memset(local_337,0,0xff);
      local_438 = '\0';
      memset(local_437,0,0xff);
      local_130._0_1_ = '\0';
      memset((void *)((int)&local_130 + 1),0,0xff);
      local_238._0_1_ = '\0';
      memset((void *)((int)&local_238 + 1),0,0xff);
      pcVar9 = &DAT_0042e188;
      local_4b54 = (BSTR)0x0;
      local_4b58 = (BSTR)0x0;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (pcVar9 == &DAT_0042e189) {
        local_4b54 = (BSTR)0x1;
        local_4b58 = (BSTR)0x100;
        SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","session_id",(DWORD *)&local_4b54,&local_438,
                    (DWORD *)&local_4b58);
      }
      else {
        FUN_00414930(&local_438,"%s",-0x78);
      }
      pcVar9 = &DAT_0042e088;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (pcVar9 == &DAT_0042e089) {
        local_4b54 = (BSTR)0x1;
        local_4b58 = (BSTR)0x100;
        SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","vsite_name",(DWORD *)&local_4b54,&local_338,
                    (DWORD *)&local_4b58);
      }
      else {
        FUN_00414930(&local_338,"%s",-0x78);
      }
      pcVar9 = &DAT_0042df88;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (pcVar9 == &DAT_0042df89) {
        local_4b54 = (BSTR)0x1;
        local_4b58 = (BSTR)0x100;
        SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","wg_name",(DWORD *)&local_4b54,&local_238,(DWORD *)&local_4b58
                   );
      }
      else {
        FUN_00414930((char *)&local_238,"%s",-0x78);
      }
      local_4b54 = (BSTR)0x1;
      local_4b58 = (BSTR)0x100;
      SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","client_pub",(DWORD *)&local_4b54,&local_130,
                  (DWORD *)&local_4b58);
      memset(&local_4c18,0,0x4c);
      local_4c18 = Json::StyledWriter::vftable;
      local_4c14 = 0;
      local_4c10 = 0;
      local_4c0c = 0;
      local_4bf4 = 0xf;
      local_4bf8 = 0;
      local_4c08 = 0;
      local_4bdc = 0xf;
      local_4be0 = 0;
      local_4bf0 = 0;
      local_4bd8 = 0x4a;
      local_4bd4 = 3;
      local_4bd0 = 0;
      local_4b80 = 0;
      uStack_4b7c = 0;
      uStack_4b74 = 0;
      local_4b70 = 0;
      uStack_4b78 = 0;
      local_8._0_1_ = 10;
      local_4c24 = 0;
      local_4c28 = local_4c28 & 0xffffff04 | 0x104;
      local_4c20 = 0;
      local_4c1c = 0;
      local_4c30[0] = FUN_00404fd0(&local_338,0xffffffff);
      pcVar9 = (char *)local_4c30;
      local_8._0_1_ = 0xb;
      pvVar7 = (void *)FUN_004062c0(&local_4b80,"vsite_name");
      FUN_00405560(pvVar7,pcVar9);
      local_8._0_1_ = 10;
      FUN_004054d0(local_4c30);
      local_4c24 = 0;
      local_4c28 = local_4c28 & 0xffffff04 | 0x104;
      local_4c20 = 0;
      local_4c1c = 0;
      local_4c30[0] = FUN_00404fd0(&local_438,0xffffffff);
      pcVar9 = (char *)local_4c30;
      local_8._0_1_ = 0xc;
      pvVar7 = (void *)FUN_004062c0(&local_4b80,"session_id");
      FUN_00405560(pvVar7,pcVar9);
      local_8._0_1_ = 10;
      FUN_004054d0(local_4c30);
      local_4c24 = 0;
      local_4c28 = local_4c28 & 0xffffff04 | 0x104;
      local_4c20 = 0;
      local_4c1c = 0;
      local_4c30[0] = FUN_00404fd0((char *)&local_238,0xffffffff);
      pcVar9 = (char *)local_4c30;
      local_8._0_1_ = 0xd;
      pvVar7 = (void *)FUN_004062c0(&local_4b80,"wg_name");
      FUN_00405560(pvVar7,pcVar9);
      local_8._0_1_ = 10;
      FUN_004054d0(local_4c30);
      local_4c24 = 0;
      local_4c28 = local_4c28 & 0xffffff04 | 0x104;
      local_4c20 = 0;
      local_4c1c = 0;
      local_4c30[0] = FUN_00404fd0(&DAT_0042dc00,0xffffffff);
      pcVar9 = (char *)local_4c30;
      local_8._0_1_ = 0xe;
      pvVar7 = (void *)FUN_004062c0(&local_4b80,"client_ip");
      FUN_00405560(pvVar7,pcVar9);
      local_8._0_1_ = 10;
      FUN_004054d0(local_4c30);
      local_4c24 = 0;
      local_4c28 = local_4c28 & 0xffffff04 | 0x104;
      local_4c20 = 0;
      local_4c1c = 0;
      local_4c30[0] = FUN_00404fd0((char *)&local_130,0xffffffff);
      pcVar9 = (char *)local_4c30;
      local_8._0_1_ = 0xf;
      pvVar7 = (void *)FUN_004062c0(&local_4b80,"client_pub_key");
      FUN_00405560(pvVar7,pcVar9);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_004054d0(local_4c30);
      FUN_004072a0(&local_4c18,(undefined1 *)local_4b98,(double *)&local_4b80);
      memset(&local_a48,0,0x400);
      ppppuVar8 = local_4b98;
      if (0xf < local_4b84) {
        ppppuVar8 = local_4b98[0];
      }
      array_vpn_wg_start(1,ppppuVar8,&local_a48,0x400);
      pcVar9 = strstr(&local_a48,":0}");
      if (pcVar9 != (char *)0x0) {
        if (0xf < local_4b84) {
          operator_delete(local_4b98[0]);
        }
        local_4b84 = 0xf;
        local_4b88 = 0;
        local_4b98[0] = (undefined4 ****)((uint)local_4b98[0] & 0xffffff00);
        local_8 = CONCAT31(local_8._1_3_,8);
        FUN_004054d0(&local_4b80);
        FUN_004013c0(&local_4c18);
        local_4c38 = 1;
        if (0xf < local_4bb4) {
          operator_delete(local_4bc8[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_4bb4 = 0xf;
        local_4bb8 = 0;
        local_4bc8[0] = (void *)((uint)local_4bc8[0] & 0xffffff00);
        if (0xf < local_4b9c) {
          operator_delete(local_4bb0[0]);
        }
        goto LAB_00411f92;
      }
      (*pcVar12)(3,"route.cpp",0x7e2,"StartWGClient failed due to wg connect request is invalid\n");
      pcVar12 = operator_delete_exref;
      if (0xf < local_4b84) {
        operator_delete(local_4b98[0]);
      }
      local_4b84 = 0xf;
      local_4b88 = 0;
      local_4b98[0] = (undefined4 ****)((uint)local_4b98[0] & 0xffffff00);
      local_8 = CONCAT31(local_8._1_3_,8);
      FUN_004054d0(&local_4b80);
      FUN_004013c0(&local_4c18);
    }
    if (0xf < local_4bb4) {
      (*pcVar12)(local_4bc8[0]);
    }
    local_4bb4 = 0xf;
    local_4bb8 = 0;
    local_4bc8[0] = (void *)((uint)local_4bc8[0] & 0xffffff00);
    if (0xf < local_4b9c) {
      (*pcVar12)(local_4bb0[0]);
    }
  }
  else {
    if ((param_1 == 2) || (local_4c38 = 0, param_1 == 5)) {
      array_vpn_logprint(1,"route.cpp",0x7ec,"start call interface StopWGClient\n");
      FUN_004149b0(&local_540,"%s --stopvpn",'x');
      local_4c38 = param_1;
      if (param_3 == 2) {
        local_238._0_1_ = '\0';
        memset((void *)((int)&local_238 + 1),0,0xff);
        local_438 = '\0';
        memset(local_437,0,0xff);
        local_130._0_1_ = '\0';
        memset((void *)((int)&local_130 + 1),0,0xff);
        local_338 = '\0';
        memset(local_337,0,0xff);
        pcVar9 = &DAT_0042e188;
        local_4b58 = (BSTR)0x0;
        local_4b54 = (BSTR)0x0;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        if (pcVar9 == &DAT_0042e189) {
          local_4b5c = (BSTR)0x1;
          local_4b60 = (BSTR)0x100;
          SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","session_id",(DWORD *)&local_4b5c,&local_438,
                      (DWORD *)&local_4b60);
        }
        else {
          FUN_00414930(&local_438,"%s",-0x78);
        }
        pcVar9 = &DAT_0042e088;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        if (pcVar9 == &DAT_0042e089) {
          local_4b58 = (BSTR)0x1;
          local_4b54 = (BSTR)0x100;
          SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","vsite_name",(DWORD *)&local_4b58,&local_238,
                      (DWORD *)&local_4b54);
        }
        else {
          FUN_00414930((char *)&local_238,"%s",-0x78);
        }
        pcVar9 = &DAT_0042df88;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        if (pcVar9 == &DAT_0042df89) {
          local_4b58 = (BSTR)0x1;
          local_4b54 = (BSTR)0x100;
          SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","wg_name",(DWORD *)&local_4b58,&local_338,
                      (DWORD *)&local_4b54);
        }
        else {
          FUN_00414930(&local_338,"%s",-0x78);
        }
        local_4b58 = (BSTR)0x1;
        local_4b54 = (BSTR)0x100;
        SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","client_pub",(DWORD *)&local_4b58,&local_130,
                    (DWORD *)&local_4b54);
        memset(&local_4c18,0,0x4c);
        FUN_00407240(&local_4c18);
        local_4b80 = 0;
        uStack_4b7c = 0;
        uStack_4b74 = 0;
        local_4b70 = 0;
        uStack_4b78 = 0;
        local_8._0_1_ = 0x13;
        local_4c24 = 0;
        local_4c28 = local_4c28 & 0xffffff04 | 0x104;
        local_4c20 = 0;
        local_4c1c = 0;
        local_4c30[0] = FUN_00404fd0((char *)&local_238,0xffffffff);
        pcVar9 = (char *)local_4c30;
        local_8._0_1_ = 0x14;
        pvVar7 = (void *)FUN_004062c0(&local_4b80,"vsite_name");
        FUN_00405560(pvVar7,pcVar9);
        local_8._0_1_ = 0x13;
        FUN_004054d0(local_4c30);
        local_4c24 = 0;
        local_4c28 = local_4c28 & 0xffffff04 | 0x104;
        local_4c20 = 0;
        local_4c1c = 0;
        local_4c30[0] = FUN_00404fd0(&local_438,0xffffffff);
        pcVar9 = (char *)local_4c30;
        local_8._0_1_ = 0x15;
        pvVar7 = (void *)FUN_004062c0(&local_4b80,"session_id");
        FUN_00405560(pvVar7,pcVar9);
        local_8._0_1_ = 0x13;
        FUN_004054d0(local_4c30);
        local_4c24 = 0;
        local_4c28 = local_4c28 & 0xffffff04 | 0x104;
        local_4c20 = 0;
        local_4c1c = 0;
        local_4c30[0] = FUN_00404fd0(&local_338,0xffffffff);
        pcVar9 = (char *)local_4c30;
        local_8._0_1_ = 0x16;
        pvVar7 = (void *)FUN_004062c0(&local_4b80,"wg_name");
        FUN_00405560(pvVar7,pcVar9);
        local_8._0_1_ = 0x13;
        FUN_004054d0(local_4c30);
        local_4c24 = 0;
        local_4c28 = local_4c28 & 0xffffff04 | 0x104;
        local_4c20 = 0;
        local_4c1c = 0;
        local_4c30[0] = FUN_00404fd0(&DAT_0042dc00,0xffffffff);
        pcVar9 = (char *)local_4c30;
        local_8._0_1_ = 0x17;
        pvVar7 = (void *)FUN_004062c0(&local_4b80,"client_ip");
        FUN_00405560(pvVar7,pcVar9);
        local_8._0_1_ = 0x13;
        FUN_004054d0(local_4c30);
        local_4c24 = 0;
        local_4c28 = local_4c28 & 0xffffff04 | 0x104;
        local_4c20 = 0;
        local_4c1c = 0;
        local_4c30[0] = FUN_00404fd0((char *)&local_130,0xffffffff);
        pcVar9 = (char *)local_4c30;
        local_8._0_1_ = 0x18;
        pvVar7 = (void *)FUN_004062c0(&local_4b80,"client_pub_key");
        FUN_00405560(pvVar7,pcVar9);
        local_8 = CONCAT31(local_8._1_3_,0x13);
        FUN_004054d0(local_4c30);
        FUN_004072a0(&local_4c18,(undefined1 *)local_4b98,(double *)&local_4b80);
        memset(&local_a48,0,0x400);
        ppppuVar8 = local_4b98;
        if (0xf < local_4b84) {
          ppppuVar8 = local_4b98[0];
        }
        array_vpn_wg_start(2,ppppuVar8,&local_a48,0x400);
        if (0xf < local_4b84) {
          operator_delete(local_4b98[0]);
        }
        local_4b84 = 0xf;
        local_4b88 = 0;
        local_4b98[0] = (undefined4 ****)((uint)local_4b98[0] & 0xffffff00);
        local_8._0_1_ = 0x11;
        FUN_004054d0(&local_4b80);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_004013c0(&local_4c18);
      }
    }
    if (param_1 == 0) {
      local_4c38 = 0;
    }
LAB_00411f92:
    pcVar9 = local_4b50;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (pcVar9 != local_4b50 + 1) {
      (*pcVar12)(1,"route.cpp",0x836,"before StartWGClient, the wg conf info:%s\n",local_4b50);
    }
    local_4b5c = local_4b64;
    pOVar3 = FUN_0040b940(local_4b50);
    if (pOVar3 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0x19;
    pOVar4 = FUN_0040b940(&DAT_0042d7f8);
    if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0x1a;
    local_4b58 = FUN_0040b940(&local_540);
    if (local_4b58 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0x1b;
    local_4b54 = FUN_0040b940("ArrayWGClient.exe");
    if (local_4b54 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0x1c;
    local_4b60 = FUN_0040b940(&local_648);
    if (local_4b60 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8 = CONCAT31(local_8._1_3_,0x1d);
    local_4b5c = (BSTR)(**(code **)(*(int *)local_4b5c + 0xd0))
                                 (local_4b5c,local_4c38,local_4b60,local_4b54,local_4b58,pOVar4,pOVar3);
    SysFreeString(local_4b60);
    SysFreeString(local_4b54);
    SysFreeString(local_4b58);
    SysFreeString(pOVar4);
    SysFreeString(pOVar3);
    if (local_4b5c == (BSTR)0x0) {
      array_vpn_logprint(1,"route.cpp",0x83b,"vpnd: StartWGClient success\n");
    }
    else {
      array_vpn_logprint(3,"route.cpp",0x83f,"vpnd: StartWGClient failed\n");
    }
  }
LAB_00412125:
  local_8 = 0xffffffff;
  if (local_4b64 != (BSTR)0x0) {
    (**(code **)(*(int *)local_4b64 + 8))(local_4b64);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_24 + 0x20));
  return;
}



// ===== FUN_00412160 @ 00412160 =====

void __fastcall FUN_00412160(char param_1)

{
  uint uVar1;
  int iVar2;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041de28;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_14 = uVar1;
  array_vpn_logprint(1,"route.cpp",0x848,
                     "StopVPNByVNIC: start *******************************************************************\n",uVar1)
  ;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
    }
    if (iVar2 != 0) goto LAB_00412227;
  }
  array_vpn_logprint(1,"route.cpp",0x857,"start call interface ReleaseAdapterForMotionPro\n",uVar1);
  (**(code **)(*local_18 + 0x20))(local_18,-(uint)(param_1 != '\0'));
LAB_00412227:
  FUN_0040f460("-resumeproxyforvnic");
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00412260 @ 00412260 =====

void FUN_00412260(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  size_t _Size;
  LPSTR pCVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  BSTR bstrString;
  BSTR bstrString_00;
  BSTR bstrString_01;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  BSTR bstrString_02;
  char cVar12;
  BSTR local_4e4;
  BSTR local_4e0;
  BSTR local_4dc;
  undefined4 *local_4d8;
  BSTR local_4d4;
  BSTR local_4d0;
  BSTR local_4cc;
  uint local_4c8;
  uint local_4c4;
  undefined4 local_4c0;
  BSTR local_4bc;
  BSTR local_4b8;
  BSTR local_4b4;
  BSTR local_4b0;
  BSTR local_4ac;
  DWORD local_4a8 [2];
  uint local_4a0;
  BSTR local_49c;
  BSTR local_498;
  char local_494 [10];
  undefined1 local_48a [502];
  char local_294 [512];
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e4e5;
  local_10 = ExceptionList;
  uVar2 = DAT_00428000 ^ (uint)(local_94 + 0x90);
  ExceptionList = &local_10;
  local_49c = (BSTR)0x0;
  local_8 = 0;
  local_14 = uVar2;
  iVar3 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_49c);
  cVar12 = (char)uVar2;
  if (iVar3 != 0) {
    if (iVar3 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar3 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_49c);
    }
    if (iVar3 != 0) goto LAB_00412c54;
  }
  array_vpn_logprint(1,"route.cpp",0x86e,"start call interface ConnectByProxy.\n");
  pcVar9 = &DAT_004291e0;
  local_4c0 = 1;
  local_4c8 = 0;
  local_4c4 = 0;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  bVar11 = pcVar9 != &DAT_004291e1;
  if (bVar11) {
    array_vpn_logprint(1,"route.cpp",0x874,
                       "connect with proxy, proxyhost:%s, proxyport:%d, proxyusername:%s, proxydomain:%s.\n",
                       &DAT_004291e0,DAT_004293ec,&DAT_004287d0,&DAT_004292e8);
    local_4c0 = 3;
  }
  local_4c4 = (uint)bVar11;
  local_4c8 = (uint)bVar11;
  array_vpn_logprint(1,"route.cpp",0x87a,"StartVPNByVNIC: start vpn with address=%s.\n",&DAT_00428cd8);
  local_94[0] = '\0';
  memset(local_94 + 1,0,0x7f);
  pcVar9 = &DAT_00428de0;
  local_4a8[0] = 1;
  local_4a8[1] = 0;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if ((pcVar9 == &DAT_00428de1) || (pcVar9 = strstr(&DAT_00428de0,"motionProweb=1"), pcVar9 == (char *)0x0)) {
    local_4a8[1] = 0x80;
    SHGetValueA((HKEY)0x80000001,"Software\\VPN\\Install Manager","vnic_version",local_4a8,local_94,local_4a8 + 1);
    array_vpn_logprint(1,"route.cpp",0x886,"get vnic version: %s\n",local_94);
  }
  else {
    FUN_004149d0(local_94,"9.0.0.5",cVar12);
    array_vpn_logprint(1,"route.cpp",0x880,"this is web launch, set vnic version: %s\n",local_94);
  }
  local_294[0] = '\0';
  memset(local_294 + 1,0,0x1ff);
  pcVar9 = &DAT_00428de0;
  do {
    cVar12 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar12 != '\0');
  if (pcVar9 != &DAT_00428de1) {
    local_498 = (BSTR)CONCAT13(local_498._3_1_,0x2340);
    local_494[0] = '\0';
    memset(local_494 + 1,0,0x1ff);
    pcVar9 = strtok_s(&DAT_00428de0,(char *)&local_498,(char **)&local_4ac);
    if (pcVar9 != (char *)0x0) {
      do {
        memset(local_494,0,0x200);
        pcVar10 = pcVar9;
        do {
          cVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar12 != '\0');
        if ((uint)((int)pcVar10 - (int)(pcVar9 + 1)) < 0x201) {
          pcVar10 = pcVar9;
          do {
            cVar12 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar12 != '\0');
          _Size = (int)pcVar10 - (int)(pcVar9 + 1);
        }
        else {
          _Size = 0x200;
        }
        memcpy(local_494,pcVar9,_Size);
        pcVar9 = strstr(local_494,"CustomDNS=");
        if (pcVar9 != (char *)0x0) {
          pcVar9 = local_494;
          do {
            cVar12 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar12 != '\0');
          memcpy(local_294,local_48a,(size_t)(pcVar9 + (-10 - (int)(local_494 + 1))));
          array_vpn_logprint(1,"route.cpp",0x89a,"start vnic vpn: chCustomDNS:%s\n",local_294);
        }
        pcVar9 = strtok_s((char *)0x0,(char *)&local_498,(char **)&local_4ac);
      } while (pcVar9 != (char *)0x0);
    }
  }
  local_4a0 = 0;
  (**(code **)(*(int *)local_49c + 0xc0))(local_49c,&local_4a0);
  array_vpn_logprint(1,"route.cpp",0x8a2,"start vnic vpn: custom dns(%s)\n",local_294);
  pcVar9 = local_294;
  do {
    cVar12 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar12 != '\0');
  if ((pcVar9 == local_294 + 1) || (local_4a0 < 0x30)) {
    pcVar9 = local_94;
    do {
      cVar12 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar12 != '\0');
    if ((pcVar9 == local_94 + 1) || (pCVar4 = StrStrIA(local_94,"9.0.0.0"), pCVar4 == (LPSTR)0x0)) {
      local_4b0 = local_49c;
      bstrString = FUN_0040b940(&DAT_004292e8);
      local_4d4 = bstrString;
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x18;
      bstrString_00 = FUN_0040b940(&DAT_004295b0);
      local_4cc = bstrString_00;
      if (bstrString_00 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x19;
      bstrString_01 = FUN_0040b940(&DAT_004287d0);
      local_4d0 = bstrString_01;
      if (bstrString_01 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x1a;
      local_4b8 = FUN_0040b940(&DAT_004291e0);
      if (local_4b8 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x1b;
      local_4b4 = FUN_0040b940("9.0.0.5");
      if (local_4b4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x1c;
      local_4ac = FUN_0040b940(&DAT_004288d8);
      if (local_4ac == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x1d;
      local_4bc = FUN_0040b940(&DAT_00428cd8);
      if (local_4bc == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8 = CONCAT31(local_8._1_3_,0x1e);
    }
    else {
      local_4b0 = local_49c;
      bstrString = FUN_0040b940(&DAT_004292e8);
      local_4d4 = bstrString;
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x11;
      bstrString_00 = FUN_0040b940(&DAT_004295b0);
      local_4cc = bstrString_00;
      if (bstrString_00 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x12;
      bstrString_01 = FUN_0040b940(&DAT_004287d0);
      local_4d0 = bstrString_01;
      if (bstrString_01 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x13;
      local_4b8 = FUN_0040b940(&DAT_004291e0);
      if (local_4b8 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x14;
      local_4b4 = FUN_0040b940("9.0.0.0");
      if (local_4b4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x15;
      local_4ac = FUN_0040b940(&DAT_004288d8);
      if (local_4ac == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8._0_1_ = 0x16;
      local_4bc = FUN_0040b940(&DAT_00428cd8);
      if (local_4bc == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
      local_8 = CONCAT31(local_8._1_3_,0x17);
    }
    (**(code **)(*(int *)local_4b0 + 0x6c))
              (local_4b0,local_4bc,DAT_004292e4,local_4ac,local_4b4,local_4c0,local_4c8,local_4b8,DAT_004293ec,local_4c4
               ,bstrString_01,bstrString_00,bstrString);
    SysFreeString(local_4bc);
    SysFreeString(local_4ac);
    SysFreeString(local_4b4);
    bstrString_02 = local_4b8;
  }
  else {
    pcVar9 = local_94;
    do {
      cVar12 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar12 != '\0');
    if ((pcVar9 != local_94 + 1) && (pCVar4 = StrStrIA(local_94,"9.0.0.0"), pCVar4 != (LPSTR)0x0)) {
      local_498 = local_49c;
      local_4ac = (BSTR)FUN_0040ba10(&local_4b0,local_294);
      local_8._0_1_ = 1;
      local_4b4 = (BSTR)FUN_0040ba10(&local_4bc,&DAT_004292e8);
      local_8._0_1_ = 2;
      local_4b8 = (BSTR)FUN_0040ba10(&local_4d4,&DAT_004295b0);
      local_8._0_1_ = 3;
      local_4d8 = FUN_0040ba10(&local_4cc,&DAT_004287d0);
      local_8._0_1_ = 4;
      puVar5 = FUN_0040ba10(&local_4d0,&DAT_004291e0);
      local_8._0_1_ = 5;
      puVar6 = FUN_0040ba10(&local_4e0,"9.0.0.0");
      local_8._0_1_ = 6;
      puVar7 = FUN_0040ba10(&local_4e4,&DAT_004288d8);
      local_8._0_1_ = 7;
      puVar8 = FUN_0040ba10(&local_4dc,&DAT_00428cd8);
      local_8 = CONCAT31(local_8._1_3_,8);
      (**(code **)(*(int *)local_498 + 0xd8))
                (local_498,*puVar8,DAT_004292e4,*puVar7,*puVar6,local_4c0,local_4c8,*puVar5,DAT_004293ec,local_4c4,
                 *local_4d8,*(undefined4 *)local_4b8,*(undefined4 *)local_4b4,*(undefined4 *)local_4ac);
      SysFreeString(local_4dc);
      SysFreeString(local_4e4);
      SysFreeString(local_4e0);
      SysFreeString(local_4d0);
      SysFreeString(local_4cc);
      SysFreeString(local_4d4);
      SysFreeString(local_4bc);
      SysFreeString(local_4b0);
      goto LAB_00412c54;
    }
    local_4b0 = local_49c;
    bstrString = FUN_0040b940(local_294);
    local_4d4 = bstrString;
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 9;
    bstrString_00 = FUN_0040b940(&DAT_004292e8);
    local_4cc = bstrString_00;
    if (bstrString_00 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 10;
    bstrString_01 = FUN_0040b940(&DAT_004295b0);
    local_4d0 = bstrString_01;
    if (bstrString_01 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0xb;
    local_4ac = FUN_0040b940(&DAT_004287d0);
    if (local_4ac == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0xc;
    local_4b4 = FUN_0040b940(&DAT_004291e0);
    if (local_4b4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0xd;
    local_4b8 = FUN_0040b940("9.0.0.5");
    if (local_4b8 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0xe;
    local_498 = FUN_0040b940(&DAT_004288d8);
    if (local_498 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8._0_1_ = 0xf;
    local_4bc = FUN_0040b940(&DAT_00428cd8);
    if (local_4bc == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
    local_8 = CONCAT31(local_8._1_3_,0x10);
    (**(code **)(*(int *)local_4b0 + 0xd8))
              (local_4b0,local_4bc,DAT_004292e4,local_498,local_4b8,local_4c0,local_4c8,local_4b4,DAT_004293ec,local_4c4
               ,local_4ac,bstrString_01,bstrString_00,bstrString);
    SysFreeString(local_4bc);
    SysFreeString(local_498);
    SysFreeString(local_4b8);
    SysFreeString(local_4b4);
    bstrString_02 = local_4ac;
  }
  SysFreeString(bstrString_02);
  SysFreeString(bstrString_01);
  SysFreeString(bstrString_00);
  SysFreeString(bstrString);
LAB_00412c54:
  local_8 = 0xffffffff;
  if (local_49c != (BSTR)0x0) {
    (**(code **)(*(int *)local_49c + 8))(local_49c);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_94 + 0x90));
  return;
}



// ===== FUN_00412c90 @ 00412c90 =====
// decompile failed: Low-level Error: Cannot properly adjust input varnodes

// ===== FUN_00412e50 @ 00412e50 =====

void __fastcall FUN_00412e50(char *param_1)

{
  HANDLE hObject;
  int iVar1;
  undefined4 local_134 [2];
  DWORD local_12c;
  char local_110 [264];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_110 + 0x10c);
  hObject = (HANDLE)CreateToolhelp32Snapshot(2,0);
  if (hObject != (HANDLE)0xffffffff) {
    local_134[0] = 0x128;
    iVar1 = Process32First(hObject,local_134);
    if (iVar1 != 0) {
      do {
        iVar1 = _stricmp(local_110,param_1);
        if (iVar1 == 0) {
          OpenProcess(0x100001,0,local_12c);
          break;
        }
        iVar1 = Process32Next(hObject,local_134);
      } while (iVar1 != 0);
      CloseHandle(hObject);
      FUN_0041c21c(local_8 ^ (uint)(local_110 + 0x10c));
      return;
    }
    CloseHandle(hObject);
  }
  FUN_0041c21c(local_8 ^ (uint)(local_110 + 0x10c));
  return;
}



// ===== FUN_00412f30 @ 00412f30 =====

void FUN_00412f30(void)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_c = 0;
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","SSTPRedirectToVNIC",4,&local_c,4);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00412f80 @ 00412f80 =====

void FUN_00412f80(void)

{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  iVar1 = FUN_00412ff0();
  local_c = (uint)(7 < iVar1);
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","WindowsVersion10orAbove",4,&local_c,4);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00412ff0 @ 00412ff0 =====

void FUN_00412ff0(void)

{
  char cVar1;
  BOOL BVar2;
  int iVar3;
  _union_530 local_c8 [9];
  _OSVERSIONINFOA local_a4;
  char local_a;
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)&(&local_a4)[1].dwBuildNumber;
  GetSystemInfo((LPSYSTEM_INFO)&local_c8[0].s);
  memset(&local_a4,0,0x9c);
  local_a4.dwOSVersionInfoSize = 0x9c;
  BVar2 = GetVersionExA(&local_a4);
  if (((BVar2 == 0) || (local_a4.dwPlatformId == 1)) || (local_a4.dwPlatformId != 2)) goto LAB_004131da;
  if (local_a4.dwMajorVersion == 5) {
    if (local_a4.dwMinorVersion == 0) {
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
    if (local_a4.dwMinorVersion == 1) {
LAB_00413091:
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
    if (local_a4.dwMinorVersion == 2) {
      if ((local_a == '\x01') && (local_c8[0].s.wProcessorArchitecture == 9)) goto LAB_00413091;
      iVar3 = GetSystemMetrics(0x59);
      if ((iVar3 == 0) || (iVar3 = GetSystemMetrics(0x59), iVar3 != 0)) {
        FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
        return;
      }
    }
  }
  else if (local_a4.dwMajorVersion == 6) {
    if (local_a4.dwMinorVersion == 0) {
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
    if (local_a4.dwMinorVersion == 1) {
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
    if (1 < local_a4.dwMinorVersion) {
      cVar1 = FUN_0040bca0();
      if (cVar1 == '\0') {
        FUN_0040bca0();
        FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
        return;
      }
LAB_00413160:
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
  }
  else if (6 < local_a4.dwMajorVersion) {
    if (local_a4.dwBuildNumber < 22000) {
      FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
      return;
    }
    goto LAB_00413160;
  }
LAB_004131da:
  FUN_0041c21c(local_8 ^ (uint)&(&local_a4)[1].dwBuildNumber);
  return;
}



// ===== FUN_004131f0 @ 004131f0 =====

void FUN_004131f0(void)

{
  LPSTR pCVar1;
  char *pcVar2;
  LPCSTR lpSrch;
  char local_314;
  undefined1 local_313 [259];
  char local_210;
  undefined1 local_20f [259];
  CHAR local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10b + 0x107);
  local_210 = '\0';
  memset(local_20f,0,0x103);
  local_314 = '\0';
  memset(local_313,0,0x103);
  local_10c = '\0';
  memset(local_10b,0,0x103);
  GetTempPathA(0x104,&local_10c);
  lpSrch = "Low";
  pCVar1 = PathFindFileNameA(&local_10c);
  pCVar1 = StrStrIA(pCVar1,lpSrch);
  if (pCVar1 == (LPSTR)0x0) {
    FUN_004149b0(&local_210,"%s\\Low\\VPN\\Proxy.ini",(char)&local_10c);
    pcVar2 = "%s\\Low\\VPN\\Proxy_backup.ini";
  }
  else {
    FUN_004149b0(&local_210,"%s\\VPN\\Proxy.ini",(char)&local_10c);
    pcVar2 = "%s\\VPN\\Proxy_backup.ini";
  }
  FUN_004149b0(&local_314,pcVar2,(char)&local_10c);
  DeleteFileA(&local_210);
  DeleteFileA(&local_314);
  FUN_0041c21c(local_8 ^ (uint)(local_10b + 0x107));
  return;
}



// ===== FUN_00413300 @ 00413300 =====

void __fastcall FUN_00413300(int param_1,int param_2,int param_3)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD DVar3;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  array_vpn_logprint(1,"route.cpp",0x9e6,"wait_status_finished for %d, flag:%d, ipv6:%d\n",param_1,param_3,DAT_0042dbf8)
  ;
  if ((DAT_0042dbf8 == 1) || (iVar2 = 0, param_2 < 0)) {
LAB_00413446:
    FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
    return;
  }
  do {
    local_14[0] = 4;
    local_14[1] = 4;
    DVar3 = 0;
    iVar2 = iVar2 + 1;
    local_14[2] = 0;
    LVar1 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","MPStatus",local_14,local_14 + 2,local_14 + 1);
    if (LVar1 == 0) {
      DVar3 = local_14[2];
    }
    else {
      array_vpn_logprint(2,"route.cpp",0x1b7,"GetL3RealStatus failed, reg:%d\n",LVar1);
    }
    if (param_3 == 1) {
      if (DVar3 == param_1) {
        array_vpn_logprint(1,"route.cpp",0x9f5,"wait_status_finished: recv the real status: %d, break\n",param_1);
        FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
        return;
      }
    }
    else if (DVar3 != param_1) {
      array_vpn_logprint(1,"route.cpp",0x9fd,"wait_status_finished: Get L3 real status %d, not %d, break\n",DVar3,
                         param_1);
      goto LAB_00413446;
    }
    array_vpn_logprint(1,"route.cpp",0xa04,
                       "wait_status_finished: Get L3 real status: %d, loop:%d(1: connecting;  2:connected; 3:disconnecting; 4:disconnected)\n"
                       ,DVar3,iVar2);
    Sleep(400);
    if (param_2 < iVar2) {
      FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
      return;
    }
  } while( true );
}



// ===== FUN_00413460 @ 00413460 =====

void FUN_00413460(void)

{
  LSTATUS LVar1;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Install Manager","AdapterType",local_14,local_14 + 2,local_14 + 1
                     );
  if ((LVar1 == 0) && (local_14[2] == 2)) {
    FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
    return;
  }
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_004134f0 @ 004134f0 =====

int __fastcall FUN_004134f0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = ~param_1;
  for (uVar1 = uVar4 & 1; uVar1 != 0; uVar1 = (uVar1 ^ uVar2) & uVar4) {
    uVar3 = uVar3 + 1;
    uVar1 = 1 << (uVar3 & 0x1f);
    uVar2 = 0;
    if (0x1f < uVar3) {
      uVar2 = uVar1;
    }
  }
  if (uVar4 >> ((byte)uVar3 & 0x1f) == 0) {
    return 0x20 - uVar3;
  }
  return 0;
}



// ===== FUN_00413540 @ 00413540 =====

void FUN_00413540(void)

{
  LSTATUS LVar1;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","dnsproxy",local_14,local_14 + 2,local_14 + 1);
  array_vpn_logprint(1,"route.cpp",0xa32,"IPv4: enable dnsproxy: %d\n",local_14[2]);
  if (LVar1 == 0) {
    if ((local_14[2] == 1) || (local_14[2] == 3)) {
      array_vpn_logprint(1,"route.cpp",0xa38,"vpnd: AG client disable dnsproxy\n");
    }
    if ((local_14[2] == 0) || (local_14[2] == 2)) {
      array_vpn_logprint(1,"route.cpp",0xa3f,"vpnd: AG client enable dnsproxy\n");
      FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
      return;
    }
  }
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_00413630 @ 00413630 =====

void __fastcall FUN_00413630(LPCSTR param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  BSTR bstrString;
  LPCSTR pCVar6;
  uint local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e520;
  local_10 = ExceptionList;
  uVar3 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar3;
  iVar4 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
  if (iVar4 != 0) {
    if (iVar4 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      iVar4 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
    }
    if (iVar4 != 0) {
      array_vpn_logprint(1,"route.cpp",0xa56,"changeDNSServer:call vpn service failed.\n");
      goto LAB_0041377e;
    }
  }
  local_1c = 0;
  (**(code **)(*local_18 + 0xc0))(local_18,&local_1c,uVar3);
  array_vpn_logprint(1,"route.cpp",0xa5c,"changeDNSServer: custom dns(%s)\n",param_1);
  pCVar6 = param_1;
  do {
    cVar1 = *pCVar6;
    pCVar6 = pCVar6 + 1;
  } while (cVar1 != '\0');
  if ((pCVar6 != param_1 + 1) && (0x2f < local_1c)) {
    uVar5 = FUN_00413460();
    array_vpn_logprint(1,"route.cpp",0xa60,"changeDNSServer: adapterType: %d\n",uVar5);
    piVar2 = local_18;
    if (param_1 == (LPCSTR)0x0) {
      bstrString = (BSTR)0x0;
    }
    else {
      bstrString = FUN_0040b940(param_1);
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0040b9a0(0x8007000e);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*piVar2 + 0xdc))(piVar2,param_2,uVar5,bstrString);
    SysFreeString(bstrString);
  }
LAB_0041377e:
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_004137b0 @ 004137b0 =====

int __fastcall FUN_004137b0(LPCWSTR param_1,int param_2,undefined4 *param_3)

{
  uint _Size;
  void *pvVar1;
  int iVar2;
  
  if ((param_1 == (LPCWSTR)0x0) || (param_2 == 0)) {
    return -1;
  }
  _Size = WideCharToMultiByte(0xfde9,0,param_1,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (_Size == 0) {
    return -1;
  }
  pvVar1 = (void *)FUN_0041c1dc(_Size);
  *param_3 = pvVar1;
  if (pvVar1 != (void *)0x0) {
    memset(pvVar1,0,_Size);
    iVar2 = WideCharToMultiByte(0xfde9,0,param_1,param_2,(LPSTR)*param_3,_Size,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar2 != 0) {
      return iVar2;
    }
    pvVar1 = (void *)*param_3;
    operator_delete__(pvVar1);
    if (pvVar1 != (void *)0x0) {
      *param_3 = 0x8123;
    }
    *param_3 = 0;
  }
  return -1;
}



// ===== FUN_00413860 @ 00413860 =====

int __fastcall FUN_00413860(LPCSTR param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  uint cchWideChar;
  LPWSTR lpWideCharStr;
  int iVar2;
  
  if ((param_1 == (LPCSTR)0x0) || (param_2 == 0)) {
    return -1;
  }
  cchWideChar = MultiByteToWideChar(0x3a8,0,param_1,-1,(LPWSTR)0x0,0);
  if (cchWideChar == 0) {
    return -1;
  }
  lpWideCharStr =
       (LPWSTR)FUN_0041c1dc(-(uint)((int)((ulonglong)cchWideChar * 2 >> 0x20) != 0) | (uint)((ulonglong)cchWideChar * 2)
                           );
  *param_3 = lpWideCharStr;
  if (lpWideCharStr != (LPWSTR)0x0) {
    memset(lpWideCharStr,0,cchWideChar * 2);
    iVar2 = MultiByteToWideChar(0x3a8,0,param_1,param_2,lpWideCharStr,cchWideChar);
    if (iVar2 != 0) {
      return iVar2;
    }
    pvVar1 = (void *)*param_3;
    operator_delete__(pvVar1);
    if (pvVar1 != (void *)0x0) {
      *param_3 = 0x8123;
    }
    *param_3 = 0;
  }
  return -1;
}



// ===== FUN_00413920 @ 00413920 =====

undefined4 __fastcall FUN_00413920(LPCSTR param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *local_8;
  
  local_8 = (int *)0x0;
  piVar1 = (int *)(param_1 + 0x10);
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(LPCSTR *)param_1;
  }
  iVar2 = FUN_00413860(param_1,*piVar1,&local_8);
  piVar1 = local_8;
  if (iVar2 == -1) {
    return 0;
  }
  if ((short)*local_8 == 0) {
    uVar3 = 0;
  }
  else {
    piVar4 = local_8;
    do {
      iVar2 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 2);
    } while ((short)iVar2 != 0);
    uVar3 = (int)piVar4 - ((int)local_8 + 2) >> 1;
  }
  FUN_00414500(param_2,local_8,uVar3);
  operator_delete__(piVar1);
  return 1;
}



// ===== FUN_004139a0 @ 004139a0 =====

void __fastcall FUN_004139a0(LPCSTR param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  LPCWSTR ***ppppWVar3;
  uint uVar4;
  int *piVar5;
  int *local_30;
  LPCWSTR ***local_2c [4];
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  LPCWSTR **local_8;
  
  puStack_c = &LAB_0041e558;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_2c + 10);
  ExceptionList = &local_10;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (LPCWSTR ***)((uint)local_2c[0] & 0xffff0000);
  local_8 = (LPCWSTR **)0x0;
  iVar2 = FUN_00413920(param_1,local_2c);
  if (iVar2 != 0) {
    ppppWVar3 = (LPCWSTR ***)local_2c;
    if (7 < local_18) {
      ppppWVar3 = local_2c[0];
    }
    local_30 = (int *)0x0;
    iVar2 = FUN_004137b0((LPCWSTR)ppppWVar3,local_1c,&local_30);
    piVar1 = local_30;
    if (iVar2 != -1) {
      if ((char)*local_30 == '\0') {
        uVar4 = 0;
      }
      else {
        piVar5 = local_30;
        do {
          iVar2 = *piVar5;
          piVar5 = (int *)((int)piVar5 + 1);
        } while ((char)iVar2 != '\0');
        uVar4 = (int)piVar5 - ((int)local_30 + 1);
      }
      FUN_00401f80(param_2,local_30,uVar4);
      operator_delete__(piVar1);
    }
  }
  if (7 < local_18) {
    operator_delete(local_2c[0]);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_2c + 10));
  return;
}



// ===== FUN_00413a80 @ 00413a80 =====

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00413a80(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  HRESULT HVar4;
  LSTATUS LVar5;
  BSTR pOVar6;
  BSTR pOVar7;
  BSTR pOVar8;
  char *pcVar9;
  int *piVar10;
  int local_a130;
  DWORD local_a124 [2];
  int *local_a11c;
  char local_a118 [40964];
  char local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041e60f;
  local_10 = ExceptionList;
  uVar3 = DAT_00428000 ^ (uint)(local_113 + 0x10f);
  ExceptionList = &local_10;
  local_a118[0] = '\0';
  local_14 = uVar3;
  memset(local_a118 + 1,0,0xa000);
  local_114 = '\0';
  memset(local_113,0,0xff);
  local_a124[0] = 1;
  local_a124[1] = 0xa001;
  local_a11c = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  CoInitializeEx((LPVOID)0x0,0);
  HVar4 = CoCreateInstance((IID *)&DAT_00420354,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420344,&local_a11c);
  if (HVar4 == 0) {
    cVar2 = FUN_00410280();
    local_a130 = 1;
    do {
      memset(local_a118,0,0xa001);
      memset(&local_114,0,0x100);
      FUN_00414930(&local_114,"acl_%d",(char)local_a130);
      local_a124[0] = 1;
      local_a124[1] = 0xa001;
      LVar5 = SHGetValueA((HKEY)0x80000001,"Software\\VPN\\acl",&local_114,local_a124,local_a118,local_a124 + 1);
      piVar10 = local_a11c;
      if (LVar5 != 0) {
LAB_00413e42:
        array_vpn_logprint(1,"route.cpp",0xae9,"UpdateWGAclRule: the acl num: %d\n",local_a130 + -1);
        break;
      }
      pcVar9 = local_a118;
      do {
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (pcVar9 == local_a118 + 1) goto LAB_00413e42;
      if (cVar2 == '\0') {
        pOVar6 = SysAllocString(L"");
        if (pOVar6 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 7;
        pOVar7 = SysAllocString(L"size");
        if (pOVar7 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 8;
        pOVar8 = SysAllocString(L"SOFTWARE\\VPN\\AWG\\ACL");
        if (pOVar8 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 9;
        (**(code **)(*piVar10 + 0x5c))(piVar10,1,4,pOVar8,pOVar7,pOVar6,local_a130);
        SysFreeString(pOVar8);
        SysFreeString(pOVar7);
        local_8._0_1_ = 0;
        SysFreeString(pOVar6);
        piVar10 = local_a11c;
        pOVar6 = FUN_0040b940(local_a118);
        if (pOVar6 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 10;
        pOVar7 = FUN_0040b940(&local_114);
        if (pOVar7 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 0xb;
        pOVar8 = SysAllocString(L"SOFTWARE\\VPN\\AWG\\ACL");
        if (pOVar8 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 0xc;
      }
      else {
        pOVar6 = SysAllocString(L"");
        if (pOVar6 == (BSTR)0x0) {
LAB_00413e38:
                    /* WARNING: Subroutine does not return */
          FUN_0040b9a0(0x8007000e);
        }
        local_8._0_1_ = 1;
        pOVar7 = SysAllocString(L"size");
        if (pOVar7 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 2;
        pOVar8 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG\\ACL");
        if (pOVar8 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 3;
        (**(code **)(*piVar10 + 0x5c))(piVar10,1,4,pOVar8,pOVar7,pOVar6,local_a130);
        SysFreeString(pOVar8);
        SysFreeString(pOVar7);
        local_8._0_1_ = 0;
        SysFreeString(pOVar6);
        piVar10 = local_a11c;
        pOVar6 = FUN_0040b940(local_a118);
        if (pOVar6 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 4;
        pOVar7 = FUN_0040b940(&local_114);
        if (pOVar7 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 5;
        pOVar8 = SysAllocString(L"SOFTWARE\\Wow6432Node\\VPN\\AWG\\ACL");
        if (pOVar8 == (BSTR)0x0) goto LAB_00413e38;
        local_8._0_1_ = 6;
      }
      (**(code **)(*piVar10 + 0x5c))(piVar10,1,1,pOVar8,pOVar7,pOVar6,0);
      SysFreeString(pOVar8);
      SysFreeString(pOVar7);
      local_8._0_1_ = 0;
      SysFreeString(pOVar6);
      local_a130 = local_a130 + 1;
    } while (local_a130 < 0x2801);
  }
  else {
    array_vpn_logprint(3,"route.cpp",0xace,"UpdateWGAclRule: call vpninstallmanager failed, acl feature works failed.\n"
                       ,uVar3);
  }
  local_8 = 0xffffffff;
  if (local_a11c != (int *)0x0) {
    (**(code **)(*local_a11c + 8))(local_a11c);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_113 + 0x10f));
  return;
}



// ===== FUN_00413ea0 @ 00413ea0 =====

void FUN_00413ea0(void)

{
  char cVar1;
  LSTATUS LVar2;
  char *pcVar3;
  DWORD local_114 [2];
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10c + 0x108);
  local_10c[0] = '\0';
  memset(local_10c + 1,0,0x103);
  local_114[1] = 1;
  local_114[0] = 0x104;
  LVar2 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","VPNMachineCPUID",local_114 + 1,local_10c,local_114);
  if (LVar2 == 0) {
    pcVar3 = local_10c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((pcVar3 != local_10c + 1) && ((uint)((int)pcVar3 - (int)(local_10c + 1)) < 0x105)) goto LAB_00413f73;
  }
  array_vpn_logprint(1,"route.cpp",0xaf9,"ArrayUpdateCPUID: start...\n");
  FUN_0040c040(0xe,&DAT_0041f7b1);
  array_vpn_logprint(1,"route.cpp",0xafb,"ArrayUpdateCPUID: finished\n");
LAB_00413f73:
  FUN_0041c21c(local_8 ^ (uint)(local_10c + 0x108));
  return;
}



// ===== FUN_00413f90 @ 00413f90 =====

void FUN_00413f90(void)

{
  LSTATUS LVar1;
  DWORD local_14 [3];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_14 + 4);
  local_14[0] = 4;
  local_14[2] = 0;
  local_14[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\VPN2","sslerror",local_14,local_14 + 2,local_14 + 1);
  if (LVar1 == 0) {
    array_vpn_logprint(1,"route.cpp",0xb0a,"GetSSLErrorValue finished, ret:%d, value:%d\n",0,local_14[2]);
    FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
    return;
  }
  FUN_0041c21c(local_8 ^ (uint)(local_14 + 4));
  return;
}



// ===== FUN_00414020 @ 00414020 =====

void FUN_00414020(void)

{
  uint uVar1;
  HRESULT HVar2;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041de28;
  local_10 = ExceptionList;
  uVar1 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_18 = (int *)0x0;
  local_8 = 0;
  local_14 = uVar1;
  HVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
  if (HVar2 == 0) {
    array_vpn_logprint(1,"route.cpp",0xb28,"UpdateVPNService: vpnservice is work fine\n",uVar1);
  }
  else {
    array_vpn_logprint(1,"route.cpp",0xb1a,"UpdateVPNService: create instance to vpnservice failed, error: %x\n",HVar2);
    if (HVar2 == -0x7ffbfe10) {
      CoInitializeEx((LPVOID)0x0,0);
      HVar2 = CoCreateInstance((IID *)&DAT_00420374,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00420364,&local_18);
    }
    if (HVar2 != 0) {
      array_vpn_logprint(1,"route.cpp",0xb10,"InstallVPNService: start...\n",uVar1);
      FUN_0040c040(0xf,&DAT_0041f7b1);
    }
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00414140 @ 00414140 =====

undefined1 * __thiscall FUN_00414140(void *this,undefined1 *param_1,uint param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00401e50(param_1,this,param_2,param_3);
  return param_1;
}



// ===== FUN_00414180 @ 00414180 =====

void __fastcall FUN_00414180(undefined4 *param_1)

{
  if (7 < (uint)param_1[5]) {
    operator_delete((void *)*param_1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  return;
}



// ===== FUN_004141b0 @ 004141b0 =====

void __fastcall FUN_004141b0(int *param_1)

{
  int iVar1;
  int *_Memory;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    free(_Memory);
    iVar1 = *param_1;
  }
  return;
}



// ===== FUN_004141e0 @ 004141e0 =====

void __fastcall FUN_004141e0(undefined4 *param_1)

{
  HRESULT HVar1;
  
  if ((SAFEARRAY *)*param_1 != (SAFEARRAY *)0x0) {
    HVar1 = SafeArrayUnlock((SAFEARRAY *)*param_1);
    if (-1 < HVar1) {
      HVar1 = SafeArrayDestroy((SAFEARRAY *)*param_1);
      if (-1 < HVar1) {
        *param_1 = 0;
      }
    }
  }
  return;
}



// ===== FUN_00414210 @ 00414210 =====

void __thiscall FUN_00414210(void *this,VARIANTARG *param_1)

{
  int iVar1;
  HRESULT HVar2;
  LONG local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  if (*(int *)this == 0) {
    iVar1 = FUN_00414300(this);
    if (iVar1 < 0) goto LAB_004142cf;
  }
  local_14 = 0;
  HVar2 = SafeArrayGetLBound(*(SAFEARRAY **)this,1,&local_14);
  if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(HVar2);
  }
  HVar2 = SafeArrayGetLBound(*(SAFEARRAY **)this,1,&local_10);
  if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(HVar2);
  }
  HVar2 = SafeArrayGetUBound(*(SAFEARRAY **)this,1,&local_c);
  if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(HVar2);
  }
  iVar1 = FUN_00414380(this,(local_c - local_10) + 2,local_14);
  if (-1 < iVar1) {
    HVar2 = SafeArrayGetLBound(*(SAFEARRAY **)this,1,&local_c);
    if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(HVar2);
    }
    HVar2 = SafeArrayGetUBound(*(SAFEARRAY **)this,1,&local_10);
    if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(HVar2);
    }
    FUN_0040bbf0(this,(local_10 - local_c) + local_14,param_1);
  }
LAB_004142cf:
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00414300 @ 00414300 =====

void __fastcall FUN_00414300(int *param_1)

{
  SAFEARRAY *psa;
  SAFEARRAYBOUND local_10;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_10.cElements = 0;
  local_10.lLbound = 0;
  if (*param_1 != 0) {
    FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
    return;
  }
  psa = SafeArrayCreate(0xc,1,&local_10);
  *param_1 = (int)psa;
  if (psa == (SAFEARRAY *)0x0) {
    FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
    return;
  }
  SafeArrayLock(psa);
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00414380 @ 00414380 =====

void __thiscall FUN_00414380(void *this,ULONG param_1,LONG param_2)

{
  SAFEARRAY *psa;
  HRESULT HVar1;
  SAFEARRAYBOUND local_10;
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (int)register0x00000010 - 4U;
  local_10.cElements = param_1;
  local_10.lLbound = param_2;
  psa = *(SAFEARRAY **)this;
  if (psa == (SAFEARRAY *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x80004005);
  }
  if ((~((byte)psa->fFeatures >> 4) & 1) == 0) {
    FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
    return;
  }
  HVar1 = SafeArrayUnlock(psa);
  if (-1 < HVar1) {
    SafeArrayRedim(*(SAFEARRAY **)this,&local_10);
    SafeArrayLock(*(SAFEARRAY **)this);
  }
  FUN_0041c21c(local_8 ^ (int)register0x00000010 - 4U);
  return;
}



// ===== FUN_00414420 @ 00414420 =====

void FUN_00414420(void)

{
  return;
}



// ===== FUN_00414430 @ 00414430 =====

void __thiscall FUN_00414430(void *this,LPCWSTR param_1,UINT param_2)

{
  WCHAR WVar1;
  code *pcVar2;
  LPCWSTR pWVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  size_t cbMultiByte;
  bool bVar7;
  
  if (param_1 == (LPCWSTR)0x0) {
    *(undefined4 *)this = 0;
    return;
  }
  pWVar3 = param_1;
  do {
    WVar1 = *pWVar3;
    pWVar3 = pWVar3 + 1;
  } while (WVar1 != L'\0');
  iVar4 = ((int)pWVar3 - (int)(param_1 + 1) >> 1) + 1;
  FUN_00414a90(this,iVar4 * 4,(void *)((int)this + 4));
  iVar5 = WideCharToMultiByte(param_2,0,param_1,iVar4,*(LPSTR *)this,iVar4 * 4,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar5 == 0) {
    DVar6 = GetLastError();
    bVar7 = true;
    if (DVar6 == 0x7a) {
      cbMultiByte = WideCharToMultiByte(param_2,0,param_1,iVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      FUN_00414a90(this,cbMultiByte,(void *)((int)this + 4));
      iVar4 = WideCharToMultiByte(param_2,0,param_1,iVar4,*(LPSTR *)this,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
      bVar7 = iVar4 == 0;
    }
    if (bVar7) {
      FUN_0040b9c0();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  return;
}



// ===== FUN_00414500 @ 00414500 =====

int * __thiscall FUN_00414500(void *this,int *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  int *piVar4;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    if (uVar1 < 8) {
      piVar4 = this;
    }
    else {
      piVar4 = *(int **)this;
    }
    if (piVar4 <= param_1) {
      if (uVar1 < 8) {
        pvVar3 = this;
      }
      else {
        pvVar3 = *(void **)this;
      }
      if (param_1 < (int *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2)) {
        if (uVar1 < 8) {
          pvVar3 = this;
        }
        else {
          pvVar3 = *(void **)this;
        }
        piVar4 = FUN_004145b0(this,this,(int)param_1 - (int)pvVar3 >> 1,param_2);
        return piVar4;
      }
    }
  }
  bVar2 = FUN_004146a0(this,param_2);
  if (bVar2) {
    if (*(uint *)((int)this + 0x14) < 8) {
      pvVar3 = this;
    }
    else {
      pvVar3 = *(void **)this;
    }
    if (param_2 != 0) {
      memcpy(pvVar3,param_1,param_2 * 2);
    }
    *(uint *)((int)this + 0x10) = param_2;
    if (7 < *(uint *)((int)this + 0x14)) {
      *(undefined2 *)(*(int *)this + param_2 * 2) = 0;
      return this;
    }
    *(undefined2 *)((int)this + param_2 * 2) = 0;
  }
  return this;
}



// ===== FUN_004145b0 @ 004145b0 =====

int * __thiscall FUN_004145b0(void *this,int *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  void *_Dst;
  uint uVar2;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  uVar2 = param_1[4] - param_2;
  if (param_3 < uVar2) {
    uVar2 = param_3;
  }
  if (this != param_1) {
    bVar1 = FUN_004146a0(this,uVar2);
    if (bVar1) {
      if (7 < (uint)param_1[5]) {
        param_1 = (int *)*param_1;
      }
      if (*(uint *)((int)this + 0x14) < 8) {
        _Dst = this;
      }
      else {
        _Dst = *(void **)this;
      }
      if (uVar2 != 0) {
        memcpy(_Dst,(void *)((int)param_1 + param_2 * 2),uVar2 * 2);
      }
      *(uint *)((int)this + 0x10) = uVar2;
      if (7 < *(uint *)((int)this + 0x14)) {
        *(undefined2 *)(*(int *)this + uVar2 * 2) = 0;
        return this;
      }
      *(undefined2 *)((int)this + uVar2 * 2) = 0;
    }
    return this;
  }
  uVar2 = uVar2 + param_2;
  if (*(uint *)((int)this + 0x10) < uVar2) {
                    /* WARNING: Subroutine does not return */
    std::_Xout_of_range("invalid string position");
  }
  *(uint *)((int)this + 0x10) = uVar2;
  if (*(uint *)((int)this + 0x14) < 8) {
    *(undefined2 *)((int)this + uVar2 * 2) = 0;
    FUN_00414700(this,param_2,param_2);
    return this;
  }
  *(undefined2 *)(*(int *)this + uVar2 * 2) = 0;
  FUN_00414700(this,param_2,param_2);
  return this;
}



// ===== FUN_004146a0 @ 004146a0 =====

bool __thiscall FUN_004146a0(void *this,uint param_1)

{
  if (0x7ffffffe < param_1) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("string too long");
  }
  if (*(uint *)((int)this + 0x14) < param_1) {
    FUN_00414790(this,param_1,*(int *)((int)this + 0x10));
    return param_1 != 0;
  }
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    *(undefined2 *)this = 0;
  }
  return param_1 != 0;
}



// ===== FUN_00414700 @ 00414700 =====

int * __thiscall FUN_00414700(void *this,undefined4 param_1,uint param_2)

{
  void *_Dst;
  int iVar1;
  
  if (*(uint *)((int)this + 0x10) <= param_2) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if (*(uint *)((int)this + 0x14) < 8) {
      *(undefined2 *)this = 0;
      return this;
    }
    **(undefined2 **)this = 0;
    return this;
  }
  if (param_2 != 0) {
    if (*(uint *)((int)this + 0x14) < 8) {
      _Dst = this;
    }
    else {
      _Dst = *(void **)this;
    }
    iVar1 = *(uint *)((int)this + 0x10) - param_2;
    if (iVar1 != 0) {
      memmove(_Dst,(void *)((int)_Dst + param_2 * 2),iVar1 * 2);
    }
    *(int *)((int)this + 0x10) = iVar1;
    if (7 < *(uint *)((int)this + 0x14)) {
      *(undefined2 *)(*(int *)this + iVar1 * 2) = 0;
      return this;
    }
    *(undefined2 *)((int)this + iVar1 * 2) = 0;
  }
  return this;
}



// ===== FUN_00414790 @ 00414790 =====

void __thiscall FUN_00414790(void *this,uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  void *_Src;
  uint uVar3;
  void *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0041e640;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar3 = param_1 | 7;
  if (uVar3 < 0x7fffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar2 = uVar1 >> 1;
    if ((uVar3 / 3 < uVar2) && (uVar3 = uVar2 + uVar1, 0x7ffffffe - uVar2 < uVar1)) {
      uVar3 = 0x7ffffffe;
    }
  }
  else {
    uVar3 = param_1;
  }
  uVar1 = uVar3 + 1;
  local_8 = 0;
  local_18 = (void *)0x0;
  if (uVar1 != 0) {
    if (uVar1 < 0x80000000) {
      local_18 = operator_new(uVar1 * 2);
      if (local_18 != (void *)0x0) goto LAB_00414859;
    }
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
LAB_00414859:
  if (param_2 != 0) {
    if (*(uint *)((int)this + 0x14) < 8) {
      _Src = this;
    }
    else {
      _Src = *(void **)this;
    }
    if (param_2 != 0) {
      memcpy(local_18,_Src,param_2 * 2);
    }
  }
  if (7 < *(uint *)((int)this + 0x14)) {
    operator_delete(*(void **)this);
  }
  *(void **)this = local_18;
  *(uint *)((int)this + 0x14) = uVar3;
  *(int *)((int)this + 0x10) = param_2;
  if (7 < uVar3) {
    this = local_18;
  }
  *(undefined2 *)((int)this + param_2 * 2) = 0;
  ExceptionList = local_10;
  return;
}



// ===== Catch_All@00414830 @ 00414830 =====

undefined * Catch_All_00414830(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + 8) = iVar1;
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pvVar2 = FUN_004148f0(iVar1 + 1);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  return &DAT_0041484d;
}



// ===== Catch_All@0041486a @ 0041486a =====

void Catch_All_0041486a(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x18);
  if (7 < (uint)puVar1[5]) {
    operator_delete((void *)*puVar1);
  }
  puVar1[5] = 7;
  puVar1[4] = 0;
  *(undefined2 *)puVar1 = 0;
                    /* WARNING: Subroutine does not return */
  _CxxThrowException((void *)0x0,(ThrowInfo *)0x0);
}



// ===== FUN_004148f0 @ 004148f0 =====

void * FUN_004148f0(uint param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    return (void *)0x0;
  }
  if ((0x7fffffff < param_1) || (pvVar1 = operator_new(param_1 * 2), pvVar1 == (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    std::_Xbad_alloc();
  }
  return pvVar1;
}



// ===== FUN_00414930 @ 00414930 =====

void __cdecl FUN_00414930(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x100,param_2,&param_3);
  return;
}



// ===== FUN_00414950 @ 00414950 =====

void __cdecl FUN_00414950(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x40,param_2,&param_3);
  return;
}



// ===== FUN_00414970 @ 00414970 =====

void __cdecl FUN_00414970(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x200,param_2,&param_3);
  return;
}



// ===== FUN_00414990 @ 00414990 =====

void __cdecl FUN_00414990(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x800,param_2,&param_3);
  return;
}



// ===== FUN_004149b0 @ 004149b0 =====

void __cdecl FUN_004149b0(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x104,param_2,&param_3);
  return;
}



// ===== FUN_004149d0 @ 004149d0 =====

void __cdecl FUN_004149d0(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x80,param_2,&param_3);
  return;
}



// ===== FUN_004149f0 @ 004149f0 =====

void __cdecl FUN_004149f0(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x10,param_2,&param_3);
  return;
}



// ===== FUN_00414a10 @ 00414a10 =====

void __cdecl FUN_00414a10(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x4104,param_2,&param_3);
  return;
}



// ===== FUN_00414a30 @ 00414a30 =====

void __cdecl FUN_00414a30(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,10,param_2,&param_3);
  return;
}



// ===== FUN_00414a50 @ 00414a50 =====

void __cdecl FUN_00414a50(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x4000,param_2,&param_3);
  return;
}



// ===== FUN_00414a70 @ 00414a70 =====

void __cdecl FUN_00414a70(char *param_1,char *param_2,char param_3)

{
  vsprintf_s(param_1,0x400,param_2,&param_3);
  return;
}



// ===== FUN_00414a90 @ 00414a90 =====

void __fastcall FUN_00414a90(int *param_1,size_t param_2,void *param_3)

{
  void *pvVar1;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x80070057);
  }
  if ((int)param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x80070057);
  }
  if (param_3 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x80070057);
  }
  pvVar1 = (void *)*param_1;
  if (pvVar1 == param_3) {
    if ((int)param_2 < 0x81) goto LAB_00414ad1;
    pvVar1 = calloc(param_2,1);
  }
  else {
    if ((int)param_2 < 0x81) {
      free(pvVar1);
LAB_00414ad1:
      *param_1 = (int)param_3;
      goto LAB_00414ad3;
    }
    pvVar1 = _recalloc(pvVar1,param_2,1);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0040b9a0(0x8007000e);
    }
  }
  *param_1 = (int)pvVar1;
LAB_00414ad3:
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0040b9a0(0x8007000e);
  }
  return;
}



// ===== FUN_00414b30 @ 00414b30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00414b30(void)

{
  void *local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  void *local_8;
  
  local_8 = (void *)0xffffffff;
  puStack_c = &LAB_0041e67e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = &DAT_0042e300;
  _DAT_0042e300 = VPNNetworks::IPC::IMsgHandler::vftable;
  _DAT_0042e36c = 0xff98;
  array_vpn_logprint(1,"..\\common\\ipc.cpp",0x9f,"ipc server start using port:%d\n",0xff98,
                     DAT_00428000 ^ (uint)(local_30 + 0xb));
  _DAT_0042e338 = 0xff98;
  DAT_0042e368 = 0;
  DAT_0042e3a4 = 0;
  local_8 = (void *)0x0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (void *)((uint)local_30[0] & 0xffffff00);
  FUN_00401f80(local_30,(int *)"daemon",6);
  local_18 = &DAT_0042e304;
  _DAT_0042e304 = VPNNetworks::IPC::LongPollClient::vftable;
  DAT_0042e31c = 0xf;
  _DAT_0042e318 = 0;
  DAT_0042e308._0_1_ = 0;
  local_8 = (void *)CONCAT31(local_8._1_3_,2);
  FUN_00401e50(&DAT_0042e308,(int *)local_30,0,0xffffffff);
  _DAT_0042e320 = 0xff97;
  DAT_0042e330 = 1;
  if (0xf < local_1c) {
    operator_delete(local_30[0]);
  }
  _DAT_0042e300 = VpnService::vftable;
  _DAT_0042e304 = VpnService::vftable;
  DAT_0042e3a8 = 0;
  DAT_0042e3ac = 0;
  _DAT_0042e3b0 = 0;
  DAT_0042e3c8 = 0xf;
  _DAT_0042e3c4 = 0;
  DAT_0042e3b4._0_1_ = 0;
  DAT_0042e3e0 = 0xf;
  _DAT_0042e3dc = 0;
  DAT_0042e3cc._0_1_ = 0;
  ExceptionList = local_10;
  return &DAT_0042e300;
}



// ===== FUN_00414dc0 @ 00414dc0 =====

void FUN_00414dc0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  char ****ppppcVar4;
  u_short *puVar5;
  char *pcVar6;
  undefined4 local_b4;
  undefined8 local_b0;
  uint local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined **local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50;
  char ****local_48 [4];
  int local_38;
  uint local_34;
  undefined4 *local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_24;
  undefined8 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  char ***local_8;
  
  local_8 = (char ***)0xffffffff;
  puStack_c = &LAB_0041e700;
  local_10 = ExceptionList;
  local_18 = DAT_00428000 ^ (uint)(local_48 + 0x11);
  ExceptionList = &local_10;
  memset(&local_98,0,0x4c);
  local_98 = Json::StyledWriter::vftable;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_74 = 0xf;
  local_78 = 0;
  local_88 = 0;
  local_5c = 0xf;
  local_60 = 0;
  local_70 = 0;
  local_58 = 0x4a;
  local_54 = 3;
  local_50 = 0;
  local_30 = (undefined4 *)0x0;
  uStack_2c = 0;
  pvStack_24 = (void *)0x0;
  local_20 = 0;
  uStack_28 = 0;
  local_a4 = 0;
  local_a8 = local_a8 & 0xfffffe01 | 1;
  local_a0 = 0;
  local_9c = 0;
  local_b0 = 0;
  pcVar6 = (char *)&local_b0;
  local_8 = (char ***)0x3;
  pvVar2 = (void *)FUN_004062c0(&local_30,"error");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_b0);
  local_a4 = 0;
  local_a8 = local_a8 & 0xfffffe01 | 1;
  local_a0 = 0;
  local_9c = 0;
  local_b0 = 10;
  local_8._0_1_ = 4;
  pvVar2 = (void *)FUN_004062c0(&local_30,"data");
  pcVar6 = (char *)&local_b0;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"action");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_b0);
  if (param_1 == 1) {
    array_vpn_logprint(1,"vpnd.cpp",0x6d,"send message to clients: DD disconnect.\n");
    local_b0 = 0x75;
    local_8._0_1_ = 5;
  }
  else {
    array_vpn_logprint(1,"vpnd.cpp",0x72,"send message to clients: Web disconnect.\n");
    local_b0 = 0;
    local_8._0_1_ = 6;
  }
  local_a8 = local_a8 & 0xfffffe01 | 1;
  local_9c = 0;
  local_a0 = 0;
  local_a4 = 0;
  pvVar2 = (void *)FUN_004062c0(&local_30,"data");
  pcVar6 = (char *)&local_b0;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"error");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_b0);
  local_a4 = 0;
  local_a8 = local_a8 & 0xfffffe01 | 1;
  local_a0 = 0;
  local_9c = 0;
  local_b0 = 0x22;
  local_8._0_1_ = 7;
  pvVar2 = (void *)FUN_004062c0(&local_30,"data");
  pcVar6 = (char *)&local_b0;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"callback");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_b0);
  local_a4 = 0;
  local_a8 = local_a8 & 0xffffff04 | 0x104;
  local_a0 = 0;
  local_9c = 0;
  uVar3 = FUN_00404fd0("daemon",0xffffffff);
  pcVar6 = (char *)&local_b0;
  local_8._0_1_ = 8;
  local_b0._0_4_ = uVar3;
  pvVar2 = (void *)FUN_004062c0(&local_30,"sender");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_b0);
  local_a4 = 0;
  local_a8 = local_a8 & 0xffffff04 | 0x104;
  local_a0 = 0;
  local_9c = 0;
  uVar3 = FUN_00404fd0("",0xffffffff);
  local_b0 = CONCAT44(local_b0._4_4_,uVar3);
  local_8._0_1_ = 9;
  pcVar6 = (char *)&local_b0;
  pvVar2 = (void *)FUN_004062c0(&local_30,"receiver");
  FUN_00405560(pvVar2,pcVar6);
  local_8 = (char ***)CONCAT31(local_8._1_3_,2);
  FUN_004054d0((undefined4 *)&local_b0);
  FUN_004072a0(&local_98,(undefined1 *)local_48,(double *)&local_30);
  puVar5 = DAT_0042e3a8;
  if (DAT_0042e3a8 != DAT_0042e3ac) {
    do {
      ppppcVar4 = (char ****)local_48;
      if (0xf < local_34) {
        ppppcVar4 = local_48[0];
      }
      FUN_00401c60(&DAT_0042e334,(char *)ppppcVar4,local_38,*puVar5);
      puVar5 = puVar5 + 1;
    } while (puVar5 != DAT_0042e3ac);
  }
  FUN_0040b790(&DAT_0042e304,local_48);
  array_vpn_logprint(1,"vpnd.cpp",0x83,"send message to clients: Web disconnect.\n");
  if (0xf < local_34) {
    operator_delete(local_48[0]);
  }
  puVar1 = local_30;
  local_8 = (char ***)((uint)local_8 & 0xffffff00);
  local_34 = 0xf;
  local_38 = 0;
  local_48[0] = (char ****)((uint)local_48[0] & 0xffffff00);
  if ((char)uStack_28 == 4) {
    if (((uStack_28 & 0x100) != 0) && (local_30 != (undefined4 *)0x0)) {
      free(local_30);
    }
  }
  else if (((int)(char)uStack_28 - 6U < 2) && (local_30 != (undefined4 *)0x0)) {
    FUN_004096a0(local_30,&local_b4,*(int **)*local_30,(int *)*local_30);
    operator_delete((void *)*puVar1);
    operator_delete(puVar1);
  }
  if (pvStack_24 != (void *)0x0) {
    pvVar2 = (void *)((int)pvStack_24 + -4);
    _eh_vector_destructor_iterator_(pvStack_24,4,*(int *)((int)pvStack_24 + -4),(_func_void_void_ptr *)&LAB_00405090);
    operator_delete__(pvVar2);
  }
  FUN_004013c0(&local_98);
  ExceptionList = local_10;
  FUN_0041c21c(local_18 ^ (uint)(local_48 + 0x11));
  return;
}



// ===== FUN_00415350 @ 00415350 =====

void FUN_00415350(void)

{
  char cVar1;
  LSTATUS LVar2;
  char *pcVar3;
  DWORD local_114 [2];
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_10c + 0x108);
  local_10c[0] = '\0';
  memset(local_10c + 1,0,0x103);
  local_114[1] = 1;
  local_114[0] = 0x104;
  LVar2 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\AWG","Endpoint",local_114 + 1,local_10c,local_114);
  array_vpn_logprint(1,"vpnd.cpp",0x8f,"IsConnectWithSWG: reg from vpn sdk, endpoint:%s\n",local_10c);
  if (LVar2 == 0) {
    pcVar3 = local_10c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (7 < (uint)((int)pcVar3 - (int)(local_10c + 1))) goto LAB_00415434;
  }
  pcVar3 = &DAT_0042dd08;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((pcVar3 == &DAT_0042dd09) || (DAT_0042dd04 == 0)) {
    FUN_0041c21c(local_8 ^ (uint)(local_10c + 0x108));
    return;
  }
  array_vpn_logprint(1,"vpnd.cpp",0x97,"IsConnectWithSWG: sdk disabled wg, mp enabled wg\n");
LAB_00415434:
  FUN_0041c21c(local_8 ^ (uint)(local_10c + 0x108));
  return;
}



// ===== FUN_00415460 @ 00415460 =====

void FUN_00415460(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  char ****ppppcVar4;
  u_short *puVar5;
  char *pcVar6;
  undefined4 local_b0;
  undefined8 local_ac;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined **local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  char ****local_44 [4];
  int local_34;
  uint local_30;
  undefined4 *local_2c;
  undefined4 uStack_28;
  uint uStack_24;
  void *pvStack_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  char ***local_8;
  
  local_8 = (char ***)0xffffffff;
  puStack_c = &LAB_0041e785;
  local_10 = ExceptionList;
  local_14 = DAT_00428000 ^ (uint)(local_44 + 0x10);
  ExceptionList = &local_10;
  memset(&local_94,0,0x4c);
  local_94 = Json::StyledWriter::vftable;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_70 = 0xf;
  local_74 = 0;
  local_84 = 0;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = 0;
  local_54 = 0x4a;
  local_50 = 3;
  local_4c = 0;
  local_2c = (undefined4 *)0x0;
  uStack_28 = 0;
  pvStack_20 = (void *)0x0;
  local_1c = 0;
  uStack_24 = 0;
  local_a0 = 0;
  local_a4 = local_a4 & 0xfffffe01 | 1;
  local_9c = 0;
  local_98 = 0;
  local_ac = 0;
  pcVar6 = (char *)&local_ac;
  local_8 = (char ***)0x3;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"error");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_ac);
  local_a0 = 0;
  local_a4 = local_a4 & 0xfffffe01 | 1;
  local_9c = 0;
  local_98 = 0;
  local_ac = 10;
  local_8._0_1_ = 4;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"data");
  pcVar6 = (char *)&local_ac;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"action");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_ac);
  local_a0 = 0;
  local_a4 = local_a4 & 0xfffffe01 | 1;
  local_9c = 0;
  local_98 = 0;
  local_ac = 0;
  local_8._0_1_ = 5;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"data");
  pcVar6 = (char *)&local_ac;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"error");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_ac);
  local_a0 = 0;
  local_a4 = local_a4 & 0xfffffe01 | 1;
  local_9c = 0;
  local_98 = 0;
  local_ac = 0x24;
  local_8._0_1_ = 6;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"data");
  pcVar6 = (char *)&local_ac;
  pvVar2 = (void *)FUN_004062c0(pvVar2,"callback");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_ac);
  local_a0 = 0;
  local_a4 = local_a4 & 0xffffff04 | 0x104;
  local_9c = 0;
  local_98 = 0;
  uVar3 = FUN_00404fd0("daemon",0xffffffff);
  pcVar6 = (char *)&local_ac;
  local_8._0_1_ = 7;
  local_ac._0_4_ = uVar3;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"sender");
  FUN_00405560(pvVar2,pcVar6);
  local_8._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_ac);
  local_a0 = 0;
  local_a4 = local_a4 & 0xffffff04 | 0x104;
  local_9c = 0;
  local_98 = 0;
  uVar3 = FUN_00404fd0("",0xffffffff);
  local_ac = CONCAT44(local_ac._4_4_,uVar3);
  pcVar6 = (char *)&local_ac;
  local_8._0_1_ = 8;
  pvVar2 = (void *)FUN_004062c0(&local_2c,"receiver");
  FUN_00405560(pvVar2,pcVar6);
  local_8 = (char ***)CONCAT31(local_8._1_3_,2);
  FUN_004054d0((undefined4 *)&local_ac);
  FUN_004072a0(&local_94,(undefined1 *)local_44,(double *)&local_2c);
  puVar5 = DAT_0042e3a8;
  if (DAT_0042e3a8 != DAT_0042e3ac) {
    do {
      ppppcVar4 = (char ****)local_44;
      if (0xf < local_30) {
        ppppcVar4 = local_44[0];
      }
      FUN_00401c60(&DAT_0042e334,(char *)ppppcVar4,local_34,*puVar5);
      puVar5 = puVar5 + 1;
    } while (puVar5 != DAT_0042e3ac);
  }
  FUN_0040b790(&DAT_0042e304,local_44);
  array_vpn_logprint(1,"vpnd.cpp",0xb3,"send message to clients: MotionPro show dd.\n");
  if (0xf < local_30) {
    operator_delete(local_44[0]);
  }
  puVar1 = local_2c;
  local_8 = (char ***)((uint)local_8 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44[0] = (char ****)((uint)local_44[0] & 0xffffff00);
  if ((char)uStack_24 == 4) {
    if (((uStack_24 & 0x100) != 0) && (local_2c != (undefined4 *)0x0)) {
      free(local_2c);
    }
  }
  else if (((int)(char)uStack_24 - 6U < 2) && (local_2c != (undefined4 *)0x0)) {
    FUN_004096a0(local_2c,&local_b0,*(int **)*local_2c,(int *)*local_2c);
    operator_delete((void *)*puVar1);
    operator_delete(puVar1);
  }
  if (pvStack_20 != (void *)0x0) {
    pvVar2 = (void *)((int)pvStack_20 + -4);
    _eh_vector_destructor_iterator_(pvStack_20,4,*(int *)((int)pvStack_20 + -4),(_func_void_void_ptr *)&LAB_00405090);
    operator_delete__(pvVar2);
  }
  FUN_004013c0(&local_94);
  ExceptionList = local_10;
  FUN_0041c21c(local_14 ^ (uint)(local_44 + 0x10));
  return;
}



// ===== FUN_00415970 @ 00415970 =====

void __fastcall FUN_00415970(int param_1,int param_2,char *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  char *pcVar5;
  char ****ppppcVar6;
  u_short *puVar7;
  longlong *plVar8;
  undefined1 auStack_d8 [8];
  longlong local_d0;
  uint local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  undefined4 local_b4;
  undefined4 *local_b0;
  undefined4 uStack_ac;
  uint uStack_a8;
  void *pvStack_a4;
  undefined8 local_a0;
  char ****local_90 [4];
  int local_80;
  uint local_7c;
  undefined **local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  uint local_24;
  void *local_1c;
  undefined1 *puStack_18;
  int local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0041e81b;
  local_1c = ExceptionList;
  local_24 = DAT_00428000 ^ (uint)auStack_d8;
  ExceptionList = &local_1c;
  local_b8 = param_2;
  memset(&local_78,0,0x4c);
  local_78 = Json::StyledWriter::vftable;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_54 = 0xf;
  local_58 = 0;
  local_68 = 0;
  local_3c = 0xf;
  local_40 = 0;
  local_50 = 0;
  local_38 = 0x4a;
  local_34 = 3;
  local_30 = 0;
  local_b0 = (undefined4 *)0x0;
  uStack_ac = 0;
  pvStack_a4 = (void *)0x0;
  uStack_a8 = 0;
  local_a0 = 0;
  local_c4 = 0;
  local_c8 = local_c8 & 0xfffffe01 | 1;
  local_c0 = 0;
  local_bc = 0;
  local_d0 = 0;
  plVar8 = &local_d0;
  local_14 = 3;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"error");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  local_c4 = 0;
  local_c8 = local_c8 & 0xfffffe01 | 1;
  local_c0 = 0;
  local_bc = 0;
  local_d0 = 10;
  local_14._0_1_ = 4;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"data");
  plVar8 = &local_d0;
  pvVar3 = (void *)FUN_004062c0(pvVar3,"action");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  local_c4 = 0;
  local_c8 = local_c8 & 0xfffffe01 | 1;
  local_c0 = 0;
  local_bc = 0;
  local_d0 = (longlong)local_b8;
  local_14._0_1_ = 5;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"data");
  plVar8 = &local_d0;
  pvVar3 = (void *)FUN_004062c0(pvVar3,"error");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  local_c4 = 0;
  local_c8 = local_c8 & 0xfffffe01 | 1;
  local_c0 = 0;
  local_bc = 0;
  local_d0 = (longlong)param_1;
  local_14._0_1_ = 6;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"data");
  plVar8 = &local_d0;
  pvVar3 = (void *)FUN_004062c0(pvVar3,"callback");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  local_c4 = 0;
  local_c8 = local_c8 & 0xffffff04 | 0x104;
  local_c0 = 0;
  local_bc = 0;
  uVar4 = FUN_00404fd0("daemon",0xffffffff);
  plVar8 = &local_d0;
  local_14._0_1_ = 7;
  local_d0._0_4_ = uVar4;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"sender");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  if ((((param_1 == 1) || (param_1 == 3)) || (param_1 == 0x26)) || (param_1 == 0x27)) {
    local_c4 = 0;
    local_c8 = local_c8 & 0xffffff04 | 0x104;
    local_c0 = 0;
    local_bc = 0;
    local_d0._0_4_ = FUN_00404fd0(&DAT_0042d7f8,0xffffffff);
    local_14._0_1_ = 8;
  }
  else {
    FUN_00405260(&local_d0,"");
    local_14._0_1_ = 9;
  }
  plVar8 = &local_d0;
  pvVar3 = (void *)FUN_004062c0(&local_b0,"receiver");
  FUN_00405560(pvVar3,(char *)plVar8);
  local_14._0_1_ = 2;
  FUN_004054d0((undefined4 *)&local_d0);
  if ((param_1 == 0x32) && (param_3 != (char *)0x0)) {
    pcVar5 = param_3;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (pcVar5 != param_3 + 1) {
      local_c4 = 0;
      local_c8 = local_c8 & 0xffffff04 | 0x104;
      local_c0 = 0;
      local_bc = 0;
      local_d0._0_4_ = FUN_00404fd0(param_3,0xffffffff);
      plVar8 = &local_d0;
      local_14._0_1_ = 10;
      pvVar3 = (void *)FUN_004062c0(&local_b0,"receiver");
      FUN_00405560(pvVar3,(char *)plVar8);
      local_14._0_1_ = 2;
      FUN_004054d0((undefined4 *)&local_d0);
    }
  }
  FUN_004072a0(&local_78,(undefined1 *)local_90,(double *)&local_b0);
  puVar7 = DAT_0042e3a8;
  if (DAT_0042e3a8 != DAT_0042e3ac) {
    do {
      ppppcVar6 = (char ****)local_90;
      if (0xf < local_7c) {
        ppppcVar6 = local_90[0];
      }
      FUN_00401c60(&DAT_0042e334,(char *)ppppcVar6,local_80,*puVar7);
      puVar7 = puVar7 + 1;
    } while (puVar7 != DAT_0042e3ac);
  }
  FUN_0040b790(&DAT_0042e304,local_90);
  array_vpn_logprint(1,"vpnd.cpp",0xd8,"send message to clients: cmd %d, error %d.\n",param_1,local_b8);
  if (0xf < local_7c) {
    operator_delete(local_90[0]);
  }
  puVar2 = local_b0;
  local_14 = (uint)local_14._1_3_ << 8;
  local_7c = 0xf;
  local_80 = 0;
  local_90[0] = (char ****)((uint)local_90[0] & 0xffffff00);
  if ((char)uStack_a8 == 4) {
    if (((uStack_a8 & 0x100) != 0) && (local_b0 != (undefined4 *)0x0)) {
      free(local_b0);
    }
  }
  else if (((int)(char)uStack_a8 - 6U < 2) && (local_b0 != (undefined4 *)0x0)) {
    FUN_004096a0(local_b0,&local_b4,*(int **)*local_b0,(int *)*local_b0);
    operator_delete((void *)*puVar2);
    operator_delete(puVar2);
  }
  if (pvStack_a4 != (void *)0x0) {
    pvVar3 = (void *)((int)pvStack_a4 + -4);
    _eh_vector_destructor_iterator_(pvStack_a4,4,*(int *)((int)pvStack_a4 + -4),(_func_void_void_ptr *)&LAB_00405090);
    operator_delete__(pvVar3);
  }
  FUN_004013c0(&local_78);
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)auStack_d8);
  return;
}



// ===== FUN_00415f80 @ 00415f80 =====

void __fastcall FUN_00415f80(BSTR param_1,int *param_2)

{
  OLECHAR OVar1;
  char cVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  undefined4 *puVar6;
  bool bVar7;
  code *_StartAddress;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 local_4f8 [16];
  uint local_4e8;
  undefined4 local_3dc;
  int local_3d8;
  undefined4 local_3d4;
  ulong local_3d0;
  undefined4 local_3cc;
  undefined2 local_3bc;
  undefined4 local_29a [32];
  undefined4 local_21a [32];
  undefined4 local_19a [32];
  char local_11a [128];
  char local_9a [128];
  undefined4 local_1a;
  int local_16;
  uint local_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_00428000 ^ (uint)(auStack_8 + 4);
  memset(local_4f8,0,0x4e6);
  array_vpn_logprint(1,"vpnd.cpp",0x241,"*************IPv4 gateway start *******\n");
  FUN_0040ee90();
  array_vpn_logprint(1,"vpnd.cpp",0x243,"*************IPv4 gateway finished *******\n");
  array_vpn_logprint(1,"vpnd.cpp",0x245,"*************IPv6 gateway start *******\n");
  FUN_0040f000();
  array_vpn_logprint(1,"vpnd.cpp",0x247,"*************IPv6 gateway finished *******\n");
  array_vpn_logprint(1,"vpnd.cpp",0x249,"*************delete routes start *******\n");
  FUN_0040d3e0();
  array_vpn_logprint(1,"vpnd.cpp",0x24b,"*************delete routes finished *******\n");
  array_vpn_get_server_ip(&local_10);
  array_vpn_get_server_ipv6(&DAT_004296f8,0x100);
  if (local_10 == 0) {
    sprintf(&DAT_00428790,"%s",&DAT_0041f7b1);
  }
  else {
    sprintf(&DAT_00428790,"%d.%d.%d.%d",local_10 & 0xff,local_10 >> 8 & 0xff,local_10 >> 0x10 & 0xff,local_10 >> 0x18);
  }
  iVar3 = FUN_00412ff0();
  if (iVar3 == 9) {
    pcVar9 = "local system is windows 11\n";
    uVar8 = 0x25a;
  }
  else if (iVar3 == 8) {
    pcVar9 = "local system is windows 10\n";
    uVar8 = 0x25e;
  }
  else if (iVar3 == 7) {
    pcVar9 = "local system is windows 8\n";
    uVar8 = 0x262;
  }
  else {
    pcVar9 = "local system is windows 7\n";
    uVar8 = 0x266;
  }
  array_vpn_logprint(1,"vpnd.cpp",uVar8,pcVar9);
  if (((*(int *)param_1 == 0) || (local_10 == 0)) || (6 < iVar3)) {
    array_vpn_logprint(1,"vpnd.cpp",0x26a,"*************add default route start *******\n");
    FUN_0040bd50();
    array_vpn_logprint(1,"vpnd.cpp",0x26c,"*************add default route finished *******\n");
  }
  iVar3 = *(int *)param_1;
  if (iVar3 == 0) {
    pOVar5 = param_1 + 8;
    pOVar4 = pOVar5;
    do {
      OVar1 = *pOVar4;
      pOVar4 = (BSTR)((int)pOVar4 + 1);
    } while ((char)OVar1 != '\0');
    if (pOVar4 != (BSTR)((int)param_1 + 0x11)) {
      array_vpn_logprint(1,"vpnd.cpp",0x271,"IPv6 address:**************%s**********",pOVar5);
      local_3bc = 0x514;
      local_4e8 = local_4e8 | ((char)param_1[0xd4] != '\0') + 1 | 4;
      puVar6 = local_29a;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *(undefined4 *)pOVar5;
        pOVar5 = pOVar5 + 2;
        puVar6 = puVar6 + 1;
      }
      pOVar5 = param_1 + 0x4c;
      puVar6 = local_21a;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *(undefined4 *)pOVar5;
        pOVar5 = pOVar5 + 2;
        puVar6 = puVar6 + 1;
      }
      pOVar5 = param_1 + 0x90;
      puVar6 = local_19a;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *(undefined4 *)pOVar5;
        pOVar5 = pOVar5 + 2;
        puVar6 = puVar6 + 1;
      }
      local_1a = array_vpn_get_ipv6_prefix(param_1 + 0x4c);
      if (*(int *)(param_1 + 0xe8) != 0) {
        sprintf(local_11a,(char *)**(undefined4 **)(param_1 + 0xec));
      }
      if (1 < *(uint *)(param_1 + 0xe8)) {
        sprintf(local_9a,*(char **)(*(int *)(param_1 + 0xec) + 4));
      }
      goto LAB_00416228;
    }
  }
  else {
    local_4e8 = local_4e8 | 5;
    bVar7 = (*(uint *)(param_1 + 0xf8) & 0x20000000) == 0;
    local_3dc = *(undefined4 *)(param_1 + 4);
    local_3d4 = *(undefined4 *)(param_1 + 2);
    local_3bc = 0x514;
    local_3d8 = iVar3;
    if (bVar7) {
      array_vpn_logprint(1,"vpnd.cpp",0x297,"vpnd: AG server enable dnsproxy\n");
    }
    else {
      array_vpn_logprint(1,"vpnd.cpp",0x292,"vpnd: AG server disable dnsproxy\n");
    }
    iVar3 = FUN_00413540();
    if ((iVar3 == 1) || ((iVar3 != 0 && (bVar7)))) {
      local_3d0 = inet_addr("127.0.0.1");
      if (*(int *)(param_1 + 0xe6) != 0) {
        local_3cc = **(undefined4 **)(param_1 + 0xea);
      }
    }
    else {
LAB_00416228:
      if (*(uint *)(param_1 + 0xe6) != 0) {
        local_3d0 = **(ulong **)(param_1 + 0xea);
      }
      if (1 < *(uint *)(param_1 + 0xe6)) {
        local_3cc = *(undefined4 *)(*(int *)(param_1 + 0xea) + 4);
      }
    }
  }
  iVar3 = FUN_0040dc40();
  if (0 < iVar3) {
    local_16 = iVar3;
  }
  if (DAT_0042e288 == 0) {
    pcVar9 = "*************This is sstp mode *******\n";
    uVar8 = 0x2bd;
LAB_0041648f:
    array_vpn_logprint(1,"vpnd.cpp",uVar8,pcVar9);
    if (DAT_0042e288 != 0) {
      *param_2 = 0;
      _beginthread(FUN_0040c3b0,0,param_1);
      FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
      return;
    }
  }
  else {
    cVar2 = FUN_00415350();
    if (cVar2 == '\0') {
      array_vpn_logprint(1,"vpnd.cpp",0x2c2,"*************This is sstp mode(no wg addr) *******\n");
    }
    else {
      array_vpn_logprint(1,"vpnd.cpp",0x2c7,"*************This is wireguard mode *******\n");
      iVar3 = FUN_004108f0(0,(BSTR)0x0,0);
      if (iVar3 < 1) {
        iVar3 = FUN_004108f0(1,param_1,0);
        if (0 < iVar3) {
          array_vpn_logprint(1,"vpnd.cpp",0x2d2,"StartVPNBySWG: SWG_ACTION_START failed, ret:%d\n",iVar3);
          DAT_0042e288 = 0;
          if (iVar3 == 2) {
            FUN_004108f0(2,(BSTR)0x0,2);
            FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
            return;
          }
          FUN_004108f0(2,(BSTR)0x0,0);
          FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
          return;
        }
        pcVar9 = "*************StartVPNBySWG success *******\n";
        uVar8 = 0x2e0;
        goto LAB_0041648f;
      }
      array_vpn_logprint(1,"vpnd.cpp",0x2cb,"StartVPNBySWG: SWG_ACTION_CREATE_CONF failed, ret:%d\n",iVar3);
    }
    DAT_0042e288 = 0;
  }
  array_vpn_logprint(1,"vpnd.cpp",0x328,"*************xtun open start *******\n");
  iVar3 = xtun_open(local_4f8);
  *param_2 = iVar3;
  if (iVar3 == -1) {
    array_vpn_logprint(3,"vpnd.cpp",0x32c,"open tun device failed\n");
    FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  array_vpn_logprint(1,"vpnd.cpp",0x330,"*************xtun open finish *******\n");
  array_vpn_logprint(1,"vpnd.cpp",0x332,"*************route config start *******\n");
  DAT_0042dbf8 = 0;
  iVar3 = *(int *)param_1;
  if (iVar3 != 0) {
    _StartAddress = FUN_0040c3b0;
  }
  else {
    FUN_0040c1c0();
    _StartAddress = FUN_0040eb90;
  }
  DAT_0042dbf8 = (uint)(iVar3 == 0);
  _beginthread(_StartAddress,0,param_1);
  array_vpn_logprint(1,"vpnd.cpp",0x354,"*************route config finish *******\n");
  FUN_0041c21c(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===== FUN_00416570 @ 00416570 =====

void __cdecl FUN_00416570(char *param_1,char *param_2,BSTR param_3,undefined4 param_4,int *param_5)

{
  OLECHAR OVar1;
  BSTR pOVar2;
  undefined4 *puVar3;
  char cVar4;
  bool bVar5;
  void *pvVar6;
  undefined4 uVar7;
  char ****ppppcVar8;
  int iVar9;
  LSTATUS LVar10;
  undefined4 extraout_ECX;
  char *pcVar11;
  undefined4 extraout_ECX_00;
  BSTR pOVar12;
  u_short *puVar13;
  code *pcVar14;
  longlong *plVar15;
  undefined1 auStack_218 [8];
  longlong local_210;
  uint local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  char *local_1f4;
  undefined4 local_1f0;
  char *local_1ec;
  char *local_1e8;
  BSTR local_1e4;
  undefined4 *local_1e0;
  undefined4 uStack_1dc;
  uint uStack_1d8;
  void *pvStack_1d4;
  undefined8 local_1d0;
  int *local_1b4;
  char ****local_1b0 [4];
  int local_1a0;
  uint local_19c;
  char ****local_198 [4];
  int local_188;
  uint local_184;
  undefined **local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined1 local_170;
  undefined4 local_160;
  undefined4 local_15c;
  undefined1 local_158;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined1 local_138;
  char local_130;
  undefined1 local_12f [267];
  uint local_24;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0041e900;
  local_1c = ExceptionList;
  local_24 = DAT_00428000 ^ (uint)auStack_218;
  ExceptionList = &local_1c;
  local_1f4 = param_2;
  local_1b4 = param_5;
  local_1ec = param_1;
  local_1e4 = param_3;
  memset(&local_180,0,0x4c);
  local_180 = Json::StyledWriter::vftable;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_15c = 0xf;
  local_160 = 0;
  local_170 = 0;
  local_144 = 0xf;
  local_148 = 0;
  local_158 = 0;
  local_140 = 0x4a;
  local_13c = 3;
  local_138 = 0;
  local_1e0 = (undefined4 *)0x0;
  uStack_1dc = 0;
  pvStack_1d4 = (void *)0x0;
  uStack_1d8 = 0;
  local_1d0 = 0;
  local_14 = 2;
  local_19c = 0xf;
  local_1a0 = 0;
  local_1b0[0] = (char ****)((uint)local_1b0[0] & 0xffffff00);
  FUN_00401f80(local_1b0,(int *)&DAT_0041f7b1,0);
  local_204 = 0;
  local_208 = local_208 & 0xfffffe01 | 1;
  local_200 = 0;
  local_1fc = 0;
  local_210 = 0;
  plVar15 = &local_210;
  local_14._0_1_ = 4;
  pvVar6 = (void *)FUN_004062c0(&local_1e0,"error");
  FUN_00405560(pvVar6,(char *)plVar15);
  local_14._0_1_ = 3;
  FUN_004054d0((undefined4 *)&local_210);
  local_204 = 0;
  local_208 = local_208 & 0xfffffe01 | 1;
  local_200 = 0;
  local_1fc = 0;
  local_210 = 10;
  local_14._0_1_ = 5;
  pvVar6 = (void *)FUN_004062c0(&local_1e0,"data");
  plVar15 = &local_210;
  pvVar6 = (void *)FUN_004062c0(pvVar6,"action");
  FUN_00405560(pvVar6,(char *)plVar15);
  local_14._0_1_ = 3;
  FUN_004054d0((undefined4 *)&local_210);
  if ((param_1 == (char *)0x2) && (local_1f4 == (char *)0x27)) {
    SHDeleteValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","virtualip");
    DAT_0042dbfc = 1;
    local_208 = local_208 & 0xfffffe01 | 1;
    local_204 = 0;
    local_200 = 0;
    local_1fc = 0;
    local_210 = 0;
    local_14._0_1_ = 6;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"data");
    plVar15 = &local_210;
    pvVar6 = (void *)FUN_004062c0(pvVar6,"error");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14._0_1_ = 3;
    FUN_004054d0((undefined4 *)&local_210);
    local_204 = 0;
    local_208 = local_208 & 0xfffffe01 | 1;
    local_200 = 0;
    local_1fc = 0;
    local_210 = 1;
    local_14._0_1_ = 7;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"data");
    plVar15 = &local_210;
    pvVar6 = (void *)FUN_004062c0(pvVar6,"callback");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
  }
  else {
    local_204 = 0;
    local_208 = local_208 & 0xfffffe01 | 1;
    local_200 = 0;
    local_1fc = 0;
    local_210 = (longlong)(int)local_1f4;
    local_14._0_1_ = 8;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"data");
    plVar15 = &local_210;
    pvVar6 = (void *)FUN_004062c0(pvVar6,"error");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14._0_1_ = 3;
    FUN_004054d0((undefined4 *)&local_210);
    local_204 = 0;
    local_208 = local_208 & 0xfffffe01 | 1;
    local_200 = 0;
    local_1fc = 0;
    local_210 = (longlong)(int)param_1;
    local_14._0_1_ = 9;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"data");
    plVar15 = &local_210;
    pvVar6 = (void *)FUN_004062c0(pvVar6,"callback");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
    if (param_1 == (char *)0x2) {
      DAT_0042dbfc = 3;
    }
  }
  local_204 = 0;
  local_208 = local_208 & 0xffffff04 | 0x104;
  local_200 = 0;
  local_1fc = 0;
  uVar7 = FUN_00404fd0("daemon",0xffffffff);
  plVar15 = &local_210;
  local_14._0_1_ = 10;
  local_210._0_4_ = uVar7;
  pvVar6 = (void *)FUN_004062c0(&local_1e0,"sender");
  FUN_00405560(pvVar6,(char *)plVar15);
  local_14._0_1_ = 3;
  FUN_004054d0((undefined4 *)&local_210);
  if ((((param_1 == (char *)0x1) || (param_1 == (char *)0x3)) || (param_1 == (char *)0x26)) || (param_1 == (char *)0x27)
     ) {
    local_204 = 0;
    local_208 = local_208 & 0xffffff04 | 0x104;
    local_200 = 0;
    local_1fc = 0;
    local_210._0_4_ = FUN_00404fd0(&DAT_0042d7f8,0xffffffff);
    local_14._0_1_ = 0xb;
  }
  else {
    FUN_00405260(&local_210,"");
    local_14._0_1_ = 0xc;
  }
  plVar15 = &local_210;
  pvVar6 = (void *)FUN_004062c0(&local_1e0,"receiver");
  FUN_00405560(pvVar6,(char *)plVar15);
  local_14 = CONCAT31(local_14._1_3_,3);
  FUN_004054d0((undefined4 *)&local_210);
  if (((param_1 != (char *)0x1f) && (param_1 != (char *)0x2d)) && (param_1 != (char *)0x2b)) {
    local_1e8 = param_1;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","VPNstatus",4,&local_1e8,4);
    local_1e8 = local_1f4;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","VPNerror",4,&local_1e8,4);
  }
  if (param_1 == (char *)0x3) {
    if (DAT_00428ddc != '\0') {
      DAT_00428ddc = '\0';
      local_1ec = (char *)0x1;
    }
LAB_00416ba1:
    array_vpn_logprint(1,"vpnd.cpp",0x397,"vpnd callback: cmd %d, error %d\n",local_1ec,local_1f4);
  }
  else {
    DAT_00428ddc = '\0';
    if (local_1ec != (char *)0x2d) goto LAB_00416ba1;
  }
  switch(local_1ec) {
  case (char *)0x1:
    array_vpn_logprint(1,"vpnd.cpp",0x39c,"vpnd callback cmd is connecting.\n");
    pcVar14 = operator_delete_exref;
    goto LAB_004172e2;
  case (char *)0x2:
    array_vpn_logprint(1,"vpnd.cpp",0x3a0,"vpnd callback cmd is connect failed. error:%d\n",local_1f4);
    FUN_00405260(&local_210,"vpn connect failed");
    plVar15 = &local_210;
    local_14._0_1_ = 0xd;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"message");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
    FUN_00401dd0(&DAT_0042e3cc,(int *)&DAT_0041f7b1);
    FUN_00401dd0(&DAT_0042e3b4,(int *)&DAT_0041f7b1);
    break;
  case (char *)0x3:
    if ((DAT_0042e288 == 0) && (cVar4 = FUN_0040c120(), cVar4 != '\0')) {
      FUN_00413300(2,0x32,1);
    }
    array_vpn_logprint(1,"vpnd.cpp",0x3ac,"vpnd callback cmd is connected.\n");
    FUN_00405260(&local_210,"vpn is connected");
    plVar15 = &local_210;
    local_14._0_1_ = 0xe;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"message");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
    DAT_0042dbfc = 2;
    FUN_0040fac0(1);
    break;
  case (char *)0x4:
    array_vpn_logprint(1,"vpnd.cpp",0x3b6,"vpnd callback cmd is disconnecting.\n");
    FUN_00405260(&local_210,"vpn is disconnecting");
    plVar15 = &local_210;
    local_14._0_1_ = 0xf;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"message");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
    FUN_0040cfd0(extraout_ECX,0);
    FUN_0040cf80();
    DAT_0042e294 = (char *)0x0;
    break;
  case (char *)0x5:
    array_vpn_logprint(1,"vpnd.cpp",0x3cc,"vpnd callback cmd is disconnected.\n");
    FUN_0040cf80();
    FUN_0040fac0(0);
    FUN_00405260(&local_210,"vpn is disconnected");
    plVar15 = &local_210;
    local_14._0_1_ = 0x10;
    pvVar6 = (void *)FUN_004062c0(&local_1e0,"message");
    FUN_00405560(pvVar6,(char *)plVar15);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0((undefined4 *)&local_210);
    FUN_00401dd0(&DAT_0042e3cc,(int *)&DAT_0041f7b1);
    FUN_00401dd0(&DAT_0042e3b4,(int *)&DAT_0041f7b1);
    xtun_close(0xffffffff);
    break;
  case (char *)0x6:
    array_vpn_logprint(1,"vpnd.cpp",0x40a,"vpnd callback cmd is config request.\n");
    DAT_0042e294 = (char *)(uint)(byte)param_3[0xd4];
    if ((char)param_3[0x108] == '\x01') {
      array_vpn_logprint(1,"vpnd.cpp",0x411,"User config callhome switch enable, start launch process.\n");
      FUN_0040d690((int *)((int)param_3 + 0x211),(char *)((int)param_3 + 0x611),(char *)((int)param_3 + 0x715));
    }
    else {
      array_vpn_logprint(1,"vpnd.cpp",0x416,"User config callhome switch disable.\n");
      SHDeleteKeyA((HKEY)0x80000001,"SOFTWARE\\VPN\\CallHome");
    }
    FUN_0040fcb0((int)param_3);
    if (*(int *)param_3 == 0) {
      DAT_00428ddc = '\x01';
    }
    bVar5 = *(int *)(param_3 + 0xfc) != 0;
    if (bVar5) {
      array_vpn_logprint(1,"vpnd.cpp",0x421,"vpnd callback connect cmd number=%d.\n",*(int *)(param_3 + 0xfc));
    }
    iVar9 = *(int *)(param_3 + 0x100);
    DAT_00428dde = bVar5;
    if (iVar9 != 0) {
      array_vpn_logprint(1,"vpnd.cpp",0x427,"vpnd callback disconnect cmd number=%d.\n",iVar9);
    }
    DAT_00428ddd = iVar9 != 0;
    array_vpn_logprint(1,"vpnd.cpp",0x42f,"Browser:%s, url:%s, SendMsgToClients\n",(int *)((int)param_3 + 0x91d),
                       (int)param_3 + 0xa21);
    FUN_00401dd0(local_1b0,(int *)((int)param_3 + 0x91d));
    if (local_1a0 != 0) {
      FUN_004083d0(local_1b0,(int *)&DAT_004235ac);
    }
    pOVar2 = local_1e4;
    pOVar12 = (BSTR)((int)local_1e4 + 0xa21);
    FUN_004083d0(local_1b0,(int *)pOVar12);
    do {
      OVar1 = *pOVar12;
      pOVar12 = (BSTR)((int)pOVar12 + 1);
    } while ((char)OVar1 != '\0');
    if (pOVar12 != pOVar2 + 0x511) {
      ppppcVar8 = (char ****)local_1b0;
      if (0xf < local_19c) {
        ppppcVar8 = local_1b0[0];
      }
      FUN_00415970(0x32,0,(char *)ppppcVar8);
    }
    pOVar2 = local_1e4;
    iVar9 = FUN_00415f80(local_1e4,local_1b4);
    if (iVar9 != 0) {
      if (iVar9 == 0x87) {
        array_vpn_logprint(2,"vpnd.cpp",0x440,"config wiregurad faild, switch with sstp.\n");
        pcVar14 = operator_delete_exref;
        goto LAB_004172e2;
      }
      array_vpn_logprint(3,"vpnd.cpp",0x445,"config vpn failed.\n");
      goto LAB_00417044;
    }
    if ((*(uint *)(pOVar2 + 0xf8) & 0x4000000) == 0) {
      array_vpn_logprint(1,"vpnd.cpp",0x450,"vpnd: enable proxy rewrite\n");
      local_1e4 = (BSTR)0x4;
      local_1ec = (char *)0x0;
      local_1b4 = (int *)0x4;
      LVar10 = SHGetValueA((HKEY)0x80000002,"Software\\VPN\\VPN2","ProxyScriptNoRewrite",(DWORD *)&local_1e4,&local_1ec,
                           (DWORD *)&local_1b4);
      if ((LVar10 == 0) && (local_1ec == (char *)0x1)) {
        array_vpn_logprint(1,"vpnd.cpp",0x456,
                           "adapter_config: ProxyScriptNoRewrite is 1, no need change proxy script.\n",1);
      }
      else {
        if (*(int *)(pOVar2 + 0x106) == 0) {
          array_vpn_logprint(1,"vpnd.cpp",0x45c,"inside proxy is disabled, we will detect outside proxy, vsite:%s\n",
                             &DAT_004296b8);
        }
        else {
          array_vpn_logprint(1,"vpnd.cpp",0x461,"inside proxy: type:%d, server:%s\n",*(undefined4 *)(pOVar2 + 0x104),
                             *(int *)(pOVar2 + 0x106));
          local_1f4 = *(char **)(pOVar2 + 0x104);
          if (((local_1f4 == (char *)0x0) || (local_1f4 == (char *)0x1)) &&
             (local_1e8 = *(char **)(pOVar2 + 0x106), local_1e8 != (char *)0x0)) {
            pcVar11 = local_1e8;
            do {
              cVar4 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar4 != '\0');
            if (pcVar11 != local_1e8 + 1) {
              local_130 = cVar4;
              memset(local_12f,0,0x103);
              FUN_004149b0(&local_130,"insideproxy set %d %s",(char)local_1f4);
              FUN_0040f270(DAT_0042e294);
              local_1ec = (char *)(2 - (uint)(DAT_0042e294 != (char *)0x1));
              LVar10 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","SetInsideProxy",4,&local_1ec,4);
              array_vpn_logprint(1,"vpnd.cpp",0x471,"SetInsideProxySettings: SHSetValueA for inside proxy, ret:%d\n",
                                 LVar10);
              break;
            }
          }
        }
        FUN_0040f600((int)pOVar2);
      }
    }
    else {
      array_vpn_logprint(1,"vpnd.cpp",0x44c,"vpnd: disable proxy rewrite\n");
    }
    break;
  case (char *)0x7:
    array_vpn_logprint(1,"vpnd.cpp",0x48b,"vpnd callback cmd is reconnecting.\n");
    FUN_0040cfd0(extraout_ECX_00,1);
    break;
  case (char *)0x2c:
    DAT_0042e28c = 1;
  case (char *)0x2b:
    FUN_00415970(0x2b,0,(char *)0x0);
    break;
  case (char *)0x2d:
    bVar5 = FUN_0040c000();
    if (bVar5) {
      pcVar14 = operator_delete_exref;
      goto LAB_004172e2;
    }
LAB_00417044:
    pcVar14 = operator_delete_exref;
    goto LAB_004172e2;
  }
  FUN_004072a0(&local_180,(undefined1 *)local_198,(double *)&local_1e0);
  puVar13 = DAT_0042e3a8;
  if (DAT_0042e3a8 != DAT_0042e3ac) {
    do {
      ppppcVar8 = (char ****)local_198;
      if (0xf < local_184) {
        ppppcVar8 = local_198[0];
      }
      FUN_00401c60(&DAT_0042e334,(char *)ppppcVar8,local_188,*puVar13);
      puVar13 = puVar13 + 1;
    } while (puVar13 != DAT_0042e3ac);
  }
  FUN_0040b790(&DAT_0042e304,local_198);
  pcVar14 = operator_delete_exref;
  if (0xf < local_184) {
    operator_delete(local_198[0]);
  }
  local_184 = 0xf;
  local_188 = 0;
  local_198[0] = (char ****)((uint)local_198[0] & 0xffffff00);
LAB_004172e2:
  if (0xf < local_19c) {
    (*pcVar14)(local_1b0[0]);
  }
  puVar3 = local_1e0;
  local_14 = local_14 & 0xffffff00;
  local_19c = 0xf;
  local_1a0 = 0;
  local_1b0[0] = (char ****)((uint)local_1b0[0] & 0xffffff00);
  if ((char)uStack_1d8 == 4) {
    if (((uStack_1d8 & 0x100) != 0) && (local_1e0 != (undefined4 *)0x0)) {
      free(local_1e0);
    }
  }
  else if (((int)(char)uStack_1d8 - 6U < 2) && (local_1e0 != (undefined4 *)0x0)) {
    FUN_004096a0(local_1e0,&local_1f0,*(int **)*local_1e0,(int *)*local_1e0);
    operator_delete((void *)*puVar3);
    operator_delete(puVar3);
  }
  if (pvStack_1d4 != (void *)0x0) {
    pvVar6 = (void *)((int)pvStack_1d4 + -4);
    _eh_vector_destructor_iterator_(pvStack_1d4,4,*(int *)((int)pvStack_1d4 + -4),(_func_void_void_ptr *)&LAB_00405090);
    operator_delete__(pvVar6);
  }
  FUN_004013c0(&local_180);
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)auStack_218);
  return;
}



// ===== FUN_00417430 @ 00417430 =====

void __thiscall FUN_00417430(void *this,int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 ***pppuVar4;
  undefined1 auStack_e8 [15];
  char local_d9;
  void *local_d8 [4];
  undefined4 local_c8;
  uint local_c4;
  char local_c0 [8];
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined4 local_a0 [10];
  undefined4 ***local_78 [4];
  int local_68;
  uint local_64;
  uint local_24;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0041e951;
  local_1c = ExceptionList;
  local_24 = DAT_00428000 ^ (uint)auStack_e8;
  ExceptionList = &local_1c;
  memset(local_a0,0,0x74);
  FUN_00402770(local_a0);
  local_c0[0] = '\0';
  local_c0[1] = '\0';
  local_c0[2] = '\0';
  local_c0[3] = '\0';
  local_c0[4] = '\0';
  local_c0[5] = '\0';
  local_c0[6] = '\0';
  local_c0[7] = '\0';
  uStack_b4 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  local_14 = 2;
  local_c4 = 0xf;
  local_c8 = 0;
  local_d8[0] = (void *)((uint)local_d8[0] & 0xffffff00);
  if ((char)*param_1 == '\0') {
    uVar2 = 0;
  }
  else {
    piVar3 = param_1;
    do {
      iVar1 = *piVar3;
      piVar3 = (int *)((int)piVar3 + 1);
    } while ((char)iVar1 != '\0');
    uVar2 = (int)piVar3 - ((int)param_1 + 1);
  }
  FUN_00401f80(local_d8,param_1,uVar2);
  local_14._0_1_ = 3;
  FUN_00401e50(local_78,(int *)local_d8,0,0xffffffff);
  pppuVar4 = local_78;
  if (0xf < local_64) {
    pppuVar4 = local_78[0];
  }
  local_d9 = FUN_004028c0(local_a0,pppuVar4,local_68 + (int)pppuVar4,local_c0);
  local_14 = CONCAT31(local_14._1_3_,2);
  if (0xf < local_c4) {
    operator_delete(local_d8[0]);
  }
  if (local_d9 == '\0') {
    array_vpn_logprint(3,"vpnd.cpp",0x4b6,"failed to parse msg [%s]\n",param_1);
  }
  else {
    FUN_00417640(this,local_c0,'\0');
  }
  local_14 = local_14 & 0xffffff00;
  FUN_004054d0((undefined4 *)local_c0);
  FUN_00404f50(local_a0);
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)auStack_e8);
  return;
}



// ===== FUN_00417600 @ 00417600 =====

void __thiscall FUN_00417600(void *this,char *param_1)

{
  FUN_00417640((void *)((int)this + -4),param_1,'\x01');
  return;
}



// ===== FUN_00417620 @ 00417620 =====

undefined4 FUN_00417620(void)

{
  HANDLE hObject;
  BOOL BVar1;
  
  hObject = (HANDLE)FUN_00412e50("MotionPro.exe");
  if (hObject == (HANDLE)0x0) {
    return 0;
  }
  BVar1 = CloseHandle(hObject);
  return CONCAT31((int3)((uint)BVar1 >> 8),1);
}



// ===== FUN_00417640 @ 00417640 =====

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00417640(void *this,char *param_1,char param_2)

{
  char *******pppppppcVar1;
  char cVar2;
  char *pcVar3;
  double *pdVar4;
  int iVar5;
  LSTATUS LVar6;
  void *this_00;
  undefined4 uVar7;
  int *piVar8;
  char *******pppppppcVar9;
  DWORD DVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  undefined4 *puVar14;
  char *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  char *extraout_ECX_04;
  char *extraout_ECX_05;
  char *extraout_ECX_06;
  char *extraout_ECX_07;
  LPCSTR ******pppppppCVar15;
  uint uVar16;
  undefined4 *puVar17;
  bool bVar18;
  undefined4 uStackY_1ce4;
  undefined4 uStackY_1cdc;
  undefined4 uStackY_1cd8;
  undefined4 uStackY_1c90;
  undefined4 uStackY_1c8c;
  char *pcStackY_1c88;
  undefined4 uStackY_1c84;
  char *pcStackY_1c80;
  char *pcStackY_1c7c;
  char *pcStackY_1c78;
  char *pcStackY_1c74;
  char *pcStackY_1c70;
  undefined4 uVar19;
  undefined1 auStack_1c38 [4];
  void *local_1c34;
  undefined4 local_1c30;
  undefined4 local_1c2c;
  uint local_1c28;
  undefined4 local_1c24;
  undefined4 local_1c20;
  undefined4 local_1c1c;
  char *pcStack_1c14;
  char *pcStack_1c10;
  uint uStack_1c0c;
  char *pcStack_1c08;
  int *local_1c04;
  undefined4 local_1c00;
  undefined4 local_1bfc;
  void *local_1bf8 [4];
  undefined4 local_1be8;
  uint local_1be4;
  undefined1 local_1be0 [2];
  undefined1 auStack_1bde [3];
  undefined4 uStack_1bdb;
  undefined4 uStack_1bd3;
  uint uStack_1bcf;
  undefined4 uStack_1bc7;
  undefined4 uStack_1bc3;
  undefined4 uStack_1bbf;
  undefined4 uStack_1bb3;
  char *******pppppppcStack_1baf;
  undefined4 *******pppppppuStack_1ba3;
  undefined4 uStack_1b9b;
  undefined4 uStack_1b97;
  undefined1 uStack_1b8b;
  undefined4 uStack_1b88;
  undefined4 uStack_1b84;
  undefined4 uStack_1b80;
  uint uStack_1b78;
  code *pcStack_1b74;
  undefined1 uStack_1b64;
  undefined *puStack_1b63;
  undefined *puStack_1b5f;
  undefined4 uStack_1b51;
  undefined4 local_1b48 [6];
  undefined4 auStack_1b30 [6];
  undefined4 local_1b18 [6];
  undefined4 auStack_1b00 [6];
  undefined4 auStack_1ae8 [6];
  undefined4 local_1ad0 [6];
  undefined4 local_1ab8 [6];
  undefined4 local_1aa0 [6];
  undefined4 local_1a88 [6];
  undefined4 local_1a70 [6];
  undefined4 local_1a58;
  char local_1a48 [408];
  char local_18b0;
  uint local_18ac;
  uint local_18a8;
  int local_18a4;
  int local_18a0;
  uint local_189c;
  uint local_1898;
  int local_1894;
  int local_1890;
  uint local_188c;
  uint local_1888;
  int local_1884;
  int local_1880;
  uint local_187c;
  uint local_1878;
  int local_1874;
  int local_1870;
  char *local_186c;
  uint local_1868;
  char local_123f [1551];
  char *******local_c30;
  int local_c2c;
  uint local_c28;
  undefined4 local_c24;
  undefined4 local_c20;
  uint local_c1c;
  DWORD local_c18;
  char *local_c14;
  undefined4 local_c10;
  undefined4 uStack_c0c;
  undefined4 uStack_c08;
  undefined4 uStack_c04;
  undefined8 local_c00;
  undefined8 local_bf0;
  undefined4 uStack_be8;
  undefined4 uStack_be4;
  undefined8 local_be0;
  undefined4 local_bd0;
  char *******local_bcc [4];
  char ******local_bbc;
  char ******local_bb8;
  DWORD local_bb4;
  void *local_bb0 [4];
  undefined4 local_ba0;
  uint local_b9c;
  char *******local_b98 [4];
  undefined4 local_b88;
  uint local_b84;
  void *local_b80 [4];
  undefined4 local_b70;
  uint local_b6c;
  LPCSTR ******local_b68 [4];
  undefined4 local_b58;
  uint local_b54;
  undefined4 *******local_b50 [4];
  undefined4 local_b40;
  uint local_b3c;
  void *local_b38 [4];
  undefined4 local_b28;
  uint local_b24;
  char *******local_b20 [4];
  undefined4 local_b10;
  uint local_b0c;
  void *local_b08 [4];
  undefined4 local_af8;
  uint local_af4;
  undefined8 local_af0;
  undefined4 uStack_ae8;
  undefined4 uStack_ae4;
  undefined8 local_ae0;
  undefined4 local_acc;
  undefined1 local_ac8 [16];
  undefined4 local_ab8;
  undefined4 local_ab4;
  undefined **local_ab0;
  undefined4 local_aac;
  undefined4 local_aa8;
  undefined4 local_aa4;
  undefined1 local_aa0;
  undefined4 local_a90;
  undefined4 local_a8c;
  undefined1 local_a88;
  undefined4 local_a78;
  undefined4 local_a74;
  undefined4 local_a70;
  undefined4 local_a6c;
  undefined1 local_a68;
  undefined4 local_a5c;
  undefined8 local_a58;
  undefined8 local_a50;
  undefined8 local_a48;
  undefined8 local_a40;
  undefined8 local_a38;
  undefined8 local_a30;
  undefined4 local_a28;
  char local_828;
  undefined1 local_827 [1023];
  undefined4 uStack_428;
  uint local_24;
  void *pvStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0041ec1f;
  local_1c = ExceptionList;
  local_24 = DAT_00428000 ^ (uint)auStack_1c38;
  ExceptionList = &local_1c;
  local_c14 = param_1;
  local_1c34 = this;
  pvStack_20 = this;
  memset(&local_ab0,0,0x4c);
  local_ab0 = Json::StyledWriter::vftable;
  local_aac = 0;
  local_aa8 = 0;
  local_aa4 = 0;
  local_a8c = 0xf;
  local_a90 = 0;
  local_aa0 = 0;
  local_a74 = 0xf;
  local_a78 = 0;
  local_a88 = 0;
  local_a70 = 0x4a;
  local_a6c = 3;
  local_a68 = 0;
  local_bf0._0_4_ = 0;
  local_bf0._4_4_ = 0;
  uStack_be4 = 0;
  uStack_be8 = 0;
  local_be0 = 0;
  local_bb8 = (char ******)0xf;
  local_bbc = (char ******)0x0;
  local_bcc[0] = (char *******)((uint)local_bcc[0] & 0xffffff00);
  local_c10 = 0;
  uStack_c0c = 0;
  uStack_c04 = 0;
  local_c00 = 0;
  uStack_c08 = 0;
  local_af0._0_4_ = 0;
  local_af0._4_4_ = 0;
  uStack_ae4 = 0;
  uStack_ae8 = 0;
  local_ae0 = 0;
  local_b9c = 0xf;
  local_ba0 = 0;
  local_bb0[0] = (void *)((uint)local_bb0[0] & 0xffffff00);
  local_ab4 = 0xf;
  local_ab8 = 0;
  local_ac8[0] = 0;
  local_b54 = 0xf;
  local_b58 = 0;
  local_b68[0] = (LPCSTR ******)((uint)local_b68[0] & 0xffffff00);
  local_b24 = 0xf;
  local_b28 = 0;
  local_b38[0] = (void *)((uint)local_b38[0] & 0xffffff00);
  local_14 = 0xb;
  local_b84 = 0xf;
  local_b88 = 0;
  local_b98[0] = (char *******)((uint)local_b98[0] & 0xffffff00);
  FUN_00401f80(local_b98,(int *)&DAT_0041f7b1,0);
  local_14._0_1_ = 0xc;
  local_828 = '\0';
  memset(local_827,0,0x3ff);
  local_b0c = 0xf;
  local_b10 = 0;
  local_b20[0] = (char *******)((uint)local_b20[0] & 0xffffff00);
  FUN_00401f80(local_b20,(int *)&DAT_0041f7b1,0);
  local_14._0_1_ = 0xd;
  local_b6c = 0xf;
  local_a38 = 0;
  local_a40 = 0;
  local_a58 = 0;
  local_a48 = 0;
  local_a50 = 0;
  local_a30 = 0;
  local_b70 = 0;
  local_b80[0] = (void *)((uint)local_b80[0] & 0xffffff00);
  FUN_00401f80(local_b80,(int *)&DAT_0041f7b1,0);
  local_14._0_1_ = 0xe;
  local_a5c = 1;
  local_acc = 0;
  local_bd0 = 0;
  local_a28._0_1_ = '\0';
  memset((void *)((int)&local_a28 + 1),0,0x1ff);
  local_b3c = 0xf;
  local_b40 = 0;
  local_b50[0] = (undefined4 *******)((uint)local_b50[0] & 0xffffff00);
  FUN_00401f80(local_b50,(int *)&DAT_0041f7b1,0);
  local_14._0_1_ = 0xf;
  local_af4 = 0xf;
  local_af8 = 0;
  local_b08[0] = (void *)((uint)local_b08[0] & 0xffffff00);
  FUN_00401f80(local_b08,(int *)&DAT_0041f7b1,0);
  local_14 = CONCAT31(local_14._1_3_,0x10);
  pcVar3 = (char *)FUN_00406490(param_1,0x41f6f0);
  FUN_00405560(&local_c10,pcVar3);
  if ((char)uStack_c08 == '\0') {
LAB_0041b582:
    if (0xf < local_af4) {
      operator_delete(local_b08[0]);
    }
    local_b08[0] = (void *)((uint)local_b08[0] & 0xffffff00);
    local_af8 = 0;
    local_af4 = 0xf;
    if (0xf < local_b3c) {
      operator_delete(local_b50[0]);
    }
    local_b50[0] = (undefined4 *******)((uint)local_b50[0] & 0xffffff00);
    local_b40 = 0;
    local_b3c = 0xf;
    if (0xf < local_b6c) {
      operator_delete(local_b80[0]);
    }
    local_b80[0] = (void *)((uint)local_b80[0] & 0xffffff00);
    local_b70 = 0;
    local_b6c = 0xf;
    if (0xf < local_b0c) {
      operator_delete(local_b20[0]);
    }
    local_b20[0] = (char *******)((uint)local_b20[0] & 0xffffff00);
    local_b10 = 0;
    local_b0c = 0xf;
    if (0xf < local_b84) {
      operator_delete(local_b98[0]);
    }
    local_b98[0] = (char *******)((uint)local_b98[0] & 0xffffff00);
    local_b88 = 0;
    local_b84 = 0xf;
    if (0xf < local_b24) {
      operator_delete(local_b38[0]);
    }
    local_b38[0] = (void *)((uint)local_b38[0] & 0xffffff00);
    local_b28 = 0;
    local_b24 = 0xf;
    if (0xf < local_b54) {
      operator_delete(local_b68[0]);
    }
    local_b68[0] = (LPCSTR ******)((uint)local_b68[0] & 0xffffff00);
    local_b58 = 0;
    local_b54 = 0xf;
    if (0xf < local_b9c) {
      operator_delete(local_bb0[0]);
    }
    local_b9c = 0xf;
    local_ba0 = 0;
    local_bb0[0] = (void *)((uint)local_bb0[0] & 0xffffff00);
    local_14._0_1_ = 5;
    FUN_004054d0((undefined4 *)&local_af0);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0(&local_c10);
    if ((char ******)0xf < local_bb8) {
      operator_delete(local_bcc[0]);
    }
LAB_0041b766:
    local_bcc[0] = (char *******)((uint)local_bcc[0] & 0xffffff00);
    local_bbc = (char ******)0x0;
    local_bb8 = (char ******)0xf;
    goto LAB_0041b784;
  }
  pdVar4 = (double *)FUN_004062c0(&local_c10,"action");
  local_c18 = FUN_00405780(pdVar4);
  if (local_c18 == 6) {
    array_vpn_logprint();
    FUN_00405f10();
    pcVar3 = (char *)FUN_00406490(local_c14,0x41f6f0);
    FUN_00405560(&DAT_0042e2e0,pcVar3);
  }
  switch(local_c18) {
  case 2:
    pdVar4 = (double *)FUN_004062c0(&local_c10,"port");
    uVar16 = FUN_004058f0(pdVar4);
    local_c14 = (char *)(uVar16 & 0xffff);
    piVar8 = (int *)FUN_0041c150(&local_1c00,(short *)&local_c14,*(short **)((int)this + 0xa8),
                                 *(short **)((int)this + 0xac));
    if (*piVar8 == *(int *)((int)this + 0xac)) {
      FUN_0041beb0((void *)((int)this + 0xa8),(undefined2 *)&local_c14);
    }
    FUN_004051e0(&local_c30,0);
    local_14._0_1_ = 0x11;
    pcVar3 = extraout_ECX;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"error");
    FUN_00405560(pvVar13,pcVar3);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"register success");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x12;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"message");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051e0(&local_c30,2);
    local_14._0_1_ = 0x13;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"action");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    puVar14 = (undefined4 *)FUN_004072a0(&local_ab0,(undefined1 *)local_1b48,(double *)&local_bf0);
    FUN_00408370(local_bcc,puVar14);
    FUN_00401da0(local_1b48);
    if (param_2 != '\0') {
      FUN_0040b790((void *)((int)this + 4),local_bcc);
      break;
    }
    goto LAB_00417d9a;
  case 3:
    pdVar4 = (double *)FUN_004062c0(&local_c10,"port");
    uVar16 = FUN_004058f0(pdVar4);
    local_c14 = (char *)(uVar16 & 0xffff);
    array_vpn_logprint();
    puVar14 = (undefined4 *)
              FUN_0041c150(&local_1bfc,(short *)&local_c14,*(short **)((int)this + 0xa8),*(short **)((int)this + 0xac));
    if ((void *)*puVar14 != *(void **)((int)this + 0xac)) {
      FUN_0041bf20((void *)((int)this + 0xa8),&local_bb4,(void *)*puVar14);
    }
    break;
  case 4:
    array_vpn_logprint();
    FUN_00401da0(local_b08);
    FUN_00401da0(local_b50);
    FUN_00401da0(local_b80);
    FUN_00401da0(local_b20);
    FUN_00401da0(local_b98);
    FUN_00401da0(local_b38);
    FUN_00401da0(local_b68);
    FUN_00401da0((undefined4 *)local_ac8);
    FUN_00401da0(local_bb0);
    local_14._0_1_ = 5;
    FUN_004054d0((undefined4 *)&local_af0);
    local_14._0_1_ = 3;
    FUN_004054d0(&local_c10);
    FUN_00401da0(local_bcc);
    local_14 = (uint)local_14._1_3_ << 8;
    FUN_004054d0((undefined4 *)&local_bf0);
    FUN_004013c0(&local_ab0);
    goto LAB_0041b7a9;
  default:
    array_vpn_logprint();
    goto LAB_0041b582;
  case 6:
    DAT_0042dbfc = 0;
    memset(&DAT_0042dd00,0,0x588);
    FUN_00412f30();
    FUN_00412f80();
    FUN_00413ea0();
    FUN_0041bc00();
    DAT_0042e294 = 0;
    array_vpn_logprint();
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","VPNstatus",4,&local_a5c,4);
    memset(local_1be0,0,0x93);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"enablednsproxy");
    _DAT_0042e290 = FUN_00405780(pdVar4);
    array_vpn_logprint();
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"host");
    if (*(char *)(puVar14 + 2) == '\x04') {
      local_1c04 = (int *)*puVar14;
    }
    else {
      local_1c04 = (int *)FUN_00405620();
    }
    unique0x1000428c = local_1c04;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"domain");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1bdb = *puVar14;
    }
    else {
      uStack_1bdb = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
    iVar5 = FUN_004062c0(pvVar13,"port");
    if (*(char *)(iVar5 + 8) == '\0') {
      DAT_0042dd04 = 0;
    }
    else {
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      pdVar4 = (double *)FUN_004062c0(pvVar13,"port");
      DAT_0042dd04 = FUN_00405780(pdVar4);
    }
    memset(&DAT_00429530,0,0x80);
    memset(&DAT_0042d7f8,0,0x400);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"domain");
    if (*(char *)(puVar14 + 2) == '\x04') {
      cVar2 = (char)*puVar14;
    }
    else {
      cVar2 = FUN_00405620();
    }
    FUN_004149d0(&DAT_00429530,"%s",cVar2);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"session");
    if (*(char *)(puVar14 + 2) == '\x04') {
      cVar2 = (char)*puVar14;
    }
    else {
      cVar2 = FUN_00405620();
    }
    FUN_00414a70(&DAT_0042d7f8,"%s",cVar2);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
    iVar5 = FUN_004062c0(pvVar13,"site_name");
    if (*(char *)(iVar5 + 8) != '\0') {
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"site_name");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_00414930(&DAT_0042e088,"%s",cVar2);
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"session_id");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_00414930(&DAT_0042e188,"%s",cVar2);
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"ip");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_004149d0(&DAT_0042dd08,"%s",cVar2);
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"pub_key");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_00414930(&DAT_0042dd88,"%s",cVar2);
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"wg_desc");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_00414930(&DAT_0042de88,"%s",cVar2);
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"wg_name");
      if (*(char *)(puVar14 + 2) == '\x04') {
        cVar2 = (char)*puVar14;
      }
      else {
        cVar2 = FUN_00405620();
      }
      FUN_00414930(&DAT_0042df88,"%s",cVar2);
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"server_type");
    uStack_1bd3 = FUN_00405780(pdVar4);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"port");
    uStack_1bcf = FUN_004058f0(pdVar4);
    uStack_1bcf = uStack_1bcf & 0xffff;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    uVar7 = 0x4189db;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"method");
    puVar14 = (undefined4 *)FUN_00405660(pvVar13,(undefined1 *)auStack_1b30);
    uVar19 = 0x4189f7;
    FUN_00408370(local_b38,puVar14);
    FUN_00401da0(auStack_1b30);
    iVar5 = FUN_0041bf60(local_b38,uVar7,uVar19,0xf);
    if (iVar5 != -1) {
      puVar14 = (undefined4 *)FUN_00414140(local_b38,(undefined1 *)auStack_1b00,0xf,0x10);
      FUN_00408370(local_b98,puVar14);
      FUN_00401da0(auStack_1b00);
    }
    pppppppcVar9 = (char *******)local_b98;
    if (0xf < local_b84) {
      pppppppcVar9 = local_b98[0];
    }
    iVar5 = atoi((char *)pppppppcVar9);
    uStack_1b64 = (undefined1)iVar5;
    array_vpn_logprint();
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"method");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1bc7 = *puVar14;
    }
    else {
      uStack_1bc7 = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"validcode");
    if (*(char *)(puVar14 + 2) == '\x04') {
      pppppppcVar9 = (char *******)*puVar14;
    }
    else {
      pppppppcVar9 = (char *******)FUN_00405620();
    }
    pppppppcStack_1baf = pppppppcVar9;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"username");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1bc3 = *puVar14;
    }
    else {
      uStack_1bc3 = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"password");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1bbf = *puVar14;
    }
    else {
      uStack_1bbf = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"session");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1bb3 = *puVar14;
    }
    else {
      uStack_1bb3 = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"certpath");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1b9b = *puVar14;
    }
    else {
      uStack_1b9b = FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"certpassword");
    if (*(char *)(puVar14 + 2) == '\x04') {
      uStack_1b97 = *puVar14;
    }
    else {
      uStack_1b97 = FUN_00405620();
    }
    puStack_1b63 = &DAT_0041f7b1;
    puStack_1b5f = &DAT_0041f7b1;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"reconncount");
    uStack_1b88 = FUN_00405780(pdVar4);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"reconntime");
    uStack_1b84 = FUN_00405780(pdVar4);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"reconninterval");
    uStack_1b80 = FUN_00405780(pdVar4);
    gethostname((char *)&local_a28,0x1ff);
    array_vpn_logprint();
    pcVar3 = (char *)&local_a28;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if (pcVar3 != (char *)((int)&local_a28 + 1)) {
      FUN_00401dd0(local_b08,&local_a28);
      cVar2 = FUN_004139a0((LPCSTR)local_b08,local_b50);
      if (cVar2 == '\0') {
        FUN_004083b0(local_b50,(int *)local_b08);
      }
      pppppppuStack_1ba3 = local_b50;
      if (0xf < local_b3c) {
        pppppppuStack_1ba3 = local_b50[0];
      }
      array_vpn_logprint();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pcVar3 = (char *)FUN_004062c0(pvVar13,"flags");
    FUN_00405560(&local_af0,pcVar3);
    if ((char)uStack_ae8 == '\0') {
      local_c18 = 0x200;
    }
    else {
      local_c18 = FUN_004058f0((double *)&local_af0);
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"tunneltype");
    uStack_1c0c = FUN_00405780(pdVar4);
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"sslproto");
    uStack_1b51 = FUN_00405780(pdVar4);
    array_vpn_logprint();
    uStack_1b8b = (undefined1)uStack_1c0c;
    if (DAT_0042e28c != 0) {
      array_vpn_logprint();
      uStack_1b8b = 0;
    }
    uStack_1b78 = local_c18 | 0x180000;
    DAT_0042e28c = 0;
    pcStack_1b74 = FUN_00416570;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"proxyhost");
    if (*(char *)(puVar14 + 2) == '\x04') {
      local_c14 = (char *)*puVar14;
    }
    else {
      local_c14 = (char *)FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"proxyport");
    uStack_1c0c = FUN_00405780(pdVar4);
    uStack_1c0c = uStack_1c0c & 0xffff;
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"proxydomain");
    if (*(char *)(puVar14 + 2) == '\x04') {
      pcStack_1c14 = (char *)*puVar14;
    }
    else {
      pcStack_1c14 = (char *)FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"proxyusername");
    if (*(char *)(puVar14 + 2) == '\x04') {
      pcStack_1c10 = (char *)*puVar14;
    }
    else {
      pcStack_1c10 = (char *)FUN_00405620();
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    puVar14 = (undefined4 *)FUN_004062c0(pvVar13,"proxypassword");
    if (*(char *)(puVar14 + 2) == '\x04') {
      pcStack_1c08 = (char *)*puVar14;
    }
    else {
      pcStack_1c08 = (char *)FUN_00405620();
    }
    array_vpn_logprint();
    DAT_0042e288 = 0;
    pppppppcVar1 = (char *******)((int)pppppppcVar9 + 1);
    do {
      cVar2 = *(char *)pppppppcVar9;
      pppppppcVar9 = (char *******)((int)pppppppcVar9 + 1);
    } while (cVar2 != '\0');
    if (pppppppcVar9 == pppppppcVar1) {
      uStack_428._0_1_ = cVar2;
      memset((undefined1 *)((int)&uStack_428 + 1),0,0x3ff);
      local_c18 = 0x400;
      local_bb4 = 1;
      LVar6 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\ValidCode","Value",&local_bb4,&uStack_428,&local_c18);
      if (LVar6 == 0) {
        FUN_00401d40(&local_c30,&uStack_428);
        pppppppcStack_1baf = (char *******)&local_c30;
        if (0xf < local_c1c) {
          pppppppcStack_1baf = local_c30;
        }
        FUN_00401da0(&local_c30);
      }
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pcVar3 = (char *)FUN_004062c0(pvVar13,"awg");
    FUN_00405560(&local_af0,pcVar3);
    if ((((char)uStack_ae8 != '\0') && (iVar5 = FUN_004058f0((double *)&local_af0), iVar5 == 1)) &&
       (cVar2 = FUN_00415350(), cVar2 != '\0')) {
      DAT_0042e288 = 1;
    }
    puVar14 = (undefined4 *)FUN_0040daa0((undefined1 *)auStack_1ae8,pcStack_1c08);
    FUN_00408370(local_b20,puVar14);
    FUN_00401da0(auStack_1ae8);
    FUN_0040d5f0(0,"proxyhost",local_c14,(char *)0x0);
    pcVar3 = (char *)(uStack_1c0c & 0xffff);
    FUN_0040d5f0(1,"proxyport","",pcVar3);
    FUN_0040d5f0(0,"proxydomain",pcStack_1c14,(char *)0x0);
    FUN_0040d5f0(0,"proxyuname",pcStack_1c10,(char *)0x0);
    pppppppcVar9 = (char *******)local_b20;
    if (0xf < local_b0c) {
      pppppppcVar9 = local_b20[0];
    }
    pcStackY_1c70 = (char *)0x419196;
    FUN_0040d5f0(0,"proxypwd",(char *)pppppppcVar9,(char *)0x0);
    pcStackY_1c70 = (char *)0x41919f;
    FUN_0040fa90((char)local_1c04);
    pcStackY_1c70 = pcStack_1c10;
    pcStackY_1c74 = pcStack_1c14;
    pcStackY_1c7c = local_c14;
    pcStackY_1c80 = "vpnd received outside proxy config:%s, %u, %s, %s";
    uStackY_1c84 = 0x70e;
    pcStackY_1c88 = "vpnd.cpp";
    uStackY_1c8c = 1;
    uStackY_1c90 = 0x4191c3;
    pcStackY_1c78 = pcVar3;
    array_vpn_logprint();
    FUN_00414020();
    FUN_00410510();
    local_c18 = FUN_00413460();
    array_vpn_logprint();
    if (((local_c18 == 0xb) || (cVar2 = FUN_00410300(), cVar2 == '\0')) || (local_c18 != 2)) {
      array_vpn_set_proxy();
      puVar14 = (undefined4 *)local_1be0;
      puVar17 = &uStackY_1cd8;
      for (iVar5 = 0x24; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar17 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar17 = puVar17 + 1;
      }
      *(undefined2 *)puVar17 = *(undefined2 *)puVar14;
      *(undefined1 *)((int)puVar17 + 2) = *(undefined1 *)((int)puVar14 + 2);
      uStackY_1cdc = 0x4192de;
      iVar5 = array_vpn_start2();
      pvVar13 = local_1c34;
      if (iVar5 == 0) {
        FUN_00401dd0((void *)((int)local_1c34 + 0xcc),local_1c04);
        this_00 = (void *)FUN_004062c0(&local_c10,"site");
        puVar14 = (undefined4 *)FUN_004062c0(this_00,"name");
        if (*(char *)(puVar14 + 2) == '\x04') {
          FUN_00401dd0((void *)((int)pvVar13 + 0xb4),(int *)*puVar14);
        }
        else {
          piVar8 = (int *)FUN_00405620();
          FUN_00401dd0((void *)((int)pvVar13 + 0xb4),piVar8);
        }
      }
      else if ((iVar5 == 0x19) && ((iVar5 = array_vpn_get_status(), iVar5 == 2 || (iVar5 == 6)))) {
        FUN_00415970(3,0,(char *)0x0);
      }
      if (DAT_0042e288 == 0) {
        iVar5 = 0;
        while( true ) {
          iVar5 = iVar5 + 1;
          array_vpn_logprint();
          if (DAT_0042dbfc == 2) {
            iVar5 = FUN_00413460();
            if (iVar5 == 2) {
              FUN_00410710(1);
            }
            goto switchD_00417b09_caseD_10;
          }
          if (DAT_0042dbfc == 1) break;
          if ((DAT_0042dbfc == 3) || (Sleep(1000), 0x3b < iVar5)) goto switchD_00417b09_caseD_10;
        }
        if ((local_c18 != 0xb) && (cVar2 = FUN_00410300(), cVar2 != '\0')) {
          puVar14 = (undefined4 *)local_1be0;
          puVar17 = &uStackY_1ce4;
          for (iVar5 = 0x24; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar17 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar17 = puVar17 + 1;
          }
          *(undefined2 *)puVar17 = *(undefined2 *)puVar14;
          *(undefined1 *)((int)puVar17 + 2) = *(undefined1 *)((int)puVar14 + 2);
          FUN_00412c90();
          FUN_0040dcd0();
        }
      }
    }
    else {
      DAT_0042e288 = 0;
      FUN_0040de30();
      cVar2 = FUN_0040dcf0();
      if (cVar2 == '\0') {
        array_vpn_logprint();
      }
      else {
        array_vpn_logprint();
        FUN_0040e590();
      }
      puVar14 = (undefined4 *)local_1be0;
      puVar17 = &uStackY_1ce4;
      for (iVar5 = 0x24; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar17 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar17 = puVar17 + 1;
      }
      *(undefined2 *)puVar17 = *(undefined2 *)puVar14;
      *(undefined1 *)((int)puVar17 + 2) = *(undefined1 *)((int)puVar14 + 2);
      FUN_00412c90();
      FUN_0040dcd0();
    }
    break;
  case 7:
    FUN_0041bc00();
    array_vpn_logprint();
    DAT_0042dbfc = 0;
    FUN_00415970(4,0,(char *)0x0);
    pdVar4 = (double *)FUN_004062c0(&local_c10,"webdisconnect");
    local_c18 = FUN_00405780(pdVar4);
    pcVar3 = (char *)FUN_004062c0(&local_c10,"flags");
    FUN_00405560(&local_af0,pcVar3);
    uVar16 = FUN_004058f0((double *)&local_af0);
    if ((uVar16 & 0x4000) == 0) {
      FUN_00415970(0x21,0,(char *)0x0);
    }
    iVar5 = array_vpn_get_status();
    array_vpn_logprint();
    if (iVar5 == 5) {
      array_vpn_logprint();
      if (local_c18 == 1) {
        FUN_00414dc0(1);
      }
      array_vpn_set_status();
    }
    else {
      if (local_c18 == 1) {
        array_vpn_logprint();
        FUN_00414dc0(0);
      }
      FUN_0040cf80();
      iVar5 = FUN_00413460();
      array_vpn_logprint();
      cVar2 = FUN_00410300();
      if ((cVar2 == '\0') || (iVar5 != 2)) {
        if ((char)uStack_ae8 == '\0') {
          array_vpn_stop();
        }
        else {
          FUN_004058f0((double *)&local_af0);
          array_vpn_stop2();
        }
        pvVar13 = local_1c34;
        FUN_00401dd0((void *)((int)local_1c34 + 0xcc),(int *)&DAT_0041f7b1);
        FUN_00401dd0((void *)((int)pvVar13 + 0xb4),(int *)&DAT_0041f7b1);
        iVar5 = 0;
        while( true ) {
          array_vpn_get_status();
          array_vpn_logprint();
          iVar11 = array_vpn_get_status();
          if ((iVar11 == 0) || (iVar11 = array_vpn_get_status(), iVar11 == 7)) break;
          iVar5 = iVar5 + 1;
          Sleep(300);
          if (9 < iVar5) {
LAB_00418141:
            array_vpn_logprint();
            FUN_0040cfd0(extraout_ECX_03,0);
            Sleep(1000);
            FUN_00415970(5,0,(char *)0x0);
                    /* WARNING: Subroutine does not return */
            exit(0);
          }
        }
        if (iVar5 < 10) break;
        goto LAB_00418141;
      }
      if (((char)uStack_ae8 == '\0') || (uVar16 = FUN_004058f0((double *)&local_af0), (uVar16 & 0x4000) == 0)) {
        FUN_00412160('\x01');
      }
      else {
        FUN_00412160('\0');
      }
    }
    break;
  case 8:
    FUN_004051e0(&local_c30,0);
    local_14._0_1_ = 0x14;
    pcVar3 = extraout_ECX_04;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"error");
    FUN_00405560(pvVar13,pcVar3);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"vpn current status");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x15;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"message");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051e0(&local_c30,8);
    local_14._0_1_ = 0x16;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"action");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    local_bb4 = array_vpn_get_status();
    DVar10 = local_bb4;
    if (local_bb4 == 5) {
      uVar7 = FUN_00417620();
      if ((char)uVar7 == '\0') {
        array_vpn_logprint();
        array_vpn_set_status();
        DVar10 = 0;
      }
      else {
        DVar10 = local_bb4;
      }
    }
    FUN_004051e0(&local_c30,DVar10);
    local_14._0_1_ = 0x17;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"status");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004052a0(&local_c30,(char *)((int)this + 0xb4));
    local_14._0_1_ = 0x18;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pvVar13 = (void *)FUN_004062c0(pvVar13,"site");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"name");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004052a0(&local_c30,(char *)((int)this + 0xcc));
    local_14._0_1_ = 0x19;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pvVar13 = (void *)FUN_004062c0(pvVar13,"site");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"host");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"daemon");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x1a;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"sender");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"receiver");
    pcVar3 = (char *)FUN_00406490(local_c14,0x422e50);
    FUN_00405560(pvVar13,pcVar3);
    puVar14 = (undefined4 *)FUN_004072a0(&local_ab0,(undefined1 *)local_1ad0,(double *)&local_bf0);
    FUN_00408370(local_bcc,puVar14);
    puVar14 = local_1ad0;
    goto LAB_00419770;
  case 0xb:
    pvVar13 = (void *)FUN_004062c0(&local_c10,"log");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"level");
    uVar16 = FUN_00405780(pdVar4);
    if (uVar16 < 4) {
      array_vpn_set_log_level();
      array_vpn_logprint();
    }
    else {
      array_vpn_logprint();
    }
    break;
  case 0xd:
    array_vpn_logprint();
    array_vpn_get_l3vpn_config();
    FUN_004051e0(&local_c30,0);
    local_14._0_1_ = 0x24;
    pcVar3 = extraout_ECX_06;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"error");
    FUN_00405560(pvVar13,pcVar3);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"vpn config");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x25;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"message");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051e0(&local_c30,0xd);
    local_14._0_1_ = 0x26;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"action");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051a0(&local_c30,local_1a58);
    local_14._0_1_ = 0x27;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051a0(&local_c30,local_1868);
    local_14._0_1_ = 0x28;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"netpoolflag");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,local_123f);
    local_14._0_1_ = 0x29;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"currentacsmode");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    uVar16 = 0;
    if (local_188c != 0) {
      do {
        FUN_004051a0(&local_c30,*(undefined4 *)(local_1884 + uVar16 * 4));
        local_14._0_1_ = 0x2a;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"dns");
        pppppppcVar9 = (char *******)&local_c30;
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        FUN_00406570(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_188c);
    }
    uVar16 = 0;
    if (local_1888 != 0) {
      do {
        FUN_00405260(&local_c30,*(char **)(local_1880 + uVar16 * 4));
        local_14._0_1_ = 0x2b;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"dns");
        piVar8 = (int *)FUN_004062c0(pvVar13,"ipv6");
        pppppppcVar9 = (char *******)&local_c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_1888);
    }
    if (local_186c != (char *)0x0) {
      FUN_00405260(&local_c30,local_186c);
      local_14._0_1_ = 0x2c;
      pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
      pppppppcVar9 = (char *******)&local_c30;
      pvVar13 = (void *)FUN_004062c0(pvVar13,"search");
      FUN_00405560(pvVar13,(char *)pppppppcVar9);
      local_14 = CONCAT31(local_14._1_3_,0x10);
      FUN_004054d0(&local_c30);
    }
    uVar16 = 0;
    if (local_187c != 0) {
      do {
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c2c = 0;
        local_1c30 = **(undefined4 **)(local_1874 + uVar16 * 4);
        local_1c28 = local_1c28 & 0xfffffe02 | 2;
        local_14._0_1_ = 0x2d;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"hostmap");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"ip");
        pcVar3 = (char *)&local_1c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,pcVar3);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_1c30);
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_c28 = local_c28 & 0xffffff04 | 0x104;
        local_c30 = (char *******)FUN_00404fd0((char *)(*(int *)(local_1874 + uVar16 * 4) + 4),0xffffffff);
        local_14._0_1_ = 0x2e;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"hostmap");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"host");
        pppppppcVar9 = (char *******)&local_c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_187c);
    }
    if (local_1878 != 0) {
      uVar16 = 0;
      do {
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_c28 = local_c28 & 0xffffff04 | 0x104;
        local_c30 = (char *******)FUN_00404fd0(*(char **)(local_1870 + uVar16 * 4),0xffffffff);
        local_14._0_1_ = 0x2f;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"hostmap");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"ip");
        pppppppcVar9 = (char *******)&local_c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_c30);
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c28 = local_1c28 & 0xffffff04 | 0x104;
        local_1c30 = FUN_00404fd0((char *)(*(int *)(local_1870 + uVar16 * 4) + 0x88),0xffffffff);
        local_14._0_1_ = 0x30;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"hostmap");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"host");
        pcVar3 = (char *)&local_1c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,pcVar3);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_1c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_1878);
    }
    uVar16 = 0;
    if (local_18ac != 0) {
      do {
        if (local_18b0 != '\0') break;
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c30 = *(undefined4 *)(local_18a4 + uVar16 * 8);
        local_1c28 = local_1c28 & 0xfffffe02 | 2;
        local_1c2c = 0;
        local_14._0_1_ = 0x31;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"include");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"net");
        pcVar3 = (char *)&local_1c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,pcVar3);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_1c30);
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_c30 = *(char ********)(local_18a4 + 4 + uVar16 * 8);
        local_c28 = local_c28 & 0xfffffe02 | 2;
        local_c2c = 0;
        local_14._0_1_ = 0x32;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"include");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"mask");
        pppppppcVar9 = (char *******)&local_c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_18ac);
    }
    local_c18 = 0;
    if (local_18a8 != 0) {
      iVar5 = 0;
      do {
        if (local_18b0 != '\0') break;
        local_1c28 = local_1c28 & 0xffffff04 | 0x104;
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c30 = FUN_00404fd0((char *)(local_18a0 + iVar5),0xffffffff);
        local_14._0_1_ = 0x33;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"include");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"net");
        pcVar3 = (char *)&local_1c30;
        uVar16 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar16);
        FUN_00405560(pvVar13,pcVar3);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_1c30);
        local_c30 = (char *******)array_vpn_get_ipv6_prefix();
        local_c2c = (int)local_c30 >> 0x1f;
        local_c28 = local_c28 & 0xfffffe01 | 1;
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_14._0_1_ = 0x34;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"include");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"mask");
        pppppppcVar9 = (char *******)&local_c30;
        uVar16 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar16);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        iVar5 = iVar5 + 0x110;
        local_c18 = local_c18 + 1;
      } while (local_c18 < local_18a8);
    }
    uVar16 = 0;
    if (local_189c != 0) {
      do {
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_c30 = *(char ********)(local_1894 + uVar16 * 8);
        local_c28 = local_c28 & 0xfffffe02 | 2;
        local_c2c = 0;
        local_14._0_1_ = 0x35;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"exclude");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"net");
        pppppppcVar9 = (char *******)&local_c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_c30);
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c30 = *(undefined4 *)(local_1894 + 4 + uVar16 * 8);
        local_1c28 = local_1c28 & 0xfffffe02 | 2;
        local_1c2c = 0;
        local_14._0_1_ = 0x36;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"exclude");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
        piVar8 = (int *)FUN_004062c0(pvVar13,"mask");
        pcVar3 = (char *)&local_1c30;
        uVar12 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar12);
        FUN_00405560(pvVar13,pcVar3);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_1c30);
        uVar16 = uVar16 + 1;
      } while (uVar16 < local_189c);
    }
    local_c18 = 0;
    if (local_1898 != 0) {
      iVar5 = 0;
      do {
        local_1c28 = local_1c28 & 0xffffff04 | 0x104;
        local_1c24 = 0;
        local_1c20 = 0;
        local_1c1c = 0;
        local_1c30 = FUN_00404fd0((char *)(local_1890 + iVar5),0xffffffff);
        local_14._0_1_ = 0x37;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"exclude");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"net");
        pcVar3 = (char *)&local_1c30;
        uVar16 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar16);
        FUN_00405560(pvVar13,pcVar3);
        local_14._0_1_ = 0x10;
        FUN_004054d0(&local_1c30);
        local_c30 = (char *******)array_vpn_get_ipv6_prefix();
        local_c2c = (int)local_c30 >> 0x1f;
        local_c28 = local_c28 & 0xfffffe01 | 1;
        local_c24 = 0;
        local_c20 = 0;
        local_c1c = 0;
        local_14._0_1_ = 0x38;
        pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"exclude");
        pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
        piVar8 = (int *)FUN_004062c0(pvVar13,"mask");
        pppppppcVar9 = (char *******)&local_c30;
        uVar16 = FUN_00405e80(piVar8);
        pvVar13 = (void *)FUN_00405fd0(piVar8,uVar16);
        FUN_00405560(pvVar13,(char *)pppppppcVar9);
        local_14 = CONCAT31(local_14._1_3_,0x10);
        FUN_004054d0(&local_c30);
        iVar5 = iVar5 + 0x110;
        local_c18 = local_c18 + 1;
      } while (local_c18 < local_1898);
    }
    local_c24 = 0;
    local_c28 = local_c28 & 0xffffff04 | 0x104;
    local_c20 = 0;
    local_c1c = 0;
    local_c30 = (char *******)FUN_00404fd0("daemon",0xffffffff);
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x39;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"sender");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"receiver");
    pcVar3 = (char *)FUN_00406490(local_c14,0x422e50);
    FUN_00405560(pvVar13,pcVar3);
    pppppppcVar9 = (char *******)FUN_004072a0(&local_ab0,(undefined1 *)local_1bf8,(double *)&local_bf0);
    if (local_bcc != (char ********)pppppppcVar9) {
      if ((char ******)0xf < local_bb8) {
        operator_delete(local_bcc[0]);
      }
      local_bb8 = (char ******)0xf;
      local_bbc = (char ******)0x0;
      local_bcc[0] = (char *******)((uint)local_bcc[0] & 0xffffff00);
      if (pppppppcVar9[5] < (char ******)0x10) {
        if ((int)pppppppcVar9[4] + 1U != 0) {
          memmove(local_bcc,pppppppcVar9,(int)pppppppcVar9[4] + 1U);
        }
      }
      else {
        local_bcc[0] = (char *******)*pppppppcVar9;
        *pppppppcVar9 = (char ******)0x0;
      }
      local_bbc = pppppppcVar9[4];
      local_bb8 = pppppppcVar9[5];
      pppppppcVar9[5] = (char ******)0xf;
      pppppppcVar9[4] = (char ******)0x0;
      *(undefined1 *)pppppppcVar9 = 0;
    }
    if (0xf < local_1be4) {
      operator_delete(local_1bf8[0]);
    }
    local_1be4 = 0xf;
    local_1be8 = 0;
    local_1bf8[0] = (void *)((uint)local_1bf8[0] & 0xffffff00);
    if (param_2 == '\0') {
      pppppppcVar9 = (char *******)local_bcc;
      if ((char ******)0xf < local_bb8) {
        pppppppcVar9 = local_bcc[0];
      }
      FUN_00401bf0((void *)((int)local_1c34 + 0x34),(char *)pppppppcVar9,(int)local_bbc);
    }
    else {
      FUN_0040b790((void *)((int)local_1c34 + 4),local_bcc);
    }
    if (0xf < local_af4) {
      operator_delete(local_b08[0]);
    }
    local_af4 = 0xf;
    local_af8 = 0;
    local_b08[0] = (void *)((uint)local_b08[0] & 0xffffff00);
    if (0xf < local_b3c) {
      operator_delete(local_b50[0]);
    }
    local_b3c = 0xf;
    local_b40 = 0;
    local_b50[0] = (undefined4 *******)((uint)local_b50[0] & 0xffffff00);
    if (0xf < local_b6c) {
      operator_delete(local_b80[0]);
    }
    local_b6c = 0xf;
    local_b70 = 0;
    local_b80[0] = (void *)((uint)local_b80[0] & 0xffffff00);
    if (0xf < local_b0c) {
      operator_delete(local_b20[0]);
    }
    local_b0c = 0xf;
    local_b10 = 0;
    local_b20[0] = (char *******)((uint)local_b20[0] & 0xffffff00);
    if (0xf < local_b84) {
      operator_delete(local_b98[0]);
    }
    local_b84 = 0xf;
    local_b88 = 0;
    local_b98[0] = (char *******)((uint)local_b98[0] & 0xffffff00);
    if (0xf < local_b24) {
      operator_delete(local_b38[0]);
    }
    local_b24 = 0xf;
    local_b28 = 0;
    local_b38[0] = (void *)((uint)local_b38[0] & 0xffffff00);
    if (0xf < local_b54) {
      operator_delete(local_b68[0]);
    }
    local_b54 = 0xf;
    local_b58 = 0;
    local_b68[0] = (LPCSTR ******)((uint)local_b68[0] & 0xffffff00);
    if (0xf < local_b9c) {
      operator_delete(local_bb0[0]);
    }
    local_b9c = 0xf;
    local_ba0 = 0;
    local_bb0[0] = (void *)((uint)local_bb0[0] & 0xffffff00);
    local_14._0_1_ = 5;
    FUN_004054d0((undefined4 *)&local_af0);
    local_14 = CONCAT31(local_14._1_3_,3);
    FUN_004054d0(&local_c10);
    if ((char ******)0xf < local_bb8) {
      operator_delete(local_bcc[0]);
    }
    goto LAB_0041b766;
  case 0xe:
    array_vpn_get_l3vpn_config();
    array_vpn_get_stats();
    FUN_004051e0(&local_c30,0);
    local_14._0_1_ = 0x1b;
    pcVar3 = extraout_ECX_05;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"error");
    FUN_00405560(pvVar13,pcVar3);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"vpn data statistics");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x1c;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"message");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051e0(&local_c30,0xe);
    local_14._0_1_ = 0x1d;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"action");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051a0(&local_c30,local_1a58);
    local_14._0_1_ = 0x1e;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv4");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,local_1a48);
    local_14._0_1_ = 0x1f;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"ipv6");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405220(&local_c30,DAT_0042e3f0,DAT_0042e3f4);
    local_14._0_1_ = 0x20;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"send");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405220(&local_c30,DAT_0042e3e8,DAT_0042e3ec);
    local_14._0_1_ = 0x21;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"recv");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    iVar5 = array_vpn_get_status();
    FUN_004051e0(&local_c30,iVar5);
    local_14._0_1_ = 0x22;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"status");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"daemon");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x23;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"sender");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"receiver");
    pcVar3 = (char *)FUN_00406490(local_c14,0x422e50);
    FUN_00405560(pvVar13,pcVar3);
    puVar14 = (undefined4 *)FUN_004072a0(&local_ab0,(undefined1 *)local_1a70,(double *)&local_bf0);
    FUN_00408370(local_bcc,puVar14);
    puVar14 = local_1a70;
    goto LAB_00419770;
  case 0x10:
    pvVar13 = (void *)FUN_004062c0(&local_c10,"log");
    pvVar13 = (void *)FUN_004062c0(pvVar13,"path");
    puVar14 = (undefined4 *)FUN_00405660(pvVar13,(undefined1 *)local_1aa0);
    FUN_00408370(local_bb0,puVar14);
    FUN_00401da0(local_1aa0);
    bVar18 = FUN_0041c180((byte *)local_bb0);
    if (bVar18) {
      array_vpn_set_log_opt();
      array_vpn_logprint();
      FUN_004083b0(&DAT_00428030,(int *)local_bb0);
    }
    break;
  case 0x11:
    array_vpn_logprint();
    iVar5 = array_vpn_get_status();
    uVar7 = extraout_ECX_00;
    if (iVar5 != 0) {
      iVar5 = array_vpn_get_status();
      uVar7 = extraout_ECX_01;
      if (iVar5 != 7) {
        FUN_00415970(4,0,(char *)0x0);
        uVar7 = extraout_ECX_02;
      }
    }
    FUN_0040cfd0(uVar7,0);
    iVar5 = array_vpn_get_status();
    if ((iVar5 != 0) && (iVar5 = array_vpn_get_status(), iVar5 != 7)) {
      FUN_00415970(5,0,(char *)0x0);
    }
    break;
  case 0x12:
  case 0x1c:
    break;
  case 0x14:
    pvVar13 = (void *)FUN_004062c0(&local_c10,"site");
    pdVar4 = (double *)FUN_004062c0(pvVar13,"status");
    DVar10 = FUN_00405780(pdVar4);
    if (DVar10 != 0x1f) {
      local_bb4 = DVar10;
      SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","VPNstatus",4,&local_bb4,4);
    }
    array_vpn_logprint();
    switch(DVar10) {
    case 1:
      array_vpn_set_status();
      break;
    case 3:
      array_vpn_set_status();
      iVar5 = 3;
      goto LAB_0041af32;
    case 4:
      array_vpn_set_status();
      break;
    case 5:
      array_vpn_set_status();
      break;
    case 7:
      array_vpn_set_status();
      iVar5 = 7;
LAB_0041af32:
      FUN_00415970(iVar5,0,(char *)0x0);
      break;
    case 0x26:
      array_vpn_set_status();
      break;
    case 0x27:
      array_vpn_set_status();
    }
    FUN_00415970(DVar10,0x74,(char *)0x0);
    break;
  case 0x16:
    FUN_00415460();
    break;
  case 0x18:
    pdVar4 = (double *)FUN_004062c0(&local_c10,"msgflag");
    iVar5 = FUN_00405780(pdVar4);
    array_vpn_logprint();
    FUN_004051e0(&local_c30,0);
    local_14._0_1_ = 0x3a;
    pcVar3 = extraout_ECX_07;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"error");
    FUN_00405560(pvVar13,pcVar3);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_00405260(&local_c30,"get vpnd message");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x3b;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"message");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    FUN_004051e0(&local_c30,0x18);
    local_14._0_1_ = 0x3c;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
    pppppppcVar9 = (char *******)&local_c30;
    pvVar13 = (void *)FUN_004062c0(pvVar13,"action");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14._0_1_ = 0x10;
    FUN_004054d0(&local_c30);
    if ((iVar5 == 1) || (iVar5 == 0)) {
      iVar11 = array_vpn_get_value();
      if ((iVar5 == 0) && (iVar11 != 0)) {
        FUN_00405260(&local_c30,"failed");
        local_14._0_1_ = 0x3d;
      }
      else {
        FUN_00405260(&local_c30,&local_828);
        local_14._0_1_ = 0x3e;
      }
      pvVar13 = (void *)FUN_004062c0(&local_bf0,"data");
      pppppppcVar9 = (char *******)&local_c30;
      pvVar13 = (void *)FUN_004062c0(pvVar13,"mptoken");
      FUN_00405560(pvVar13,(char *)pppppppcVar9);
      local_14._0_1_ = 0x10;
      FUN_004054d0(&local_c30);
    }
    FUN_00405260(&local_c30,"daemon");
    pppppppcVar9 = (char *******)&local_c30;
    local_14._0_1_ = 0x3f;
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"sender");
    FUN_00405560(pvVar13,(char *)pppppppcVar9);
    local_14 = CONCAT31(local_14._1_3_,0x10);
    FUN_004054d0(&local_c30);
    pvVar13 = (void *)FUN_004062c0(&local_bf0,"receiver");
    pcVar3 = (char *)FUN_00406490(local_c14,0x422e50);
    FUN_00405560(pvVar13,pcVar3);
    puVar14 = (undefined4 *)FUN_004072a0(&local_ab0,(undefined1 *)local_1a88,(double *)&local_bf0);
    FUN_00408370(local_bcc,puVar14);
    puVar14 = local_1a88;
LAB_00419770:
    FUN_00401da0(puVar14);
    this = local_1c34;
    if (param_2 == '\0') {
LAB_00417d9a:
      FUN_00401bd0((void *)((int)this + 0x34),(char *)local_bcc);
    }
    else {
      FUN_0040b790((void *)((int)local_1c34 + 4),local_bcc);
    }
    break;
  case 0x19:
    pdVar4 = (double *)FUN_004062c0(&local_c10,"iNum");
    FUN_00405780(pdVar4);
    pdVar4 = (double *)FUN_004062c0(&local_c10,"iInterval");
    FUN_00405780(pdVar4);
    array_send_keep_alive();
    break;
  case 0x1a:
    array_vpn_get_stats();
    local_acc = DAT_0042e3f0;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","SendBytes",4,&local_acc,4);
    local_acc = DAT_0042e3e8;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","RecvBytes",4,&local_acc,4);
    array_vpn_get_pkg_num();
    local_bd0 = (undefined4)local_a38;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Sent_PkgNumBig",4,&local_bd0,4);
    local_bd0 = (undefined4)local_a40;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Sent_PkgNumMid",4,&local_bd0,4);
    local_bd0 = (undefined4)local_a58;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Sent_PkgNumSmall",4,&local_bd0,4);
    local_bd0 = (undefined4)local_a48;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Recv_PkgNumBig",4,&local_bd0,4);
    local_bd0 = (undefined4)local_a50;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Recv_PkgNumMid",4,&local_bd0,4);
    local_bd0 = (undefined4)local_a30;
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","Recv_PkgNumSmall",4,&local_bd0,4);
    break;
  case 0x1b:
    array_vpn_reconnect();
    break;
  case 0x1d:
    iVar5 = FUN_00413460();
    if (iVar5 != 2) {
      DAT_004296b4 = 1;
      array_vpn_logprint();
      FUN_004108f0(2,(BSTR)0x0,2);
      iVar5 = 0;
      do {
        bVar18 = FUN_0040bfd0();
        if (!bVar18) break;
        Sleep(0x32);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x14);
    }
    array_vpn_logprint();
    pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
    iVar5 = FUN_004062c0(pvVar13,"port");
    if (*(char *)(iVar5 + 8) == '\0') {
      array_vpn_logprint();
    }
    else {
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      pdVar4 = (double *)FUN_004062c0(pvVar13,"port");
      DAT_0042dd04 = FUN_00405780(pdVar4);
    }
    pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
    iVar5 = FUN_004062c0(pvVar13,"pub_key");
    if (*(char *)(iVar5 + 8) == '\0') {
      array_vpn_logprint();
    }
    else {
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      iVar5 = FUN_004062c0(pvVar13,"ip");
      if (*(char *)(iVar5 + 8) != '\x04') {
        FUN_00405620();
      }
      sprintf(&DAT_0042dd08,"%s");
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      iVar5 = FUN_004062c0(pvVar13,"pub_key");
      if (*(char *)(iVar5 + 8) != '\x04') {
        FUN_00405620();
      }
      sprintf(&DAT_0042dd88,"%s");
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      iVar5 = FUN_004062c0(pvVar13,"wg_desc");
      if (*(char *)(iVar5 + 8) != '\x04') {
        FUN_00405620();
      }
      sprintf(&DAT_0042de88,"%s");
      pvVar13 = (void *)FUN_004062c0(&local_c10,"wg");
      iVar5 = FUN_004062c0(pvVar13,"wg_name");
      if (*(char *)(iVar5 + 8) != '\x04') {
        FUN_00405620();
      }
      sprintf(&DAT_0042df88,"%s");
    }
    iVar5 = FUN_00413460();
    if (iVar5 != 2) {
      array_vpn_logprint();
      iVar5 = FUN_004108f0(0,(BSTR)0x0,0);
      if (iVar5 < 1) {
        array_vpn_logprint();
        FUN_00413a80();
        local_c18 = FUN_004108f0(1,(BSTR)0x0,0);
        if ((int)local_c18 < 1) {
          array_vpn_logprint();
        }
        else {
          array_vpn_logprint();
          DAT_0042e288 = 0;
          if (local_c18 == 2) {
            FUN_004108f0(2,(BSTR)0x0,2);
          }
          else {
            FUN_004108f0(2,(BSTR)0x0,0);
          }
        }
      }
      else {
        array_vpn_logprint();
      }
      DAT_004296b4 = 0;
      FUN_00401da0(local_b08);
      FUN_00401da0(local_b50);
      FUN_00401da0(local_b80);
      FUN_00401da0(local_b20);
      FUN_00401da0(local_b98);
      FUN_00401da0(local_b38);
      FUN_00401da0(local_b68);
      FUN_00401da0((undefined4 *)local_ac8);
      FUN_00401da0(local_bb0);
      local_14._0_1_ = 5;
      FUN_004054d0((undefined4 *)&local_af0);
      local_14._0_1_ = 3;
      FUN_004054d0(&local_c10);
      FUN_00401da0(local_bcc);
      local_14 = (uint)local_14._1_3_ << 8;
      FUN_004054d0((undefined4 *)&local_bf0);
      FUN_004013c0(&local_ab0);
      goto LAB_0041b7a9;
    }
    array_vpn_logprint();
    FUN_004108f0(4,(BSTR)0x0,0);
    break;
  case 0x1e:
    pvVar13 = (void *)FUN_004062c0(&local_c10,"changetunneldns");
    pvVar13 = (void *)FUN_004062c0(pvVar13,"dnslist");
    puVar14 = (undefined4 *)FUN_00405660(pvVar13,(undefined1 *)local_1b18);
    FUN_00408370(local_b68,puVar14);
    FUN_00401da0(local_1b18);
    array_vpn_logprint();
    array_vpn_get_l3vpn_config();
    bVar18 = (local_1868 & 0x20000000) == 0;
    if (bVar18) {
      array_vpn_logprint();
    }
    else {
      array_vpn_logprint();
    }
    uVar12 = FUN_00413540();
    uVar16 = (uint)bVar18;
    if (uVar12 != 0xffffffff) {
      uVar16 = uVar12;
    }
    pppppppCVar15 = (LPCSTR ******)local_b68;
    if (0xf < local_b54) {
      pppppppCVar15 = local_b68[0];
    }
    FUN_00413630((LPCSTR)pppppppCVar15,uVar16);
    break;
  case 0x1f:
    pvVar13 = (void *)FUN_004062c0(&local_c10,"newdns");
    puVar14 = (undefined4 *)FUN_00405660(pvVar13,(undefined1 *)local_1ab8);
    FUN_00408370(local_b80,puVar14);
    FUN_00401da0(local_1ab8);
    array_vpn_logprint();
    array_vpn_reconnect_with_dns();
  }
switchD_00417b09_caseD_10:
  FUN_00401da0(local_b08);
  FUN_00401da0(local_b50);
  FUN_00401da0(local_b80);
  FUN_00401da0(local_b20);
  FUN_00401da0(local_b98);
  FUN_00401da0(local_b38);
  FUN_00401da0(local_b68);
  FUN_00401da0((undefined4 *)local_ac8);
  FUN_00401da0(local_bb0);
  local_14._0_1_ = 5;
  FUN_004054d0((undefined4 *)&local_af0);
  local_14 = CONCAT31(local_14._1_3_,3);
  FUN_004054d0(&local_c10);
  FUN_00401da0(local_bcc);
LAB_0041b784:
  local_14 = local_14 & 0xffffff00;
  FUN_004054d0((undefined4 *)&local_bf0);
  FUN_004013c0(&local_ab0);
LAB_0041b7a9:
  ExceptionList = local_1c;
  FUN_0041c21c(local_24 ^ (uint)auStack_1c38);
  return;
}



// ===== FUN_0041b890 @ 0041b890 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0041b890(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  _DAT_0042e364 = &DAT_0042e300;
  if (DAT_0042e3a4 == 1) {
    _DAT_0042e398 = &DAT_0042e300;
    _Thrd_create(&DAT_0042e390,FUN_004015e0,&DAT_0042e36c);
  }
  uVar1 = _Thrd_create(&DAT_0042e35c,FUN_00401ac0,&DAT_0042e334);
  if (uVar1 == 0) {
    uVar2 = _Thrd_create(&DAT_0042e324,FUN_0040b4b0,&DAT_0042e304);
    return CONCAT31((int3)((uint)uVar2 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}



// ===== FUN_0041b900 @ 0041b900 =====

void FUN_0041b900(void)

{
  int iVar1;
  undefined1 local_10 [4];
  uint local_c;
  
  local_c = DAT_00428000 ^ (uint)local_10;
  _Thrd_join(DAT_0042e35c,DAT_0042e360,local_10);
  if (DAT_0042e32c != 0xffffffff) {
    closesocket(DAT_0042e32c);
    DAT_0042e32c = 0xffffffff;
  }
  iVar1 = thrd_is_null(DAT_0042e324,DAT_0042e328);
  if (iVar1 == 0) {
    _Thrd_join(DAT_0042e324,DAT_0042e328,local_10);
    thrd_set_null(&DAT_0042e324);
  }
  FUN_0041c21c(local_c ^ (uint)local_10);
  return;
}



// ===== FUN_0041b9a0 @ 0041b9a0 =====

void __fastcall FUN_0041b9a0(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  CHAR local_10c [2];
  char acStack_10a [258];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(acStack_10a + 0x106);
  local_10c[0] = '\0';
  memset(local_10c + 1,0,0x103);
  SHGetFolderPathA(0,0x1c,0,0,local_10c);
  pcVar1 = local_10c + -1;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (pcVar2[1] != '\0');
  builtin_strncpy(pcVar2 + 1,"\\MotionPro\\Log\\",0x10);
  SHPathPrepareForWriteA((HWND)0x0,(IUnknown *)0x0,local_10c,1);
  _snprintf(param_1,0x104,"%s",local_10c);
  FUN_0041c21c(local_8 ^ (uint)(acStack_10a + 0x106));
  return;
}



// ===== FUN_0041ba60 @ 0041ba60 =====

void FUN_0041ba60(void)

{
  HANDLE hFindFile;
  BOOL BVar1;
  int iVar2;
  undefined1 auStack_4dc [4];
  _SYSTEMTIME local_4d8;
  _SYSTEMTIME local_4c8;
  _WIN32_FIND_DATAA local_4b8;
  char local_378;
  undefined1 local_377 [263];
  char local_270;
  undefined1 local_26f [303];
  char local_140;
  undefined1 local_13f [307];
  uint local_c;
  
  local_c = DAT_00428000 ^ (uint)auStack_4dc;
  local_270 = '\0';
  memset(local_26f,0,299);
  local_378 = '\0';
  memset(local_377,0,0x103);
  FUN_0041b9a0(&local_378);
  local_140 = '\0';
  memset(local_13f,0,299);
  _snprintf(&local_140,300,"%s*.*",&local_378);
  hFindFile = FindFirstFileA(&local_140,&local_4b8);
  if (hFindFile != (HANDLE)0xffffffff) {
    GetLocalTime(&local_4c8);
    do {
      if (((byte)local_4b8.dwFileAttributes & 0x10) == 0) {
        FileTimeToSystemTime(&local_4b8.ftCreationTime,&local_4d8);
        iVar2 = (((uint)local_4c8.wYear - (uint)local_4d8.wYear) * 0xc - (uint)local_4d8.wMonth) +
                (uint)local_4c8.wMonth;
        if ((1 < iVar2) || ((iVar2 == 1 && (local_4d8.wDay < local_4c8.wDay)))) {
          memset(&local_270,0,300);
          _snprintf(&local_270,300,"%s%s",&local_378,local_4b8.cFileName);
          DeleteFileA(&local_270);
        }
      }
      BVar1 = FindNextFileA(hFindFile,&local_4b8);
    } while (BVar1 != 0);
    FindClose(hFindFile);
  }
  FUN_0041c21c(local_c ^ (uint)auStack_4dc);
  return;
}



// ===== FUN_0041bc00 @ 0041bc00 =====

void FUN_0041bc00(void)

{
  char cVar1;
  byte bVar2;
  byte **ppbVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  bool bVar9;
  _SYSTEMTIME local_144;
  byte local_134 [268];
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_28 + 0x24);
  local_134[0] = 0;
  memset(local_134 + 1,0,0x103);
  local_28[0] = '\0';
  local_28[0x19] = '\0';
  local_28[0x1a] = '\0';
  local_28[0x1b] = '\0';
  local_28[0x1c] = '\0';
  local_28[0x11] = '\0';
  local_28[0x12] = '\0';
  local_28[0x13] = '\0';
  local_28[0x14] = '\0';
  local_28[0x15] = '\0';
  local_28[0x16] = '\0';
  local_28[0x17] = '\0';
  local_28[0x18] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_28[0x10] = '\0';
  local_28[0x1d] = '\0';
  local_28[0x1e] = '\0';
  local_28[0x1f] = 0;
  FUN_0041b9a0((char *)local_134);
  GetLocalTime(&local_144);
  sprintf(local_28,"MotionPro_%02d_%02d_%02d.log",(uint)local_144.wYear,(uint)local_144.wMonth,(uint)local_144.wDay);
  pcVar6 = local_28;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar7 = (int)pcVar6 - (int)local_28;
  pcVar6 = (char *)((int)&local_144.wMilliseconds + 1);
  do {
    pcVar8 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar8 != '\0');
  ppbVar3 = &DAT_00428030;
  pcVar8 = local_28;
  for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar6 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar6 = pcVar6 + 1;
  }
  if (0xf < DAT_00428044) {
    ppbVar3 = (byte **)DAT_00428030;
  }
  pbVar5 = local_134;
  do {
    bVar2 = *pbVar5;
    bVar9 = bVar2 < *(byte *)ppbVar3;
    if (bVar2 != *(byte *)ppbVar3) {
LAB_0041bd00:
      uVar7 = -(uint)bVar9 | 1;
      goto LAB_0041bd05;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar5[1];
    bVar9 = bVar2 < *(byte *)((int)ppbVar3 + 1);
    if (bVar2 != *(byte *)((int)ppbVar3 + 1)) goto LAB_0041bd00;
    pbVar5 = pbVar5 + 2;
    ppbVar3 = (byte **)((int)ppbVar3 + 2);
  } while (bVar2 != 0);
  uVar7 = 0;
LAB_0041bd05:
  if (uVar7 != 0) {
    array_vpn_set_log_opt(0x24,local_134);
    if (local_134[0] == 0) {
      uVar7 = 0;
    }
    else {
      pbVar5 = local_134;
      do {
        bVar2 = *pbVar5;
        pbVar5 = pbVar5 + 1;
      } while (bVar2 != 0);
      uVar7 = (int)pbVar5 - (int)(local_134 + 1);
    }
    FUN_00401f80(&DAT_00428030,(int *)local_134,uVar7);
  }
  FUN_0041c21c(local_8 ^ (uint)(local_28 + 0x24));
  return;
}



// ===== FUN_0041bd60 @ 0041bd60 =====

void FUN_0041bd60(void)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD local_18 [4];
  DWORD local_8;
  
  local_8 = DAT_00428000 ^ (uint)(local_18 + 5);
  winsock_init();
  local_18[2] = 0;
  SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","VPNstatus",4,local_18 + 2,4);
  CoInitializeEx((LPVOID)0x0,0);
  DAT_0042e294 = 0;
  DAT_0042e28c = 0;
  local_18[0] = 4;
  local_18[3] = 0;
  local_18[1] = 4;
  LVar1 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","debug",local_18,local_18 + 3,local_18 + 1);
  if ((LVar1 == 0) && (local_18[3] == 1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  array_vpn_set_log_level(uVar3,0);
  FUN_0041bc00();
  array_vpn_logprint(1,"vpnd.cpp",0x99a,"This is vpnd, %s\n","Jan 26 2024");
  FUN_0041ba60();
  iVar2 = FUN_00401840((SOCKET *)&DAT_0042e334);
  if (iVar2 == 0) {
    FUN_0041b890();
    array_vpn_logprint(1,"vpnd.cpp",0x9b0,"vpnd: Before vpn service wait.\n");
    FUN_0041b900();
    array_vpn_logprint(1,"vpnd.cpp",0x9b2,"vpnd: After vpn service wait.\n");
    Sleep(200);
    array_vpn_logprint(1,"vpnd.cpp",0x9b7,"vpnd: After Sleep , process will exist.\n");
  }
  FUN_0041c21c(local_8 ^ (uint)(local_18 + 5));
  return;
}



// ===== FUN_0041beb0 @ 0041beb0 =====

void __thiscall FUN_0041beb0(void *this,undefined2 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar1 = *(undefined2 **)((int)this + 4);
  if ((param_1 < puVar1) && (puVar2 = *(undefined2 **)this, puVar2 <= param_1)) {
    if (puVar1 == *(undefined2 **)((int)this + 8)) {
      FUN_0041c060(this);
    }
    if (*(undefined2 **)((int)this + 4) != (undefined2 *)0x0) {
      **(undefined2 **)((int)this + 4) = *(undefined2 *)(*(int *)this + ((int)param_1 - (int)puVar2 >> 1) * 2);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 2;
      return;
    }
  }
  else {
    if (puVar1 == *(undefined2 **)((int)this + 8)) {
      FUN_0041c060(this);
    }
    if (*(undefined2 **)((int)this + 4) != (undefined2 *)0x0) {
      **(undefined2 **)((int)this + 4) = *param_1;
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 2;
  return;
}



// ===== FUN_0041bf20 @ 0041bf20 =====

void __thiscall FUN_0041bf20(void *this,undefined4 *param_1,void *param_2)

{
  memmove(param_2,(void *)((int)param_2 + 2),*(int *)((int)this + 4) - ((int)param_2 + 2) & 0xfffffffe);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -2;
  *param_1 = param_2;
  return;
}



// ===== FUN_0041bf60 @ 0041bf60 =====

int __thiscall FUN_0041bf60(void *this,undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  char *_MaxCount;
  char *pcVar5;
  char *local_8;
  
  if (param_3 == 0) {
    return 0;
  }
  uVar1 = *(uint *)((int)this + 0x10);
  if ((uVar1 != 0) && (param_3 <= uVar1)) {
    _MaxCount = (char *)(uVar1 + (1 - param_3));
    if (*(uint *)((int)this + 0x14) < 0x10) {
      local_8 = this;
    }
    else {
      local_8 = *(char **)this;
    }
    while ((_MaxCount != (char *)0x0 && (piVar3 = memchr(local_8,0x55,(size_t)_MaxCount), piVar3 != (int *)0x0))) {
      pcVar5 = "UnresolvedFlag=";
      piVar4 = piVar3;
      uVar1 = param_3;
      while (uVar2 = uVar1 - 4, 3 < uVar1) {
        if (*piVar4 != *(int *)pcVar5) goto LAB_0041bff6;
        piVar4 = piVar4 + 1;
        pcVar5 = (char *)((int)pcVar5 + 4);
        uVar1 = uVar2;
      }
      if (uVar2 == 0xfffffffc) {
LAB_0041c036:
        if (0xf < *(uint *)((int)this + 0x14)) {
          this = *(void **)this;
        }
        return (int)piVar3 - (int)this;
      }
LAB_0041bff6:
      if (((char)*piVar4 == (char)*(int *)pcVar5) &&
         ((uVar2 == 0xfffffffd ||
          ((*(char *)((int)piVar4 + 1) == *(char *)((int)pcVar5 + 1) &&
           ((uVar2 == 0xfffffffe ||
            ((*(char *)((int)piVar4 + 2) == *(char *)((int)pcVar5 + 2) &&
             ((uVar2 == 0xffffffff || (*(char *)((int)piVar4 + 3) == *(char *)((int)pcVar5 + 3)))))))))))))
      goto LAB_0041c036;
      _MaxCount = local_8 + (int)(_MaxCount + (-1 - (int)piVar3));
      local_8 = (char *)((int)piVar3 + 1);
    }
  }
  return -1;
}



// ===== FUN_0041c060 @ 0041c060 =====

void __fastcall FUN_0041c060(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[2] - param_1[1] >> 1 == 0) {
    iVar2 = param_1[1] - *param_1 >> 1;
    if (iVar2 == 0x7fffffff) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("vector<T> too long");
    }
    uVar3 = iVar2 + 1;
    uVar1 = param_1[2] - *param_1 >> 1;
    if (0x7fffffff - (uVar1 >> 1) < uVar1) {
      uVar1 = 0;
      if (uVar3 != 0) {
        uVar1 = uVar3;
      }
      FUN_0041c0d0(param_1,uVar1);
      return;
    }
    uVar1 = uVar1 + (uVar1 >> 1);
    if (uVar1 < uVar3) {
      uVar1 = uVar3;
    }
    FUN_0041c0d0(param_1,uVar1);
  }
  return;
}



// ===== FUN_0041c0d0 @ 0041c0d0 =====

void __thiscall FUN_0041c0d0(void *this,uint param_1)

{
  void *pvVar1;
  int iVar2;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (param_1 == 0) {
LAB_0041c103:
    memmove(_Dst,*(void **)this,*(int *)((int)this + 4) - (int)*(void **)this & 0xfffffffe);
    pvVar1 = *(void **)this;
    iVar2 = *(int *)((int)this + 4);
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
    *(void **)this = _Dst;
    *(void **)((int)this + 8) = (void *)((int)_Dst + param_1 * 2);
    *(void **)((int)this + 4) = (void *)((int)_Dst + (iVar2 - (int)pvVar1 >> 1) * 2);
    return;
  }
  if (param_1 < 0x80000000) {
    _Dst = operator_new(param_1 * 2);
    if (_Dst != (void *)0x0) goto LAB_0041c103;
  }
                    /* WARNING: Subroutine does not return */
  std::_Xbad_alloc();
}



// ===== FUN_0041c150 @ 0041c150 =====

void __fastcall FUN_0041c150(undefined4 *param_1,short *param_2,short *param_3,short *param_4)

{
  if (param_3 != param_4) {
    do {
      if (*param_3 == *param_2) break;
      param_3 = param_3 + 1;
    } while (param_3 != param_4);
  }
  *param_1 = param_3;
  return;
}



// ===== FUN_0041c180 @ 0041c180 =====

bool __fastcall FUN_0041c180(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar2 = DAT_00428040;
  pbVar4 = (byte *)&DAT_00428030;
  if (0xf < DAT_00428044) {
    pbVar4 = DAT_00428030;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(byte **)param_1;
  }
  uVar3 = DAT_00428040;
  if (uVar1 < DAT_00428040) {
    uVar3 = uVar1;
  }
  uVar3 = FUN_00402430(param_1,pbVar4,uVar3);
  if (uVar3 == 0) {
    if (uVar1 < uVar2) {
      return true;
    }
    uVar3 = (uint)(uVar1 != uVar2);
  }
  return uVar3 != 0;
}



// ===== FUN_0041c1dc @ 0041c1dc =====

void __cdecl FUN_0041c1dc(uint param_1)

{
  operator_new(param_1);
  return;
}



// ===== FUN_0041c21c @ 0041c21c =====

void __fastcall FUN_0041c21c(int param_1)

{
  if (param_1 != DAT_00428000) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}



// ===== FUN_0041c267 @ 0041c267 =====

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

_onexit_t __cdecl FUN_0041c267(_onexit_t param_1)

{
  _onexit_t p_Var1;
  PVOID pvVar2;
  PVOID *ppvVar3;
  PVOID *ppvVar4;
  PVOID local_24;
  PVOID local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_004265a0;
  uStack_c = 0x41c273;
  local_20[0] = DecodePointer(DAT_0042e418);
  if (local_20[0] == (PVOID)0xffffffff) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = DecodePointer(DAT_0042e418);
    local_24 = DecodePointer(DAT_0042e414);
    ppvVar4 = &local_24;
    ppvVar3 = local_20;
    pvVar2 = EncodePointer(param_1);
    p_Var1 = (_onexit_t)__dllonexit(pvVar2,ppvVar3,ppvVar4);
    DAT_0042e418 = EncodePointer(local_20[0]);
    DAT_0042e414 = EncodePointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_0041c307();
  }
  return p_Var1;
}



// ===== FUN_0041c307 @ 0041c307 =====

void FUN_0041c307(void)

{
  _unlock(8);
  return;
}



// ===== FUN_0041c310 @ 0041c310 =====

int __cdecl FUN_0041c310(_onexit_t param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = FUN_0041c267(param_1);
  return (p_Var1 != (_onexit_t)0x0) - 1;
}



// ===== ___raise_securityfailure @ 0041c332 =====

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_0042871c = IsDebuggerPresent();
  _crt_debugger_hook(1);
  __crtUnhandledException(param_1);
  if (DAT_0042871c == 0) {
    _crt_debugger_hook(1);
  }
  __crtTerminateProcess(0xc0000409);
  return;
}



// ===== ___report_gsfailure @ 0041c36f =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Library: Visual Studio 2015 Release */

void __cdecl ___report_gsfailure(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;
  undefined1 uStack00000004;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_004284f8 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_00428500 = (undefined4)lVar9;
  _DAT_00428510 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 | (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 |
       (uint)(bVar4 & 1) | (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_00428514 = &uStack00000004;
  _DAT_00428450 = 0x10001;
  _DAT_00428400 = 0xc0000409;
  _DAT_00428404 = 1;
  _DAT_00428410 = 1;
  DAT_00428414 = 2;
  _DAT_0042840c = unaff_retaddr;
  _DAT_004284dc = in_GS;
  _DAT_004284e0 = in_FS;
  _DAT_004284e4 = in_ES;
  _DAT_004284e8 = in_DS;
  _DAT_004284ec = unaff_EDI;
  _DAT_004284f0 = unaff_ESI;
  _DAT_004284f4 = unaff_EBX;
  _DAT_004284fc = uVar3;
  _DAT_00428504 = unaff_EBP;
  DAT_00428508 = unaff_retaddr;
  _DAT_0042850c = in_CS;
  _DAT_00428518 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_0041f428);
  return;
}



// ===== ___report_rangecheckfailure @ 0041c46a =====

/* Library Function - Single Match
    ___report_rangecheckfailure
   
   Library: Visual Studio 2015 Release */

void ___report_rangecheckfailure(void)

{
  ___report_securityfailure(8);
  return;
}



// ===== ___report_securityfailure @ 0041c476 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_securityfailure
   
   Library: Visual Studio 2015 Release */

void __cdecl ___report_securityfailure(undefined4 param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  uint extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  longlong lVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  lVar9 = (ulonglong)extraout_EDX << 0x20;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    lVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_004284f8 = (undefined4)((ulonglong)lVar9 >> 0x20);
  _DAT_00428500 = (undefined4)lVar9;
  _DAT_00428510 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
       (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 | (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 |
       (uint)(bVar4 & 1) | (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_00428514 = &param_1;
  _DAT_00428400 = 0xc0000409;
  _DAT_00428404 = 1;
  _DAT_00428410 = 1;
  DAT_00428414 = param_1;
  _DAT_0042840c = unaff_retaddr;
  _DAT_004284dc = in_GS;
  _DAT_004284e0 = in_FS;
  _DAT_004284e4 = in_ES;
  _DAT_004284e8 = in_DS;
  _DAT_004284ec = unaff_EDI;
  _DAT_004284f0 = unaff_ESI;
  _DAT_004284f4 = unaff_EBX;
  _DAT_004284fc = uVar3;
  _DAT_00428504 = unaff_EBP;
  DAT_00428508 = unaff_retaddr;
  _DAT_0042850c = in_CS;
  _DAT_00428518 = in_SS;
  ___raise_securityfailure((EXCEPTION_POINTERS *)&PTR_DAT_0041f428);
  return;
}



// ===== FID_conflict:`vector_deleting_destructor' @ 0041c546 =====

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall CDaoRelationFieldInfo::`vector deleting destructor'(unsigned int)
    public: virtual void * __thiscall type_info::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

void * __thiscall FID_conflict__vector_deleting_destructor_(void *this,uint param_1)

{
  int *piVar1;
  
  if ((param_1 & 2) == 0) {
    type_info::~type_info(this);
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    piVar1 = (int *)((int)this + -4);
    _eh_vector_destructor_iterator_(this,0xc,*piVar1,type_info::~type_info);
    if ((param_1 & 1) != 0) {
      operator_delete(piVar1);
    }
    this = piVar1;
  }
  return this;
}



// ===== `eh_vector_destructor_iterator' @ 0041c5a8 =====

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall `eh vector destructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void _eh_vector_destructor_iterator_(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffd0;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffd0);
  }
  FUN_0041c607();
  return;
}



// ===== FUN_0041c607 @ 0041c607 =====

void FUN_0041c607(void)

{
  int in_EAX;
  uint unaff_EBX;
  int unaff_EBP;
  void *unaff_ESI;
  int unaff_EDI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(unaff_ESI,unaff_EBX,unaff_EDI,*(_func_void_void_ptr **)(unaff_EBP + 0x14));
  }
  return;
}



// ===== __ArrayUnwind @ 0041c617 =====

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 2012 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *in_stack_ffffffc8;
  
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(in_stack_ffffffc8);
  }
  return;
}



// ===== FUN_0041c675 @ 0041c675 =====

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_0041c675(undefined4 param_1,undefined4 param_2,int param_3,undefined *param_4)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    (*(code *)param_4)();
  }
  FUN_0041c6c3();
  return;
}



// ===== FUN_0041c6c3 @ 0041c6c3 =====

void FUN_0041c6c3(void)

{
  int in_EAX;
  int unaff_EBP;
  int unaff_ESI;
  
  if (in_EAX == 0) {
    __ArrayUnwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),unaff_ESI,
                  *(_func_void_void_ptr **)(unaff_EBP + 0x18));
  }
  return;
}



// ===== ___tmainCRTStartup @ 0041c7db =====

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tmainCRTStartup
   
   Library: Visual Studio 2012 Release */

int ___tmainCRTStartup(void)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  BOOL BVar4;
  
  bVar1 = false;
  do {
    pvVar2 = (void *)0x0;
    LOCK();
    if (DAT_0042e408 == (void *)0x0) {
      DAT_0042e408 = StackBase;
    }
    else {
      pvVar2 = DAT_0042e408;
    }
    UNLOCK();
    if (pvVar2 == (void *)0x0) goto LAB_0041c816;
  } while (pvVar2 != StackBase);
  bVar1 = true;
LAB_0041c816:
  if (DAT_0042e40c == 1) {
    _amsg_exit(0x1f);
  }
  else if (DAT_0042e40c == 0) {
    DAT_0042e40c = 1;
    iVar3 = initterm_e(&DAT_0041f3d0,&DAT_0041f3e0);
    if (iVar3 != 0) {
      return 0xff;
    }
  }
  else {
    DAT_00428720 = 1;
  }
  if (DAT_0042e40c == 1) {
    initterm(&DAT_0041f39c,&DAT_0041f3cc);
    DAT_0042e40c = 2;
  }
  if (!bVar1) {
    LOCK();
    DAT_0042e408 = (void *)0x0;
    UNLOCK();
  }
  if ((DAT_0042e410 != (code *)0x0) && (BVar4 = __IsNonwritableInCurrentImage((PBYTE)&DAT_0042e410), BVar4 != 0)) {
    (*DAT_0042e410)(0,2,0);
  }
  *(undefined4 *)__initenv_exref = DAT_00428734;
  DAT_00428724 = FUN_0041bd60();
  if (DAT_00428728 == 0) {
                    /* WARNING: Subroutine does not return */
    exit(DAT_00428724);
  }
  if (DAT_00428720 == 0) {
    _cexit();
  }
  return DAT_00428724;
}



// ===== entry @ 0041c940 =====

void entry(void)

{
  ___security_init_cookie();
  ___tmainCRTStartup();
  return;
}



// ===== __SEH_prolog4 @ 0041c960 =====

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: param_2 */
/* Library Function - Single Match
    __SEH_prolog4
   
   Library: Visual Studio */

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  iVar1 = -param_2;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + iVar1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + iVar1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + iVar1 + 4) = DAT_00428000 ^ (uint)&param_2;
  *(undefined4 *)((int)auStack_1c + iVar1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}



// ===== __SEH_epilog4 @ 0041c9a5 =====

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __SEH_epilog4
   
   Library: Visual Studio */

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 unaff_retaddr;
  
  ExceptionList = (void *)unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}



// ===== FUN_0041c9b9 @ 0041c9b9 =====

void __cdecl FUN_0041c9b9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  except_handler4_common(&DAT_00428000,FUN_0041c21c,param_1,param_2,param_3,param_4);
  return;
}



// ===== FUN_0041c9fa @ 0041c9fa =====

undefined4 FUN_0041c9fa(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) &&
     ((iVar2 = piVar1[5], iVar2 == 0x19930520 ||
      (((iVar2 == 0x19930521 || (iVar2 == 0x19930522)) || (iVar2 == 0x1994000)))))) {
                    /* WARNING: Subroutine does not return */
    terminate();
  }
  return 0;
}



// ===== __FindPESection @ 0041ca60 =====

/* Library Function - Single Match
    __FindPESection
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  int iVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  uint uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(pImageBase + 0x3c);
  p_Var2 = (PIMAGE_SECTION_HEADER)(pImageBase + *(ushort *)(pImageBase + iVar1 + 0x14) + 0x18 + iVar1);
  if (*(ushort *)(pImageBase + iVar1 + 6) != 0) {
    do {
      if ((p_Var2->VirtualAddress <= rva) && (rva < (p_Var2->Misc).PhysicalAddress + p_Var2->VirtualAddress)) {
        return p_Var2;
      }
      uVar3 = uVar3 + 1;
      p_Var2 = p_Var2 + 1;
    } while (uVar3 < *(ushort *)(pImageBase + iVar1 + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



// ===== __IsNonwritableInCurrentImage @ 0041cab0 =====

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2012 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = FUN_0041c9b9;
  local_14 = ExceptionList;
  local_c = DAT_00428000 ^ 0x426640;
  ExceptionList = &local_14;
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_00400000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_00400000,(DWORD_PTR)(pTarget + -0x400000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}



// ===== __ValidateImageBase @ 0041cb70 =====

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  uint uVar1;
  
  if (*(short *)pImageBase != 0x5a4d) {
    return 0;
  }
  uVar1 = 0;
  if (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550) {
    uVar1 = (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b);
  }
  return uVar1;
}



// ===== ___security_init_cookie @ 0041cba1 =====

/* Library Function - Single Match
    ___security_init_cookie
   
   Library: Visual Studio 2015 Release */

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  LARGE_INTEGER local_18;
  _FILETIME local_10;
  uint local_8;
  
  local_10.dwLowDateTime = 0;
  local_10.dwHighDateTime = 0;
  if ((DAT_00428000 == 0xbb40e64e) || ((DAT_00428000 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime(&local_10);
    local_8 = local_10.dwHighDateTime ^ local_10.dwLowDateTime;
    DVar1 = GetCurrentThreadId();
    local_8 = local_8 ^ DVar1;
    DVar1 = GetCurrentProcessId();
    local_8 = local_8 ^ DVar1;
    QueryPerformanceCounter(&local_18);
    DAT_00428000 = local_18.s.HighPart ^ local_18.s.LowPart ^ local_8 ^ (uint)&local_8;
    if (DAT_00428000 == 0xbb40e64e) {
      DAT_00428000 = 0xbb40e64f;
    }
    else if ((DAT_00428000 & 0xffff0000) == 0) {
      DAT_00428000 = DAT_00428000 | (DAT_00428000 | 0x4711) << 0x10;
    }
  }
  DAT_00428004 = ~DAT_00428000;
  return;
}



// ===== FUN_0041cc3d @ 0041cc3d =====

undefined4 FUN_0041cc3d(void)

{
  return 0;
}



// ===== FUN_0041cc40 @ 0041cc40 =====

void FUN_0041cc40(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = &DAT_00424d70; puVar1 < &DAT_00424d70; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  return;
}



// ===== FUN_0041cc80 @ 0041cc80 =====

void FUN_0041cc80(void)

{
  errno_t eVar1;
  
  eVar1 = _controlfp_s((uint *)0x0,0x10000,0x30000);
  if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  return;
}



// ===== FUN_0041cccc @ 0041cccc =====

_ATL_BASE_MODULE70 * __fastcall FUN_0041cccc(_ATL_BASE_MODULE70 *param_1)

{
  uint uVar1;
  BOOL BVar2;
  
  ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(param_1);
  *(undefined4 *)param_1 = 0x38;
  *(undefined4 *)(param_1 + 8) = 0x400000;
  *(undefined4 *)(param_1 + 4) = 0x400000;
  *(undefined4 *)(param_1 + 0xc) = 0xc00;
  *(undefined **)(param_1 + 0x10) = &DAT_0041f438;
  uVar1 = FUN_0040b9e0((LPCRITICAL_SECTION)(param_1 + 0x14));
  if ((int)uVar1 < 0) {
    BVar2 = IsDebuggerPresent();
    if (BVar2 != 0) {
      OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
    }
    DAT_0042e3e6 = 1;
  }
  return param_1;
}



// ===== ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70 @ 0041cd1f =====

/* Library Function - Single Match
    public: __thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(void)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

_ATL_BASE_MODULE70 * __thiscall ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(_ATL_BASE_MODULE70 *this)

{
  memset(this + 0x14,0,0x18);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  return this;
}



// ===== ATL::CAtlBaseModule::~CAtlBaseModule @ 0041cd42 =====

/* Library Function - Single Match
    public: __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019
   Release */

void __thiscall ATL::CAtlBaseModule::~CAtlBaseModule(CAtlBaseModule *this)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(this + 0x14));
  CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_>::RemoveAll
            ((CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_> *)(this + 0x2c));
  return;
}



// ===== ATL::CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_>::RemoveAll @ 0041cd58 =====

/* Library Function - Single Match
    public: void __thiscall ATL::CSimpleArray<struct HINSTANCE__ *,class ATL::CSimpleArrayEqualHelper<struct HINSTANCE__
   *> >::RemoveAll(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019
   Release */

void __thiscall
ATL::CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_>::RemoveAll
          (CSimpleArray<HINSTANCE__*,ATL::CSimpleArrayEqualHelper<HINSTANCE__*>_> *this)

{
  if (*(int *)this != 0) {
    free(*(void **)this);
    *(undefined4 *)this = 0;
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}



// ===== __alloca_probe_16 @ 0041cd90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// ===== __alloca_probe_8 @ 0041cda6 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_8
   
   Library: Visual Studio */

uint __alloca_probe_8(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 7;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}



// ===== __aulldiv @ 0041cdc0 =====

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_4 == 0) {
    uVar4 = param_2 / param_3;
    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) / (ulonglong)param_3);
  }
  else {
    uVar8 = param_1;
    uVar6 = param_4;
    uVar7 = param_2;
    uVar4 = param_3;
    do {
      uVar3 = uVar6 & 1;
      uVar6 = uVar6 >> 1;
      uVar4 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
      uVar3 = uVar7 & 1;
      uVar7 = uVar7 >> 1;
      uVar8 = (uint)(CONCAT14(uVar3 != 0,uVar8) >> 1);
    } while (uVar6 != 0);
    uVar1 = CONCAT44(uVar7,uVar8) / (ulonglong)uVar4;
    iVar5 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar4 + iVar5 * param_4;
    if (((CARRY4(uVar4,iVar5 * param_4)) || (param_2 < uVar8)) || ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar5 = iVar5 + -1;
    }
    uVar4 = 0;
  }
  return CONCAT44(uVar4,iVar5);
}



// ===== __alloca_probe @ 0041ce30 =====

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Library: Visual Studio */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_res0;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)((int)&local_res0 - (int)in_EAX & ~-(uint)(&local_res0 < in_EAX));
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1; puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = _local_res0;
  return;
}



// ===== FUN_0041cffd @ 0041cffd =====

void __fastcall FUN_0041cffd(undefined4 param_1,int param_2)

{
  byte in_FPUControlWord;
  
  if ((param_2 == 8) || (((&DAT_0042453f)[param_2] & in_FPUControlWord) == 0)) {
    except1(param_2,0);
  }
  return;
}



// ===== FUN_0041d03f @ 0041d03f =====

/* WARNING: Removing unreachable block (ram,0x0041d090) */
/* WARNING: Removing unreachable block (ram,0x0041d0ac) */
/* WARNING: Removing unreachable block (ram,0x0041d0b1) */
/* WARNING: Removing unreachable block (ram,0x0041cea8) */
/* WARNING: Removing unreachable block (ram,0x0041ceb6) */
/* WARNING: Removing unreachable block (ram,0x0041d0c7) */
/* WARNING: Removing unreachable block (ram,0x0041d0db) */
/* WARNING: Removing unreachable block (ram,0x0041d110) */
/* WARNING: Removing unreachable block (ram,0x0041d119) */
/* WARNING: Removing unreachable block (ram,0x0041d127) */
/* WARNING: Removing unreachable block (ram,0x0041d12b) */
/* WARNING: Removing unreachable block (ram,0x0041d141) */
/* WARNING: Removing unreachable block (ram,0x0041d14b) */
/* WARNING: Removing unreachable block (ram,0x0041d155) */
/* WARNING: Removing unreachable block (ram,0x0041d167) */
/* WARNING: Removing unreachable block (ram,0x0041d0e9) */
/* WARNING: Removing unreachable block (ram,0x0041d0f7) */
/* WARNING: Removing unreachable block (ram,0x0041ceef) */
/* WARNING: Removing unreachable block (ram,0x0041cefd) */
/* WARNING: Removing unreachable block (ram,0x0041cf07) */
/* WARNING: Removing unreachable block (ram,0x0041cf17) */

ulonglong FUN_0041d03f(void)

{
  double in_XMM0_Qa;
  ulonglong in_XMM0_Qb;
  int iVar1;
  ulonglong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auVar7 [16];
  
  if (((((uint)((ulonglong)in_XMM0_Qa >> 0x20) & 0x7fffffff) < 0x7ff00000) && (in_XMM0_Qa < 9.223372036854776e+18)) &&
     (-9.223372036854776e+18 <= in_XMM0_Qa)) {
    auVar3._0_8_ = ABS(in_XMM0_Qa);
    auVar3._8_8_ = in_XMM0_Qb & 0x7fffffffffffffff;
    uVar2 = 0;
    if (auVar3._0_8_ != 0.0) {
      auVar4 = auVar3 & ZEXT816(0xfffffffffffff) | ZEXT816(0x10000000000000);
      lVar5 = SUB168(ZEXT416(0x433),0) - ((ulonglong)auVar3._0_8_ >> 0x34);
      uVar6 = auVar4._0_8_ >> lVar5;
      iVar1 = -(uint)(0x433 < (uint)((ulonglong)auVar3._0_8_ >> 0x34));
      uVar2 = CONCAT44(iVar1,iVar1);
      uVar2 = ~uVar2 & uVar6 | auVar4._0_8_ << ((ulonglong)auVar3._0_8_ >> 0x34) - SUB168(ZEXT416(0x433),0) & uVar2;
      uVar2 = ~-(ulonglong)(in_XMM0_Qa == auVar3._0_8_) & -uVar2 | uVar2 & -(ulonglong)(in_XMM0_Qa == auVar3._0_8_);
      if ((0 < (int)lVar5) &&
         (auVar7._0_8_ = uVar6 << lVar5, auVar7._8_8_ = (auVar4._8_8_ >> lVar5) << lVar5,
         SUB164(auVar4 ^ auVar7,0) != 0 || SUB164(auVar4 ^ auVar7,4) != 0)) {
        FUN_0041cffd(1,0x10);
      }
    }
    return uVar2;
  }
  FUN_0041cffd(1,8);
  return 0x8000000000000000;
}



// ===== FUN_0041d04e @ 0041d04e =====

/* WARNING: Removing unreachable block (ram,0x0041cea3) */
/* WARNING: Removing unreachable block (ram,0x0041d0b1) */
/* WARNING: Removing unreachable block (ram,0x0041cea8) */
/* WARNING: Removing unreachable block (ram,0x0041ceb6) */
/* WARNING: Removing unreachable block (ram,0x0041cec0) */
/* WARNING: Removing unreachable block (ram,0x0041ceca) */
/* WARNING: Removing unreachable block (ram,0x0041cedc) */
/* WARNING: Removing unreachable block (ram,0x0041ceef) */
/* WARNING: Removing unreachable block (ram,0x0041cefd) */
/* WARNING: Removing unreachable block (ram,0x0041cf07) */
/* WARNING: Removing unreachable block (ram,0x0041cf17) */

ulonglong FUN_0041d04e(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  double in_XMM0_Qa;
  ulonglong in_XMM0_Qb;
  int iVar2;
  double dVar3;
  ulonglong uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  double dVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 auVar10 [16];
  
  iVar1 = 4;
  dVar3 = 1.8446744073709552e+19;
  if (0x7fefffff < ((uint)((ulonglong)in_XMM0_Qa >> 0x20) & 0x7fffffff)) {
LAB_0041cfeb:
    FUN_0041cffd(iVar1,8);
    return 0x8000000000000000;
  }
  auVar5._0_8_ = ABS(in_XMM0_Qa);
  auVar5._8_8_ = in_XMM0_Qb & 0x7fffffffffffffff;
  if (3.4028235677973366e+38 < auVar5._0_8_) {
    FUN_0041cffd(4,0x10);
    FUN_0041cffd(extraout_ECX,1);
    iVar1 = extraout_ECX_00;
  }
  if (1.1754943157898259e-38 <= auVar5._0_8_) {
    dVar7 = in_XMM0_Qa;
    if ((iVar1 == 4) && (9.223372036854776e+18 <= in_XMM0_Qa)) {
      dVar7 = in_XMM0_Qa - 9.223372036854776e+18;
    }
    if ((int)((ulonglong)((longlong)dVar7 << 0x23) >> 0x20) != 0) {
      FUN_0041cffd(iVar1,0x10);
      iVar1 = extraout_ECX_03;
    }
    if ((dVar3 <= in_XMM0_Qa) || (in_XMM0_Qa < -9.223372036854776e+18)) goto LAB_0041cfeb;
  }
  else if (auVar5._0_8_ != 0.0) {
    FUN_0041cffd(iVar1,2);
    FUN_0041cffd(extraout_ECX_01,0x10);
    iVar1 = extraout_ECX_02;
  }
  uVar4 = 0;
  dVar3 = auVar5._0_8_;
  if (dVar3 != 0.0) {
    auVar6 = auVar5 & ZEXT816(0xfffffffffffff) | ZEXT816(0x10000000000000);
    lVar8 = SUB168(ZEXT416(0x433),0) - ((ulonglong)dVar3 >> 0x34);
    uVar9 = auVar6._0_8_ >> lVar8;
    iVar2 = -(uint)(0x433 < auVar5._4_4_ >> 0x14);
    uVar4 = CONCAT44(iVar2,iVar2);
    uVar4 = ~uVar4 & uVar9 | auVar6._0_8_ << ((ulonglong)dVar3 >> 0x34) - SUB168(ZEXT416(0x433),0) & uVar4;
    uVar4 = ~-(ulonglong)(in_XMM0_Qa == dVar3) & -uVar4 | uVar4 & -(ulonglong)(in_XMM0_Qa == dVar3);
    if ((0 < (int)lVar8) &&
       (auVar10._0_8_ = uVar9 << lVar8, auVar10._8_8_ = (auVar6._8_8_ >> lVar8) << lVar8,
       SUB164(auVar6 ^ auVar10,0) != 0 || SUB164(auVar6 ^ auVar10,4) != 0)) {
      FUN_0041cffd(iVar1,0x10);
    }
  }
  return uVar4;
}



// ===== FUN_0041d05d @ 0041d05d =====

/* WARNING: Removing unreachable block (ram,0x0041cea3) */
/* WARNING: Removing unreachable block (ram,0x0041d0c7) */
/* WARNING: Removing unreachable block (ram,0x0041cea8) */
/* WARNING: Removing unreachable block (ram,0x0041ceb6) */
/* WARNING: Removing unreachable block (ram,0x0041cec0) */
/* WARNING: Removing unreachable block (ram,0x0041ceca) */
/* WARNING: Removing unreachable block (ram,0x0041cedc) */
/* WARNING: Removing unreachable block (ram,0x0041ceef) */
/* WARNING: Removing unreachable block (ram,0x0041cefd) */
/* WARNING: Removing unreachable block (ram,0x0041cf07) */
/* WARNING: Removing unreachable block (ram,0x0041cf17) */

ulonglong FUN_0041d05d(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  double in_XMM0_Qa;
  ulonglong in_XMM0_Qb;
  int iVar2;
  double dVar3;
  ulonglong uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  double dVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 auVar10 [16];
  
  iVar1 = 5;
  dVar3 = 9.223372036854776e+18;
  if (0x7fefffff < ((uint)((ulonglong)in_XMM0_Qa >> 0x20) & 0x7fffffff)) {
LAB_0041cfeb:
    FUN_0041cffd(iVar1,8);
    return 0x8000000000000000;
  }
  auVar5._0_8_ = ABS(in_XMM0_Qa);
  auVar5._8_8_ = in_XMM0_Qb & 0x7fffffffffffffff;
  if (3.4028235677973366e+38 < auVar5._0_8_) {
    FUN_0041cffd(5,1);
    FUN_0041cffd(extraout_ECX,0x10);
    iVar1 = extraout_ECX_00;
  }
  if (1.1754943157898259e-38 <= auVar5._0_8_) {
    dVar7 = in_XMM0_Qa;
    if ((iVar1 == 4) && (9.223372036854776e+18 <= in_XMM0_Qa)) {
      dVar7 = in_XMM0_Qa - 9.223372036854776e+18;
    }
    if ((int)((ulonglong)((longlong)dVar7 << 0x23) >> 0x20) != 0) {
      FUN_0041cffd(iVar1,0x10);
      iVar1 = extraout_ECX_03;
    }
    if ((dVar3 <= in_XMM0_Qa) || (in_XMM0_Qa < -9.223372036854776e+18)) goto LAB_0041cfeb;
  }
  else if (auVar5._0_8_ != 0.0) {
    FUN_0041cffd(iVar1,2);
    FUN_0041cffd(extraout_ECX_01,0x10);
    iVar1 = extraout_ECX_02;
  }
  uVar4 = 0;
  dVar3 = auVar5._0_8_;
  if (dVar3 != 0.0) {
    auVar6 = auVar5 & ZEXT816(0xfffffffffffff) | ZEXT816(0x10000000000000);
    lVar8 = SUB168(ZEXT416(0x433),0) - ((ulonglong)dVar3 >> 0x34);
    uVar9 = auVar6._0_8_ >> lVar8;
    iVar2 = -(uint)(0x433 < auVar5._4_4_ >> 0x14);
    uVar4 = CONCAT44(iVar2,iVar2);
    uVar4 = ~uVar4 & uVar9 | auVar6._0_8_ << ((ulonglong)dVar3 >> 0x34) - SUB168(ZEXT416(0x433),0) & uVar4;
    uVar4 = ~-(ulonglong)(in_XMM0_Qa == dVar3) & -uVar4 | uVar4 & -(ulonglong)(in_XMM0_Qa == dVar3);
    if ((0 < (int)lVar8) &&
       (auVar10._0_8_ = uVar9 << lVar8, auVar10._8_8_ = (auVar6._8_8_ >> lVar8) << lVar8,
       SUB164(auVar6 ^ auVar10,0) != 0 || SUB164(auVar6 ^ auVar10,4) != 0)) {
      FUN_0041cffd(iVar1,0x10);
    }
  }
  return uVar4;
}



// ===== FUN_0041d16c @ 0041d16c =====

int __fastcall FUN_0041d16c(undefined4 param_1,uint param_2)

{
  int iVar1;
  int in_EAX;
  
  if (param_2 == 0) {
    return in_EAX;
  }
  iVar1 = 0x1f;
  if (param_2 != 0) {
    for (; param_2 >> iVar1 == 0; iVar1 = iVar1 + -1) {
    }
  }
  return 0x20 - iVar1;
}



// ===== FUN_0041d1fd @ 0041d1fd =====

uint __fastcall FUN_0041d1fd(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 0x1f;
  if (uVar2 == param_2) {
    return uVar2;
  }
  if ((int)param_2 < 0) {
    uVar2 = FUN_0041d16c(-param_1,-(param_2 + (param_1 != 0)));
    return uVar2;
  }
  if (param_2 == 0) {
    return uVar2;
  }
  iVar1 = 0x1f;
  if (param_2 != 0) {
    for (; param_2 >> iVar1 == 0; iVar1 = iVar1 + -1) {
    }
  }
  return 0x20 - iVar1;
}



// ===== Unwind@0041d270 @ 0041d270 =====

void Unwind_0041d270(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) == 0) {
    return;
  }
  *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
  FUN_00401da0(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041d2b0 @ 0041d2b0 =====

void Unwind_0041d2b0(void)

{
  int unaff_EBP;
  
  FUN_004028a0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// ===== Unwind@0041d2e0 @ 0041d2e0 =====

void Unwind_0041d2e0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d310 @ 0041d310 =====

void Unwind_0041d310(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// ===== Unwind@0041d318 @ 0041d318 =====

void Unwind_0041d318(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// ===== Unwind@0041d320 @ 0041d320 =====

void Unwind_0041d320(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// ===== Unwind@0041d328 @ 0041d328 =====

void Unwind_0041d328(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// ===== Unwind@0041d330 @ 0041d330 =====

void Unwind_0041d330(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041d360 @ 0041d360 =====

void Unwind_0041d360(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041d368 @ 0041d368 =====

void Unwind_0041d368(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d390 @ 0041d390 =====

void Unwind_0041d390(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x44));
  return;
}



// ===== Unwind@0041d398 @ 0041d398 =====

void Unwind_0041d398(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d3a4 @ 0041d3a4 =====

void Unwind_0041d3a4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d3ac @ 0041d3ac =====

void Unwind_0041d3ac(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d3b4 @ 0041d3b4 =====

void Unwind_0041d3b4(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d3bc @ 0041d3bc =====

void Unwind_0041d3bc(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d3c4 @ 0041d3c4 =====

void Unwind_0041d3c4(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d400 @ 0041d400 =====

void Unwind_0041d400(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041d40c @ 0041d40c =====

void Unwind_0041d40c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d414 @ 0041d414 =====

void Unwind_0041d414(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -100));
  return;
}



// ===== Unwind@0041d450 @ 0041d450 =====

void Unwind_0041d450(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d480 @ 0041d480 =====

void Unwind_0041d480(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// ===== Unwind@0041d488 @ 0041d488 =====

void Unwind_0041d488(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x78));
  return;
}



// ===== Unwind@0041d490 @ 0041d490 =====

void Unwind_0041d490(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// ===== Unwind@0041d498 @ 0041d498 =====

void Unwind_0041d498(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// ===== Unwind@0041d4a0 @ 0041d4a0 =====

void Unwind_0041d4a0(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// ===== Unwind@0041d4a8 @ 0041d4a8 =====

void Unwind_0041d4a8(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x48));
  return;
}



// ===== Unwind@0041d4d0 @ 0041d4d0 =====

void Unwind_0041d4d0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// ===== Unwind@0041d4d8 @ 0041d4d8 =====

void Unwind_0041d4d8(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// ===== Unwind@0041d4e0 @ 0041d4e0 =====

void Unwind_0041d4e0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d4e8 @ 0041d4e8 =====

void Unwind_0041d4e8(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// ===== Unwind@0041d4f0 @ 0041d4f0 =====

void Unwind_0041d4f0(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// ===== Unwind@0041d520 @ 0041d520 =====

void Unwind_0041d520(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d528 @ 0041d528 =====

void Unwind_0041d528(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d560 @ 0041d560 =====

void Unwind_0041d560(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// ===== Unwind@0041d568 @ 0041d568 =====

void Unwind_0041d568(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// ===== Unwind@0041d570 @ 0041d570 =====

void Unwind_0041d570(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// ===== Unwind@0041d5a0 @ 0041d5a0 =====

void Unwind_0041d5a0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041d5a8 @ 0041d5a8 =====

void Unwind_0041d5a8(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d5d0 @ 0041d5d0 =====

void Unwind_0041d5d0(void)

{
  int unaff_EBP;
  
  FUN_00404e20(unaff_EBP + -0x3c);
  return;
}



// ===== Unwind@0041d600 @ 0041d600 =====

void Unwind_0041d600(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041d60c @ 0041d60c =====

void Unwind_0041d60c(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041d640 @ 0041d640 =====

void Unwind_0041d640(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x50));
  return;
}



// ===== Unwind@0041d64c @ 0041d64c =====

void Unwind_0041d64c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d654 @ 0041d654 =====

void Unwind_0041d654(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// ===== Unwind@0041d65c @ 0041d65c =====

void Unwind_0041d65c(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d664 @ 0041d664 =====

void Unwind_0041d664(void)

{
  int unaff_EBP;
  
  FUN_00406180((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d66c @ 0041d66c =====

void Unwind_0041d66c(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d6a0 @ 0041d6a0 =====

void Unwind_0041d6a0(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



// ===== Unwind@0041d6d0 @ 0041d6d0 =====

void Unwind_0041d6d0(void)

{
  int unaff_EBP;
  
  operator_delete(*(void **)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041d6dc @ 0041d6dc =====

void Unwind_0041d6dc(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x60));
  return;
}



// ===== Unwind@0041d6e4 @ 0041d6e4 =====

void Unwind_0041d6e4(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041d6ec @ 0041d6ec =====

void Unwind_0041d6ec(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d6f4 @ 0041d6f4 =====

void Unwind_0041d6f4(void)

{
  int unaff_EBP;
  
  FUN_00406180((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d6fc @ 0041d6fc =====

void Unwind_0041d6fc(void)

{
  int unaff_EBP;
  
  FUN_00405120((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d730 @ 0041d730 =====

void Unwind_0041d730(void)

{
  int unaff_EBP;
  
  FUN_00401e10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041d738 @ 0041d738 =====

void Unwind_0041d738(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// ===== Unwind@0041d770 @ 0041d770 =====

void Unwind_0041d770(void)

{
  int unaff_EBP;
  
  operator_delete__(*(void **)(unaff_EBP + 8));
  return;
}



// ===== Unwind@0041d7a0 @ 0041d7a0 =====

void Unwind_0041d7a0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xd8));
  return;
}



// ===== Unwind@0041d7ab @ 0041d7ab =====

void Unwind_0041d7ab(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xf0));
  return;
}



// ===== Unwind@0041d7b6 @ 0041d7b6 =====

void Unwind_0041d7b6(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041d7be @ 0041d7be =====

void Unwind_0041d7be(void)

{
  int unaff_EBP;
  
  FUN_004071d0((int *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041d7c9 @ 0041d7c9 =====

void Unwind_0041d7c9(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xd8));
  return;
}



// ===== Unwind@0041d800 @ 0041d800 =====

void Unwind_0041d800(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xf8));
  return;
}



// ===== Unwind@0041d80b @ 0041d80b =====

void Unwind_0041d80b(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x98));
  return;
}



// ===== Unwind@0041d816 @ 0041d816 =====

void Unwind_0041d816(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// ===== Unwind@0041d81e @ 0041d81e =====

void Unwind_0041d81e(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x80));
  return;
}



// ===== Unwind@0041d826 @ 0041d826 =====

void Unwind_0041d826(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x38));
  return;
}



// ===== Unwind@0041d82e @ 0041d82e =====

void Unwind_0041d82e(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x50));
  return;
}



// ===== Unwind@0041d836 @ 0041d836 =====

void Unwind_0041d836(void)

{
  int unaff_EBP;
  
  FUN_00401e10((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041d83e @ 0041d83e =====

void Unwind_0041d83e(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -200));
  return;
}



// ===== Unwind@0041d849 @ 0041d849 =====

void Unwind_0041d849(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xe0));
  return;
}



// ===== Unwind@0041d854 @ 0041d854 =====

void Unwind_0041d854(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x110));
  return;
}



// ===== Unwind@0041d85f @ 0041d85f =====

void Unwind_0041d85f(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb0));
  return;
}



// ===== Unwind@0041d8a0 @ 0041d8a0 =====

void Unwind_0041d8a0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// ===== Unwind@0041d8a8 @ 0041d8a8 =====

void Unwind_0041d8a8(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// ===== Unwind@0041d8b0 @ 0041d8b0 =====

void Unwind_0041d8b0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x54));
  return;
}



// ===== Unwind@0041d8e0 @ 0041d8e0 =====

void Unwind_0041d8e0(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041d910 @ 0041d910 =====

void Unwind_0041d910(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// ===== Unwind@0041d918 @ 0041d918 =====

void Unwind_0041d918(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041d950 @ 0041d950 =====

void Unwind_0041d950(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x88));
  return;
}



// ===== Unwind@0041d95b @ 0041d95b =====

void Unwind_0041d95b(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x40));
  return;
}



// ===== Unwind@0041d963 @ 0041d963 =====

void Unwind_0041d963(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041d96b @ 0041d96b =====

void Unwind_0041d96b(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x70));
  return;
}



// ===== Unwind@0041d973 @ 0041d973 =====

void Unwind_0041d973(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x58));
  return;
}



// ===== Unwind@0041d9a0 @ 0041d9a0 =====

void Unwind_0041d9a0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x18) & 1) == 0) {
    return;
  }
  *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x18) & 0xfffffffe;
  FUN_00401da0(*(undefined4 **)(unaff_EBP + -0x1c));
  return;
}



// ===== Unwind@0041d9e0 @ 0041d9e0 =====

void Unwind_0041d9e0(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041da60 @ 0041da60 =====

void Unwind_0041da60(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) == 0) {
    return;
  }
  *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x0041da76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(*(int *)(unaff_EBP + -0x14) + 0x50));
  return;
}



// ===== Unwind@0041da7d @ 0041da7d =====

void Unwind_0041da7d(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x0041da83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_ostream<char,std::char_traits<char>_>::~basic_ostream<char,std::char_traits<char>_>
            ((basic_ostream<char,std::char_traits<char>_> *)(*(int *)(unaff_EBP + -0x14) + 8));
  return;
}



// ===== Unwind@0041da89 @ 0041da89 =====

void Unwind_0041da89(void)

{
  int unaff_EBP;
  
                    /* WARNING: Could not recover jumptable at 0x0041da8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (*(basic_streambuf<char,std::char_traits<char>_> **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041dab0 @ 0041dab0 =====

void Unwind_0041dab0(void)

{
  int unaff_EBP;
  
  FUN_00409170(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041dae0 @ 0041dae0 =====

void Unwind_0041dae0(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// ===== Unwind@0041db10 @ 0041db10 =====

void Unwind_0041db10(void)

{
  int unaff_EBP;
  
  FUN_0040a230((int *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041db18 @ 0041db18 =====

void Unwind_0041db18(void)

{
  int unaff_EBP;
  
  FUN_0040a010((int *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041db45 @ 0041db45 =====

void Unwind_0041db45(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041dbc0 @ 0041dbc0 =====

void Unwind_0041dbc0(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + 8));
  return;
}



// ===== Unwind@0041dbf0 @ 0041dbf0 =====

void Unwind_0041dbf0(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + 0xc));
  return;
}



// ===== Unwind@0041dc20 @ 0041dc20 =====

void Unwind_0041dc20(void)

{
  int unaff_EBP;
  
  FUN_00405120(*(undefined4 **)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041dc50 @ 0041dc50 =====

void Unwind_0041dc50(void)

{
  int unaff_EBP;
  
  FUN_00404f50((undefined4 *)(unaff_EBP + -0x490));
  return;
}



// ===== Unwind@0041dc5b @ 0041dc5b =====

void Unwind_0041dc5b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// ===== Unwind@0041dc66 @ 0041dc66 =====

void Unwind_0041dc66(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// ===== Unwind@0041dca0 @ 0041dca0 =====

void Unwind_0041dca0(void)

{
  int unaff_EBP;
  
  FUN_004141b0((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041dcd0 @ 0041dcd0 =====

void Unwind_0041dcd0(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041dd00 @ 0041dd00 =====

void Unwind_0041dd00(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041dd08 @ 0041dd08 =====

void Unwind_0041dd08(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// ===== Unwind@0041dd10 @ 0041dd10 =====

void Unwind_0041dd10(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041dd18 @ 0041dd18 =====

void Unwind_0041dd18(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041dd20 @ 0041dd20 =====

void Unwind_0041dd20(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041dd28 @ 0041dd28 =====

void Unwind_0041dd28(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041dd30 @ 0041dd30 =====

void Unwind_0041dd30(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// ===== Unwind@0041dd60 @ 0041dd60 =====

void Unwind_0041dd60(void)

{
  int unaff_EBP;
  
  FUN_004141e0((undefined4 *)(unaff_EBP + -0x668));
  return;
}



// ===== Unwind@0041dd6b @ 0041dd6b =====

void Unwind_0041dd6b(void)

{
  int unaff_EBP;
  
  FUN_004141e0((undefined4 *)(unaff_EBP + -0x65c));
  return;
}



// ===== Unwind@0041dd76 @ 0041dd76 =====

void Unwind_0041dd76(void)

{
  int unaff_EBP;
  
  FUN_004141e0((undefined4 *)(unaff_EBP + -0x664));
  return;
}



// ===== Unwind@0041dd81 @ 0041dd81 =====

void Unwind_0041dd81(void)

{
  int unaff_EBP;
  
  FUN_004141e0((undefined4 *)(unaff_EBP + -0x674));
  return;
}



// ===== Unwind@0041dd8c @ 0041dd8c =====

void Unwind_0041dd8c(void)

{
  int unaff_EBP;
  
  FUN_0040ba60((VARIANTARG *)(unaff_EBP + -0x6d0));
  return;
}



// ===== Unwind@0041dd97 @ 0041dd97 =====

void Unwind_0041dd97(void)

{
  int unaff_EBP;
  
  FUN_0040ba60((VARIANTARG *)(unaff_EBP + -0x6d0));
  return;
}



// ===== Unwind@0041dda2 @ 0041dda2 =====

void Unwind_0041dda2(void)

{
  int unaff_EBP;
  
  FUN_0040ba60((VARIANTARG *)(unaff_EBP + -0x6d0));
  return;
}



// ===== Unwind@0041ddad @ 0041ddad =====

void Unwind_0041ddad(void)

{
  int unaff_EBP;
  
  FUN_0040ba60((VARIANTARG *)(unaff_EBP + -0x6d0));
  return;
}



// ===== Unwind@0041ddb8 @ 0041ddb8 =====

void Unwind_0041ddb8(void)

{
  int unaff_EBP;
  
  FUN_0040ba60((VARIANTARG *)(unaff_EBP + -0x6d0));
  return;
}



// ===== Unwind@0041ddc3 @ 0041ddc3 =====

void Unwind_0041ddc3(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x660));
  return;
}



// ===== Unwind@0041ddce @ 0041ddce =====

void Unwind_0041ddce(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x6bc));
  return;
}



// ===== Unwind@0041ddd9 @ 0041ddd9 =====

void Unwind_0041ddd9(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x6d8));
  return;
}



// ===== Unwind@0041de20 @ 0041de20 =====

void Unwind_0041de20(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041de50 @ 0041de50 =====

void Unwind_0041de50(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x17c));
  return;
}



// ===== Unwind@0041de5b @ 0041de5b =====

void Unwind_0041de5b(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x14c));
  return;
}



// ===== Unwind@0041de66 @ 0041de66 =====

void Unwind_0041de66(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x134));
  return;
}



// ===== Unwind@0041dea0 @ 0041dea0 =====

void Unwind_0041dea0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x534) & 1) == 0) {
    return;
  }
  *(uint *)(unaff_EBP + -0x534) = *(uint *)(unaff_EBP + -0x534) & 0xfffffffe;
  FUN_00401da0(*(undefined4 **)(unaff_EBP + -0x538));
  return;
}



// ===== Unwind@0041def0 @ 0041def0 =====

void Unwind_0041def0(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041df20 @ 0041df20 =====

void Unwind_0041df20(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x94));
  return;
}



// ===== Unwind@0041df2b @ 0041df2b =====

void Unwind_0041df2b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041df36 @ 0041df36 =====

void Unwind_0041df36(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041df41 @ 0041df41 =====

void Unwind_0041df41(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041df4c @ 0041df4c =====

void Unwind_0041df4c(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041df57 @ 0041df57 =====

void Unwind_0041df57(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041df62 @ 0041df62 =====

void Unwind_0041df62(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041df6d @ 0041df6d =====

void Unwind_0041df6d(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041df78 @ 0041df78 =====

void Unwind_0041df78(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041df83 @ 0041df83 =====

void Unwind_0041df83(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041df8e @ 0041df8e =====

void Unwind_0041df8e(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041df99 @ 0041df99 =====

void Unwind_0041df99(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041dfa4 @ 0041dfa4 =====

void Unwind_0041dfa4(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041dfaf @ 0041dfaf =====

void Unwind_0041dfaf(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041dfba @ 0041dfba =====

void Unwind_0041dfba(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041dfc5 @ 0041dfc5 =====

void Unwind_0041dfc5(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041dfd0 @ 0041dfd0 =====

void Unwind_0041dfd0(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041dfdb @ 0041dfdb =====

void Unwind_0041dfdb(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041dfe6 @ 0041dfe6 =====

void Unwind_0041dfe6(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041dff1 @ 0041dff1 =====

void Unwind_0041dff1(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041dffc @ 0041dffc =====

void Unwind_0041dffc(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041e007 @ 0041e007 =====

void Unwind_0041e007(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041e012 @ 0041e012 =====

void Unwind_0041e012(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041e01d @ 0041e01d =====

void Unwind_0041e01d(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041e028 @ 0041e028 =====

void Unwind_0041e028(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041e033 @ 0041e033 =====

void Unwind_0041e033(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041e03e @ 0041e03e =====

void Unwind_0041e03e(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041e049 @ 0041e049 =====

void Unwind_0041e049(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041e054 @ 0041e054 =====

void Unwind_0041e054(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041e05f @ 0041e05f =====

void Unwind_0041e05f(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa4));
  return;
}



// ===== Unwind@0041e06a @ 0041e06a =====

void Unwind_0041e06a(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// ===== Unwind@0041e0a0 @ 0041e0a0 =====

void Unwind_0041e0a0(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041e0a8 @ 0041e0a8 =====

void Unwind_0041e0a8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x18));
  return;
}



// ===== Unwind@0041e0e0 @ 0041e0e0 =====

void Unwind_0041e0e0(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041e110 @ 0041e110 =====

void Unwind_0041e110(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e140 @ 0041e140 =====

void Unwind_0041e140(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x134));
  return;
}



// ===== Unwind@0041e14b @ 0041e14b =====

void Unwind_0041e14b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x140));
  return;
}



// ===== Unwind@0041e180 @ 0041e180 =====

void Unwind_0041e180(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041e188 @ 0041e188 =====

void Unwind_0041e188(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041e190 @ 0041e190 =====

void Unwind_0041e190(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041e198 @ 0041e198 =====

void Unwind_0041e198(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e1d0 @ 0041e1d0 =====

void Unwind_0041e1d0(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041e1d8 @ 0041e1d8 =====

void Unwind_0041e1d8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041e1e0 @ 0041e1e0 =====

void Unwind_0041e1e0(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041e1e8 @ 0041e1e8 =====

void Unwind_0041e1e8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e1f0 @ 0041e1f0 =====

void Unwind_0041e1f0(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e1f8 @ 0041e1f8 =====

void Unwind_0041e1f8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x24));
  return;
}



// ===== Unwind@0041e200 @ 0041e200 =====

void Unwind_0041e200(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x20));
  return;
}



// ===== Unwind@0041e230 @ 0041e230 =====

void Unwind_0041e230(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x4b60));
  return;
}



// ===== Unwind@0041e23b @ 0041e23b =====

void Unwind_0041e23b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b58));
  return;
}



// ===== Unwind@0041e246 @ 0041e246 =====

void Unwind_0041e246(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c38));
  return;
}



// ===== Unwind@0041e251 @ 0041e251 =====

void Unwind_0041e251(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b50));
  return;
}



// ===== Unwind@0041e25c @ 0041e25c =====

void Unwind_0041e25c(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c34));
  return;
}



// ===== Unwind@0041e267 @ 0041e267 =====

void Unwind_0041e267(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b5c));
  return;
}



// ===== Unwind@0041e272 @ 0041e272 =====

void Unwind_0041e272(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x4bac));
  return;
}



// ===== Unwind@0041e27d @ 0041e27d =====

void Unwind_0041e27d(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x4bc4));
  return;
}



// ===== Unwind@0041e288 @ 0041e288 =====

void Unwind_0041e288(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x4c14));
  return;
}



// ===== Unwind@0041e293 @ 0041e293 =====

void Unwind_0041e293(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4b7c));
  return;
}



// ===== Unwind@0041e29e @ 0041e29e =====

void Unwind_0041e29e(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e2a9 @ 0041e2a9 =====

void Unwind_0041e2a9(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e2b4 @ 0041e2b4 =====

void Unwind_0041e2b4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e2bf @ 0041e2bf =====

void Unwind_0041e2bf(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e2ca @ 0041e2ca =====

void Unwind_0041e2ca(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e2d5 @ 0041e2d5 =====

void Unwind_0041e2d5(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x4b94));
  return;
}



// ===== Unwind@0041e2e0 @ 0041e2e0 =====

void Unwind_0041e2e0(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x4c14));
  return;
}



// ===== Unwind@0041e2eb @ 0041e2eb =====

void Unwind_0041e2eb(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4b7c));
  return;
}



// ===== Unwind@0041e2f6 @ 0041e2f6 =====

void Unwind_0041e2f6(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e301 @ 0041e301 =====

void Unwind_0041e301(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e30c @ 0041e30c =====

void Unwind_0041e30c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e317 @ 0041e317 =====

void Unwind_0041e317(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e322 @ 0041e322 =====

void Unwind_0041e322(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x4c2c));
  return;
}



// ===== Unwind@0041e32d @ 0041e32d =====

void Unwind_0041e32d(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c38));
  return;
}



// ===== Unwind@0041e338 @ 0041e338 =====

void Unwind_0041e338(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c3c));
  return;
}



// ===== Unwind@0041e343 @ 0041e343 =====

void Unwind_0041e343(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b54));
  return;
}



// ===== Unwind@0041e34e @ 0041e34e =====

void Unwind_0041e34e(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b50));
  return;
}



// ===== Unwind@0041e359 @ 0041e359 =====

void Unwind_0041e359(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b5c));
  return;
}



// ===== Unwind@0041e390 @ 0041e390 =====

void Unwind_0041e390(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x498));
  return;
}



// ===== Unwind@0041e39b @ 0041e39b =====

void Unwind_0041e39b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4ac));
  return;
}



// ===== Unwind@0041e3a6 @ 0041e3a6 =====

void Unwind_0041e3a6(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// ===== Unwind@0041e3b1 @ 0041e3b1 =====

void Unwind_0041e3b1(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4d0));
  return;
}



// ===== Unwind@0041e3bc @ 0041e3bc =====

void Unwind_0041e3bc(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// ===== Unwind@0041e3c7 @ 0041e3c7 =====

void Unwind_0041e3c7(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// ===== Unwind@0041e3d2 @ 0041e3d2 =====

void Unwind_0041e3d2(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4dc));
  return;
}



// ===== Unwind@0041e3dd @ 0041e3dd =====

void Unwind_0041e3dd(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4e0));
  return;
}



// ===== Unwind@0041e3e8 @ 0041e3e8 =====

void Unwind_0041e3e8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4d8));
  return;
}



// ===== Unwind@0041e3f3 @ 0041e3f3 =====

void Unwind_0041e3f3(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4d0));
  return;
}



// ===== Unwind@0041e3fe @ 0041e3fe =====

void Unwind_0041e3fe(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// ===== Unwind@0041e409 @ 0041e409 =====

void Unwind_0041e409(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// ===== Unwind@0041e414 @ 0041e414 =====

void Unwind_0041e414(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4a8));
  return;
}



// ===== Unwind@0041e41f @ 0041e41f =====

void Unwind_0041e41f(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// ===== Unwind@0041e42a @ 0041e42a =====

void Unwind_0041e42a(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b4));
  return;
}



// ===== Unwind@0041e435 @ 0041e435 =====

void Unwind_0041e435(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x494));
  return;
}



// ===== Unwind@0041e440 @ 0041e440 =====

void Unwind_0041e440(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// ===== Unwind@0041e44b @ 0041e44b =====

void Unwind_0041e44b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4d0));
  return;
}



// ===== Unwind@0041e456 @ 0041e456 =====

void Unwind_0041e456(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// ===== Unwind@0041e461 @ 0041e461 =====

void Unwind_0041e461(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// ===== Unwind@0041e46c @ 0041e46c =====

void Unwind_0041e46c(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b4));
  return;
}



// ===== Unwind@0041e477 @ 0041e477 =====

void Unwind_0041e477(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// ===== Unwind@0041e482 @ 0041e482 =====

void Unwind_0041e482(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4a8));
  return;
}



// ===== Unwind@0041e48d @ 0041e48d =====

void Unwind_0041e48d(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// ===== Unwind@0041e498 @ 0041e498 =====

void Unwind_0041e498(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4d0));
  return;
}



// ===== Unwind@0041e4a3 @ 0041e4a3 =====

void Unwind_0041e4a3(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4c8));
  return;
}



// ===== Unwind@0041e4ae @ 0041e4ae =====

void Unwind_0041e4ae(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4cc));
  return;
}



// ===== Unwind@0041e4b9 @ 0041e4b9 =====

void Unwind_0041e4b9(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b4));
  return;
}



// ===== Unwind@0041e4c4 @ 0041e4c4 =====

void Unwind_0041e4c4(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b0));
  return;
}



// ===== Unwind@0041e4cf @ 0041e4cf =====

void Unwind_0041e4cf(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4a8));
  return;
}



// ===== Unwind@0041e4da @ 0041e4da =====

void Unwind_0041e4da(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x4b8));
  return;
}



// ===== Unwind@0041e510 @ 0041e510 =====

void Unwind_0041e510(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0x14));
  return;
}



// ===== Unwind@0041e518 @ 0041e518 =====

void Unwind_0041e518(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// ===== Unwind@0041e550 @ 0041e550 =====

void Unwind_0041e550(void)

{
  int unaff_EBP;
  
  FUN_00414180((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e580 @ 0041e580 =====

void Unwind_0041e580(void)

{
  int unaff_EBP;
  
  FUN_0040c110((int *)(unaff_EBP + -0xa118));
  return;
}



// ===== Unwind@0041e58b @ 0041e58b =====

void Unwind_0041e58b(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa138));
  return;
}



// ===== Unwind@0041e596 @ 0041e596 =====

void Unwind_0041e596(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa134));
  return;
}



// ===== Unwind@0041e5a1 @ 0041e5a1 =====

void Unwind_0041e5a1(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa130));
  return;
}



// ===== Unwind@0041e5ac @ 0041e5ac =====

void Unwind_0041e5ac(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa130));
  return;
}



// ===== Unwind@0041e5b7 @ 0041e5b7 =====

void Unwind_0041e5b7(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa134));
  return;
}



// ===== Unwind@0041e5c2 @ 0041e5c2 =====

void Unwind_0041e5c2(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa138));
  return;
}



// ===== Unwind@0041e5cd @ 0041e5cd =====

void Unwind_0041e5cd(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa130));
  return;
}



// ===== Unwind@0041e5d8 @ 0041e5d8 =====

void Unwind_0041e5d8(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa134));
  return;
}



// ===== Unwind@0041e5e3 @ 0041e5e3 =====

void Unwind_0041e5e3(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa138));
  return;
}



// ===== Unwind@0041e5ee @ 0041e5ee =====

void Unwind_0041e5ee(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa130));
  return;
}



// ===== Unwind@0041e5f9 @ 0041e5f9 =====

void Unwind_0041e5f9(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa134));
  return;
}



// ===== Unwind@0041e604 @ 0041e604 =====

void Unwind_0041e604(void)

{
  int unaff_EBP;
  
  FUN_0040ba50((undefined4 *)(unaff_EBP + -0xa138));
  return;
}



// ===== Unwind@0041e660 @ 0041e660 =====

void Unwind_0041e660(void)

{
  int unaff_EBP;
  
  FUN_00401760((SOCKET *)(*(int *)(unaff_EBP + -0x10) + 0x34));
  return;
}



// ===== Unwind@0041e66b @ 0041e66b =====

void Unwind_0041e66b(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041e673 @ 0041e673 =====

void Unwind_0041e673(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 4));
  return;
}



// ===== Unwind@0041e6a0 @ 0041e6a0 =====

void Unwind_0041e6a0(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x94));
  return;
}



// ===== Unwind@0041e6ab @ 0041e6ab =====

void Unwind_0041e6ab(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x2c));
  return;
}



// ===== Unwind@0041e6b3 @ 0041e6b3 =====

void Unwind_0041e6b3(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6be @ 0041e6be =====

void Unwind_0041e6be(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6c9 @ 0041e6c9 =====

void Unwind_0041e6c9(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6d4 @ 0041e6d4 =====

void Unwind_0041e6d4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6df @ 0041e6df =====

void Unwind_0041e6df(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6ea @ 0041e6ea =====

void Unwind_0041e6ea(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e6f5 @ 0041e6f5 =====

void Unwind_0041e6f5(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xac));
  return;
}



// ===== Unwind@0041e730 @ 0041e730 =====

void Unwind_0041e730(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// ===== Unwind@0041e73b @ 0041e73b =====

void Unwind_0041e73b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x28));
  return;
}



// ===== Unwind@0041e743 @ 0041e743 =====

void Unwind_0041e743(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e74e @ 0041e74e =====

void Unwind_0041e74e(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e759 @ 0041e759 =====

void Unwind_0041e759(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e764 @ 0041e764 =====

void Unwind_0041e764(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e76f @ 0041e76f =====

void Unwind_0041e76f(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e77a @ 0041e77a =====

void Unwind_0041e77a(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa8));
  return;
}



// ===== Unwind@0041e7b0 @ 0041e7b0 =====

void Unwind_0041e7b0(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x68));
  return;
}



// ===== Unwind@0041e7b8 @ 0041e7b8 =====

void Unwind_0041e7b8(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xa0));
  return;
}



// ===== Unwind@0041e7c3 @ 0041e7c3 =====

void Unwind_0041e7c3(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e7ce @ 0041e7ce =====

void Unwind_0041e7ce(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e7d9 @ 0041e7d9 =====

void Unwind_0041e7d9(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e7e4 @ 0041e7e4 =====

void Unwind_0041e7e4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e7ef @ 0041e7ef =====

void Unwind_0041e7ef(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e7fa @ 0041e7fa =====

void Unwind_0041e7fa(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e805 @ 0041e805 =====

void Unwind_0041e805(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e810 @ 0041e810 =====

void Unwind_0041e810(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc0));
  return;
}



// ===== Unwind@0041e850 @ 0041e850 =====

void Unwind_0041e850(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0x170));
  return;
}



// ===== Unwind@0041e85b @ 0041e85b =====

void Unwind_0041e85b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1d0));
  return;
}



// ===== Unwind@0041e866 @ 0041e866 =====

void Unwind_0041e866(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0x1a0));
  return;
}



// ===== Unwind@0041e871 @ 0041e871 =====

void Unwind_0041e871(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e87c @ 0041e87c =====

void Unwind_0041e87c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e887 @ 0041e887 =====

void Unwind_0041e887(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e892 @ 0041e892 =====

void Unwind_0041e892(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e89d @ 0041e89d =====

void Unwind_0041e89d(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8a8 @ 0041e8a8 =====

void Unwind_0041e8a8(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8b3 @ 0041e8b3 =====

void Unwind_0041e8b3(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8be @ 0041e8be =====

void Unwind_0041e8be(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8c9 @ 0041e8c9 =====

void Unwind_0041e8c9(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8d4 @ 0041e8d4 =====

void Unwind_0041e8d4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8df @ 0041e8df =====

void Unwind_0041e8df(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8ea @ 0041e8ea =====

void Unwind_0041e8ea(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e8f5 @ 0041e8f5 =====

void Unwind_0041e8f5(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x200));
  return;
}



// ===== Unwind@0041e930 @ 0041e930 =====

void Unwind_0041e930(void)

{
  int unaff_EBP;
  
  FUN_00404f50((undefined4 *)(unaff_EBP + -0x90));
  return;
}



// ===== Unwind@0041e93b @ 0041e93b =====

void Unwind_0041e93b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xb0));
  return;
}



// ===== Unwind@0041e946 @ 0041e946 =====

void Unwind_0041e946(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -200));
  return;
}



// ===== Unwind@0041e980 @ 0041e980 =====

void Unwind_0041e980(void)

{
  int unaff_EBP;
  
  FUN_004013c0((undefined4 *)(unaff_EBP + -0xaa0));
  return;
}



// ===== Unwind@0041e98b @ 0041e98b =====

void Unwind_0041e98b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xbe0));
  return;
}



// ===== Unwind@0041e996 @ 0041e996 =====

void Unwind_0041e996(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xbbc));
  return;
}



// ===== Unwind@0041e9a1 @ 0041e9a1 =====

void Unwind_0041e9a1(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc00));
  return;
}



// ===== Unwind@0041e9ac @ 0041e9ac =====

void Unwind_0041e9ac(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xae0));
  return;
}



// ===== Unwind@0041e9b7 @ 0041e9b7 =====

void Unwind_0041e9b7(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xba0));
  return;
}



// ===== Unwind@0041e9c2 @ 0041e9c2 =====

void Unwind_0041e9c2(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xab8));
  return;
}



// ===== Unwind@0041e9cd @ 0041e9cd =====

void Unwind_0041e9cd(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb58));
  return;
}



// ===== Unwind@0041e9d8 @ 0041e9d8 =====

void Unwind_0041e9d8(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb28));
  return;
}



// ===== Unwind@0041e9e3 @ 0041e9e3 =====

void Unwind_0041e9e3(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb88));
  return;
}



// ===== Unwind@0041e9ee @ 0041e9ee =====

void Unwind_0041e9ee(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb10));
  return;
}



// ===== Unwind@0041e9f9 @ 0041e9f9 =====

void Unwind_0041e9f9(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb70));
  return;
}



// ===== Unwind@0041ea04 @ 0041ea04 =====

void Unwind_0041ea04(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xb40));
  return;
}



// ===== Unwind@0041ea0f @ 0041ea0f =====

void Unwind_0041ea0f(void)

{
  int unaff_EBP;
  
  FUN_00401da0((undefined4 *)(unaff_EBP + -0xaf8));
  return;
}



// ===== Unwind@0041ea1a @ 0041ea1a =====

void Unwind_0041ea1a(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea25 @ 0041ea25 =====

void Unwind_0041ea25(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea30 @ 0041ea30 =====

void Unwind_0041ea30(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea3b @ 0041ea3b =====

void Unwind_0041ea3b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea46 @ 0041ea46 =====

void Unwind_0041ea46(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea51 @ 0041ea51 =====

void Unwind_0041ea51(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea5c @ 0041ea5c =====

void Unwind_0041ea5c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea67 @ 0041ea67 =====

void Unwind_0041ea67(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea72 @ 0041ea72 =====

void Unwind_0041ea72(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea7d @ 0041ea7d =====

void Unwind_0041ea7d(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea88 @ 0041ea88 =====

void Unwind_0041ea88(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea93 @ 0041ea93 =====

void Unwind_0041ea93(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ea9e @ 0041ea9e =====

void Unwind_0041ea9e(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eaa9 @ 0041eaa9 =====

void Unwind_0041eaa9(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eab4 @ 0041eab4 =====

void Unwind_0041eab4(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eabf @ 0041eabf =====

void Unwind_0041eabf(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eaca @ 0041eaca =====

void Unwind_0041eaca(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ead5 @ 0041ead5 =====

void Unwind_0041ead5(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eae0 @ 0041eae0 =====

void Unwind_0041eae0(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eaeb @ 0041eaeb =====

void Unwind_0041eaeb(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eaf6 @ 0041eaf6 =====

void Unwind_0041eaf6(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb01 @ 0041eb01 =====

void Unwind_0041eb01(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb0c @ 0041eb0c =====

void Unwind_0041eb0c(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb17 @ 0041eb17 =====

void Unwind_0041eb17(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb22 @ 0041eb22 =====

void Unwind_0041eb22(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb2d @ 0041eb2d =====

void Unwind_0041eb2d(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb38 @ 0041eb38 =====

void Unwind_0041eb38(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb43 @ 0041eb43 =====

void Unwind_0041eb43(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb4e @ 0041eb4e =====

void Unwind_0041eb4e(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041eb59 @ 0041eb59 =====

void Unwind_0041eb59(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb64 @ 0041eb64 =====

void Unwind_0041eb64(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb6f @ 0041eb6f =====

void Unwind_0041eb6f(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041eb7a @ 0041eb7a =====

void Unwind_0041eb7a(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041eb85 @ 0041eb85 =====

void Unwind_0041eb85(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eb90 @ 0041eb90 =====

void Unwind_0041eb90(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041eb9b @ 0041eb9b =====

void Unwind_0041eb9b(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041eba6 @ 0041eba6 =====

void Unwind_0041eba6(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebb1 @ 0041ebb1 =====

void Unwind_0041ebb1(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041ebbc @ 0041ebbc =====

void Unwind_0041ebbc(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0x1c20));
  return;
}



// ===== Unwind@0041ebc7 @ 0041ebc7 =====

void Unwind_0041ebc7(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebd2 @ 0041ebd2 =====

void Unwind_0041ebd2(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebdd @ 0041ebdd =====

void Unwind_0041ebdd(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebe8 @ 0041ebe8 =====

void Unwind_0041ebe8(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebf3 @ 0041ebf3 =====

void Unwind_0041ebf3(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ebfe @ 0041ebfe =====

void Unwind_0041ebfe(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ec09 @ 0041ec09 =====

void Unwind_0041ec09(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== Unwind@0041ec14 @ 0041ec14 =====

void Unwind_0041ec14(void)

{
  int unaff_EBP;
  
  FUN_004054d0((undefined4 *)(unaff_EBP + -0xc20));
  return;
}



// ===== FUN_0041eca0 @ 0041eca0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041eca0(void)

{
  undefined1 local_5;
  
  if (DAT_0042e2cc != 0) {
    FUN_00414420();
    FUN_00402240(&local_5);
    operator_delete((void *)DAT_0042e2cc);
    DAT_0042e2cc = 0;
    _DAT_0042e2d0 = 0;
    _DAT_0042e2d4 = 0;
  }
  return;
}



// ===== FUN_0041ecf0 @ 0041ecf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ecf0(void)

{
  uint uVar1;
  undefined1 local_5;
  
  uVar1 = DAT_00428050;
  if (0xf < DAT_00428064) {
    FUN_00402240(&local_5);
    FUN_00402420();
    FUN_00402240(&local_5);
    operator_delete((void *)uVar1);
  }
  DAT_00428064 = 0xf;
  _DAT_00428060 = 0;
  DAT_00428050 = DAT_00428050 & 0xffffff00;
  return;
}



// ===== FUN_0041ed60 @ 0041ed60 =====

void FUN_0041ed60(void)

{
  uint uVar1;
  undefined1 local_5;
  
  uVar1 = DAT_00428030;
  if (0xf < DAT_00428044) {
    FUN_00402240(&local_5);
    FUN_00402420();
    FUN_00402240(&local_5);
    operator_delete((void *)uVar1);
  }
  DAT_00428044 = 0xf;
  DAT_00428040 = 0;
  DAT_00428030 = DAT_00428030 & 0xffffff00;
  return;
}


