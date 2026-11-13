// decompiled by DumpAnchors for program: vl3vpn.dll

// ===================== FUN_100640d0 @ 100640d0  anchors: [send_tcp_tunnel_keep_alive(win@100f3b78), send_tcp_tunnel_keep_alive(win@100f3bc8), send_tcp_tunnel_keep_alive(win@100f3c28), send_tcp_tunnel_keep_alive(win@100f3c70), send_tcp_tunnel_keep_alive(win@100f3cc0), send_tcp_tunnel_keep_alive(win@100f3d10), send_tcp_tunnel_keep_alive(win@100f3d28), send_tcp_tunnel_keep_alive(win@100f3d7c), send_tcp_tunnel_keep_alive(win@100f3d90), send_tcp_tunnel_keep_alive(win@100f3da8), send_tcp_tunnel_keep_alive(win@100f3dfc)] =====================

void FUN_100640d0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  LSTATUS LVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  SOCKET *in_ECX;
  SOCKET SVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  char *pcVar17;
  SOCKET SVar18;
  undefined1 auStack_3b4 [4];
  SOCKET *local_3b0;
  int local_3ac;
  SOCKET local_3a8;
  SOCKET local_3a4;
  int local_3a0;
  uint local_39c;
  int local_398;
  int local_394;
  int local_390;
  undefined4 local_38c;
  uint local_388;
  DWORD DStack_384;
  int local_380;
  undefined4 local_37c;
  uint local_378;
  undefined4 local_374;
  DWORD DStack_370;
  uint local_36c;
  int local_368;
  uint local_364;
  DWORD local_360;
  int iStack_35c;
  int local_358;
  int iStack_354;
  DWORD local_350;
  int iStack_34c;
  DWORD local_348;
  DWORD local_344;
  DWORD local_340;
  DWORD DStack_33c;
  DWORD local_338;
  timeval local_334;
  int local_32c;
  fd_set local_328;
  CHAR CStack_220;
  undefined1 auStack_21f [263];
  CHAR CStack_118;
  undefined1 auStack_117 [267];
  uint local_c;
  
  local_c = DAT_101052f0 ^ (uint)auStack_3b4;
  local_3a0 = *in_ECX + 1;
  DAT_1011eccc = 0;
  local_37c = 1;
  local_374 = 1;
  DAT_1011ecbc = 0;
  local_358 = 0;
  local_340 = 4;
  local_350 = 4;
  local_3b0 = in_ECX;
  SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Install Manager","EnablePrintRequest",&local_340,&local_358,&local_350);
  SVar11 = local_3b0[0x1678];
  if ((int)SVar11 < 0x3d) {
    if ((int)SVar11 < 1) {
      SVar11 = 0x1e;
    }
  }
  else {
    SVar11 = 0x3c;
  }
  local_3a4 = 0;
  local_344 = 4;
  local_360 = 4;
  local_3a8 = SVar11;
  LVar7 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Keepalive","SendInterval",&local_344,&local_3a4,&local_360);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x54c,"Get keep alive SendInterval from reg: [%d], dwRet: [%d]\n",
                       local_3a4,LVar7);
  }
  if (LVar7 == 0) {
    if (local_3a4 - 1 < 0x3c) {
      SVar11 = local_3a4;
    }
    local_3a8 = SVar11;
  }
  iVar13 = 3;
  local_398 = 3;
  local_394 = 0;
  local_338 = 4;
  local_3b0[0x10] = 0;
  local_348 = 4;
  LVar7 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Keepalive","AttemptMaxTimes",&local_338,&local_394,&local_348);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x558,"Get keep alive KeepAliveAttempts from reg: [%d], dwRet: [%d]\n",
                       local_394,LVar7);
  }
  if (LVar7 == 0) {
    if (local_394 - 1U < 300) {
      iVar13 = local_394;
    }
    local_398 = iVar13;
  }
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x55f,"select_loop: keep alive interval: [%d], KeepAliveAttempts: [%d]\n",
                       SVar11,iVar13);
  }
  uVar15 = FUN_10092e28(0);
  uVar3 = CONCAT44(local_3ac,local_39c);
  local_388 = (uint)uVar15;
  SVar11 = local_3b0[0x10];
  local_36c = local_388;
  uVar1 = uVar15;
  uVar2 = uVar15;
  uVar4 = uVar15;
  uVar5 = uVar15;
  do {
    if (SVar11 != 0) {
LAB_10064a81:
      local_3ac = (int)((ulonglong)uVar3 >> 0x20);
      local_39c = (uint)uVar3;
      local_380 = (int)((ulonglong)uVar2 >> 0x20);
      local_378 = (uint)uVar2;
      local_38c = (int)((ulonglong)uVar1 >> 0x20);
      local_388 = (uint)uVar1;
      local_368 = (int)((ulonglong)uVar15 >> 0x20);
      local_364 = (uint)uVar15;
      local_3a4 = 0;
      LVar7 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","tun_device_thread_exit",4,&local_3a4,4);
      if ((DAT_10106410 < 2) &&
         (array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x616,
                             "select_loop: SHSetValueA: set HKCU VPN-VPN2-tun_device_thread_exit to 0, iRet = %d\n",
                             LVar7), DAT_10106410 < 2)) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x618,
                           "select loop thread exit, l3vpn addr:%x, l3vpn->sess.error: %d\n",&local_3b0,local_3b0[0x11])
        ;
      }
      FUN_1008fc07();
      return;
    }
    local_38c = (int)((ulonglong)uVar5 >> 0x20);
    local_378 = (uint)uVar5;
    local_380 = (int)((ulonglong)uVar4 >> 0x20);
    local_36c = (uint)uVar4;
    uVar3 = CONCAT44(local_3ac,local_39c);
    local_368 = (int)((ulonglong)uVar15 >> 0x20);
    local_364 = (uint)uVar15;
    uVar6 = local_364;
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    if (local_3b0[0x11] != 0) goto LAB_10064a81;
    local_328.fd_array[0] = *local_3b0;
    local_328.fd_count = 1;
    if (local_3b0[0x1a02] != 0) {
      iVar13 = 0;
      do {
        if (local_328.fd_array[iVar13] == local_3b0[0x14e8]) break;
        iVar13 = iVar13 + 1;
      } while (iVar13 == 0);
      if (iVar13 == 1) {
        local_328.fd_count = 2;
        local_328.fd_array[1] = local_3b0[0x14e8];
      }
      if (local_3a0 <= (int)local_3b0[0x14e8]) {
        local_3a0 = local_3b0[0x14e8] + 1;
      }
    }
    local_334.tv_sec = 1;
    local_334.tv_usec = 0;
    iVar13 = select(local_3a0,&local_328,(fd_set *)0x0,(fd_set *)0x0,&local_334);
    uVar3 = CONCAT44(local_3ac,local_39c);
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    uVar15 = CONCAT44(local_368,local_364);
    if (local_3b0[0x11] != 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x573,
                           "after select, detect sess is error status, break select loop thread.\n");
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
      }
      goto LAB_10064a81;
    }
    if (iVar13 < 0) {
      if (DAT_10106410 < 3) {
        piVar9 = __errno();
        piVar10 = __errno();
        uVar16 = FUN_1009324b(*piVar9,local_3b0[0x11]);
        array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x578,
                           "vpn thread select failed, ret %d, error %u(%s), vpn session error: %d\n",iVar13,*piVar10,
                           uVar16);
      }
      uVar3 = CONCAT44(local_3ac,local_39c);
      uVar2 = CONCAT44(local_380,local_378);
      uVar1 = CONCAT44(local_38c,local_388);
      uVar15 = CONCAT44(local_368,local_364);
      local_3b0[0x11] = 0x1d;
      goto LAB_10064a81;
    }
    if (local_3b0[0x10] != 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x57c,"vpn tunnel is interrupted, stop tunnel.\n");
      }
      uVar3 = CONCAT44(local_3ac,local_39c);
      uVar2 = CONCAT44(local_380,local_378);
      uVar1 = CONCAT44(local_38c,local_388);
      uVar15 = CONCAT44(local_368,local_364);
      local_3b0[0x11] = 0x29;
      goto LAB_10064a81;
    }
    uVar15 = FUN_10092e28(0);
    local_3ac = (int)((ulonglong)uVar15 >> 0x20);
    uVar14 = (uint)uVar15;
    local_390 = uVar14 - uVar6;
    if (local_3b0[0x1a02] == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = uVar14 - local_388;
    }
    local_39c = uVar14;
    if ((iVar13 == 0) || ((0 < iVar13 && (local_3b0[0x1a02] != 0)))) {
      if ((local_3b0[0x940] == 2) || (local_3b0[0x940] == 6)) {
        if ((iVar13 == 0) && (DAT_1011e8a8 == 1)) {
          iVar8 = FUN_10058240();
          uVar15 = CONCAT44(local_3ac,local_39c);
          if ((iVar8 == 0xb) || (((iVar8 == 0xc || (iVar8 == 0xd)) || (iVar8 == 0xe)))) {
            if (DAT_10106410 < 3) {
              pcVar17 = "It seems the wg status is SWG_STATUS_RECONNECTING, we have to reconnect VPN\n";
              uVar16 = 0x5a6;
LAB_10064873:
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17);
            }
LAB_10064882:
            uVar3 = CONCAT44(local_3ac,local_39c);
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            DAT_1011e8a8 = 2;
            local_3b0[0x11] = 0x86;
            goto LAB_10064a81;
          }
          local_32c = iVar13;
          if ((code *)local_3b0[0x992] != (code *)0x0) {
            iVar8 = (*(code *)local_3b0[0x992])(0x2d,0,0,0,0,0);
            uVar15 = CONCAT44(local_3ac,local_39c);
            if (iVar8 != 0) {
              if (DAT_10106410 < 3) {
                pcVar17 = "It seems the wg process is not exist, we have to reconnect\n";
                uVar16 = 0x5af;
                goto LAB_10064873;
              }
              goto LAB_10064882;
            }
          }
        }
        local_3ac = (int)((ulonglong)uVar15 >> 0x20);
        local_39c = (uint)uVar15;
        uVar3 = uVar15;
        if ((local_3b0[0x1a02] != 0) && ((int)local_3a8 <= iVar12)) {
          iVar8 = (local_3ac - local_380) - (uint)(uVar14 < local_36c);
          if (((int)local_3a8 >> 0x1f <= iVar8) &&
             (((int)local_3a8 >> 0x1f < iVar8 || (local_3a8 <= uVar14 - local_36c)))) {
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x5ba,
                                 "select_loop: UDP tunnel %d seconds no response from AG, send UDP keepalive(send times:%d).\n"
                                 ,uVar14 - local_36c,iVar8,DAT_1011eccc);
              uVar15 = CONCAT44(local_3ac,local_39c);
            }
            iVar8 = DAT_1011eccc;
            local_3ac = (int)((ulonglong)uVar15 >> 0x20);
            local_39c = (uint)uVar15;
            DStack_384 = 0;
            DStack_33c = 1;
            if (DAT_1011eccc != 0) {
              DStack_384 = GetTickCount();
              uVar15 = CONCAT44(local_3ac,local_39c);
            }
            local_3ac = (int)((ulonglong)uVar15 >> 0x20);
            local_39c = (uint)uVar15;
            CStack_220 = '\0';
            FUN_10093d10(auStack_21f,0,0x103);
            FUN_1008fdb3(&CStack_220,"SOFTWARE\\VPN\\Keepalive\\L3UDPTunnel");
            iStack_35c = iVar8;
            SHSetValueA((HKEY)0x80000001,&CStack_220,"Running",4,&DStack_33c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_220,"SendTimes",4,&iStack_35c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_220,"TimeofLatestSend",4,&DStack_384,4);
            FUN_10063f70();
            DAT_1011eccc = DAT_1011eccc + 1;
            local_36c = local_39c;
            local_380 = local_3ac;
            uVar3 = CONCAT44(local_3ac,local_39c);
          }
          local_3ac = (int)((ulonglong)uVar3 >> 0x20);
          local_39c = (uint)uVar3;
          uVar14 = local_39c;
          if ((int)(local_398 * local_3a8) <= iVar12) {
            if (DAT_10106410 < 3) {
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x5c2,
                                 "select_loop: UDP tunnel %d seconds no response from AG, will reconnect VPN\n",iVar12);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            local_3b0[0x11] = 0x79;
            *(undefined1 *)((int)local_3b0 + 0x5197) = 1;
            goto LAB_10064a81;
          }
        }
        local_3ac = (int)((ulonglong)uVar3 >> 0x20);
        local_39c = (uint)uVar3;
        uVar15 = CONCAT44(local_3ac,uVar14);
        if ((int)local_3a8 <= local_390) {
          iVar12 = (local_3ac - local_368) - (uint)(uVar14 < local_378);
          if (((int)local_3a8 >> 0x1f <= iVar12) &&
             (((int)local_3a8 >> 0x1f < iVar12 || (local_3a8 <= uVar14 - local_378)))) {
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x5cd,
                                 "select_loop: TCP tunnel %d seconds no response from AG, send TCP keepalive(send times:%d).\n"
                                 ,uVar14 - local_378,iVar12,DAT_1011ecbc);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            iVar13 = DAT_1011ecbc;
            local_3ac = (int)((ulonglong)uVar3 >> 0x20);
            local_39c = (uint)uVar3;
            DStack_370 = 0;
            iStack_354 = 1;
            if (DAT_1011ecbc != 0) {
              DStack_370 = GetTickCount();
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            local_3ac = (int)((ulonglong)uVar3 >> 0x20);
            local_39c = (uint)uVar3;
            CStack_118 = '\0';
            FUN_10093d10(auStack_117,0,0x103);
            FUN_1008fdb3(&CStack_118,"SOFTWARE\\VPN\\Keepalive\\L3TCPTunnel");
            iStack_34c = iVar13;
            SHSetValueA((HKEY)0x80000001,&CStack_118,"Running",4,&iStack_354,4);
            SHSetValueA((HKEY)0x80000001,&CStack_118,"SendTimes",4,&iStack_34c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_118,"TimeofLatestSend",4,&DStack_370,4);
            SVar11 = FUN_10063d70();
            iVar13 = DAT_10106410;
            uVar3 = CONCAT44(local_3ac,local_39c);
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            if (SVar11 != 0) {
              local_3b0[0x11] = SVar11;
              if (iVar13 < 4) {
                array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x5d9,
                                   "It seems send_tcp_tunnel_keep_alive failed, return tunnel error %d\n",SVar11);
                uVar3 = CONCAT44(local_3ac,local_39c);
                uVar2 = CONCAT44(local_380,local_378);
                uVar1 = CONCAT44(local_38c,local_388);
                uVar15 = CONCAT44(local_368,local_364);
              }
              goto LAB_10064a81;
            }
            DAT_1011ecbc = DAT_1011ecbc + 1;
            local_368 = local_3ac;
            iVar13 = 0;
            local_378 = uVar14;
          }
          local_3ac = (int)((ulonglong)uVar3 >> 0x20);
          local_39c = (uint)uVar3;
          uVar15 = CONCAT44(local_3ac,uVar14);
          if ((int)(local_398 * local_3a8) <= local_390) {
            if (DAT_10106410 < 3) {
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x5e1,
                                 "select_loop: TCP tunnel %d seconds no response from AG, will reconnect VPN\n",
                                 local_390);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            local_3b0[0x11] = 0x32;
            goto LAB_10064a81;
          }
        }
      }
      local_3ac = (int)((ulonglong)uVar15 >> 0x20);
      if (iVar13 != 0) goto LAB_10064760;
    }
    else {
LAB_10064760:
      local_3ac = (int)((ulonglong)uVar15 >> 0x20);
      SVar11 = *local_3b0;
      if ((SVar11 == 0xffffffff) || (local_3b0[0x10] != 0)) {
        if (DAT_10106410 < 2) {
          SVar18 = local_3b0[0x10];
          pcVar17 = "vpn tunnel is interrupted, stop tunnel, fd:%d, l3vpn->sess.manually_stop:%d\n";
          uVar16 = 0x5f0;
LAB_1006498b:
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17,SVar11,SVar18);
        }
LAB_1006499a:
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
        local_3b0[0x11] = 0x29;
        goto LAB_10064a81;
      }
      iVar13 = __WSAFDIsSet(SVar11,&local_328);
      if (iVar13 != 0) {
        SVar11 = FUN_10063130();
        local_37c = 0;
        if (SVar11 == 0) {
          local_38c = local_3ac;
          DAT_1011ecbc = 0;
          local_364 = (uint)uVar15;
          goto LAB_100647c2;
        }
        if (DAT_10106410 < 4) {
          pcVar17 = "ssl tunnel error %d\n";
          uVar16 = 0x5f8;
LAB_10064954:
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17,SVar11);
        }
LAB_10064963:
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
        local_3b0[0x11] = SVar11;
        goto LAB_10064a81;
      }
LAB_100647c2:
      iVar13 = local_3ac;
      SVar11 = local_3b0[0x14e8];
      if (local_3b0[0x1a02] != 0) {
        if ((SVar11 == 0xffffffff) || (local_3b0[0x10] != 0)) {
          if (DAT_10106410 < 2) {
            SVar18 = local_3b0[0x10];
            pcVar17 = "vpn udp tunnel is interrupted, stop tunnel, fd:%d, l3vpn->sess.manually_stop:%d\n";
            uVar16 = 0x602;
            goto LAB_1006498b;
          }
          goto LAB_1006499a;
        }
        if (local_3b0[0x1a02] != 0) {
          iVar12 = __WSAFDIsSet(SVar11,&local_328);
          if (iVar12 != 0) {
            SVar11 = FUN_10062c70();
            local_374 = 0;
            if (SVar11 != 0) {
              if (DAT_10106410 < 4) {
                pcVar17 = "udp tunnel error %d";
                uVar16 = 0x60a;
                goto LAB_10064954;
              }
              goto LAB_10064963;
            }
            DAT_1011eccc = 0;
            local_38c = iVar13;
            local_388 = (uint)uVar15;
          }
        }
      }
    }
    uVar5 = CONCAT44(local_38c,local_378);
    uVar4 = CONCAT44(local_380,local_36c);
    uVar3 = CONCAT44(local_3ac,local_39c);
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    uVar15 = CONCAT44(local_368,local_364);
    SVar11 = local_3b0[0x10];
  } while( true );
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


// ----- callee: FUN_10058240 @ 10058240

void FUN_10058240(void)

{
  DWORD local_118 [3];
  CHAR local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_10b + 0x107);
  local_10c = '\0';
  FUN_10093d10(local_10b,0,0x103);
  local_118[0] = 4;
  local_118[2] = 0;
  local_118[1] = 4;
  FUN_1008fdb3(&local_10c,"SOFTWARE\\VPN\\AWG");
  SHGetValueA((HKEY)0x80000002,&local_10c,"status",local_118,local_118 + 2,local_118 + 1);
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


// ----- callee: __errno @ 100908cb

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2012 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_10105058;
  }
  return &p_Var1->_terrno;
}


// ----- callee: KERNEL32.DLL::GetTickCount @ EXTERNAL:000000ee
// decompile failed: Exception while decompiling EXTERNAL:000000ee: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_10063130 @ 10063130

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10063130(void)

{
  u_short uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int in_EDX;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  undefined1 local_11c [136];
  undefined1 local_94 [140];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_94 + 0x90);
  if (in_EDX != 0) {
    DAT_1011ecb8 = 0;
  }
  iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x34),&DAT_10130190 + DAT_1011ecb8,0x10000 - (uint)DAT_1011ecb8);
  if (*(int *)(in_ECX + 0x40) != 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0x29;
    FUN_1008fc07();
    return;
  }
  if (iVar2 < 1) {
    uVar3 = SSL_get_error(*(undefined4 *)(in_ECX + 0x34),iVar2);
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x35b,"handle ssl tunnel, SSL read failed, error %d, SSL error %d.\n",
                         iVar2,uVar3);
    }
    DAT_1011ecb8 = 0;
    FUN_1008fc07();
    return;
  }
  _DAT_1011ecb0 = 0;
  if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x36b,"handel ssl tunnel, recv %d bytes\n",iVar2);
  }
  FUN_100650d0(iVar2,iVar2 >> 0x1f);
  pcVar6 = ntohs_exref;
  DAT_1011ecb8 = DAT_1011ecb8 + (short)iVar2;
  if (DAT_1011ecb8 < 0x14) {
    if (DAT_10106410 < 1) {
      array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x372,"recv bytes (%d) < ipheader size\n",DAT_1011ecb8);
      FUN_1008fc07();
      return;
    }
  }
  else {
    if ((DAT_10130190 & 0xf0) == 0x60) {
      uVar1 = ntohs(DAT_10130194);
      if ((uint)DAT_1011ecb8 < uVar1 + 0x28) {
        if (DAT_10106410 < 1) {
          uVar1 = ntohs(DAT_10130194);
          array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x378,"recv bytes (%d) < ip6 packet size(%d)\n",DAT_1011ecb8,
                             uVar1 + 0x28);
          FUN_1008fc07();
          return;
        }
        goto LAB_10063630;
      }
    }
    else {
      uVar1 = ntohs(DAT_10130192);
      if (DAT_1011ecb8 < uVar1) {
        if (DAT_10106410 < 1) {
          uVar1 = ntohs(DAT_10130192);
          array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x37d,"recv bytes (%d) < ip packet size(%d)\n",DAT_1011ecb8,uVar1);
          FUN_1008fc07();
          return;
        }
        goto LAB_10063630;
      }
    }
    uVar4 = 0;
    if (DAT_1011ecb8 != 0) {
      uVar5 = uVar4;
      while( true ) {
        if (((&DAT_10130190)[uVar5] & 0xf0) == 0x60) {
          uVar4 = (*pcVar6)(*(undefined2 *)((int)&DAT_10130194 + uVar5));
          uVar7 = (uVar4 & 0xffff) + 0x28;
        }
        else {
          uVar7 = (*pcVar6)(*(undefined2 *)((int)&DAT_10130192 + uVar5));
          uVar7 = uVar7 & 0xffff;
        }
        if (uVar7 == 0) {
          if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x38e,
                               "leave partial ip packet: index:%d, offset:%d, new_offser:%d\n",uVar5,(uint)DAT_1011ecb8,
                               DAT_1011ecb8 - uVar5);
          }
          FUN_10091050(&DAT_10130190,&DAT_10130190 + uVar5,DAT_1011ecb8 - uVar5);
          DAT_1011ecb8 = DAT_1011ecb8 - (short)uVar5;
          FUN_1008fc07();
          return;
        }
        uVar4 = uVar7 + uVar5;
        if ((int)(uint)DAT_1011ecb8 < (int)uVar4) {
          if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x397,
                               "leave partial ip packet: index:%d, offset:%d, new_offser:%d\n",uVar5,(uint)DAT_1011ecb8,
                               DAT_1011ecb8 - uVar5);
          }
          FUN_10091050(&DAT_10130190,&DAT_10130190 + uVar5,DAT_1011ecb8 - uVar5);
          DAT_1011ecb8 = DAT_1011ecb8 - (short)uVar5;
          FUN_1008fc07();
          return;
        }
        if ((&DAT_10130199)[uVar5] == -1) {
          iVar2 = FUN_10062270(0);
          if (iVar2 != 0) goto LAB_10063630;
        }
        else {
          if (((&DAT_10130190)[uVar5] & 0xf0) == 0x60) {
            inet_ntop(0x17,&DAT_10130198 + uVar5,local_94,0x88);
            inet_ntop(0x17,&DAT_101301a8 + uVar5,local_11c,0x88);
            if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x3ae,"read %d bytes from ssl tunnel, %s --> %s\n",uVar7,
                                 local_94,local_11c);
            }
          }
          else if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x3b4,
                               "read %d bytes from ssl tunnel, %d.%d.%d.%d --> %d.%d.%d.%d\n",uVar7,
                               *(undefined1 *)(uVar5 + 0x1013019c),*(undefined1 *)(uVar5 + 0x1013019d),
                               *(undefined1 *)(uVar5 + 0x1013019e),*(undefined1 *)(uVar5 + 0x1013019f),
                               *(undefined1 *)(uVar5 + 0x101301a0),*(undefined1 *)(uVar5 + 0x101301a1),
                               *(undefined1 *)(uVar5 + 0x101301a2),*(undefined1 *)(uVar5 + 0x101301a3));
          }
          iVar2 = FUN_10062bd0(uVar7);
          if (iVar2 < 1) {
            DAT_1011ecb8 = 0;
            FUN_1008fc07();
            return;
          }
        }
        if ((int)(uint)DAT_1011ecb8 <= (int)uVar4) break;
        uVar5 = uVar4;
        pcVar6 = ntohs_exref;
      }
    }
    if (uVar4 == DAT_1011ecb8) {
      DAT_1011ecb8 = 0;
    }
  }
LAB_10063630:
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10062c70 @ 10062c70

void FUN_10062c70(void)

{
  u_short uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int in_EDX;
  code *pcVar6;
  int local_138;
  uint local_134;
  sockaddr local_12c;
  undefined1 local_11c [136];
  undefined1 local_94 [140];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_94 + 0x90);
  local_138 = 0x10;
  if (in_EDX != 0) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x2e4,"handel udp tunnel, first call, offset %d\n",DAT_1011e8ac);
    }
    DAT_1011e8ac = 0;
  }
  uVar5 = (uint)DAT_1011e8ac;
  if (*(int *)(in_ECX + 0x59c8) == 0) {
    iVar2 = recvfrom(*(SOCKET *)(in_ECX + 0x53a0),(char *)(&DAT_10120190 + uVar5),0x10000 - uVar5,0,&local_12c,
                     &local_138);
  }
  else {
    iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x59d0),&DAT_10120190 + uVar5,0x10000 - uVar5);
  }
  if (iVar2 < 1) {
    if (DAT_10106410 < 4) {
      piVar3 = __errno();
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x2ee,"handel udp tunnel, read failed, error %d\n",*piVar3);
    }
    FUN_1007dbd0();
    FUN_100629c0();
    FUN_1008fc07();
    return;
  }
  if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x2f6,"handel udp tunnel, recv %d bytes\n",iVar2);
  }
  FUN_100650d0(iVar2,iVar2 >> 0x1f);
  if ((*(int *)(in_ECX + 0x59c8) == 0) && (*(int *)(in_ECX + 0x53ac) != 0)) {
    FUN_100481a0(iVar2);
  }
  pcVar6 = ntohs_exref;
  DAT_1011e8ac = DAT_1011e8ac + (short)iVar2;
  if (DAT_1011e8ac < 0x14) {
    if (DAT_10106410 < 1) {
      array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x301,"handel udp tunnel: recv bytes < ipheader size\n");
      FUN_1008fc07();
      return;
    }
  }
  else {
    if ((DAT_10120190 & 0xf0) == 0x60) {
      uVar1 = ntohs(DAT_10120194);
      if ((uint)DAT_1011e8ac < uVar1 + 0x28) {
        if (DAT_10106410 < 1) {
          uVar1 = ntohs(DAT_10120194);
          array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x308,"handle udp tunnel: recv bytes(%d) < ip packet size(%d)\n",
                             DAT_1011e8ac,uVar1 + 0x28);
          FUN_1008fc07();
          return;
        }
        goto LAB_1006311d;
      }
    }
    else {
      uVar1 = ntohs(DAT_10120192);
      if (DAT_1011e8ac < uVar1) {
        if (DAT_10106410 < 1) {
          array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x30d,"handel udp tunnel: recv bytes < ip packet size\n");
          FUN_1008fc07();
          return;
        }
        goto LAB_1006311d;
      }
    }
    uVar5 = 0;
    if (DAT_1011e8ac != 0) {
      while( true ) {
        if (((&DAT_10120190)[uVar5] & 0xf0) == 0x60) {
          uVar4 = (*pcVar6)(*(undefined2 *)((int)&DAT_10120194 + uVar5));
          uVar4 = (uVar4 & 0xffff) + 0x28;
        }
        else {
          uVar4 = (*pcVar6)(*(undefined2 *)((int)&DAT_10120192 + uVar5));
          uVar4 = uVar4 & 0xffff;
        }
        local_134 = uVar4 + uVar5;
        if ((int)(uint)DAT_1011e8ac < (int)local_134) {
          if (DAT_10106410 < 1) {
            array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0x31a,"leave partial ip packet\n");
          }
          FUN_10091050(&DAT_10120190,&DAT_10120190 + uVar5,DAT_1011e8ac - uVar5);
          DAT_1011e8ac = DAT_1011e8ac - (short)uVar5;
          FUN_1008fc07();
          return;
        }
        if ((&DAT_10120199)[uVar5] == -1) {
          iVar2 = FUN_10062270(1);
          if (iVar2 != 0) goto LAB_1006311d;
        }
        else {
          if (((&DAT_10120190)[uVar5] & 0xf0) == 0x60) {
            inet_ntop(0x17,&DAT_10120198 + uVar5,local_94,0x88);
            inet_ntop(0x17,&DAT_101201a8 + uVar5,local_11c,0x88);
            if ((DAT_1011ecc4 == 1) && (DAT_10106410 < 2)) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x332,"read %d bytes from udp tunnel, %s --> %s\n",uVar4,
                                 local_94,local_11c);
            }
          }
          else if ((DAT_1011ecc4 == 1) && (DAT_10106410 < 2)) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x338,
                               "read %d bytes from udp tunnel, %d.%d.%d.%d --> %d.%d.%d.%d\n",uVar4,
                               *(undefined1 *)(uVar5 + 0x1012019c),*(undefined1 *)(uVar5 + 0x1012019d),
                               *(undefined1 *)(uVar5 + 0x1012019e),*(undefined1 *)(uVar5 + 0x1012019f),
                               *(undefined1 *)(uVar5 + 0x101201a0),*(undefined1 *)(uVar5 + 0x101201a1),
                               *(undefined1 *)(uVar5 + 0x101201a2),*(undefined1 *)(uVar5 + 0x101201a3));
          }
          iVar2 = FUN_10062bd0(uVar4);
          if (iVar2 < 1) {
            FUN_1008fc07();
            return;
          }
        }
        uVar5 = local_134;
        if ((int)(uint)DAT_1011e8ac <= (int)local_134) break;
        pcVar6 = ntohs_exref;
      }
    }
    if (uVar5 == DAT_1011e8ac) {
      DAT_1011e8ac = 0;
    }
  }
LAB_1006311d:
  FUN_1008fc07();
  return;
}


// ----- callee: WS2_32.DLL::__WSAFDIsSet @ EXTERNAL:0000001f
// decompile failed: Exception while decompiling EXTERNAL:0000001f: Cannot marshal address space: EXTERNAL

// ----- callee: SHLWAPI.DLL::SHGetValueA @ EXTERNAL:0000011e
// decompile failed: Exception while decompiling EXTERNAL:0000011e: Cannot marshal address space: EXTERNAL

// ----- callee: SHLWAPI.DLL::SHSetValueA @ EXTERNAL:0000011f
// decompile failed: Exception while decompiling EXTERNAL:0000011f: Cannot marshal address space: EXTERNAL

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


// ----- callee: WS2_32.DLL::select @ EXTERNAL:00000016
// decompile failed: Exception while decompiling EXTERNAL:00000016: Cannot marshal address space: EXTERNAL

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


// ----- callee: FUN_10092e28 @ 10092e28

/* WARNING: Removing unreachable block (ram,0x10092e5d) */

void FUN_10092e28(longlong *param_1)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __aulldiv(local_c.dwLowDateTime + 0x2ac18000,
                    local_c.dwHighDateTime + 0xfe624e21 + (uint)(0xd53e7fff < local_c.dwLowDateTime),10000000,0);
  if (0x793406fff < lVar1) {
    lVar1 = -1;
  }
  if (param_1 != (longlong *)0x0) {
    *param_1 = lVar1;
  }
  return;
}


// ----- callee: FUN_1009324b @ 1009324b

char * FUN_1009324b(undefined4 param_1)

{
  _ptiddata p_Var1;
  char *pcVar2;
  char *_Src;
  errno_t eVar3;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    pcVar2 = "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  else {
    if (p_Var1->_errmsg == (char *)0x0) {
      pcVar2 = (char *)FUN_10096b51(0x86,1);
      p_Var1->_errmsg = pcVar2;
      if (pcVar2 == (char *)0x0) {
        return "Visual C++ CRT: Not enough memory to complete call to strerror.";
      }
    }
    pcVar2 = p_Var1->_errmsg;
    _Src = (char *)FUN_10093225(param_1);
    eVar3 = _strcpy_s(pcVar2,0x86,_Src);
    if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return pcVar2;
}



// ===================== FUN_100659b0 @ 100659b0  anchors: [send_tcp_tunnel_keep_alive(win@100f3d90)] =====================

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


// ----- caller: FUN_10066250 @ 10066250

/* WARNING: Removing unreachable block (ram,0x10067001) */

void FUN_10066250(int param_1)

{
  char cVar1;
  byte bVar2;
  int *_Memory;
  undefined4 uVar3;
  LSTATUS LVar4;
  uint uVar5;
  code *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  undefined8 uVar15;
  longlong lVar16;
  longlong lVar17;
  undefined4 uVar18;
  DWORD dwMilliseconds;
  undefined1 auStack_6d8 [4];
  int local_6d4;
  int local_6d0;
  uint local_6cc;
  int local_6c8;
  uint uStack_6c4;
  int iStack_6c0;
  uint uStack_6bc;
  int iStack_6b8;
  int iStack_6b4;
  int local_6b0;
  int iStack_6ac;
  undefined2 local_6a8;
  undefined1 local_6a6;
  int iStack_6a4;
  int iStack_6a0;
  int local_69c;
  undefined4 uStack_698;
  undefined4 local_694;
  int iStack_690;
  int iStack_68c;
  undefined4 uStack_688;
  undefined4 uStack_684;
  uint local_680;
  DWORD DStack_67c;
  DWORD DStack_678;
  DWORD DStack_674;
  DWORD DStack_670;
  undefined4 uStack_66c;
  undefined4 uStack_668;
  DWORD DStack_664;
  DWORD DStack_660;
  undefined4 local_65c;
  undefined4 local_658;
  undefined4 uStack_654;
  undefined4 uStack_650;
  undefined4 local_64c;
  undefined4 uStack_648;
  undefined4 uStack_644;
  undefined4 uStack_640;
  undefined4 uStack_63c;
  undefined4 uStack_638;
  undefined4 uStack_634;
  undefined4 uStack_630;
  byte local_618 [10];
  undefined1 local_60e [502];
  char local_418 [512];
  char local_218 [516];
  uint local_14;
  
  local_14 = DAT_101052f0 ^ (uint)auStack_6d8;
  local_6a8 = 0x2340;
  local_6d4 = param_1;
  local_69c = 0;
  local_6b0 = 0;
  local_6d0 = 0;
  local_65c = 0;
  local_658 = 0;
  local_6a6 = 0;
  local_6c8 = 0;
  local_680 = 0;
  local_6cc = 0;
  do {
    pcVar7 = (char *)(param_1 + 0x290);
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (pcVar7 == (char *)(param_1 + 0x291)) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x8f1,"vpn tunnel thread start do authentication, set thread flag.\n")
        ;
      }
      local_694 = 1;
      LVar4 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","SDKConnectThread",4,&local_694,4);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x6bd,
                           "set_connect_thread_flag: thread name:%s, dwRunning:%d,dwRet=%d\n","SDKConnectThread",
                           local_694,LVar4);
      }
    }
    GetCurrentThreadId();
    FUN_10071880();
    iVar9 = DAT_10106410;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined1 *)(param_1 + 0x5197) = 0;
    DAT_1011ecc0 = 0;
    if (iVar9 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x8fb,"vpn tunnel thread start, valid string:(%s), host:%s, domain:%s\n"
                         ,param_1 + 0x18f5,param_1 + 0x8c,param_1 + 0x18c);
    }
    pcVar7 = (char *)FUN_1009315e(param_1 + 0x18f5,&local_6a8);
    local_618[0] = 0;
    FUN_10093d10(local_618 + 1,0,0x1ff);
    local_418[0] = '\0';
    FUN_10093d10(local_418 + 1,0,0x1ff);
    local_218[0] = '\0';
    FUN_10093d10(local_218 + 1,0,0x1ff);
    while (pcVar7 != (char *)0x0) {
      FUN_10093d10(local_618,0,0x200);
      pcVar8 = pcVar7;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      if ((uint)((int)pcVar8 - (int)(pcVar7 + 1)) < 0x201) {
        pcVar8 = pcVar7;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        iVar9 = (int)pcVar8 - (int)(pcVar7 + 1);
      }
      else {
        iVar9 = 0x200;
      }
      FUN_10093f20(local_618,pcVar7,iVar9);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x902,"vpn tunnel thread start, valid splite string:(%s)\n",local_618)
        ;
      }
      iVar9 = FUN_10090450(local_618,"validcode=");
      if (iVar9 != 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x906,"vpn tunnel thread start: found validcode(%s)\n",local_618);
        }
        pbVar10 = local_618;
        do {
          bVar2 = *pbVar10;
          pbVar10 = pbVar10 + 1;
        } while (bVar2 != 0);
        FUN_10093f20(local_418,local_60e,pbVar10 + (-10 - (int)(local_618 + 1)));
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x908,"vpn tunnel thread start: chValidcode:%s\n",local_418);
        }
      }
      pcVar7 = "motionProweb=1";
      pbVar10 = local_618;
      do {
        bVar2 = *pbVar10;
        bVar14 = bVar2 < (byte)*pcVar7;
        if (bVar2 != *pcVar7) {
LAB_10066581:
          uVar5 = -(uint)bVar14 | 1;
          goto LAB_10066586;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar10[1];
        bVar14 = bVar2 < (byte)pcVar7[1];
        if (bVar2 != pcVar7[1]) goto LAB_10066581;
        pbVar10 = pbVar10 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar2 != 0);
      uVar5 = 0;
LAB_10066586:
      if (uVar5 == 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x90c,
                             "vpn tunnel thread start: MotionPro connect with web launch.\n");
        }
        DAT_1011ecc0 = 1;
      }
      iVar9 = FUN_10090450(local_618,"L4Connected=1");
      if (iVar9 != 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x911,
                             "vpn tunnel thread start: MotionPro connect l4 connected. MotionPro client still stay connected if l3 connect failed.\n"
                            );
        }
        local_6c8 = 1;
      }
      iVar9 = FUN_10090450(local_618,"CustomDNS=");
      if (iVar9 != 0) {
        pbVar10 = local_618;
        do {
          bVar2 = *pbVar10;
          pbVar10 = pbVar10 + 1;
        } while (bVar2 != 0);
        FUN_10093f20(local_218,local_60e,pbVar10 + (-10 - (int)(local_618 + 1)));
      }
      pcVar7 = (char *)FUN_1009315e(0,&local_6a8);
    }
    pcVar7 = local_418;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if ((int)pcVar7 - (int)(local_418 + 1) != 0) {
      FUN_10093d10(param_1 + 0x18f5,0,0x400);
      FUN_10093f20(param_1 + 0x18f5,local_418,(int)pcVar7 - (int)(local_418 + 1));
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x91f,"vpn tunnel thread start: connect valid code=%s.\n",
                         param_1 + 0x18f5);
    }
    iVar9 = DAT_10106410;
    FUN_10093d10(param_1 + 0x5198,0,0x200);
    pcVar7 = local_218;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_10093f20(param_1 + 0x5198,local_218,(int)pcVar7 - (int)(local_218 + 1));
    if (iVar9 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x923,"vpn tunnel thread start: connect custom dns=%s.\n",
                         param_1 + 0x5198);
    }
    if (DAT_1011c770 == 0) {
      SSL_load_error_strings();
      SSL_library_init();
      DAT_1011c770 = 1;
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\common.c",0x2448,"openssl init\n");
      }
    }
    if (DAT_1011ecc8 == 1) {
      pcVar7 = &DAT_10ae55b2;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (pcVar7 != &DAT_10ae55b3) {
        FUN_10093d10((undefined4 *)(param_1 + 0x15f2),0,0x101);
        puVar11 = (undefined4 *)&DAT_10ae55b2;
        puVar13 = (undefined4 *)(param_1 + 0x15f2);
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
        param_1 = local_6d4;
      }
      pcVar7 = &DAT_10ae56b3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (pcVar7 != &DAT_10ae56b4) {
        FUN_10093d10((undefined4 *)(param_1 + 0x16f3),0,0x101);
        puVar11 = (undefined4 *)&DAT_10ae56b3;
        puVar13 = (undefined4 *)(param_1 + 0x16f3);
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
      }
      pcVar7 = &DAT_10ae57b4;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      param_1 = local_6d4;
      if (pcVar7 != &DAT_10ae57b5) {
        puVar13 = (undefined4 *)(local_6d4 + 0x17f4);
        FUN_10093d10(puVar13,0,0x101);
        puVar11 = (undefined4 *)&DAT_10ae57b4;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
        param_1 = local_6d4;
      }
    }
    FUN_10093d10(&DAT_10ae3fc0,0,0x53a0);
    DAT_10ae3fc0 = 0xffffffff;
    FUN_10093d10(&DAT_10ae9380,0,0xc12);
    *(undefined4 *)(param_1 + 0x2500) = 1;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",1,0);
    }
    local_64c = 0;
    if (*(code **)(param_1 + 0x2648) != (code *)0x0) {
      (**(code **)(param_1 + 0x2648))(1,0,0,0,0,0);
    }
    pcVar7 = (char *)(param_1 + 0x21f6);
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if ((pcVar7 != (char *)(param_1 + 0x21f7)) ||
       ((uint)((int)pcVar7 - (param_1 + 0x21f7)) < *(uint *)(param_1 + 0x23fc))) {
      uVar5 = FUN_1004b6a0();
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      if ((*(uint *)(param_1 + 0x2644) & 0x300000) != 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x946,"l3vpn_tunnel_thread: no need check cert file info result.\n")
          ;
        }
        goto LAB_1006692e;
      }
      if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
      if (uVar5 == 0) goto LAB_1006692e;
LAB_10066904:
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      *(uint *)(param_1 + 0x44) = uVar5;
      goto LAB_100671e0;
    }
LAB_1006692e:
    if (DAT_1015566c != 1) {
      uVar5 = FUN_1004cb10();
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
      if (uVar5 != 0) goto LAB_10066904;
    }
    if ((*(byte *)(param_1 + 0x2e6e) & 2) != 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x955,"l3vpn_tunnel_thread: get local address begin\n");
      }
      uStack_630 = 0;
      uStack_640 = 0;
      uStack_63c = 0;
      uStack_638 = 0;
      uStack_634 = 0;
      get_local_address(&uStack_640,5);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x958,"l3vpn_tunnel_thread: get local address end\n");
      }
    }
    uVar5 = FUN_1004d770();
    lVar17 = CONCAT44(local_6cc,uStack_6c4);
    if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
    if (uVar5 != 0) goto LAB_10066904;
    uStack_6c4 = FUN_10052e70();
    iStack_6a0 = 0;
    DStack_674 = 4;
    DStack_67c = 4;
    LVar4 = SHGetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","GetCSsession",&DStack_674,&iStack_6a0,&DStack_67c);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x96e,"Get Get ClientSecurity Session flag: value:[%d], dwRet:[%d]\n",
                         iStack_6a0,LVar4);
    }
    lVar17 = CONCAT44(local_6cc,uStack_6c4);
    if ((LVar4 == 0) && (iStack_6a0 == 1)) {
      if (1 < DAT_10106410) goto LAB_10067205;
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x971,
                         "MotionPro client get clientsecurity session finish, go to cleanup!\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      goto LAB_100671e0;
    }
    if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
    uVar5 = uStack_6c4;
    if (uStack_6c4 != 0) goto LAB_10066904;
    FUN_10093f20(&DAT_10ae3fc0,param_1,0x53a0);
    DAT_1011ecb4 = ~(*(uint *)(param_1 + 0x2644) >> 10) & 1;
    if ((*(uint *)(param_1 + 0x2644) & 0x40) == 0) {
LAB_10066b56:
      if ((DAT_1011ecb4 == 0) && ((*(uint *)(param_1 + 0x2644) & 0x500) != 0)) {
        *(uint *)(param_1 + 0x2644) = *(uint *)(param_1 + 0x2644) | 0x80000;
        iVar9 = FUN_1004df40();
        if (iVar9 == 0) {
          iVar9 = FUN_1004f170();
          uVar5 = 0;
          if (iVar9 != 0) goto LAB_10066b8f;
        }
        else {
LAB_10066b8f:
          uVar5 = FUN_1004d770();
        }
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
        if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
        if (uVar5 != 0) goto LAB_10066904;
      }
    }
    else {
      iStack_68c = 0;
      uStack_688 = 0;
      uStack_684 = 0;
      FUN_1004ee50();
      iVar9 = iStack_68c;
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x99e,
                           "get_settings_motionpro: bookmark:%d, cs postlogin:%d, cs interval:%d\n",iStack_68c,
                           uStack_688,uStack_684);
      }
      if (iVar9 == 1) {
        FUN_1004e800();
      }
      *(undefined4 *)(param_1 + 0x2e8d) = uStack_688;
      *(int *)(param_1 + 0x2e89) = iVar9;
      *(undefined4 *)(param_1 + 0x2e91) = uStack_684;
      iVar9 = FUN_1004f170();
      if (iVar9 == 0) goto LAB_10066b56;
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x9ab,"start vpn_tunnel: get user resource failed, ret=%d\n",iVar9);
      }
    }
    if ((*(uint *)(param_1 + 0x2644) & 0x1000) != 0) {
      iVar12 = 0;
      *(undefined4 *)(param_1 + 0x2500) = 2;
      iVar9 = DAT_10106410;
      *(undefined4 *)(param_1 + 0x44) = 0;
      if (iVar9 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",3,0);
      }
      iStack_6b4 = 0;
      LVar4 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","ErrorCode",4,&iStack_6b4,4);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1bf,
                           "vpncallback:: Connect successfully, iRet = %d, Set Error code to Reg, Error code=%d\n",LVar4
                           ,iStack_6b4);
      }
      if (((*(byte *)(param_1 + 0x2644) & 3) == 0) || (iVar12 = FUN_10062060(), iVar12 == 0)) {
        if (*(code **)(param_1 + 0x2648) != (code *)0x0) {
          iVar12 = (**(code **)(param_1 + 0x2648))(3,0,0,0,0,0);
        }
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
        if (iVar12 == 0) goto LAB_100671e0;
      }
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      *(int *)(param_1 + 0x44) = iVar12;
      goto LAB_100671e0;
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x9cb,"start vpn_tunnel: domain (%s), user:%s\n",param_1 + 0x18c,
                         param_1 + 0x14f1);
    }
    iVar9 = FUN_10090450(param_1 + 0x14f1,"array_wg_tunnel");
    uStack_668 = 0;
    DAT_1011e8a8 = (uint)(iVar9 != 0);
    if (local_6cc == 1) {
      DAT_1011e8a8 = 2;
    }
    SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","SSTPRedirectToVNIC",4,&uStack_668,4);
    iVar9 = FUN_10058570();
    DAT_1011ecc4 = (uint)(iVar9 == 1);
    if ((*(uint *)(param_1 + 0x2644) & 0x10000) == 0) {
      iVar9 = FUN_100659b0();
    }
    else {
      iVar9 = FUN_1006f900(1);
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x9e2,"vpn_tunnel break: ret:%d, error:%d, connected:%d\n",iVar9,
                         *(undefined4 *)(param_1 + 0x44),local_6d0);
    }
    if (iVar9 != 0x87) break;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x9e5,"connect wg failed, switch to sstp.\n");
    }
    local_6cc = 1;
  } while( true );
  if (local_6d0 == 1) {
    local_6c8 = 0;
  }
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l4vpn.c",0x441,"l4vpn session be killed flag=%d\n",DAT_1011f0d0);
  }
  lVar17 = CONCAT44(local_6cc,uStack_6c4);
  local_6b0 = DAT_1011f0d0;
  if (((((local_6d0 == 0) || (iVar9 == 6)) || (iVar9 == 7)) || ((iVar9 == 0x1f || (iVar9 == 0x30)))) ||
     (DAT_1011f0d0 == 1)) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x9f0,"disconnect vpn tunnel, step out reconnection\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
  }
  else if (*(int *)(param_1 + 0x40) == 0) {
    if ((*(int *)(param_1 + 0x250c) == 0) && (0 < *(int *)(param_1 + 0x2510))) {
      *(undefined4 *)(param_1 + 0x250c) = 0x7fffffff;
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x9fb,"l3vpn reconnect count [%d], reconnect time [%d]\n",
                         *(undefined4 *)(param_1 + 0x250c),*(undefined4 *)(param_1 + 0x2510));
    }
    iVar9 = 0;
    iStack_6c0 = 0;
    uVar15 = FUN_10092e28(0);
    local_6cc = (uint)((ulonglong)uVar15 >> 0x20);
    uStack_6c4 = (uint)uVar15;
    *(undefined1 *)(param_1 + 0x2e6d) = 0;
    *(undefined4 *)(param_1 + 0x2e70) = 1;
    FUN_100661b0();
    local_680 = *(uint *)(param_1 + 0x59d4);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa04,"The current L3vpn virtual ip is %d.%d.%d.%d\n",local_680 & 0xff,
                         local_680 >> 8 & 0xff,local_680 >> 0x10 & 0xff,local_680 >> 0x18);
    }
    iStack_6b8 = 10;
    if (0 < *(int *)(param_1 + 0x2514)) {
      iStack_6b8 = *(int *)(param_1 + 0x2514);
    }
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa0b,"l3vpn reconnect interval [%d].\n",iStack_6b8);
    }
    if ((*(int *)(param_1 + 0x44) == 0x86) && (DAT_10106410 < 2)) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa0e,"received the sess.error is ERR_WG_TUNNEL_SWITCH, reconnect VPN\n"
                        );
    }
    lVar17 = CONCAT44(local_6cc,uStack_6c4);
    if (*(int *)(param_1 + 0x40) == 0) {
      while( true ) {
        local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
        uStack_6c4 = (uint)lVar17;
        if (*(int *)(param_1 + 0x250c) <= iVar9) break;
        FUN_10064b20();
        DStack_670 = 4;
        uStack_6bc = 0;
        DStack_664 = 4;
        LVar4 = SHGetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","system_wakeup_time",&DStack_670,&uStack_6bc,
                            &DStack_664);
        if ((LVar4 == 0) && (uStack_6bc != 0)) {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa1a,"reconnect: get system wakeup time: %x, reconn_start:%x\n",
                               uStack_6bc,uStack_6c4,local_6cc);
          }
          if (((int)local_6cc < 1) && ((0x7fffffff < local_6cc || (uStack_6c4 < uStack_6bc)))) {
            local_6cc = 0;
            uStack_6c4 = uStack_6bc;
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa1e,
                                 "detect the reconnect start time is before system wakeup, then update to wakeup time\n"
                                );
            }
          }
          SHDeleteValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","system_wakeup_time");
        }
        else if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa24,"reconnect: there is no system wakeup time\n");
        }
        if (0 < *(int *)(param_1 + 0x2510)) {
          lVar16 = FUN_10092e28(0);
          lVar17 = CONCAT44(local_6cc,uStack_6c4);
          if ((longlong)*(int *)(param_1 + 0x2510) < lVar16 - lVar17) {
            if (1 < DAT_10106410) goto LAB_10067205;
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa2c,"*** reach reconnect time limit ***\n");
            lVar17 = CONCAT44(local_6cc,uStack_6c4);
            break;
          }
          iVar9 = iStack_6c0;
        }
        DStack_678 = 4;
        iStack_690 = 0;
        DStack_660 = 4;
        LVar4 = SHGetValueA((HKEY)0x80000001,"Software\\VPN\\Install Manager","sstp_invalid_status",&DStack_678,
                            &iStack_690,&DStack_660);
        if ((LVar4 == 0) && (iStack_690 == 1)) {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa36,
                               "*** stop reconnect due to received lcp ternimate request *** \n");
          }
          lVar17 = CONCAT44(local_6cc,uStack_6c4);
          *(undefined1 *)(param_1 + 0x5195) = 1;
          break;
        }
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa3b,"reconnect attempt [%d], error:%d\n",iVar9 + 1,
                             *(undefined4 *)(param_1 + 0x44));
        }
        iVar12 = DAT_10106410;
        if (iVar9 == 0) {
          *(undefined4 *)(param_1 + 0x2500) = 4;
          if (iVar12 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa3f,"sdk will reconnect VPN, set vpn->sess.reconn_now to 1\n");
            iVar12 = DAT_10106410;
          }
          *(undefined1 *)(param_1 + 0x5195) = 1;
          if (iVar12 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",7,0);
          }
          uStack_650 = 0;
          if ((*(byte *)(param_1 + 0x2644) & 3) != 0) {
            FUN_10070120();
          }
          if (*(code **)(param_1 + 0x2648) != (code *)0x0) {
            (**(code **)(param_1 + 0x2648))(7,0,0,0,0,0);
          }
          dwMilliseconds = 3000;
        }
        else if (iVar9 - 1U < 4) {
          dwMilliseconds = iVar9 * 2000;
        }
        else {
          dwMilliseconds = iStack_6b8 * 1000;
        }
        Sleep(dwMilliseconds);
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
        if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
        FUN_100661b0();
        if (*(int *)(param_1 + 0x2e70) == 2) {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa4e,"reconnect new ip of vpn server\n");
          }
          iVar12 = FUN_1004cb10();
          if (iVar12 == 0) goto LAB_10067326;
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa55,"reconnecting: failed to get ip of [%s]\n",param_1 + 0x8c);
          }
          lVar17 = CONCAT44(local_6cc,uStack_6c4);
          iStack_6c0 = iVar9 + 1;
          if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
        }
        else {
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa5b,"reconnect cache ip of vpn server\n");
          }
LAB_10067326:
          if ((*(byte *)(param_1 + 0x2e6e) & 2) != 0) {
            uStack_630 = 0;
            uStack_640 = 0;
            uStack_63c = 0;
            uStack_638 = 0;
            uStack_634 = 0;
            get_local_address(&uStack_640,5);
          }
          lVar17 = CONCAT44(local_6cc,uStack_6c4);
          if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
          iVar9 = FUN_1004d770();
          lVar17 = CONCAT44(local_6cc,uStack_6c4);
          if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
          if (iVar9 == 0) {
            if (local_680 != 0) {
              *(uint *)(param_1 + 0x59d4) = local_680;
            }
            iVar9 = FUN_10066150();
            if (local_6d0 == 0) goto LAB_10067407;
            iStack_6c0 = 0;
            lVar17 = FUN_10092e28(0);
            *(undefined1 *)(param_1 + 0x2e6d) = 0;
            *(undefined4 *)(param_1 + 0x2e70) = 1;
LAB_100673c7:
            iVar12 = DAT_10106410;
            local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
            uStack_6c4 = (uint)lVar17;
            if (((iVar9 == 6) || (iVar9 == 7)) || (iVar9 == 0x1f)) {
              *(undefined1 *)(param_1 + 0x290) = 0;
              if (iVar12 < 4) {
                array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0xa84,"start vpn tunnel failed during reconnection\n");
                lVar17 = CONCAT44(local_6cc,uStack_6c4);
              }
              break;
            }
          }
          else {
            local_6d0 = 0;
LAB_10067407:
            lVar17 = CONCAT44(local_6cc,uStack_6c4);
            iStack_6c0 = iStack_6c0 + 1;
            if (*(int *)(param_1 + 0x2e70) == 1) {
              *(undefined4 *)(param_1 + 0x2e70) = 2;
              *(undefined1 *)(param_1 + 0x2e6d) = 0;
              lVar17 = CONCAT44(local_6cc,uStack_6c4);
              goto LAB_100673c7;
            }
            if (iVar9 != 0x51) goto LAB_100673c7;
            if (*(byte *)(param_1 + 0x2e6d) < 10) {
              *(byte *)(param_1 + 0x2e6d) = *(byte *)(param_1 + 0x2e6d) + 1;
            }
          }
          if (*(int *)(param_1 + 0x40) != 0) goto LAB_100671d9;
        }
        iVar9 = iStack_6c0;
        if (*(int *)(param_1 + 0x40) != 0) break;
      }
    }
  }
  else {
LAB_100671d9:
    *(undefined4 *)(param_1 + 0x44) = 0x29;
  }
LAB_100671e0:
  local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
  uStack_6c4 = (uint)lVar17;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa8d,"l3vpn will stop, error [%d]\n",*(undefined4 *)(param_1 + 0x44));
    lVar17 = CONCAT44(local_6cc,uStack_6c4);
  }
LAB_10067205:
  iVar9 = DAT_10106410;
  local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
  uStack_6c4 = (uint)lVar17;
  uStack_6bc = (uint)(*(int *)(param_1 + 0x2500) != 1);
  if (local_6c8 == 1) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xa97,
                         "MotionPro connect l4 successfully but connect l3 failed, still stay connected status.\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
    local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
    uStack_6c4 = (uint)lVar17;
    iVar12 = 0;
    *(undefined4 *)(param_1 + 0x2500) = 5;
    iVar9 = DAT_10106410;
    *(undefined4 *)(param_1 + 0x44) = 0;
    if (iVar9 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",3,0);
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
    local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
    uStack_6c4 = (uint)lVar17;
    iStack_6ac = 0;
    LVar4 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","ErrorCode",4,&iStack_6ac,4);
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1bf,
                         "vpncallback:: Connect successfully, iRet = %d, Set Error code to Reg, Error code=%d\n",LVar4,
                         iStack_6ac);
    }
    if (((*(byte *)(param_1 + 0x2644) & 3) == 0) || (iVar12 = FUN_10062060(), iVar12 == 0)) {
      if (*(code **)(param_1 + 0x2648) != (code *)0x0) {
        iVar12 = (**(code **)(param_1 + 0x2648))(3,0,0,0,0,0);
      }
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      if (iVar12 == 0) goto LAB_10067654;
    }
    lVar17 = CONCAT44(local_6cc,uStack_6c4);
    *(int *)(param_1 + 0x44) = iVar12;
  }
  else {
    *(undefined4 *)(param_1 + 0x2500) = 3;
    if (iVar9 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xaa2,"MotionPro sdk send call back disconnecting start.\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",4,0);
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
      }
    }
    local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
    uStack_6c4 = (uint)lVar17;
    uStack_66c = 0;
    if (*(code **)(param_1 + 0x2648) != (code *)0x0) {
      (**(code **)(param_1 + 0x2648))(4,0,0,0,0,0);
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
    local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
    uStack_6c4 = (uint)lVar17;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xaa4,"MotionPro sdk send call back disconnecting finished.\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
  }
LAB_10067654:
  uVar5 = uStack_6bc;
  local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
  uStack_6c4 = (uint)lVar17;
  if (((DAT_1011ecc0 == 1) && (uStack_6bc == 0)) || (local_6c8 == 1)) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xaa9,"MotionPro web connect failed or stay connected, skip logout.\n");
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      goto LAB_100677cf;
    }
  }
  else {
    pcVar7 = (char *)(param_1 + 0x290);
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if ((((pcVar7 != (char *)(param_1 + 0x291)) && ((*(uint *)(param_1 + 0x2644) & 0x4000) == 0)) &&
        ((*(uint *)(param_1 + 0x2e74) & 0x4000) == 0)) && (local_6b0 != 1)) {
      local_6b0 = FUN_100584f0();
      iStack_6ac = FUN_10058340();
      iStack_6b4 = FUN_100583c0();
      uVar18 = FUN_10058470();
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xab4,
                           "before logout: iSSTPSessionReuseFlag:%d, iSSTPDialFailedFlag:%d, iRemainSessionFlag:%d, iSSTPRedirectToVNICFlag:%d,g_iconnectweb:%d, iL4Connected:%d\n"
                           ,local_6b0,iStack_6ac,iStack_6b4,uVar18,DAT_1011ecc0,local_6c8);
      }
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
      if ((local_6b0 == 1) && ((iStack_6ac == 1 || (iStack_6b4 == 1)))) {
        if (1 < DAT_10106410) goto LAB_100677f2;
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xab8,
                           "Enabled session reuse or SSTP dial failed, no need log off session\n");
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
      }
      else if (*(int *)(param_1 + 0x44) == 0x27) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xac2,"Win32: sstp redirect to vnic, no need logoff session\n");
        }
        FUN_10058440();
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
      }
      else {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xac7,"Mac or Linux, logoff session\n");
        }
        array_vpn_logout();
        lVar17 = CONCAT44(local_6cc,uStack_6c4);
        local_69c = 1;
      }
    }
LAB_100677cf:
    local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
    uStack_6c4 = (uint)lVar17;
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xace,"MotionPro connected flag=%d.\n",uVar5);
      lVar17 = CONCAT44(local_6cc,uStack_6c4);
    }
  }
LAB_100677f2:
  local_6cc = (uint)((ulonglong)lVar17 >> 0x20);
  uStack_6c4 = (uint)lVar17;
  FUN_1008f4d3(&DAT_10ae3fb8);
  _Memory = DAT_10ae3fb0;
  while (DAT_10ae3fb0 = _Memory, _Memory != (int *)0x0) {
    if (*_Memory == 0) {
      DAT_10ae3fb4 = _Memory[1];
    }
    else {
      *(int *)(*_Memory + 4) = _Memory[1];
    }
    *(int *)_Memory[1] = *_Memory;
    FID_conflict__free(_Memory);
    _Memory = DAT_10ae3fb0;
  }
  __Mtx_unlock(&DAT_10ae3fb8);
  FUN_1006ea70();
  if (local_6c8 == 1) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xadc,"MotionPro stay l4 connected, don\'t call back l3 failed.\n");
    }
  }
  else {
    iVar9 = *(int *)(param_1 + 0x44);
    if (uStack_6bc == 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",2,iVar9);
      }
      iStack_6a4 = 0;
      if (iVar9 != 0x5e) {
        iStack_6a4 = iVar9;
        LVar4 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","ErrorCode",4,&iStack_6a4,4);
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b9,
                             "vpncallback:: Connect failed, iRet = %d, Set Error code to Reg, Error code=%d\n",LVar4,
                             iStack_6a4);
        }
      }
      if ((*(byte *)(param_1 + 0x2644) & 3) != 0) {
        FUN_10061fd0();
        FUN_10070120();
      }
      pcVar6 = *(code **)(param_1 + 0x2648);
      if (pcVar6 != (code *)0x0) {
        uVar18 = 2;
        goto LAB_100679b5;
      }
    }
    else {
      if ((DAT_10106410 < 2) &&
         (array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xae2,"MotionPro sdk start call back disconnected.\n"),
         DAT_10106410 < 2)) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",5,iVar9);
      }
      uStack_654 = 0;
      if ((*(byte *)(param_1 + 0x2644) & 3) != 0) {
        FUN_10061fd0();
        FUN_10070120();
      }
      pcVar6 = *(code **)(param_1 + 0x2648);
      if (pcVar6 != (code *)0x0) {
        uVar18 = 5;
LAB_100679b5:
        (*pcVar6)(uVar18,iVar9,0,0,0,0);
      }
    }
  }
  uVar3 = DAT_10aec4a8;
  uVar18 = DAT_10aec4a4;
  FUN_10064b20();
  FUN_1008f605(uVar18,uVar3);
  DAT_10aec4a4 = local_65c;
  DAT_10aec4a8 = local_658;
  if (local_6c8 == 1) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xaf4,"MotionPro stay l4 connected, don\'t call back l3 failed.\n");
    }
  }
  else {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",0x1f,0);
    }
    uStack_644 = 0;
    if (*(code **)(local_6d4 + 0x2648) != (code *)0x0) {
      (**(code **)(local_6d4 + 0x2648))(0x1f,0,0,0,0,0);
    }
    if (local_69c == 1) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",0x21,0);
      }
      iVar9 = local_6d4;
      uStack_648 = 0;
      if (*(code **)(local_6d4 + 0x2648) != (code *)0x0) {
        (**(code **)(local_6d4 + 0x2648))(0x21,0,0,0,0,0);
      }
      goto LAB_10067a24;
    }
  }
  iVar9 = local_6d4;
LAB_10067a24:
  FUN_10093d10(iVar9,0,0x6818);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0xaff,"l3vpn_tunnel_thread: exit\n");
  }
  uStack_698 = 0;
  LVar4 = SHSetValueA((HKEY)0x80000001,"SOFTWARE\\VPN\\VPN2","SDKConnectThread",4,&uStack_698,4);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x6bd,"set_connect_thread_flag: thread name:%s, dwRunning:%d,dwRet=%d\n",
                       "SDKConnectThread",uStack_698,LVar4);
  }
  FUN_1008fc07();
  return;
}


// ----- caller: FUN_10066150 @ 10066150

void FUN_10066150(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x2644) & 0x10000) == 0) {
    FUN_100659b0();
    return;
  }
  FUN_1006f900(1);
  return;
}


// ----- callee: FUN_1006ff20 @ 1006ff20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1006ff20(void)

{
  uint uVar1;
  char cVar2;
  HANDLE hHandle;
  DWORD DVar3;
  BOOL BVar4;
  int iVar5;
  undefined4 *in_ECX;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  int local_c;
  
  _DAT_10155564 = *in_ECX;
  _DAT_1015555c = in_ECX[1];
  _DAT_10155560 = in_ECX[2];
  DAT_1011f0d8 = in_ECX;
  if (DAT_1011f0dc == 0) {
    hHandle = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)0x0,0,0xff,(LPCSTR)0x0);
    if (hHandle == (HANDLE)0x0) {
      DVar3 = GetLastError();
      FUN_10091a4e("CreateSemaphore error: %d\n",DVar3);
    }
    FUN_10085870();
    DVar3 = WaitForSingleObject(hHandle,0xffffffff);
    if (DVar3 != 0) {
      DVar3 = GetLastError();
      FUN_10091a4e("semaphore wait error: %d\n",DVar3);
    }
    BVar4 = CloseHandle(hHandle);
    in_ECX = extraout_ECX;
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      FUN_10091a4e("semaphore destroy error: %d\n",DVar3);
      in_ECX = extraout_ECX_00;
    }
    DAT_1011f0dc = 1;
  }
  DAT_10ab3938 = FUN_100884e0(&DAT_1015555c,&DAT_10155560,in_ECX,FUN_1006fe50,in_ECX);
  if ((*(byte *)(DAT_10ab3938 + 0x29) & 1) == 0) {
    *(byte *)(DAT_10ab3938 + 0x29) = *(byte *)(DAT_10ab3938 + 0x29) | 1;
  }
  iVar6 = DAT_10163110;
  puVar8 = DAT_1011f0d8;
  DAT_10163100 = 0;
  _DAT_10163104 = 0;
  _DAT_10163108 = 0;
  _DAT_1016310c = 0;
  if (DAT_1011f0d8[9] == 0) {
    iVar5 = FUN_10087280();
    iVar6 = -1;
    if (iVar5 != 0) {
      iVar6 = local_c;
    }
    puVar8 = DAT_1011f0d8;
    if ((DAT_10163110 != 0) && (iVar6 != 0)) {
      DAT_10163100 = iVar6;
    }
  }
  else {
    uVar7 = 0;
    do {
      if ((uint)puVar8[9] <= uVar7) break;
      iVar5 = *(int *)(puVar8[10] + uVar7 * 4);
      if ((((byte)uVar7 < 4) && (iVar6 != 0)) && (iVar5 != 0)) {
        (&DAT_10163100)[uVar7 & 0xff] = iVar5;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 4);
  }
  uVar7 = 0;
  if (puVar8[0xb] != 0) {
    do {
      uVar1 = **(uint **)(puVar8[0xc] + uVar7 * 4);
      if (0xfffe < ((uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 & 0xff00 | uVar1 << 0x10) << 8)) {
        cVar2 = FUN_10085ad0();
        if (cVar2 != '\0') {
          FUN_10091a4e("!!!failed to add static dns host, error %d\n",(int)cVar2);
        }
        puVar8 = DAT_1011f0d8;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)puVar8[0xb]);
  }
  return 0;
}


// ----- callee: FUN_10062060 @ 10062060

int FUN_10062060(void)

{
  int iVar1;
  
  if ((DAT_10aec5e4 & 0x10000) == 0) {
    if ((((((DAT_10aec5e4 & 1) != 0) && (iVar1 = FUN_100616a0(), iVar1 != 0)) && (iVar1 != 0x19)) ||
        ((((DAT_10aec5e4 & 2) != 0 && (iVar1 = FUN_100772e0(), iVar1 != 0)) && (iVar1 != 0x19)))) ||
       ((((DAT_10aec5e4 & 1) != 0 && (iVar1 = FUN_10079ee0(), iVar1 != 0)) && (iVar1 != 0x19)))) {
      return 0x37;
    }
    if (((DAT_10aec5e4 & 0x8000) != 0) && (iVar1 = FUN_1006f900(0), iVar1 != 0)) {
      return iVar1;
    }
  }
  return 0;
}


// ----- callee: FUN_1008f51d @ 1008f51d

int FUN_1008f51d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int *local_14;
  undefined1 local_10 [4];
  int local_c;
  undefined1 local_8 [4];
  
  local_c = 0;
  FUN_1008ece5(local_10);
  FUN_1008f497(local_8,1);
  local_24 = param_2;
  local_20 = param_3;
  local_1c = local_10;
  local_18 = local_8;
  local_14 = &local_c;
  FUN_1008f4d3(local_8);
  iVar1 = __Thrd_start(param_1,FUN_1008f6a7,&local_24);
  if (iVar1 == 0) {
    while (local_c == 0) {
      FUN_1008ed24(local_10,local_8);
    }
  }
  __Mtx_unlock(local_8);
  __Cnd_destroy(local_10);
  __Mtx_destroy(local_8);
  return iVar1;
}


// ----- callee: FUN_1007e0f0 @ 1007e0f0

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


// ----- callee: __errno @ 100908cb

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2012 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_10105058;
  }
  return &p_Var1->_terrno;
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


// ----- callee: FUN_1007dbd0 @ 1007dbd0

undefined4 FUN_1007dbd0(void)

{
  SOCKET s;
  int in_ECX;
  
  s = *(SOCKET *)(in_ECX + 0x53a0);
  *(undefined4 *)(in_ECX + 0x53a0) = 0xffffffff;
  if ((s != 0) && (s != 0xffffffff)) {
    closesocket(s);
  }
  *(undefined2 *)(in_ECX + 0x53b0) = 0;
  FUN_10093d10(in_ECX + 0x53e0,0,0x5dc);
  *(undefined2 *)(in_ECX + 0x59bc) = 0;
  *(undefined4 *)(in_ECX + 0x6808) = 0;
  if (*(int *)(in_ECX + 0x59c8) != 0) {
    if (*(int *)(in_ECX + 0x59d0) != 0) {
      SSL_free(*(int *)(in_ECX + 0x59d0));
      *(undefined4 *)(in_ECX + 0x59d0) = 0;
    }
    if (*(int *)(in_ECX + 0x59cc) != 0) {
      SSL_CTX_free(*(int *)(in_ECX + 0x59cc));
      *(undefined4 *)(in_ECX + 0x59cc) = 0;
    }
  }
  return 0;
}


// ----- callee: FUN_10062ab0 @ 10062ab0

void FUN_10062ab0(void)

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
  FUN_10093d10(&DAT_1011e8b0,0,0x400);
  local_1c = 0x14000045;
  local_18 = 0;
  local_14 = 0xff00;
  local_10 = htons(6);
  local_e = 0;
  local_c = 0;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x2b6,"get_mp_token start: %s\n",in_ECX + 0x8c);
  }
  iVar1 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&local_1c,0x14);
  if (*(int *)(in_ECX + 0x40) != 0) {
    *(undefined4 *)(in_ECX + 0x44) = 0x29;
    FUN_1008fc07();
    return;
  }
  if (iVar1 < 1) {
    if (DAT_10106410 < 4) {
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",699,"get_mp_token failed.");
    }
    FUN_1008fc07();
    return;
  }
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x2be,"get_mp_token success.");
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_1008f62d @ 1008f62d

int FUN_1008f62d(HANDLE param_1,undefined4 param_2,DWORD *param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_8;
  
  DVar1 = WaitForSingleObject(param_1,0xffffffff);
  if ((DVar1 == 0xffffffff) || (BVar2 = GetExitCodeThread(param_1,&local_8), BVar2 == 0)) {
    return 4;
  }
  if (param_3 != (DWORD *)0x0) {
    *param_3 = local_8;
  }
  BVar2 = CloseHandle(param_1);
  return (-(uint)(BVar2 != 0) & 0xfffffffc) + 4;
}


// ----- callee: SHLWAPI.DLL::SHSetValueA @ EXTERNAL:0000011f
// decompile failed: Exception while decompiling EXTERNAL:0000011f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_1007ee20 @ 1007ee20

undefined4 FUN_1007ee20(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_1011f140 == 0) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x212,"speed tunnel open thread is not running\n");
    }
    return 0x1a;
  }
  if (DAT_10ae9fe0 == 0) {
    uVar2 = 10;
  }
  else {
    uVar2 = 3;
  }
  iVar1 = thrd_timedjoin(&DAT_1011f13c,uVar2);
  if (iVar1 == 0) {
    if (DAT_10106410 < 2) {
      array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x220,"joined speed tunnel open thread\n");
    }
    uVar2 = 0;
  }
  else {
    if (DAT_10106410 < 3) {
      array_vpn_logprint(2,"..\\l3vpn\\udp_tunnel.c",0x21d,"join speed tunnel open thread failed, return %d\n",iVar1);
    }
    uVar2 = 0x1b;
  }
  DAT_1011f140 = 0;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\udp_tunnel.c",0x225,"stop_udp_open_thread, finished\n");
  }
  return uVar2;
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


// ----- callee: pipe @ 10070ef0

void pipe(SOCKET *param_1)

{
  SOCKET s;
  int iVar1;
  SOCKET SVar2;
  undefined1 auStack_38 [4];
  int local_34;
  sockaddr local_30;
  uint local_14;
  
                    /* 0x70ef0  101  pipe */
  local_14 = DAT_101052f0 ^ (uint)auStack_38;
  local_30.sa_data[2] = '\0';
  local_30.sa_data[3] = '\0';
  local_30.sa_data[4] = '\0';
  local_30.sa_data[5] = '\0';
  local_30.sa_data[6] = '\0';
  local_30.sa_data[7] = '\0';
  local_30.sa_data[8] = '\0';
  local_30.sa_data[9] = '\0';
  local_30.sa_data[10] = '\0';
  local_30.sa_data[0xb] = '\0';
  local_30.sa_data[0xc] = '\0';
  local_30.sa_data[0xd] = '\0';
  local_34 = 0x10;
  local_30.sa_family = 2;
  local_30.sa_data[0] = '\0';
  local_30.sa_data[1] = '\0';
  local_30.sa_data._2_4_ = htonl(0x7f000001);
  param_1[1] = 0xffffffff;
  *param_1 = 0xffffffff;
  s = socket(2,1,0);
  if (s != 0xffffffff) {
    iVar1 = bind(s,&local_30,local_34);
    if (iVar1 != -1) {
      iVar1 = listen(s,5);
      if (iVar1 != -1) {
        iVar1 = getsockname(s,&local_30,&local_34);
        if (iVar1 != -1) {
          SVar2 = socket(2,1,0);
          param_1[1] = SVar2;
          if (SVar2 != 0xffffffff) {
            iVar1 = connect(SVar2,&local_30,local_34);
            if (iVar1 != -1) {
              SVar2 = accept(s,&local_30,&local_34);
              *param_1 = SVar2;
              if (SVar2 != 0xffffffff) {
                iVar1 = closesocket(s);
                if (iVar1 != -1) {
                  FUN_1008fc07();
                  return;
                }
              }
            }
          }
        }
      }
    }
    closesocket(s);
  }
  if (*param_1 != 0xffffffff) {
    closesocket(*param_1);
  }
  if (param_1[1] != 0xffffffff) {
    closesocket(param_1[1]);
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_100640d0 @ 100640d0

void FUN_100640d0(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  LSTATUS LVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  SOCKET *in_ECX;
  SOCKET SVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  char *pcVar17;
  SOCKET SVar18;
  undefined1 auStack_3b4 [4];
  SOCKET *local_3b0;
  int local_3ac;
  SOCKET local_3a8;
  SOCKET local_3a4;
  int local_3a0;
  uint local_39c;
  int local_398;
  int local_394;
  int local_390;
  undefined4 local_38c;
  uint local_388;
  DWORD DStack_384;
  int local_380;
  undefined4 local_37c;
  uint local_378;
  undefined4 local_374;
  DWORD DStack_370;
  uint local_36c;
  int local_368;
  uint local_364;
  DWORD local_360;
  int iStack_35c;
  int local_358;
  int iStack_354;
  DWORD local_350;
  int iStack_34c;
  DWORD local_348;
  DWORD local_344;
  DWORD local_340;
  DWORD DStack_33c;
  DWORD local_338;
  timeval local_334;
  int local_32c;
  fd_set local_328;
  CHAR CStack_220;
  undefined1 auStack_21f [263];
  CHAR CStack_118;
  undefined1 auStack_117 [267];
  uint local_c;
  
  local_c = DAT_101052f0 ^ (uint)auStack_3b4;
  local_3a0 = *in_ECX + 1;
  DAT_1011eccc = 0;
  local_37c = 1;
  local_374 = 1;
  DAT_1011ecbc = 0;
  local_358 = 0;
  local_340 = 4;
  local_350 = 4;
  local_3b0 = in_ECX;
  SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Install Manager","EnablePrintRequest",&local_340,&local_358,&local_350);
  SVar11 = local_3b0[0x1678];
  if ((int)SVar11 < 0x3d) {
    if ((int)SVar11 < 1) {
      SVar11 = 0x1e;
    }
  }
  else {
    SVar11 = 0x3c;
  }
  local_3a4 = 0;
  local_344 = 4;
  local_360 = 4;
  local_3a8 = SVar11;
  LVar7 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Keepalive","SendInterval",&local_344,&local_3a4,&local_360);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x54c,"Get keep alive SendInterval from reg: [%d], dwRet: [%d]\n",
                       local_3a4,LVar7);
  }
  if (LVar7 == 0) {
    if (local_3a4 - 1 < 0x3c) {
      SVar11 = local_3a4;
    }
    local_3a8 = SVar11;
  }
  iVar13 = 3;
  local_398 = 3;
  local_394 = 0;
  local_338 = 4;
  local_3b0[0x10] = 0;
  local_348 = 4;
  LVar7 = SHGetValueA((HKEY)0x80000002,"SOFTWARE\\VPN\\Keepalive","AttemptMaxTimes",&local_338,&local_394,&local_348);
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x558,"Get keep alive KeepAliveAttempts from reg: [%d], dwRet: [%d]\n",
                       local_394,LVar7);
  }
  if (LVar7 == 0) {
    if (local_394 - 1U < 300) {
      iVar13 = local_394;
    }
    local_398 = iVar13;
  }
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x55f,"select_loop: keep alive interval: [%d], KeepAliveAttempts: [%d]\n",
                       SVar11,iVar13);
  }
  uVar15 = FUN_10092e28(0);
  uVar3 = CONCAT44(local_3ac,local_39c);
  local_388 = (uint)uVar15;
  SVar11 = local_3b0[0x10];
  local_36c = local_388;
  uVar1 = uVar15;
  uVar2 = uVar15;
  uVar4 = uVar15;
  uVar5 = uVar15;
  do {
    if (SVar11 != 0) {
LAB_10064a81:
      local_3ac = (int)((ulonglong)uVar3 >> 0x20);
      local_39c = (uint)uVar3;
      local_380 = (int)((ulonglong)uVar2 >> 0x20);
      local_378 = (uint)uVar2;
      local_38c = (int)((ulonglong)uVar1 >> 0x20);
      local_388 = (uint)uVar1;
      local_368 = (int)((ulonglong)uVar15 >> 0x20);
      local_364 = (uint)uVar15;
      local_3a4 = 0;
      LVar7 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","tun_device_thread_exit",4,&local_3a4,4);
      if ((DAT_10106410 < 2) &&
         (array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x616,
                             "select_loop: SHSetValueA: set HKCU VPN-VPN2-tun_device_thread_exit to 0, iRet = %d\n",
                             LVar7), DAT_10106410 < 2)) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x618,
                           "select loop thread exit, l3vpn addr:%x, l3vpn->sess.error: %d\n",&local_3b0,local_3b0[0x11])
        ;
      }
      FUN_1008fc07();
      return;
    }
    local_38c = (int)((ulonglong)uVar5 >> 0x20);
    local_378 = (uint)uVar5;
    local_380 = (int)((ulonglong)uVar4 >> 0x20);
    local_36c = (uint)uVar4;
    uVar3 = CONCAT44(local_3ac,local_39c);
    local_368 = (int)((ulonglong)uVar15 >> 0x20);
    local_364 = (uint)uVar15;
    uVar6 = local_364;
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    if (local_3b0[0x11] != 0) goto LAB_10064a81;
    local_328.fd_array[0] = *local_3b0;
    local_328.fd_count = 1;
    if (local_3b0[0x1a02] != 0) {
      iVar13 = 0;
      do {
        if (local_328.fd_array[iVar13] == local_3b0[0x14e8]) break;
        iVar13 = iVar13 + 1;
      } while (iVar13 == 0);
      if (iVar13 == 1) {
        local_328.fd_count = 2;
        local_328.fd_array[1] = local_3b0[0x14e8];
      }
      if (local_3a0 <= (int)local_3b0[0x14e8]) {
        local_3a0 = local_3b0[0x14e8] + 1;
      }
    }
    local_334.tv_sec = 1;
    local_334.tv_usec = 0;
    iVar13 = select(local_3a0,&local_328,(fd_set *)0x0,(fd_set *)0x0,&local_334);
    uVar3 = CONCAT44(local_3ac,local_39c);
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    uVar15 = CONCAT44(local_368,local_364);
    if (local_3b0[0x11] != 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x573,
                           "after select, detect sess is error status, break select loop thread.\n");
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
      }
      goto LAB_10064a81;
    }
    if (iVar13 < 0) {
      if (DAT_10106410 < 3) {
        piVar9 = __errno();
        piVar10 = __errno();
        uVar16 = FUN_1009324b(*piVar9,local_3b0[0x11]);
        array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x578,
                           "vpn thread select failed, ret %d, error %u(%s), vpn session error: %d\n",iVar13,*piVar10,
                           uVar16);
      }
      uVar3 = CONCAT44(local_3ac,local_39c);
      uVar2 = CONCAT44(local_380,local_378);
      uVar1 = CONCAT44(local_38c,local_388);
      uVar15 = CONCAT44(local_368,local_364);
      local_3b0[0x11] = 0x1d;
      goto LAB_10064a81;
    }
    if (local_3b0[0x10] != 0) {
      if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x57c,"vpn tunnel is interrupted, stop tunnel.\n");
      }
      uVar3 = CONCAT44(local_3ac,local_39c);
      uVar2 = CONCAT44(local_380,local_378);
      uVar1 = CONCAT44(local_38c,local_388);
      uVar15 = CONCAT44(local_368,local_364);
      local_3b0[0x11] = 0x29;
      goto LAB_10064a81;
    }
    uVar15 = FUN_10092e28(0);
    local_3ac = (int)((ulonglong)uVar15 >> 0x20);
    uVar14 = (uint)uVar15;
    local_390 = uVar14 - uVar6;
    if (local_3b0[0x1a02] == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = uVar14 - local_388;
    }
    local_39c = uVar14;
    if ((iVar13 == 0) || ((0 < iVar13 && (local_3b0[0x1a02] != 0)))) {
      if ((local_3b0[0x940] == 2) || (local_3b0[0x940] == 6)) {
        if ((iVar13 == 0) && (DAT_1011e8a8 == 1)) {
          iVar8 = FUN_10058240();
          uVar15 = CONCAT44(local_3ac,local_39c);
          if ((iVar8 == 0xb) || (((iVar8 == 0xc || (iVar8 == 0xd)) || (iVar8 == 0xe)))) {
            if (DAT_10106410 < 3) {
              pcVar17 = "It seems the wg status is SWG_STATUS_RECONNECTING, we have to reconnect VPN\n";
              uVar16 = 0x5a6;
LAB_10064873:
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17);
            }
LAB_10064882:
            uVar3 = CONCAT44(local_3ac,local_39c);
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            DAT_1011e8a8 = 2;
            local_3b0[0x11] = 0x86;
            goto LAB_10064a81;
          }
          local_32c = iVar13;
          if ((code *)local_3b0[0x992] != (code *)0x0) {
            iVar8 = (*(code *)local_3b0[0x992])(0x2d,0,0,0,0,0);
            uVar15 = CONCAT44(local_3ac,local_39c);
            if (iVar8 != 0) {
              if (DAT_10106410 < 3) {
                pcVar17 = "It seems the wg process is not exist, we have to reconnect\n";
                uVar16 = 0x5af;
                goto LAB_10064873;
              }
              goto LAB_10064882;
            }
          }
        }
        local_3ac = (int)((ulonglong)uVar15 >> 0x20);
        local_39c = (uint)uVar15;
        uVar3 = uVar15;
        if ((local_3b0[0x1a02] != 0) && ((int)local_3a8 <= iVar12)) {
          iVar8 = (local_3ac - local_380) - (uint)(uVar14 < local_36c);
          if (((int)local_3a8 >> 0x1f <= iVar8) &&
             (((int)local_3a8 >> 0x1f < iVar8 || (local_3a8 <= uVar14 - local_36c)))) {
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x5ba,
                                 "select_loop: UDP tunnel %d seconds no response from AG, send UDP keepalive(send times:%d).\n"
                                 ,uVar14 - local_36c,iVar8,DAT_1011eccc);
              uVar15 = CONCAT44(local_3ac,local_39c);
            }
            iVar8 = DAT_1011eccc;
            local_3ac = (int)((ulonglong)uVar15 >> 0x20);
            local_39c = (uint)uVar15;
            DStack_384 = 0;
            DStack_33c = 1;
            if (DAT_1011eccc != 0) {
              DStack_384 = GetTickCount();
              uVar15 = CONCAT44(local_3ac,local_39c);
            }
            local_3ac = (int)((ulonglong)uVar15 >> 0x20);
            local_39c = (uint)uVar15;
            CStack_220 = '\0';
            FUN_10093d10(auStack_21f,0,0x103);
            FUN_1008fdb3(&CStack_220,"SOFTWARE\\VPN\\Keepalive\\L3UDPTunnel");
            iStack_35c = iVar8;
            SHSetValueA((HKEY)0x80000001,&CStack_220,"Running",4,&DStack_33c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_220,"SendTimes",4,&iStack_35c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_220,"TimeofLatestSend",4,&DStack_384,4);
            FUN_10063f70();
            DAT_1011eccc = DAT_1011eccc + 1;
            local_36c = local_39c;
            local_380 = local_3ac;
            uVar3 = CONCAT44(local_3ac,local_39c);
          }
          local_3ac = (int)((ulonglong)uVar3 >> 0x20);
          local_39c = (uint)uVar3;
          uVar14 = local_39c;
          if ((int)(local_398 * local_3a8) <= iVar12) {
            if (DAT_10106410 < 3) {
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x5c2,
                                 "select_loop: UDP tunnel %d seconds no response from AG, will reconnect VPN\n",iVar12);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            local_3b0[0x11] = 0x79;
            *(undefined1 *)((int)local_3b0 + 0x5197) = 1;
            goto LAB_10064a81;
          }
        }
        local_3ac = (int)((ulonglong)uVar3 >> 0x20);
        local_39c = (uint)uVar3;
        uVar15 = CONCAT44(local_3ac,uVar14);
        if ((int)local_3a8 <= local_390) {
          iVar12 = (local_3ac - local_368) - (uint)(uVar14 < local_378);
          if (((int)local_3a8 >> 0x1f <= iVar12) &&
             (((int)local_3a8 >> 0x1f < iVar12 || (local_3a8 <= uVar14 - local_378)))) {
            if (DAT_10106410 < 2) {
              array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x5cd,
                                 "select_loop: TCP tunnel %d seconds no response from AG, send TCP keepalive(send times:%d).\n"
                                 ,uVar14 - local_378,iVar12,DAT_1011ecbc);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            iVar13 = DAT_1011ecbc;
            local_3ac = (int)((ulonglong)uVar3 >> 0x20);
            local_39c = (uint)uVar3;
            DStack_370 = 0;
            iStack_354 = 1;
            if (DAT_1011ecbc != 0) {
              DStack_370 = GetTickCount();
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            local_3ac = (int)((ulonglong)uVar3 >> 0x20);
            local_39c = (uint)uVar3;
            CStack_118 = '\0';
            FUN_10093d10(auStack_117,0,0x103);
            FUN_1008fdb3(&CStack_118,"SOFTWARE\\VPN\\Keepalive\\L3TCPTunnel");
            iStack_34c = iVar13;
            SHSetValueA((HKEY)0x80000001,&CStack_118,"Running",4,&iStack_354,4);
            SHSetValueA((HKEY)0x80000001,&CStack_118,"SendTimes",4,&iStack_34c,4);
            SHSetValueA((HKEY)0x80000001,&CStack_118,"TimeofLatestSend",4,&DStack_370,4);
            SVar11 = FUN_10063d70();
            iVar13 = DAT_10106410;
            uVar3 = CONCAT44(local_3ac,local_39c);
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            if (SVar11 != 0) {
              local_3b0[0x11] = SVar11;
              if (iVar13 < 4) {
                array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x5d9,
                                   "It seems send_tcp_tunnel_keep_alive failed, return tunnel error %d\n",SVar11);
                uVar3 = CONCAT44(local_3ac,local_39c);
                uVar2 = CONCAT44(local_380,local_378);
                uVar1 = CONCAT44(local_38c,local_388);
                uVar15 = CONCAT44(local_368,local_364);
              }
              goto LAB_10064a81;
            }
            DAT_1011ecbc = DAT_1011ecbc + 1;
            local_368 = local_3ac;
            iVar13 = 0;
            local_378 = uVar14;
          }
          local_3ac = (int)((ulonglong)uVar3 >> 0x20);
          local_39c = (uint)uVar3;
          uVar15 = CONCAT44(local_3ac,uVar14);
          if ((int)(local_398 * local_3a8) <= local_390) {
            if (DAT_10106410 < 3) {
              array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x5e1,
                                 "select_loop: TCP tunnel %d seconds no response from AG, will reconnect VPN\n",
                                 local_390);
              uVar3 = CONCAT44(local_3ac,local_39c);
            }
            uVar2 = CONCAT44(local_380,local_378);
            uVar1 = CONCAT44(local_38c,local_388);
            uVar15 = CONCAT44(local_368,local_364);
            local_3b0[0x11] = 0x32;
            goto LAB_10064a81;
          }
        }
      }
      local_3ac = (int)((ulonglong)uVar15 >> 0x20);
      if (iVar13 != 0) goto LAB_10064760;
    }
    else {
LAB_10064760:
      local_3ac = (int)((ulonglong)uVar15 >> 0x20);
      SVar11 = *local_3b0;
      if ((SVar11 == 0xffffffff) || (local_3b0[0x10] != 0)) {
        if (DAT_10106410 < 2) {
          SVar18 = local_3b0[0x10];
          pcVar17 = "vpn tunnel is interrupted, stop tunnel, fd:%d, l3vpn->sess.manually_stop:%d\n";
          uVar16 = 0x5f0;
LAB_1006498b:
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17,SVar11,SVar18);
        }
LAB_1006499a:
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
        local_3b0[0x11] = 0x29;
        goto LAB_10064a81;
      }
      iVar13 = __WSAFDIsSet(SVar11,&local_328);
      if (iVar13 != 0) {
        SVar11 = FUN_10063130();
        local_37c = 0;
        if (SVar11 == 0) {
          local_38c = local_3ac;
          DAT_1011ecbc = 0;
          local_364 = (uint)uVar15;
          goto LAB_100647c2;
        }
        if (DAT_10106410 < 4) {
          pcVar17 = "ssl tunnel error %d\n";
          uVar16 = 0x5f8;
LAB_10064954:
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",uVar16,pcVar17,SVar11);
        }
LAB_10064963:
        uVar3 = CONCAT44(local_3ac,local_39c);
        uVar2 = CONCAT44(local_380,local_378);
        uVar1 = CONCAT44(local_38c,local_388);
        uVar15 = CONCAT44(local_368,local_364);
        local_3b0[0x11] = SVar11;
        goto LAB_10064a81;
      }
LAB_100647c2:
      iVar13 = local_3ac;
      SVar11 = local_3b0[0x14e8];
      if (local_3b0[0x1a02] != 0) {
        if ((SVar11 == 0xffffffff) || (local_3b0[0x10] != 0)) {
          if (DAT_10106410 < 2) {
            SVar18 = local_3b0[0x10];
            pcVar17 = "vpn udp tunnel is interrupted, stop tunnel, fd:%d, l3vpn->sess.manually_stop:%d\n";
            uVar16 = 0x602;
            goto LAB_1006498b;
          }
          goto LAB_1006499a;
        }
        if (local_3b0[0x1a02] != 0) {
          iVar12 = __WSAFDIsSet(SVar11,&local_328);
          if (iVar12 != 0) {
            SVar11 = FUN_10062c70();
            local_374 = 0;
            if (SVar11 != 0) {
              if (DAT_10106410 < 4) {
                pcVar17 = "udp tunnel error %d";
                uVar16 = 0x60a;
                goto LAB_10064954;
              }
              goto LAB_10064963;
            }
            DAT_1011eccc = 0;
            local_38c = iVar13;
            local_388 = (uint)uVar15;
          }
        }
      }
    }
    uVar5 = CONCAT44(local_38c,local_378);
    uVar4 = CONCAT44(local_380,local_36c);
    uVar3 = CONCAT44(local_3ac,local_39c);
    uVar2 = CONCAT44(local_380,local_378);
    uVar1 = CONCAT44(local_38c,local_388);
    uVar15 = CONCAT44(local_368,local_364);
    SVar11 = local_3b0[0x10];
  } while( true );
}


// ----- callee: WS2_32.DLL::closesocket @ EXTERNAL:00000020
// decompile failed: Exception while decompiling EXTERNAL:00000020: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_1005cc10 @ 1005cc10

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



// ===================== FUN_10065350 @ 10065350  anchors: [send_tcp_tunnel_keep_alive(win@100f3d90)] =====================

void FUN_10065350(int param_1)

{
  SOCKET SVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  LSTATUS LVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  int local_46c [9];
  undefined4 local_448;
  undefined4 uStack_444;
  undefined4 local_440;
  timeval local_43c;
  undefined4 local_434;
  fd_set local_430;
  CHAR local_328;
  undefined1 local_327 [263];
  CHAR local_220;
  undefined1 local_21f [263];
  CHAR CStack_118;
  undefined1 auStack_117 [267];
  uint local_c;
  
  local_c = DAT_101052f0 ^ (uint)local_46c;
  local_46c[0] = param_1;
  if (((DAT_10aec5e4 & 0x200) == 0) || (((byte)DAT_10ab3970 & 4) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  local_46c[4] = 0;
  local_448 = 1;
  local_328 = '\0';
  local_46c[8] = (int)!bVar2;
  FUN_10093d10(local_327,0,0x103);
  FUN_1008fdb3(&local_328,"SOFTWARE\\VPN\\Keepalive\\L3TCPTunnel");
  local_46c[7] = 0;
  SHSetValueA((HKEY)0x80000001,&local_328,"Running",4,&local_448,4);
  SHSetValueA((HKEY)0x80000001,&local_328,"SendTimes",4,local_46c + 7,4);
  SHSetValueA((HKEY)0x80000001,&local_328,"TimeofLatestSend",4,local_46c + 4,4);
  iVar3 = *(int *)(local_46c[0] + 0x67f8) + 1;
  iVar9 = 1;
  if (1 < iVar3) {
    iVar9 = iVar3;
  }
  iVar3 = *(int *)(local_46c[0] + 0x6800) + 1;
  if (iVar9 < iVar3) {
    iVar9 = iVar3;
  }
  iVar3 = *(int *)(local_46c[0] + 0x6804) + 1;
  if (iVar9 < iVar3) {
    iVar9 = iVar3;
  }
  if (*(int *)(local_46c[0] + 0x40) == 0) {
    while (*(int *)(local_46c[0] + 0x44) == 0) {
      uVar8 = 0;
      local_430.fd_count = 0;
      if (DAT_1011e8a8 == 0) {
        if (*(SOCKET *)(local_46c[0] + 0x67f8) != 0xffffffff) {
          uVar8 = 1;
          local_430.fd_array[0] = *(SOCKET *)(local_46c[0] + 0x67f8);
          local_430.fd_count = 1;
          if (iVar9 <= *(int *)(local_46c[0] + 0x67f8)) {
            iVar9 = *(int *)(local_46c[0] + 0x67f8) + 1;
          }
        }
        SVar1 = *(SOCKET *)(local_46c[0] + 0x6800);
        if (SVar1 != 0xffffffff) {
          uVar4 = 0;
          if (uVar8 != 0) {
            do {
              if (local_430.fd_array[uVar4] == SVar1) break;
              uVar4 = uVar4 + 1;
            } while (uVar4 < uVar8);
          }
          if ((uVar4 == uVar8) && (uVar8 < 0x400)) {
            local_430.fd_array[uVar4] = SVar1;
            local_430.fd_count = local_430.fd_count + 1;
          }
          if (iVar9 <= *(int *)(local_46c[0] + 0x6800)) {
            iVar9 = *(int *)(local_46c[0] + 0x6800) + 1;
          }
        }
      }
      else {
        local_430.fd_array[0] = 999999999;
        local_430.fd_count = 1;
      }
      local_43c.tv_sec = 1;
      local_43c.tv_usec = 0;
      iVar3 = select(iVar9,&local_430,(fd_set *)0x0,(fd_set *)0x0,&local_43c);
      if (iVar3 < 0) {
        if ((DAT_1011e8a8 == 0) || (DAT_1011e8a8 == 2)) {
          if (DAT_10106410 < 3) {
            piVar5 = __errno();
            piVar6 = __errno();
            uVar10 = FUN_1009324b(*piVar5,*(undefined4 *)(local_46c[0] + 0x44));
            array_vpn_logprint(2,"..\\l3vpn\\l3vpn.c",0x783,
                               "tun device thread select failed, ret %d, error %u(%s), vpn session error: %d\n",iVar3,
                               *piVar6,uVar10);
          }
          piVar5 = __errno();
          uVar10 = 0;
          if (*piVar5 != 4) {
            uVar10 = 0x1d;
          }
          *(undefined4 *)(local_46c[0] + 0x44) = uVar10;
          break;
        }
        if (DAT_1011e8a8 == 1) {
          Sleep(1000);
        }
      }
      if (*(int *)(local_46c[0] + 0x40) != 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x793,"vpn tunnel is interrupted, stop tunnel.\n");
        }
        goto LAB_100657cc;
      }
      if (iVar3 != 0) {
        if (((*(uint *)(local_46c[0] + 0x2644) & 0x200) == 0) || (local_46c[8] == 0)) {
          SVar1 = *(SOCKET *)(local_46c[0] + 0x67f8);
          if ((SVar1 != 0xffffffff) && (*(int *)(local_46c[0] + 0x40) == 0)) {
            iVar3 = __WSAFDIsSet(SVar1,&local_430);
            if ((iVar3 != 0) && (iVar3 = FUN_10068d50(), iVar3 != 0)) {
              if (DAT_10106410 < 4) {
                pcVar11 = "lwip error %d";
                uVar10 = 0x7ca;
                goto LAB_10065662;
              }
              goto LAB_10065671;
            }
            goto LAB_100656b9;
          }
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7c3,
                               "vpn tunnel is interrupted, stop tunnel, fd(%d), manually_stop(%d).\n",SVar1,
                               *(undefined4 *)(local_46c[0] + 0x40));
          }
        }
        else {
          SVar1 = *(SOCKET *)(local_46c[0] + 0x6800);
          if ((SVar1 != 0xffffffff) && (*(int *)(local_46c[0] + 0x40) == 0)) {
            iVar3 = __WSAFDIsSet(SVar1,&local_430);
            if ((iVar3 == 0) || (iVar3 = FUN_10061b10(), iVar3 == 0)) goto LAB_100656b9;
            if (DAT_10106410 < 4) {
              pcVar11 = "tun device error %d.\n";
              uVar10 = 0x7ab;
LAB_10065662:
              array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",uVar10,pcVar11,iVar3);
            }
LAB_10065671:
            *(int *)(local_46c[0] + 0x44) = iVar3;
            break;
          }
          if (DAT_10106410 < 2) {
            array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7a4,"vpn tunnel is interrupted, stop tunnel,fd:%d.\n",SVar1);
          }
        }
LAB_100657cc:
        *(undefined4 *)(local_46c[0] + 0x44) = 0x29;
        break;
      }
      if (3 < DAT_1011ecbc) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x79a,
                             "TCPTunnel: keepalive send time more than 3 times, reconnect VPN\n");
        }
        iVar9 = local_46c[0];
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x1b0,"vpncallback: code %d, error %d\n",0x2b,0);
        }
        local_434 = 0;
        if (*(code **)(iVar9 + 0x2648) != (code *)0x0) {
          (**(code **)(iVar9 + 0x2648))(0x2b,0,0,0,0,0);
        }
        break;
      }
LAB_100656b9:
      if (*(int *)(local_46c[0] + 0x40) != 0) break;
    }
  }
  local_46c[6] = 0;
  local_440 = 0;
  local_220 = '\0';
  FUN_10093d10(local_21f,0,0x103);
  FUN_1008fdb3(&local_220,"SOFTWARE\\VPN\\Keepalive\\L3TCPTunnel");
  uStack_444 = 0;
  SHSetValueA((HKEY)0x80000001,&local_220,"Running",4,local_46c + 6,4);
  SHSetValueA((HKEY)0x80000001,&local_220,"SendTimes",4,&uStack_444,4);
  SHSetValueA((HKEY)0x80000001,&local_220,"TimeofLatestSend",4,&local_440,4);
  local_46c[1] = 0;
  local_46c[3] = 0;
  CStack_118 = '\0';
  FUN_10093d10(auStack_117,0,0x103);
  FUN_1008fdb3(&CStack_118,"SOFTWARE\\VPN\\Keepalive\\L3UDPTunnel");
  local_46c[2] = 0;
  SHSetValueA((HKEY)0x80000001,&CStack_118,"Running",4,local_46c + 1,4);
  SHSetValueA((HKEY)0x80000001,&CStack_118,"SendTimes",4,local_46c + 2,4);
  SHSetValueA((HKEY)0x80000001,&CStack_118,"TimeofLatestSend",4,local_46c + 3,4);
  local_46c[5] = 1;
  LVar7 = SHSetValueA((HKEY)0x80000001,"Software\\VPN\\VPN2","tun_device_thread_exit",4,local_46c + 5,4);
  if ((DAT_10106410 < 2) &&
     (array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7d9,
                         "tun_device_thread: SHSetValueA: set HKCU VPN-VPN2-tun_device_thread_exit to 1, iRet = %d\n",
                         LVar7), DAT_10106410 < 2)) {
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x7dd,
                       "tun_device_thread thread exit, l3vpn addr:%x, l3vpn->sess.error:%d\n",local_46c,
                       *(undefined4 *)(local_46c[0] + 0x44));
  }
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10061b10 @ 10061b10

void FUN_10061b10(void)

{
  u_short uVar1;
  BOOL BVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  DWORD DVar12;
  int in_ECX;
  undefined4 uVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  DWORD local_210;
  undefined1 local_20c;
  undefined1 local_20b [255];
  undefined1 local_10c;
  undefined1 local_10b [259];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_10b + 0x107);
  if (((byte)DAT_10ab3970 & 8) == 0) {
LAB_10061f83:
    if (DAT_10106410 < 4) {
      DVar12 = GetLastError();
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0xee,"failed to read tun device (fd %d), error %d",
                         *(undefined4 *)(in_ECX + 0x6800),DVar12);
    }
    FUN_1008fc07();
    return;
  }
  local_210 = 0;
  BVar2 = ReadFile(DAT_10ab3a74,&DAT_10140190,0x10000,&local_210,(LPOVERLAPPED)0x0);
  DVar12 = 0xffffffff;
  if (BVar2 != 0) {
    DVar12 = local_210;
  }
  if (DVar12 == 0xffffffff) goto LAB_10061f83;
  if (DVar12 == 0) {
    if (DAT_10106410 < 1) {
      array_vpn_logprint(0,"..\\l3vpn\\l3vpn.c",0xf3,"read tun device, get 0 byte!!!");
    }
    FUN_1008fc07();
    return;
  }
  if ((DAT_10140190 & 0xf0) == 0x60) {
    local_20c = 0;
    FUN_10093d10(local_20b,0,0xff);
    local_10c = 0;
    FUN_10093d10(local_10b,0,0xff);
    inet_ntop(0x17,&DAT_10140198,&local_20c,0x100);
    inet_ntop(0x17,&DAT_101401a8,&local_10c,0x100);
    if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
      puVar15 = &local_10c;
      puVar14 = &local_20c;
      uVar1 = ntohs(DAT_10140194);
      array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x101,"read %d bytes (ipv6 len %d) from tun device, %s --> %s",DVar12,
                         uVar1,puVar14,puVar15);
    }
  }
  else if ((DAT_1011ecc4 != 0) && (DAT_10106410 < 2)) {
    uVar3 = (uint)DAT_101401a3;
    uVar4 = (uint)DAT_101401a2;
    uVar5 = (uint)DAT_101401a1;
    uVar6 = (uint)DAT_101401a0;
    uVar7 = (uint)DAT_1014019f;
    uVar8 = (uint)DAT_1014019e;
    uVar9 = (uint)DAT_1014019d;
    uVar10 = (uint)DAT_1014019c;
    uVar1 = ntohs(DAT_10140192);
    array_vpn_logprint(1,"..\\l3vpn\\l3vpn.c",0x109,
                       "read %d bytes (ip len %d) from tun device, %u.%u.%u.%u --> %u.%u.%u.%u",DVar12,uVar1,uVar10,
                       uVar9,uVar8,uVar7,uVar6,uVar5,uVar4,uVar3);
  }
  if ((*(int *)(in_ECX + 0x6808) == 0) || (iVar11 = *(int *)(in_ECX + 0x59c0), iVar11 == 0)) {
    iVar11 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&DAT_10140190,DVar12);
    if (iVar11 < 1) {
      if (DAT_10106410 < 4) {
        uVar13 = SSL_get_error(*(undefined4 *)(in_ECX + 0x34),iVar11);
        array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x111,"ssl write failed, error %d, SSL error %d",iVar11,uVar13);
      }
LAB_10061f4d:
      FUN_1008fc07();
      return;
    }
    goto LAB_10061f63;
  }
  if (iVar11 == 1) {
    if (DAT_10140199 == '\x06') {
      iVar11 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&DAT_10140190);
      if (iVar11 < 1) {
        if (DAT_10106410 < 4) {
          uVar13 = SSL_get_error(*(undefined4 *)(in_ECX + 0x34),iVar11);
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x11a,"ssl write failed, error %d, SSL error %d",iVar11,uVar13);
          FUN_1008fc07();
          return;
        }
        goto LAB_10061f4d;
      }
LAB_10061f63:
      FUN_10065150(DVar12,(int)DVar12 >> 0x1f);
      FUN_1008fc07();
      return;
    }
    iVar11 = FUN_1007dd70(DVar12);
    if (iVar11 == 0) goto LAB_10061f63;
    if (3 < DAT_10106410) goto LAB_10061ee3;
    uVar13 = 0x120;
  }
  else if (iVar11 == 2) {
    if (DAT_10140199 != '\x06') {
      iVar11 = SSL_write(*(undefined4 *)(in_ECX + 0x34),&DAT_10140190,DVar12);
      if (iVar11 < 1) {
        if (DAT_10106410 < 4) {
          uVar13 = SSL_get_error(*(undefined4 *)(in_ECX + 0x34),iVar11);
          array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x135,"ssl write failed, error %d, ssl error %d",iVar11,uVar13);
          FUN_1008fc07();
          return;
        }
        goto LAB_10061f4d;
      }
      goto LAB_10061f63;
    }
    iVar11 = FUN_1007dd70();
    if (iVar11 == 0) goto LAB_10061f63;
    if (3 < DAT_10106410) goto LAB_10061ee3;
    uVar13 = 0x12d;
  }
  else {
    if (iVar11 != 3) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0x149,"fatal error, dispatch rule [%d]",iVar11);
      }
      FUN_1008fc07();
      return;
    }
    iVar11 = FUN_1007dd70(DVar12);
    if (iVar11 == 0) goto LAB_10061f63;
    if (3 < DAT_10106410) goto LAB_10061ee3;
    uVar13 = 0x140;
  }
  array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",uVar13,"udp send failed, error %d",iVar11);
LAB_10061ee3:
  FUN_1007dbd0();
  FUN_100629c0();
  FUN_1008fc07();
  return;
}


// ----- callee: FUN_10068d50 @ 10068d50

void FUN_10068d50(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  char local_10c [260];
  undefined4 local_8;
  
  local_8 = DAT_101052f0 ^ (uint)(local_10c + 0x108);
  iVar1 = recv(*(SOCKET *)(in_ECX + 0x67f8),local_10c,0x100,0);
  if (iVar1 < 1) {
    if (DAT_10106410 < 4) {
      piVar2 = __errno();
      array_vpn_logprint(3,"..\\l3vpn\\l3vpn.c",0xc6f,"failed to read data from pipe, error: %d\n",*piVar2);
    }
    FUN_1008fc07();
    return;
  }
  FUN_1008f4d3(&DAT_10ae3fb8);
  while (DAT_10ae3fb0 != 0) {
    piVar2 = (int *)**(undefined4 **)(DAT_10ae3fb4 + 4);
    if (*piVar2 == 0) {
      DAT_10ae3fb4 = piVar2[1];
    }
    else {
      *(int *)(*piVar2 + 4) = piVar2[1];
    }
    *(int *)piVar2[1] = *piVar2;
    __Mtx_unlock(&DAT_10ae3fb8);
    iVar1 = FUN_10063650((short)piVar2[3]);
    FID_conflict__free((void *)piVar2[2]);
    FID_conflict__free(piVar2);
    if (iVar1 != 0) goto LAB_10068e5f;
    FUN_1008f4d3(&DAT_10ae3fb8);
  }
  __Mtx_unlock(&DAT_10ae3fb8);
LAB_10068e5f:
  FUN_1008fc07();
  return;
}


// ----- callee: WS2_32.DLL::__WSAFDIsSet @ EXTERNAL:0000001f
// decompile failed: Exception while decompiling EXTERNAL:0000001f: Cannot marshal address space: EXTERNAL

// ----- callee: SHLWAPI.DLL::SHSetValueA @ EXTERNAL:0000011f
// decompile failed: Exception while decompiling EXTERNAL:0000011f: Cannot marshal address space: EXTERNAL

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


// ----- callee: WS2_32.DLL::select @ EXTERNAL:00000016
// decompile failed: Exception while decompiling EXTERNAL:00000016: Cannot marshal address space: EXTERNAL

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


// ----- callee: __errno @ 100908cb

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2012 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_10105058;
  }
  return &p_Var1->_terrno;
}


// ----- callee: FUN_1009324b @ 1009324b

char * FUN_1009324b(undefined4 param_1)

{
  _ptiddata p_Var1;
  char *pcVar2;
  char *_Src;
  errno_t eVar3;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    pcVar2 = "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  else {
    if (p_Var1->_errmsg == (char *)0x0) {
      pcVar2 = (char *)FUN_10096b51(0x86,1);
      p_Var1->_errmsg = pcVar2;
      if (pcVar2 == (char *)0x0) {
        return "Visual C++ CRT: Not enough memory to complete call to strerror.";
      }
    }
    pcVar2 = p_Var1->_errmsg;
    _Src = (char *)FUN_10093225(param_1);
    eVar3 = _strcpy_s(pcVar2,0x86,_Src);
    if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return pcVar2;
}


