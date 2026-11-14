// decompiled by DumpAnchors for program: vl3vpn.dll

// ===================== FUN_1005a560 @ 1005a560  anchors: [FUN_1005a560(byname)] =====================

u_long FUN_1005a560(int param_1)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  u_long uVar3;
  undefined4 uVar4;
  int in_ECX;
  int in_EDX;
  int *piVar5;
  char *pcVar6;
  u_long local_18;
  u_long local_14;
  int *local_10;
  void *local_c;
  int local_8;
  
  local_8 = 0;
  local_14 = 0;
  if (DAT_10106410 < 2) {
    array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0x97,"get_ag_launch_command: data len [%u]\n");
  }
  if (in_EDX == 0) {
    return 0;
  }
  piVar5 = (int *)(in_ECX + 0x5bcc);
  if (param_1 == 0) {
    piVar5 = (int *)(in_ECX + 0x5bd4);
  }
  *piVar5 = 0x10;
  local_10 = piVar5;
  iVar1 = FUN_10090374(1,0x40);
  piVar5[1] = iVar1;
  if (iVar1 == 0) {
    return 8;
  }
  if (in_EDX == 0) {
    *local_10 = local_8;
    return local_18;
  }
  do {
    iVar1 = 0;
    do {
      iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x34),(int)&local_14 + iVar1,4 - iVar1);
      if ((iVar2 < 1) || (*(int *)(in_ECX + 0x40) != 0)) {
        iVar1 = -1;
        goto LAB_1005a627;
      }
      iVar1 = iVar1 + iVar2;
    } while (iVar1 < 4);
    iVar1 = 4;
LAB_1005a627:
    if (*(int *)(in_ECX + 0x40) != 0) {
LAB_1005a8ca:
      *(undefined4 *)(in_ECX + 0x44) = 0x29;
      return 0x29;
    }
    if ((iVar1 < 1) || (iVar1 != 4)) {
      if (DAT_10106410 < 4) {
        array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0xa8,
                           "get_ag_launch_command: failed to read length from ssl tunnel, ret: %d\n",iVar1);
      }
      return 2;
    }
    FUN_100650d0(4,0);
    uVar3 = ntohl(local_14);
    piVar5 = local_10;
    local_14 = uVar3;
    if (local_8 < *local_10 + -1) {
      uVar4 = FUN_10090374(1,uVar3 + 1);
      uVar3 = local_14;
      *(undefined4 *)(piVar5[1] + local_8 * 4) = uVar4;
      iVar1 = piVar5[1];
      if (iVar1 == 0) {
        return 8;
      }
      iVar2 = 0;
      local_c = *(void **)(iVar1 + local_8 * 4);
      if (0 < (int)local_14) {
        do {
          iVar1 = SSL_read(*(undefined4 *)(in_ECX + 0x34),iVar2 + (int)local_c,uVar3 - iVar2);
          if ((iVar1 < 1) || (*(int *)(in_ECX + 0x40) != 0)) {
            uVar3 = 0xffffffff;
            break;
          }
          iVar2 = iVar2 + iVar1;
        } while (iVar2 < (int)uVar3);
      }
      if (*(int *)(in_ECX + 0x40) != 0) goto LAB_1005a8ca;
      if ((int)uVar3 < 1) {
        if (DAT_10106410 < 4) {
          array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0xb8,
                             "get_ag_launch_command: failed to read command from ssl tunnel\n");
        }
        return 2;
      }
      in_EDX = (in_EDX + -4) - uVar3;
      FUN_100650d0(uVar3,(int)uVar3 >> 0x1f);
      if (param_1 == 0) {
        if (DAT_10106410 < 2) {
          array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0xc2,"disconnect command: [%s]\n",
                             *(undefined4 *)(local_10[1] + local_8 * 4));
        }
      }
      else if (DAT_10106410 < 2) {
        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",0xc0,"launch command: [%s]\n",
                           *(undefined4 *)(local_10[1] + local_8 * 4));
      }
    }
    else {
      local_c = (void *)FUN_10090374(1,uVar3 + 1);
      if (local_c == (void *)0x0) {
        return 8;
      }
      iVar1 = 0;
      if (0 < (int)uVar3) {
        do {
          iVar2 = SSL_read(*(undefined4 *)(in_ECX + 0x34),iVar1 + (int)local_c,uVar3 - iVar1);
          if ((iVar2 < 1) || (*(int *)(in_ECX + 0x40) != 0)) {
            uVar3 = 0xffffffff;
            break;
          }
          iVar1 = iVar1 + iVar2;
        } while (iVar1 < (int)uVar3);
      }
      if (*(int *)(in_ECX + 0x40) != 0) goto LAB_1005a8ca;
      if ((int)uVar3 < 1) {
        if (DAT_10106410 < 4) {
          array_vpn_logprint(3,"..\\l3vpn\\get_config.c",0xcc,
                             "get_ag_launch_command: failed to read command from ssl tunnel\n");
          return 2;
        }
        return 2;
      }
      in_EDX = (in_EDX + -4) - uVar3;
      FUN_100650d0(uVar3,(int)uVar3 >> 0x1f);
      _Memory = local_c;
      if (param_1 == 0) {
        if (DAT_10106410 < 2) {
          pcVar6 = "disconnect command: [%s] (dropped)\n";
          uVar4 = 0xd6;
          goto LAB_1005a808;
        }
      }
      else if (DAT_10106410 < 2) {
        pcVar6 = "launch command: [%s] (dropped)\n";
        uVar4 = 0xd4;
LAB_1005a808:
        array_vpn_logprint(1,"..\\l3vpn\\get_config.c",uVar4,pcVar6,local_c);
      }
      FID_conflict__free(_Memory);
    }
    local_8 = local_8 + 1;
    if (in_EDX == 0) {
      *local_10 = local_8;
      return uVar3;
    }
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


// ----- callee: FUN_10090374 @ 10090374

int FUN_10090374(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = __calloc_impl(param_1,param_2,&local_8);
  if ((iVar1 == 0) && (local_8 != 0)) {
    piVar2 = __errno();
    if (piVar2 != (int *)0x0) {
      piVar2 = __errno();
      *piVar2 = local_8;
    }
  }
  return iVar1;
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


// ----- callee: WS2_32.DLL::ntohl @ EXTERNAL:00000012
// decompile failed: Exception while decompiling EXTERNAL:00000012: Cannot marshal address space: EXTERNAL

// ----- callee: SSLEAY32.DLL::SSL_read @ EXTERNAL:00000056
// decompile failed: Exception while decompiling EXTERNAL:00000056: Cannot marshal address space: EXTERNAL

