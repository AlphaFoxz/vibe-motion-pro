// decompiled by DumpAnchors for program: ArrayVPNApi.dll

// ===================== ArrayGetMTUAndTAF @ 10001990  anchors: [ArrayGetMTUAndTAF(byname)] =====================

void __cdecl ArrayGetMTUAndTAF(short *param_1,short *param_2)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 local_54 [9];
  char local_2e;
  char local_2d;
  char local_2c;
  short local_24;
  short local_22;
  short local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x1990  9  ArrayGetMTUAndTAF */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10099218;
  local_10 = ExceptionList;
  local_14 = DAT_100d6b20 ^ (uint)(local_54 + 0x14);
  ExceptionList = &local_10;
  FUN_100292d0(local_54);
  local_8 = 0;
  cVar1 = FUN_10028590((int)local_54);
  if (cVar1 == '\0') {
    DVar2 = GetLastError();
    iVar3 = FUN_100219f0(3,L"ArrayApi.cpp",0x9dc);
    if (iVar3 != 0) {
      DVar4 = GetLastError();
      FUN_10021a20(L"ArrayGetMTUAndTAF: load failed, error:%d\n",(char)DVar4);
      FUN_10021a10();
    }
    SetLastError(DVar2);
  }
  else {
    DVar2 = GetLastError();
    iVar3 = FUN_100219f0(3,L"ArrayApi.cpp",0x9e0);
    if (iVar3 != 0) {
      FUN_10021a20(L"ArrayGetMTUAndTAF: MTUExist:%d, MTU:%d, DTLDMTUExist:%d, DTLSMTU:%d, TAFexist:%d, TAF:%d\n",
                   local_2e);
      FUN_10021a10();
    }
    SetLastError(DVar2);
    if (((local_2e != '\0') && (local_24 != 0)) || ((local_2d != '\0' && (local_24 = local_22, local_22 != 0)))) {
      *param_1 = local_24;
    }
    if ((local_2c != '\0') && (local_20 != 0)) {
      *param_2 = local_20;
    }
  }
  local_8 = 0xffffffff;
  FUN_10028b40(local_54);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)(local_54 + 0x14));
  return;
}


// ----- callee: FUN_100219f0 @ 100219f0

void __cdecl FUN_100219f0(int param_1,wchar_t *param_2,int param_3)

{
  FUN_100223d0(&DAT_100d9220,param_1,param_2,param_3);
  return;
}


// ----- callee: FUN_100292d0 @ 100292d0

void __fastcall FUN_100292d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  void *local_8;
  
  puStack_c = &LAB_1009b973;
  local_10 = ExceptionList;
  local_14 = DAT_100d6b20 ^ (uint)(local_30 + 0xb);
  ExceptionList = &local_10;
  *param_1 = Configuration::vftable;
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  local_8 = (void *)0x0;
  param_1[1] = 0;
  puVar1 = (undefined4 *)FUN_100291e0((undefined2 *)local_30);
  local_8 = (void *)CONCAT31(local_8._1_3_,1);
  FUN_1000ae10(param_1 + 2,puVar1);
  if (7 < local_1c) {
    FUN_1002ed1e(local_30[0]);
  }
  *(undefined2 *)((int)param_1 + 0x3a) = 0;
  *param_1 = CommonConfiguration::vftable;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined2 *)((int)param_1 + 0x2e) = 0x100;
  *(undefined1 *)(param_1 + 0xf) = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)(local_30 + 0xb));
  return;
}


// ----- callee: FUN_10028b40 @ 10028b40

void __fastcall FUN_10028b40(undefined4 *param_1)

{
  *param_1 = Configuration::vftable;
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
    param_1[1] = 0;
  }
  if (7 < (uint)param_1[7]) {
    FUN_1002ed1e((void *)param_1[2]);
  }
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}


// ----- callee: FUN_10021a20 @ 10021a20

void __cdecl FUN_10021a20(wchar_t *param_1,char param_2)

{
  wchar_t *_Dst;
  int iVar1;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_100d6b20 ^ 0x100d2fa0;
  ExceptionList = &local_14;
  _Dst = (wchar_t *)FUN_10021ea0(0x100d9220);
  if (_Dst != (wchar_t *)0x0) {
    _memset(_Dst,0,0x2000);
    local_8 = 0;
    iVar1 = FID_conflict___vscprintf_p(param_1,&param_2);
    if ((iVar1 + 1 < 0x1001) && (_vswprintf_s(_Dst,0xfff,param_1,&param_2), iVar1 + 1 < 0x1001)) {
      FUN_100238f0(&DAT_100d9220,1);
    }
  }
  ExceptionList = local_14;
  return;
}


// ----- callee: __security_check_cookie @ 1002fc1a

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 != DAT_100d6b20) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_10028590 @ 10028590

void __fastcall FUN_10028590(int param_1)

{
  WCHAR WVar1;
  ushort uVar2;
  DWORD dwErrCode;
  int iVar3;
  BOOL BVar4;
  ulong uVar5;
  LPCWSTR pWVar6;
  WCHAR *pWVar7;
  char unaff_DI;
  bool bVar8;
  WCHAR local_408;
  undefined1 local_406 [1022];
  undefined4 local_8;
  
  local_8 = DAT_100d6b20 ^ (uint)(local_406 + 0x402);
  dwErrCode = GetLastError();
  iVar3 = FUN_100219f0(3,L"configfile.cpp",0x137);
  if (iVar3 != 0) {
    FUN_10021a20(L"CommonConfiguration: start to Load\n",unaff_DI);
    FUN_10021a10();
  }
  SetLastError(dwErrCode);
  if (*(uint *)(param_1 + 0x1c) < 8) {
    pWVar6 = (LPCWSTR)(param_1 + 8);
  }
  else {
    pWVar6 = *(LPCWSTR *)(param_1 + 8);
  }
  BVar4 = PathFileExistsW(pWVar6);
  if (BVar4 == 0) {
    *(undefined4 *)(param_1 + 0x26) = 0;
    *(undefined1 *)(param_1 + 0x2a) = 0;
    *(undefined1 *)(param_1 + 0x25) = 0;
    *(undefined1 *)(param_1 + 0x3c) = 0;
    __security_check_cookie(local_8 ^ (uint)(local_406 + 0x402));
    return;
  }
  local_408 = L'\0';
  if (*(uint *)(param_1 + 0x1c) < 8) {
    pWVar6 = (LPCWSTR)(param_1 + 8);
  }
  else {
    pWVar6 = *(LPCWSTR *)(param_1 + 8);
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"VNIC_MTU",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x26) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x30) = uVar2;
    if ((uVar2 < 0x240) || (0x5c0 < uVar2)) {
      *(undefined1 *)(param_1 + 0x26) = 0;
    }
  }
  local_408 = L'\0';
  pWVar6 = (LPCWSTR)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"Proxy_Profix_Value",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x3c) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x3e) = uVar2;
    if ((uVar2 < 2) || (3 < uVar2)) {
      *(undefined1 *)(param_1 + 0x3c) = 0;
    }
  }
  local_408 = L'\0';
  pWVar6 = (LPCWSTR)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"VNIC_DTLS_MTU",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x27) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x32) = uVar2;
    if ((uVar2 < 0x240) || (0x5c0 < uVar2)) {
      *(undefined1 *)(param_1 + 0x27) = 0;
    }
  }
  local_408 = L'\0';
  pWVar6 = (LPCWSTR)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"VNIC_TCP_ACK_Frequency",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x28) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x34) = uVar2;
    if ((uVar2 == 0) || (0x20 < uVar2)) {
      *(undefined1 *)(param_1 + 0x28) = 0;
    }
  }
  local_408 = L'\0';
  pWVar6 = (LPCWSTR)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"Virtual_DNS_Timeout",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x29) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x36) = uVar2;
    if ((uVar2 < 100) || (3000 < uVar2)) {
      *(undefined1 *)(param_1 + 0x29) = 0;
    }
  }
  pWVar6 = (LPCWSTR)(param_1 + 8);
  local_408 = L'\0';
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"Local_DNS_Timeout",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x2a) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    uVar2 = (ushort)uVar5;
    *(ushort *)(param_1 + 0x38) = uVar2;
    if ((uVar2 < 100) || (3000 < uVar2)) {
      *(undefined1 *)(param_1 + 0x2a) = 0;
    }
  }
  local_408 = L'\0';
  pWVar6 = (LPCWSTR)(param_1 + 8);
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"Local_Subnet_Access",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x25) = bVar8;
  if (bVar8) {
    iVar3 = __wcsicmp(&local_408,L"true");
    *(bool *)(param_1 + 0x24) = iVar3 == 0;
  }
  pWVar6 = (LPCWSTR)(param_1 + 8);
  local_408 = L'\0';
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"L3VPNTunnelDispatchRule",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x2b) = bVar8;
  if (bVar8) {
    uVar5 = FID_conflict___wcstoul_l(&local_408,(wchar_t **)0x0,10);
    *(ushort *)(param_1 + 0x3a) = (ushort)uVar5;
    if (4 < (ushort)uVar5) {
      *(undefined1 *)(param_1 + 0x2b) = 0;
    }
  }
  pWVar6 = (LPCWSTR)(param_1 + 8);
  local_408 = L'\0';
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"IPsec_Over_SSL",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x2c) = bVar8;
  if (bVar8) {
    iVar3 = __wcsicmp(&local_408,L"true");
    *(bool *)(param_1 + 0x2d) = iVar3 == 0;
  }
  pWVar6 = (LPCWSTR)(param_1 + 8);
  local_408 = L'\0';
  if (7 < *(uint *)(param_1 + 0x1c)) {
    pWVar6 = *(LPCWSTR *)pWVar6;
  }
  GetPrivateProfileStringW(L"Global_Configuration",L"TLSV_12",L"",&local_408,0x200,pWVar6);
  pWVar7 = &local_408;
  do {
    WVar1 = *pWVar7;
    pWVar7 = pWVar7 + 1;
  } while (WVar1 != L'\0');
  bVar8 = (int)pWVar7 - (int)local_406 >> 1 != 0;
  *(bool *)(param_1 + 0x2e) = bVar8;
  if (bVar8) {
    iVar3 = __wcsicmp(&local_408,L"true");
    *(bool *)(param_1 + 0x2f) = iVar3 == 0;
    __security_check_cookie(local_8 ^ (uint)(local_406 + 0x402));
    return;
  }
  *(undefined1 *)(param_1 + 0x2f) = 1;
  __security_check_cookie(local_8 ^ (uint)(local_406 + 0x402));
  return;
}


// ----- callee: KERNEL32.DLL::GetLastError @ EXTERNAL:0000002c
// decompile failed: Exception while decompiling EXTERNAL:0000002c: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::SetLastError @ EXTERNAL:0000000f
// decompile failed: Exception while decompiling EXTERNAL:0000000f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_10021a10 @ 10021a10

void FUN_10021a10(void)

{
  FUN_10021e80(0x100d9220);
  return;
}


