// decompiled by DumpAnchors for program: vl3vpn.dll

// ===================== FUN_1007dc70 @ 1007dc70  anchors: [FUN_1007dc70(byname)] =====================

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


// ----- caller: FUN_1007dd70 @ 1007dd70

uint FUN_1007dd70(int param_1)

{
  uint uVar1;
  u_short uVar2;
  uint uVar3;
  uint *puVar4;
  int in_ECX;
  uint *in_EDX;
  int iVar5;
  int iVar6;
  
  uVar2 = ntohs(*(u_short *)((int)in_EDX + 2));
  uVar1 = (uint)uVar2;
  do {
    if (*(int *)(in_ECX + 0xc) == 0) {
      if (DAT_10106410 < 1) {
        array_vpn_logprint(0,"..\\l3vpn\\udp_tunnel.c",0x62,"speed tunnel write plain data %d bytes\n",uVar1);
      }
LAB_1007de53:
      uVar3 = FUN_1007dc70(uVar1);
    }
    else {
      if (*(int *)(in_ECX + 0x628) == 0) {
        if (DAT_10106410 < 1) {
          array_vpn_logprint(0,"..\\l3vpn\\udp_tunnel.c",0x6b,"speed tunnel write encrypted data %d bytes\n",uVar1);
        }
        iVar5 = (int)uVar1 >> 2;
        iVar6 = 0;
        if (iVar5 != 0) {
          puVar4 = in_EDX;
          iVar6 = iVar5;
          do {
            *puVar4 = *puVar4 ^ *(uint *)(((in_ECX + 0x40) - (int)in_EDX) + (int)puVar4);
            iVar6 = iVar6 + -1;
            puVar4 = puVar4 + 1;
          } while (iVar6 != 0);
          iVar6 = iVar5;
        }
        if ((uint)(iVar6 * 4) < uVar1) {
          iVar5 = uVar1 + iVar6 * -4;
          puVar4 = in_EDX + iVar6;
          do {
            *(byte *)puVar4 = (byte)*puVar4 ^ *(byte *)((int)puVar4 + ((in_ECX + 0x40) - (int)in_EDX));
            iVar5 = iVar5 + -1;
            puVar4 = (uint *)((int)puVar4 + 1);
          } while (iVar5 != 0);
        }
        goto LAB_1007de53;
      }
      uVar3 = SSL_write(*(undefined4 *)(in_ECX + 0x630),in_EDX,uVar1);
      uVar3 = -(uint)(uVar3 != uVar1) & 3;
    }
    if (uVar3 != 0) {
      return uVar3;
    }
    in_EDX = (uint *)((int)in_EDX + uVar1);
    param_1 = param_1 - uVar1;
    if (param_1 < 1) {
      return 0;
    }
  } while( true );
}


// ----- caller: FUN_1007e240 @ 1007e240

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


// ----- callee: WS2_32.DLL::sendto @ EXTERNAL:0000001a
// decompile failed: Exception while decompiling EXTERNAL:0000001a: Cannot marshal address space: EXTERNAL

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


