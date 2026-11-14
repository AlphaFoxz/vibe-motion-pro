// decompiled by DumpAnchors for program: ArrayWGClient.exe

// ===================== FUN_00429d00 @ 00429d00  anchors: [ObfuscateKey(win@00448270), ObfuscateKey(win@004482ac)] =====================

void __thiscall FUN_00429d00(void *this,uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int local_10 [3];
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  puVar1 = (uint *)((int)this + 0x140);
  *puVar1 = *param_1;
  *(uint *)((int)this + 0x144) = uVar2;
  *(uint *)((int)this + 0x148) = uVar3;
  *(uint *)((int)this + 0x14c) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(uint *)((int)this + 0x150) = param_1[4];
  *(uint *)((int)this + 0x154) = uVar2;
  *(uint *)((int)this + 0x158) = uVar3;
  *(uint *)((int)this + 0x15c) = uVar4;
  piVar5 = (int *)FUN_0042c5a0((void *)(*(int *)this + 0x5c),local_10,puVar1);
  *(void **)(*piVar5 + 0x28) = this;
  if (*(char *)(*(int *)this + 0x85) != '\0') {
    FUN_004200c0((undefined1 *)((int)this + 0x180),(byte *)(*(int *)this + 0xc0),(byte *)puVar1);
    FUN_00429550((void *)((int)this + 0x1ac),(uint *)&DAT_004482ac,8,puVar1,0x20);
    FUN_00429550((void *)((int)this + 0x1cc),(uint *)&DAT_00448270,8,puVar1,0x20);
    FUN_00429c00((int)this);
    param_1 = *(uint **)((int)this + 0x24);
    if (param_1 != (uint *)0x0) {
      *(undefined4 *)((int)this + 0x24) = 0;
      FUN_0042c360((void *)(*(int *)this + 0x1c),(uint *)&param_1);
    }
  }
  return;
}


// ----- caller: FUN_00420280 @ 00420280

void __thiscall FUN_00420280(void *this,byte *param_1,byte *param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  char *pcVar13;
  byte *pbVar14;
  byte *pbVar15;
  int *piVar16;
  uint *puVar17;
  void *pvVar18;
  byte bVar19;
  undefined1 uVar20;
  int iVar21;
  char unaff_DI;
  bool bVar22;
  uint local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8 [16];
  uint local_88;
  char local_80;
  void *local_78;
  int local_74;
  int local_70;
  int *local_6c;
  void *local_68;
  uint *local_64;
  byte local_5d;
  uint local_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined2 local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c [8];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  uVar20 = 0;
  pcVar13 = "[Interface]";
  local_68 = (void *)0x0;
  local_78 = (void *)0x0;
  local_74 = 0;
  local_70 = 0;
  local_64 = param_3;
  pbVar5 = param_1;
  do {
    bVar19 = *pbVar5;
    bVar22 = bVar19 < (byte)*pcVar13;
    if (bVar19 != *pcVar13) {
LAB_004202e0:
      uVar6 = -(uint)bVar22 | 1;
      goto LAB_004202e5;
    }
    if (bVar19 == 0) break;
    bVar19 = pbVar5[1];
    bVar22 = bVar19 < (byte)pcVar13[1];
    if (bVar19 != pcVar13[1]) goto LAB_004202e0;
    pbVar5 = pbVar5 + 2;
    pcVar13 = pcVar13 + 2;
  } while (bVar19 != 0);
  uVar6 = 0;
LAB_004202e5:
  local_6c = this;
  if (uVar6 == 0) {
    if ((param_2 != (byte *)0x0) &&
       ((*(int **)(*(int *)this + 0x38) == (int *)0x0 ||
        (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 8))(param_2,param_3), cVar4 == '\0')))) {
      pcVar13 = "PrivateKey";
      pbVar5 = param_2;
      do {
        bVar19 = *pbVar5;
        bVar22 = bVar19 < (byte)*pcVar13;
        if (bVar19 != *pcVar13) {
LAB_00420340:
          uVar6 = -(uint)bVar22 | 1;
          goto LAB_00420345;
        }
        if (bVar19 == 0) break;
        bVar19 = pbVar5[1];
        bVar22 = bVar19 < (byte)pcVar13[1];
        if (bVar19 != pcVar13[1]) goto LAB_00420340;
        pbVar5 = pbVar5 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar19 != 0);
      uVar6 = 0;
LAB_00420345:
      if (uVar6 == 0) {
        local_64 = (uint *)0x20;
        puVar17 = param_3;
        do {
          uVar6 = *puVar17;
          puVar17 = (uint *)((int)puVar17 + 1);
        } while ((char)uVar6 != '\0');
        uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)local_2c,(uint *)&local_64)
        ;
        if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
          *(undefined1 *)((int)this + 0x50) = 1;
          FUN_00429640((void *)(*(int *)this + 0x20),local_2c);
        }
      }
      else {
        pcVar13 = "ListenPort";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_004203c2:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_004203c7;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_004203c2;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_004203c7:
        if (uVar6 == 0) {
          uVar8 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xc) == uVar8) goto LAB_00420763;
          uVar6 = uVar8 & 0xffff;
          *(short *)(iVar9 + 0xc) = (short)uVar8;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar8 = (uint)*(ushort *)(iVar9 + 0xe);
        }
        else {
          pcVar13 = "ListenPortTCP";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00420422:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00420427;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00420422;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00420427:
          if (uVar6 != 0) {
            pcVar13 = "Address";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_004204a5:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_004204aa;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_004204a5;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_004204aa:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if (cVar4 == '\0') break;
                  iVar9 = *(int *)this;
                  puVar17 = *(uint **)(iVar9 + 0x2334);
                  if (puVar17 == *(uint **)(iVar9 + 0x2338)) {
                    FUN_00414bc0((void *)(iVar9 + 0x2330),puVar17,&local_5c);
                  }
                  else {
                    *puVar17 = local_5c;
                    puVar17[1] = uStack_58;
                    puVar17[2] = uStack_54;
                    puVar17[3] = uStack_50;
                    *(undefined2 *)(puVar17 + 4) = local_4c;
                    *(int *)(iVar9 + 0x2334) = *(int *)(iVar9 + 0x2334) + 0x12;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pbVar14 = &DAT_0044a2d0;
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < *pbVar14;
                if (bVar19 != *pbVar14) {
LAB_00420550:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_00420555;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < pbVar14[1];
                if (bVar19 != pbVar14[1]) goto LAB_00420550;
                pbVar5 = pbVar5 + 2;
                pbVar14 = pbVar14 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_00420555:
              if (uVar6 == 0) {
                iVar9 = FID_conflict__atoi((char *)param_3);
                if ((0x23f < iVar9) && (iVar9 < 0x2711)) {
                  *(short *)(*(int *)this + 0x10) = (short)iVar9;
                }
              }
              else {
                pcVar13 = "Table";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_004205b0:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_004205b5;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_004205b0;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_004205b5:
                if (uVar6 == 0) {
                  pbVar5 = &DAT_0044a25c;
                  puVar17 = param_3;
                  do {
                    bVar19 = (byte)*puVar17;
                    bVar22 = bVar19 < *pbVar5;
                    if (bVar19 != *pbVar5) {
LAB_004205e4:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004205e9;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = *(byte *)((int)puVar17 + 1);
                    bVar22 = bVar19 < pbVar5[1];
                    if (bVar19 != pbVar5[1]) goto LAB_004205e4;
                    puVar17 = (uint *)((int)puVar17 + 2);
                    pbVar5 = pbVar5 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004205e9:
                  if (uVar6 == 0) {
                    *(undefined1 *)(*(int *)this + 0x14) = 0;
                  }
                  else {
                    pbVar5 = &DAT_0044a2dc;
                    do {
                      bVar19 = (byte)*param_3;
                      bVar22 = bVar19 < *pbVar5;
                      if (bVar19 != *pbVar5) {
LAB_00420620:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_00420625;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = *(byte *)((int)param_3 + 1);
                      bVar22 = bVar19 < pbVar5[1];
                      if (bVar19 != pbVar5[1]) goto LAB_00420620;
                      param_3 = (uint *)((int)param_3 + 2);
                      pbVar5 = pbVar5 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_00420625:
                    if (uVar6 == 0) {
                      *(undefined1 *)(*(int *)this + 0x14) = 1;
                    }
                  }
                }
                else {
                  pbVar14 = &DAT_0044a2e4;
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < *pbVar14;
                    if (bVar19 != *pbVar14) {
LAB_00420662:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_00420667;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < pbVar14[1];
                    if (bVar19 != pbVar14[1]) goto LAB_00420662;
                    pbVar5 = pbVar5 + 2;
                    pbVar14 = pbVar14 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_00420667:
                  if (uVar6 == 0) {
                    FUN_0040e1b0(param_3,&local_78);
                    puVar17 = (uint *)0x0;
                    local_68 = local_78;
                    local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                    if (local_64 != (uint *)0x0) {
                      do {
                        piVar10 = *(int **)((int)local_68 + (int)puVar17 * 4);
                        pvVar18 = *(void **)((int)this + 0x4c);
                        local_48 = 0;
                        uStack_44 = 0;
                        uStack_40 = 0;
                        uStack_3c = 0;
                        local_30 = 0;
                        local_38 = 0;
                        iVar9 = inet_pton(0x17,piVar10,&uStack_40);
                        if (iVar9 == 1) {
                          local_48 = CONCAT22(local_48._2_2_,0x17);
                        }
                        else {
                          iVar9 = inet_pton(2,piVar10,&uStack_44);
                          if (iVar9 == 1) {
                            local_48 = CONCAT22(local_48._2_2_,2);
                          }
                          else {
                            if (pvVar18 == (void *)0x0) break;
                            cVar4 = FUN_0040c0e0(pvVar18,piVar10,(int *)&local_48);
                            if (cVar4 == '\0') {
                              FUN_0040e010("Unable to resolve %s",(char)piVar10);
                              break;
                            }
                          }
                        }
                        this = local_6c;
                        iVar9 = *local_6c;
                        puVar1 = *(uint **)(iVar9 + 0x2340);
                        if (puVar1 == *(uint **)(iVar9 + 0x2344)) {
                          FUN_004181c0((void *)(iVar9 + 0x233c),puVar1,&local_48);
                        }
                        else {
                          *puVar1 = local_48;
                          puVar1[1] = uStack_44;
                          puVar1[2] = uStack_40;
                          puVar1[3] = uStack_3c;
                          *(undefined8 *)(puVar1 + 4) = local_38;
                          puVar1[6] = local_30;
                          *(int *)(iVar9 + 0x2340) = *(int *)(iVar9 + 0x2340) + 0x1c;
                        }
                        puVar17 = (uint *)((int)puVar17 + 1);
                      } while (puVar17 < local_64);
                    }
                  }
                  else {
                    pcVar13 = "BlockDNS";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_004207c4:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_004207c9;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_004207c4;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_004207c9:
                    if (uVar6 == 0) {
                      uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                      if ((char)uVar7 != '\0') {
                        *(byte *)(*(int *)this + 0x12) = local_5d;
                      }
                    }
                    else {
                      pcVar13 = "BlockInternet";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00420811:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00420816;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00420811;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00420816:
                      if (uVar6 == 0) {
                        bVar19 = 0xff;
                        FUN_0040e1b0(param_3,&local_78);
                        puVar17 = (uint *)0x0;
                        local_68 = local_78;
                        local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                        if (local_64 != (uint *)0x0) {
                          do {
                            pbVar5 = *(byte **)((int)local_68 + (int)puVar17 * 4);
                            pcVar13 = "route";
                            pbVar14 = pbVar5;
                            do {
                              bVar12 = *pbVar14;
                              bVar22 = bVar12 < (byte)*pcVar13;
                              if (bVar12 != *pcVar13) {
LAB_00420880:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420885;
                              }
                              if (bVar12 == 0) break;
                              bVar12 = pbVar14[1];
                              bVar22 = bVar12 < (byte)pcVar13[1];
                              if (bVar12 != pcVar13[1]) goto LAB_00420880;
                              pbVar14 = pbVar14 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar12 != 0);
                            uVar6 = 0;
LAB_00420885:
                            if (uVar6 == 0) {
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 1;
                            }
                            else {
                              pcVar13 = "firewall";
                              pbVar14 = pbVar5;
                              do {
                                bVar12 = *pbVar14;
                                bVar22 = bVar12 < (byte)*pcVar13;
                                if (bVar12 != *pcVar13) {
LAB_004208c4:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_004208c9;
                                }
                                if (bVar12 == 0) break;
                                bVar12 = pbVar14[1];
                                bVar22 = bVar12 < (byte)pcVar13[1];
                                if (bVar12 != pcVar13[1]) goto LAB_004208c4;
                                pbVar14 = pbVar14 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar12 != 0);
                              uVar6 = 0;
LAB_004208c9:
                              if (uVar6 != 0) {
                                pbVar15 = &DAT_0044a248;
                                pbVar14 = pbVar5;
                                do {
                                  bVar12 = *pbVar14;
                                  bVar22 = bVar12 < *pbVar15;
                                  if (bVar12 != *pbVar15) {
LAB_004208f8:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_004208fd;
                                  }
                                  if (bVar12 == 0) break;
                                  bVar12 = pbVar14[1];
                                  bVar22 = bVar12 < pbVar15[1];
                                  if (bVar12 != pbVar15[1]) goto LAB_004208f8;
                                  pbVar14 = pbVar14 + 2;
                                  pbVar15 = pbVar15 + 2;
                                } while (bVar12 != 0);
                                uVar6 = 0;
LAB_004208fd:
                                if (uVar6 != 0) {
                                  pbVar15 = &DAT_0044a25c;
                                  pbVar14 = pbVar5;
                                  do {
                                    bVar12 = *pbVar14;
                                    bVar22 = bVar12 < *pbVar15;
                                    if (bVar12 != *pbVar15) {
LAB_00420930:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420935;
                                    }
                                    if (bVar12 == 0) break;
                                    bVar12 = pbVar14[1];
                                    bVar22 = bVar12 < pbVar15[1];
                                    if (bVar12 != pbVar15[1]) goto LAB_00420930;
                                    pbVar14 = pbVar14 + 2;
                                    pbVar15 = pbVar15 + 2;
                                  } while (bVar12 != 0);
                                  uVar6 = 0;
LAB_00420935:
                                  if (uVar6 == 0) {
                                    bVar19 = 0;
                                  }
                                  else {
                                    pcVar13 = "default";
                                    pbVar14 = pbVar5;
                                    do {
                                      bVar12 = *pbVar14;
                                      bVar22 = bVar12 < (byte)*pcVar13;
                                      if (bVar12 != *pcVar13) {
LAB_00420967:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_0042096c;
                                      }
                                      if (bVar12 == 0) break;
                                      bVar12 = pbVar14[1];
                                      bVar22 = bVar12 < (byte)pcVar13[1];
                                      if (bVar12 != pcVar13[1]) goto LAB_00420967;
                                      pbVar14 = pbVar14 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar12 != 0);
                                    uVar6 = 0;
LAB_0042096c:
                                    if (uVar6 == 0) {
                                      bVar19 = 0xff;
                                    }
                                    else {
                                      pcVar13 = "persist";
                                      pbVar14 = pbVar5;
                                      do {
                                        bVar12 = *pbVar14;
                                        bVar22 = bVar12 < (byte)*pcVar13;
                                        if (bVar12 != *pcVar13) {
LAB_004209a0:
                                          uVar6 = -(uint)bVar22 | 1;
                                          goto LAB_004209a5;
                                        }
                                        if (bVar12 == 0) break;
                                        bVar12 = pbVar14[1];
                                        bVar22 = bVar12 < (byte)pcVar13[1];
                                        if (bVar12 != pcVar13[1]) goto LAB_004209a0;
                                        pbVar14 = pbVar14 + 2;
                                        pcVar13 = pcVar13 + 2;
                                      } while (bVar12 != 0);
                                      uVar6 = 0;
LAB_004209a5:
                                      if (uVar6 == 0) {
                                        bVar12 = 0;
                                        if (-1 < (char)bVar19) {
                                          bVar12 = bVar19;
                                        }
                                        bVar19 = bVar12 | 0x10;
                                      }
                                      else {
                                        pcVar13 = "allow_local";
                                        pbVar14 = pbVar5;
                                        do {
                                          bVar12 = *pbVar14;
                                          bVar22 = bVar12 < (byte)*pcVar13;
                                          if (bVar12 != *pcVar13) {
LAB_004209e1:
                                            uVar6 = -(uint)bVar22 | 1;
                                            goto LAB_004209e6;
                                          }
                                          if (bVar12 == 0) break;
                                          bVar12 = pbVar14[1];
                                          bVar22 = bVar12 < (byte)pcVar13[1];
                                          if (bVar12 != pcVar13[1]) goto LAB_004209e1;
                                          pbVar14 = pbVar14 + 2;
                                          pcVar13 = pcVar13 + 2;
                                        } while (bVar12 != 0);
                                        uVar6 = 0;
LAB_004209e6:
                                        if (uVar6 == 0) {
                                          bVar12 = 0;
                                          if (-1 < (char)bVar19) {
                                            bVar12 = bVar19;
                                          }
                                          bVar19 = bVar12 | 0x20;
                                        }
                                        else {
                                          FUN_0040e010("Unknown mode in BlockInternet: %s",(char)pbVar5);
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_00420a1a;
                                }
                              }
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 2;
                            }
LAB_00420a1a:
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while (puVar17 < local_64);
                        }
                        *(byte *)(*local_6c + 0x13) = bVar19;
                      }
                      else {
                        pcVar13 = "ObfuscateKey";
                        pbVar5 = param_2;
                        do {
                          bVar19 = *pbVar5;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00420a60:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00420a65;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = pbVar5[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00420a60;
                          pbVar5 = pbVar5 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00420a65:
                        if (uVar6 == 0) {
                          puVar17 = param_3;
                          do {
                            uVar6 = *puVar17;
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while ((char)uVar6 != '\0');
                          iVar9 = *(int *)this;
                          *(bool *)(iVar9 + 0x1a8) = param_3 != (uint *)0x0;
                          if (param_3 != (uint *)0x0) {
                            FUN_00418620(&local_f8,0x20,(uint *)&DAT_0044828c,0x20);
                            FUN_00419bc0(&local_f8,param_3,(int)puVar17 - ((int)param_3 + 1));
                            local_d8 = local_d8 + local_88;
                            local_d0 = 0xffffffff;
                            local_d4 = local_d4 + (uint)(local_d8 < local_88);
                            if (local_80 != '\0') {
                              local_cc = 0xffffffff;
                            }
                            _memset((void *)((int)local_c8 + local_88),0,0x40 - local_88);
                            FUN_004186e0(&local_f8,local_c8);
                            *(uint *)(iVar9 + 0x1b0) = local_f8;
                            *(undefined4 *)(iVar9 + 0x1b4) = uStack_f4;
                            *(undefined4 *)(iVar9 + 0x1b8) = uStack_f0;
                            *(undefined4 *)(iVar9 + 0x1bc) = uStack_ec;
                            *(undefined4 *)(iVar9 + 0x1c0) = local_e8;
                            *(undefined4 *)(iVar9 + 0x1c4) = uStack_e4;
                            *(undefined4 *)(iVar9 + 0x1c8) = uStack_e0;
                            *(undefined4 *)(iVar9 + 0x1cc) = uStack_dc;
                          }
                        }
                        else {
                          pcVar13 = "ObfuscateTCP";
                          pbVar5 = param_2;
                          do {
                            bVar19 = *pbVar5;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_00420b70:
                              uVar6 = -(uint)bVar22 | 1;
                              goto LAB_00420b75;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar5[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_00420b70;
                            pbVar5 = pbVar5 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar6 = 0;
LAB_00420b75:
                          if (uVar6 == 0) {
                            uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                            if ((char)uVar7 == '\0') {
                              pcVar13 = "tls-firefox";
                              puVar17 = param_3;
                              do {
                                bVar19 = (byte)*puVar17;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420bc8:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420bcd;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = *(byte *)((int)puVar17 + 1);
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420bc8;
                                puVar17 = (uint *)((int)puVar17 + 2);
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420bcd:
                              if (uVar6 == 0) {
                                *(undefined4 *)(*(int *)this + 0x1ac) = 2;
                              }
                              else {
                                pcVar13 = "tls-chrome";
                                puVar17 = param_3;
                                do {
                                  bVar19 = (byte)*puVar17;
                                  bVar22 = bVar19 < (byte)*pcVar13;
                                  if (bVar19 != *pcVar13) {
LAB_00420c10:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420c15;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = *(byte *)((int)puVar17 + 1);
                                  bVar22 = bVar19 < (byte)pcVar13[1];
                                  if (bVar19 != pcVar13[1]) goto LAB_00420c10;
                                  puVar17 = (uint *)((int)puVar17 + 2);
                                  pcVar13 = pcVar13 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420c15:
                                if (uVar6 == 0) {
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 3;
                                }
                                else {
                                  if ((char)*param_3 != '\0') {
                                    FUN_0040e010("Unknown mode in ObfuscateTCP: %s",(char)param_3);
                                  }
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 1;
                                }
                              }
                            }
                            else {
                              *(uint *)(*(int *)this + 0x1ac) = (uint)local_5d;
                            }
                          }
                          else {
                            pcVar13 = "PostUp";
                            pbVar5 = param_2;
                            do {
                              bVar19 = *pbVar5;
                              bVar22 = bVar19 < (byte)*pcVar13;
                              if (bVar19 != *pcVar13) {
LAB_00420c76:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420c7b;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar5[1];
                              bVar22 = bVar19 < (byte)pcVar13[1];
                              if (bVar19 != pcVar13[1]) goto LAB_00420c76;
                              pbVar5 = pbVar5 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar19 != 0);
                            uVar6 = 0;
LAB_00420c7b:
                            if (uVar6 == 0) {
                              iVar9 = *(int *)this;
                              piVar10 = *(int **)(iVar9 + 0x2358);
                              if (piVar10 == *(int **)(iVar9 + 0x235c)) {
                                FUN_00422a20((void *)(iVar9 + 0x2354),piVar10,&local_64);
                              }
                              else {
                                piVar10[4] = 0;
                                piVar10[5] = 0xf;
                                *(undefined1 *)piVar10 = 0;
                                puVar17 = param_3;
                                do {
                                  uVar6 = *puVar17;
                                  puVar17 = (uint *)((int)puVar17 + 1);
                                } while ((char)uVar6 != '\0');
                                FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                *(int *)(iVar9 + 0x2358) = *(int *)(iVar9 + 0x2358) + 0x18;
                              }
                            }
                            else {
                              pcVar13 = "PostDown";
                              pbVar5 = param_2;
                              do {
                                bVar19 = *pbVar5;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420d00:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420d05;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar5[1];
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420d00;
                                pbVar5 = pbVar5 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420d05:
                              if (uVar6 == 0) {
                                iVar9 = *(int *)this;
                                piVar10 = *(int **)(iVar9 + 0x2370);
                                if (piVar10 == *(int **)(iVar9 + 0x2374)) {
                                  FUN_00422a20((void *)(iVar9 + 0x236c),piVar10,&local_64);
                                }
                                else {
                                  piVar10[4] = 0;
                                  piVar10[5] = 0xf;
                                  *(undefined1 *)piVar10 = 0;
                                  puVar17 = param_3;
                                  do {
                                    uVar6 = *puVar17;
                                    puVar17 = (uint *)((int)puVar17 + 1);
                                  } while ((char)uVar6 != '\0');
                                  FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                  *(int *)(iVar9 + 0x2370) = *(int *)(iVar9 + 0x2370) + 0x18;
                                }
                              }
                              else {
                                pbVar14 = &DAT_0044a3c8;
                                pbVar5 = param_2;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00420d90:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420d95;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00420d90;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420d95:
                                if (uVar6 == 0) {
                                  iVar9 = *(int *)this;
                                  piVar10 = *(int **)(iVar9 + 0x234c);
                                  if (piVar10 == *(int **)(iVar9 + 0x2350)) {
                                    FUN_00422a20((void *)(iVar9 + 0x2348),piVar10,&local_64);
                                  }
                                  else {
                                    piVar10[4] = 0;
                                    piVar10[5] = 0xf;
                                    *(undefined1 *)piVar10 = 0;
                                    puVar17 = param_3;
                                    do {
                                      uVar6 = *puVar17;
                                      puVar17 = (uint *)((int)puVar17 + 1);
                                    } while ((char)uVar6 != '\0');
                                    FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                    *(int *)(iVar9 + 0x234c) = *(int *)(iVar9 + 0x234c) + 0x18;
                                  }
                                }
                                else {
                                  pcVar13 = "PreDown";
                                  pbVar5 = param_2;
                                  do {
                                    bVar19 = *pbVar5;
                                    bVar22 = bVar19 < (byte)*pcVar13;
                                    if (bVar19 != *pcVar13) {
LAB_00420e20:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420e25;
                                    }
                                    if (bVar19 == 0) break;
                                    bVar19 = pbVar5[1];
                                    bVar22 = bVar19 < (byte)pcVar13[1];
                                    if (bVar19 != pcVar13[1]) goto LAB_00420e20;
                                    pbVar5 = pbVar5 + 2;
                                    pcVar13 = pcVar13 + 2;
                                  } while (bVar19 != 0);
                                  uVar6 = 0;
LAB_00420e25:
                                  if (uVar6 == 0) {
                                    iVar9 = *(int *)this;
                                    piVar10 = *(int **)(iVar9 + 0x2364);
                                    if (piVar10 == *(int **)(iVar9 + 0x2368)) {
                                      FUN_00422a20((void *)(iVar9 + 0x2360),piVar10,&local_64);
                                    }
                                    else {
                                      piVar10[4] = 0;
                                      piVar10[5] = 0xf;
                                      *(undefined1 *)piVar10 = 0;
                                      puVar17 = param_3;
                                      do {
                                        uVar6 = *puVar17;
                                        puVar17 = (uint *)((int)puVar17 + 1);
                                      } while ((char)uVar6 != '\0');
                                      FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                      *(int *)(iVar9 + 0x2364) = *(int *)(iVar9 + 0x2364) + 0x18;
                                    }
                                  }
                                  else {
                                    pcVar13 = "ExcludedIPs";
                                    do {
                                      bVar19 = *param_2;
                                      bVar22 = bVar19 < (byte)*pcVar13;
                                      if (bVar19 != *pcVar13) {
LAB_00420eb0:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_00420eb5;
                                      }
                                      if (bVar19 == 0) break;
                                      bVar19 = param_2[1];
                                      bVar22 = bVar19 < (byte)pcVar13[1];
                                      if (bVar19 != pcVar13[1]) goto LAB_00420eb0;
                                      param_2 = param_2 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar19 != 0);
                                    uVar6 = 0;
LAB_00420eb5:
                                    if (uVar6 == 0) {
                                      FUN_0040e1b0(param_3,&local_78);
                                      uVar6 = 0;
                                      local_68 = local_78;
                                      uVar8 = local_74 - (int)local_78 >> 2;
                                      if (uVar8 != 0) {
                                        do {
                                          cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                                          if (cVar4 == '\0') break;
                                          iVar9 = *(int *)this;
                                          puVar17 = *(uint **)(iVar9 + 0x2394);
                                          if (puVar17 == *(uint **)(iVar9 + 0x2398)) {
                                            FUN_00414bc0((void *)(iVar9 + 0x2390),puVar17,&local_5c);
                                          }
                                          else {
                                            *puVar17 = local_5c;
                                            puVar17[1] = uStack_58;
                                            puVar17[2] = uStack_54;
                                            puVar17[3] = uStack_50;
                                            *(undefined2 *)(puVar17 + 4) = local_4c;
                                            *(int *)(iVar9 + 0x2394) = *(int *)(iVar9 + 0x2394) + 0x12;
                                          }
                                          uVar6 = uVar6 + 1;
                                        } while (uVar6 < uVar8);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00420763;
          }
          uVar6 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xe) == uVar6) goto LAB_00420763;
          uVar8 = uVar6 & 0xffff;
          *(short *)(iVar9 + 0xe) = (short)uVar6;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar6 = (uint)*(ushort *)(iVar9 + 0xc);
        }
        cVar4 = (**(code **)**(undefined4 **)(iVar9 + 8))(uVar6,uVar8);
        if (cVar4 == '\0') {
          FUN_0040e0a0("ConfigureUdp failed",unaff_DI);
        }
      }
    }
  }
  else {
    pbVar5 = &DAT_0044a3e4;
    do {
      bVar19 = *param_1;
      bVar22 = bVar19 < *pbVar5;
      if (bVar19 != *pbVar5) {
LAB_00420f60:
        uVar6 = -(uint)bVar22 | 1;
        goto LAB_00420f65;
      }
      if (bVar19 == 0) break;
      bVar19 = param_1[1];
      bVar22 = bVar19 < pbVar5[1];
      if (bVar19 != pbVar5[1]) goto LAB_00420f60;
      param_1 = param_1 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar19 != 0);
    uVar6 = 0;
LAB_00420f65:
    if (uVar6 == 0) {
      if (param_2 == (byte *)0x0) {
        if (*(char *)((int)this + 0x50) == '\0') {
          FUN_0040e010("Missing [Interface].PrivateKey.",unaff_DI);
        }
        else {
          if (*(void **)((int)this + 0x48) != (void *)0x0) {
            FUN_00429d00(*(void **)((int)this + 0x48),(uint *)((int)this + 8));
            *(undefined4 *)((int)this + 0x48) = 0;
          }
          piVar10 = FUN_004296d0(*(int *)this + 0x20);
          *(int **)((int)this + 0x48) = piVar10;
          _memset((uint *)((int)this + 8),0,0x40);
        }
      }
      else if ((*(int **)(*(int *)this + 0x38) == (int *)0x0) ||
              (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 0xc))
                                 (*(undefined4 *)((int)this + 0x48),param_2,param_3), cVar4 == '\0')) {
        piVar10 = local_6c;
        pcVar13 = "PublicKey";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_00421010:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_00421015;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_00421010;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_00421015:
        if (uVar6 == 0) {
          local_64 = (uint *)0x20;
          puVar17 = param_3;
          do {
            uVar6 = *puVar17;
            puVar17 = (uint *)((int)puVar17 + 1);
          } while ((char)uVar6 != '\0');
          FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)(local_6c + 2),(uint *)&local_64)
          ;
        }
        else {
          pcVar13 = "PresharedKey";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00421081:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00421086;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00421081;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00421086:
          if (uVar6 == 0) {
            local_64 = (uint *)0x20;
            puVar17 = param_3;
            do {
              uVar6 = *puVar17;
              puVar17 = (uint *)((int)puVar17 + 1);
            } while ((char)uVar6 != '\0');
            piVar16 = local_6c + 10;
            uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)piVar16,
                                 (uint *)&local_64);
            if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
              iVar9 = piVar10[0x12];
              if (piVar16 == (int *)0x0) {
                *(undefined4 *)(iVar9 + 0x160) = 0;
                *(undefined4 *)(iVar9 + 0x164) = 0;
                *(undefined4 *)(iVar9 + 0x168) = 0;
                *(undefined4 *)(iVar9 + 0x16c) = 0;
                *(undefined4 *)(iVar9 + 0x170) = 0;
                *(undefined4 *)(iVar9 + 0x174) = 0;
                *(undefined4 *)(iVar9 + 0x178) = 0;
                *(undefined4 *)(iVar9 + 0x17c) = 0;
              }
              else {
                iVar21 = piVar10[0xb];
                iVar2 = piVar10[0xc];
                iVar3 = piVar10[0xd];
                *(int *)(iVar9 + 0x160) = *piVar16;
                *(int *)(iVar9 + 0x164) = iVar21;
                *(int *)(iVar9 + 0x168) = iVar2;
                *(int *)(iVar9 + 0x16c) = iVar3;
                iVar21 = piVar10[0xf];
                iVar2 = piVar10[0x10];
                iVar3 = piVar10[0x11];
                *(int *)(iVar9 + 0x170) = piVar10[0xe];
                *(int *)(iVar9 + 0x174) = iVar21;
                *(int *)(iVar9 + 0x178) = iVar2;
                *(int *)(iVar9 + 0x17c) = iVar3;
              }
            }
          }
          else {
            pcVar13 = "AllowedIPs";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_00421128:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_0042112d;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_00421128;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_0042112d:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if ((cVar4 == '\0') || (uVar7 = FUN_0042bd40((void *)local_6c[0x12],&local_5c), (char)uVar7 == '\0'))
                  break;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pcVar13 = "Endpoint";
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < (byte)*pcVar13;
                if (bVar19 != *pcVar13) {
LAB_004211b3:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_004211b8;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < (byte)pcVar13[1];
                if (bVar19 != pcVar13[1]) goto LAB_004211b3;
                pbVar5 = pbVar5 + 2;
                pcVar13 = pcVar13 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_004211b8:
              if (uVar6 == 0) {
                uVar20 = 1;
                iVar9 = _strncmp((char *)param_3,"tcp://",6);
                piVar10 = local_6c;
                if (iVar9 == 0) {
                  param_3 = (uint *)((int)param_3 + 6);
                  uVar20 = 2;
                }
                cVar4 = FUN_0040c530((char *)param_3,&local_48,(void *)local_6c[0x13]);
                if (cVar4 != '\0') {
                  iVar9 = piVar10[0x12];
                  *(undefined1 *)(iVar9 + 0x3b) = uVar20;
                  *(undefined1 *)(iVar9 + 0x3c) = uVar20;
                  *(uint *)(iVar9 + 0x68) = local_48;
                  *(uint *)(iVar9 + 0x6c) = uStack_44;
                  *(uint *)(iVar9 + 0x70) = uStack_40;
                  *(uint *)(iVar9 + 0x74) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x78) = local_38;
                  *(uint *)(iVar9 + 0x80) = local_30;
                  *(uint *)(iVar9 + 0x84) = local_48;
                  *(uint *)(iVar9 + 0x88) = uStack_44;
                  *(uint *)(iVar9 + 0x8c) = uStack_40;
                  *(uint *)(iVar9 + 0x90) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x94) = local_38;
                  *(uint *)(iVar9 + 0x9c) = local_30;
                }
              }
              else {
                pcVar13 = "PersistentKeepalive";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_00421270:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_00421275;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_00421270;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_00421275:
                if (uVar6 == 0) {
                  uVar6 = FID_conflict__atoi((char *)param_3);
                  if (uVar6 < 0x10000) {
                    *(uint *)(local_6c[0x12] + 0x218) = uVar6 * 1000;
                  }
                }
                else {
                  pcVar13 = "AllowMulticast";
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < (byte)*pcVar13;
                    if (bVar19 != *pcVar13) {
LAB_004212d0:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004212d5;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < (byte)pcVar13[1];
                    if (bVar19 != pcVar13[1]) goto LAB_004212d0;
                    pbVar5 = pbVar5 + 2;
                    pcVar13 = pcVar13 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004212d5:
                  if (uVar6 == 0) {
                    uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                    if ((char)uVar7 != '\0') {
                      *(byte *)(local_6c[0x12] + 0x37) = local_5d;
                    }
                  }
                  else {
                    pcVar13 = "Features";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_00421325:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_0042132a;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_00421325;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_0042132a:
                    if (uVar6 == 0) {
                      FUN_0040e1b0(param_3,&local_78);
                      uVar8 = 0;
                      local_68 = local_78;
                      uVar6 = local_74 - (int)local_78 >> 2;
                      if (uVar6 != 0) {
                        do {
                          piVar10 = *(int **)((int)local_78 + uVar8 * 4);
                          piVar16 = piVar10;
                          do {
                            iVar9 = *piVar16;
                            piVar16 = (int *)((int)piVar16 + 1);
                          } while ((char)iVar9 != '\0');
                          iVar9 = (int)piVar16 - (int)((int)piVar10 + 1);
                          iVar21 = 2;
                          if (iVar9 != 0) {
                            cVar4 = *(char *)((int)piVar10 + iVar9 + -1);
                            if (cVar4 == '?') {
                              iVar21 = 1;
                            }
                            else {
                              if (cVar4 != '!') goto LAB_00421389;
                              iVar21 = 3;
                            }
                            iVar9 = iVar9 + -1;
                          }
LAB_00421389:
                          if ((((iVar9 != 10) || (*piVar10 != 0x72627968)) || (piVar10[1] != 0x745f6469)) ||
                             ((short)piVar10[2] != 0x7063)) break;
                          uVar8 = uVar8 + 1;
                          *(byte *)((iVar21 + 0x60U >> 4) + 0x3d + local_6c[0x12]) = (byte)(iVar21 + 0x60U) & 3;
                        } while (uVar8 < uVar6);
                      }
                    }
                    else {
                      pcVar13 = "Ciphers";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00421404:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00421409;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00421404;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00421409:
                      if (uVar6 != 0) {
                        uVar20 = 1;
                        pcVar13 = "Ciphers!";
                        do {
                          bVar19 = *param_2;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00421434:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00421439;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = param_2[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00421434;
                          param_2 = param_2 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00421439:
                        if (uVar6 != 0) goto LAB_00420763;
                      }
                      FUN_0040e1b0(param_3,&local_78);
                      uVar6 = 0;
                      uVar8 = local_74 - (int)local_78 >> 2;
                      local_68 = local_78;
                      *(undefined1 *)(local_6c[0x12] + 0xa4) = uVar20;
                      if (uVar8 != 0) {
                        do {
                          pbVar5 = *(byte **)((int)local_78 + uVar6 * 4);
                          pcVar13 = "chacha20-poly1305";
                          pbVar14 = pbVar5;
                          do {
                            bVar19 = *pbVar14;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_004214a0:
                              uVar11 = -(uint)bVar22 | 1;
                              goto LAB_004214a5;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar14[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_004214a0;
                            pbVar14 = pbVar14 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar11 = 0;
LAB_004214a5:
                          if (uVar11 == 0) {
                            cVar4 = '\0';
                          }
                          else {
                            pbVar15 = &DAT_0044a274;
                            pbVar14 = pbVar5;
                            do {
                              bVar19 = *pbVar14;
                              bVar22 = bVar19 < *pbVar15;
                              if (bVar19 != *pbVar15) {
LAB_004214d7:
                                uVar11 = -(uint)bVar22 | 1;
                                goto LAB_004214dc;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar14[1];
                              bVar22 = bVar19 < pbVar15[1];
                              if (bVar19 != pbVar15[1]) goto LAB_004214d7;
                              pbVar14 = pbVar14 + 2;
                              pbVar15 = pbVar15 + 2;
                            } while (bVar19 != 0);
                            uVar11 = 0;
LAB_004214dc:
                            if (uVar11 == 0) {
                              cVar4 = '\x01';
                            }
                            else {
                              pbVar15 = &DAT_0044a280;
                              pbVar14 = pbVar5;
                              do {
                                bVar19 = *pbVar14;
                                bVar22 = bVar19 < *pbVar15;
                                if (bVar19 != *pbVar15) {
LAB_00421510:
                                  uVar11 = -(uint)bVar22 | 1;
                                  goto LAB_00421515;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar14[1];
                                bVar22 = bVar19 < pbVar15[1];
                                if (bVar19 != pbVar15[1]) goto LAB_00421510;
                                pbVar14 = pbVar14 + 2;
                                pbVar15 = pbVar15 + 2;
                              } while (bVar19 != 0);
                              uVar11 = 0;
LAB_00421515:
                              if (uVar11 == 0) {
                                cVar4 = '\x02';
                              }
                              else {
                                pbVar14 = &DAT_0044a28c;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00421543:
                                    uVar11 = -(uint)bVar22 | 1;
                                    goto LAB_00421548;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00421543;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar11 = 0;
LAB_00421548:
                                if (uVar11 != 0) break;
                                cVar4 = '\x03';
                              }
                            }
                          }
                          iVar9 = local_6c[0x12];
                          if (*(byte *)(iVar9 + 0xa5) == 4) break;
                          if ((cVar4 != '\x01') && (cVar4 != '\x02')) {
                            *(char *)(*(byte *)(iVar9 + 0xa5) + 0xa6 + iVar9) = cVar4;
                            *(char *)(iVar9 + 0xa5) = *(char *)(iVar9 + 0xa5) + '\x01';
                          }
                          uVar6 = uVar6 + 1;
                        } while (uVar6 < uVar8);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00420763:
  if (local_68 != (void *)0x0) {
    pvVar18 = local_68;
    if ((0xfff < (local_70 - (int)local_68 & 0xfffffffcU)) &&
       (pvVar18 = *(void **)((int)local_68 + -4), 0x1f < (uint)((int)local_68 + (-4 - (int)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pvVar18);
  }
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- caller: FUN_00422150 @ 00422150

void __fastcall FUN_00422150(void *param_1,uint *param_2,undefined4 *param_3)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  uint *puVar4;
  uint *puVar5;
  uint ****_Str;
  int iVar6;
  uint ****ppppuVar7;
  uint uVar8;
  byte *pbVar9;
  char *pcVar10;
  uint *****pppppuVar11;
  void *pvVar12;
  undefined4 *puVar13;
  uint *****pppppuVar14;
  uint ****ppppuVar15;
  undefined4 unaff_EDI;
  bool bVar16;
  undefined8 uVar17;
  int local_c4;
  uint ****local_c0;
  uint *****local_bc;
  undefined4 *local_b8;
  uint *****local_b4;
  uint *****local_b0;
  uint *****local_ac;
  int *local_a8;
  uint *****local_a4;
  char local_9e;
  char local_9d;
  void *local_9c;
  int local_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int local_88;
  int iStack_84;
  int local_80;
  uint *****local_7c [5];
  uint local_68;
  uint local_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined2 local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  local_b8 = param_3;
  local_9c = param_1;
  FUN_00409810(local_7c,param_2);
  local_b4 = (uint *****)0x0;
  pppppuVar11 = (uint *****)0x0;
  param_3[4] = 0;
  local_bc = (uint *****)0x0;
  local_ac = (uint *****)0x0;
  local_9e = '\0';
  local_9d = '\0';
  local_a8 = (int *)0x0;
  local_b0 = (uint *****)0x0;
  if (0xf < (uint)param_3[5]) {
    param_3 = (undefined4 *)*param_3;
  }
  *(undefined1 *)param_3 = 0;
  pppppuVar14 = (uint *****)local_7c;
  if (0xf < local_68) {
    pppppuVar14 = local_7c[0];
  }
  while( true ) {
    local_a4 = pppppuVar14;
    puVar4 = FUN_0042dd80((uint *)pppppuVar14,'\n');
    if (puVar4 != (uint *)0x0) {
      *(undefined1 *)puVar4 = 0;
    }
    if (*(char *)pppppuVar14 != '\0') {
      puVar5 = FUN_0042dd80((uint *)pppppuVar14,'=');
      if (puVar5 == (uint *)0x0) goto LAB_00422970;
      *(undefined1 *)puVar5 = 0;
      local_c0 = (uint ****)((int)puVar5 + 1);
      if (pppppuVar11 == local_bc) {
        FUN_0040e270(&local_b4,pppppuVar11,&local_a4,&local_c0);
        local_bc = local_ac;
        pppppuVar11 = local_b0;
      }
      else {
        *pppppuVar11 = (uint ****)pppppuVar14;
        pppppuVar11[1] = local_c0;
        local_b0 = pppppuVar11 + 2;
        pppppuVar11 = local_b0;
      }
    }
    if (puVar4 == (uint *)0x0) break;
    pppppuVar14 = (uint *****)((int)puVar4 + 1);
  }
  local_a4 = local_b4;
  if (local_b4 != pppppuVar11) {
LAB_00422270:
    pvVar12 = local_9c;
    piVar2 = local_a8;
    ppppuVar15 = *local_a4;
    pbVar9 = &DAT_0044a604;
    _Str = local_a4[1];
    ppppuVar7 = ppppuVar15;
    do {
      bVar1 = *(byte *)ppppuVar7;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_004222a0:
        uVar8 = -(uint)bVar16 | 1;
        goto LAB_004222a5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppppuVar7 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_004222a0;
      ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar8 = 0;
LAB_004222a5:
    if (uVar8 == 0) {
      pbVar9 = &DAT_0044a244;
      goto LAB_004228d0;
    }
    pbVar9 = &DAT_0044a608;
    ppppuVar7 = ppppuVar15;
    do {
      bVar1 = *(byte *)ppppuVar7;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_004222d4:
        uVar8 = -(uint)bVar16 | 1;
        goto LAB_004222d9;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppppuVar7 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_004222d4;
      ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar8 = 0;
LAB_004222d9:
    if (uVar8 == 0) {
      pbVar9 = &DAT_0044a244;
      do {
        bVar1 = *(byte *)_Str;
        bVar16 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00422302:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422307;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)_Str + 1);
        bVar16 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00422302;
        _Str = (uint ****)((int)_Str + 2);
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422307:
      if (uVar8 != 0) goto LAB_0042295e;
      local_9e = '\x01';
    }
    else {
      if (local_9e == '\0') goto LAB_0042295e;
      pcVar10 = "private_key";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422350:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422355;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422350;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422355:
      if (uVar8 == 0) {
        uVar8 = FUN_0040e130((char *)_Str,(int)&local_2c);
        pvVar12 = local_9c;
        if ((char)uVar8 == '\0') goto LAB_0042295e;
        FUN_00429640((void *)((int)local_9c + 0x20),&local_2c);
        goto LAB_004228ac;
      }
      pcVar10 = "listen_port";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_004223b0:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_004223b5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_004223b0;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_004223b5:
      if (uVar8 == 0) {
        uVar8 = FID_conflict__atoi((char *)_Str);
        pvVar12 = local_9c;
        if (*(ushort *)((int)local_9c + 0xc) != uVar8) {
          *(short *)((int)local_9c + 0xc) = (short)uVar8;
          if ((*(char *)((int)local_9c + 0x17) != '\0') &&
             (cVar3 = (**(code **)**(undefined4 **)((int)local_9c + 8))
                                (uVar8 & 0xffff,*(undefined2 *)((int)local_9c + 0xe)), cVar3 == '\0')) {
            FUN_0040e0a0("ConfigureUdp failed",(char)unaff_EDI);
          }
        }
        goto LAB_004228ac;
      }
      pcVar10 = "replace_peers";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422437:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_0042243c;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422437;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_0042243c:
      if (uVar8 == 0) {
        pbVar9 = &DAT_0044a238;
        do {
          bVar1 = *(byte *)_Str;
          bVar16 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_00422465:
            uVar8 = -(uint)bVar16 | 1;
            goto LAB_0042246a;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)_Str + 1);
          bVar16 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_00422465;
          _Str = (uint ****)((int)_Str + 2);
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        uVar8 = 0;
LAB_0042246a:
        if (uVar8 != 0) goto LAB_0042295e;
        piVar2 = *(int **)((int)local_9c + 0x30);
        while (piVar2 != (int *)0x0) {
          FUN_00429ab0(piVar2);
          piVar2 = *(int **)((int)pvVar12 + 0x30);
        }
        goto LAB_004228ac;
      }
      pcVar10 = "address";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_004224c0:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_004224c5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_004224c0;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_004224c5:
      if (uVar8 == 0) {
        cVar3 = FUN_0040bde0((uint *)_Str,(int)&local_64);
        pvVar12 = local_9c;
        if (cVar3 == '\0') goto LAB_0042295e;
        if (local_9d == '\0') {
          local_9d = '\x01';
          *(undefined4 *)((int)local_9c + 0x2334) = *(undefined4 *)((int)local_9c + 0x2330);
        }
        puVar4 = *(uint **)((int)local_9c + 0x2334);
        if (puVar4 == *(uint **)((int)local_9c + 0x2338)) {
          FUN_00414bc0((void *)((int)local_9c + 0x2330),puVar4,&local_64);
        }
        else {
          *puVar4 = local_64;
          puVar4[1] = uStack_60;
          puVar4[2] = uStack_5c;
          puVar4[3] = uStack_58;
          *(undefined2 *)(puVar4 + 4) = local_54;
          *(int *)((int)local_9c + 0x2334) = *(int *)((int)local_9c + 0x2334) + 0x12;
        }
        goto LAB_004228ac;
      }
      pcVar10 = "public_key";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422560:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422565;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422560;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422565:
      if (uVar8 == 0) {
        uVar8 = FUN_0040e130((char *)_Str,(int)&local_50);
        pvVar12 = local_9c;
        if ((char)uVar8 == '\0') goto LAB_0042295e;
        uVar17 = FUN_0040a7f0(local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34);
        iVar6 = FUN_0042c760((void *)((int)pvVar12 + 0x7c),&local_c4,(int *)&local_50,(uint)uVar17);
        iVar6 = *(int *)(iVar6 + 4);
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)pvVar12 + 0x80);
        }
        if ((iVar6 == *(int *)((int)pvVar12 + 0x80)) || (local_a8 = *(int **)(iVar6 + 0x28), local_a8 == (int *)0x0)) {
          local_a8 = FUN_004296d0((int)pvVar12 + 0x20);
          FUN_00429d00(local_a8,&local_50);
        }
        goto LAB_004228ac;
      }
      if (local_a8 != (int *)0x0) {
        pcVar10 = "remove";
        ppppuVar7 = ppppuVar15;
        do {
          bVar1 = *(byte *)ppppuVar7;
          bVar16 = bVar1 < (byte)*pcVar10;
          if (bVar1 != *pcVar10) {
LAB_00422640:
            uVar8 = -(uint)bVar16 | 1;
            goto LAB_00422645;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppppuVar7 + 1);
          bVar16 = bVar1 < (byte)pcVar10[1];
          if (bVar1 != pcVar10[1]) goto LAB_00422640;
          ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
          pcVar10 = pcVar10 + 2;
        } while (bVar1 != 0);
        uVar8 = 0;
LAB_00422645:
        if (uVar8 == 0) {
          pbVar9 = &DAT_0044a238;
          do {
            bVar1 = *(byte *)_Str;
            bVar16 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_00422670:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_00422675;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)_Str + 1);
            bVar16 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_00422670;
            _Str = (uint ****)((int)_Str + 2);
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_00422675:
          if (uVar8 != 0) goto LAB_0042295e;
          FUN_00429ab0(local_a8);
          local_a8 = (int *)0x0;
        }
        else {
          pcVar10 = "preshared_key";
          ppppuVar7 = ppppuVar15;
          do {
            bVar1 = *(byte *)ppppuVar7;
            bVar16 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_004226b8:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_004226bd;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppppuVar7 + 1);
            bVar16 = bVar1 < (byte)pcVar10[1];
            if (bVar1 != pcVar10[1]) goto LAB_004226b8;
            ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
            pcVar10 = pcVar10 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_004226bd:
          if (uVar8 == 0) {
            uVar8 = FUN_0040e130((char *)_Str,(int)&local_2c);
            if ((char)uVar8 != '\0') {
              piVar2[0x58] = local_2c;
              piVar2[0x59] = iStack_28;
              piVar2[0x5a] = iStack_24;
              piVar2[0x5b] = iStack_20;
              piVar2[0x5c] = local_1c;
              piVar2[0x5d] = iStack_18;
              piVar2[0x5e] = iStack_14;
              piVar2[0x5f] = iStack_10;
              goto LAB_004228a6;
            }
            goto LAB_0042295e;
          }
          pcVar10 = "endpoint";
          ppppuVar7 = ppppuVar15;
          do {
            bVar1 = *(byte *)ppppuVar7;
            bVar16 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00422720:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_00422725;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppppuVar7 + 1);
            bVar16 = bVar1 < (byte)pcVar10[1];
            if (bVar1 != pcVar10[1]) goto LAB_00422720;
            ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
            pcVar10 = pcVar10 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_00422725:
          if (uVar8 == 0) {
            cVar3 = FUN_0040c530((char *)_Str,&local_98,(void *)0x0);
            if (cVar3 == '\0') goto LAB_0042295e;
            *(undefined2 *)((int)piVar2 + 0x3b) = 0x101;
            piVar2[0x1a] = local_98;
            piVar2[0x1b] = iStack_94;
            piVar2[0x1c] = iStack_90;
            piVar2[0x1d] = iStack_8c;
            *(ulonglong *)(piVar2 + 0x1e) = CONCAT44(iStack_84,local_88);
            piVar2[0x20] = local_80;
            piVar2[0x21] = local_98;
            piVar2[0x22] = iStack_94;
            piVar2[0x23] = iStack_90;
            piVar2[0x24] = iStack_8c;
            piVar2[0x25] = local_88;
            piVar2[0x26] = iStack_84;
            piVar2[0x27] = local_80;
          }
          else {
            pcVar10 = "persistent_keepalive_interval";
            ppppuVar7 = ppppuVar15;
            do {
              bVar1 = *(byte *)ppppuVar7;
              bVar16 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_004227c0:
                uVar8 = -(uint)bVar16 | 1;
                goto LAB_004227c5;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppppuVar7 + 1);
              bVar16 = bVar1 < (byte)pcVar10[1];
              if (bVar1 != pcVar10[1]) goto LAB_004227c0;
              ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
              pcVar10 = pcVar10 + 2;
            } while (bVar1 != 0);
            uVar8 = 0;
LAB_004227c5:
            if (uVar8 == 0) {
              uVar8 = FID_conflict__atoi((char *)_Str);
              if (0xffff < uVar8) goto LAB_0042295e;
              piVar2[0x86] = uVar8 * 1000;
            }
            else {
              pcVar10 = "replace_allowed_ips";
              ppppuVar7 = ppppuVar15;
              do {
                bVar1 = *(byte *)ppppuVar7;
                bVar16 = bVar1 < (byte)*pcVar10;
                if (bVar1 != *pcVar10) {
LAB_00422815:
                  uVar8 = -(uint)bVar16 | 1;
                  goto LAB_0042281a;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppuVar7 + 1);
                bVar16 = bVar1 < (byte)pcVar10[1];
                if (bVar1 != pcVar10[1]) goto LAB_00422815;
                ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
                pcVar10 = pcVar10 + 2;
              } while (bVar1 != 0);
              uVar8 = 0;
LAB_0042281a:
              if (uVar8 == 0) {
                pbVar9 = &DAT_0044a238;
                do {
                  bVar1 = *(byte *)_Str;
                  bVar16 = bVar1 < *pbVar9;
                  if (bVar1 != *pbVar9) {
LAB_00422843:
                    uVar8 = -(uint)bVar16 | 1;
                    goto LAB_00422848;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)_Str + 1);
                  bVar16 = bVar1 < pbVar9[1];
                  if (bVar1 != pbVar9[1]) goto LAB_00422843;
                  _Str = (uint ****)((int)_Str + 2);
                  pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                uVar8 = 0;
LAB_00422848:
                if (uVar8 != 0) goto LAB_0042295e;
                FUN_0042bf30(local_a8);
              }
              else {
                pcVar10 = "allowed_ip";
                do {
                  bVar1 = *(byte *)ppppuVar15;
                  bVar16 = bVar1 < (byte)*pcVar10;
                  if (bVar1 != *pcVar10) {
LAB_00422880:
                    uVar8 = -(uint)bVar16 | 1;
                    goto LAB_00422885;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)ppppuVar15 + 1);
                  bVar16 = bVar1 < (byte)pcVar10[1];
                  if (bVar1 != pcVar10[1]) goto LAB_00422880;
                  ppppuVar15 = (uint ****)((int)ppppuVar15 + 2);
                  pcVar10 = pcVar10 + 2;
                } while (bVar1 != 0);
                uVar8 = 0;
LAB_00422885:
                if (uVar8 == 0) {
                  cVar3 = FUN_0040bde0((uint *)_Str,(int)&local_64);
                  if (cVar3 == '\0') goto LAB_0042295e;
                  FUN_0042bd40(piVar2,&local_64);
                }
              }
            }
          }
        }
      }
    }
LAB_004228a6:
    pvVar12 = local_9c;
LAB_004228ac:
    local_a4 = local_a4 + 2;
    if (local_a4 == local_b0) goto LAB_0042290c;
    goto LAB_00422270;
  }
LAB_00422922:
  pppppuVar11 = local_b4;
  iVar6 = local_b8[4];
  if ((uint)(local_b8[5] - iVar6) < 9) {
    local_c0 = (uint ****)((uint)local_c0 & 0xffffff00);
    FUN_0040e540(local_b8,9,local_c0,(uint *)"errno=0\n\n",9);
  }
  else {
    local_b8[4] = iVar6 + 9;
    puVar13 = local_b8;
    if (0xf < (uint)local_b8[5]) {
      puVar13 = (undefined4 *)*local_b8;
    }
    FUN_0042e660((uint *)(iVar6 + (int)puVar13),(uint *)"errno=0\n\n",9);
    *(undefined1 *)(iVar6 + 9 + (int)puVar13) = 0;
  }
  goto LAB_00422999;
  while( true ) {
    bVar1 = *(byte *)((int)_Str + 1);
    bVar16 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_004228f0;
    _Str = (uint ****)((int)_Str + 2);
    pbVar9 = pbVar9 + 2;
    if (bVar1 == 0) break;
LAB_004228d0:
    bVar1 = *(byte *)_Str;
    bVar16 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_004228f0:
      uVar8 = -(uint)bVar16 | 1;
      goto LAB_004228f5;
    }
    if (bVar1 == 0) break;
  }
  uVar8 = 0;
LAB_004228f5:
  if (uVar8 == 0) {
    FUN_00421d10((int)local_9c,local_b8);
LAB_0042290c:
    if (local_9d != '\0') {
      FUN_00416140(pvVar12);
    }
    goto LAB_00422922;
  }
LAB_0042295e:
  FUN_004096e0(local_b8,(uint *)"errno=1\n\n",9);
LAB_00422970:
  pppppuVar11 = local_b4;
LAB_00422999:
  if (pppppuVar11 != (uint *****)0x0) {
    pppppuVar14 = pppppuVar11;
    if ((0xfff < ((int)local_bc - (int)pppppuVar11 & 0xfffffff8U)) &&
       (pppppuVar14 = (uint *****)pppppuVar11[-1], 0x1f < (uint)((int)pppppuVar11 + (-4 - (int)pppppuVar14))))
    goto LAB_00422a0f;
    FUN_0042cf8d(pppppuVar14);
  }
  if (0xf < local_68) {
    pppppuVar11 = local_7c[0];
    if ((0xfff < local_68 + 1) &&
       (pppppuVar11 = (uint *****)local_7c[0][-1], 0x1f < (uint)((int)local_7c[0] + (-4 - (int)pppppuVar11)))) {
LAB_00422a0f:
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pppppuVar11);
  }
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- caller: FUN_004215c0 @ 004215c0

void __fastcall FUN_004215c0(int param_1,uint *param_2,int param_3,undefined4 param_4)

{
  uint *******pppppppuVar1;
  char cVar2;
  undefined1 *puVar3;
  uint *******pppppppuVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_EDI;
  uint *******pppppppuVar8;
  undefined1 auStack_c8 [11];
  undefined1 local_bd;
  int local_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  uint *******local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  int local_98 [2];
  uint local_90 [16];
  void *local_50;
  undefined4 local_4c;
  undefined1 local_48;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_14;
  
  local_14 = DAT_0044f008 ^ (uint)auStack_c8;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  local_a0 = 0;
  local_9c = 0xf;
  local_b0[0] = (uint *******)((uint)local_b0[0] & 0xffffff00);
  puVar5 = param_2;
  do {
    uVar7 = *puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while ((char)uVar7 != '\0');
  local_bc = param_1;
  FUN_004096e0(local_b0,param_2,(int)puVar5 - ((int)param_2 + 1));
  pppppppuVar8 = (uint *******)local_b0;
  if (0xf < local_9c) {
    pppppppuVar8 = local_b0[0];
  }
  local_98[0] = local_bc;
  local_b4 = (undefined1 *)(param_3 + (int)pppppppuVar8);
  local_50 = (void *)0x0;
  local_4c = param_4;
  local_48 = 0;
  while( true ) {
    puVar3 = local_b4;
    local_b8 = _memchr(pppppppuVar8,10,(int)local_b4 - (int)pppppppuVar8);
    if (local_b8 != (undefined1 *)0x0) {
      *local_b8 = 0;
      puVar3 = local_b8;
    }
    uVar6 = 0;
    uVar7 = (int)puVar3 - (int)pppppppuVar8;
    if (uVar7 != 0) {
      do {
        if ((*(byte *)(uVar6 + (int)pppppppuVar8) < 0x20) &&
           ((1 << (*(byte *)(uVar6 + (int)pppppppuVar8) & 0x1f) & 0x2600U) == 0)) {
          FUN_0040e010("File is not a config file",(char)unaff_EDI);
          local_bd = 0;
          goto LAB_00421845;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
    }
    puVar3 = _memchr(pppppppuVar8,0x23,uVar7);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
      uVar7 = (int)puVar3 - (int)pppppppuVar8;
    }
    while ((uVar7 != 0 &&
           ((((cVar2 = *(char *)((uVar7 - 1) + (int)pppppppuVar8), cVar2 == ' ' || (cVar2 == '\r')) || (cVar2 == '\n'))
            || (cVar2 == '\t'))))) {
      uVar7 = uVar7 - 1;
      *(undefined1 *)(uVar7 + (int)pppppppuVar8) = 0;
    }
    if (*(char *)pppppppuVar8 == '[') {
      if (uVar7 < 0x20) {
        FUN_0042f280(&local_40,(uint *)pppppppuVar8,uVar7 + 1);
        cVar2 = FUN_00420280(local_98,(byte *)&local_40,(byte *)0x0,(uint *)0x0);
        if (cVar2 == '\0') {
          FUN_0040e010("Error parsing %s",(char)&local_40);
          local_bd = 0;
          goto LAB_00421845;
        }
      }
    }
    else if (*(char *)pppppppuVar8 != '\0') {
      pppppppuVar4 = (uint *******)FUN_0042dd80((uint *)pppppppuVar8,'=');
      pppppppuVar1 = pppppppuVar4;
      if (pppppppuVar4 == (uint *******)0x0) {
        FUN_0040e010("Missing = on line: %s",(char)pppppppuVar8);
        local_bd = 0;
        goto LAB_00421845;
      }
      for (; (pppppppuVar8 < pppppppuVar1 &&
             (((cVar2 = *(char *)((int)pppppppuVar1 + -1), cVar2 == ' ' || (cVar2 == '\r')) ||
              ((cVar2 == '\n' || (cVar2 == '\t')))))); pppppppuVar1 = (uint *******)((int)pppppppuVar1 + -1)) {
      }
      *(undefined1 *)pppppppuVar1 = 0;
      do {
        do {
          cVar2 = *(char *)((int)pppppppuVar4 + 1);
          pppppppuVar4 = (uint *******)((int)pppppppuVar4 + 1);
        } while (cVar2 == ' ');
      } while (((cVar2 == '\r') || (cVar2 == '\n')) || (cVar2 == '\t'));
      cVar2 = FUN_00420280(local_98,(byte *)&local_40,(byte *)pppppppuVar8,(uint *)pppppppuVar4);
      if (cVar2 == '\0') {
        FUN_0040e010("Error parsing %s.%s = %s",(char)&local_40);
        local_bd = 0;
        goto LAB_00421845;
      }
    }
    if (local_b8 == (undefined1 *)0x0) break;
    pppppppuVar8 = (uint *******)(local_b8 + 1);
  }
  if (local_50 != (void *)0x0) {
    FUN_00429d00(local_50,local_90);
    local_50 = (void *)0x0;
  }
  if ((*(int **)(local_bc + 0x38) == (int *)0x0) ||
     (cVar2 = (**(code **)(**(int **)(local_bc + 0x38) + 0x10))(), cVar2 != '\0')) {
    local_bd = 1;
  }
  else {
    local_bd = 0;
  }
LAB_00421845:
  if (0xf < local_9c) {
    pppppppuVar8 = local_b0[0];
    if ((0xfff < local_9c + 1) &&
       (pppppppuVar8 = (uint *******)local_b0[0][-1], 0x1f < (uint)((int)local_b0[0] + (-4 - (int)pppppppuVar8)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pppppppuVar8);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_c8);
  return;
}


// ----- caller: FUN_00429640 @ 00429640

void __thiscall FUN_00429640(void *this,undefined4 *param_1)

{
  uint *puVar1;
  void *this_00;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)((int)this + 0xc0) = *param_1;
  *(undefined4 *)((int)this + 0xc4) = uVar2;
  *(undefined4 *)((int)this + 200) = uVar3;
  *(undefined4 *)((int)this + 0xcc) = uVar4;
  puVar1 = (uint *)((int)this + 0xe0);
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)((int)this + 0xd0) = param_1[4];
  *(undefined4 *)((int)this + 0xd4) = uVar2;
  *(undefined4 *)((int)this + 0xd8) = uVar3;
  *(undefined4 *)((int)this + 0xdc) = uVar4;
  FUN_004200c0((undefined1 *)puVar1,(byte *)((int)this + 0xc0),&DAT_004481e8);
  FUN_00429550((void *)((int)this + 0x100),(uint *)&DAT_004482ac,8,puVar1,0x20);
  FUN_00429550((void *)((int)this + 0x120),(uint *)&DAT_00448270,8,puVar1,0x20);
  this_00 = *(void **)((int)this + 0x10);
  *(undefined1 *)((int)this + 0x85) = 1;
  for (; this_00 != (void *)0x0; this_00 = *(void **)((int)this_00 + 4)) {
    FUN_00429d00(this_00,(uint *)((int)this_00 + 0x140));
  }
  return;
}


// ----- callee: FUN_0042c360 @ 0042c360

undefined4 __thiscall FUN_0042c360(void *this,uint *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int local_10 [3];
  
  uVar2 = *param_1;
  piVar4 = _Find_last<>(this,local_10,(int *)param_1,uVar2);
  piVar4 = (int *)piVar4[1];
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)(*(int *)((int)this + 0xc) + (*(uint *)((int)this + 0x18) & uVar2) * 8);
  if ((int *)piVar1[1] == piVar4) {
    if ((int *)*piVar1 == piVar4) {
      iVar3 = *(int *)((int)this + 4);
      *piVar1 = iVar3;
      piVar1[1] = iVar3;
    }
    else {
      piVar1[1] = piVar4[1];
    }
  }
  else if ((int *)*piVar1 == piVar4) {
    *piVar1 = *piVar4;
  }
  iVar3 = *piVar4;
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  *(int *)piVar4[1] = iVar3;
  *(int *)(iVar3 + 4) = piVar4[1];
  FUN_0042cf8d(piVar4);
  return 1;
}


// ----- callee: FUN_00429c00 @ 00429c00

void __fastcall FUN_00429c00(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pvVar2 = *(void **)*puVar1;
    if (puVar1[1] != 0) {
      FUN_00429970(pvVar2,(int)puVar1);
    }
    if (puVar1[6] != 0) {
      FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
      puVar1[6] = 0;
    }
    *(undefined1 *)(puVar1 + 5) = 0;
    FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pvVar2 = *(void **)*puVar1;
    if (puVar1[1] != 0) {
      FUN_00429970(pvVar2,(int)puVar1);
    }
    if (puVar1[6] != 0) {
      FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
      puVar1[6] = 0;
    }
    *(undefined1 *)(puVar1 + 5) = 0;
    FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
  }
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pvVar2 = *(void **)*puVar1;
    if (puVar1[1] != 0) {
      FUN_00429970(pvVar2,(int)puVar1);
    }
    if (puVar1[6] != 0) {
      FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
      puVar1[6] = 0;
    }
    *(undefined1 *)(puVar1 + 5) = 0;
    FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
  }
  return;
}


// ----- callee: FUN_004200c0 @ 004200c0

void __fastcall FUN_004200c0(undefined1 *param_1,byte *param_2,byte *param_3)

{
  uint local_210 [20];
  uint local_1c0 [20];
  uint local_170 [20];
  uint local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  byte local_2c;
  byte bStack_2b;
  byte bStack_2a;
  byte bStack_29;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte local_1c;
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  bStack_2b = param_2[1];
  bStack_2a = param_2[2];
  bStack_29 = param_2[3];
  bStack_28 = param_2[4];
  bStack_27 = param_2[5];
  bStack_26 = param_2[6];
  bStack_25 = param_2[7];
  bStack_24 = param_2[8];
  bStack_23 = param_2[9];
  bStack_22 = param_2[10];
  bStack_21 = param_2[0xb];
  bStack_20 = param_2[0xc];
  bStack_1f = param_2[0xd];
  bStack_1e = param_2[0xe];
  bStack_1d = param_2[0xf];
  local_1c = param_2[0x10];
  bStack_1b = param_2[0x11];
  bStack_1a = param_2[0x12];
  bStack_19 = param_2[0x13];
  bStack_18 = param_2[0x14];
  bStack_17 = param_2[0x15];
  bStack_16 = param_2[0x16];
  bStack_15 = param_2[0x17];
  bStack_14 = param_2[0x18];
  bStack_13 = param_2[0x19];
  bStack_12 = param_2[0x1a];
  bStack_11 = param_2[0x1b];
  bStack_10 = param_2[0x1c];
  bStack_f = param_2[0x1d];
  bStack_e = param_2[0x1e];
  local_2c = *param_2 & 0xf8;
  bStack_d = param_2[0x1f] & 0x3f | 0x40;
  FUN_0041d7f0(local_170,param_3);
  FUN_0041e920(local_210,&local_88,(int)&local_2c,local_170);
  FUN_0041ec90(local_1c0,(int *)&local_88);
  FUN_0041cd80((longlong *)&local_120,(int *)local_210,(int *)local_1c0);
  FUN_0041d250(&local_120);
  FUN_0041d330(&local_120);
  local_88 = local_120;
  uStack_84 = uStack_11c;
  uStack_80 = uStack_118;
  uStack_7c = uStack_114;
  local_78 = local_110;
  uStack_74 = uStack_10c;
  uStack_70 = uStack_108;
  uStack_6c = uStack_104;
  local_68 = local_100;
  uStack_64 = uStack_fc;
  uStack_60 = uStack_f8;
  uStack_5c = uStack_f4;
  local_58 = local_f0;
  uStack_54 = uStack_ec;
  uStack_50 = uStack_e8;
  uStack_4c = uStack_e4;
  local_48 = local_e0;
  uStack_44 = uStack_dc;
  uStack_40 = uStack_d8;
  uStack_3c = uStack_d4;
  FUN_0041d330(&local_88);
  FUN_0041daf0(param_1,(int *)&local_88);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_00429550 @ 00429550

void __thiscall FUN_00429550(void *this,uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  uint local_8;
  
  local_8 = DAT_0044f008 ^ (uint)(local_54 + 0x14);
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,param_1,param_2);
  FUN_00419bc0(local_84,param_3,param_4);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  __security_check_cookie(local_8 ^ (uint)(local_54 + 0x14));
  return;
}


// ----- callee: FUN_0042c5a0 @ 0042c5a0

void __thiscall FUN_0042c5a0(void *this,int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float fVar10;
  undefined8 uVar11;
  undefined8 local_14;
  int *local_8;
  
  uVar11 = FUN_0040a7f0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],param_2[7]);
  uVar6 = (uint)uVar11;
  FUN_0042c760(this,(int *)&local_14,(int *)param_2,uVar6);
  if (local_14._4_4_ != 0) {
    *param_1 = local_14._4_4_;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  if (*(int *)((int)this + 8) == 0x5555555) {
                    /* WARNING: Subroutine does not return */
    FUN_0042cf49("unordered_map/set too long");
  }
  piVar3 = (int *)FUN_0042cfbe(0x30);
  uVar1 = param_2[1];
  uVar8 = param_2[2];
  uVar4 = param_2[3];
  piVar3[2] = *param_2;
  piVar3[3] = uVar1;
  piVar3[4] = uVar8;
  piVar3[5] = uVar4;
  uVar1 = param_2[4];
  uVar8 = param_2[5];
  uVar4 = param_2[6];
  uVar2 = param_2[7];
  piVar3[10] = 0;
  piVar3[6] = uVar1;
  piVar3[7] = uVar8;
  piVar3[8] = uVar4;
  piVar3[9] = uVar2;
  uVar1 = *(uint *)((int)this + 0x1c);
  iVar7 = *(int *)((int)this + 8) + 1;
  fVar10 = (float)((double)iVar7 + (double)(&DAT_0044b520)[-(iVar7 >> 0x1f)]);
  local_8 = piVar3;
  if (fVar10 / (float)((double)(int)uVar1 + (double)(&DAT_0044b520)[-((int)uVar1 >> 0x1f)]) <= *(float *)this) {
  }
  else {
    local_14 = (double)(fVar10 / *(float *)this);
    fVar9 = FUN_0043e440(local_14);
    local_14 = (double)fVar9;
    uVar4 = FUN_00440ea0();
    uVar8 = 8;
    if (8 < uVar4) {
      uVar8 = uVar4;
    }
    uVar4 = uVar1;
    if ((uVar1 < uVar8) && ((0x1ff < uVar1 || (uVar4 = uVar1 << 3, uVar1 << 3 < uVar8)))) {
      uVar4 = uVar8;
    }
    FUN_0042caf0(this,uVar4);
    piVar5 = (int *)FUN_0042c760(this,(int *)&local_14,piVar3 + 2,uVar6);
    local_14._0_4_ = *piVar5;
  }
  piVar5 = *(int **)((int)local_14 + 4);
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  *piVar3 = (int)local_14;
  piVar3[1] = (int)piVar5;
  *piVar5 = (int)piVar3;
  *(int **)((int)local_14 + 4) = piVar3;
  uVar6 = *(uint *)((int)this + 0x18) & uVar6;
  iVar7 = *(int *)((int)this + 0xc);
  if (*(int *)(iVar7 + uVar6 * 8) == *(int *)((int)this + 4)) {
    *(int **)(iVar7 + uVar6 * 8) = local_8;
  }
  else {
    if (*(int *)(iVar7 + uVar6 * 8) == (int)local_14) {
      *(int **)(iVar7 + uVar6 * 8) = local_8;
      *param_1 = (int)local_8;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    if (*(int **)(iVar7 + 4 + uVar6 * 8) != piVar5) goto LAB_0042c735;
  }
  *(int **)(iVar7 + 4 + uVar6 * 8) = local_8;
LAB_0042c735:
  *param_1 = (int)local_8;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}



// ===================== FUN_00429640 @ 00429640  anchors: [ObfuscateKey(win@00448270), ObfuscateKey(win@004482ac)] =====================

void __thiscall FUN_00429640(void *this,undefined4 *param_1)

{
  uint *puVar1;
  void *this_00;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)((int)this + 0xc0) = *param_1;
  *(undefined4 *)((int)this + 0xc4) = uVar2;
  *(undefined4 *)((int)this + 200) = uVar3;
  *(undefined4 *)((int)this + 0xcc) = uVar4;
  puVar1 = (uint *)((int)this + 0xe0);
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)((int)this + 0xd0) = param_1[4];
  *(undefined4 *)((int)this + 0xd4) = uVar2;
  *(undefined4 *)((int)this + 0xd8) = uVar3;
  *(undefined4 *)((int)this + 0xdc) = uVar4;
  FUN_004200c0((undefined1 *)puVar1,(byte *)((int)this + 0xc0),&DAT_004481e8);
  FUN_00429550((void *)((int)this + 0x100),(uint *)&DAT_004482ac,8,puVar1,0x20);
  FUN_00429550((void *)((int)this + 0x120),(uint *)&DAT_00448270,8,puVar1,0x20);
  this_00 = *(void **)((int)this + 0x10);
  *(undefined1 *)((int)this + 0x85) = 1;
  for (; this_00 != (void *)0x0; this_00 = *(void **)((int)this_00 + 4)) {
    FUN_00429d00(this_00,(uint *)((int)this_00 + 0x140));
  }
  return;
}


// ----- caller: FUN_00420280 @ 00420280

void __thiscall FUN_00420280(void *this,byte *param_1,byte *param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  char *pcVar13;
  byte *pbVar14;
  byte *pbVar15;
  int *piVar16;
  uint *puVar17;
  void *pvVar18;
  byte bVar19;
  undefined1 uVar20;
  int iVar21;
  char unaff_DI;
  bool bVar22;
  uint local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8 [16];
  uint local_88;
  char local_80;
  void *local_78;
  int local_74;
  int local_70;
  int *local_6c;
  void *local_68;
  uint *local_64;
  byte local_5d;
  uint local_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined2 local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c [8];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  uVar20 = 0;
  pcVar13 = "[Interface]";
  local_68 = (void *)0x0;
  local_78 = (void *)0x0;
  local_74 = 0;
  local_70 = 0;
  local_64 = param_3;
  pbVar5 = param_1;
  do {
    bVar19 = *pbVar5;
    bVar22 = bVar19 < (byte)*pcVar13;
    if (bVar19 != *pcVar13) {
LAB_004202e0:
      uVar6 = -(uint)bVar22 | 1;
      goto LAB_004202e5;
    }
    if (bVar19 == 0) break;
    bVar19 = pbVar5[1];
    bVar22 = bVar19 < (byte)pcVar13[1];
    if (bVar19 != pcVar13[1]) goto LAB_004202e0;
    pbVar5 = pbVar5 + 2;
    pcVar13 = pcVar13 + 2;
  } while (bVar19 != 0);
  uVar6 = 0;
LAB_004202e5:
  local_6c = this;
  if (uVar6 == 0) {
    if ((param_2 != (byte *)0x0) &&
       ((*(int **)(*(int *)this + 0x38) == (int *)0x0 ||
        (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 8))(param_2,param_3), cVar4 == '\0')))) {
      pcVar13 = "PrivateKey";
      pbVar5 = param_2;
      do {
        bVar19 = *pbVar5;
        bVar22 = bVar19 < (byte)*pcVar13;
        if (bVar19 != *pcVar13) {
LAB_00420340:
          uVar6 = -(uint)bVar22 | 1;
          goto LAB_00420345;
        }
        if (bVar19 == 0) break;
        bVar19 = pbVar5[1];
        bVar22 = bVar19 < (byte)pcVar13[1];
        if (bVar19 != pcVar13[1]) goto LAB_00420340;
        pbVar5 = pbVar5 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar19 != 0);
      uVar6 = 0;
LAB_00420345:
      if (uVar6 == 0) {
        local_64 = (uint *)0x20;
        puVar17 = param_3;
        do {
          uVar6 = *puVar17;
          puVar17 = (uint *)((int)puVar17 + 1);
        } while ((char)uVar6 != '\0');
        uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)local_2c,(uint *)&local_64)
        ;
        if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
          *(undefined1 *)((int)this + 0x50) = 1;
          FUN_00429640((void *)(*(int *)this + 0x20),local_2c);
        }
      }
      else {
        pcVar13 = "ListenPort";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_004203c2:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_004203c7;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_004203c2;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_004203c7:
        if (uVar6 == 0) {
          uVar8 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xc) == uVar8) goto LAB_00420763;
          uVar6 = uVar8 & 0xffff;
          *(short *)(iVar9 + 0xc) = (short)uVar8;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar8 = (uint)*(ushort *)(iVar9 + 0xe);
        }
        else {
          pcVar13 = "ListenPortTCP";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00420422:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00420427;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00420422;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00420427:
          if (uVar6 != 0) {
            pcVar13 = "Address";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_004204a5:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_004204aa;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_004204a5;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_004204aa:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if (cVar4 == '\0') break;
                  iVar9 = *(int *)this;
                  puVar17 = *(uint **)(iVar9 + 0x2334);
                  if (puVar17 == *(uint **)(iVar9 + 0x2338)) {
                    FUN_00414bc0((void *)(iVar9 + 0x2330),puVar17,&local_5c);
                  }
                  else {
                    *puVar17 = local_5c;
                    puVar17[1] = uStack_58;
                    puVar17[2] = uStack_54;
                    puVar17[3] = uStack_50;
                    *(undefined2 *)(puVar17 + 4) = local_4c;
                    *(int *)(iVar9 + 0x2334) = *(int *)(iVar9 + 0x2334) + 0x12;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pbVar14 = &DAT_0044a2d0;
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < *pbVar14;
                if (bVar19 != *pbVar14) {
LAB_00420550:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_00420555;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < pbVar14[1];
                if (bVar19 != pbVar14[1]) goto LAB_00420550;
                pbVar5 = pbVar5 + 2;
                pbVar14 = pbVar14 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_00420555:
              if (uVar6 == 0) {
                iVar9 = FID_conflict__atoi((char *)param_3);
                if ((0x23f < iVar9) && (iVar9 < 0x2711)) {
                  *(short *)(*(int *)this + 0x10) = (short)iVar9;
                }
              }
              else {
                pcVar13 = "Table";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_004205b0:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_004205b5;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_004205b0;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_004205b5:
                if (uVar6 == 0) {
                  pbVar5 = &DAT_0044a25c;
                  puVar17 = param_3;
                  do {
                    bVar19 = (byte)*puVar17;
                    bVar22 = bVar19 < *pbVar5;
                    if (bVar19 != *pbVar5) {
LAB_004205e4:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004205e9;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = *(byte *)((int)puVar17 + 1);
                    bVar22 = bVar19 < pbVar5[1];
                    if (bVar19 != pbVar5[1]) goto LAB_004205e4;
                    puVar17 = (uint *)((int)puVar17 + 2);
                    pbVar5 = pbVar5 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004205e9:
                  if (uVar6 == 0) {
                    *(undefined1 *)(*(int *)this + 0x14) = 0;
                  }
                  else {
                    pbVar5 = &DAT_0044a2dc;
                    do {
                      bVar19 = (byte)*param_3;
                      bVar22 = bVar19 < *pbVar5;
                      if (bVar19 != *pbVar5) {
LAB_00420620:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_00420625;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = *(byte *)((int)param_3 + 1);
                      bVar22 = bVar19 < pbVar5[1];
                      if (bVar19 != pbVar5[1]) goto LAB_00420620;
                      param_3 = (uint *)((int)param_3 + 2);
                      pbVar5 = pbVar5 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_00420625:
                    if (uVar6 == 0) {
                      *(undefined1 *)(*(int *)this + 0x14) = 1;
                    }
                  }
                }
                else {
                  pbVar14 = &DAT_0044a2e4;
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < *pbVar14;
                    if (bVar19 != *pbVar14) {
LAB_00420662:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_00420667;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < pbVar14[1];
                    if (bVar19 != pbVar14[1]) goto LAB_00420662;
                    pbVar5 = pbVar5 + 2;
                    pbVar14 = pbVar14 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_00420667:
                  if (uVar6 == 0) {
                    FUN_0040e1b0(param_3,&local_78);
                    puVar17 = (uint *)0x0;
                    local_68 = local_78;
                    local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                    if (local_64 != (uint *)0x0) {
                      do {
                        piVar10 = *(int **)((int)local_68 + (int)puVar17 * 4);
                        pvVar18 = *(void **)((int)this + 0x4c);
                        local_48 = 0;
                        uStack_44 = 0;
                        uStack_40 = 0;
                        uStack_3c = 0;
                        local_30 = 0;
                        local_38 = 0;
                        iVar9 = inet_pton(0x17,piVar10,&uStack_40);
                        if (iVar9 == 1) {
                          local_48 = CONCAT22(local_48._2_2_,0x17);
                        }
                        else {
                          iVar9 = inet_pton(2,piVar10,&uStack_44);
                          if (iVar9 == 1) {
                            local_48 = CONCAT22(local_48._2_2_,2);
                          }
                          else {
                            if (pvVar18 == (void *)0x0) break;
                            cVar4 = FUN_0040c0e0(pvVar18,piVar10,(int *)&local_48);
                            if (cVar4 == '\0') {
                              FUN_0040e010("Unable to resolve %s",(char)piVar10);
                              break;
                            }
                          }
                        }
                        this = local_6c;
                        iVar9 = *local_6c;
                        puVar1 = *(uint **)(iVar9 + 0x2340);
                        if (puVar1 == *(uint **)(iVar9 + 0x2344)) {
                          FUN_004181c0((void *)(iVar9 + 0x233c),puVar1,&local_48);
                        }
                        else {
                          *puVar1 = local_48;
                          puVar1[1] = uStack_44;
                          puVar1[2] = uStack_40;
                          puVar1[3] = uStack_3c;
                          *(undefined8 *)(puVar1 + 4) = local_38;
                          puVar1[6] = local_30;
                          *(int *)(iVar9 + 0x2340) = *(int *)(iVar9 + 0x2340) + 0x1c;
                        }
                        puVar17 = (uint *)((int)puVar17 + 1);
                      } while (puVar17 < local_64);
                    }
                  }
                  else {
                    pcVar13 = "BlockDNS";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_004207c4:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_004207c9;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_004207c4;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_004207c9:
                    if (uVar6 == 0) {
                      uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                      if ((char)uVar7 != '\0') {
                        *(byte *)(*(int *)this + 0x12) = local_5d;
                      }
                    }
                    else {
                      pcVar13 = "BlockInternet";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00420811:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00420816;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00420811;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00420816:
                      if (uVar6 == 0) {
                        bVar19 = 0xff;
                        FUN_0040e1b0(param_3,&local_78);
                        puVar17 = (uint *)0x0;
                        local_68 = local_78;
                        local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                        if (local_64 != (uint *)0x0) {
                          do {
                            pbVar5 = *(byte **)((int)local_68 + (int)puVar17 * 4);
                            pcVar13 = "route";
                            pbVar14 = pbVar5;
                            do {
                              bVar12 = *pbVar14;
                              bVar22 = bVar12 < (byte)*pcVar13;
                              if (bVar12 != *pcVar13) {
LAB_00420880:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420885;
                              }
                              if (bVar12 == 0) break;
                              bVar12 = pbVar14[1];
                              bVar22 = bVar12 < (byte)pcVar13[1];
                              if (bVar12 != pcVar13[1]) goto LAB_00420880;
                              pbVar14 = pbVar14 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar12 != 0);
                            uVar6 = 0;
LAB_00420885:
                            if (uVar6 == 0) {
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 1;
                            }
                            else {
                              pcVar13 = "firewall";
                              pbVar14 = pbVar5;
                              do {
                                bVar12 = *pbVar14;
                                bVar22 = bVar12 < (byte)*pcVar13;
                                if (bVar12 != *pcVar13) {
LAB_004208c4:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_004208c9;
                                }
                                if (bVar12 == 0) break;
                                bVar12 = pbVar14[1];
                                bVar22 = bVar12 < (byte)pcVar13[1];
                                if (bVar12 != pcVar13[1]) goto LAB_004208c4;
                                pbVar14 = pbVar14 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar12 != 0);
                              uVar6 = 0;
LAB_004208c9:
                              if (uVar6 != 0) {
                                pbVar15 = &DAT_0044a248;
                                pbVar14 = pbVar5;
                                do {
                                  bVar12 = *pbVar14;
                                  bVar22 = bVar12 < *pbVar15;
                                  if (bVar12 != *pbVar15) {
LAB_004208f8:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_004208fd;
                                  }
                                  if (bVar12 == 0) break;
                                  bVar12 = pbVar14[1];
                                  bVar22 = bVar12 < pbVar15[1];
                                  if (bVar12 != pbVar15[1]) goto LAB_004208f8;
                                  pbVar14 = pbVar14 + 2;
                                  pbVar15 = pbVar15 + 2;
                                } while (bVar12 != 0);
                                uVar6 = 0;
LAB_004208fd:
                                if (uVar6 != 0) {
                                  pbVar15 = &DAT_0044a25c;
                                  pbVar14 = pbVar5;
                                  do {
                                    bVar12 = *pbVar14;
                                    bVar22 = bVar12 < *pbVar15;
                                    if (bVar12 != *pbVar15) {
LAB_00420930:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420935;
                                    }
                                    if (bVar12 == 0) break;
                                    bVar12 = pbVar14[1];
                                    bVar22 = bVar12 < pbVar15[1];
                                    if (bVar12 != pbVar15[1]) goto LAB_00420930;
                                    pbVar14 = pbVar14 + 2;
                                    pbVar15 = pbVar15 + 2;
                                  } while (bVar12 != 0);
                                  uVar6 = 0;
LAB_00420935:
                                  if (uVar6 == 0) {
                                    bVar19 = 0;
                                  }
                                  else {
                                    pcVar13 = "default";
                                    pbVar14 = pbVar5;
                                    do {
                                      bVar12 = *pbVar14;
                                      bVar22 = bVar12 < (byte)*pcVar13;
                                      if (bVar12 != *pcVar13) {
LAB_00420967:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_0042096c;
                                      }
                                      if (bVar12 == 0) break;
                                      bVar12 = pbVar14[1];
                                      bVar22 = bVar12 < (byte)pcVar13[1];
                                      if (bVar12 != pcVar13[1]) goto LAB_00420967;
                                      pbVar14 = pbVar14 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar12 != 0);
                                    uVar6 = 0;
LAB_0042096c:
                                    if (uVar6 == 0) {
                                      bVar19 = 0xff;
                                    }
                                    else {
                                      pcVar13 = "persist";
                                      pbVar14 = pbVar5;
                                      do {
                                        bVar12 = *pbVar14;
                                        bVar22 = bVar12 < (byte)*pcVar13;
                                        if (bVar12 != *pcVar13) {
LAB_004209a0:
                                          uVar6 = -(uint)bVar22 | 1;
                                          goto LAB_004209a5;
                                        }
                                        if (bVar12 == 0) break;
                                        bVar12 = pbVar14[1];
                                        bVar22 = bVar12 < (byte)pcVar13[1];
                                        if (bVar12 != pcVar13[1]) goto LAB_004209a0;
                                        pbVar14 = pbVar14 + 2;
                                        pcVar13 = pcVar13 + 2;
                                      } while (bVar12 != 0);
                                      uVar6 = 0;
LAB_004209a5:
                                      if (uVar6 == 0) {
                                        bVar12 = 0;
                                        if (-1 < (char)bVar19) {
                                          bVar12 = bVar19;
                                        }
                                        bVar19 = bVar12 | 0x10;
                                      }
                                      else {
                                        pcVar13 = "allow_local";
                                        pbVar14 = pbVar5;
                                        do {
                                          bVar12 = *pbVar14;
                                          bVar22 = bVar12 < (byte)*pcVar13;
                                          if (bVar12 != *pcVar13) {
LAB_004209e1:
                                            uVar6 = -(uint)bVar22 | 1;
                                            goto LAB_004209e6;
                                          }
                                          if (bVar12 == 0) break;
                                          bVar12 = pbVar14[1];
                                          bVar22 = bVar12 < (byte)pcVar13[1];
                                          if (bVar12 != pcVar13[1]) goto LAB_004209e1;
                                          pbVar14 = pbVar14 + 2;
                                          pcVar13 = pcVar13 + 2;
                                        } while (bVar12 != 0);
                                        uVar6 = 0;
LAB_004209e6:
                                        if (uVar6 == 0) {
                                          bVar12 = 0;
                                          if (-1 < (char)bVar19) {
                                            bVar12 = bVar19;
                                          }
                                          bVar19 = bVar12 | 0x20;
                                        }
                                        else {
                                          FUN_0040e010("Unknown mode in BlockInternet: %s",(char)pbVar5);
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_00420a1a;
                                }
                              }
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 2;
                            }
LAB_00420a1a:
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while (puVar17 < local_64);
                        }
                        *(byte *)(*local_6c + 0x13) = bVar19;
                      }
                      else {
                        pcVar13 = "ObfuscateKey";
                        pbVar5 = param_2;
                        do {
                          bVar19 = *pbVar5;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00420a60:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00420a65;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = pbVar5[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00420a60;
                          pbVar5 = pbVar5 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00420a65:
                        if (uVar6 == 0) {
                          puVar17 = param_3;
                          do {
                            uVar6 = *puVar17;
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while ((char)uVar6 != '\0');
                          iVar9 = *(int *)this;
                          *(bool *)(iVar9 + 0x1a8) = param_3 != (uint *)0x0;
                          if (param_3 != (uint *)0x0) {
                            FUN_00418620(&local_f8,0x20,(uint *)&DAT_0044828c,0x20);
                            FUN_00419bc0(&local_f8,param_3,(int)puVar17 - ((int)param_3 + 1));
                            local_d8 = local_d8 + local_88;
                            local_d0 = 0xffffffff;
                            local_d4 = local_d4 + (uint)(local_d8 < local_88);
                            if (local_80 != '\0') {
                              local_cc = 0xffffffff;
                            }
                            _memset((void *)((int)local_c8 + local_88),0,0x40 - local_88);
                            FUN_004186e0(&local_f8,local_c8);
                            *(uint *)(iVar9 + 0x1b0) = local_f8;
                            *(undefined4 *)(iVar9 + 0x1b4) = uStack_f4;
                            *(undefined4 *)(iVar9 + 0x1b8) = uStack_f0;
                            *(undefined4 *)(iVar9 + 0x1bc) = uStack_ec;
                            *(undefined4 *)(iVar9 + 0x1c0) = local_e8;
                            *(undefined4 *)(iVar9 + 0x1c4) = uStack_e4;
                            *(undefined4 *)(iVar9 + 0x1c8) = uStack_e0;
                            *(undefined4 *)(iVar9 + 0x1cc) = uStack_dc;
                          }
                        }
                        else {
                          pcVar13 = "ObfuscateTCP";
                          pbVar5 = param_2;
                          do {
                            bVar19 = *pbVar5;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_00420b70:
                              uVar6 = -(uint)bVar22 | 1;
                              goto LAB_00420b75;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar5[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_00420b70;
                            pbVar5 = pbVar5 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar6 = 0;
LAB_00420b75:
                          if (uVar6 == 0) {
                            uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                            if ((char)uVar7 == '\0') {
                              pcVar13 = "tls-firefox";
                              puVar17 = param_3;
                              do {
                                bVar19 = (byte)*puVar17;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420bc8:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420bcd;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = *(byte *)((int)puVar17 + 1);
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420bc8;
                                puVar17 = (uint *)((int)puVar17 + 2);
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420bcd:
                              if (uVar6 == 0) {
                                *(undefined4 *)(*(int *)this + 0x1ac) = 2;
                              }
                              else {
                                pcVar13 = "tls-chrome";
                                puVar17 = param_3;
                                do {
                                  bVar19 = (byte)*puVar17;
                                  bVar22 = bVar19 < (byte)*pcVar13;
                                  if (bVar19 != *pcVar13) {
LAB_00420c10:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420c15;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = *(byte *)((int)puVar17 + 1);
                                  bVar22 = bVar19 < (byte)pcVar13[1];
                                  if (bVar19 != pcVar13[1]) goto LAB_00420c10;
                                  puVar17 = (uint *)((int)puVar17 + 2);
                                  pcVar13 = pcVar13 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420c15:
                                if (uVar6 == 0) {
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 3;
                                }
                                else {
                                  if ((char)*param_3 != '\0') {
                                    FUN_0040e010("Unknown mode in ObfuscateTCP: %s",(char)param_3);
                                  }
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 1;
                                }
                              }
                            }
                            else {
                              *(uint *)(*(int *)this + 0x1ac) = (uint)local_5d;
                            }
                          }
                          else {
                            pcVar13 = "PostUp";
                            pbVar5 = param_2;
                            do {
                              bVar19 = *pbVar5;
                              bVar22 = bVar19 < (byte)*pcVar13;
                              if (bVar19 != *pcVar13) {
LAB_00420c76:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420c7b;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar5[1];
                              bVar22 = bVar19 < (byte)pcVar13[1];
                              if (bVar19 != pcVar13[1]) goto LAB_00420c76;
                              pbVar5 = pbVar5 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar19 != 0);
                            uVar6 = 0;
LAB_00420c7b:
                            if (uVar6 == 0) {
                              iVar9 = *(int *)this;
                              piVar10 = *(int **)(iVar9 + 0x2358);
                              if (piVar10 == *(int **)(iVar9 + 0x235c)) {
                                FUN_00422a20((void *)(iVar9 + 0x2354),piVar10,&local_64);
                              }
                              else {
                                piVar10[4] = 0;
                                piVar10[5] = 0xf;
                                *(undefined1 *)piVar10 = 0;
                                puVar17 = param_3;
                                do {
                                  uVar6 = *puVar17;
                                  puVar17 = (uint *)((int)puVar17 + 1);
                                } while ((char)uVar6 != '\0');
                                FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                *(int *)(iVar9 + 0x2358) = *(int *)(iVar9 + 0x2358) + 0x18;
                              }
                            }
                            else {
                              pcVar13 = "PostDown";
                              pbVar5 = param_2;
                              do {
                                bVar19 = *pbVar5;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420d00:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420d05;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar5[1];
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420d00;
                                pbVar5 = pbVar5 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420d05:
                              if (uVar6 == 0) {
                                iVar9 = *(int *)this;
                                piVar10 = *(int **)(iVar9 + 0x2370);
                                if (piVar10 == *(int **)(iVar9 + 0x2374)) {
                                  FUN_00422a20((void *)(iVar9 + 0x236c),piVar10,&local_64);
                                }
                                else {
                                  piVar10[4] = 0;
                                  piVar10[5] = 0xf;
                                  *(undefined1 *)piVar10 = 0;
                                  puVar17 = param_3;
                                  do {
                                    uVar6 = *puVar17;
                                    puVar17 = (uint *)((int)puVar17 + 1);
                                  } while ((char)uVar6 != '\0');
                                  FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                  *(int *)(iVar9 + 0x2370) = *(int *)(iVar9 + 0x2370) + 0x18;
                                }
                              }
                              else {
                                pbVar14 = &DAT_0044a3c8;
                                pbVar5 = param_2;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00420d90:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420d95;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00420d90;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420d95:
                                if (uVar6 == 0) {
                                  iVar9 = *(int *)this;
                                  piVar10 = *(int **)(iVar9 + 0x234c);
                                  if (piVar10 == *(int **)(iVar9 + 0x2350)) {
                                    FUN_00422a20((void *)(iVar9 + 0x2348),piVar10,&local_64);
                                  }
                                  else {
                                    piVar10[4] = 0;
                                    piVar10[5] = 0xf;
                                    *(undefined1 *)piVar10 = 0;
                                    puVar17 = param_3;
                                    do {
                                      uVar6 = *puVar17;
                                      puVar17 = (uint *)((int)puVar17 + 1);
                                    } while ((char)uVar6 != '\0');
                                    FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                    *(int *)(iVar9 + 0x234c) = *(int *)(iVar9 + 0x234c) + 0x18;
                                  }
                                }
                                else {
                                  pcVar13 = "PreDown";
                                  pbVar5 = param_2;
                                  do {
                                    bVar19 = *pbVar5;
                                    bVar22 = bVar19 < (byte)*pcVar13;
                                    if (bVar19 != *pcVar13) {
LAB_00420e20:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420e25;
                                    }
                                    if (bVar19 == 0) break;
                                    bVar19 = pbVar5[1];
                                    bVar22 = bVar19 < (byte)pcVar13[1];
                                    if (bVar19 != pcVar13[1]) goto LAB_00420e20;
                                    pbVar5 = pbVar5 + 2;
                                    pcVar13 = pcVar13 + 2;
                                  } while (bVar19 != 0);
                                  uVar6 = 0;
LAB_00420e25:
                                  if (uVar6 == 0) {
                                    iVar9 = *(int *)this;
                                    piVar10 = *(int **)(iVar9 + 0x2364);
                                    if (piVar10 == *(int **)(iVar9 + 0x2368)) {
                                      FUN_00422a20((void *)(iVar9 + 0x2360),piVar10,&local_64);
                                    }
                                    else {
                                      piVar10[4] = 0;
                                      piVar10[5] = 0xf;
                                      *(undefined1 *)piVar10 = 0;
                                      puVar17 = param_3;
                                      do {
                                        uVar6 = *puVar17;
                                        puVar17 = (uint *)((int)puVar17 + 1);
                                      } while ((char)uVar6 != '\0');
                                      FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                      *(int *)(iVar9 + 0x2364) = *(int *)(iVar9 + 0x2364) + 0x18;
                                    }
                                  }
                                  else {
                                    pcVar13 = "ExcludedIPs";
                                    do {
                                      bVar19 = *param_2;
                                      bVar22 = bVar19 < (byte)*pcVar13;
                                      if (bVar19 != *pcVar13) {
LAB_00420eb0:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_00420eb5;
                                      }
                                      if (bVar19 == 0) break;
                                      bVar19 = param_2[1];
                                      bVar22 = bVar19 < (byte)pcVar13[1];
                                      if (bVar19 != pcVar13[1]) goto LAB_00420eb0;
                                      param_2 = param_2 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar19 != 0);
                                    uVar6 = 0;
LAB_00420eb5:
                                    if (uVar6 == 0) {
                                      FUN_0040e1b0(param_3,&local_78);
                                      uVar6 = 0;
                                      local_68 = local_78;
                                      uVar8 = local_74 - (int)local_78 >> 2;
                                      if (uVar8 != 0) {
                                        do {
                                          cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                                          if (cVar4 == '\0') break;
                                          iVar9 = *(int *)this;
                                          puVar17 = *(uint **)(iVar9 + 0x2394);
                                          if (puVar17 == *(uint **)(iVar9 + 0x2398)) {
                                            FUN_00414bc0((void *)(iVar9 + 0x2390),puVar17,&local_5c);
                                          }
                                          else {
                                            *puVar17 = local_5c;
                                            puVar17[1] = uStack_58;
                                            puVar17[2] = uStack_54;
                                            puVar17[3] = uStack_50;
                                            *(undefined2 *)(puVar17 + 4) = local_4c;
                                            *(int *)(iVar9 + 0x2394) = *(int *)(iVar9 + 0x2394) + 0x12;
                                          }
                                          uVar6 = uVar6 + 1;
                                        } while (uVar6 < uVar8);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00420763;
          }
          uVar6 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xe) == uVar6) goto LAB_00420763;
          uVar8 = uVar6 & 0xffff;
          *(short *)(iVar9 + 0xe) = (short)uVar6;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar6 = (uint)*(ushort *)(iVar9 + 0xc);
        }
        cVar4 = (**(code **)**(undefined4 **)(iVar9 + 8))(uVar6,uVar8);
        if (cVar4 == '\0') {
          FUN_0040e0a0("ConfigureUdp failed",unaff_DI);
        }
      }
    }
  }
  else {
    pbVar5 = &DAT_0044a3e4;
    do {
      bVar19 = *param_1;
      bVar22 = bVar19 < *pbVar5;
      if (bVar19 != *pbVar5) {
LAB_00420f60:
        uVar6 = -(uint)bVar22 | 1;
        goto LAB_00420f65;
      }
      if (bVar19 == 0) break;
      bVar19 = param_1[1];
      bVar22 = bVar19 < pbVar5[1];
      if (bVar19 != pbVar5[1]) goto LAB_00420f60;
      param_1 = param_1 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar19 != 0);
    uVar6 = 0;
LAB_00420f65:
    if (uVar6 == 0) {
      if (param_2 == (byte *)0x0) {
        if (*(char *)((int)this + 0x50) == '\0') {
          FUN_0040e010("Missing [Interface].PrivateKey.",unaff_DI);
        }
        else {
          if (*(void **)((int)this + 0x48) != (void *)0x0) {
            FUN_00429d00(*(void **)((int)this + 0x48),(uint *)((int)this + 8));
            *(undefined4 *)((int)this + 0x48) = 0;
          }
          piVar10 = FUN_004296d0(*(int *)this + 0x20);
          *(int **)((int)this + 0x48) = piVar10;
          _memset((uint *)((int)this + 8),0,0x40);
        }
      }
      else if ((*(int **)(*(int *)this + 0x38) == (int *)0x0) ||
              (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 0xc))
                                 (*(undefined4 *)((int)this + 0x48),param_2,param_3), cVar4 == '\0')) {
        piVar10 = local_6c;
        pcVar13 = "PublicKey";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_00421010:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_00421015;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_00421010;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_00421015:
        if (uVar6 == 0) {
          local_64 = (uint *)0x20;
          puVar17 = param_3;
          do {
            uVar6 = *puVar17;
            puVar17 = (uint *)((int)puVar17 + 1);
          } while ((char)uVar6 != '\0');
          FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)(local_6c + 2),(uint *)&local_64)
          ;
        }
        else {
          pcVar13 = "PresharedKey";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00421081:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00421086;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00421081;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00421086:
          if (uVar6 == 0) {
            local_64 = (uint *)0x20;
            puVar17 = param_3;
            do {
              uVar6 = *puVar17;
              puVar17 = (uint *)((int)puVar17 + 1);
            } while ((char)uVar6 != '\0');
            piVar16 = local_6c + 10;
            uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)piVar16,
                                 (uint *)&local_64);
            if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
              iVar9 = piVar10[0x12];
              if (piVar16 == (int *)0x0) {
                *(undefined4 *)(iVar9 + 0x160) = 0;
                *(undefined4 *)(iVar9 + 0x164) = 0;
                *(undefined4 *)(iVar9 + 0x168) = 0;
                *(undefined4 *)(iVar9 + 0x16c) = 0;
                *(undefined4 *)(iVar9 + 0x170) = 0;
                *(undefined4 *)(iVar9 + 0x174) = 0;
                *(undefined4 *)(iVar9 + 0x178) = 0;
                *(undefined4 *)(iVar9 + 0x17c) = 0;
              }
              else {
                iVar21 = piVar10[0xb];
                iVar2 = piVar10[0xc];
                iVar3 = piVar10[0xd];
                *(int *)(iVar9 + 0x160) = *piVar16;
                *(int *)(iVar9 + 0x164) = iVar21;
                *(int *)(iVar9 + 0x168) = iVar2;
                *(int *)(iVar9 + 0x16c) = iVar3;
                iVar21 = piVar10[0xf];
                iVar2 = piVar10[0x10];
                iVar3 = piVar10[0x11];
                *(int *)(iVar9 + 0x170) = piVar10[0xe];
                *(int *)(iVar9 + 0x174) = iVar21;
                *(int *)(iVar9 + 0x178) = iVar2;
                *(int *)(iVar9 + 0x17c) = iVar3;
              }
            }
          }
          else {
            pcVar13 = "AllowedIPs";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_00421128:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_0042112d;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_00421128;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_0042112d:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if ((cVar4 == '\0') || (uVar7 = FUN_0042bd40((void *)local_6c[0x12],&local_5c), (char)uVar7 == '\0'))
                  break;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pcVar13 = "Endpoint";
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < (byte)*pcVar13;
                if (bVar19 != *pcVar13) {
LAB_004211b3:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_004211b8;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < (byte)pcVar13[1];
                if (bVar19 != pcVar13[1]) goto LAB_004211b3;
                pbVar5 = pbVar5 + 2;
                pcVar13 = pcVar13 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_004211b8:
              if (uVar6 == 0) {
                uVar20 = 1;
                iVar9 = _strncmp((char *)param_3,"tcp://",6);
                piVar10 = local_6c;
                if (iVar9 == 0) {
                  param_3 = (uint *)((int)param_3 + 6);
                  uVar20 = 2;
                }
                cVar4 = FUN_0040c530((char *)param_3,&local_48,(void *)local_6c[0x13]);
                if (cVar4 != '\0') {
                  iVar9 = piVar10[0x12];
                  *(undefined1 *)(iVar9 + 0x3b) = uVar20;
                  *(undefined1 *)(iVar9 + 0x3c) = uVar20;
                  *(uint *)(iVar9 + 0x68) = local_48;
                  *(uint *)(iVar9 + 0x6c) = uStack_44;
                  *(uint *)(iVar9 + 0x70) = uStack_40;
                  *(uint *)(iVar9 + 0x74) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x78) = local_38;
                  *(uint *)(iVar9 + 0x80) = local_30;
                  *(uint *)(iVar9 + 0x84) = local_48;
                  *(uint *)(iVar9 + 0x88) = uStack_44;
                  *(uint *)(iVar9 + 0x8c) = uStack_40;
                  *(uint *)(iVar9 + 0x90) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x94) = local_38;
                  *(uint *)(iVar9 + 0x9c) = local_30;
                }
              }
              else {
                pcVar13 = "PersistentKeepalive";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_00421270:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_00421275;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_00421270;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_00421275:
                if (uVar6 == 0) {
                  uVar6 = FID_conflict__atoi((char *)param_3);
                  if (uVar6 < 0x10000) {
                    *(uint *)(local_6c[0x12] + 0x218) = uVar6 * 1000;
                  }
                }
                else {
                  pcVar13 = "AllowMulticast";
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < (byte)*pcVar13;
                    if (bVar19 != *pcVar13) {
LAB_004212d0:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004212d5;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < (byte)pcVar13[1];
                    if (bVar19 != pcVar13[1]) goto LAB_004212d0;
                    pbVar5 = pbVar5 + 2;
                    pcVar13 = pcVar13 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004212d5:
                  if (uVar6 == 0) {
                    uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                    if ((char)uVar7 != '\0') {
                      *(byte *)(local_6c[0x12] + 0x37) = local_5d;
                    }
                  }
                  else {
                    pcVar13 = "Features";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_00421325:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_0042132a;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_00421325;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_0042132a:
                    if (uVar6 == 0) {
                      FUN_0040e1b0(param_3,&local_78);
                      uVar8 = 0;
                      local_68 = local_78;
                      uVar6 = local_74 - (int)local_78 >> 2;
                      if (uVar6 != 0) {
                        do {
                          piVar10 = *(int **)((int)local_78 + uVar8 * 4);
                          piVar16 = piVar10;
                          do {
                            iVar9 = *piVar16;
                            piVar16 = (int *)((int)piVar16 + 1);
                          } while ((char)iVar9 != '\0');
                          iVar9 = (int)piVar16 - (int)((int)piVar10 + 1);
                          iVar21 = 2;
                          if (iVar9 != 0) {
                            cVar4 = *(char *)((int)piVar10 + iVar9 + -1);
                            if (cVar4 == '?') {
                              iVar21 = 1;
                            }
                            else {
                              if (cVar4 != '!') goto LAB_00421389;
                              iVar21 = 3;
                            }
                            iVar9 = iVar9 + -1;
                          }
LAB_00421389:
                          if ((((iVar9 != 10) || (*piVar10 != 0x72627968)) || (piVar10[1] != 0x745f6469)) ||
                             ((short)piVar10[2] != 0x7063)) break;
                          uVar8 = uVar8 + 1;
                          *(byte *)((iVar21 + 0x60U >> 4) + 0x3d + local_6c[0x12]) = (byte)(iVar21 + 0x60U) & 3;
                        } while (uVar8 < uVar6);
                      }
                    }
                    else {
                      pcVar13 = "Ciphers";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00421404:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00421409;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00421404;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00421409:
                      if (uVar6 != 0) {
                        uVar20 = 1;
                        pcVar13 = "Ciphers!";
                        do {
                          bVar19 = *param_2;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00421434:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00421439;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = param_2[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00421434;
                          param_2 = param_2 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00421439:
                        if (uVar6 != 0) goto LAB_00420763;
                      }
                      FUN_0040e1b0(param_3,&local_78);
                      uVar6 = 0;
                      uVar8 = local_74 - (int)local_78 >> 2;
                      local_68 = local_78;
                      *(undefined1 *)(local_6c[0x12] + 0xa4) = uVar20;
                      if (uVar8 != 0) {
                        do {
                          pbVar5 = *(byte **)((int)local_78 + uVar6 * 4);
                          pcVar13 = "chacha20-poly1305";
                          pbVar14 = pbVar5;
                          do {
                            bVar19 = *pbVar14;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_004214a0:
                              uVar11 = -(uint)bVar22 | 1;
                              goto LAB_004214a5;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar14[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_004214a0;
                            pbVar14 = pbVar14 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar11 = 0;
LAB_004214a5:
                          if (uVar11 == 0) {
                            cVar4 = '\0';
                          }
                          else {
                            pbVar15 = &DAT_0044a274;
                            pbVar14 = pbVar5;
                            do {
                              bVar19 = *pbVar14;
                              bVar22 = bVar19 < *pbVar15;
                              if (bVar19 != *pbVar15) {
LAB_004214d7:
                                uVar11 = -(uint)bVar22 | 1;
                                goto LAB_004214dc;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar14[1];
                              bVar22 = bVar19 < pbVar15[1];
                              if (bVar19 != pbVar15[1]) goto LAB_004214d7;
                              pbVar14 = pbVar14 + 2;
                              pbVar15 = pbVar15 + 2;
                            } while (bVar19 != 0);
                            uVar11 = 0;
LAB_004214dc:
                            if (uVar11 == 0) {
                              cVar4 = '\x01';
                            }
                            else {
                              pbVar15 = &DAT_0044a280;
                              pbVar14 = pbVar5;
                              do {
                                bVar19 = *pbVar14;
                                bVar22 = bVar19 < *pbVar15;
                                if (bVar19 != *pbVar15) {
LAB_00421510:
                                  uVar11 = -(uint)bVar22 | 1;
                                  goto LAB_00421515;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar14[1];
                                bVar22 = bVar19 < pbVar15[1];
                                if (bVar19 != pbVar15[1]) goto LAB_00421510;
                                pbVar14 = pbVar14 + 2;
                                pbVar15 = pbVar15 + 2;
                              } while (bVar19 != 0);
                              uVar11 = 0;
LAB_00421515:
                              if (uVar11 == 0) {
                                cVar4 = '\x02';
                              }
                              else {
                                pbVar14 = &DAT_0044a28c;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00421543:
                                    uVar11 = -(uint)bVar22 | 1;
                                    goto LAB_00421548;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00421543;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar11 = 0;
LAB_00421548:
                                if (uVar11 != 0) break;
                                cVar4 = '\x03';
                              }
                            }
                          }
                          iVar9 = local_6c[0x12];
                          if (*(byte *)(iVar9 + 0xa5) == 4) break;
                          if ((cVar4 != '\x01') && (cVar4 != '\x02')) {
                            *(char *)(*(byte *)(iVar9 + 0xa5) + 0xa6 + iVar9) = cVar4;
                            *(char *)(iVar9 + 0xa5) = *(char *)(iVar9 + 0xa5) + '\x01';
                          }
                          uVar6 = uVar6 + 1;
                        } while (uVar6 < uVar8);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00420763:
  if (local_68 != (void *)0x0) {
    pvVar18 = local_68;
    if ((0xfff < (local_70 - (int)local_68 & 0xfffffffcU)) &&
       (pvVar18 = *(void **)((int)local_68 + -4), 0x1f < (uint)((int)local_68 + (-4 - (int)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pvVar18);
  }
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- caller: FUN_00422150 @ 00422150

void __fastcall FUN_00422150(void *param_1,uint *param_2,undefined4 *param_3)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  uint *puVar4;
  uint *puVar5;
  uint ****_Str;
  int iVar6;
  uint ****ppppuVar7;
  uint uVar8;
  byte *pbVar9;
  char *pcVar10;
  uint *****pppppuVar11;
  void *pvVar12;
  undefined4 *puVar13;
  uint *****pppppuVar14;
  uint ****ppppuVar15;
  undefined4 unaff_EDI;
  bool bVar16;
  undefined8 uVar17;
  int local_c4;
  uint ****local_c0;
  uint *****local_bc;
  undefined4 *local_b8;
  uint *****local_b4;
  uint *****local_b0;
  uint *****local_ac;
  int *local_a8;
  uint *****local_a4;
  char local_9e;
  char local_9d;
  void *local_9c;
  int local_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int local_88;
  int iStack_84;
  int local_80;
  uint *****local_7c [5];
  uint local_68;
  uint local_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined2 local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  local_b8 = param_3;
  local_9c = param_1;
  FUN_00409810(local_7c,param_2);
  local_b4 = (uint *****)0x0;
  pppppuVar11 = (uint *****)0x0;
  param_3[4] = 0;
  local_bc = (uint *****)0x0;
  local_ac = (uint *****)0x0;
  local_9e = '\0';
  local_9d = '\0';
  local_a8 = (int *)0x0;
  local_b0 = (uint *****)0x0;
  if (0xf < (uint)param_3[5]) {
    param_3 = (undefined4 *)*param_3;
  }
  *(undefined1 *)param_3 = 0;
  pppppuVar14 = (uint *****)local_7c;
  if (0xf < local_68) {
    pppppuVar14 = local_7c[0];
  }
  while( true ) {
    local_a4 = pppppuVar14;
    puVar4 = FUN_0042dd80((uint *)pppppuVar14,'\n');
    if (puVar4 != (uint *)0x0) {
      *(undefined1 *)puVar4 = 0;
    }
    if (*(char *)pppppuVar14 != '\0') {
      puVar5 = FUN_0042dd80((uint *)pppppuVar14,'=');
      if (puVar5 == (uint *)0x0) goto LAB_00422970;
      *(undefined1 *)puVar5 = 0;
      local_c0 = (uint ****)((int)puVar5 + 1);
      if (pppppuVar11 == local_bc) {
        FUN_0040e270(&local_b4,pppppuVar11,&local_a4,&local_c0);
        local_bc = local_ac;
        pppppuVar11 = local_b0;
      }
      else {
        *pppppuVar11 = (uint ****)pppppuVar14;
        pppppuVar11[1] = local_c0;
        local_b0 = pppppuVar11 + 2;
        pppppuVar11 = local_b0;
      }
    }
    if (puVar4 == (uint *)0x0) break;
    pppppuVar14 = (uint *****)((int)puVar4 + 1);
  }
  local_a4 = local_b4;
  if (local_b4 != pppppuVar11) {
LAB_00422270:
    pvVar12 = local_9c;
    piVar2 = local_a8;
    ppppuVar15 = *local_a4;
    pbVar9 = &DAT_0044a604;
    _Str = local_a4[1];
    ppppuVar7 = ppppuVar15;
    do {
      bVar1 = *(byte *)ppppuVar7;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_004222a0:
        uVar8 = -(uint)bVar16 | 1;
        goto LAB_004222a5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppppuVar7 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_004222a0;
      ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar8 = 0;
LAB_004222a5:
    if (uVar8 == 0) {
      pbVar9 = &DAT_0044a244;
      goto LAB_004228d0;
    }
    pbVar9 = &DAT_0044a608;
    ppppuVar7 = ppppuVar15;
    do {
      bVar1 = *(byte *)ppppuVar7;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_004222d4:
        uVar8 = -(uint)bVar16 | 1;
        goto LAB_004222d9;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppppuVar7 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_004222d4;
      ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar8 = 0;
LAB_004222d9:
    if (uVar8 == 0) {
      pbVar9 = &DAT_0044a244;
      do {
        bVar1 = *(byte *)_Str;
        bVar16 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00422302:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422307;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)_Str + 1);
        bVar16 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00422302;
        _Str = (uint ****)((int)_Str + 2);
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422307:
      if (uVar8 != 0) goto LAB_0042295e;
      local_9e = '\x01';
    }
    else {
      if (local_9e == '\0') goto LAB_0042295e;
      pcVar10 = "private_key";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422350:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422355;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422350;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422355:
      if (uVar8 == 0) {
        uVar8 = FUN_0040e130((char *)_Str,(int)&local_2c);
        pvVar12 = local_9c;
        if ((char)uVar8 == '\0') goto LAB_0042295e;
        FUN_00429640((void *)((int)local_9c + 0x20),&local_2c);
        goto LAB_004228ac;
      }
      pcVar10 = "listen_port";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_004223b0:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_004223b5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_004223b0;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_004223b5:
      if (uVar8 == 0) {
        uVar8 = FID_conflict__atoi((char *)_Str);
        pvVar12 = local_9c;
        if (*(ushort *)((int)local_9c + 0xc) != uVar8) {
          *(short *)((int)local_9c + 0xc) = (short)uVar8;
          if ((*(char *)((int)local_9c + 0x17) != '\0') &&
             (cVar3 = (**(code **)**(undefined4 **)((int)local_9c + 8))
                                (uVar8 & 0xffff,*(undefined2 *)((int)local_9c + 0xe)), cVar3 == '\0')) {
            FUN_0040e0a0("ConfigureUdp failed",(char)unaff_EDI);
          }
        }
        goto LAB_004228ac;
      }
      pcVar10 = "replace_peers";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422437:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_0042243c;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422437;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_0042243c:
      if (uVar8 == 0) {
        pbVar9 = &DAT_0044a238;
        do {
          bVar1 = *(byte *)_Str;
          bVar16 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_00422465:
            uVar8 = -(uint)bVar16 | 1;
            goto LAB_0042246a;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)_Str + 1);
          bVar16 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_00422465;
          _Str = (uint ****)((int)_Str + 2);
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        uVar8 = 0;
LAB_0042246a:
        if (uVar8 != 0) goto LAB_0042295e;
        piVar2 = *(int **)((int)local_9c + 0x30);
        while (piVar2 != (int *)0x0) {
          FUN_00429ab0(piVar2);
          piVar2 = *(int **)((int)pvVar12 + 0x30);
        }
        goto LAB_004228ac;
      }
      pcVar10 = "address";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_004224c0:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_004224c5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_004224c0;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_004224c5:
      if (uVar8 == 0) {
        cVar3 = FUN_0040bde0((uint *)_Str,(int)&local_64);
        pvVar12 = local_9c;
        if (cVar3 == '\0') goto LAB_0042295e;
        if (local_9d == '\0') {
          local_9d = '\x01';
          *(undefined4 *)((int)local_9c + 0x2334) = *(undefined4 *)((int)local_9c + 0x2330);
        }
        puVar4 = *(uint **)((int)local_9c + 0x2334);
        if (puVar4 == *(uint **)((int)local_9c + 0x2338)) {
          FUN_00414bc0((void *)((int)local_9c + 0x2330),puVar4,&local_64);
        }
        else {
          *puVar4 = local_64;
          puVar4[1] = uStack_60;
          puVar4[2] = uStack_5c;
          puVar4[3] = uStack_58;
          *(undefined2 *)(puVar4 + 4) = local_54;
          *(int *)((int)local_9c + 0x2334) = *(int *)((int)local_9c + 0x2334) + 0x12;
        }
        goto LAB_004228ac;
      }
      pcVar10 = "public_key";
      ppppuVar7 = ppppuVar15;
      do {
        bVar1 = *(byte *)ppppuVar7;
        bVar16 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00422560:
          uVar8 = -(uint)bVar16 | 1;
          goto LAB_00422565;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppppuVar7 + 1);
        bVar16 = bVar1 < (byte)pcVar10[1];
        if (bVar1 != pcVar10[1]) goto LAB_00422560;
        ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
        pcVar10 = pcVar10 + 2;
      } while (bVar1 != 0);
      uVar8 = 0;
LAB_00422565:
      if (uVar8 == 0) {
        uVar8 = FUN_0040e130((char *)_Str,(int)&local_50);
        pvVar12 = local_9c;
        if ((char)uVar8 == '\0') goto LAB_0042295e;
        uVar17 = FUN_0040a7f0(local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34);
        iVar6 = FUN_0042c760((void *)((int)pvVar12 + 0x7c),&local_c4,(int *)&local_50,(uint)uVar17);
        iVar6 = *(int *)(iVar6 + 4);
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)pvVar12 + 0x80);
        }
        if ((iVar6 == *(int *)((int)pvVar12 + 0x80)) || (local_a8 = *(int **)(iVar6 + 0x28), local_a8 == (int *)0x0)) {
          local_a8 = FUN_004296d0((int)pvVar12 + 0x20);
          FUN_00429d00(local_a8,&local_50);
        }
        goto LAB_004228ac;
      }
      if (local_a8 != (int *)0x0) {
        pcVar10 = "remove";
        ppppuVar7 = ppppuVar15;
        do {
          bVar1 = *(byte *)ppppuVar7;
          bVar16 = bVar1 < (byte)*pcVar10;
          if (bVar1 != *pcVar10) {
LAB_00422640:
            uVar8 = -(uint)bVar16 | 1;
            goto LAB_00422645;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppppuVar7 + 1);
          bVar16 = bVar1 < (byte)pcVar10[1];
          if (bVar1 != pcVar10[1]) goto LAB_00422640;
          ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
          pcVar10 = pcVar10 + 2;
        } while (bVar1 != 0);
        uVar8 = 0;
LAB_00422645:
        if (uVar8 == 0) {
          pbVar9 = &DAT_0044a238;
          do {
            bVar1 = *(byte *)_Str;
            bVar16 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_00422670:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_00422675;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)_Str + 1);
            bVar16 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_00422670;
            _Str = (uint ****)((int)_Str + 2);
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_00422675:
          if (uVar8 != 0) goto LAB_0042295e;
          FUN_00429ab0(local_a8);
          local_a8 = (int *)0x0;
        }
        else {
          pcVar10 = "preshared_key";
          ppppuVar7 = ppppuVar15;
          do {
            bVar1 = *(byte *)ppppuVar7;
            bVar16 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_004226b8:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_004226bd;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppppuVar7 + 1);
            bVar16 = bVar1 < (byte)pcVar10[1];
            if (bVar1 != pcVar10[1]) goto LAB_004226b8;
            ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
            pcVar10 = pcVar10 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_004226bd:
          if (uVar8 == 0) {
            uVar8 = FUN_0040e130((char *)_Str,(int)&local_2c);
            if ((char)uVar8 != '\0') {
              piVar2[0x58] = local_2c;
              piVar2[0x59] = iStack_28;
              piVar2[0x5a] = iStack_24;
              piVar2[0x5b] = iStack_20;
              piVar2[0x5c] = local_1c;
              piVar2[0x5d] = iStack_18;
              piVar2[0x5e] = iStack_14;
              piVar2[0x5f] = iStack_10;
              goto LAB_004228a6;
            }
            goto LAB_0042295e;
          }
          pcVar10 = "endpoint";
          ppppuVar7 = ppppuVar15;
          do {
            bVar1 = *(byte *)ppppuVar7;
            bVar16 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00422720:
              uVar8 = -(uint)bVar16 | 1;
              goto LAB_00422725;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppppuVar7 + 1);
            bVar16 = bVar1 < (byte)pcVar10[1];
            if (bVar1 != pcVar10[1]) goto LAB_00422720;
            ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
            pcVar10 = pcVar10 + 2;
          } while (bVar1 != 0);
          uVar8 = 0;
LAB_00422725:
          if (uVar8 == 0) {
            cVar3 = FUN_0040c530((char *)_Str,&local_98,(void *)0x0);
            if (cVar3 == '\0') goto LAB_0042295e;
            *(undefined2 *)((int)piVar2 + 0x3b) = 0x101;
            piVar2[0x1a] = local_98;
            piVar2[0x1b] = iStack_94;
            piVar2[0x1c] = iStack_90;
            piVar2[0x1d] = iStack_8c;
            *(ulonglong *)(piVar2 + 0x1e) = CONCAT44(iStack_84,local_88);
            piVar2[0x20] = local_80;
            piVar2[0x21] = local_98;
            piVar2[0x22] = iStack_94;
            piVar2[0x23] = iStack_90;
            piVar2[0x24] = iStack_8c;
            piVar2[0x25] = local_88;
            piVar2[0x26] = iStack_84;
            piVar2[0x27] = local_80;
          }
          else {
            pcVar10 = "persistent_keepalive_interval";
            ppppuVar7 = ppppuVar15;
            do {
              bVar1 = *(byte *)ppppuVar7;
              bVar16 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_004227c0:
                uVar8 = -(uint)bVar16 | 1;
                goto LAB_004227c5;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppppuVar7 + 1);
              bVar16 = bVar1 < (byte)pcVar10[1];
              if (bVar1 != pcVar10[1]) goto LAB_004227c0;
              ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
              pcVar10 = pcVar10 + 2;
            } while (bVar1 != 0);
            uVar8 = 0;
LAB_004227c5:
            if (uVar8 == 0) {
              uVar8 = FID_conflict__atoi((char *)_Str);
              if (0xffff < uVar8) goto LAB_0042295e;
              piVar2[0x86] = uVar8 * 1000;
            }
            else {
              pcVar10 = "replace_allowed_ips";
              ppppuVar7 = ppppuVar15;
              do {
                bVar1 = *(byte *)ppppuVar7;
                bVar16 = bVar1 < (byte)*pcVar10;
                if (bVar1 != *pcVar10) {
LAB_00422815:
                  uVar8 = -(uint)bVar16 | 1;
                  goto LAB_0042281a;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppuVar7 + 1);
                bVar16 = bVar1 < (byte)pcVar10[1];
                if (bVar1 != pcVar10[1]) goto LAB_00422815;
                ppppuVar7 = (uint ****)((int)ppppuVar7 + 2);
                pcVar10 = pcVar10 + 2;
              } while (bVar1 != 0);
              uVar8 = 0;
LAB_0042281a:
              if (uVar8 == 0) {
                pbVar9 = &DAT_0044a238;
                do {
                  bVar1 = *(byte *)_Str;
                  bVar16 = bVar1 < *pbVar9;
                  if (bVar1 != *pbVar9) {
LAB_00422843:
                    uVar8 = -(uint)bVar16 | 1;
                    goto LAB_00422848;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)_Str + 1);
                  bVar16 = bVar1 < pbVar9[1];
                  if (bVar1 != pbVar9[1]) goto LAB_00422843;
                  _Str = (uint ****)((int)_Str + 2);
                  pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                uVar8 = 0;
LAB_00422848:
                if (uVar8 != 0) goto LAB_0042295e;
                FUN_0042bf30(local_a8);
              }
              else {
                pcVar10 = "allowed_ip";
                do {
                  bVar1 = *(byte *)ppppuVar15;
                  bVar16 = bVar1 < (byte)*pcVar10;
                  if (bVar1 != *pcVar10) {
LAB_00422880:
                    uVar8 = -(uint)bVar16 | 1;
                    goto LAB_00422885;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)ppppuVar15 + 1);
                  bVar16 = bVar1 < (byte)pcVar10[1];
                  if (bVar1 != pcVar10[1]) goto LAB_00422880;
                  ppppuVar15 = (uint ****)((int)ppppuVar15 + 2);
                  pcVar10 = pcVar10 + 2;
                } while (bVar1 != 0);
                uVar8 = 0;
LAB_00422885:
                if (uVar8 == 0) {
                  cVar3 = FUN_0040bde0((uint *)_Str,(int)&local_64);
                  if (cVar3 == '\0') goto LAB_0042295e;
                  FUN_0042bd40(piVar2,&local_64);
                }
              }
            }
          }
        }
      }
    }
LAB_004228a6:
    pvVar12 = local_9c;
LAB_004228ac:
    local_a4 = local_a4 + 2;
    if (local_a4 == local_b0) goto LAB_0042290c;
    goto LAB_00422270;
  }
LAB_00422922:
  pppppuVar11 = local_b4;
  iVar6 = local_b8[4];
  if ((uint)(local_b8[5] - iVar6) < 9) {
    local_c0 = (uint ****)((uint)local_c0 & 0xffffff00);
    FUN_0040e540(local_b8,9,local_c0,(uint *)"errno=0\n\n",9);
  }
  else {
    local_b8[4] = iVar6 + 9;
    puVar13 = local_b8;
    if (0xf < (uint)local_b8[5]) {
      puVar13 = (undefined4 *)*local_b8;
    }
    FUN_0042e660((uint *)(iVar6 + (int)puVar13),(uint *)"errno=0\n\n",9);
    *(undefined1 *)(iVar6 + 9 + (int)puVar13) = 0;
  }
  goto LAB_00422999;
  while( true ) {
    bVar1 = *(byte *)((int)_Str + 1);
    bVar16 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_004228f0;
    _Str = (uint ****)((int)_Str + 2);
    pbVar9 = pbVar9 + 2;
    if (bVar1 == 0) break;
LAB_004228d0:
    bVar1 = *(byte *)_Str;
    bVar16 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_004228f0:
      uVar8 = -(uint)bVar16 | 1;
      goto LAB_004228f5;
    }
    if (bVar1 == 0) break;
  }
  uVar8 = 0;
LAB_004228f5:
  if (uVar8 == 0) {
    FUN_00421d10((int)local_9c,local_b8);
LAB_0042290c:
    if (local_9d != '\0') {
      FUN_00416140(pvVar12);
    }
    goto LAB_00422922;
  }
LAB_0042295e:
  FUN_004096e0(local_b8,(uint *)"errno=1\n\n",9);
LAB_00422970:
  pppppuVar11 = local_b4;
LAB_00422999:
  if (pppppuVar11 != (uint *****)0x0) {
    pppppuVar14 = pppppuVar11;
    if ((0xfff < ((int)local_bc - (int)pppppuVar11 & 0xfffffff8U)) &&
       (pppppuVar14 = (uint *****)pppppuVar11[-1], 0x1f < (uint)((int)pppppuVar11 + (-4 - (int)pppppuVar14))))
    goto LAB_00422a0f;
    FUN_0042cf8d(pppppuVar14);
  }
  if (0xf < local_68) {
    pppppuVar11 = local_7c[0];
    if ((0xfff < local_68 + 1) &&
       (pppppuVar11 = (uint *****)local_7c[0][-1], 0x1f < (uint)((int)local_7c[0] + (-4 - (int)pppppuVar11)))) {
LAB_00422a0f:
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pppppuVar11);
  }
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_00429d00 @ 00429d00

void __thiscall FUN_00429d00(void *this,uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int local_10 [3];
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  puVar1 = (uint *)((int)this + 0x140);
  *puVar1 = *param_1;
  *(uint *)((int)this + 0x144) = uVar2;
  *(uint *)((int)this + 0x148) = uVar3;
  *(uint *)((int)this + 0x14c) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(uint *)((int)this + 0x150) = param_1[4];
  *(uint *)((int)this + 0x154) = uVar2;
  *(uint *)((int)this + 0x158) = uVar3;
  *(uint *)((int)this + 0x15c) = uVar4;
  piVar5 = (int *)FUN_0042c5a0((void *)(*(int *)this + 0x5c),local_10,puVar1);
  *(void **)(*piVar5 + 0x28) = this;
  if (*(char *)(*(int *)this + 0x85) != '\0') {
    FUN_004200c0((undefined1 *)((int)this + 0x180),(byte *)(*(int *)this + 0xc0),(byte *)puVar1);
    FUN_00429550((void *)((int)this + 0x1ac),(uint *)&DAT_004482ac,8,puVar1,0x20);
    FUN_00429550((void *)((int)this + 0x1cc),(uint *)&DAT_00448270,8,puVar1,0x20);
    FUN_00429c00((int)this);
    param_1 = *(uint **)((int)this + 0x24);
    if (param_1 != (uint *)0x0) {
      *(undefined4 *)((int)this + 0x24) = 0;
      FUN_0042c360((void *)(*(int *)this + 0x1c),(uint *)&param_1);
    }
  }
  return;
}


// ----- callee: FUN_004200c0 @ 004200c0

void __fastcall FUN_004200c0(undefined1 *param_1,byte *param_2,byte *param_3)

{
  uint local_210 [20];
  uint local_1c0 [20];
  uint local_170 [20];
  uint local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  byte local_2c;
  byte bStack_2b;
  byte bStack_2a;
  byte bStack_29;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte local_1c;
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  bStack_2b = param_2[1];
  bStack_2a = param_2[2];
  bStack_29 = param_2[3];
  bStack_28 = param_2[4];
  bStack_27 = param_2[5];
  bStack_26 = param_2[6];
  bStack_25 = param_2[7];
  bStack_24 = param_2[8];
  bStack_23 = param_2[9];
  bStack_22 = param_2[10];
  bStack_21 = param_2[0xb];
  bStack_20 = param_2[0xc];
  bStack_1f = param_2[0xd];
  bStack_1e = param_2[0xe];
  bStack_1d = param_2[0xf];
  local_1c = param_2[0x10];
  bStack_1b = param_2[0x11];
  bStack_1a = param_2[0x12];
  bStack_19 = param_2[0x13];
  bStack_18 = param_2[0x14];
  bStack_17 = param_2[0x15];
  bStack_16 = param_2[0x16];
  bStack_15 = param_2[0x17];
  bStack_14 = param_2[0x18];
  bStack_13 = param_2[0x19];
  bStack_12 = param_2[0x1a];
  bStack_11 = param_2[0x1b];
  bStack_10 = param_2[0x1c];
  bStack_f = param_2[0x1d];
  bStack_e = param_2[0x1e];
  local_2c = *param_2 & 0xf8;
  bStack_d = param_2[0x1f] & 0x3f | 0x40;
  FUN_0041d7f0(local_170,param_3);
  FUN_0041e920(local_210,&local_88,(int)&local_2c,local_170);
  FUN_0041ec90(local_1c0,(int *)&local_88);
  FUN_0041cd80((longlong *)&local_120,(int *)local_210,(int *)local_1c0);
  FUN_0041d250(&local_120);
  FUN_0041d330(&local_120);
  local_88 = local_120;
  uStack_84 = uStack_11c;
  uStack_80 = uStack_118;
  uStack_7c = uStack_114;
  local_78 = local_110;
  uStack_74 = uStack_10c;
  uStack_70 = uStack_108;
  uStack_6c = uStack_104;
  local_68 = local_100;
  uStack_64 = uStack_fc;
  uStack_60 = uStack_f8;
  uStack_5c = uStack_f4;
  local_58 = local_f0;
  uStack_54 = uStack_ec;
  uStack_50 = uStack_e8;
  uStack_4c = uStack_e4;
  local_48 = local_e0;
  uStack_44 = uStack_dc;
  uStack_40 = uStack_d8;
  uStack_3c = uStack_d4;
  FUN_0041d330(&local_88);
  FUN_0041daf0(param_1,(int *)&local_88);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_00429550 @ 00429550

void __thiscall FUN_00429550(void *this,uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  uint local_8;
  
  local_8 = DAT_0044f008 ^ (uint)(local_54 + 0x14);
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,param_1,param_2);
  FUN_00419bc0(local_84,param_3,param_4);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  __security_check_cookie(local_8 ^ (uint)(local_54 + 0x14));
  return;
}



// ===================== FUN_0042b770 @ 0042b770  anchors: [ObfuscateKey(win@00448278)] =====================

void __fastcall FUN_0042b770(int param_1)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EDX;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffbe;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  GetTickCount64();
  if (*(int *)(param_1 + 0x58) == 0 && *(int *)(param_1 + 0x5c) == 0) {
    iVar1 = *(int *)(param_1 + 8);
    if ((*(byte *)(iVar1 + 0x17) != 0) ||
       ((((((*(char *)(iVar1 + 0xe) != '\0' || *(char *)(iVar1 + 0xc) != '\0') || *(char *)(iVar1 + 0xd) != '\0') ||
          (char)*(undefined2 *)(iVar1 + 0xf) != '\0') || (char)((ushort)*(undefined2 *)(iVar1 + 0xf) >> 8) != '\0') ||
        *(char *)(iVar1 + 0x11) != '\0') || *(char *)(iVar1 + 0xb) != '\0')) {
      FUN_0040e0a0("Using %s%s%s%s%s%s%s",(char)(&PTR_s_chacha20_poly1305_00448278)[*(byte *)(iVar1 + 0x17)]);
    }
  }
  *(undefined4 *)(param_1 + 0x58) = extraout_EAX;
  *(undefined4 *)(param_1 + 0x5c) = extraout_EDX;
  return;
}


// ----- caller: FUN_00416f20 @ 00416f20

void __thiscall FUN_00416f20(void *this,int param_1,char param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 extraout_EAX;
  int *piVar3;
  undefined4 extraout_EAX_00;
  PSINGLE_LIST_ENTRY p_Var4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint *puVar7;
  undefined1 auStack_68 [8];
  uint local_60;
  int *local_5c;
  int local_58 [2];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint local_40 [11];
  uint local_14;
  
  local_14 = DAT_0044f008 ^ (uint)auStack_68;
  uVar5 = *(uint *)(param_1 + 0x1c);
  if (uVar5 < 4) {
LAB_00417257:
    puVar7 = (uint *)((int)this + 0x2268);
    uVar5 = *puVar7;
    *puVar7 = *puVar7 + 1;
    *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
    uVar5 = *(uint *)(param_1 + 0x1c);
  }
  else {
    local_5c = *(int **)(param_1 + 0x20);
    iVar6 = *local_5c;
    if (iVar6 == 4) {
      if (0xf < uVar5) {
        FUN_00417600(this,param_1);
        __security_check_cookie(local_14 ^ (uint)auStack_68);
        return;
      }
      goto LAB_00417257;
    }
    if (iVar6 == 3) {
      if ((uVar5 == 0x40) && (*(char *)((int)this + 0xa5) != '\0')) {
        local_60 = local_5c[1];
        piVar1 = _Find_last<>((void *)((int)this + 0x3c),local_58,(int *)&local_60,local_60);
        piVar3 = local_5c;
        iVar6 = piVar1[1];
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)this + 0x40);
        }
        if ((((iVar6 != *(int *)((int)this + 0x40)) && (*(int *)(iVar6 + 0x10) == 0)) &&
            ((uint *)(iVar6 + 0xc) != (uint *)0x0)) &&
           (local_60 = *(uint *)(iVar6 + 0xc), *(char *)(local_60 + 0x36) != '\0')) {
          FUN_0041b1f0(local_40,(uint *)(local_5c + 2),(uint *)(local_60 + 0x1ac));
          uVar5 = local_60;
          uVar2 = FUN_0041cc10(&local_50,(uint *)(piVar3 + 8),0x20,(uint *)(local_60 + 0x1ec),0x10,piVar3[6],piVar3[7],
                               local_40);
          puVar7 = local_40;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if ((char)uVar2 != '\0') {
            puVar7 = (uint *)(uVar5 + 200);
            uVar2 = *puVar7;
            *puVar7 = *puVar7 + 0x40;
            *(undefined1 *)(uVar5 + 0x36) = 0;
            *(int *)(uVar5 + 0xcc) = *(int *)(uVar5 + 0xcc) + (uint)(0xffffffbf < uVar2);
            *(undefined1 *)(uVar5 + 0x38) = 1;
            GetTickCount64();
            *(undefined4 *)(uVar5 + 0x210) = extraout_EAX;
            *(undefined4 *)(uVar5 + 0x214) = extraout_EDX;
            *(undefined4 *)(uVar5 + 0x1fc) = local_50;
            *(undefined4 *)(uVar5 + 0x200) = uStack_4c;
            *(undefined4 *)(uVar5 + 0x204) = uStack_48;
            *(undefined4 *)(uVar5 + 0x208) = uStack_44;
          }
        }
        goto LAB_0041727a;
      }
      goto LAB_00417257;
    }
    if (iVar6 == 1) {
      if (uVar5 < 0x94) goto LAB_00417257;
      *(int *)((int)this + 0x22c8) = *(int *)((int)this + 0x22c8) + 1;
      iVar6 = FUN_00417850(this,param_1,param_2);
      if (iVar6 != 0) goto LAB_0041727a;
      local_60 = *(uint *)(param_1 + 0x1c);
      iVar6 = FUN_0042a220((void *)((int)this + 0x20),param_1);
      if (iVar6 != 0) {
        if (*(int **)((int)this + 0x38) != (int *)0x0) {
          (**(code **)(**(int **)((int)this + 0x38) + 0x24))(iVar6,param_1);
        }
        puVar7 = (uint *)((int)this + 0x2250);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x2254) = *(int *)((int)this + 0x2254) + (uint)(0xfffffffe < uVar5);
        uVar2 = *(uint *)(param_1 + 0x1c);
        puVar7 = (uint *)((int)this + 0x2260);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + uVar2;
        *(int *)((int)this + 0x2264) = *(int *)((int)this + 0x2264) + (uint)CARRY4(uVar5,uVar2);
        puVar7 = (uint *)((int)this + 0x2238);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar5);
        puVar7 = (uint *)((int)this + 0x2250);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        puVar7 = (uint *)((int)this + 0x2248);
        uVar2 = *puVar7;
        *puVar7 = *puVar7 + local_60;
        *(uint *)((int)this + 0x2254) = *(int *)((int)this + 0x2254) + (uint)(0xfffffffe < uVar5);
        *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar2,local_60);
        uVar2 = *(uint *)(param_1 + 0x1c);
        puVar7 = (uint *)((int)this + 0x2260);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + uVar2;
        *(uint *)((int)this + 0x2264) = *(int *)((int)this + 0x2264) + (uint)CARRY4(uVar5,uVar2);
        __security_check_cookie(local_14 ^ (uint)auStack_68);
        return;
      }
      puVar7 = (uint *)((int)this + 0x2268);
      uVar5 = *puVar7;
      *puVar7 = *puVar7 + 1;
      *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
      uVar5 = local_60;
    }
    else {
      if ((iVar6 != 2) || (uVar5 < 0x5c)) goto LAB_00417257;
      iVar6 = FUN_00417850(this,param_1,param_2);
      if (iVar6 != 0) goto LAB_0041727a;
      local_60 = *(uint *)(param_1 + 0x1c);
      piVar3 = (int *)FUN_0042abf0((int)this + 0x20,param_1);
      if (piVar3 != (int *)0x0) {
        puVar7 = (uint *)((int)this + 0x2238);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar5);
        puVar7 = (uint *)((int)this + 0x2248);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + local_60;
        *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar5,local_60);
        *(int *)((int)this + 0x22d4) = *(int *)((int)this + 0x22d4) + 1;
        piVar3[8] = piVar3[8] & 0xfffffefbU | 0x600;
        FUN_0042b770((int)piVar3);
        GetTickCount64();
        *(undefined4 *)((int)this + 0x22a0) = extraout_EAX_00;
        *(undefined4 *)((int)this + 0x22a4) = extraout_EDX_00;
        if (*(int *)((int)this + 0x2298) == 0 && *(int *)((int)this + 0x229c) == 0) {
          *(undefined4 *)((int)this + 0x2298) = extraout_EAX_00;
          *(undefined4 *)((int)this + 0x229c) = extraout_EDX_00;
        }
        if (*(undefined4 **)this != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)this)();
        }
        if ((short)piVar3[0x1a] != 0) {
          if (piVar3[0x12] == 0) {
            p_Var4 = FUN_0040e6a0();
            if (p_Var4 == (PSINGLE_LIST_ENTRY)0x0) goto LAB_0041727a;
            p_Var4[7].Next = (_SINGLE_LIST_ENTRY *)0x0;
            p_Var4->Next = (_SINGLE_LIST_ENTRY *)0x0;
            piVar3[0x12] = (int)p_Var4;
          }
          FUN_00417d90(this,piVar3);
        }
        goto LAB_0041727a;
      }
      puVar7 = (uint *)((int)this + 0x2268);
      uVar5 = *puVar7;
      *puVar7 = *puVar7 + 1;
      *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
      uVar5 = local_60;
    }
  }
  puVar7 = (uint *)((int)this + 0x2270);
  uVar2 = *puVar7;
  *puVar7 = *puVar7 + uVar5;
  *(int *)((int)this + 0x2274) = *(int *)((int)this + 0x2274) + (uint)CARRY4(uVar2,uVar5);
LAB_0041727a:
  __security_check_cookie(local_14 ^ (uint)auStack_68);
  return;
}


// ----- caller: FUN_00417290 @ 00417290

undefined4 __thiscall FUN_00417290(void *this,undefined4 *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  void *this_00;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 extraout_EAX;
  uint uVar10;
  int *piVar11;
  ushort uVar12;
  undefined4 extraout_EDX;
  bool bVar13;
  uint local_c;
  
  piVar3 = (int *)*param_1;
  if (*(char *)((int)piVar3 + 0x35) != '\0') {
    uVar12 = *(ushort *)(piVar3 + 0x21) ^ *(ushort *)(param_2 + 0x28);
    if (*(ushort *)(param_2 + 0x28) == 0x17) {
      local_c = (uint)(*(ushort *)((int)piVar3 + 0x86) ^ *(ushort *)(param_2 + 0x2a)) |
                piVar3[0x26] ^ *(uint *)(param_2 + 0x3c) | piVar3[0x24] ^ *(uint *)(param_2 + 0x34) | (uint)uVar12 |
                piVar3[0x25] ^ *(uint *)(param_2 + 0x38) | piVar3[0x23] ^ *(uint *)(param_2 + 0x30);
    }
    else {
      local_c = piVar3[0x22] ^ *(uint *)(param_2 + 0x2c) |
                (uint)(*(ushort *)((int)piVar3 + 0x86) ^ *(ushort *)(param_2 + 0x2a)) | (uint)uVar12;
    }
    if ((char)piVar3[0xf] != *(char *)(param_2 + 0x25) || local_c != 0) {
      iVar5 = *(int *)(param_2 + 0x2c);
      iVar8 = *(int *)(param_2 + 0x30);
      iVar9 = *(int *)(param_2 + 0x34);
      piVar3[0x21] = *(int *)(param_2 + 0x28);
      piVar3[0x22] = iVar5;
      piVar3[0x23] = iVar8;
      piVar3[0x24] = iVar9;
      *(undefined8 *)(piVar3 + 0x25) = *(undefined8 *)(param_2 + 0x38);
      piVar3[0x27] = *(int *)(param_2 + 0x40);
      *(undefined1 *)(piVar3 + 0xf) = *(undefined1 *)(param_2 + 0x25);
      if (*(char *)((int)param_1 + 0x11) == '\0') {
        iVar5 = *(int *)(param_2 + 0x2c);
        iVar8 = *(int *)(param_2 + 0x30);
        iVar9 = *(int *)(param_2 + 0x34);
        piVar3[0x1a] = *(int *)(param_2 + 0x28);
        piVar3[0x1b] = iVar5;
        piVar3[0x1c] = iVar8;
        piVar3[0x1d] = iVar9;
        *(undefined8 *)(piVar3 + 0x1e) = *(undefined8 *)(param_2 + 0x38);
        piVar3[0x20] = *(int *)(param_2 + 0x40);
        *(undefined1 *)((int)piVar3 + 0x3b) = *(undefined1 *)(param_2 + 0x25);
      }
    }
  }
  puVar1 = param_1 + 0xe;
  uVar10 = *puVar1;
  *puVar1 = *puVar1 + 1;
  param_1[0xf] = param_1[0xf] + (uint)(0xfffffffe < uVar10);
  if (param_1 == (undefined4 *)piVar3[4]) {
    puVar4 = (undefined4 *)piVar3[3];
    piVar3[3] = 0;
    if (puVar4 != (undefined4 *)0x0) {
      this_00 = *(void **)*puVar4;
      if (puVar4[1] != 0) {
        FUN_00429970(this_00,(int)puVar4);
      }
      if (puVar4[6] != 0) {
        FUN_0042c360((void *)((int)this_00 + 0x1c),puVar4 + 6);
        puVar4[6] = 0;
      }
      *(undefined1 *)(puVar4 + 5) = 0;
      FUN_0040cb70((void *)((int)this_00 + 0x21e8),FUN_0042b190,(uint)puVar4);
    }
    piVar3[3] = piVar3[2];
    piVar3[2] = piVar3[4];
    piVar3[4] = 0;
    piVar3[6] = 0;
    piVar3[7] = 0;
    *(int *)((int)this + 0x22d0) = *(int *)((int)this + 0x22d0) + 1;
    FUN_0042b770((int)piVar3);
    GetTickCount64();
    *(undefined4 *)((int)this + 0x22a0) = extraout_EAX;
    *(undefined4 *)((int)this + 0x22a4) = extraout_EDX;
    if (*(int *)((int)this + 0x2298) == 0 && *(int *)((int)this + 0x229c) == 0) {
      *(undefined4 *)((int)this + 0x2298) = extraout_EAX;
      *(undefined4 *)((int)this + 0x229c) = extraout_EDX;
    }
    if (*(undefined4 **)this != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)this)();
    }
    FUN_00417d90(this,piVar3);
  }
  iVar5 = piVar3[2];
  if ((iVar5 != 0) && (*(char *)(iVar5 + 0x14) == '\x02')) {
    *(undefined1 *)(iVar5 + 0x14) = 3;
    puVar1 = (uint *)(piVar3 + 10);
    uVar10 = *puVar1;
    do {
      LOCK();
      uVar2 = *puVar1;
      bVar13 = uVar10 == uVar2;
      if (bVar13) {
        *puVar1 = uVar10 | 1;
      }
      else {
        uVar10 = uVar2;
      }
      UNLOCK();
    } while (!bVar13);
    if (uVar10 == 0) {
      piVar3[0xb] = 0;
      **(undefined4 **)(*piVar3 + 0x80) = piVar3;
      *(int **)(*piVar3 + 0x80) = piVar3 + 0xb;
    }
  }
  uVar10 = piVar3[8] & 0xfffffefb;
  if (param_3 == 0) {
    piVar3[8] = uVar10 | 0xc00;
    puVar1 = (uint *)((int)this + 0x2238);
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar10);
    uVar2 = *(uint *)(param_2 + 0x1c);
    puVar1 = (uint *)((int)this + 0x2248);
    uVar10 = *puVar1;
    *puVar1 = *puVar1 + uVar2;
    *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar10,uVar2);
    return 3;
  }
  if ((piVar3[8] & 0x82U) == 0) {
    uVar10 = uVar10 | 0x80;
  }
  else {
    *(undefined1 *)(piVar3 + 0xd) = 1;
  }
  piVar3[8] = uVar10 | 0xc00;
  pbVar6 = *(byte **)(param_2 + 0x20);
  if (*pbVar6 >> 4 == 4) {
    if (param_3 < 0x14) goto LAB_0041755e;
    uVar10 = *(uint *)(pbVar6 + 0xc);
    piVar11 = (int *)FUN_00402500((void *)((int)this + 0x2c),
                                  uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 | uVar10 << 0x18);
    if ((piVar11 != piVar3) ||
       (uVar10 = (uint)CONCAT11((char)*(undefined2 *)(pbVar6 + 2),(char)((ushort)*(undefined2 *)(pbVar6 + 2) >> 8)),
       uVar10 < 0x14)) goto LAB_0041755e;
  }
  else {
    if ((*pbVar6 >> 4 != 6) || (param_3 < 0x28)) goto LAB_0041755e;
    piVar11 = (int *)FUN_00402370((void *)((int)this + 0x20),(uint *)(pbVar6 + 8));
    if (piVar11 != piVar3) goto LAB_0041755e;
    uVar10 = CONCAT11((char)*(undefined2 *)(pbVar6 + 4),(char)((ushort)*(undefined2 *)(pbVar6 + 4) >> 8)) + 0x28;
  }
  if (uVar10 <= param_3) {
    puVar1 = (uint *)((int)this + 0x2238);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar2);
    puVar1 = (uint *)((int)this + 0x2240);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar10;
    *(int *)((int)this + 0x2244) = *(int *)((int)this + 0x2244) + (uint)CARRY4(uVar2,uVar10);
    uVar7 = *(uint *)(param_2 + 0x1c);
    puVar1 = (uint *)((int)this + 0x2248);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar2,uVar7);
    *(uint *)(param_2 + 0x1c) = uVar10;
    return 2;
  }
LAB_0041755e:
  *(int *)((int)this + 0x2288) = *(int *)((int)this + 0x2288) + 1;
  puVar1 = (uint *)((int)this + 0x2268);
  uVar10 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar10);
  uVar2 = *(uint *)(param_2 + 0x1c);
  puVar1 = (uint *)((int)this + 0x2270);
  uVar10 = *puVar1;
  *puVar1 = *puVar1 + uVar2;
  *(int *)((int)this + 0x2274) = *(int *)((int)this + 0x2274) + (uint)CARRY4(uVar10,uVar2);
  return 3;
}


// ----- callee: FUN_0040e0a0 @ 0040e0a0

void __cdecl FUN_0040e0a0(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(0,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: KERNEL32.DLL::GetTickCount64 @ EXTERNAL:00000060
// decompile failed: Exception while decompiling EXTERNAL:00000060: Cannot marshal address space: EXTERNAL


// ===================== FUN_00420280 @ 00420280  anchors: [ObfuscateKey(win@0044828c), ObfuscateKey] =====================

void __thiscall FUN_00420280(void *this,byte *param_1,byte *param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  char *pcVar13;
  byte *pbVar14;
  byte *pbVar15;
  int *piVar16;
  uint *puVar17;
  void *pvVar18;
  byte bVar19;
  undefined1 uVar20;
  int iVar21;
  char unaff_DI;
  bool bVar22;
  uint local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  uint local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  int local_c8 [16];
  uint local_88;
  char local_80;
  void *local_78;
  int local_74;
  int local_70;
  int *local_6c;
  void *local_68;
  uint *local_64;
  byte local_5d;
  uint local_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined2 local_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  uint local_30;
  undefined4 local_2c [8];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  uVar20 = 0;
  pcVar13 = "[Interface]";
  local_68 = (void *)0x0;
  local_78 = (void *)0x0;
  local_74 = 0;
  local_70 = 0;
  local_64 = param_3;
  pbVar5 = param_1;
  do {
    bVar19 = *pbVar5;
    bVar22 = bVar19 < (byte)*pcVar13;
    if (bVar19 != *pcVar13) {
LAB_004202e0:
      uVar6 = -(uint)bVar22 | 1;
      goto LAB_004202e5;
    }
    if (bVar19 == 0) break;
    bVar19 = pbVar5[1];
    bVar22 = bVar19 < (byte)pcVar13[1];
    if (bVar19 != pcVar13[1]) goto LAB_004202e0;
    pbVar5 = pbVar5 + 2;
    pcVar13 = pcVar13 + 2;
  } while (bVar19 != 0);
  uVar6 = 0;
LAB_004202e5:
  local_6c = this;
  if (uVar6 == 0) {
    if ((param_2 != (byte *)0x0) &&
       ((*(int **)(*(int *)this + 0x38) == (int *)0x0 ||
        (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 8))(param_2,param_3), cVar4 == '\0')))) {
      pcVar13 = "PrivateKey";
      pbVar5 = param_2;
      do {
        bVar19 = *pbVar5;
        bVar22 = bVar19 < (byte)*pcVar13;
        if (bVar19 != *pcVar13) {
LAB_00420340:
          uVar6 = -(uint)bVar22 | 1;
          goto LAB_00420345;
        }
        if (bVar19 == 0) break;
        bVar19 = pbVar5[1];
        bVar22 = bVar19 < (byte)pcVar13[1];
        if (bVar19 != pcVar13[1]) goto LAB_00420340;
        pbVar5 = pbVar5 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar19 != 0);
      uVar6 = 0;
LAB_00420345:
      if (uVar6 == 0) {
        local_64 = (uint *)0x20;
        puVar17 = param_3;
        do {
          uVar6 = *puVar17;
          puVar17 = (uint *)((int)puVar17 + 1);
        } while ((char)uVar6 != '\0');
        uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)local_2c,(uint *)&local_64)
        ;
        if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
          *(undefined1 *)((int)this + 0x50) = 1;
          FUN_00429640((void *)(*(int *)this + 0x20),local_2c);
        }
      }
      else {
        pcVar13 = "ListenPort";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_004203c2:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_004203c7;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_004203c2;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_004203c7:
        if (uVar6 == 0) {
          uVar8 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xc) == uVar8) goto LAB_00420763;
          uVar6 = uVar8 & 0xffff;
          *(short *)(iVar9 + 0xc) = (short)uVar8;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar8 = (uint)*(ushort *)(iVar9 + 0xe);
        }
        else {
          pcVar13 = "ListenPortTCP";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00420422:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00420427;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00420422;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00420427:
          if (uVar6 != 0) {
            pcVar13 = "Address";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_004204a5:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_004204aa;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_004204a5;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_004204aa:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if (cVar4 == '\0') break;
                  iVar9 = *(int *)this;
                  puVar17 = *(uint **)(iVar9 + 0x2334);
                  if (puVar17 == *(uint **)(iVar9 + 0x2338)) {
                    FUN_00414bc0((void *)(iVar9 + 0x2330),puVar17,&local_5c);
                  }
                  else {
                    *puVar17 = local_5c;
                    puVar17[1] = uStack_58;
                    puVar17[2] = uStack_54;
                    puVar17[3] = uStack_50;
                    *(undefined2 *)(puVar17 + 4) = local_4c;
                    *(int *)(iVar9 + 0x2334) = *(int *)(iVar9 + 0x2334) + 0x12;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pbVar14 = &DAT_0044a2d0;
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < *pbVar14;
                if (bVar19 != *pbVar14) {
LAB_00420550:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_00420555;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < pbVar14[1];
                if (bVar19 != pbVar14[1]) goto LAB_00420550;
                pbVar5 = pbVar5 + 2;
                pbVar14 = pbVar14 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_00420555:
              if (uVar6 == 0) {
                iVar9 = FID_conflict__atoi((char *)param_3);
                if ((0x23f < iVar9) && (iVar9 < 0x2711)) {
                  *(short *)(*(int *)this + 0x10) = (short)iVar9;
                }
              }
              else {
                pcVar13 = "Table";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_004205b0:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_004205b5;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_004205b0;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_004205b5:
                if (uVar6 == 0) {
                  pbVar5 = &DAT_0044a25c;
                  puVar17 = param_3;
                  do {
                    bVar19 = (byte)*puVar17;
                    bVar22 = bVar19 < *pbVar5;
                    if (bVar19 != *pbVar5) {
LAB_004205e4:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004205e9;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = *(byte *)((int)puVar17 + 1);
                    bVar22 = bVar19 < pbVar5[1];
                    if (bVar19 != pbVar5[1]) goto LAB_004205e4;
                    puVar17 = (uint *)((int)puVar17 + 2);
                    pbVar5 = pbVar5 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004205e9:
                  if (uVar6 == 0) {
                    *(undefined1 *)(*(int *)this + 0x14) = 0;
                  }
                  else {
                    pbVar5 = &DAT_0044a2dc;
                    do {
                      bVar19 = (byte)*param_3;
                      bVar22 = bVar19 < *pbVar5;
                      if (bVar19 != *pbVar5) {
LAB_00420620:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_00420625;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = *(byte *)((int)param_3 + 1);
                      bVar22 = bVar19 < pbVar5[1];
                      if (bVar19 != pbVar5[1]) goto LAB_00420620;
                      param_3 = (uint *)((int)param_3 + 2);
                      pbVar5 = pbVar5 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_00420625:
                    if (uVar6 == 0) {
                      *(undefined1 *)(*(int *)this + 0x14) = 1;
                    }
                  }
                }
                else {
                  pbVar14 = &DAT_0044a2e4;
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < *pbVar14;
                    if (bVar19 != *pbVar14) {
LAB_00420662:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_00420667;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < pbVar14[1];
                    if (bVar19 != pbVar14[1]) goto LAB_00420662;
                    pbVar5 = pbVar5 + 2;
                    pbVar14 = pbVar14 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_00420667:
                  if (uVar6 == 0) {
                    FUN_0040e1b0(param_3,&local_78);
                    puVar17 = (uint *)0x0;
                    local_68 = local_78;
                    local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                    if (local_64 != (uint *)0x0) {
                      do {
                        piVar10 = *(int **)((int)local_68 + (int)puVar17 * 4);
                        pvVar18 = *(void **)((int)this + 0x4c);
                        local_48 = 0;
                        uStack_44 = 0;
                        uStack_40 = 0;
                        uStack_3c = 0;
                        local_30 = 0;
                        local_38 = 0;
                        iVar9 = inet_pton(0x17,piVar10,&uStack_40);
                        if (iVar9 == 1) {
                          local_48 = CONCAT22(local_48._2_2_,0x17);
                        }
                        else {
                          iVar9 = inet_pton(2,piVar10,&uStack_44);
                          if (iVar9 == 1) {
                            local_48 = CONCAT22(local_48._2_2_,2);
                          }
                          else {
                            if (pvVar18 == (void *)0x0) break;
                            cVar4 = FUN_0040c0e0(pvVar18,piVar10,(int *)&local_48);
                            if (cVar4 == '\0') {
                              FUN_0040e010("Unable to resolve %s",(char)piVar10);
                              break;
                            }
                          }
                        }
                        this = local_6c;
                        iVar9 = *local_6c;
                        puVar1 = *(uint **)(iVar9 + 0x2340);
                        if (puVar1 == *(uint **)(iVar9 + 0x2344)) {
                          FUN_004181c0((void *)(iVar9 + 0x233c),puVar1,&local_48);
                        }
                        else {
                          *puVar1 = local_48;
                          puVar1[1] = uStack_44;
                          puVar1[2] = uStack_40;
                          puVar1[3] = uStack_3c;
                          *(undefined8 *)(puVar1 + 4) = local_38;
                          puVar1[6] = local_30;
                          *(int *)(iVar9 + 0x2340) = *(int *)(iVar9 + 0x2340) + 0x1c;
                        }
                        puVar17 = (uint *)((int)puVar17 + 1);
                      } while (puVar17 < local_64);
                    }
                  }
                  else {
                    pcVar13 = "BlockDNS";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_004207c4:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_004207c9;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_004207c4;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_004207c9:
                    if (uVar6 == 0) {
                      uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                      if ((char)uVar7 != '\0') {
                        *(byte *)(*(int *)this + 0x12) = local_5d;
                      }
                    }
                    else {
                      pcVar13 = "BlockInternet";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00420811:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00420816;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00420811;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00420816:
                      if (uVar6 == 0) {
                        bVar19 = 0xff;
                        FUN_0040e1b0(param_3,&local_78);
                        puVar17 = (uint *)0x0;
                        local_68 = local_78;
                        local_64 = (uint *)(local_74 - (int)local_78 >> 2);
                        if (local_64 != (uint *)0x0) {
                          do {
                            pbVar5 = *(byte **)((int)local_68 + (int)puVar17 * 4);
                            pcVar13 = "route";
                            pbVar14 = pbVar5;
                            do {
                              bVar12 = *pbVar14;
                              bVar22 = bVar12 < (byte)*pcVar13;
                              if (bVar12 != *pcVar13) {
LAB_00420880:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420885;
                              }
                              if (bVar12 == 0) break;
                              bVar12 = pbVar14[1];
                              bVar22 = bVar12 < (byte)pcVar13[1];
                              if (bVar12 != pcVar13[1]) goto LAB_00420880;
                              pbVar14 = pbVar14 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar12 != 0);
                            uVar6 = 0;
LAB_00420885:
                            if (uVar6 == 0) {
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 1;
                            }
                            else {
                              pcVar13 = "firewall";
                              pbVar14 = pbVar5;
                              do {
                                bVar12 = *pbVar14;
                                bVar22 = bVar12 < (byte)*pcVar13;
                                if (bVar12 != *pcVar13) {
LAB_004208c4:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_004208c9;
                                }
                                if (bVar12 == 0) break;
                                bVar12 = pbVar14[1];
                                bVar22 = bVar12 < (byte)pcVar13[1];
                                if (bVar12 != pcVar13[1]) goto LAB_004208c4;
                                pbVar14 = pbVar14 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar12 != 0);
                              uVar6 = 0;
LAB_004208c9:
                              if (uVar6 != 0) {
                                pbVar15 = &DAT_0044a248;
                                pbVar14 = pbVar5;
                                do {
                                  bVar12 = *pbVar14;
                                  bVar22 = bVar12 < *pbVar15;
                                  if (bVar12 != *pbVar15) {
LAB_004208f8:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_004208fd;
                                  }
                                  if (bVar12 == 0) break;
                                  bVar12 = pbVar14[1];
                                  bVar22 = bVar12 < pbVar15[1];
                                  if (bVar12 != pbVar15[1]) goto LAB_004208f8;
                                  pbVar14 = pbVar14 + 2;
                                  pbVar15 = pbVar15 + 2;
                                } while (bVar12 != 0);
                                uVar6 = 0;
LAB_004208fd:
                                if (uVar6 != 0) {
                                  pbVar15 = &DAT_0044a25c;
                                  pbVar14 = pbVar5;
                                  do {
                                    bVar12 = *pbVar14;
                                    bVar22 = bVar12 < *pbVar15;
                                    if (bVar12 != *pbVar15) {
LAB_00420930:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420935;
                                    }
                                    if (bVar12 == 0) break;
                                    bVar12 = pbVar14[1];
                                    bVar22 = bVar12 < pbVar15[1];
                                    if (bVar12 != pbVar15[1]) goto LAB_00420930;
                                    pbVar14 = pbVar14 + 2;
                                    pbVar15 = pbVar15 + 2;
                                  } while (bVar12 != 0);
                                  uVar6 = 0;
LAB_00420935:
                                  if (uVar6 == 0) {
                                    bVar19 = 0;
                                  }
                                  else {
                                    pcVar13 = "default";
                                    pbVar14 = pbVar5;
                                    do {
                                      bVar12 = *pbVar14;
                                      bVar22 = bVar12 < (byte)*pcVar13;
                                      if (bVar12 != *pcVar13) {
LAB_00420967:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_0042096c;
                                      }
                                      if (bVar12 == 0) break;
                                      bVar12 = pbVar14[1];
                                      bVar22 = bVar12 < (byte)pcVar13[1];
                                      if (bVar12 != pcVar13[1]) goto LAB_00420967;
                                      pbVar14 = pbVar14 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar12 != 0);
                                    uVar6 = 0;
LAB_0042096c:
                                    if (uVar6 == 0) {
                                      bVar19 = 0xff;
                                    }
                                    else {
                                      pcVar13 = "persist";
                                      pbVar14 = pbVar5;
                                      do {
                                        bVar12 = *pbVar14;
                                        bVar22 = bVar12 < (byte)*pcVar13;
                                        if (bVar12 != *pcVar13) {
LAB_004209a0:
                                          uVar6 = -(uint)bVar22 | 1;
                                          goto LAB_004209a5;
                                        }
                                        if (bVar12 == 0) break;
                                        bVar12 = pbVar14[1];
                                        bVar22 = bVar12 < (byte)pcVar13[1];
                                        if (bVar12 != pcVar13[1]) goto LAB_004209a0;
                                        pbVar14 = pbVar14 + 2;
                                        pcVar13 = pcVar13 + 2;
                                      } while (bVar12 != 0);
                                      uVar6 = 0;
LAB_004209a5:
                                      if (uVar6 == 0) {
                                        bVar12 = 0;
                                        if (-1 < (char)bVar19) {
                                          bVar12 = bVar19;
                                        }
                                        bVar19 = bVar12 | 0x10;
                                      }
                                      else {
                                        pcVar13 = "allow_local";
                                        pbVar14 = pbVar5;
                                        do {
                                          bVar12 = *pbVar14;
                                          bVar22 = bVar12 < (byte)*pcVar13;
                                          if (bVar12 != *pcVar13) {
LAB_004209e1:
                                            uVar6 = -(uint)bVar22 | 1;
                                            goto LAB_004209e6;
                                          }
                                          if (bVar12 == 0) break;
                                          bVar12 = pbVar14[1];
                                          bVar22 = bVar12 < (byte)pcVar13[1];
                                          if (bVar12 != pcVar13[1]) goto LAB_004209e1;
                                          pbVar14 = pbVar14 + 2;
                                          pcVar13 = pcVar13 + 2;
                                        } while (bVar12 != 0);
                                        uVar6 = 0;
LAB_004209e6:
                                        if (uVar6 == 0) {
                                          bVar12 = 0;
                                          if (-1 < (char)bVar19) {
                                            bVar12 = bVar19;
                                          }
                                          bVar19 = bVar12 | 0x20;
                                        }
                                        else {
                                          FUN_0040e010("Unknown mode in BlockInternet: %s",(char)pbVar5);
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_00420a1a;
                                }
                              }
                              bVar12 = 0;
                              if (-1 < (char)bVar19) {
                                bVar12 = bVar19;
                              }
                              bVar19 = bVar12 | 2;
                            }
LAB_00420a1a:
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while (puVar17 < local_64);
                        }
                        *(byte *)(*local_6c + 0x13) = bVar19;
                      }
                      else {
                        pcVar13 = "ObfuscateKey";
                        pbVar5 = param_2;
                        do {
                          bVar19 = *pbVar5;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00420a60:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00420a65;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = pbVar5[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00420a60;
                          pbVar5 = pbVar5 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00420a65:
                        if (uVar6 == 0) {
                          puVar17 = param_3;
                          do {
                            uVar6 = *puVar17;
                            puVar17 = (uint *)((int)puVar17 + 1);
                          } while ((char)uVar6 != '\0');
                          iVar9 = *(int *)this;
                          *(bool *)(iVar9 + 0x1a8) = param_3 != (uint *)0x0;
                          if (param_3 != (uint *)0x0) {
                            FUN_00418620(&local_f8,0x20,(uint *)&DAT_0044828c,0x20);
                            FUN_00419bc0(&local_f8,param_3,(int)puVar17 - ((int)param_3 + 1));
                            local_d8 = local_d8 + local_88;
                            local_d0 = 0xffffffff;
                            local_d4 = local_d4 + (uint)(local_d8 < local_88);
                            if (local_80 != '\0') {
                              local_cc = 0xffffffff;
                            }
                            _memset((void *)((int)local_c8 + local_88),0,0x40 - local_88);
                            FUN_004186e0(&local_f8,local_c8);
                            *(uint *)(iVar9 + 0x1b0) = local_f8;
                            *(undefined4 *)(iVar9 + 0x1b4) = uStack_f4;
                            *(undefined4 *)(iVar9 + 0x1b8) = uStack_f0;
                            *(undefined4 *)(iVar9 + 0x1bc) = uStack_ec;
                            *(undefined4 *)(iVar9 + 0x1c0) = local_e8;
                            *(undefined4 *)(iVar9 + 0x1c4) = uStack_e4;
                            *(undefined4 *)(iVar9 + 0x1c8) = uStack_e0;
                            *(undefined4 *)(iVar9 + 0x1cc) = uStack_dc;
                          }
                        }
                        else {
                          pcVar13 = "ObfuscateTCP";
                          pbVar5 = param_2;
                          do {
                            bVar19 = *pbVar5;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_00420b70:
                              uVar6 = -(uint)bVar22 | 1;
                              goto LAB_00420b75;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar5[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_00420b70;
                            pbVar5 = pbVar5 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar6 = 0;
LAB_00420b75:
                          if (uVar6 == 0) {
                            uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                            if ((char)uVar7 == '\0') {
                              pcVar13 = "tls-firefox";
                              puVar17 = param_3;
                              do {
                                bVar19 = (byte)*puVar17;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420bc8:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420bcd;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = *(byte *)((int)puVar17 + 1);
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420bc8;
                                puVar17 = (uint *)((int)puVar17 + 2);
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420bcd:
                              if (uVar6 == 0) {
                                *(undefined4 *)(*(int *)this + 0x1ac) = 2;
                              }
                              else {
                                pcVar13 = "tls-chrome";
                                puVar17 = param_3;
                                do {
                                  bVar19 = (byte)*puVar17;
                                  bVar22 = bVar19 < (byte)*pcVar13;
                                  if (bVar19 != *pcVar13) {
LAB_00420c10:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420c15;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = *(byte *)((int)puVar17 + 1);
                                  bVar22 = bVar19 < (byte)pcVar13[1];
                                  if (bVar19 != pcVar13[1]) goto LAB_00420c10;
                                  puVar17 = (uint *)((int)puVar17 + 2);
                                  pcVar13 = pcVar13 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420c15:
                                if (uVar6 == 0) {
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 3;
                                }
                                else {
                                  if ((char)*param_3 != '\0') {
                                    FUN_0040e010("Unknown mode in ObfuscateTCP: %s",(char)param_3);
                                  }
                                  *(undefined4 *)(*(int *)this + 0x1ac) = 1;
                                }
                              }
                            }
                            else {
                              *(uint *)(*(int *)this + 0x1ac) = (uint)local_5d;
                            }
                          }
                          else {
                            pcVar13 = "PostUp";
                            pbVar5 = param_2;
                            do {
                              bVar19 = *pbVar5;
                              bVar22 = bVar19 < (byte)*pcVar13;
                              if (bVar19 != *pcVar13) {
LAB_00420c76:
                                uVar6 = -(uint)bVar22 | 1;
                                goto LAB_00420c7b;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar5[1];
                              bVar22 = bVar19 < (byte)pcVar13[1];
                              if (bVar19 != pcVar13[1]) goto LAB_00420c76;
                              pbVar5 = pbVar5 + 2;
                              pcVar13 = pcVar13 + 2;
                            } while (bVar19 != 0);
                            uVar6 = 0;
LAB_00420c7b:
                            if (uVar6 == 0) {
                              iVar9 = *(int *)this;
                              piVar10 = *(int **)(iVar9 + 0x2358);
                              if (piVar10 == *(int **)(iVar9 + 0x235c)) {
                                FUN_00422a20((void *)(iVar9 + 0x2354),piVar10,&local_64);
                              }
                              else {
                                piVar10[4] = 0;
                                piVar10[5] = 0xf;
                                *(undefined1 *)piVar10 = 0;
                                puVar17 = param_3;
                                do {
                                  uVar6 = *puVar17;
                                  puVar17 = (uint *)((int)puVar17 + 1);
                                } while ((char)uVar6 != '\0');
                                FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                *(int *)(iVar9 + 0x2358) = *(int *)(iVar9 + 0x2358) + 0x18;
                              }
                            }
                            else {
                              pcVar13 = "PostDown";
                              pbVar5 = param_2;
                              do {
                                bVar19 = *pbVar5;
                                bVar22 = bVar19 < (byte)*pcVar13;
                                if (bVar19 != *pcVar13) {
LAB_00420d00:
                                  uVar6 = -(uint)bVar22 | 1;
                                  goto LAB_00420d05;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar5[1];
                                bVar22 = bVar19 < (byte)pcVar13[1];
                                if (bVar19 != pcVar13[1]) goto LAB_00420d00;
                                pbVar5 = pbVar5 + 2;
                                pcVar13 = pcVar13 + 2;
                              } while (bVar19 != 0);
                              uVar6 = 0;
LAB_00420d05:
                              if (uVar6 == 0) {
                                iVar9 = *(int *)this;
                                piVar10 = *(int **)(iVar9 + 0x2370);
                                if (piVar10 == *(int **)(iVar9 + 0x2374)) {
                                  FUN_00422a20((void *)(iVar9 + 0x236c),piVar10,&local_64);
                                }
                                else {
                                  piVar10[4] = 0;
                                  piVar10[5] = 0xf;
                                  *(undefined1 *)piVar10 = 0;
                                  puVar17 = param_3;
                                  do {
                                    uVar6 = *puVar17;
                                    puVar17 = (uint *)((int)puVar17 + 1);
                                  } while ((char)uVar6 != '\0');
                                  FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                  *(int *)(iVar9 + 0x2370) = *(int *)(iVar9 + 0x2370) + 0x18;
                                }
                              }
                              else {
                                pbVar14 = &DAT_0044a3c8;
                                pbVar5 = param_2;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00420d90:
                                    uVar6 = -(uint)bVar22 | 1;
                                    goto LAB_00420d95;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00420d90;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar6 = 0;
LAB_00420d95:
                                if (uVar6 == 0) {
                                  iVar9 = *(int *)this;
                                  piVar10 = *(int **)(iVar9 + 0x234c);
                                  if (piVar10 == *(int **)(iVar9 + 0x2350)) {
                                    FUN_00422a20((void *)(iVar9 + 0x2348),piVar10,&local_64);
                                  }
                                  else {
                                    piVar10[4] = 0;
                                    piVar10[5] = 0xf;
                                    *(undefined1 *)piVar10 = 0;
                                    puVar17 = param_3;
                                    do {
                                      uVar6 = *puVar17;
                                      puVar17 = (uint *)((int)puVar17 + 1);
                                    } while ((char)uVar6 != '\0');
                                    FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                    *(int *)(iVar9 + 0x234c) = *(int *)(iVar9 + 0x234c) + 0x18;
                                  }
                                }
                                else {
                                  pcVar13 = "PreDown";
                                  pbVar5 = param_2;
                                  do {
                                    bVar19 = *pbVar5;
                                    bVar22 = bVar19 < (byte)*pcVar13;
                                    if (bVar19 != *pcVar13) {
LAB_00420e20:
                                      uVar6 = -(uint)bVar22 | 1;
                                      goto LAB_00420e25;
                                    }
                                    if (bVar19 == 0) break;
                                    bVar19 = pbVar5[1];
                                    bVar22 = bVar19 < (byte)pcVar13[1];
                                    if (bVar19 != pcVar13[1]) goto LAB_00420e20;
                                    pbVar5 = pbVar5 + 2;
                                    pcVar13 = pcVar13 + 2;
                                  } while (bVar19 != 0);
                                  uVar6 = 0;
LAB_00420e25:
                                  if (uVar6 == 0) {
                                    iVar9 = *(int *)this;
                                    piVar10 = *(int **)(iVar9 + 0x2364);
                                    if (piVar10 == *(int **)(iVar9 + 0x2368)) {
                                      FUN_00422a20((void *)(iVar9 + 0x2360),piVar10,&local_64);
                                    }
                                    else {
                                      piVar10[4] = 0;
                                      piVar10[5] = 0xf;
                                      *(undefined1 *)piVar10 = 0;
                                      puVar17 = param_3;
                                      do {
                                        uVar6 = *puVar17;
                                        puVar17 = (uint *)((int)puVar17 + 1);
                                      } while ((char)uVar6 != '\0');
                                      FUN_004096e0(piVar10,param_3,(int)puVar17 - ((int)param_3 + 1));
                                      *(int *)(iVar9 + 0x2364) = *(int *)(iVar9 + 0x2364) + 0x18;
                                    }
                                  }
                                  else {
                                    pcVar13 = "ExcludedIPs";
                                    do {
                                      bVar19 = *param_2;
                                      bVar22 = bVar19 < (byte)*pcVar13;
                                      if (bVar19 != *pcVar13) {
LAB_00420eb0:
                                        uVar6 = -(uint)bVar22 | 1;
                                        goto LAB_00420eb5;
                                      }
                                      if (bVar19 == 0) break;
                                      bVar19 = param_2[1];
                                      bVar22 = bVar19 < (byte)pcVar13[1];
                                      if (bVar19 != pcVar13[1]) goto LAB_00420eb0;
                                      param_2 = param_2 + 2;
                                      pcVar13 = pcVar13 + 2;
                                    } while (bVar19 != 0);
                                    uVar6 = 0;
LAB_00420eb5:
                                    if (uVar6 == 0) {
                                      FUN_0040e1b0(param_3,&local_78);
                                      uVar6 = 0;
                                      local_68 = local_78;
                                      uVar8 = local_74 - (int)local_78 >> 2;
                                      if (uVar8 != 0) {
                                        do {
                                          cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                                          if (cVar4 == '\0') break;
                                          iVar9 = *(int *)this;
                                          puVar17 = *(uint **)(iVar9 + 0x2394);
                                          if (puVar17 == *(uint **)(iVar9 + 0x2398)) {
                                            FUN_00414bc0((void *)(iVar9 + 0x2390),puVar17,&local_5c);
                                          }
                                          else {
                                            *puVar17 = local_5c;
                                            puVar17[1] = uStack_58;
                                            puVar17[2] = uStack_54;
                                            puVar17[3] = uStack_50;
                                            *(undefined2 *)(puVar17 + 4) = local_4c;
                                            *(int *)(iVar9 + 0x2394) = *(int *)(iVar9 + 0x2394) + 0x12;
                                          }
                                          uVar6 = uVar6 + 1;
                                        } while (uVar6 < uVar8);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00420763;
          }
          uVar6 = FID_conflict__atoi((char *)param_3);
          iVar9 = *(int *)this;
          if (*(ushort *)(iVar9 + 0xe) == uVar6) goto LAB_00420763;
          uVar8 = uVar6 & 0xffff;
          *(short *)(iVar9 + 0xe) = (short)uVar6;
          if (*(char *)(iVar9 + 0x17) == '\0') goto LAB_00420763;
          uVar6 = (uint)*(ushort *)(iVar9 + 0xc);
        }
        cVar4 = (**(code **)**(undefined4 **)(iVar9 + 8))(uVar6,uVar8);
        if (cVar4 == '\0') {
          FUN_0040e0a0("ConfigureUdp failed",unaff_DI);
        }
      }
    }
  }
  else {
    pbVar5 = &DAT_0044a3e4;
    do {
      bVar19 = *param_1;
      bVar22 = bVar19 < *pbVar5;
      if (bVar19 != *pbVar5) {
LAB_00420f60:
        uVar6 = -(uint)bVar22 | 1;
        goto LAB_00420f65;
      }
      if (bVar19 == 0) break;
      bVar19 = param_1[1];
      bVar22 = bVar19 < pbVar5[1];
      if (bVar19 != pbVar5[1]) goto LAB_00420f60;
      param_1 = param_1 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar19 != 0);
    uVar6 = 0;
LAB_00420f65:
    if (uVar6 == 0) {
      if (param_2 == (byte *)0x0) {
        if (*(char *)((int)this + 0x50) == '\0') {
          FUN_0040e010("Missing [Interface].PrivateKey.",unaff_DI);
        }
        else {
          if (*(void **)((int)this + 0x48) != (void *)0x0) {
            FUN_00429d00(*(void **)((int)this + 0x48),(uint *)((int)this + 8));
            *(undefined4 *)((int)this + 0x48) = 0;
          }
          piVar10 = FUN_004296d0(*(int *)this + 0x20);
          *(int **)((int)this + 0x48) = piVar10;
          _memset((uint *)((int)this + 8),0,0x40);
        }
      }
      else if ((*(int **)(*(int *)this + 0x38) == (int *)0x0) ||
              (cVar4 = (**(code **)(**(int **)(*(int *)this + 0x38) + 0xc))
                                 (*(undefined4 *)((int)this + 0x48),param_2,param_3), cVar4 == '\0')) {
        piVar10 = local_6c;
        pcVar13 = "PublicKey";
        pbVar5 = param_2;
        do {
          bVar19 = *pbVar5;
          bVar22 = bVar19 < (byte)*pcVar13;
          if (bVar19 != *pcVar13) {
LAB_00421010:
            uVar6 = -(uint)bVar22 | 1;
            goto LAB_00421015;
          }
          if (bVar19 == 0) break;
          bVar19 = pbVar5[1];
          bVar22 = bVar19 < (byte)pcVar13[1];
          if (bVar19 != pcVar13[1]) goto LAB_00421010;
          pbVar5 = pbVar5 + 2;
          pcVar13 = pcVar13 + 2;
        } while (bVar19 != 0);
        uVar6 = 0;
LAB_00421015:
        if (uVar6 == 0) {
          local_64 = (uint *)0x20;
          puVar17 = param_3;
          do {
            uVar6 = *puVar17;
            puVar17 = (uint *)((int)puVar17 + 1);
          } while ((char)uVar6 != '\0');
          FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)(local_6c + 2),(uint *)&local_64)
          ;
        }
        else {
          pcVar13 = "PresharedKey";
          pbVar5 = param_2;
          do {
            bVar19 = *pbVar5;
            bVar22 = bVar19 < (byte)*pcVar13;
            if (bVar19 != *pcVar13) {
LAB_00421081:
              uVar6 = -(uint)bVar22 | 1;
              goto LAB_00421086;
            }
            if (bVar19 == 0) break;
            bVar19 = pbVar5[1];
            bVar22 = bVar19 < (byte)pcVar13[1];
            if (bVar19 != pcVar13[1]) goto LAB_00421081;
            pbVar5 = pbVar5 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar19 != 0);
          uVar6 = 0;
LAB_00421086:
          if (uVar6 == 0) {
            local_64 = (uint *)0x20;
            puVar17 = param_3;
            do {
              uVar6 = *puVar17;
              puVar17 = (uint *)((int)puVar17 + 1);
            } while ((char)uVar6 != '\0');
            piVar16 = local_6c + 10;
            uVar7 = FUN_0040df40((byte *)param_3,(int)puVar17 - ((int)param_3 + 1),(undefined1 *)piVar16,
                                 (uint *)&local_64);
            if (((char)uVar7 != '\0') && (local_64 == (uint *)0x20)) {
              iVar9 = piVar10[0x12];
              if (piVar16 == (int *)0x0) {
                *(undefined4 *)(iVar9 + 0x160) = 0;
                *(undefined4 *)(iVar9 + 0x164) = 0;
                *(undefined4 *)(iVar9 + 0x168) = 0;
                *(undefined4 *)(iVar9 + 0x16c) = 0;
                *(undefined4 *)(iVar9 + 0x170) = 0;
                *(undefined4 *)(iVar9 + 0x174) = 0;
                *(undefined4 *)(iVar9 + 0x178) = 0;
                *(undefined4 *)(iVar9 + 0x17c) = 0;
              }
              else {
                iVar21 = piVar10[0xb];
                iVar2 = piVar10[0xc];
                iVar3 = piVar10[0xd];
                *(int *)(iVar9 + 0x160) = *piVar16;
                *(int *)(iVar9 + 0x164) = iVar21;
                *(int *)(iVar9 + 0x168) = iVar2;
                *(int *)(iVar9 + 0x16c) = iVar3;
                iVar21 = piVar10[0xf];
                iVar2 = piVar10[0x10];
                iVar3 = piVar10[0x11];
                *(int *)(iVar9 + 0x170) = piVar10[0xe];
                *(int *)(iVar9 + 0x174) = iVar21;
                *(int *)(iVar9 + 0x178) = iVar2;
                *(int *)(iVar9 + 0x17c) = iVar3;
              }
            }
          }
          else {
            pcVar13 = "AllowedIPs";
            pbVar5 = param_2;
            do {
              bVar19 = *pbVar5;
              bVar22 = bVar19 < (byte)*pcVar13;
              if (bVar19 != *pcVar13) {
LAB_00421128:
                uVar6 = -(uint)bVar22 | 1;
                goto LAB_0042112d;
              }
              if (bVar19 == 0) break;
              bVar19 = pbVar5[1];
              bVar22 = bVar19 < (byte)pcVar13[1];
              if (bVar19 != pcVar13[1]) goto LAB_00421128;
              pbVar5 = pbVar5 + 2;
              pcVar13 = pcVar13 + 2;
            } while (bVar19 != 0);
            uVar6 = 0;
LAB_0042112d:
            if (uVar6 == 0) {
              FUN_0040e1b0(param_3,&local_78);
              uVar6 = 0;
              local_68 = local_78;
              uVar8 = local_74 - (int)local_78 >> 2;
              if (uVar8 != 0) {
                do {
                  cVar4 = FUN_0040bde0(*(uint **)((int)local_68 + uVar6 * 4),(int)&local_5c);
                  if ((cVar4 == '\0') || (uVar7 = FUN_0042bd40((void *)local_6c[0x12],&local_5c), (char)uVar7 == '\0'))
                  break;
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uVar8);
              }
            }
            else {
              pcVar13 = "Endpoint";
              pbVar5 = param_2;
              do {
                bVar19 = *pbVar5;
                bVar22 = bVar19 < (byte)*pcVar13;
                if (bVar19 != *pcVar13) {
LAB_004211b3:
                  uVar6 = -(uint)bVar22 | 1;
                  goto LAB_004211b8;
                }
                if (bVar19 == 0) break;
                bVar19 = pbVar5[1];
                bVar22 = bVar19 < (byte)pcVar13[1];
                if (bVar19 != pcVar13[1]) goto LAB_004211b3;
                pbVar5 = pbVar5 + 2;
                pcVar13 = pcVar13 + 2;
              } while (bVar19 != 0);
              uVar6 = 0;
LAB_004211b8:
              if (uVar6 == 0) {
                uVar20 = 1;
                iVar9 = _strncmp((char *)param_3,"tcp://",6);
                piVar10 = local_6c;
                if (iVar9 == 0) {
                  param_3 = (uint *)((int)param_3 + 6);
                  uVar20 = 2;
                }
                cVar4 = FUN_0040c530((char *)param_3,&local_48,(void *)local_6c[0x13]);
                if (cVar4 != '\0') {
                  iVar9 = piVar10[0x12];
                  *(undefined1 *)(iVar9 + 0x3b) = uVar20;
                  *(undefined1 *)(iVar9 + 0x3c) = uVar20;
                  *(uint *)(iVar9 + 0x68) = local_48;
                  *(uint *)(iVar9 + 0x6c) = uStack_44;
                  *(uint *)(iVar9 + 0x70) = uStack_40;
                  *(uint *)(iVar9 + 0x74) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x78) = local_38;
                  *(uint *)(iVar9 + 0x80) = local_30;
                  *(uint *)(iVar9 + 0x84) = local_48;
                  *(uint *)(iVar9 + 0x88) = uStack_44;
                  *(uint *)(iVar9 + 0x8c) = uStack_40;
                  *(uint *)(iVar9 + 0x90) = uStack_3c;
                  *(undefined8 *)(iVar9 + 0x94) = local_38;
                  *(uint *)(iVar9 + 0x9c) = local_30;
                }
              }
              else {
                pcVar13 = "PersistentKeepalive";
                pbVar5 = param_2;
                do {
                  bVar19 = *pbVar5;
                  bVar22 = bVar19 < (byte)*pcVar13;
                  if (bVar19 != *pcVar13) {
LAB_00421270:
                    uVar6 = -(uint)bVar22 | 1;
                    goto LAB_00421275;
                  }
                  if (bVar19 == 0) break;
                  bVar19 = pbVar5[1];
                  bVar22 = bVar19 < (byte)pcVar13[1];
                  if (bVar19 != pcVar13[1]) goto LAB_00421270;
                  pbVar5 = pbVar5 + 2;
                  pcVar13 = pcVar13 + 2;
                } while (bVar19 != 0);
                uVar6 = 0;
LAB_00421275:
                if (uVar6 == 0) {
                  uVar6 = FID_conflict__atoi((char *)param_3);
                  if (uVar6 < 0x10000) {
                    *(uint *)(local_6c[0x12] + 0x218) = uVar6 * 1000;
                  }
                }
                else {
                  pcVar13 = "AllowMulticast";
                  pbVar5 = param_2;
                  do {
                    bVar19 = *pbVar5;
                    bVar22 = bVar19 < (byte)*pcVar13;
                    if (bVar19 != *pcVar13) {
LAB_004212d0:
                      uVar6 = -(uint)bVar22 | 1;
                      goto LAB_004212d5;
                    }
                    if (bVar19 == 0) break;
                    bVar19 = pbVar5[1];
                    bVar22 = bVar19 < (byte)pcVar13[1];
                    if (bVar19 != pcVar13[1]) goto LAB_004212d0;
                    pbVar5 = pbVar5 + 2;
                    pcVar13 = pcVar13 + 2;
                  } while (bVar19 != 0);
                  uVar6 = 0;
LAB_004212d5:
                  if (uVar6 == 0) {
                    uVar7 = FUN_004201d0((char *)param_3,&local_5d);
                    if ((char)uVar7 != '\0') {
                      *(byte *)(local_6c[0x12] + 0x37) = local_5d;
                    }
                  }
                  else {
                    pcVar13 = "Features";
                    pbVar5 = param_2;
                    do {
                      bVar19 = *pbVar5;
                      bVar22 = bVar19 < (byte)*pcVar13;
                      if (bVar19 != *pcVar13) {
LAB_00421325:
                        uVar6 = -(uint)bVar22 | 1;
                        goto LAB_0042132a;
                      }
                      if (bVar19 == 0) break;
                      bVar19 = pbVar5[1];
                      bVar22 = bVar19 < (byte)pcVar13[1];
                      if (bVar19 != pcVar13[1]) goto LAB_00421325;
                      pbVar5 = pbVar5 + 2;
                      pcVar13 = pcVar13 + 2;
                    } while (bVar19 != 0);
                    uVar6 = 0;
LAB_0042132a:
                    if (uVar6 == 0) {
                      FUN_0040e1b0(param_3,&local_78);
                      uVar8 = 0;
                      local_68 = local_78;
                      uVar6 = local_74 - (int)local_78 >> 2;
                      if (uVar6 != 0) {
                        do {
                          piVar10 = *(int **)((int)local_78 + uVar8 * 4);
                          piVar16 = piVar10;
                          do {
                            iVar9 = *piVar16;
                            piVar16 = (int *)((int)piVar16 + 1);
                          } while ((char)iVar9 != '\0');
                          iVar9 = (int)piVar16 - (int)((int)piVar10 + 1);
                          iVar21 = 2;
                          if (iVar9 != 0) {
                            cVar4 = *(char *)((int)piVar10 + iVar9 + -1);
                            if (cVar4 == '?') {
                              iVar21 = 1;
                            }
                            else {
                              if (cVar4 != '!') goto LAB_00421389;
                              iVar21 = 3;
                            }
                            iVar9 = iVar9 + -1;
                          }
LAB_00421389:
                          if ((((iVar9 != 10) || (*piVar10 != 0x72627968)) || (piVar10[1] != 0x745f6469)) ||
                             ((short)piVar10[2] != 0x7063)) break;
                          uVar8 = uVar8 + 1;
                          *(byte *)((iVar21 + 0x60U >> 4) + 0x3d + local_6c[0x12]) = (byte)(iVar21 + 0x60U) & 3;
                        } while (uVar8 < uVar6);
                      }
                    }
                    else {
                      pcVar13 = "Ciphers";
                      pbVar5 = param_2;
                      do {
                        bVar19 = *pbVar5;
                        bVar22 = bVar19 < (byte)*pcVar13;
                        if (bVar19 != *pcVar13) {
LAB_00421404:
                          uVar6 = -(uint)bVar22 | 1;
                          goto LAB_00421409;
                        }
                        if (bVar19 == 0) break;
                        bVar19 = pbVar5[1];
                        bVar22 = bVar19 < (byte)pcVar13[1];
                        if (bVar19 != pcVar13[1]) goto LAB_00421404;
                        pbVar5 = pbVar5 + 2;
                        pcVar13 = pcVar13 + 2;
                      } while (bVar19 != 0);
                      uVar6 = 0;
LAB_00421409:
                      if (uVar6 != 0) {
                        uVar20 = 1;
                        pcVar13 = "Ciphers!";
                        do {
                          bVar19 = *param_2;
                          bVar22 = bVar19 < (byte)*pcVar13;
                          if (bVar19 != *pcVar13) {
LAB_00421434:
                            uVar6 = -(uint)bVar22 | 1;
                            goto LAB_00421439;
                          }
                          if (bVar19 == 0) break;
                          bVar19 = param_2[1];
                          bVar22 = bVar19 < (byte)pcVar13[1];
                          if (bVar19 != pcVar13[1]) goto LAB_00421434;
                          param_2 = param_2 + 2;
                          pcVar13 = pcVar13 + 2;
                        } while (bVar19 != 0);
                        uVar6 = 0;
LAB_00421439:
                        if (uVar6 != 0) goto LAB_00420763;
                      }
                      FUN_0040e1b0(param_3,&local_78);
                      uVar6 = 0;
                      uVar8 = local_74 - (int)local_78 >> 2;
                      local_68 = local_78;
                      *(undefined1 *)(local_6c[0x12] + 0xa4) = uVar20;
                      if (uVar8 != 0) {
                        do {
                          pbVar5 = *(byte **)((int)local_78 + uVar6 * 4);
                          pcVar13 = "chacha20-poly1305";
                          pbVar14 = pbVar5;
                          do {
                            bVar19 = *pbVar14;
                            bVar22 = bVar19 < (byte)*pcVar13;
                            if (bVar19 != *pcVar13) {
LAB_004214a0:
                              uVar11 = -(uint)bVar22 | 1;
                              goto LAB_004214a5;
                            }
                            if (bVar19 == 0) break;
                            bVar19 = pbVar14[1];
                            bVar22 = bVar19 < (byte)pcVar13[1];
                            if (bVar19 != pcVar13[1]) goto LAB_004214a0;
                            pbVar14 = pbVar14 + 2;
                            pcVar13 = pcVar13 + 2;
                          } while (bVar19 != 0);
                          uVar11 = 0;
LAB_004214a5:
                          if (uVar11 == 0) {
                            cVar4 = '\0';
                          }
                          else {
                            pbVar15 = &DAT_0044a274;
                            pbVar14 = pbVar5;
                            do {
                              bVar19 = *pbVar14;
                              bVar22 = bVar19 < *pbVar15;
                              if (bVar19 != *pbVar15) {
LAB_004214d7:
                                uVar11 = -(uint)bVar22 | 1;
                                goto LAB_004214dc;
                              }
                              if (bVar19 == 0) break;
                              bVar19 = pbVar14[1];
                              bVar22 = bVar19 < pbVar15[1];
                              if (bVar19 != pbVar15[1]) goto LAB_004214d7;
                              pbVar14 = pbVar14 + 2;
                              pbVar15 = pbVar15 + 2;
                            } while (bVar19 != 0);
                            uVar11 = 0;
LAB_004214dc:
                            if (uVar11 == 0) {
                              cVar4 = '\x01';
                            }
                            else {
                              pbVar15 = &DAT_0044a280;
                              pbVar14 = pbVar5;
                              do {
                                bVar19 = *pbVar14;
                                bVar22 = bVar19 < *pbVar15;
                                if (bVar19 != *pbVar15) {
LAB_00421510:
                                  uVar11 = -(uint)bVar22 | 1;
                                  goto LAB_00421515;
                                }
                                if (bVar19 == 0) break;
                                bVar19 = pbVar14[1];
                                bVar22 = bVar19 < pbVar15[1];
                                if (bVar19 != pbVar15[1]) goto LAB_00421510;
                                pbVar14 = pbVar14 + 2;
                                pbVar15 = pbVar15 + 2;
                              } while (bVar19 != 0);
                              uVar11 = 0;
LAB_00421515:
                              if (uVar11 == 0) {
                                cVar4 = '\x02';
                              }
                              else {
                                pbVar14 = &DAT_0044a28c;
                                do {
                                  bVar19 = *pbVar5;
                                  bVar22 = bVar19 < *pbVar14;
                                  if (bVar19 != *pbVar14) {
LAB_00421543:
                                    uVar11 = -(uint)bVar22 | 1;
                                    goto LAB_00421548;
                                  }
                                  if (bVar19 == 0) break;
                                  bVar19 = pbVar5[1];
                                  bVar22 = bVar19 < pbVar14[1];
                                  if (bVar19 != pbVar14[1]) goto LAB_00421543;
                                  pbVar5 = pbVar5 + 2;
                                  pbVar14 = pbVar14 + 2;
                                } while (bVar19 != 0);
                                uVar11 = 0;
LAB_00421548:
                                if (uVar11 != 0) break;
                                cVar4 = '\x03';
                              }
                            }
                          }
                          iVar9 = local_6c[0x12];
                          if (*(byte *)(iVar9 + 0xa5) == 4) break;
                          if ((cVar4 != '\x01') && (cVar4 != '\x02')) {
                            *(char *)(*(byte *)(iVar9 + 0xa5) + 0xa6 + iVar9) = cVar4;
                            *(char *)(iVar9 + 0xa5) = *(char *)(iVar9 + 0xa5) + '\x01';
                          }
                          uVar6 = uVar6 + 1;
                        } while (uVar6 < uVar8);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00420763:
  if (local_68 != (void *)0x0) {
    pvVar18 = local_68;
    if ((0xfff < (local_70 - (int)local_68 & 0xfffffffcU)) &&
       (pvVar18 = *(void **)((int)local_68 + -4), 0x1f < (uint)((int)local_68 + (-4 - (int)pvVar18)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pvVar18);
  }
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- caller: FUN_004215c0 @ 004215c0

void __fastcall FUN_004215c0(int param_1,uint *param_2,int param_3,undefined4 param_4)

{
  uint *******pppppppuVar1;
  char cVar2;
  undefined1 *puVar3;
  uint *******pppppppuVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_EDI;
  uint *******pppppppuVar8;
  undefined1 auStack_c8 [11];
  undefined1 local_bd;
  int local_bc;
  undefined1 *local_b8;
  undefined1 *local_b4;
  uint *******local_b0 [4];
  undefined4 local_a0;
  uint local_9c;
  int local_98 [2];
  uint local_90 [16];
  void *local_50;
  undefined4 local_4c;
  undefined1 local_48;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_14;
  
  local_14 = DAT_0044f008 ^ (uint)auStack_c8;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  local_a0 = 0;
  local_9c = 0xf;
  local_b0[0] = (uint *******)((uint)local_b0[0] & 0xffffff00);
  puVar5 = param_2;
  do {
    uVar7 = *puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while ((char)uVar7 != '\0');
  local_bc = param_1;
  FUN_004096e0(local_b0,param_2,(int)puVar5 - ((int)param_2 + 1));
  pppppppuVar8 = (uint *******)local_b0;
  if (0xf < local_9c) {
    pppppppuVar8 = local_b0[0];
  }
  local_98[0] = local_bc;
  local_b4 = (undefined1 *)(param_3 + (int)pppppppuVar8);
  local_50 = (void *)0x0;
  local_4c = param_4;
  local_48 = 0;
  while( true ) {
    puVar3 = local_b4;
    local_b8 = _memchr(pppppppuVar8,10,(int)local_b4 - (int)pppppppuVar8);
    if (local_b8 != (undefined1 *)0x0) {
      *local_b8 = 0;
      puVar3 = local_b8;
    }
    uVar6 = 0;
    uVar7 = (int)puVar3 - (int)pppppppuVar8;
    if (uVar7 != 0) {
      do {
        if ((*(byte *)(uVar6 + (int)pppppppuVar8) < 0x20) &&
           ((1 << (*(byte *)(uVar6 + (int)pppppppuVar8) & 0x1f) & 0x2600U) == 0)) {
          FUN_0040e010("File is not a config file",(char)unaff_EDI);
          local_bd = 0;
          goto LAB_00421845;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
    }
    puVar3 = _memchr(pppppppuVar8,0x23,uVar7);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
      uVar7 = (int)puVar3 - (int)pppppppuVar8;
    }
    while ((uVar7 != 0 &&
           ((((cVar2 = *(char *)((uVar7 - 1) + (int)pppppppuVar8), cVar2 == ' ' || (cVar2 == '\r')) || (cVar2 == '\n'))
            || (cVar2 == '\t'))))) {
      uVar7 = uVar7 - 1;
      *(undefined1 *)(uVar7 + (int)pppppppuVar8) = 0;
    }
    if (*(char *)pppppppuVar8 == '[') {
      if (uVar7 < 0x20) {
        FUN_0042f280(&local_40,(uint *)pppppppuVar8,uVar7 + 1);
        cVar2 = FUN_00420280(local_98,(byte *)&local_40,(byte *)0x0,(uint *)0x0);
        if (cVar2 == '\0') {
          FUN_0040e010("Error parsing %s",(char)&local_40);
          local_bd = 0;
          goto LAB_00421845;
        }
      }
    }
    else if (*(char *)pppppppuVar8 != '\0') {
      pppppppuVar4 = (uint *******)FUN_0042dd80((uint *)pppppppuVar8,'=');
      pppppppuVar1 = pppppppuVar4;
      if (pppppppuVar4 == (uint *******)0x0) {
        FUN_0040e010("Missing = on line: %s",(char)pppppppuVar8);
        local_bd = 0;
        goto LAB_00421845;
      }
      for (; (pppppppuVar8 < pppppppuVar1 &&
             (((cVar2 = *(char *)((int)pppppppuVar1 + -1), cVar2 == ' ' || (cVar2 == '\r')) ||
              ((cVar2 == '\n' || (cVar2 == '\t')))))); pppppppuVar1 = (uint *******)((int)pppppppuVar1 + -1)) {
      }
      *(undefined1 *)pppppppuVar1 = 0;
      do {
        do {
          cVar2 = *(char *)((int)pppppppuVar4 + 1);
          pppppppuVar4 = (uint *******)((int)pppppppuVar4 + 1);
        } while (cVar2 == ' ');
      } while (((cVar2 == '\r') || (cVar2 == '\n')) || (cVar2 == '\t'));
      cVar2 = FUN_00420280(local_98,(byte *)&local_40,(byte *)pppppppuVar8,(uint *)pppppppuVar4);
      if (cVar2 == '\0') {
        FUN_0040e010("Error parsing %s.%s = %s",(char)&local_40);
        local_bd = 0;
        goto LAB_00421845;
      }
    }
    if (local_b8 == (undefined1 *)0x0) break;
    pppppppuVar8 = (uint *******)(local_b8 + 1);
  }
  if (local_50 != (void *)0x0) {
    FUN_00429d00(local_50,local_90);
    local_50 = (void *)0x0;
  }
  if ((*(int **)(local_bc + 0x38) == (int *)0x0) ||
     (cVar2 = (**(code **)(**(int **)(local_bc + 0x38) + 0x10))(), cVar2 != '\0')) {
    local_bd = 1;
  }
  else {
    local_bd = 0;
  }
LAB_00421845:
  if (0xf < local_9c) {
    pppppppuVar8 = local_b0[0];
    if ((0xfff < local_9c + 1) &&
       (pppppppuVar8 = (uint *******)local_b0[0][-1], 0x1f < (uint)((int)local_b0[0] + (-4 - (int)pppppppuVar8)))) {
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pppppppuVar8);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_c8);
  return;
}


// ----- callee: WS2_32.DLL::inet_pton @ EXTERNAL:00000119
// decompile failed: Exception while decompiling EXTERNAL:00000119: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_004181c0 @ 004181c0

uint * __thiscall FUN_004181c0(void *this,uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  uint *puVar10;
  uint uVar11;
  
  iVar2 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar2) / 0x1c;
  if (iVar5 != 0x9249249) {
    uVar11 = iVar5 + 1;
    uVar8 = (*(int *)((int)this + 8) - iVar2) / 0x1c;
    if (0x9249249 - (uVar8 >> 1) < uVar8) {
      uVar8 = uVar11;
    }
    else {
      uVar8 = (uVar8 >> 1) + uVar8;
      if (uVar8 < uVar11) {
        uVar8 = uVar11;
      }
    }
    if (uVar8 < 0x924924a) {
      uVar11 = uVar8 * 0x1c;
      if (uVar11 < 0x1000) {
        if (uVar11 == 0) {
          puVar10 = (uint *)0x0;
        }
        else {
          puVar10 = (uint *)FUN_0042cfbe(uVar11);
        }
      }
      else {
        if (uVar11 + 0x23 <= uVar11) goto LAB_00418384;
        uVar11 = FUN_0042cfbe(uVar11 + 0x23);
        if (uVar11 == 0) goto LAB_0041838e;
        puVar10 = (uint *)(uVar11 + 0x23 & 0xffffffe0);
        puVar10[-1] = uVar11;
      }
      puVar1 = puVar10 + (((int)param_1 - iVar2) / 0x1c) * 7;
      uVar11 = param_2[1];
      uVar6 = param_2[2];
      uVar7 = param_2[3];
      *puVar1 = *param_2;
      puVar1[1] = uVar11;
      puVar1[2] = uVar6;
      puVar1[3] = uVar7;
      *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_2 + 4);
      puVar1[6] = param_2[6];
      puVar3 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar10,puVar3,(int)*(uint **)((int)this + 4) - (int)puVar3);
      }
      else {
        FUN_0042e660(puVar10,puVar3,(int)param_1 - (int)puVar3);
        FUN_0042e660(puVar1 + 7,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_0041835a:
        *(uint **)this = puVar10;
        *(uint **)((int)this + 4) = puVar10 + (iVar5 + 1) * 7;
        *(uint **)((int)this + 8) = puVar10 + uVar8 * 7;
        return puVar1;
      }
      pvVar9 = pvVar4;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar4) / 0x1c) * 0x1c) < 0x1000) ||
         (pvVar9 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar9)) < 0x20)) {
        FUN_0042cf8d(pvVar9);
        goto LAB_0041835a;
      }
      goto LAB_0041838e;
    }
LAB_00418384:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_0041838e:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- callee: FUN_0042fb66 @ 0042fb66

void FUN_0042fb66(void)

{
  FUN_0042faf2((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}


// ----- callee: FUN_0040e0a0 @ 0040e0a0

void __cdecl FUN_0040e0a0(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(0,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_0040df40 @ 0040df40

undefined4 __fastcall FUN_0040df40(byte *param_1,int param_2,undefined1 *param_3,uint *param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined3 uVar5;
  uint uVar4;
  uint uVar6;
  char cVar7;
  uint uVar8;
  
  cVar7 = '\0';
  uVar3 = 0;
  uVar8 = 0;
  pbVar1 = param_1 + param_2;
  uVar5 = (undefined3)((uint)param_4 >> 8);
  if (param_1 < pbVar1) {
    do {
      bVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar6 = (uint)(byte)"BBBBBBBBBB@BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB>BBB?456789:;<=BBBABBB"[bVar2];
      if (uVar6 != 0x40) {
        if (uVar6 == 0x41) break;
        if (uVar6 == 0x42) goto LAB_0040dfed;
        uVar4 = uVar3 << 6;
        cVar7 = cVar7 + '\x01';
        uVar3 = uVar4 | uVar6;
        if (cVar7 == '\x04') {
          uVar8 = uVar8 + 3;
          if (*param_4 < uVar8) goto LAB_0040dfed;
          *param_3 = (char)(uVar4 >> 0x10);
          param_3[2] = (char)uVar3;
          uVar3 = 0;
          param_3[1] = (char)(uVar4 >> 8);
          param_3 = param_3 + 3;
          cVar7 = '\0';
        }
      }
    } while (param_1 < pbVar1);
    if (cVar7 == '\x03') {
      if (uVar8 + 2 <= *param_4) {
        *param_3 = (char)(uVar3 >> 10);
        param_3[1] = (char)(uVar3 >> 2);
        *param_4 = uVar8 + 2;
        return CONCAT31(uVar5,1);
      }
LAB_0040dfed:
      return uVar3 & 0xffffff00;
    }
    if (cVar7 == '\x02') {
      uVar8 = uVar8 + 1;
      if (*param_4 < uVar8) goto LAB_0040dfed;
      *param_3 = (char)(uVar3 >> 4);
    }
  }
  *param_4 = uVar8;
  return CONCAT31(uVar5,1);
}


// ----- callee: FUN_004186e0 @ 004186e0

void __fastcall FUN_004186e0(uint *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  
  iVar5 = *param_2;
  iVar6 = param_2[1];
  iVar7 = param_2[2];
  iVar8 = param_2[3];
  iVar9 = param_2[4];
  iVar10 = param_2[5];
  iVar11 = param_2[6];
  iVar12 = param_2[7];
  iVar13 = param_2[8];
  iVar14 = param_2[9];
  iVar15 = param_2[10];
  iVar16 = param_2[0xb];
  uVar1 = param_1[4];
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  iVar17 = param_2[0xc];
  iVar18 = param_2[0xd];
  iVar19 = param_2[0xe];
  iVar20 = param_2[0xf];
  uVar21 = iVar5 + *param_1 + uVar1;
  uVar35 = param_1[8] ^ uVar21 ^ 0x510e527f;
  uVar36 = uVar35 >> 0x10 | uVar35 << 0x10;
  uVar35 = uVar36 + 0x6a09e667;
  uVar27 = uVar35 ^ uVar1;
  uVar27 = uVar27 >> 0xc | uVar27 << 0x14;
  uVar22 = uVar21 + uVar27 + iVar6;
  uVar36 = uVar22 ^ uVar36;
  uVar23 = uVar36 >> 8 | uVar36 << 0x18;
  uVar35 = uVar23 + uVar35;
  uVar27 = uVar35 ^ uVar27;
  uVar24 = uVar27 >> 7 | uVar27 << 0x19;
  uVar36 = param_1[1] + uVar2 + iVar7;
  uVar21 = param_1[9] ^ uVar36 ^ 0x9b05688c;
  uVar27 = uVar21 >> 0x10 | uVar21 << 0x10;
  uVar21 = uVar27 + 0xbb67ae85;
  uVar28 = uVar21 ^ uVar2;
  uVar29 = uVar28 >> 0xc | uVar28 << 0x14;
  uVar28 = uVar36 + uVar29 + iVar8;
  uVar27 = uVar28 ^ uVar27;
  uVar25 = uVar27 >> 8 | uVar27 << 0x18;
  uVar21 = uVar25 + uVar21;
  uVar29 = uVar21 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar27 = param_1[2] + uVar3 + iVar9;
  uVar36 = param_1[10] ^ uVar27 ^ 0x1f83d9ab;
  uVar37 = uVar36 >> 0x10 | uVar36 << 0x10;
  uVar36 = uVar37 + 0x3c6ef372;
  uVar30 = uVar36 ^ uVar3;
  uVar31 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar30 = uVar27 + uVar31 + iVar10;
  uVar37 = uVar30 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar36 = uVar37 + uVar36;
  uVar31 = uVar36 ^ uVar31;
  uVar31 = uVar31 >> 7 | uVar31 << 0x19;
  uVar26 = param_1[3] + uVar4 + iVar11;
  uVar27 = param_1[0xb] ^ uVar26 ^ 0x5be0cd19;
  uVar39 = uVar27 >> 0x10 | uVar27 << 0x10;
  uVar27 = uVar39 + 0xa54ff53a;
  uVar38 = uVar27 ^ uVar4;
  uVar38 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar26 = uVar26 + uVar38 + iVar12;
  uVar39 = uVar26 ^ uVar39;
  uVar39 = uVar39 >> 8 | uVar39 << 0x18;
  uVar27 = uVar39 + uVar27;
  uVar38 = uVar27 ^ uVar38;
  uVar38 = uVar38 >> 7 | uVar38 << 0x19;
  uVar22 = uVar29 + uVar22 + iVar13;
  uVar39 = uVar22 ^ uVar39;
  uVar39 = uVar39 >> 0x10 | uVar39 << 0x10;
  uVar36 = uVar39 + uVar36;
  uVar29 = uVar36 ^ uVar29;
  uVar32 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar22 = uVar22 + uVar32 + iVar14;
  uVar39 = uVar22 ^ uVar39;
  uVar29 = uVar39 >> 8 | uVar39 << 0x18;
  uVar36 = uVar29 + uVar36;
  uVar32 = uVar36 ^ uVar32;
  uVar39 = uVar32 >> 7 | uVar32 << 0x19;
  uVar28 = uVar28 + uVar31 + iVar15;
  uVar23 = uVar28 ^ uVar23;
  uVar33 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar27 = uVar33 + uVar27;
  uVar31 = uVar31 ^ uVar27;
  uVar23 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar32 = uVar28 + iVar16 + uVar23;
  uVar33 = uVar33 ^ uVar32;
  uVar34 = uVar33 >> 8 | uVar33 << 0x18;
  uVar27 = uVar34 + uVar27;
  uVar23 = uVar27 ^ uVar23;
  uVar23 = uVar23 >> 7 | uVar23 << 0x19;
  uVar28 = iVar17 + uVar30 + uVar38;
  uVar25 = uVar25 ^ uVar28;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar35 = uVar35 + uVar25;
  uVar38 = uVar38 ^ uVar35;
  uVar30 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar28 = iVar18 + uVar30 + uVar28;
  uVar25 = uVar28 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar35 = uVar25 + uVar35;
  uVar30 = uVar35 ^ uVar30;
  uVar30 = uVar30 >> 7 | uVar30 << 0x19;
  uVar31 = iVar19 + uVar26 + uVar24;
  uVar37 = uVar37 ^ uVar31;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar21 = uVar21 + uVar37;
  uVar24 = uVar24 ^ uVar21;
  uVar26 = uVar24 >> 0xc | uVar24 << 0x14;
  uVar31 = iVar20 + uVar26 + uVar31;
  uVar37 = uVar31 ^ uVar37;
  uVar24 = uVar37 >> 8 | uVar37 << 0x18;
  uVar21 = uVar24 + uVar21;
  uVar26 = uVar21 ^ uVar26;
  uVar37 = uVar26 >> 7 | uVar26 << 0x19;
  uVar33 = iVar19 + uVar22 + uVar37;
  uVar34 = uVar33 ^ uVar34;
  uVar22 = uVar34 >> 0x10 | uVar34 << 0x10;
  uVar35 = uVar22 + uVar35;
  uVar37 = uVar35 ^ uVar37;
  uVar37 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar33 = iVar15 + uVar37 + uVar33;
  uVar22 = uVar33 ^ uVar22;
  uVar22 = uVar22 >> 8 | uVar22 << 0x18;
  uVar35 = uVar22 + uVar35;
  uVar37 = uVar35 ^ uVar37;
  uVar37 = uVar37 >> 7 | uVar37 << 0x19;
  uVar32 = uVar32 + iVar9 + uVar39;
  uVar25 = uVar32 ^ uVar25;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar21 = uVar21 + uVar25;
  uVar39 = uVar39 ^ uVar21;
  uVar26 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar32 = iVar13 + uVar26 + uVar32;
  uVar39 = uVar28 + iVar14 + uVar23;
  uVar25 = uVar32 ^ uVar25;
  uVar28 = uVar25 >> 8 | uVar25 << 0x18;
  uVar24 = uVar39 ^ uVar24;
  uVar21 = uVar28 + uVar21;
  uVar26 = uVar21 ^ uVar26;
  uVar25 = uVar26 >> 7 | uVar26 << 0x19;
  uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar36 = uVar36 + uVar24;
  uVar23 = uVar36 ^ uVar23;
  uVar26 = uVar23 >> 0xc | uVar23 << 0x14;
  uVar39 = iVar20 + uVar26 + uVar39;
  uVar24 = uVar39 ^ uVar24;
  uVar23 = uVar24 >> 8 | uVar24 << 0x18;
  uVar36 = uVar23 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar24 = uVar26 >> 7 | uVar26 << 0x19;
  uVar31 = iVar18 + uVar31 + uVar30;
  uVar29 = uVar29 ^ uVar31;
  uVar26 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar27 = uVar26 + uVar27;
  uVar30 = uVar27 ^ uVar30;
  uVar29 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar31 = iVar11 + uVar29 + uVar31;
  uVar26 = uVar31 ^ uVar26;
  uVar30 = uVar26 >> 8 | uVar26 << 0x18;
  uVar27 = uVar30 + uVar27;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar33 = uVar33 + uVar25 + iVar6;
  uVar30 = uVar33 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar36 = uVar30 + uVar36;
  uVar25 = uVar36 ^ uVar25;
  uVar26 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar33 = iVar17 + uVar26 + uVar33;
  uVar30 = uVar33 ^ uVar30;
  uVar25 = uVar30 >> 8 | uVar30 << 0x18;
  uVar36 = uVar25 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar30 = uVar26 >> 7 | uVar26 << 0x19;
  uVar32 = iVar5 + uVar24 + uVar32;
  uVar22 = uVar32 ^ uVar22;
  uVar26 = uVar22 >> 0x10 | uVar22 << 0x10;
  uVar27 = uVar27 + uVar26;
  uVar24 = uVar27 ^ uVar24;
  uVar38 = uVar24 >> 0xc | uVar24 << 0x14;
  uVar22 = uVar32 + uVar38 + iVar7;
  uVar26 = uVar22 ^ uVar26;
  uVar24 = uVar26 >> 8 | uVar26 << 0x18;
  uVar27 = uVar24 + uVar27;
  uVar38 = uVar27 ^ uVar38;
  uVar26 = uVar38 >> 7 | uVar38 << 0x19;
  uVar39 = iVar16 + uVar29 + uVar39;
  uVar28 = uVar39 ^ uVar28;
  uVar38 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar35 = uVar35 + uVar38;
  uVar29 = uVar35 ^ uVar29;
  uVar32 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar28 = uVar39 + uVar32 + iVar12;
  uVar38 = uVar28 ^ uVar38;
  uVar29 = uVar38 >> 8 | uVar38 << 0x18;
  uVar35 = uVar29 + uVar35;
  uVar32 = uVar35 ^ uVar32;
  uVar38 = uVar32 >> 7 | uVar32 << 0x19;
  uVar31 = uVar31 + iVar10 + uVar37;
  uVar23 = uVar31 ^ uVar23;
  uVar39 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar21 = uVar21 + uVar39;
  uVar37 = uVar21 ^ uVar37;
  uVar32 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar23 = uVar31 + uVar32 + iVar8;
  uVar39 = uVar23 ^ uVar39;
  uVar37 = uVar39 >> 8 | uVar39 << 0x18;
  uVar21 = uVar37 + uVar21;
  uVar32 = uVar21 ^ uVar32;
  uVar39 = uVar32 >> 7 | uVar32 << 0x19;
  uVar33 = iVar16 + uVar39 + uVar33;
  uVar24 = uVar33 ^ uVar24;
  uVar31 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar35 = uVar31 + uVar35;
  uVar39 = uVar35 ^ uVar39;
  uVar39 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar24 = uVar33 + uVar39 + iVar13;
  uVar31 = uVar24 ^ uVar31;
  uVar31 = uVar31 >> 8 | uVar31 << 0x18;
  uVar35 = uVar31 + uVar35;
  uVar39 = uVar35 ^ uVar39;
  uVar39 = uVar39 >> 7 | uVar39 << 0x19;
  uVar22 = uVar22 + uVar30 + iVar17;
  uVar29 = uVar22 ^ uVar29;
  uVar29 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar21 = uVar29 + uVar21;
  uVar30 = uVar21 ^ uVar30;
  uVar30 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar22 = uVar22 + uVar30 + iVar5;
  uVar29 = uVar22 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar21 = uVar29 + uVar21;
  uVar30 = uVar21 ^ uVar30;
  uVar30 = uVar30 >> 7 | uVar30 << 0x19;
  uVar28 = uVar28 + uVar26 + iVar10;
  uVar37 = uVar28 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar36 = uVar36 + uVar37;
  uVar26 = uVar36 ^ uVar26;
  uVar26 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar28 = uVar28 + uVar26 + iVar7;
  uVar37 = uVar28 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar36 = uVar37 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar26 = uVar26 >> 7 | uVar26 << 0x19;
  uVar23 = uVar23 + uVar38 + iVar20;
  uVar25 = uVar23 ^ uVar25;
  uVar32 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar27 = uVar27 + uVar32;
  uVar38 = uVar27 ^ uVar38;
  uVar25 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar23 = uVar23 + uVar25 + iVar18;
  uVar32 = uVar23 ^ uVar32;
  uVar38 = uVar32 >> 8 | uVar32 << 0x18;
  uVar27 = uVar38 + uVar27;
  uVar25 = uVar27 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar24 = uVar30 + uVar24 + iVar15;
  uVar38 = uVar24 ^ uVar38;
  uVar38 = uVar38 >> 0x10 | uVar38 << 0x10;
  uVar36 = uVar38 + uVar36;
  uVar30 = uVar36 ^ uVar30;
  uVar32 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar24 = uVar24 + uVar32 + iVar19;
  uVar38 = uVar24 ^ uVar38;
  uVar30 = uVar38 >> 8 | uVar38 << 0x18;
  uVar36 = uVar30 + uVar36;
  uVar32 = uVar36 ^ uVar32;
  uVar38 = uVar32 >> 7 | uVar32 << 0x19;
  uVar22 = uVar22 + uVar26 + iVar8;
  uVar31 = uVar22 ^ uVar31;
  uVar31 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar27 = uVar27 + uVar31;
  uVar26 = uVar27 ^ uVar26;
  uVar26 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar22 = uVar22 + uVar26 + iVar11;
  uVar31 = uVar22 ^ uVar31;
  uVar32 = uVar31 >> 8 | uVar31 << 0x18;
  uVar27 = uVar32 + uVar27;
  uVar26 = uVar27 ^ uVar26;
  uVar31 = uVar26 >> 7 | uVar26 << 0x19;
  uVar28 = uVar28 + uVar25 + iVar12;
  uVar29 = uVar28 ^ uVar29;
  uVar29 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar35 = uVar35 + uVar29;
  uVar25 = uVar25 ^ uVar35;
  uVar25 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar33 = uVar28 + iVar6 + uVar25;
  uVar29 = uVar33 ^ uVar29;
  uVar28 = uVar29 >> 8 | uVar29 << 0x18;
  uVar35 = uVar28 + uVar35;
  uVar25 = uVar35 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar23 = iVar14 + uVar23 + uVar39;
  uVar37 = uVar37 ^ uVar23;
  uVar29 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar21 = uVar21 + uVar29;
  uVar39 = uVar39 ^ uVar21;
  uVar37 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar23 = iVar9 + uVar37 + uVar23;
  uVar29 = uVar23 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar21 = uVar29 + uVar21;
  uVar37 = uVar21 ^ uVar37;
  uVar37 = uVar37 >> 7 | uVar37 << 0x19;
  uVar34 = iVar12 + uVar24 + uVar37;
  uVar32 = uVar32 ^ uVar34;
  uVar24 = uVar32 >> 0x10 | uVar32 << 0x10;
  uVar35 = uVar24 + uVar35;
  uVar37 = uVar35 ^ uVar37;
  uVar37 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar34 = iVar14 + uVar37 + uVar34;
  uVar24 = uVar34 ^ uVar24;
  uVar24 = uVar24 >> 8 | uVar24 << 0x18;
  uVar35 = uVar24 + uVar35;
  uVar37 = uVar35 ^ uVar37;
  uVar37 = uVar37 >> 7 | uVar37 << 0x19;
  uVar39 = iVar8 + uVar22 + uVar38;
  uVar28 = uVar39 ^ uVar28;
  uVar22 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar21 = uVar22 + uVar21;
  uVar38 = uVar38 ^ uVar21;
  uVar28 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar39 = iVar6 + uVar28 + uVar39;
  uVar22 = uVar39 ^ uVar22;
  uVar22 = uVar22 >> 8 | uVar22 << 0x18;
  uVar21 = uVar22 + uVar21;
  uVar28 = uVar21 ^ uVar28;
  uVar28 = uVar28 >> 7 | uVar28 << 0x19;
  uVar33 = uVar33 + iVar18 + uVar31;
  uVar29 = uVar33 ^ uVar29;
  uVar29 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar36 = uVar36 + uVar29;
  uVar31 = uVar31 ^ uVar36;
  uVar31 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar33 = iVar17 + uVar31 + uVar33;
  uVar26 = iVar16 + uVar23 + uVar25;
  uVar29 = uVar33 ^ uVar29;
  uVar23 = uVar29 >> 8 | uVar29 << 0x18;
  uVar36 = uVar23 + uVar36;
  uVar30 = uVar30 ^ uVar26;
  uVar31 = uVar36 ^ uVar31;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar29 = uVar31 >> 7 | uVar31 << 0x19;
  uVar27 = uVar30 + uVar27;
  uVar25 = uVar27 ^ uVar25;
  uVar25 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar26 = iVar19 + uVar25 + uVar26;
  uVar30 = uVar26 ^ uVar30;
  uVar30 = uVar30 >> 8 | uVar30 << 0x18;
  uVar27 = uVar30 + uVar27;
  uVar25 = uVar27 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar34 = uVar34 + uVar28 + iVar7;
  uVar30 = uVar34 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar36 = uVar30 + uVar36;
  uVar28 = uVar36 ^ uVar28;
  uVar31 = uVar28 >> 0xc | uVar28 << 0x14;
  uVar34 = iVar11 + uVar31 + uVar34;
  uVar30 = uVar34 ^ uVar30;
  uVar28 = uVar30 >> 8 | uVar30 << 0x18;
  uVar36 = uVar28 + uVar36;
  uVar31 = uVar36 ^ uVar31;
  uVar30 = uVar31 >> 7 | uVar31 << 0x19;
  uVar39 = uVar39 + iVar10 + uVar29;
  uVar24 = uVar39 ^ uVar24;
  uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar27 = uVar27 + uVar24;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar39 = iVar15 + uVar29 + uVar39;
  uVar24 = uVar39 ^ uVar24;
  uVar24 = uVar24 >> 8 | uVar24 << 0x18;
  uVar27 = uVar24 + uVar27;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar33 = iVar9 + uVar25 + uVar33;
  uVar22 = uVar33 ^ uVar22;
  uVar31 = uVar22 >> 0x10 | uVar22 << 0x10;
  uVar35 = uVar35 + uVar31;
  uVar25 = uVar35 ^ uVar25;
  uVar38 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar22 = uVar33 + uVar38 + iVar5;
  uVar31 = uVar22 ^ uVar31;
  uVar25 = uVar31 >> 8 | uVar31 << 0x18;
  uVar35 = uVar25 + uVar35;
  uVar38 = uVar35 ^ uVar38;
  uVar31 = uVar38 >> 7 | uVar38 << 0x19;
  uVar26 = uVar26 + iVar20 + uVar37;
  uVar23 = uVar26 ^ uVar23;
  uVar38 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar21 = uVar21 + uVar38;
  uVar37 = uVar21 ^ uVar37;
  uVar32 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar23 = uVar26 + uVar32 + iVar13;
  uVar38 = uVar23 ^ uVar38;
  uVar37 = uVar38 >> 8 | uVar38 << 0x18;
  uVar21 = uVar37 + uVar21;
  uVar32 = uVar21 ^ uVar32;
  uVar38 = uVar32 >> 7 | uVar32 << 0x19;
  uVar34 = iVar14 + uVar38 + uVar34;
  uVar24 = uVar34 ^ uVar24;
  uVar26 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar35 = uVar26 + uVar35;
  uVar38 = uVar35 ^ uVar38;
  uVar38 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar24 = uVar34 + uVar38 + iVar5;
  uVar26 = uVar24 ^ uVar26;
  uVar26 = uVar26 >> 8 | uVar26 << 0x18;
  uVar35 = uVar26 + uVar35;
  uVar38 = uVar35 ^ uVar38;
  uVar38 = uVar38 >> 7 | uVar38 << 0x19;
  uVar39 = uVar39 + iVar10 + uVar30;
  uVar25 = uVar39 ^ uVar25;
  uVar32 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar21 = uVar32 + uVar21;
  uVar30 = uVar21 ^ uVar30;
  uVar33 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar25 = uVar39 + uVar33 + iVar12;
  uVar32 = uVar25 ^ uVar32;
  uVar30 = uVar32 >> 8 | uVar32 << 0x18;
  uVar21 = uVar30 + uVar21;
  uVar33 = uVar21 ^ uVar33;
  uVar39 = uVar33 >> 7 | uVar33 << 0x19;
  uVar22 = uVar22 + uVar29 + iVar7;
  uVar37 = uVar22 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar36 = uVar36 + uVar37;
  uVar29 = uVar36 ^ uVar29;
  uVar32 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar22 = uVar22 + uVar32 + iVar9;
  uVar37 = uVar22 ^ uVar37;
  uVar29 = uVar37 >> 8 | uVar37 << 0x18;
  uVar36 = uVar29 + uVar36;
  uVar32 = uVar36 ^ uVar32;
  uVar37 = uVar32 >> 7 | uVar32 << 0x19;
  uVar23 = uVar23 + uVar31 + iVar15;
  uVar28 = uVar23 ^ uVar28;
  uVar32 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar27 = uVar27 + uVar32;
  uVar31 = uVar27 ^ uVar31;
  uVar28 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar23 = uVar23 + uVar28 + iVar20;
  uVar32 = uVar23 ^ uVar32;
  uVar31 = uVar32 >> 8 | uVar32 << 0x18;
  uVar27 = uVar31 + uVar27;
  uVar28 = uVar27 ^ uVar28;
  uVar28 = uVar28 >> 7 | uVar28 << 0x19;
  uVar24 = uVar39 + uVar24 + iVar19;
  uVar31 = uVar24 ^ uVar31;
  uVar31 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar36 = uVar31 + uVar36;
  uVar39 = uVar36 ^ uVar39;
  uVar39 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar24 = uVar24 + uVar39 + iVar6;
  uVar31 = uVar24 ^ uVar31;
  uVar31 = uVar31 >> 8 | uVar31 << 0x18;
  uVar36 = uVar31 + uVar36;
  uVar39 = uVar36 ^ uVar39;
  uVar39 = uVar39 >> 7 | uVar39 << 0x19;
  uVar25 = uVar25 + uVar37 + iVar16;
  uVar26 = uVar25 ^ uVar26;
  uVar26 = uVar26 >> 0x10 | uVar26 << 0x10;
  uVar27 = uVar27 + uVar26;
  uVar37 = uVar27 ^ uVar37;
  uVar37 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar25 = uVar25 + uVar37 + iVar17;
  uVar26 = uVar25 ^ uVar26;
  uVar32 = uVar26 >> 8 | uVar26 << 0x18;
  uVar27 = uVar32 + uVar27;
  uVar37 = uVar27 ^ uVar37;
  uVar37 = uVar37 >> 7 | uVar37 << 0x19;
  uVar22 = uVar22 + uVar28 + iVar11;
  uVar30 = uVar22 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar35 = uVar35 + uVar30;
  uVar28 = uVar35 ^ uVar28;
  uVar26 = uVar28 >> 0xc | uVar28 << 0x14;
  uVar22 = uVar22 + uVar26 + iVar13;
  uVar30 = uVar22 ^ uVar30;
  uVar28 = uVar30 >> 8 | uVar30 << 0x18;
  uVar35 = uVar28 + uVar35;
  uVar26 = uVar35 ^ uVar26;
  uVar30 = uVar26 >> 7 | uVar26 << 0x19;
  uVar23 = uVar23 + uVar38 + iVar8;
  uVar29 = uVar23 ^ uVar29;
  uVar26 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar21 = uVar21 + uVar26;
  uVar38 = uVar38 ^ uVar21;
  uVar38 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar29 = uVar23 + iVar18 + uVar38;
  uVar26 = uVar26 ^ uVar29;
  uVar34 = uVar26 >> 8 | uVar26 << 0x18;
  uVar21 = uVar34 + uVar21;
  uVar38 = uVar21 ^ uVar38;
  uVar26 = uVar38 >> 7 | uVar38 << 0x19;
  uVar33 = iVar7 + uVar24 + uVar26;
  uVar32 = uVar32 ^ uVar33;
  uVar23 = uVar32 >> 0x10 | uVar32 << 0x10;
  uVar35 = uVar35 + uVar23;
  uVar26 = uVar35 ^ uVar26;
  uVar24 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar33 = iVar17 + uVar24 + uVar33;
  uVar23 = uVar33 ^ uVar23;
  uVar23 = uVar23 >> 8 | uVar23 << 0x18;
  uVar35 = uVar23 + uVar35;
  uVar24 = uVar35 ^ uVar24;
  uVar24 = uVar24 >> 7 | uVar24 << 0x19;
  uVar26 = iVar11 + uVar25 + uVar39;
  uVar28 = uVar28 ^ uVar26;
  uVar28 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar21 = uVar28 + uVar21;
  uVar39 = uVar39 ^ uVar21;
  uVar25 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar26 = iVar15 + uVar25 + uVar26;
  uVar28 = uVar26 ^ uVar28;
  uVar28 = uVar28 >> 8 | uVar28 << 0x18;
  uVar21 = uVar28 + uVar21;
  uVar25 = uVar21 ^ uVar25;
  uVar39 = uVar25 >> 7 | uVar25 << 0x19;
  uVar38 = iVar5 + uVar22 + uVar37;
  uVar34 = uVar38 ^ uVar34;
  uVar22 = uVar34 >> 0x10 | uVar34 << 0x10;
  uVar36 = uVar36 + uVar22;
  uVar37 = uVar37 ^ uVar36;
  uVar25 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar38 = iVar16 + uVar25 + uVar38;
  uVar22 = uVar38 ^ uVar22;
  uVar22 = uVar22 >> 8 | uVar22 << 0x18;
  uVar36 = uVar22 + uVar36;
  uVar25 = uVar36 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar29 = uVar29 + iVar13 + uVar30;
  uVar31 = uVar31 ^ uVar29;
  uVar37 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar27 = uVar37 + uVar27;
  uVar30 = uVar30 ^ uVar27;
  uVar30 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar29 = iVar8 + uVar30 + uVar29;
  uVar37 = uVar29 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar27 = uVar37 + uVar27;
  uVar30 = uVar27 ^ uVar30;
  uVar30 = uVar30 >> 7 | uVar30 << 0x19;
  uVar33 = uVar33 + iVar9 + uVar39;
  uVar37 = uVar33 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar36 = uVar37 + uVar36;
  uVar39 = uVar36 ^ uVar39;
  uVar31 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar33 = iVar18 + uVar31 + uVar33;
  uVar37 = uVar33 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar36 = uVar37 + uVar36;
  uVar31 = uVar36 ^ uVar31;
  uVar31 = uVar31 >> 7 | uVar31 << 0x19;
  uVar26 = uVar26 + iVar12 + uVar25;
  uVar23 = uVar26 ^ uVar23;
  uVar23 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar27 = uVar27 + uVar23;
  uVar25 = uVar27 ^ uVar25;
  uVar25 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar26 = iVar10 + uVar25 + uVar26;
  uVar23 = uVar26 ^ uVar23;
  uVar23 = uVar23 >> 8 | uVar23 << 0x18;
  uVar27 = uVar23 + uVar27;
  uVar25 = uVar27 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar38 = uVar38 + iVar20 + uVar30;
  uVar28 = uVar38 ^ uVar28;
  uVar28 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar35 = uVar35 + uVar28;
  uVar30 = uVar35 ^ uVar30;
  uVar30 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar38 = iVar19 + uVar30 + uVar38;
  uVar28 = uVar38 ^ uVar28;
  uVar28 = uVar28 >> 8 | uVar28 << 0x18;
  uVar35 = uVar28 + uVar35;
  uVar30 = uVar35 ^ uVar30;
  uVar30 = uVar30 >> 7 | uVar30 << 0x19;
  uVar29 = uVar29 + iVar6 + uVar24;
  uVar22 = uVar29 ^ uVar22;
  uVar39 = uVar22 >> 0x10 | uVar22 << 0x10;
  uVar21 = uVar21 + uVar39;
  uVar24 = uVar21 ^ uVar24;
  uVar32 = uVar24 >> 0xc | uVar24 << 0x14;
  uVar22 = uVar29 + uVar32 + iVar14;
  uVar39 = uVar22 ^ uVar39;
  uVar24 = uVar39 >> 8 | uVar39 << 0x18;
  uVar21 = uVar24 + uVar21;
  uVar32 = uVar21 ^ uVar32;
  uVar39 = uVar32 >> 7 | uVar32 << 0x19;
  uVar33 = iVar17 + uVar39 + uVar33;
  uVar23 = uVar33 ^ uVar23;
  uVar29 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar35 = uVar29 + uVar35;
  uVar39 = uVar35 ^ uVar39;
  uVar39 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar23 = uVar33 + uVar39 + iVar10;
  uVar29 = uVar23 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar35 = uVar29 + uVar35;
  uVar39 = uVar35 ^ uVar39;
  uVar39 = uVar39 >> 7 | uVar39 << 0x19;
  uVar26 = uVar26 + iVar6 + uVar31;
  uVar28 = uVar26 ^ uVar28;
  uVar32 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar21 = uVar21 + uVar32;
  uVar31 = uVar21 ^ uVar31;
  uVar33 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar28 = uVar26 + uVar33 + iVar20;
  uVar32 = uVar28 ^ uVar32;
  uVar31 = uVar32 >> 8 | uVar32 << 0x18;
  uVar21 = uVar31 + uVar21;
  uVar33 = uVar21 ^ uVar33;
  uVar26 = uVar33 >> 7 | uVar33 << 0x19;
  uVar38 = uVar38 + iVar19 + uVar25;
  uVar24 = uVar38 ^ uVar24;
  uVar32 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar36 = uVar36 + uVar32;
  uVar25 = uVar36 ^ uVar25;
  uVar33 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar24 = uVar38 + uVar33 + iVar18;
  uVar32 = uVar24 ^ uVar32;
  uVar25 = uVar32 >> 8 | uVar32 << 0x18;
  uVar36 = uVar25 + uVar36;
  uVar33 = uVar36 ^ uVar33;
  uVar38 = uVar33 >> 7 | uVar33 << 0x19;
  uVar22 = uVar22 + uVar30 + iVar9;
  uVar37 = uVar22 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar27 = uVar27 + uVar37;
  uVar30 = uVar27 ^ uVar30;
  uVar30 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar22 = uVar22 + uVar30 + iVar15;
  uVar37 = uVar22 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar27 = uVar37 + uVar27;
  uVar30 = uVar27 ^ uVar30;
  uVar30 = uVar30 >> 7 | uVar30 << 0x19;
  uVar23 = uVar26 + uVar23 + iVar5;
  uVar37 = uVar23 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar36 = uVar37 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar26 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar23 = uVar23 + uVar26 + iVar12;
  uVar37 = uVar23 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar36 = uVar37 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar26 = uVar26 >> 7 | uVar26 << 0x19;
  uVar28 = uVar28 + uVar38 + iVar11;
  uVar29 = uVar28 ^ uVar29;
  uVar29 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar27 = uVar27 + uVar29;
  uVar38 = uVar27 ^ uVar38;
  uVar38 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar28 = uVar28 + uVar38 + iVar8;
  uVar29 = uVar28 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar27 = uVar29 + uVar27;
  uVar38 = uVar27 ^ uVar38;
  uVar38 = uVar38 >> 7 | uVar38 << 0x19;
  uVar24 = uVar24 + uVar30 + iVar14;
  uVar31 = uVar24 ^ uVar31;
  uVar31 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar35 = uVar35 + uVar31;
  uVar30 = uVar35 ^ uVar30;
  uVar32 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar24 = uVar24 + uVar32 + iVar7;
  uVar31 = uVar24 ^ uVar31;
  uVar30 = uVar31 >> 8 | uVar31 << 0x18;
  uVar35 = uVar30 + uVar35;
  uVar32 = uVar35 ^ uVar32;
  uVar31 = uVar32 >> 7 | uVar32 << 0x19;
  uVar22 = uVar22 + uVar39 + iVar13;
  uVar25 = uVar22 ^ uVar25;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar21 = uVar21 + uVar25;
  uVar39 = uVar21 ^ uVar39;
  uVar39 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar22 = uVar22 + uVar39 + iVar16;
  uVar25 = uVar22 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar21 = uVar25 + uVar21;
  uVar39 = uVar21 ^ uVar39;
  uVar32 = uVar39 >> 7 | uVar39 << 0x19;
  uVar23 = uVar23 + uVar32 + iVar18;
  uVar29 = uVar23 ^ uVar29;
  uVar39 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar35 = uVar39 + uVar35;
  uVar32 = uVar35 ^ uVar32;
  uVar29 = uVar32 >> 0xc | uVar32 << 0x14;
  uVar33 = uVar23 + iVar16 + uVar29;
  uVar39 = uVar39 ^ uVar33;
  uVar34 = uVar39 >> 8 | uVar39 << 0x18;
  uVar35 = uVar35 + uVar34;
  uVar29 = uVar35 ^ uVar29;
  uVar23 = uVar29 >> 7 | uVar29 << 0x19;
  uVar39 = iVar12 + uVar28 + uVar26;
  uVar30 = uVar30 ^ uVar39;
  uVar28 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar21 = uVar21 + uVar28;
  uVar26 = uVar26 ^ uVar21;
  uVar29 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar39 = iVar19 + uVar29 + uVar39;
  uVar28 = uVar39 ^ uVar28;
  uVar28 = uVar28 >> 8 | uVar28 << 0x18;
  uVar21 = uVar28 + uVar21;
  uVar29 = uVar21 ^ uVar29;
  uVar26 = uVar29 >> 7 | uVar29 << 0x19;
  uVar32 = iVar17 + uVar24 + uVar38;
  uVar25 = uVar25 ^ uVar32;
  uVar24 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar36 = uVar36 + uVar24;
  uVar38 = uVar38 ^ uVar36;
  uVar25 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar32 = iVar6 + uVar25 + uVar32;
  uVar24 = uVar32 ^ uVar24;
  uVar24 = uVar24 >> 8 | uVar24 << 0x18;
  uVar36 = uVar24 + uVar36;
  uVar25 = uVar36 ^ uVar25;
  uVar25 = uVar25 >> 7 | uVar25 << 0x19;
  uVar22 = iVar8 + uVar22 + uVar31;
  uVar37 = uVar37 ^ uVar22;
  uVar30 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar27 = uVar30 + uVar27;
  uVar31 = uVar31 ^ uVar27;
  uVar29 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar22 = iVar14 + uVar29 + uVar22;
  uVar30 = uVar22 ^ uVar30;
  uVar30 = uVar30 >> 8 | uVar30 << 0x18;
  uVar27 = uVar30 + uVar27;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar33 = uVar33 + iVar10 + uVar26;
  uVar30 = uVar33 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar36 = uVar30 + uVar36;
  uVar26 = uVar36 ^ uVar26;
  uVar37 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar33 = iVar5 + uVar37 + uVar33;
  uVar30 = uVar33 ^ uVar30;
  uVar30 = uVar30 >> 8 | uVar30 << 0x18;
  uVar36 = uVar30 + uVar36;
  uVar37 = uVar36 ^ uVar37;
  uVar37 = uVar37 >> 7 | uVar37 << 0x19;
  uVar39 = uVar39 + iVar20 + uVar25;
  uVar34 = uVar39 ^ uVar34;
  uVar31 = uVar34 >> 0x10 | uVar34 << 0x10;
  uVar27 = uVar27 + uVar31;
  uVar25 = uVar27 ^ uVar25;
  uVar26 = uVar25 >> 0xc | uVar25 << 0x14;
  uVar39 = iVar9 + uVar26 + uVar39;
  uVar31 = uVar39 ^ uVar31;
  uVar25 = uVar31 >> 8 | uVar31 << 0x18;
  uVar27 = uVar25 + uVar27;
  uVar26 = uVar27 ^ uVar26;
  uVar31 = uVar26 >> 7 | uVar26 << 0x19;
  uVar32 = uVar32 + iVar13 + uVar29;
  uVar28 = uVar32 ^ uVar28;
  uVar28 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar35 = uVar35 + uVar28;
  uVar29 = uVar35 ^ uVar29;
  uVar29 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar32 = iVar11 + uVar29 + uVar32;
  uVar28 = uVar32 ^ uVar28;
  uVar28 = uVar28 >> 8 | uVar28 << 0x18;
  uVar35 = uVar28 + uVar35;
  uVar29 = uVar35 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar22 = uVar23 + uVar22 + iVar7;
  uVar24 = uVar22 ^ uVar24;
  uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
  uVar21 = uVar21 + uVar24;
  uVar23 = uVar21 ^ uVar23;
  uVar26 = uVar23 >> 0xc | uVar23 << 0x14;
  uVar22 = iVar15 + uVar26 + uVar22;
  uVar24 = uVar22 ^ uVar24;
  uVar23 = uVar24 >> 8 | uVar24 << 0x18;
  uVar21 = uVar23 + uVar21;
  uVar26 = uVar21 ^ uVar26;
  uVar24 = uVar26 >> 7 | uVar26 << 0x19;
  uVar33 = iVar11 + uVar24 + uVar33;
  uVar25 = uVar33 ^ uVar25;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar35 = uVar25 + uVar35;
  uVar24 = uVar35 ^ uVar24;
  uVar26 = uVar24 >> 0xc | uVar24 << 0x14;
  uVar24 = uVar33 + uVar26 + iVar20;
  uVar25 = uVar24 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar35 = uVar25 + uVar35;
  uVar26 = uVar35 ^ uVar26;
  uVar26 = uVar26 >> 7 | uVar26 << 0x19;
  uVar38 = uVar39 + iVar19 + uVar37;
  uVar28 = uVar38 ^ uVar28;
  uVar39 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar21 = uVar21 + uVar39;
  uVar37 = uVar21 ^ uVar37;
  uVar33 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar28 = uVar38 + uVar33 + iVar14;
  uVar39 = uVar28 ^ uVar39;
  uVar37 = uVar39 >> 8 | uVar39 << 0x18;
  uVar21 = uVar37 + uVar21;
  uVar33 = uVar21 ^ uVar33;
  uVar38 = uVar33 >> 7 | uVar33 << 0x19;
  uVar39 = uVar32 + iVar16 + uVar31;
  uVar23 = uVar39 ^ uVar23;
  uVar32 = uVar23 >> 0x10 | uVar23 << 0x10;
  uVar36 = uVar36 + uVar32;
  uVar31 = uVar36 ^ uVar31;
  uVar33 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar23 = uVar39 + uVar33 + iVar8;
  uVar32 = uVar23 ^ uVar32;
  uVar31 = uVar32 >> 8 | uVar32 << 0x18;
  uVar36 = uVar31 + uVar36;
  uVar33 = uVar36 ^ uVar33;
  uVar39 = uVar33 >> 7 | uVar33 << 0x19;
  uVar22 = uVar22 + iVar5 + uVar29;
  uVar30 = uVar22 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar27 = uVar27 + uVar30;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar22 = uVar22 + uVar29 + iVar13;
  uVar30 = uVar22 ^ uVar30;
  uVar30 = uVar30 >> 8 | uVar30 << 0x18;
  uVar27 = uVar30 + uVar27;
  uVar29 = uVar27 ^ uVar29;
  uVar29 = uVar29 >> 7 | uVar29 << 0x19;
  uVar24 = uVar38 + uVar24 + iVar17;
  uVar30 = uVar24 ^ uVar30;
  uVar30 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar36 = uVar30 + uVar36;
  uVar38 = uVar36 ^ uVar38;
  uVar38 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar24 = uVar24 + uVar38 + iVar7;
  uVar30 = uVar24 ^ uVar30;
  uVar30 = uVar30 >> 8 | uVar30 << 0x18;
  uVar36 = uVar30 + uVar36;
  uVar38 = uVar36 ^ uVar38;
  uVar38 = uVar38 >> 7 | uVar38 << 0x19;
  uVar28 = uVar28 + uVar39 + iVar18;
  uVar25 = uVar28 ^ uVar25;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar27 = uVar27 + uVar25;
  uVar39 = uVar27 ^ uVar39;
  uVar39 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar28 = uVar28 + uVar39 + iVar12;
  uVar25 = uVar28 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar27 = uVar25 + uVar27;
  uVar39 = uVar27 ^ uVar39;
  uVar39 = uVar39 >> 7 | uVar39 << 0x19;
  uVar23 = uVar23 + uVar29 + iVar6;
  uVar37 = uVar23 ^ uVar37;
  uVar37 = uVar37 >> 0x10 | uVar37 << 0x10;
  uVar35 = uVar35 + uVar37;
  uVar29 = uVar35 ^ uVar29;
  uVar32 = uVar29 >> 0xc | uVar29 << 0x14;
  uVar23 = uVar23 + uVar32 + iVar9;
  uVar37 = uVar23 ^ uVar37;
  uVar29 = uVar37 >> 8 | uVar37 << 0x18;
  uVar35 = uVar29 + uVar35;
  uVar32 = uVar35 ^ uVar32;
  uVar37 = uVar32 >> 7 | uVar32 << 0x19;
  uVar22 = uVar22 + uVar26 + iVar15;
  uVar31 = uVar22 ^ uVar31;
  uVar31 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar21 = uVar21 + uVar31;
  uVar26 = uVar21 ^ uVar26;
  uVar26 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar22 = uVar22 + uVar26 + iVar10;
  uVar31 = uVar22 ^ uVar31;
  uVar31 = uVar31 >> 8 | uVar31 << 0x18;
  uVar21 = uVar31 + uVar21;
  uVar26 = uVar21 ^ uVar26;
  uVar26 = uVar26 >> 7 | uVar26 << 0x19;
  uVar24 = uVar24 + uVar26 + iVar15;
  uVar25 = uVar24 ^ uVar25;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar35 = uVar25 + uVar35;
  uVar26 = uVar35 ^ uVar26;
  uVar26 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar24 = uVar24 + uVar26 + iVar7;
  uVar25 = uVar24 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar35 = uVar25 + uVar35;
  uVar26 = uVar35 ^ uVar26;
  uVar26 = uVar26 >> 7 | uVar26 << 0x19;
  uVar28 = uVar28 + uVar38 + iVar13;
  uVar29 = uVar28 ^ uVar29;
  uVar33 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar21 = uVar33 + uVar21;
  uVar38 = uVar21 ^ uVar38;
  uVar29 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar32 = uVar28 + iVar9 + uVar29;
  uVar33 = uVar33 ^ uVar32;
  uVar33 = uVar33 >> 8 | uVar33 << 0x18;
  uVar21 = uVar21 + uVar33;
  uVar29 = uVar21 ^ uVar29;
  uVar23 = iVar12 + uVar23 + uVar39;
  uVar38 = uVar29 >> 7 | uVar29 << 0x19;
  uVar31 = uVar31 ^ uVar23;
  uVar28 = uVar31 >> 0x10 | uVar31 << 0x10;
  uVar36 = uVar36 + uVar28;
  uVar39 = uVar39 ^ uVar36;
  uVar29 = uVar39 >> 0xc | uVar39 << 0x14;
  uVar23 = iVar11 + uVar29 + uVar23;
  uVar28 = uVar23 ^ uVar28;
  uVar28 = uVar28 >> 8 | uVar28 << 0x18;
  uVar36 = uVar28 + uVar36;
  uVar29 = uVar36 ^ uVar29;
  uVar31 = uVar29 >> 7 | uVar29 << 0x19;
  uVar39 = iVar6 + uVar22 + uVar37;
  uVar30 = uVar30 ^ uVar39;
  uVar29 = uVar30 >> 0x10 | uVar30 << 0x10;
  uVar27 = uVar29 + uVar27;
  uVar37 = uVar37 ^ uVar27;
  uVar22 = uVar37 >> 0xc | uVar37 << 0x14;
  uVar39 = iVar10 + uVar22 + uVar39;
  uVar29 = uVar39 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar27 = uVar29 + uVar27;
  uVar22 = uVar27 ^ uVar22;
  uVar30 = uVar22 >> 7 | uVar22 << 0x19;
  uVar24 = iVar20 + uVar24 + uVar38;
  uVar29 = uVar24 ^ uVar29;
  uVar29 = uVar29 >> 0x10 | uVar29 << 0x10;
  uVar36 = uVar36 + uVar29;
  uVar38 = uVar36 ^ uVar38;
  uVar22 = uVar38 >> 0xc | uVar38 << 0x14;
  uVar24 = uVar22 + iVar16 + uVar24;
  uVar29 = uVar24 ^ uVar29;
  uVar29 = uVar29 >> 8 | uVar29 << 0x18;
  uVar36 = uVar29 + uVar36;
  uVar32 = uVar32 + iVar14 + uVar31;
  uVar25 = uVar25 ^ uVar32;
  uVar25 = uVar25 >> 0x10 | uVar25 << 0x10;
  uVar27 = uVar25 + uVar27;
  uVar31 = uVar27 ^ uVar31;
  uVar31 = uVar31 >> 0xc | uVar31 << 0x14;
  uVar32 = uVar31 + iVar19 + uVar32;
  uVar25 = uVar32 ^ uVar25;
  uVar25 = uVar25 >> 8 | uVar25 << 0x18;
  uVar27 = uVar25 + uVar27;
  uVar23 = uVar23 + iVar8 + uVar30;
  uVar33 = uVar23 ^ uVar33;
  uVar37 = uVar33 >> 0x10 | uVar33 << 0x10;
  uVar35 = uVar35 + uVar37;
  uVar30 = uVar35 ^ uVar30;
  uVar30 = uVar30 >> 0xc | uVar30 << 0x14;
  uVar23 = iVar17 + uVar30 + uVar23;
  uVar37 = uVar23 ^ uVar37;
  uVar37 = uVar37 >> 8 | uVar37 << 0x18;
  uVar35 = uVar37 + uVar35;
  uVar39 = uVar39 + iVar18 + uVar26;
  uVar28 = uVar39 ^ uVar28;
  uVar38 = uVar28 >> 0x10 | uVar28 << 0x10;
  uVar21 = uVar21 + uVar38;
  uVar26 = uVar26 ^ uVar21;
  uVar28 = uVar26 >> 0xc | uVar26 << 0x14;
  uVar39 = iVar5 + uVar28 + uVar39;
  uVar38 = uVar39 ^ uVar38;
  uVar26 = uVar38 >> 8 | uVar38 << 0x18;
  uVar21 = uVar26 + uVar21;
  *param_1 = *param_1 ^ uVar35 ^ uVar24;
  uVar28 = uVar21 ^ uVar28;
  param_1[1] = param_1[1] ^ uVar21 ^ uVar32;
  uVar22 = uVar36 ^ uVar22;
  param_1[2] = param_1[2] ^ uVar23 ^ uVar36;
  uVar31 = uVar27 ^ uVar31;
  param_1[3] = param_1[3] ^ uVar39 ^ uVar27;
  uVar35 = uVar35 ^ uVar30;
  param_1[5] = (uVar22 >> 7 | uVar22 << 0x19) ^ uVar2 ^ uVar37;
  param_1[4] = (uVar28 >> 7 | uVar28 << 0x19) ^ uVar1 ^ uVar25;
  param_1[6] = (uVar31 >> 7 | uVar31 << 0x19) ^ uVar3 ^ uVar26;
  param_1[7] = (uVar35 >> 7 | uVar35 << 0x19) ^ uVar4 ^ uVar29;
  return;
}


// ----- callee: FUN_004296d0 @ 004296d0

int * __fastcall FUN_004296d0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0042cfbe(0x228);
  piVar1[10] = 0;
  piVar1[0x12] = 0;
  piVar1[1] = 0;
  *(undefined2 *)(piVar1 + 0x1a) = 0;
  *(undefined2 *)(piVar1 + 0x21) = 0;
  *(undefined2 *)((int)piVar1 + 0x3b) = 0;
  piVar1[0x36] = 0;
  piVar1[3] = 0;
  piVar1[4] = 0;
  piVar1[2] = 0;
  *(undefined4 *)((int)piVar1 + 0x36) = 0;
  piVar1[9] = 0;
  piVar1[0x18] = 0;
  piVar1[0x19] = 0;
  piVar1[0x16] = 0;
  piVar1[0x17] = 0;
  piVar1[0x86] = 0;
  piVar1[0x32] = 0;
  piVar1[0x33] = 0;
  piVar1[0x34] = 0;
  piVar1[0x35] = 0;
  piVar1[8] = 0;
  piVar1[0x87] = 0;
  piVar1[0x88] = 0;
  piVar1[0x89] = 0;
  piVar1[0x13] = (int)(piVar1 + 0x12);
  *piVar1 = param_1;
  *(undefined2 *)(piVar1 + 0xd) = 0x100;
  piVar1[0x14] = -1000000;
  piVar1[0x15] = -1;
  piVar1[0x2b] = 10000;
  *(undefined1 *)(piVar1 + 0x11) = 0;
  *(undefined1 *)((int)piVar1 + 0x3a) = 0;
  piVar1[0x28] = 0;
  *(undefined2 *)(piVar1 + 0x29) = 0;
  LOCK();
  piVar1[10] = 0;
  UNLOCK();
  piVar1[0x68] = 0;
  piVar1[0x69] = 0;
  piVar1[0x6a] = 0;
  piVar1[0xc] = -1;
  *(undefined4 *)((int)piVar1 + 0x3d) = 0;
  *(undefined2 *)((int)piVar1 + 0x41) = 0;
  *(undefined1 *)((int)piVar1 + 0x43) = 0;
  piVar1[0x58] = 0;
  piVar1[0x59] = 0;
  piVar1[0x5a] = 0;
  piVar1[0x5b] = 0;
  piVar1[0x5c] = 0;
  piVar1[0x5d] = 0;
  piVar1[0x5e] = 0;
  piVar1[0x5f] = 0;
  piVar1[0x50] = 0;
  piVar1[0x51] = 0;
  piVar1[0x52] = 0;
  piVar1[0x53] = 0;
  piVar1[0x54] = 0;
  piVar1[0x55] = 0;
  piVar1[0x56] = 0;
  piVar1[0x57] = 0;
  **(undefined4 **)(*piVar1 + 0x14) = piVar1;
  *(int **)(*piVar1 + 0x14) = piVar1 + 1;
  return piVar1;
}


// ----- callee: FUN_0040bde0 @ 0040bde0

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_0040bde0(uint *param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uStackY_30;
  int iStackY_2c;
  undefined4 uStackY_28;
  
  uVar1 = DAT_0044f008 ^ (int)register0x00000010 - 4U;
  uStackY_28 = 0x40bdff;
  puVar2 = FUN_0042dd80(param_1,'/');
  if (puVar2 != (uint *)0x0) {
    iVar6 = (int)puVar2 - (int)param_1;
    iVar4 = -(iVar6 + 1);
    *(int *)((int)register0x00000010 + iVar4 + -0x20) = iVar6;
    *(uint **)((int)register0x00000010 + iVar4 + -0x24) = param_1;
    *(int *)((int)&uStackY_28 + iVar4) = (int)register0x00000010 + iVar4 + -0x1c;
    *(undefined1 *)((int)register0x00000010 + iVar6 + iVar4 + -0x1c) = 0;
    *(undefined4 *)((int)&iStackY_2c + iVar4) = 0x40be2a;
    FUN_0042f280(*(uint **)((int)&uStackY_28 + iVar4),*(uint **)((int)register0x00000010 + iVar4 + -0x24),
                 *(uint *)((int)register0x00000010 + iVar4 + -0x20));
    *(int *)((int)&iStackY_2c + iVar4) = (int)puVar2 + 1;
    *(undefined4 *)((int)&uStackY_30 + iVar4) = 0x40be34;
    iVar6 = FID_conflict__atoi(*(char **)((int)&iStackY_2c + iVar4));
    if (-1 < iVar6) {
      *(int *)((int)register0x00000010 + iVar4 + -0x20) = param_2;
      *(int *)((int)register0x00000010 + iVar4 + -0x24) = (int)register0x00000010 + iVar4 + -0x1c;
      *(undefined4 *)((int)&uStackY_28 + iVar4) = 2;
      puVar5 = (undefined1 *)((int)&iStackY_2c + iVar4);
      *(undefined4 *)((int)&iStackY_2c + iVar4) = 0x40be4a;
      iVar3 = inet_pton();
      if (iVar3 == 1) {
        if (iVar6 < 0x21) {
          *(char *)(param_2 + 0x11) = (char)iVar6;
          *(undefined1 *)(param_2 + 0x10) = 0x20;
          __security_check_cookie(uVar1 ^ (int)register0x00000010 - 4U);
          return;
        }
      }
      else {
        *(int *)(puVar5 + -4) = param_2;
        *(int *)(puVar5 + -8) = (int)register0x00000010 + iVar4 + -0x1c;
        *(undefined4 *)(puVar5 + -0xc) = 0x17;
        *(undefined4 *)(puVar5 + -0x10) = 0x40be7b;
        iVar4 = inet_pton();
        if ((iVar4 == 1) && (iVar6 < 0x81)) {
          *(char *)(param_2 + 0x11) = (char)iVar6;
          *(undefined1 *)(param_2 + 0x10) = 0x80;
          __security_check_cookie(uVar1 ^ (int)register0x00000010 - 4U);
          return;
        }
      }
    }
  }
  __security_check_cookie(uVar1 ^ (int)register0x00000010 - 4U);
  return;
}


// ----- callee: FUN_0040c0e0 @ 0040c0e0

void __thiscall FUN_0040c0e0(void *this,int *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int *piVar8;
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar9;
  int *piVar10;
  int *piVar11;
  DWORD dwMilliseconds;
  undefined4 uVar12;
  void *local_60;
  uint local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_8;
  
  local_8 = DAT_0044f008 ^ (int)register0x00000010 - 4U;
  local_50 = param_1;
  *(undefined4 *)((int)this + 0x18) = 0;
  local_58 = param_1;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  local_54 = param_2;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  for (piVar8 = *(int **)this; local_60 = this, piVar8 != *(int **)((int)this + 4); piVar8 = piVar8 + 0xd) {
    piVar11 = param_1;
    do {
      iVar9 = *piVar11;
      piVar11 = (int *)((int)piVar11 + 1);
    } while ((char)iVar9 != '\0');
    piVar10 = piVar8;
    if (0xf < (uint)piVar8[5]) {
      piVar10 = (int *)*piVar8;
    }
    uVar2 = piVar8[4];
    piVar5 = param_1;
    if (uVar2 == (int)piVar11 - ((int)param_1 + 1)) {
      while (local_5c = uVar2 - 4, 3 < uVar2) {
        if (*piVar10 != *piVar5) goto LAB_0040c17d;
        piVar10 = piVar10 + 1;
        piVar5 = piVar5 + 1;
        uVar2 = local_5c;
      }
      if (local_5c != 0xfffffffc) {
LAB_0040c17d:
        if (((char)*piVar10 != (char)*piVar5) ||
           ((local_5c != 0xfffffffd &&
            ((*(char *)((int)piVar10 + 1) != *(char *)((int)piVar5 + 1) ||
             ((local_5c != 0xfffffffe &&
              ((*(char *)((int)piVar10 + 2) != *(char *)((int)piVar5 + 2) ||
               ((local_5c != 0xffffffff && (*(char *)((int)piVar10 + 3) != *(char *)((int)piVar5 + 3)))))))))))))
        goto LAB_0040c1bd;
      }
      iVar9 = piVar8[7];
      iVar3 = piVar8[8];
      iVar4 = piVar8[9];
      *param_2 = piVar8[6];
      param_2[1] = iVar9;
      param_2[2] = iVar3;
      param_2[3] = iVar4;
      *(undefined8 *)(param_2 + 4) = *(undefined8 *)(piVar8 + 10);
      param_2[6] = piVar8[0xc];
      if ((short)*param_2 == 2) {
        piVar8 = param_2 + 1;
        uVar12 = 2;
      }
      else {
        if ((short)*param_2 != 0x17) {
          local_4c = local_4c & 0xffffff00;
          goto LAB_0040c36f;
        }
        piVar8 = param_2 + 2;
        uVar12 = 0x17;
      }
      iVar9 = inet_ntop(uVar12,piVar8,&local_4c,0x38);
      if (iVar9 == 0) {
        local_4c = 0x6e6b6e75;
        local_48 = 0x6e776f;
      }
LAB_0040c36f:
      FUN_0040e0a0("Resolved %s to %s%s",(char)local_50);
      __security_check_cookie(local_8 ^ (int)register0x00000010 - 4U);
      return;
    }
LAB_0040c1bd:
  }
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)(*(int *)((int)this + 0xc) + 8) != 0)) {
    FUN_0040e0a0("Disabling DNS blocker to resolve %s",(char)param_1);
    iVar9 = *(int *)(*(int *)((int)this + 0xc) + 8);
    if (iVar9 != 0) {
      *(undefined4 *)(*(int *)((int)this + 0xc) + 8) = 0;
      FwpmEngineClose0(iVar9);
    }
  }
  while (*(char *)((int)this + 0x10) == '\0') {
    puVar6 = (undefined4 *)FUN_0042cfbe(0x14);
    *puVar6 = 0;
    pcVar7 = FUN_0042fbb7((char *)local_50);
    puVar6[1] = param_2;
    *puVar6 = pcVar7;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = (PCONDITION_VARIABLE)((int)this + 0x14);
    *(short *)local_54 = 0;
    AcquireSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
    piVar8 = &DAT_0044f8b8;
    iVar9 = DAT_0044f8b8;
    while (iVar9 != 0) {
      piVar8 = (int *)(iVar9 + 8);
      iVar9 = *piVar8;
    }
    *piVar8 = (int)puVar6;
    if (DAT_0044f8c0 == '\0') {
      if (DAT_0044f8bc != (HANDLE)0x0) {
        WaitForSingleObject(DAT_0044f8bc,0xffffffff);
        CloseHandle(DAT_0044f8bc);
        DAT_0044f8bc = (HANDLE)0x0;
      }
      DAT_0044f8c0 = '\x01';
      DAT_0044f8bc = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0040ca60,&PTR_PTR_0044f8b4,0,(LPDWORD)&local_60);
    }
    cVar1 = *(char *)((int)this + 0x10);
    while ((cVar1 == '\0' && (puVar6[3] == 0))) {
      SleepConditionVariableSRW((PCONDITION_VARIABLE)((int)this + 0x14),(PSRWLOCK)&DAT_004518c8,0xffffffff,0);
      cVar1 = *(char *)((int)this + 0x10);
    }
    if (puVar6[3] == 1) {
      FUN_0042f984((void *)*puVar6);
      FUN_0042cf8d(puVar6);
    }
    else {
      puVar6[3] = 2;
    }
    ReleaseSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
    piVar8 = local_54;
    if ((short)*local_54 != 0) {
      puVar6 = *(undefined4 **)((int)this + 4);
      if (puVar6 == *(undefined4 **)((int)this + 8)) {
        FUN_0040c7d0(this,puVar6,&local_58,local_54);
      }
      else {
        FUN_0040c720(&local_58,puVar6,&local_58,local_54);
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x34;
      }
      if ((short)*piVar8 == 2) {
        piVar8 = piVar8 + 1;
        uVar12 = 2;
      }
      else {
        if ((short)*piVar8 != 0x17) {
          local_4c = local_4c & 0xffffff00;
          goto LAB_0040c4e9;
        }
        piVar8 = piVar8 + 2;
        uVar12 = 0x17;
      }
      iVar9 = inet_ntop(uVar12,piVar8,&local_4c,0x38);
      if (iVar9 == 0) {
        local_4c = 0x6e6b6e75;
        local_48 = 0x6e776f;
      }
LAB_0040c4e9:
      FUN_0040e0a0("Resolved %s to %s%s",(char)local_58);
      __security_check_cookie(local_8 ^ (int)register0x00000010 - 4U);
      return;
    }
    if (*(char *)((int)this + 0x10) != '\0') break;
    FUN_0040e0a0("Unable to resolve %s. Trying again in %d second(s)",(char)local_50);
    dwMilliseconds = (uint)(byte)(&DAT_00448e2c)[*(int *)((int)this + 0x18)] * 1000;
    AcquireSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
    GetTickCount64();
    iVar9 = extraout_EAX;
    if (dwMilliseconds == 0) {
LAB_0040c454:
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
      if (dwMilliseconds != 0) break;
    }
    else {
      do {
        if (*(char *)((int)this + 0x10) != '\0') goto LAB_0040c454;
        if (*(char *)((int)this + 0x11) != '\0') {
          *(undefined1 *)((int)this + 0x11) = 0;
          ReleaseSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
          goto LAB_0040c467;
        }
        SleepConditionVariableSRW((PCONDITION_VARIABLE)((int)this + 0x14),(PSRWLOCK)&DAT_004518c8,dwMilliseconds,0);
        GetTickCount64();
        dwMilliseconds = dwMilliseconds + (iVar9 - extraout_EAX_00);
        iVar9 = extraout_EAX_00;
      } while (0 < (int)dwMilliseconds);
      ReleaseSRWLockExclusive((PSRWLOCK)&DAT_004518c8);
    }
LAB_0040c467:
    param_2 = local_54;
    if (*(int *)((int)this + 0x18) != 10) {
      *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + 1;
    }
  }
  __security_check_cookie(local_8 ^ (int)register0x00000010 - 4U);
  return;
}


// ----- callee: FUN_0040e1b0 @ 0040e1b0

void __thiscall FUN_0040e1b0(void *this,undefined4 *param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  uint *local_8;
  
  param_1[1] = *param_1;
  do {
    for (; (((cVar1 = (char)*(uint *)this, cVar1 == ' ' || (cVar1 == '\r')) || (cVar1 == '\n')) || (cVar1 == '\t'));
        this = (void *)((int)this + 1)) {
    }
    local_8 = this;
    puVar2 = FUN_0042dd80(this,',');
    if (puVar2 == (uint *)0x0) {
      if ((char)*(uint *)this != '\0') {
        puVar2 = (uint *)param_1[1];
        if (puVar2 != (uint *)param_1[2]) {
          *puVar2 = (uint)this;
          param_1[1] = param_1[1] + 4;
          return;
        }
        FUN_004098d0(param_1,puVar2,(uint *)&local_8);
      }
      return;
    }
    *(undefined1 *)puVar2 = 0;
    puVar3 = puVar2;
    while (this < puVar3) {
      cVar1 = *(char *)((int)puVar3 + -1);
      puVar3 = (uint *)((int)puVar3 + -1);
      if (((cVar1 != ' ') && (cVar1 != '\r')) && ((cVar1 != '\n' && (cVar1 != '\t')))) break;
      *(undefined1 *)puVar3 = 0;
    }
    puVar3 = (uint *)param_1[1];
    if (puVar3 == (uint *)param_1[2]) {
      FUN_004098d0(param_1,puVar3,(uint *)&local_8);
      this = (void *)((int)puVar2 + 1);
    }
    else {
      *puVar3 = (uint)this;
      this = (void *)((int)puVar2 + 1);
      param_1[1] = param_1[1] + 4;
    }
  } while( true );
}


// ----- callee: _memset @ 0042e500

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual Studio 2019 Release
    */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;
  
  if (_Size == 0) {
    return _Dst;
  }
  iVar1 = (_Val & 0xffU) * 0x1010101;
  piVar3 = _Dst;
  if (0x20 < _Size) {
    if (0x7f < _Size) {
      puVar2 = _Dst;
      if ((DAT_0044fd84 >> 1 & 1) != 0) {
        for (; _Size != 0; _Size = _Size - 1) {
          *puVar2 = (char)iVar1;
          puVar2 = puVar2 + 1;
        }
        return _Dst;
      }
      if ((DAT_0044f00c >> 1 & 1) == 0) goto joined_r0x0042e60b;
      *(int *)_Dst = iVar1;
      *(int *)((int)_Dst + 4) = iVar1;
      *(int *)((int)_Dst + 8) = iVar1;
      *(int *)((int)_Dst + 0xc) = iVar1;
      piVar3 = (int *)((int)_Dst + 0x10U & 0xfffffff0);
      _Size = (int)_Dst + (_Size - (int)piVar3);
      if (0x80 < _Size) {
        do {
          *piVar3 = iVar1;
          piVar3[1] = iVar1;
          piVar3[2] = iVar1;
          piVar3[3] = iVar1;
          piVar3[4] = iVar1;
          piVar3[5] = iVar1;
          piVar3[6] = iVar1;
          piVar3[7] = iVar1;
          piVar3[8] = iVar1;
          piVar3[9] = iVar1;
          piVar3[10] = iVar1;
          piVar3[0xb] = iVar1;
          piVar3[0xc] = iVar1;
          piVar3[0xd] = iVar1;
          piVar3[0xe] = iVar1;
          piVar3[0xf] = iVar1;
          piVar3[0x10] = iVar1;
          piVar3[0x11] = iVar1;
          piVar3[0x12] = iVar1;
          piVar3[0x13] = iVar1;
          piVar3[0x14] = iVar1;
          piVar3[0x15] = iVar1;
          piVar3[0x16] = iVar1;
          piVar3[0x17] = iVar1;
          piVar3[0x18] = iVar1;
          piVar3[0x19] = iVar1;
          piVar3[0x1a] = iVar1;
          piVar3[0x1b] = iVar1;
          piVar3[0x1c] = iVar1;
          piVar3[0x1d] = iVar1;
          piVar3[0x1e] = iVar1;
          piVar3[0x1f] = iVar1;
          piVar3 = piVar3 + 0x20;
          _Size = _Size - 0x80;
        } while ((_Size & 0xffffff00) != 0);
        goto LAB_0042e5d0;
      }
    }
    if ((DAT_0044f00c >> 1 & 1) != 0) {
LAB_0042e5d0:
      if (0x1f < _Size) {
        do {
          *piVar3 = iVar1;
          piVar3[1] = iVar1;
          piVar3[2] = iVar1;
          piVar3[3] = iVar1;
          piVar3[4] = iVar1;
          piVar3[5] = iVar1;
          piVar3[6] = iVar1;
          piVar3[7] = iVar1;
          piVar3 = piVar3 + 8;
          _Size = _Size - 0x20;
        } while (0x1f < _Size);
        if ((_Size & 0x1f) == 0) {
          return _Dst;
        }
      }
      piVar3 = (int *)((int)piVar3 + (_Size - 0x20));
      *piVar3 = iVar1;
      piVar3[1] = iVar1;
      piVar3[2] = iVar1;
      piVar3[3] = iVar1;
      piVar3[4] = iVar1;
      piVar3[5] = iVar1;
      piVar3[6] = iVar1;
      piVar3[7] = iVar1;
      return _Dst;
    }
  }
joined_r0x0042e60b:
  for (; (_Size & 3) != 0; _Size = _Size - 1) {
    *(char *)piVar3 = (char)iVar1;
    piVar3 = (int *)((int)piVar3 + 1);
  }
  if ((_Size & 4) != 0) {
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    _Size = _Size - 4;
  }
  for (; (_Size & 0xfffffff8) != 0; _Size = _Size - 8) {
    *piVar3 = iVar1;
    piVar3[1] = iVar1;
    piVar3 = piVar3 + 2;
  }
  return _Dst;
}


// ----- callee: FUN_004201d0 @ 004201d0

uint __fastcall FUN_004201d0(char *param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __stricmp(param_1,"true");
  if (iVar1 != 0) {
    iVar1 = __stricmp(param_1,"yes");
    if (iVar1 != 0) {
      iVar1 = __stricmp(param_1,"1");
      if (iVar1 != 0) {
        iVar1 = __stricmp(param_1,"on");
        if (iVar1 != 0) {
          iVar1 = __stricmp(param_1,"false");
          if (iVar1 != 0) {
            iVar1 = __stricmp(param_1,"no");
            if (iVar1 != 0) {
              iVar1 = __stricmp(param_1,"0");
              if (iVar1 != 0) {
                uVar2 = __stricmp(param_1,"off");
                if (uVar2 != 0) {
                  return uVar2 & 0xffffff00;
                }
              }
            }
          }
          *param_2 = 0;
          return 1;
        }
      }
    }
  }
  *param_2 = 1;
  return 1;
}


// ----- callee: FUN_00418620 @ 00418620

void __fastcall FUN_00418620(uint *param_1,byte param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint local_48 [16];
  uint local_8;
  
  local_8 = DAT_0044f008 ^ (uint)(local_48 + 0x11);
  _memset(param_1,0,0x7c);
  *(byte *)param_1 = param_2;
  param_1[0x1d] = (uint)param_2;
  *(char *)((int)param_1 + 1) = (char)param_4;
  *(undefined2 *)((int)param_1 + 2) = 0x101;
  *param_1 = *param_1 ^ 0x6a09e667;
  param_1[1] = param_1[1] ^ 0xbb67ae85;
  param_1[2] = param_1[2] ^ 0x3c6ef372;
  param_1[3] = param_1[3] ^ 0xa54ff53a;
  param_1[4] = param_1[4] ^ 0x510e527f;
  param_1[5] = param_1[5] ^ 0x9b05688c;
  param_1[6] = param_1[6] ^ 0x1f83d9ab;
  param_1[7] = param_1[7] ^ 0x5be0cd19;
  _memset(local_48,0,0x40);
  FUN_0042f280(local_48,param_3,param_4);
  FUN_00419bc0(param_1,local_48,0x40);
  puVar2 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  __security_check_cookie(local_8 ^ (uint)(local_48 + 0x11));
  return;
}


// ----- callee: __security_check_cookie @ 0042cf7c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 != DAT_0044f008) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_00429640 @ 00429640

void __thiscall FUN_00429640(void *this,undefined4 *param_1)

{
  uint *puVar1;
  void *this_00;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)((int)this + 0xc0) = *param_1;
  *(undefined4 *)((int)this + 0xc4) = uVar2;
  *(undefined4 *)((int)this + 200) = uVar3;
  *(undefined4 *)((int)this + 0xcc) = uVar4;
  puVar1 = (uint *)((int)this + 0xe0);
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)((int)this + 0xd0) = param_1[4];
  *(undefined4 *)((int)this + 0xd4) = uVar2;
  *(undefined4 *)((int)this + 0xd8) = uVar3;
  *(undefined4 *)((int)this + 0xdc) = uVar4;
  FUN_004200c0((undefined1 *)puVar1,(byte *)((int)this + 0xc0),&DAT_004481e8);
  FUN_00429550((void *)((int)this + 0x100),(uint *)&DAT_004482ac,8,puVar1,0x20);
  FUN_00429550((void *)((int)this + 0x120),(uint *)&DAT_00448270,8,puVar1,0x20);
  this_00 = *(void **)((int)this + 0x10);
  *(undefined1 *)((int)this + 0x85) = 1;
  for (; this_00 != (void *)0x0; this_00 = *(void **)((int)this_00 + 4)) {
    FUN_00429d00(this_00,(uint *)((int)this_00 + 0x140));
  }
  return;
}


// ----- callee: FUN_004096e0 @ 004096e0

uint * __thiscall FUN_004096e0(void *this,uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  code *pcVar4;
  uint uVar5;
  uint *puVar6;
  void *pvVar7;
  uint uVar8;
  
  uVar2 = *(uint *)((int)this + 0x14);
  if (param_2 <= uVar2) {
    puVar6 = this;
    if (0xf < uVar2) {
      puVar6 = *(uint **)this;
    }
    *(uint *)((int)this + 0x10) = param_2;
    FUN_0042e660(puVar6,param_1,param_2);
    *(undefined1 *)((int)puVar6 + param_2) = 0;
    return this;
  }
  if (0x7fffffff < param_2) {
    FUN_004071b0();
LAB_00409800:
    FUN_00402350();
    pcVar4 = (code *)swi(3);
    puVar6 = (uint *)(*pcVar4)();
    return puVar6;
  }
  uVar8 = param_2 | 0xf;
  if ((uVar8 < 0x80000000) && (uVar2 <= 0x7fffffff - (uVar2 >> 1))) {
    uVar5 = (uVar2 >> 1) + uVar2;
    if (uVar8 < uVar5) {
      uVar8 = uVar5;
    }
    uVar1 = uVar8 + 1;
    if (0xfff < uVar1) {
      uVar5 = uVar8 + 0x24;
      if (uVar5 <= uVar1) goto LAB_00409800;
      goto LAB_00409770;
    }
    if (uVar1 == 0) {
      puVar6 = (uint *)0x0;
    }
    else {
      puVar6 = (uint *)FUN_0042cfbe(uVar1);
    }
  }
  else {
    uVar8 = 0x7fffffff;
    uVar5 = 0x80000023;
LAB_00409770:
    uVar5 = FUN_0042cfbe(uVar5);
    if (uVar5 == 0) goto LAB_004097f6;
    puVar6 = (uint *)(uVar5 + 0x23 & 0xffffffe0);
    puVar6[-1] = uVar5;
  }
  *(uint *)((int)this + 0x10) = param_2;
  *(uint *)((int)this + 0x14) = uVar8;
  FUN_0042f280(puVar6,param_1,param_2);
  *(undefined1 *)((int)puVar6 + param_2) = 0;
  if (0xf < uVar2) {
    pvVar3 = *(void **)this;
    pvVar7 = pvVar3;
    if ((0xfff < uVar2 + 1) && (pvVar7 = *(void **)((int)pvVar3 + -4), 0x1f < (uint)((int)pvVar3 + (-4 - (int)pvVar7))))
    {
LAB_004097f6:
                    /* WARNING: Subroutine does not return */
      FUN_0042fb66();
    }
    FUN_0042cf8d(pvVar7);
  }
  *(uint **)this = puVar6;
  return this;
}


// ----- callee: FUN_0042bd40 @ 0042bd40

undefined4 __thiscall FUN_0042bd40(void *this,uint *param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint in_EAX;
  uint *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  byte bVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  ulonglong uVar13;
  uint local_2c;
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined4 local_1c;
  void *pvStack_18;
  uint *local_14;
  void *local_10;
  uint *local_c;
  
  puVar4 = param_1;
  local_10 = this;
  if ((char)param_1[4] == ' ') {
    pbVar1 = (byte *)((int)param_1 + 0x11);
    if (*pbVar1 < 0x21) {
      uVar11 = *param_1;
      param_1 = this;
      puVar5 = (uint *)FUN_004026b0((void *)(*(int *)this + 0xc),
                                    uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18,
                                    *pbVar1,(uint *)&param_1);
      puVar7 = param_1;
LAB_0042bde0:
      local_14 = puVar7;
      if (puVar7 != (uint *)0x0) {
        local_c = (uint *)puVar7[0x88];
        puVar5 = (uint *)puVar7[0x87];
        if (puVar5 != local_c) {
          bVar8 = (byte)puVar4[4];
          do {
            if (((byte)puVar5[4] == bVar8) && (*(char *)((int)puVar5 + 0x11) == *(char *)((int)puVar4 + 0x11))) {
              puVar9 = puVar4;
              puVar10 = puVar5;
              uVar11 = (uint)(byte)((byte)puVar5[4] >> 3);
              while (uVar3 = uVar11 - 4, 3 < uVar11) {
                if (*puVar10 != *puVar9) goto LAB_0042be3c;
                puVar10 = puVar10 + 1;
                puVar9 = puVar9 + 1;
                uVar11 = uVar3;
              }
              if (uVar3 != 0xfffffffc) {
LAB_0042be3c:
                if (((char)*puVar10 != (char)*puVar9) ||
                   ((uVar3 != 0xfffffffd &&
                    ((*(char *)((int)puVar10 + 1) != *(char *)((int)puVar9 + 1) ||
                     ((uVar3 != 0xfffffffe &&
                      ((*(char *)((int)puVar10 + 2) != *(char *)((int)puVar9 + 2) ||
                       ((uVar3 != 0xffffffff && (*(char *)((int)puVar10 + 3) != *(char *)((int)puVar9 + 3))))))))))))) {
                  bVar8 = (byte)puVar4[4];
                  goto LAB_0042be6f;
                }
              }
              uVar13 = FUN_0042e660(puVar5,(uint *)((int)puVar5 + 0x12),puVar7[0x88] - ((int)puVar5 + 0x12));
              puVar5 = (uint *)uVar13;
              puVar7[0x88] = puVar7[0x88] - 0x12;
              break;
            }
LAB_0042be6f:
            puVar5 = (uint *)((int)puVar5 + 0x12);
          } while (puVar5 != local_c);
        }
      }
      goto LAB_0042bee2;
    }
  }
  else if (((char)param_1[4] == -0x80) && (bVar8 = *(byte *)((int)param_1 + 0x11), bVar8 < 0x81)) {
    local_c = *(uint **)this;
    local_14 = (uint *)local_c[1];
    puVar5 = (uint *)*local_c;
    if (puVar5 != local_14) {
      do {
        if ((byte)puVar5[4] == bVar8) {
          uVar11 = 0xc;
          puVar7 = puVar5;
          puVar9 = param_1;
          while (*puVar7 == *puVar9) {
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
            bVar12 = uVar11 < 4;
            uVar11 = uVar11 - 4;
            if (bVar12) {
              puVar7 = (uint *)puVar5[5];
              puVar5[5] = (uint)this;
              goto LAB_0042bde0;
            }
          }
          bVar8 = *(byte *)((int)param_1 + 0x11);
        }
        puVar5 = puVar5 + 6;
      } while (puVar5 != local_14);
    }
    local_2c = *param_1;
    uStack_28 = param_1[1];
    uStack_24 = param_1[2];
    uStack_20 = param_1[3];
    local_1c = CONCAT31(local_1c._1_3_,bVar8);
    pvStack_18 = this;
    if (local_14 == (uint *)local_c[2]) {
      puVar5 = FUN_00403600(local_c,local_14,&local_2c);
    }
    else {
      *local_14 = local_2c;
      local_14[1] = uStack_28;
      local_14[2] = uStack_24;
      local_14[3] = uStack_20;
      *(ulonglong *)(local_14 + 4) = CONCAT44(this,local_1c);
      local_c[1] = local_c[1] + 0x18;
    }
LAB_0042bee2:
    puVar7 = *(uint **)((int)local_10 + 0x220);
    if (puVar7 == *(uint **)((int)local_10 + 0x224)) {
      puVar6 = FUN_00414bc0((void *)((int)local_10 + 0x21c),puVar7,puVar4);
      return CONCAT31((int3)((uint)puVar6 >> 8),1);
    }
    uVar11 = puVar4[1];
    uVar3 = puVar4[2];
    uVar2 = puVar4[3];
    *puVar7 = *puVar4;
    puVar7[1] = uVar11;
    puVar7[2] = uVar3;
    puVar7[3] = uVar2;
    uVar11 = puVar4[4];
    *(short *)(puVar7 + 4) = (short)uVar11;
    *(int *)((int)local_10 + 0x220) = *(int *)((int)local_10 + 0x220) + 0x12;
    return CONCAT31((int3)(CONCAT22((short)((uint)puVar5 >> 0x10),(short)uVar11) >> 8),1);
  }
  return in_EAX & 0xffffff00;
}


// ----- callee: FUN_0040e010 @ 0040e010

void __cdecl FUN_0040e010(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(1,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_0042cf8d @ 0042cf8d

void __cdecl FUN_0042cf8d(void *param_1)

{
  thunk_FUN_0042f984(param_1);
  return;
}


// ----- callee: FUN_00422a20 @ 00422a20

int * __thiscall FUN_00422a20(void *this,int *param_1,undefined4 *param_2)

{
  int *this_00;
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  void *pvVar12;
  int *piVar13;
  
  iVar1 = *(int *)this;
  iVar4 = (*(int *)((int)this + 4) - iVar1) / 0x18;
  if (iVar4 != 0xaaaaaaa) {
    uVar10 = iVar4 + 1;
    uVar5 = (*(int *)((int)this + 8) - iVar1) / 0x18;
    if (0xaaaaaaa - (uVar5 >> 1) < uVar5) {
      uVar5 = uVar10;
    }
    else {
      uVar5 = (uVar5 >> 1) + uVar5;
      if (uVar5 < uVar10) {
        uVar5 = uVar10;
      }
    }
    if (uVar5 < 0xaaaaaab) {
      uVar10 = uVar5 * 0x18;
      if (uVar10 < 0x1000) {
        if (uVar10 == 0) {
          piVar11 = (int *)0x0;
        }
        else {
          piVar11 = (int *)FUN_0042cfbe(uVar10);
        }
      }
      else {
        if (uVar10 + 0x23 <= uVar10) goto LAB_00422bde;
        iVar6 = FUN_0042cfbe(uVar10 + 0x23);
        if (iVar6 == 0) goto LAB_00422be8;
        piVar11 = (int *)(iVar6 + 0x23U & 0xffffffe0);
        piVar11[-1] = iVar6;
      }
      this_00 = piVar11 + (((int)param_1 - iVar1) / 0x18) * 6;
      puVar2 = (uint *)*param_2;
      this_00[4] = 0;
      this_00[5] = 0xf;
      *(undefined1 *)this_00 = 0;
      puVar7 = puVar2;
      do {
        uVar10 = *puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
      } while ((char)uVar10 != '\0');
      FUN_004096e0(this_00,puVar2,(int)puVar7 - ((int)puVar2 + 1));
      piVar9 = *(int **)((int)this + 4);
      piVar8 = *(int **)this;
      piVar13 = piVar11;
      if (param_1 != piVar9) {
        FUN_00422d40(*(int **)this,param_1,piVar11);
        piVar9 = *(int **)((int)this + 4);
        piVar13 = this_00 + 6;
        piVar8 = param_1;
      }
      FUN_00422d40(piVar8,piVar9,piVar13);
      if (*(int **)this == (int *)0x0) {
LAB_00422bbd:
        *(int **)this = piVar11;
        *(int **)((int)this + 4) = piVar11 + (iVar4 + 1) * 6;
        *(int **)((int)this + 8) = piVar11 + uVar5 * 6;
        return this_00;
      }
      FUN_00414d70(*(int **)this,*(int **)((int)this + 4));
      pvVar3 = *(void **)this;
      pvVar12 = pvVar3;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar3) / 0x18) * 0x18) < 0x1000) ||
         (pvVar12 = *(void **)((int)pvVar3 + -4), (uint)((int)pvVar3 + (-4 - (int)pvVar12)) < 0x20)) {
        FUN_0042cf8d(pvVar12);
        goto LAB_00422bbd;
      }
      goto LAB_00422be8;
    }
LAB_00422bde:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00422be8:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- callee: _strncmp @ 004315d0

/* Library Function - Single Match
    _strncmp
   
   Library: Visual Studio 2019 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if (_MaxCount != 0) {
    iVar3 = (int)_Str1 - (int)_Str2;
    do {
      if (((uint)_Str2 & 3) == 0) {
        while ((((uint)(iVar3 + (int)_Str2) & 0xfff) < 0xffd &&
               (uVar2 = *(uint *)(iVar3 + (int)_Str2), uVar2 == *(uint *)_Str2))) {
          bVar4 = _MaxCount < 4;
          _MaxCount = _MaxCount - 4;
          if (bVar4 || _MaxCount == 0) {
            return 0;
          }
          _Str2 = (char *)((int)_Str2 + 4);
          if ((~uVar2 & uVar2 + 0xfefefeff & 0x80808080) != 0) {
            return 0;
          }
        }
      }
      bVar1 = *(byte *)(iVar3 + (int)_Str2);
      if (bVar1 != (byte)*(uint *)_Str2) {
        return -(uint)(bVar1 < (byte)*(uint *)_Str2) | 1;
      }
      if (bVar1 == 0) {
        return 0;
      }
      _Str2 = (char *)((int)_Str2 + 1);
      bVar4 = _MaxCount != 0;
      _MaxCount = _MaxCount - 1;
    } while (bVar4 && _MaxCount != 0);
  }
  return 0;
}


// ----- callee: FUN_00429d00 @ 00429d00

void __thiscall FUN_00429d00(void *this,uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int local_10 [3];
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  puVar1 = (uint *)((int)this + 0x140);
  *puVar1 = *param_1;
  *(uint *)((int)this + 0x144) = uVar2;
  *(uint *)((int)this + 0x148) = uVar3;
  *(uint *)((int)this + 0x14c) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(uint *)((int)this + 0x150) = param_1[4];
  *(uint *)((int)this + 0x154) = uVar2;
  *(uint *)((int)this + 0x158) = uVar3;
  *(uint *)((int)this + 0x15c) = uVar4;
  piVar5 = (int *)FUN_0042c5a0((void *)(*(int *)this + 0x5c),local_10,puVar1);
  *(void **)(*piVar5 + 0x28) = this;
  if (*(char *)(*(int *)this + 0x85) != '\0') {
    FUN_004200c0((undefined1 *)((int)this + 0x180),(byte *)(*(int *)this + 0xc0),(byte *)puVar1);
    FUN_00429550((void *)((int)this + 0x1ac),(uint *)&DAT_004482ac,8,puVar1,0x20);
    FUN_00429550((void *)((int)this + 0x1cc),(uint *)&DAT_00448270,8,puVar1,0x20);
    FUN_00429c00((int)this);
    param_1 = *(uint **)((int)this + 0x24);
    if (param_1 != (uint *)0x0) {
      *(undefined4 *)((int)this + 0x24) = 0;
      FUN_0042c360((void *)(*(int *)this + 0x1c),(uint *)&param_1);
    }
  }
  return;
}


// ----- callee: FUN_0040c530 @ 0040c530

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_0040c530(char *param_1,undefined4 *param_2,void *param_3)

{
  char cVar1;
  u_short uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  
  uVar3 = DAT_0044f008 ^ (int)register0x00000010 - 4U;
  pcVar9 = param_1;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uStack_20 = 0x40c561;
  iVar5 = -(int)(pcVar9 + (1 - (int)(param_1 + 1)));
  *(char **)((int)&uStack_20 + iVar5) = pcVar9 + (1 - (int)(param_1 + 1));
  *(char **)((int)&iStack_24 + iVar5) = param_1;
  *(int *)((int)&uStack_28 + iVar5) = (int)register0x00000010 + iVar5 + -0x1c;
  *(undefined4 *)((int)&uStack_2c + iVar5) = 0x40c56d;
  FUN_0042f280(*(uint **)((int)&uStack_28 + iVar5),*(uint **)((int)&iStack_24 + iVar5),
               *(uint *)((int)&uStack_20 + iVar5));
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined8 *)(param_2 + 4) = 0;
  param_2[6] = 0;
  if (*(char *)((int)register0x00000010 + iVar5 + -0x1c) == '[') {
    *(undefined4 *)((int)&uStack_20 + iVar5) = 0x5d;
    *(int *)((int)&iStack_24 + iVar5) = (int)register0x00000010 + iVar5 + -0x1c;
    *(undefined4 *)((int)&uStack_28 + iVar5) = 0x40c58f;
    puVar4 = FUN_0042dd80(*(uint **)((int)&iStack_24 + iVar5),*(char *)((int)&uStack_20 + iVar5));
    if (puVar4 != (uint *)0x0) {
      *(undefined1 *)puVar4 = 0;
      *(undefined4 **)((int)&uStack_20 + iVar5) = param_2 + 2;
      *(int *)((int)&iStack_24 + iVar5) = (int)register0x00000010 + iVar5 + -0x1b;
      *(undefined4 *)((int)&uStack_28 + iVar5) = 0x17;
      puVar7 = (undefined1 *)((int)&uStack_2c + iVar5);
      *(undefined4 *)((int)&uStack_2c + iVar5) = 0x40c5af;
      iVar5 = inet_pton();
      if (iVar5 == 1) {
        *(undefined4 *)(puVar7 + -4) = 0x3a;
        *(int *)(puVar7 + -8) = (int)puVar4 + 1;
        *(undefined4 *)(puVar7 + -0xc) = 0x40c5c3;
        puVar4 = FUN_0042dd80(*(uint **)(puVar7 + -8),puVar7[-4]);
        if (puVar4 != (uint *)0x0) {
          *(int *)(puVar7 + -4) = (int)puVar4 + 1;
          *(undefined2 *)param_2 = 0x17;
          *(undefined4 *)(puVar7 + -8) = 0x40c5dd;
          iVar5 = FID_conflict__atoi(*(char **)(puVar7 + -4));
          *(int *)(puVar7 + -4) = iVar5;
          *(undefined4 *)(puVar7 + -8) = 0x40c5e7;
          uVar2 = htons(*(u_short *)(puVar7 + -4));
          *(u_short *)((int)param_2 + 2) = uVar2;
          __security_check_cookie(uVar3 ^ (int)register0x00000010 - 4U);
          return;
        }
      }
    }
  }
  else {
    *(undefined4 *)((int)&uStack_20 + iVar5) = 0x3a;
    *(int *)((int)&iStack_24 + iVar5) = (int)register0x00000010 + iVar5 + -0x1c;
    *(undefined4 *)((int)&uStack_28 + iVar5) = 0x40c609;
    puVar4 = FUN_0042dd80(*(uint **)((int)&iStack_24 + iVar5),*(char *)((int)&uStack_20 + iVar5));
    if (puVar4 != (uint *)0x0) {
      *(undefined1 *)puVar4 = 0;
      *(undefined4 **)((int)&uStack_20 + iVar5) = param_2 + 1;
      *(int *)((int)&iStack_24 + iVar5) = (int)register0x00000010 + iVar5 + -0x1c;
      *(undefined4 *)((int)&uStack_28 + iVar5) = 2;
      puVar8 = (undefined1 *)((int)&uStack_2c + iVar5);
      *(undefined4 *)((int)&uStack_2c + iVar5) = 0x40c622;
      iVar6 = inet_pton();
      if (iVar6 == 1) {
        *(undefined2 *)param_2 = 2;
LAB_0040c62f:
        *(int *)(puVar8 + -4) = (int)puVar4 + 1;
        *(undefined4 *)(puVar8 + -8) = 0x40c638;
        iVar5 = FID_conflict__atoi(*(char **)(puVar8 + -4));
        *(int *)(puVar8 + -4) = iVar5;
        *(undefined4 *)(puVar8 + -8) = 0x40c642;
        uVar2 = htons(*(u_short *)(puVar8 + -4));
        *(u_short *)((int)param_2 + 2) = uVar2;
        __security_check_cookie(uVar3 ^ (int)register0x00000010 - 4U);
        return;
      }
      if (param_3 != (void *)0x0) {
        *(undefined4 **)(puVar8 + -4) = param_2;
        *(int *)((int)puVar8 + -8) = (int)register0x00000010 + iVar5 + -0x1c;
        *(undefined4 *)(puVar8 + -0xc) = 0x40c66a;
        cVar1 = FUN_0040c0e0(param_3,*(int **)(puVar8 + -8),*(int **)(puVar8 + -4));
        if (cVar1 != '\0') goto LAB_0040c62f;
        *(int *)((int)puVar8 + -4) = (int)register0x00000010 + iVar5 + -0x1c;
        *(char **)(puVar8 + -8) = "Unable to resolve %s";
        *(undefined4 *)(puVar8 + -0xc) = 0x40c679;
        FUN_0040e010(*(char **)(puVar8 + -8),puVar8[-4]);
      }
    }
  }
  __security_check_cookie(uVar3 ^ (int)register0x00000010 - 4U);
  return;
}


// ----- callee: FUN_00419bc0 @ 00419bc0

void __fastcall FUN_00419bc0(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 != 0) {
    uVar1 = param_1[0x1c];
    uVar2 = 0x40 - uVar1;
    uVar3 = param_3;
    if (uVar2 < param_3) {
      param_1[0x1c] = 0;
      FUN_0042f280((uint *)((int)param_1 + uVar1 + 0x30),param_2,uVar2);
      param_1[8] = param_1[8] + 0x40;
      param_1[9] = param_1[9] + (uint)(param_1[8] < 0x40);
      FUN_004186e0(param_1,(int *)(param_1 + 0xc));
      uVar3 = param_3 - uVar2;
      param_2 = (uint *)((int)param_2 + uVar2);
      if (0x40 < uVar3) {
        param_3 = (uVar3 - 0x41 >> 6) + 1;
        do {
          param_1[8] = param_1[8] + 0x40;
          param_1[9] = param_1[9] + (uint)(param_1[8] < 0x40);
          FUN_004186e0(param_1,(int *)param_2);
          param_2 = param_2 + 0x10;
          uVar3 = uVar3 - 0x40;
          param_3 = param_3 - 1;
        } while (param_3 != 0);
      }
    }
    FUN_0042f280((uint *)(param_1[0x1c] + 0x30 + (int)param_1),param_2,uVar3);
    param_1[0x1c] = param_1[0x1c] + uVar3;
  }
  return;
}


// ----- callee: FID_conflict:_atoi @ 004315a0

/* Library Function - Multiple Matches With Different Base Names
    _atoi
    _atol
   
   Library: Visual Studio 2019 Release */

int __cdecl FID_conflict__atoi(char *_Str)

{
  ulong uVar1;
  
  uVar1 = __crt_strtox::parse_integer<unsigned_long,__crt_strtox::c_string_character_source<char>_>(0,_Str,0,10,1);
  return uVar1;
}


// ----- callee: FUN_00414bc0 @ 00414bc0

undefined4 * __thiscall FUN_00414bc0(void *this,uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  void *pvVar12;
  
  iVar2 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar2) / 0x12;
  if (iVar5 != 0xe38e38e) {
    uVar10 = iVar5 + 1;
    uVar9 = (*(int *)((int)this + 8) - iVar2) / 0x12;
    if (0xe38e38e - (uVar9 >> 1) < uVar9) {
      uVar9 = uVar10;
    }
    else {
      uVar9 = (uVar9 >> 1) + uVar9;
      if (uVar9 < uVar10) {
        uVar9 = uVar10;
      }
    }
    if (uVar9 < 0xe38e38f) {
      uVar9 = uVar9 * 0x12;
      if (uVar9 < 0x1000) {
        if (uVar9 == 0) {
          puVar11 = (uint *)0x0;
        }
        else {
          puVar11 = (uint *)FUN_0042cfbe(uVar9);
        }
      }
      else {
        if (uVar9 + 0x23 <= uVar9) goto LAB_00414d5c;
        uVar10 = FUN_0042cfbe(uVar9 + 0x23);
        if (uVar10 == 0) goto LAB_00414d66;
        puVar11 = (uint *)(uVar10 + 0x23 & 0xffffffe0);
        puVar11[-1] = uVar10;
      }
      puVar1 = (undefined4 *)((int)puVar11 + (((int)param_1 - iVar2) / 0x12) * 0x12);
      uVar6 = param_2[1];
      uVar7 = param_2[2];
      uVar8 = param_2[3];
      *puVar1 = *param_2;
      puVar1[1] = uVar6;
      puVar1[2] = uVar7;
      puVar1[3] = uVar8;
      *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(param_2 + 4);
      puVar3 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar11,puVar3,(int)*(uint **)((int)this + 4) - (int)puVar3);
      }
      else {
        FUN_0042e660(puVar11,puVar3,(int)param_1 - (int)puVar3);
        FUN_0042e660((uint *)((int)puVar1 + 0x12),param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_00414d36:
        *(uint **)this = puVar11;
        *(int *)((int)this + 4) = (int)puVar11 + (iVar5 * 9 + 9) * 2;
        *(uint *)((int)this + 8) = uVar9 + (int)puVar11;
        return puVar1;
      }
      pvVar12 = pvVar4;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar4) / 0x12) * 0x12) < 0x1000) ||
         (pvVar12 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar12)) < 0x20)) {
        FUN_0042cf8d(pvVar12);
        goto LAB_00414d36;
      }
      goto LAB_00414d66;
    }
LAB_00414d5c:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414d66:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}



// ===================== FUN_00429db0 @ 00429db0  anchors: [ObfuscateKey(win@004482b4), ObfuscateKey(win@004482c4), ObfuscateKey(win@004482d4), ObfuscateKey(win@004482e4)] =====================

void __thiscall FUN_00429db0(void *this,int param_1)

{
  undefined4 *this_00;
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  _FILETIME _Var4;
  int *this_01;
  HMODULE hModule;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  char *lpProcName;
  uint local_b0 [8];
  uint local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 local_70;
  _FILETIME local_68;
  int *local_60;
  undefined4 local_5c;
  uint *local_58;
  uint *local_54;
  uint local_50 [4];
  _SYSTEMTIME local_40;
  uint local_2c [4];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  puVar12 = *(uint **)(param_1 + 0x20);
  this_00 = (undefined4 *)((int)this + 0xdc);
  *(undefined4 *)((int)this + 0xfc) = 0xae6de260;
  *(undefined4 *)((int)this + 0x100) = 0xc0ef27f3;
  *(undefined4 *)((int)this + 0x104) = 0xe235c32e;
  *(undefined4 *)((int)this + 0x108) = 0xd0d225a0;
  *(undefined4 *)((int)this + 0x10c) = 0x642eb16;
  *(undefined4 *)((int)this + 0x110) = 0xf57772f8;
  *(undefined4 *)((int)this + 0x114) = 0x98d1382d;
  *(undefined4 *)((int)this + 0x118) = 0x36cd788b;
  *this_00 = 0x61b31122;
  *(undefined4 *)((int)this + 0xe0) = 0x66c51a08;
  *(undefined4 *)((int)this + 0xe4) = 0xdb431269;
  *(undefined4 *)((int)this + 0xe8) = 0x32d58a45;
  *(undefined4 *)((int)this + 0xec) = 0x666c9c2d;
  *(undefined4 *)((int)this + 0xf0) = 0xb7e89322;
  *(undefined4 *)((int)this + 0xf4) = 0x659ce10e;
  *(undefined4 *)((int)this + 0xf8) = 0xf39e07ba;
  local_60 = this;
  local_58 = puVar12;
  FUN_00429550(this_00,this_00,0x20,(uint *)((int)this + 0x140),0x20);
  if (DAT_00451dbc == (FARPROC)0x0) {
    lpProcName = "SystemFunction036";
    hModule = LoadLibraryA("ADVAPI32.DLL");
    DAT_00451dbc = GetProcAddress(hModule,lpProcName);
    if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00429e5f;
  }
  iVar5 = (*DAT_00451dbc)((int)this + 0x11c,0x20);
  if ((char)iVar5 != '\0') {
    *(byte *)((int)this + 0x11c) = *(byte *)((int)this + 0x11c) & 0xf8;
    *(byte *)((int)this + 0x13b) = *(byte *)((int)this + 0x13b) & 0x3f | 0x40;
    local_54 = puVar12 + 2;
    FUN_004200c0((undefined1 *)local_54,(byte *)((int)this + 0x11c),&DAT_004481e8);
    FUN_00419d50(local_b0,local_54,0x20,(uint *)((int)this + 0xfc));
    local_90 = CONCAT31(local_90._1_3_,1);
    FUN_00419d50(&local_90,&local_90,1,local_b0);
    puVar12 = local_54;
    *(uint *)((int)this + 0xfc) = local_90;
    *(undefined4 *)((int)this + 0x100) = uStack_8c;
    *(undefined4 *)((int)this + 0x104) = uStack_88;
    *(undefined4 *)((int)this + 0x108) = uStack_84;
    *(undefined4 *)((int)this + 0x10c) = local_80;
    *(undefined4 *)((int)this + 0x110) = uStack_7c;
    *(undefined4 *)((int)this + 0x114) = uStack_78;
    *(undefined4 *)((int)this + 0x118) = uStack_74;
    puVar11 = local_b0;
    for (iVar5 = 0x41; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (uint *)((int)puVar11 + 1);
    }
    FUN_00429550(this_00,this_00,0x20,puVar12,0x20);
    FUN_004200c0((undefined1 *)local_50,(byte *)((int)this + 0x11c),(byte *)((int)this + 0x140));
    FUN_00419d50(local_b0,local_50,0x20,(uint *)((int)this + 0xfc));
    local_90 = CONCAT31(local_90._1_3_,1);
    FUN_00419d50(&local_90,&local_90,1,local_b0);
    local_70 = 2;
    *(uint *)((int)this + 0xfc) = local_90;
    *(undefined4 *)((int)this + 0x100) = uStack_8c;
    *(undefined4 *)((int)this + 0x104) = uStack_88;
    *(undefined4 *)((int)this + 0x108) = uStack_84;
    *(undefined4 *)((int)this + 0x10c) = local_80;
    *(undefined4 *)((int)this + 0x110) = uStack_7c;
    *(undefined4 *)((int)this + 0x114) = uStack_78;
    *(undefined4 *)((int)this + 0x118) = uStack_74;
    FUN_00419d50(&local_90,&local_90,0x21,local_b0);
    local_2c[0] = local_90;
    local_2c[1] = uStack_8c;
    local_2c[2] = uStack_88;
    local_2c[3] = uStack_84;
    local_1c = local_80;
    uStack_18 = uStack_7c;
    uStack_14 = uStack_78;
    uStack_10 = uStack_74;
    iVar5 = *(int *)this;
    puVar11 = local_58 + 10;
    puVar12 = local_b0;
    for (iVar6 = 0x41; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (uint *)((int)puVar12 + 1);
    }
    puVar12 = local_50;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    puVar12 = (uint *)((int)this + 0xdc);
    FUN_0041c930(puVar11,(uint *)(iVar5 + 0xe0),0x20,puVar12,0x20,0,0,local_2c);
    FUN_00429550(puVar12,puVar12,0x20,puVar11,0x30);
    FUN_00419d50(local_b0,(uint *)((int)this + 0x180),0x20,(uint *)((int)this + 0xfc));
    local_90 = CONCAT31(local_90._1_3_,1);
    FUN_00419d50(&local_90,&local_90,1,local_b0);
    local_70 = 2;
    *(uint *)((int)this + 0xfc) = local_90;
    *(undefined4 *)((int)this + 0x100) = uStack_8c;
    *(undefined4 *)((int)this + 0x104) = uStack_88;
    *(undefined4 *)((int)this + 0x108) = uStack_84;
    *(undefined4 *)((int)this + 0x10c) = local_80;
    *(undefined4 *)((int)this + 0x110) = uStack_7c;
    *(undefined4 *)((int)this + 0x114) = uStack_78;
    *(undefined4 *)((int)this + 0x118) = uStack_74;
    FUN_00419d50(&local_90,&local_90,0x21,local_b0);
    local_2c[0] = local_90;
    local_2c[1] = uStack_8c;
    local_2c[2] = uStack_88;
    local_2c[3] = uStack_84;
    puVar12 = local_b0;
    for (iVar5 = 0x41; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (uint *)((int)puVar12 + 1);
    }
    local_54 = local_58 + 0x16;
    local_1c = local_80;
    uStack_18 = uStack_7c;
    uStack_14 = uStack_78;
    uStack_10 = uStack_74;
    local_68.dwLowDateTime = 0;
    local_68.dwHighDateTime = 0;
    GetSystemTime(&local_40);
    SystemTimeToFileTime(&local_40,&local_68);
    puVar12 = local_58;
    this_01 = local_60;
    uVar9 = local_68.dwLowDateTime + 0x2ac18000;
    uVar7 = local_68.dwHighDateTime + 0xfe624e21 + (uint)(0xd53e7fff < local_68.dwLowDateTime);
    _Var4.dwHighDateTime = (DWORD)((ulonglong)uVar9 * 0xd6bf94d5 >> 0x20);
    _Var4.dwLowDateTime = (DWORD)((ulonglong)uVar9 * 0xe57a42bd);
    lVar1 = (ulonglong)uVar7 * 0xd6bf94d5;
    local_5c = (undefined4)lVar1;
    uVar2 = (ulonglong)uVar7 * 0xe57a42bd + ((ulonglong)uVar9 * 0xe57a42bd >> 0x20);
    uVar10 = (uint)(uVar2 >> 0x20);
    lVar3 = (ulonglong)uVar9 * 0xd6bf94d5 + (uVar2 & 0xffffffff);
    local_40._8_4_ = SUB84(lVar3,0);
    uVar7 = (uint)((ulonglong)lVar3 >> 0x20);
    lVar1 = lVar1 + (ulonglong)CONCAT14(CARRY4(uVar10,uVar7),uVar10 + uVar7);
    uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
    uVar10 = (uint)lVar1 >> 0x17 | uVar8 * 0x200;
    uVar7 = uVar10 + 10;
    local_54[1] = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    uVar7 = (uVar8 >> 0x17) + 0x40000000 + (uint)(0xfffffff5 < uVar10);
    *local_54 = uVar7 >> 0x18 | (uVar7 & 0xff00) << 8 | uVar7 * 0x1000000;
    uVar7 = (uVar9 + uVar10 * -10000000) * 100;
    local_54[2] = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | local_68.dwLowDateTime * 0x64000000;
    local_68 = _Var4;
    iVar5 = FUN_0042b0f0(local_60,(undefined2 *)(local_58 + 0x1a));
    local_60 = *(int **)(*this_01 + 0x18);
    if (local_60 != (int *)0x0) {
      iVar6 = (**(code **)(*local_60 + 0x18))(this_01,(int)puVar12 + iVar5 + 0x68,0x560 - iVar5,puVar12 + 2);
      iVar5 = iVar5 + iVar6;
    }
    if (iVar5 != 0) {
      puVar12[0x19] = 0x5354;
      iVar5 = iVar5 + 4;
    }
    puVar12 = (uint *)(this_01 + 0x37);
    FUN_0041c930(local_54,local_54,iVar5 + 0xc,puVar12,0x20,0,0,local_2c);
    FUN_00429550(puVar12,puVar12,0x20,local_54,iVar5 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar5 + 0x94;
    uVar7 = FUN_00429490((void *)*this_01,(uint)this_01,0);
    local_58[1] = uVar7;
    puVar12 = local_2c;
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    *local_58 = 1;
    FUN_0042b590(this_01,local_58,(uint *)((int)local_58 + iVar5 + 0x74));
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
LAB_00429e5f:
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}


// ----- caller: FUN_00416db0 @ 00416db0

void __thiscall FUN_00416db0(void *this,void *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  _SINGLE_LIST_ENTRY *p_Var4;
  _SINGLE_LIST_ENTRY *p_Var5;
  _SINGLE_LIST_ENTRY *p_Var6;
  char cVar7;
  uint extraout_EAX;
  PSINGLE_LIST_ENTRY p_Var8;
  int extraout_EDX;
  int iStack_14;
  
  GetTickCount64();
  if ((extraout_EDX - *(int *)((int)param_1 + 0x54) != (uint)(extraout_EAX < *(uint *)((int)param_1 + 0x50))) ||
     (1999 < extraout_EAX - *(uint *)((int)param_1 + 0x50))) {
    *(uint *)((int)param_1 + 0x50) = extraout_EAX;
    *(int *)((int)param_1 + 0x54) = extraout_EDX;
    if ((*(short *)((int)param_1 + 0x68) != 0) &&
       (((*(int **)((int)this + 0x38) == (int *)0x0 ||
         (cVar7 = (**(code **)(**(int **)((int)this + 0x38) + 0x14))(param_1), cVar7 != '\0')) &&
        (p_Var8 = FUN_0040e6a0(), p_Var8 != (PSINGLE_LIST_ENTRY)0x0)))) {
      FUN_00429db0(param_1,(int)p_Var8);
      *(int *)((int)this + 0x22cc) = *(int *)((int)this + 0x22cc) + 1;
      *(int *)((int)param_1 + 0xa0) = *(int *)((int)param_1 + 0xa0) + 1;
      iVar3 = *(int *)((int)param_1 + 0xa0);
      if (*(int **)this != (int *)0x0) {
        (**(code **)(**(int **)this + 4))(iVar3);
      }
      p_Var4 = *(_SINGLE_LIST_ENTRY **)((int)param_1 + 0x6c);
      p_Var5 = *(_SINGLE_LIST_ENTRY **)((int)param_1 + 0x70);
      p_Var6 = *(_SINGLE_LIST_ENTRY **)((int)param_1 + 0x74);
      *(uint *)((int)param_1 + 0x20) = *(uint *)((int)param_1 + 0x20) & 0xffffff7d | 0x440;
      p_Var8[10].Next = *(_SINGLE_LIST_ENTRY **)((int)param_1 + 0x68);
      p_Var8[0xb].Next = p_Var4;
      p_Var8[0xc].Next = p_Var5;
      p_Var8[0xd].Next = p_Var6;
      *(undefined8 *)(p_Var8 + 0xe) = *(undefined8 *)((int)param_1 + 0x78);
      p_Var8[0x10].Next = *(_SINGLE_LIST_ENTRY **)((int)param_1 + 0x80);
      *(undefined1 *)((int)&p_Var8[9].Next + 1) = *(undefined1 *)((int)param_1 + 0x3b);
      p_Var4 = p_Var8[7].Next;
      puVar1 = (uint *)((int)param_1 + 0xd0);
      uVar2 = *puVar1;
      *puVar1 = (int)&p_Var4->Next + *puVar1;
      *(int *)((int)param_1 + 0xd4) = *(int *)((int)param_1 + 0xd4) + (uint)CARRY4(uVar2,(uint)p_Var4);
      if (((2 < iVar3) && (*(char *)((int)param_1 + 0x35) != '\0')) && (*(char *)((int)param_1 + 0x3b) < '\0')) {
        *(undefined2 *)((int)param_1 + 0x3b) = 0;
        *(undefined2 *)((int)param_1 + 0x68) = 0;
        *(undefined2 *)((int)param_1 + 0x84) = 0;
      }
      if (*(int **)((int)this + 0x38) != (int *)0x0) {
        (**(code **)(**(int **)((int)this + 0x38) + 0x24))(param_1,p_Var8);
      }
      puVar1 = (uint *)((int)this + 0x2250);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      *(int *)((int)this + 0x2254) = *(int *)((int)this + 0x2254) + (uint)(0xfffffffe < uVar2);
      p_Var4 = p_Var8[7].Next;
      puVar1 = (uint *)((int)this + 0x2260);
      uVar2 = *puVar1;
      *puVar1 = (int)&p_Var4->Next + *puVar1;
      *(int *)((int)this + 0x2264) = *(int *)((int)this + 0x2264) + (uint)CARRY4(uVar2,(uint)p_Var4);
      (**(code **)(**(int **)((int)this + 8) + 4))(p_Var8);
      if (iStack_14 - 2U < 0x13) {
        FUN_0040e0a0("Retrying handshake, attempt %d...%s",(char)iStack_14);
      }
    }
  }
  return;
}


// ----- callee: KERNEL32.DLL::LoadLibraryA @ EXTERNAL:0000005f
// decompile failed: Exception while decompiling EXTERNAL:0000005f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0041c930 @ 0041c930

void __fastcall
FUN_0041c930(uint *param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,undefined4 param_6,undefined4 param_7,
            undefined4 *param_8)

{
  int *extraout_ECX;
  int iVar1;
  int *piVar2;
  uint local_17c [6];
  uint local_164;
  uint local_160;
  uint local_15c;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_9c;
  int local_94 [16];
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_14 [3];
  undefined4 local_8;
  
  FUN_0041c700(local_94,param_8,param_6,param_7);
  FUN_0041c200(extraout_ECX,&local_54,&local_54,0x40);
  FUN_0041c200(local_94,param_1,param_2,param_3);
  local_bc = local_44;
  local_b8 = local_40;
  local_b4 = local_3c;
  local_b0 = local_38;
  local_17c[5] = local_54 & 0xfffffff;
  local_17c[0] = 0;
  local_164 = local_50 & 0xffffffc;
  local_9c = 0;
  local_160 = local_4c & 0xffffffc;
  local_15c = local_48 & 0xffffffc;
  local_17c[1] = 0;
  local_17c[2] = 0;
  local_17c[3] = 0;
  local_17c[4] = 0;
  FUN_0041c520(local_17c,param_4,param_5);
  FUN_0041c520(local_17c,(uint *)&DAT_004481d8,-param_5 & 0xf);
  FUN_0041c520(local_17c,param_1,param_3);
  FUN_0041c520(local_17c,(uint *)&DAT_004481d8,-param_3 & 0xf);
  local_14[0] = param_5;
  local_14[1] = 0;
  local_14[2] = param_3;
  local_8 = 0;
  FUN_0041c520(local_17c,local_14,0x10);
  FUN_0041c5e0(local_17c,(int *)((int)param_1 + param_3));
  piVar2 = local_94;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  return;
}


// ----- callee: FUN_00419d50 @ 00419d50

void __thiscall FUN_00419d50(void *this,uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint local_e4 [4];
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint local_c4 [4];
  uint local_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  ulonglong local_a4;
  ulonglong uStack_9c;
  ulonglong local_94;
  ulonglong uStack_8c;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  
  local_c4[0] = *param_3 ^ 0x36363636;
  local_c4[1] = param_3[1] ^ 0x36363636;
  local_c4[2] = param_3[2] ^ 0x36363636;
  local_c4[3] = param_3[3] ^ 0x36363636;
  local_b4 = param_3[4] ^ 0x36363636;
  uStack_b0 = param_3[5] ^ 0x36363636;
  uStack_ac = param_3[6] ^ 0x36363636;
  uStack_a8 = param_3[7] ^ 0x36363636;
  local_a4 = 0x3636363636363636;
  uStack_9c = 0x3636363636363636;
  local_94 = 0x3636363636363636;
  uStack_8c = 0x3636363636363636;
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,local_c4,0x40);
  FUN_00419bc0(local_84,param_1,param_2);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  local_e4[0] = local_84[0];
  local_e4[1] = local_84[1];
  local_e4[2] = local_84[2];
  local_e4[3] = local_84[3];
  local_d4 = local_84[4];
  uStack_d0 = local_84[5];
  uStack_cc = local_84[6];
  uStack_c8 = uStack_68;
  local_c4[0] = local_c4[0] ^ 0x6a6a6a6a;
  local_c4[1] = local_c4[1] ^ 0x6a6a6a6a;
  local_c4[2] = local_c4[2] ^ 0x6a6a6a6a;
  local_c4[3] = local_c4[3] ^ 0x6a6a6a6a;
  local_b4 = local_b4 ^ 0x6a6a6a6a;
  uStack_b0 = uStack_b0 ^ 0x6a6a6a6a;
  uStack_ac = uStack_ac ^ 0x6a6a6a6a;
  uStack_a8 = uStack_a8 ^ 0x6a6a6a6a;
  local_a4 = local_a4 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_9c = uStack_9c ^ 0x6a6a6a6a6a6a6a6a;
  local_94 = local_94 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_8c = uStack_8c ^ 0x6a6a6a6a6a6a6a6a;
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,local_c4,0x40);
  FUN_00419bc0(local_84,local_e4,0x20);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  puVar6 = local_c4;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = local_e4;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  return;
}


// ----- callee: KERNEL32.DLL::SystemTimeToFileTime @ EXTERNAL:0000005d
// decompile failed: Exception while decompiling EXTERNAL:0000005d: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0042b0f0 @ 0042b0f0

undefined4 __thiscall FUN_0042b0f0(void *this,undefined2 *param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = param_1;
  iVar3 = 0;
  param_1 = (undefined2 *)0x0;
  do {
    if (*(char *)((int)this + iVar3 + 0x3d) != '\0') {
      uVar5 = 0;
      *puVar2 = 0x201;
      iVar3 = 0;
      do {
        bVar1 = (byte)iVar3;
        iVar3 = iVar3 + 2;
        bVar1 = (-((uVar5 & 3) != 0) & param_1._3_1_) + (*(char *)((int)this + uVar5 + 0x3d) << (bVar1 & 7));
        param_1 = (undefined2 *)((uint)bVar1 << 0x18);
        uVar4 = uVar5 >> 2;
        uVar5 = uVar5 + 1;
        *(byte *)(uVar4 + 2 + (int)puVar2) = bVar1;
      } while (iVar3 != 0xe);
      bVar1 = *(byte *)((int)puVar2 + 3);
      *(byte *)((int)puVar2 + 3) = (bVar1 >> 2 & 3) + (bVar1 & 3) * '\x04' + (bVar1 & 0xf0);
      return 4;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 7);
  return 0;
}


// ----- callee: KERNEL32.DLL::GetProcAddress @ EXTERNAL:0000005e
// decompile failed: Exception while decompiling EXTERNAL:0000005e: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_004200c0 @ 004200c0

void __fastcall FUN_004200c0(undefined1 *param_1,byte *param_2,byte *param_3)

{
  uint local_210 [20];
  uint local_1c0 [20];
  uint local_170 [20];
  uint local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  byte local_2c;
  byte bStack_2b;
  byte bStack_2a;
  byte bStack_29;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte local_1c;
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  bStack_2b = param_2[1];
  bStack_2a = param_2[2];
  bStack_29 = param_2[3];
  bStack_28 = param_2[4];
  bStack_27 = param_2[5];
  bStack_26 = param_2[6];
  bStack_25 = param_2[7];
  bStack_24 = param_2[8];
  bStack_23 = param_2[9];
  bStack_22 = param_2[10];
  bStack_21 = param_2[0xb];
  bStack_20 = param_2[0xc];
  bStack_1f = param_2[0xd];
  bStack_1e = param_2[0xe];
  bStack_1d = param_2[0xf];
  local_1c = param_2[0x10];
  bStack_1b = param_2[0x11];
  bStack_1a = param_2[0x12];
  bStack_19 = param_2[0x13];
  bStack_18 = param_2[0x14];
  bStack_17 = param_2[0x15];
  bStack_16 = param_2[0x16];
  bStack_15 = param_2[0x17];
  bStack_14 = param_2[0x18];
  bStack_13 = param_2[0x19];
  bStack_12 = param_2[0x1a];
  bStack_11 = param_2[0x1b];
  bStack_10 = param_2[0x1c];
  bStack_f = param_2[0x1d];
  bStack_e = param_2[0x1e];
  local_2c = *param_2 & 0xf8;
  bStack_d = param_2[0x1f] & 0x3f | 0x40;
  FUN_0041d7f0(local_170,param_3);
  FUN_0041e920(local_210,&local_88,(int)&local_2c,local_170);
  FUN_0041ec90(local_1c0,(int *)&local_88);
  FUN_0041cd80((longlong *)&local_120,(int *)local_210,(int *)local_1c0);
  FUN_0041d250(&local_120);
  FUN_0041d330(&local_120);
  local_88 = local_120;
  uStack_84 = uStack_11c;
  uStack_80 = uStack_118;
  uStack_7c = uStack_114;
  local_78 = local_110;
  uStack_74 = uStack_10c;
  uStack_70 = uStack_108;
  uStack_6c = uStack_104;
  local_68 = local_100;
  uStack_64 = uStack_fc;
  uStack_60 = uStack_f8;
  uStack_5c = uStack_f4;
  local_58 = local_f0;
  uStack_54 = uStack_ec;
  uStack_50 = uStack_e8;
  uStack_4c = uStack_e4;
  local_48 = local_e0;
  uStack_44 = uStack_dc;
  uStack_40 = uStack_d8;
  uStack_3c = uStack_d4;
  FUN_0041d330(&local_88);
  FUN_0041daf0(param_1,(int *)&local_88);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: __security_check_cookie @ 0042cf7c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 != DAT_0044f008) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_00429550 @ 00429550

void __thiscall FUN_00429550(void *this,uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  uint local_8;
  
  local_8 = DAT_0044f008 ^ (uint)(local_54 + 0x14);
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,param_1,param_2);
  FUN_00419bc0(local_84,param_3,param_4);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  __security_check_cookie(local_8 ^ (uint)(local_54 + 0x14));
  return;
}


// ----- callee: KERNEL32.DLL::GetSystemTime @ EXTERNAL:0000005c
// decompile failed: Exception while decompiling EXTERNAL:0000005c: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::ExitProcess @ EXTERNAL:0000006c
// decompile failed: Exception while decompiling EXTERNAL:0000006c: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_00429490 @ 00429490

uint __thiscall FUN_00429490(void *this,uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int local_10 [2];
  uint local_8;
  
  do {
    do {
      uVar3 = (uint)*(byte *)((int)this + 0x84);
      if (uVar3 == 0) {
        puVar5 = (uint *)((int)this + 0x140);
        FUN_00419c70((uint *)((int)this + 0x168),0x20,puVar5,0x28,(uint *)0x0,0);
        uVar3 = 8;
        uVar1 = *puVar5;
        *puVar5 = *puVar5 + 1;
        *(int *)((int)this + 0x144) = *(int *)((int)this + 0x144) + (uint)(0xfffffffe < uVar1);
      }
      *(char *)((int)this + 0x84) = (char)(uVar3 - 1);
      local_8 = *(uint *)((int)this + (uVar3 - 1) * 4 + 0x168);
    } while (local_8 == 0);
    piVar4 = (int *)FUN_0042c8f0((void *)((int)this + 0x1c),local_10,&local_8);
    iVar2 = *piVar4;
  } while (*(int *)(iVar2 + 0xc) != 0);
  *(uint *)(iVar2 + 0xc) = param_1;
  *(int *)(iVar2 + 0x10) = param_2;
  puVar5 = (uint *)(param_2 + 0x18);
  if (param_2 == 0) {
    puVar5 = (uint *)(param_1 + 0x24);
  }
  param_1 = *puVar5;
  *puVar5 = local_8;
  if (param_1 == 0) {
    return local_8;
  }
  FUN_0042c360((void *)((int)this + 0x1c),&param_1);
  return local_8;
}


// ----- callee: FUN_0042b590 @ 0042b590

void __thiscall FUN_0042b590(void *this,uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  int extraout_EDX;
  uint *puVar5;
  uint local_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  char local_c;
  int *local_8;
  
  *(undefined1 *)((int)this + 0x36) = 1;
  local_8 = this;
  FUN_00418620(&local_84,0x10,(uint *)((int)this + 0x1cc),0x20);
  FUN_00419bc0(&local_84,param_1,(int)param_2 - (int)param_1);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(&local_84,local_54);
  *param_2 = local_84;
  param_2[1] = uStack_80;
  param_2[2] = uStack_7c;
  param_2[3] = uStack_78;
  *(uint *)((int)this + 0x1ec) = local_84;
  *(uint *)((int)this + 0x1f0) = uStack_80;
  *(uint *)((int)this + 500) = uStack_7c;
  *(uint *)((int)this + 0x1f8) = uStack_78;
  if (*(char *)((int)this + 0x38) != '\0') {
    GetTickCount64();
    if ((extraout_EDX - *(int *)((int)this + 0x214) == (uint)(extraout_EAX < *(uint *)((int)this + 0x210))) &&
       (extraout_EAX - *(uint *)((int)this + 0x210) < 0x1c138)) {
      FUN_00418620(&local_84,0x10,(uint *)((int)this + 0x1fc),0x10);
      FUN_00419bc0(&local_84,param_1,((int)param_2 - (int)param_1) + 0x10);
      local_64 = local_64 + local_14;
      local_5c = 0xffffffff;
      local_60 = local_60 + (uint)(local_64 < local_14);
      if (local_c != '\0') {
        local_58 = 0xffffffff;
      }
      _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
      FUN_004186e0(&local_84,local_54);
      param_2[4] = local_84;
      param_2[5] = uStack_80;
      param_2[6] = uStack_7c;
      param_2[7] = uStack_78;
      return;
    }
  }
  puVar5 = param_2 + 4;
  *(undefined1 *)((int)this + 0x38) = 0;
  if (*(char *)(*(int *)this + 0x188) == '\0') {
    *puVar5 = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    return;
  }
  param_1 = (uint *)0x4;
  do {
    iVar3 = *(int *)this;
    uVar4 = (uint)*(byte *)(iVar3 + 0x84);
    if (uVar4 == 0) {
      puVar1 = (uint *)(iVar3 + 0x140);
      FUN_00419c70((uint *)(iVar3 + 0x168),0x20,puVar1,0x28,(uint *)0x0,0);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      uVar4 = 8;
      *(int *)(iVar3 + 0x144) = *(int *)(iVar3 + 0x144) + (uint)(0xfffffffe < uVar2);
      this = local_8;
    }
    *(char *)(iVar3 + 0x84) = (char)(uVar4 - 1);
    *puVar5 = *(uint *)(iVar3 + 0x168 + (uVar4 - 1) * 4);
    puVar5 = puVar5 + 1;
    param_1 = (uint *)((int)param_1 + -1);
  } while (param_1 != (uint *)0x0);
  return;
}



// ===================== FUN_0042a220 @ 0042a220  anchors: [ObfuscateKey(win@004482b4), ObfuscateKey(win@004482c4), ObfuscateKey(win@004482d4), ObfuscateKey(win@004482e4)] =====================

void __fastcall FUN_0042a220(void *param_1,int param_2)

{
  void *this;
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  uint extraout_EAX;
  HMODULE hModule;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  uint extraout_EDX;
  uint uVar11;
  uint *puVar12;
  bool bVar13;
  undefined8 uVar14;
  char *lpProcName;
  uint local_6b4 [8];
  uint local_694;
  undefined4 uStack_690;
  undefined4 uStack_68c;
  undefined4 uStack_688;
  undefined4 local_684;
  undefined4 uStack_680;
  undefined4 uStack_67c;
  uint uStack_678;
  undefined1 local_674;
  uint *local_66c;
  int local_668;
  uint *local_664;
  uint *local_660;
  uint local_65c [4];
  undefined4 local_64c;
  undefined4 uStack_648;
  undefined4 uStack_644;
  uint uStack_640;
  uint local_63c;
  uint uStack_638;
  uint uStack_634;
  uint uStack_630;
  uint local_62c;
  uint uStack_628;
  uint uStack_624;
  uint uStack_620;
  undefined8 local_61c;
  undefined4 local_614;
  uint local_610 [346];
  uint local_a8 [4];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  uint uStack_8c;
  uint local_88 [8];
  uint local_68 [4];
  uint local_58 [4];
  uint local_48 [17];
  
  local_48[0x10] = DAT_0044f008 ^ (uint)(local_48 + 0x11);
  local_48[8] = 0xae6de260;
  local_48[9] = 0xc0ef27f3;
  local_48[10] = 0xe235c32e;
  local_48[0xb] = 0xd0d225a0;
  puVar9 = *(uint **)(param_2 + 0x20);
  local_48[0xc] = 0x642eb16;
  local_48[0xd] = 0xf57772f8;
  local_48[0xe] = 0x98d1382d;
  local_48[0xf] = 0x36cd788b;
  local_48[0] = 0x61b31122;
  local_48[1] = 0x66c51a08;
  local_48[2] = 0xdb431269;
  local_48[3] = 0x32d58a45;
  local_48[4] = 0x666c9c2d;
  local_48[5] = 0xb7e89322;
  local_48[6] = 0x659ce10e;
  local_48[7] = 0xf39e07ba;
  local_668 = param_2;
  local_664 = puVar9;
  FUN_00429550(local_48,local_48,0x20,(uint *)((int)param_1 + 0xe0),0x20);
  local_660 = puVar9 + 2;
  FUN_00419d50(local_6b4,local_660,0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  local_48[0xf] = uStack_678;
  local_48[0xe] = uStack_67c;
  local_48[0xd] = uStack_680;
  local_48[0xc] = local_684;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  puVar10 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar10 = 0;
    puVar10 = (uint *)((int)puVar10 + 1);
  }
  FUN_00429550(local_48,local_48,0x20,puVar9 + 2,0x20);
  FUN_004200c0((undefined1 *)local_68,(byte *)((int)param_1 + 0xc0),(byte *)(puVar9 + 2));
  FUN_00419d50(local_6b4,local_68,0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  local_674 = 2;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  local_48[0xc] = local_684;
  local_48[0xd] = uStack_680;
  local_48[0xe] = uStack_67c;
  local_48[0xf] = uStack_678;
  FUN_00419d50(&local_694,&local_694,0x21,local_6b4);
  uStack_640 = uStack_678;
  uStack_644 = uStack_67c;
  uStack_648 = uStack_680;
  local_64c = local_684;
  local_65c[0] = local_694;
  local_65c[1] = uStack_690;
  local_65c[2] = uStack_68c;
  local_65c[3] = uStack_688;
  puVar10 = local_6b4;
  local_66c = puVar9 + 10;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar10 = 0;
    puVar10 = (uint *)((int)puVar10 + 1);
  }
  puVar10 = local_68;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  FUN_0041caa0(&local_63c,puVar9 + 10,0x20,local_48,0x20,0,0,local_65c,(int *)local_58);
  iVar7 = 0x10;
  puVar9 = puVar9 + 0x12;
  puVar10 = local_58;
  uVar11 = 0;
  iVar8 = 4;
  do {
    uVar6 = *puVar10;
    iVar7 = iVar7 + -4;
    puVar10 = puVar10 + 1;
    uVar11 = uVar11 | uVar6 ^ *puVar9;
    puVar9 = puVar9 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    uVar6 = *puVar10;
    puVar10 = (uint *)((int)puVar10 + 1);
    uVar11 = uVar11 | (byte)((byte)uVar6 ^ (byte)*puVar9);
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  if (uVar11 != 0) {
LAB_0042abac:
    puVar9 = local_48;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    puVar9 = local_48 + 8;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    puVar9 = local_65c;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    puVar9 = local_a8;
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    __security_check_cookie(local_48[0x10] ^ (uint)(local_48 + 0x11));
    return;
  }
  FUN_00429550(local_48,local_48,0x20,local_66c,0x30);
  iVar7 = local_668;
  while( true ) {
    uVar14 = FUN_0040a7f0(local_63c,uStack_638,uStack_634,uStack_630,local_62c,uStack_628,uStack_624,uStack_620);
    iVar8 = FUN_0042c760((void *)((int)param_1 + 0x5c),(int *)(local_58 + 2),(int *)&local_63c,(uint)uVar14);
    iVar8 = *(int *)(iVar8 + 4);
    if (iVar8 == 0) {
      iVar8 = *(int *)((int)param_1 + 0x60);
    }
    if ((iVar8 != *(int *)((int)param_1 + 0x60)) && (this = *(void **)(iVar8 + 0x28), this != (void *)0x0)) break;
    if ((*(int **)((int)param_1 + 0x18) == (int *)0x0) ||
       (cVar4 = (**(code **)(**(int **)((int)param_1 + 0x18) + 4))(&local_63c,iVar7), cVar4 == '\0')) goto LAB_0042abac;
  }
  FUN_00419d50(local_6b4,(uint *)((int)this + 0x180),0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  local_674 = 2;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  local_48[0xc] = local_684;
  local_48[0xd] = uStack_680;
  local_48[0xe] = uStack_67c;
  local_48[0xf] = uStack_678;
  FUN_00419d50(&local_694,&local_694,0x21,local_6b4);
  uStack_640 = uStack_678;
  uStack_644 = uStack_67c;
  uStack_648 = uStack_680;
  local_64c = local_684;
  local_65c[0] = local_694;
  local_65c[1] = uStack_690;
  local_65c[2] = uStack_68c;
  local_65c[3] = uStack_688;
  puVar9 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar9 = 0;
    puVar9 = (uint *)((int)puVar9 + 1);
  }
  local_66c = (uint *)(*(int *)(local_668 + 0x1c) - 0x94);
  local_63c = local_48[0];
  uStack_638 = local_48[1];
  uStack_634 = local_48[2];
  uStack_630 = local_48[3];
  local_62c = local_48[4];
  uStack_628 = local_48[5];
  uStack_624 = local_48[6];
  uStack_620 = local_48[7];
  if ((uint *)0x564 < local_66c) goto LAB_0042abac;
  uVar11 = *(int *)(local_668 + 0x1c) - 0x78;
  puVar9 = local_664 + 0x16;
  FUN_00429550(local_48,local_48,0x20,puVar9,uVar11);
  uVar11 = FUN_0041cc10(&local_61c,puVar9,uVar11,&local_63c,0x20,0,0,local_65c);
  if ((char)uVar11 == '\0') goto LAB_0042abac;
  puVar9 = (uint *)&local_61c;
  uVar11 = 8;
  puVar10 = (uint *)((int)this + 0x1a0);
  do {
    if (*puVar9 != *puVar10) {
      iVar7 = (*puVar9 & 0xff) - (uint)(byte)*puVar10;
      if (((iVar7 == 0) && (iVar7 = (uint)*(byte *)((int)puVar9 + 1) - (uint)*(byte *)((int)puVar10 + 1), iVar7 == 0))
         && (iVar7 = (uint)*(byte *)((int)puVar9 + 2) - (uint)*(byte *)((int)puVar10 + 2), iVar7 == 0)) {
        iVar7 = (uint)*(byte *)((int)puVar9 + 3) - (uint)*(byte *)((int)puVar10 + 3);
      }
      goto LAB_0042a661;
    }
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
    bVar13 = 3 < uVar11;
    uVar11 = uVar11 - 4;
  } while (bVar13);
  iVar7 = 0;
LAB_0042a661:
  if (iVar7 < 1) goto LAB_0042abac;
  GetTickCount64();
  puVar9 = local_664;
  uVar11 = *(int *)((int)this + 100) + (uint)(0xffffffeb < *(uint *)((int)this + 0x60));
  if ((extraout_EDX < uVar11) || ((extraout_EDX <= uVar11 && (extraout_EAX < *(uint *)((int)this + 0x60) + 0x14))))
  goto LAB_0042abac;
  *(uint *)((int)this + 0x60) = extraout_EAX;
  *(uint *)((int)this + 100) = extraout_EDX;
  *(undefined8 *)((int)this + 0x1a0) = local_61c;
  *(undefined4 *)((int)this + 0x1a8) = local_614;
  local_63c = *local_660;
  uStack_638 = local_660[1];
  uStack_634 = local_660[2];
  uStack_630 = local_660[3];
  local_62c = local_660[4];
  uStack_628 = local_660[5];
  uStack_624 = local_660[6];
  uStack_620 = local_660[7];
  uVar11 = local_664[1];
  *local_660 = uVar11;
  local_660 = (uint *)uVar11;
  if (DAT_00451dbc == (FARPROC)0x0) {
    lpProcName = "SystemFunction036";
    hModule = LoadLibraryA("ADVAPI32.DLL");
    DAT_00451dbc = GetProcAddress(hModule,lpProcName);
    if (DAT_00451dbc == (FARPROC)0x0) goto LAB_0042a713;
  }
  iVar7 = (*DAT_00451dbc)(local_65c,0x20);
  if ((char)iVar7 == '\0') {
LAB_0042a713:
                    /* WARNING: Subroutine does not return */
    ExitProcess(1);
  }
  puVar10 = puVar9 + 3;
  local_65c[0] = local_65c[0] & 0xfffffff8;
  uStack_640 = uStack_640 & 0x3fffffff | 0x40000000;
  FUN_004200c0((undefined1 *)puVar10,(byte *)local_65c,&DAT_004481e8);
  FUN_00429550(local_48,local_48,0x20,puVar10,0x20);
  FUN_00419d50(local_6b4,puVar10,0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  local_48[0xf] = uStack_678;
  local_48[0xe] = uStack_67c;
  local_48[0xd] = uStack_680;
  local_48[0xc] = local_684;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  puVar12 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((int)puVar12 + 1);
  }
  FUN_004200c0((undefined1 *)local_88,(byte *)local_65c,(byte *)&local_63c);
  FUN_00419d50(local_6b4,local_88,0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  uVar11 = uStack_678;
  uVar3 = uStack_67c;
  uVar2 = uStack_680;
  uVar5 = local_684;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  puVar12 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((int)puVar12 + 1);
  }
  puVar12 = local_88;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  local_48[0xc] = uVar5;
  local_48[0xd] = uVar2;
  local_48[0xe] = uVar3;
  local_48[0xf] = uVar11;
  FUN_004200c0((undefined1 *)local_88,(byte *)local_65c,(byte *)((int)this + 0x140));
  FUN_00419d50(local_6b4,local_88,0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  uVar11 = uStack_678;
  uVar3 = uStack_67c;
  uVar2 = uStack_680;
  uVar5 = local_684;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  puVar12 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((int)puVar12 + 1);
  }
  puVar12 = local_88;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  local_48[0xc] = uVar5;
  local_48[0xd] = uVar2;
  local_48[0xe] = uVar3;
  local_48[0xf] = uVar11;
  FUN_00419d50(local_6b4,(uint *)((int)this + 0x160),0x20,local_48 + 8);
  local_694 = CONCAT31(local_694._1_3_,1);
  FUN_00419d50(&local_694,&local_694,1,local_6b4);
  local_674 = 2;
  local_48[8] = local_694;
  local_48[9] = uStack_690;
  local_48[10] = uStack_68c;
  local_48[0xb] = uStack_688;
  local_48[0xc] = local_684;
  local_48[0xd] = uStack_680;
  local_48[0xe] = uStack_67c;
  local_48[0xf] = uStack_678;
  FUN_00419d50(&local_694,&local_694,0x21,local_6b4);
  local_674 = 3;
  local_a8[0] = local_694;
  local_a8[1] = uStack_690;
  local_a8[2] = uStack_68c;
  local_a8[3] = uStack_688;
  local_98 = local_684;
  uStack_94 = uStack_680;
  uStack_90 = uStack_67c;
  uStack_8c = uStack_678;
  FUN_00419d50(&local_694,&local_694,0x21,local_6b4);
  local_65c[0] = local_694;
  local_65c[1] = uStack_690;
  local_65c[2] = uStack_68c;
  local_65c[3] = uStack_688;
  puVar12 = local_6b4;
  for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar12 = 0;
    puVar12 = (uint *)((int)puVar12 + 1);
  }
  local_64c = local_684;
  uStack_648 = uStack_680;
  uStack_644 = uStack_67c;
  uStack_640 = uStack_678;
  FUN_00429550(local_48,local_48,0x20,local_a8,0x20);
  local_660 = FUN_0042b2e0(0,local_48 + 8,local_660);
  if (local_660 == (uint *)0x0) goto LAB_0042abac;
  uVar5 = FUN_0042b1c0(this,(int)local_660,local_610,(uint)local_66c);
  if ((char)uVar5 == '\0') {
LAB_0042ab96:
    FUN_0042cf8d(local_660);
  }
  else {
    uVar11 = 0;
    if (local_66c != (uint *)0x0) {
      uVar11 = FUN_0042b0f0(this,(undefined2 *)(puVar9 + 0xc));
    }
    if (*(int **)((int)param_1 + 0x18) != (int *)0x0) {
      uVar6 = (**(code **)(**(int **)((int)param_1 + 0x18) + 0x1c))
                        (this,local_610,local_66c,&local_63c,(int)local_664 + uVar11 + 0x30,0x560 - uVar11,puVar10);
      puVar9 = local_660;
      if (uVar6 == 0xffffffff) goto LAB_0042ab96;
      if ((int)uVar6 < 0) {
        local_660 = (uint *)0x0;
        FUN_0042cf8d(puVar9);
      }
      uVar11 = uVar11 + (uVar6 & 0x7fffffff);
    }
    if (uVar11 != 0) {
      uVar11 = uVar11 + 4;
      local_664[0xb] = 0x5354;
    }
    if (local_660 == (uint *)0x0) {
      local_664[1] = 0;
      uVar1 = *(uint *)(local_668 + 0x1c);
      puVar9 = (uint *)((int)this + 200);
      uVar6 = *puVar9;
      *puVar9 = *puVar9 + uVar1;
      *(int *)((int)this + 0xcc) = *(int *)((int)this + 0xcc) + (uint)CARRY4(uVar6,uVar1);
      puVar9 = local_664;
    }
    else {
      uVar6 = FUN_00429490(param_1,(uint)this,(int)local_660);
      puVar9 = local_664;
      local_664[1] = uVar6;
      uVar1 = *(uint *)(local_668 + 0x1c);
      puVar10 = (uint *)((int)this + 200);
      uVar6 = *puVar10;
      *puVar10 = *puVar10 + uVar1;
      *(int *)((int)this + 0xcc) = *(int *)((int)this + 0xcc) + (uint)CARRY4(uVar6,uVar1);
      if ((*(char *)((int)this + 0x35) != '\0') && (*(char *)((int)local_660 + 0x11) != '\0')) {
        uVar5 = *(undefined4 *)(local_668 + 0x2c);
        uVar2 = *(undefined4 *)(local_668 + 0x30);
        uVar3 = *(undefined4 *)(local_668 + 0x34);
        *(undefined4 *)((int)this + 0x68) = *(undefined4 *)(local_668 + 0x28);
        *(undefined4 *)((int)this + 0x6c) = uVar5;
        *(undefined4 *)((int)this + 0x70) = uVar2;
        *(undefined4 *)((int)this + 0x74) = uVar3;
        *(undefined8 *)((int)this + 0x78) = *(undefined8 *)(local_668 + 0x38);
        *(undefined4 *)((int)this + 0x80) = *(undefined4 *)(local_668 + 0x40);
        *(undefined1 *)((int)this + 0x3b) = *(undefined1 *)(local_668 + 0x25);
      }
      FUN_0042b430(this,(int *)local_660);
      *(uint *)((int)this + 0x20) = *(uint *)((int)this + 0x20) & 0xfffffefb | 0x600;
    }
    uVar6 = uVar11 + 0x5c;
    *(uint *)(local_668 + 0x1c) = uVar6;
    puVar10 = (uint *)((int)this + 0xd0);
    uVar1 = *puVar10;
    *puVar10 = *puVar10 + uVar6;
    *(int *)((int)this + 0xd4) = *(int *)((int)this + 0xd4) + (uint)CARRY4(uVar1,uVar6);
    FUN_0041c930(puVar9 + 0xb,puVar9 + 0xb,uVar11,local_48,0x20,0,0,local_65c);
    *puVar9 = 2;
    FUN_0042b590(this,puVar9,(uint *)((int)puVar9 + uVar11 + 0x3c));
  }
  goto LAB_0042abac;
}


// ----- caller: FUN_00416f20 @ 00416f20

void __thiscall FUN_00416f20(void *this,int param_1,char param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 extraout_EAX;
  int *piVar3;
  undefined4 extraout_EAX_00;
  PSINGLE_LIST_ENTRY p_Var4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint *puVar7;
  undefined1 auStack_68 [8];
  uint local_60;
  int *local_5c;
  int local_58 [2];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint local_40 [11];
  uint local_14;
  
  local_14 = DAT_0044f008 ^ (uint)auStack_68;
  uVar5 = *(uint *)(param_1 + 0x1c);
  if (uVar5 < 4) {
LAB_00417257:
    puVar7 = (uint *)((int)this + 0x2268);
    uVar5 = *puVar7;
    *puVar7 = *puVar7 + 1;
    *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
    uVar5 = *(uint *)(param_1 + 0x1c);
  }
  else {
    local_5c = *(int **)(param_1 + 0x20);
    iVar6 = *local_5c;
    if (iVar6 == 4) {
      if (0xf < uVar5) {
        FUN_00417600(this,param_1);
        __security_check_cookie(local_14 ^ (uint)auStack_68);
        return;
      }
      goto LAB_00417257;
    }
    if (iVar6 == 3) {
      if ((uVar5 == 0x40) && (*(char *)((int)this + 0xa5) != '\0')) {
        local_60 = local_5c[1];
        piVar1 = _Find_last<>((void *)((int)this + 0x3c),local_58,(int *)&local_60,local_60);
        piVar3 = local_5c;
        iVar6 = piVar1[1];
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)this + 0x40);
        }
        if ((((iVar6 != *(int *)((int)this + 0x40)) && (*(int *)(iVar6 + 0x10) == 0)) &&
            ((uint *)(iVar6 + 0xc) != (uint *)0x0)) &&
           (local_60 = *(uint *)(iVar6 + 0xc), *(char *)(local_60 + 0x36) != '\0')) {
          FUN_0041b1f0(local_40,(uint *)(local_5c + 2),(uint *)(local_60 + 0x1ac));
          uVar5 = local_60;
          uVar2 = FUN_0041cc10(&local_50,(uint *)(piVar3 + 8),0x20,(uint *)(local_60 + 0x1ec),0x10,piVar3[6],piVar3[7],
                               local_40);
          puVar7 = local_40;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          if ((char)uVar2 != '\0') {
            puVar7 = (uint *)(uVar5 + 200);
            uVar2 = *puVar7;
            *puVar7 = *puVar7 + 0x40;
            *(undefined1 *)(uVar5 + 0x36) = 0;
            *(int *)(uVar5 + 0xcc) = *(int *)(uVar5 + 0xcc) + (uint)(0xffffffbf < uVar2);
            *(undefined1 *)(uVar5 + 0x38) = 1;
            GetTickCount64();
            *(undefined4 *)(uVar5 + 0x210) = extraout_EAX;
            *(undefined4 *)(uVar5 + 0x214) = extraout_EDX;
            *(undefined4 *)(uVar5 + 0x1fc) = local_50;
            *(undefined4 *)(uVar5 + 0x200) = uStack_4c;
            *(undefined4 *)(uVar5 + 0x204) = uStack_48;
            *(undefined4 *)(uVar5 + 0x208) = uStack_44;
          }
        }
        goto LAB_0041727a;
      }
      goto LAB_00417257;
    }
    if (iVar6 == 1) {
      if (uVar5 < 0x94) goto LAB_00417257;
      *(int *)((int)this + 0x22c8) = *(int *)((int)this + 0x22c8) + 1;
      iVar6 = FUN_00417850(this,param_1,param_2);
      if (iVar6 != 0) goto LAB_0041727a;
      local_60 = *(uint *)(param_1 + 0x1c);
      iVar6 = FUN_0042a220((void *)((int)this + 0x20),param_1);
      if (iVar6 != 0) {
        if (*(int **)((int)this + 0x38) != (int *)0x0) {
          (**(code **)(**(int **)((int)this + 0x38) + 0x24))(iVar6,param_1);
        }
        puVar7 = (uint *)((int)this + 0x2250);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x2254) = *(int *)((int)this + 0x2254) + (uint)(0xfffffffe < uVar5);
        uVar2 = *(uint *)(param_1 + 0x1c);
        puVar7 = (uint *)((int)this + 0x2260);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + uVar2;
        *(int *)((int)this + 0x2264) = *(int *)((int)this + 0x2264) + (uint)CARRY4(uVar5,uVar2);
        puVar7 = (uint *)((int)this + 0x2238);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar5);
        puVar7 = (uint *)((int)this + 0x2250);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        puVar7 = (uint *)((int)this + 0x2248);
        uVar2 = *puVar7;
        *puVar7 = *puVar7 + local_60;
        *(uint *)((int)this + 0x2254) = *(int *)((int)this + 0x2254) + (uint)(0xfffffffe < uVar5);
        *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar2,local_60);
        uVar2 = *(uint *)(param_1 + 0x1c);
        puVar7 = (uint *)((int)this + 0x2260);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + uVar2;
        *(uint *)((int)this + 0x2264) = *(int *)((int)this + 0x2264) + (uint)CARRY4(uVar5,uVar2);
        __security_check_cookie(local_14 ^ (uint)auStack_68);
        return;
      }
      puVar7 = (uint *)((int)this + 0x2268);
      uVar5 = *puVar7;
      *puVar7 = *puVar7 + 1;
      *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
      uVar5 = local_60;
    }
    else {
      if ((iVar6 != 2) || (uVar5 < 0x5c)) goto LAB_00417257;
      iVar6 = FUN_00417850(this,param_1,param_2);
      if (iVar6 != 0) goto LAB_0041727a;
      local_60 = *(uint *)(param_1 + 0x1c);
      piVar3 = (int *)FUN_0042abf0((int)this + 0x20,param_1);
      if (piVar3 != (int *)0x0) {
        puVar7 = (uint *)((int)this + 0x2238);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + 1;
        *(int *)((int)this + 0x223c) = *(int *)((int)this + 0x223c) + (uint)(0xfffffffe < uVar5);
        puVar7 = (uint *)((int)this + 0x2248);
        uVar5 = *puVar7;
        *puVar7 = *puVar7 + local_60;
        *(int *)((int)this + 0x224c) = *(int *)((int)this + 0x224c) + (uint)CARRY4(uVar5,local_60);
        *(int *)((int)this + 0x22d4) = *(int *)((int)this + 0x22d4) + 1;
        piVar3[8] = piVar3[8] & 0xfffffefbU | 0x600;
        FUN_0042b770((int)piVar3);
        GetTickCount64();
        *(undefined4 *)((int)this + 0x22a0) = extraout_EAX_00;
        *(undefined4 *)((int)this + 0x22a4) = extraout_EDX_00;
        if (*(int *)((int)this + 0x2298) == 0 && *(int *)((int)this + 0x229c) == 0) {
          *(undefined4 *)((int)this + 0x2298) = extraout_EAX_00;
          *(undefined4 *)((int)this + 0x229c) = extraout_EDX_00;
        }
        if (*(undefined4 **)this != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)this)();
        }
        if ((short)piVar3[0x1a] != 0) {
          if (piVar3[0x12] == 0) {
            p_Var4 = FUN_0040e6a0();
            if (p_Var4 == (PSINGLE_LIST_ENTRY)0x0) goto LAB_0041727a;
            p_Var4[7].Next = (_SINGLE_LIST_ENTRY *)0x0;
            p_Var4->Next = (_SINGLE_LIST_ENTRY *)0x0;
            piVar3[0x12] = (int)p_Var4;
          }
          FUN_00417d90(this,piVar3);
        }
        goto LAB_0041727a;
      }
      puVar7 = (uint *)((int)this + 0x2268);
      uVar5 = *puVar7;
      *puVar7 = *puVar7 + 1;
      *(int *)((int)this + 0x226c) = *(int *)((int)this + 0x226c) + (uint)(0xfffffffe < uVar5);
      uVar5 = local_60;
    }
  }
  puVar7 = (uint *)((int)this + 0x2270);
  uVar2 = *puVar7;
  *puVar7 = *puVar7 + uVar5;
  *(int *)((int)this + 0x2274) = *(int *)((int)this + 0x2274) + (uint)CARRY4(uVar2,uVar5);
LAB_0041727a:
  __security_check_cookie(local_14 ^ (uint)auStack_68);
  return;
}


// ----- callee: KERNEL32.DLL::LoadLibraryA @ EXTERNAL:0000005f
// decompile failed: Exception while decompiling EXTERNAL:0000005f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0042cf8d @ 0042cf8d

void __cdecl FUN_0042cf8d(void *param_1)

{
  thunk_FUN_0042f984(param_1);
  return;
}


// ----- callee: FUN_0041c930 @ 0041c930

void __fastcall
FUN_0041c930(uint *param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,undefined4 param_6,undefined4 param_7,
            undefined4 *param_8)

{
  int *extraout_ECX;
  int iVar1;
  int *piVar2;
  uint local_17c [6];
  uint local_164;
  uint local_160;
  uint local_15c;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_9c;
  int local_94 [16];
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_14 [3];
  undefined4 local_8;
  
  FUN_0041c700(local_94,param_8,param_6,param_7);
  FUN_0041c200(extraout_ECX,&local_54,&local_54,0x40);
  FUN_0041c200(local_94,param_1,param_2,param_3);
  local_bc = local_44;
  local_b8 = local_40;
  local_b4 = local_3c;
  local_b0 = local_38;
  local_17c[5] = local_54 & 0xfffffff;
  local_17c[0] = 0;
  local_164 = local_50 & 0xffffffc;
  local_9c = 0;
  local_160 = local_4c & 0xffffffc;
  local_15c = local_48 & 0xffffffc;
  local_17c[1] = 0;
  local_17c[2] = 0;
  local_17c[3] = 0;
  local_17c[4] = 0;
  FUN_0041c520(local_17c,param_4,param_5);
  FUN_0041c520(local_17c,(uint *)&DAT_004481d8,-param_5 & 0xf);
  FUN_0041c520(local_17c,param_1,param_3);
  FUN_0041c520(local_17c,(uint *)&DAT_004481d8,-param_3 & 0xf);
  local_14[0] = param_5;
  local_14[1] = 0;
  local_14[2] = param_3;
  local_8 = 0;
  FUN_0041c520(local_17c,local_14,0x10);
  FUN_0041c5e0(local_17c,(int *)((int)param_1 + param_3));
  piVar2 = local_94;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  return;
}


// ----- callee: KERNEL32.DLL::GetTickCount64 @ EXTERNAL:00000060
// decompile failed: Exception while decompiling EXTERNAL:00000060: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0041cc10 @ 0041cc10

uint __fastcall
FUN_0041cc10(undefined4 param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,undefined4 param_6,
            undefined4 param_7,undefined4 *param_8)

{
  uint uVar1;
  uint in_EAX;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint local_14 [4];
  
  if (param_3 < 0x10) {
    return in_EAX & 0xffffff00;
  }
  FUN_0041caa0(param_1,param_2,param_3 - 0x10,param_4,param_5,param_6,param_7,param_8,(int *)local_14);
  iVar4 = 0x10;
  puVar2 = local_14;
  puVar5 = (uint *)((param_3 - 0x10) + (int)param_2);
  uVar6 = 0;
  iVar3 = 4;
  do {
    uVar1 = *puVar2;
    iVar4 = iVar4 + -4;
    puVar2 = puVar2 + 1;
    uVar6 = uVar6 | uVar1 ^ *puVar5;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
    uVar6 = uVar6 | (byte)((byte)uVar1 ^ (byte)*puVar5);
    puVar5 = (uint *)((int)puVar5 + 1);
  }
  return CONCAT31((int3)((uint)puVar2 >> 8),uVar6 == 0);
}


// ----- callee: FUN_00419d50 @ 00419d50

void __thiscall FUN_00419d50(void *this,uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint local_e4 [4];
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint local_c4 [4];
  uint local_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  ulonglong local_a4;
  ulonglong uStack_9c;
  ulonglong local_94;
  ulonglong uStack_8c;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  
  local_c4[0] = *param_3 ^ 0x36363636;
  local_c4[1] = param_3[1] ^ 0x36363636;
  local_c4[2] = param_3[2] ^ 0x36363636;
  local_c4[3] = param_3[3] ^ 0x36363636;
  local_b4 = param_3[4] ^ 0x36363636;
  uStack_b0 = param_3[5] ^ 0x36363636;
  uStack_ac = param_3[6] ^ 0x36363636;
  uStack_a8 = param_3[7] ^ 0x36363636;
  local_a4 = 0x3636363636363636;
  uStack_9c = 0x3636363636363636;
  local_94 = 0x3636363636363636;
  uStack_8c = 0x3636363636363636;
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,local_c4,0x40);
  FUN_00419bc0(local_84,param_1,param_2);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  local_e4[0] = local_84[0];
  local_e4[1] = local_84[1];
  local_e4[2] = local_84[2];
  local_e4[3] = local_84[3];
  local_d4 = local_84[4];
  uStack_d0 = local_84[5];
  uStack_cc = local_84[6];
  uStack_c8 = uStack_68;
  local_c4[0] = local_c4[0] ^ 0x6a6a6a6a;
  local_c4[1] = local_c4[1] ^ 0x6a6a6a6a;
  local_c4[2] = local_c4[2] ^ 0x6a6a6a6a;
  local_c4[3] = local_c4[3] ^ 0x6a6a6a6a;
  local_b4 = local_b4 ^ 0x6a6a6a6a;
  uStack_b0 = uStack_b0 ^ 0x6a6a6a6a;
  uStack_ac = uStack_ac ^ 0x6a6a6a6a;
  uStack_a8 = uStack_a8 ^ 0x6a6a6a6a;
  local_a4 = local_a4 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_9c = uStack_9c ^ 0x6a6a6a6a6a6a6a6a;
  local_94 = local_94 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_8c = uStack_8c ^ 0x6a6a6a6a6a6a6a6a;
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,local_c4,0x40);
  FUN_00419bc0(local_84,local_e4,0x20);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  puVar6 = local_c4;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  puVar6 = local_e4;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  return;
}


// ----- callee: FUN_0042b0f0 @ 0042b0f0

undefined4 __thiscall FUN_0042b0f0(void *this,undefined2 *param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = param_1;
  iVar3 = 0;
  param_1 = (undefined2 *)0x0;
  do {
    if (*(char *)((int)this + iVar3 + 0x3d) != '\0') {
      uVar5 = 0;
      *puVar2 = 0x201;
      iVar3 = 0;
      do {
        bVar1 = (byte)iVar3;
        iVar3 = iVar3 + 2;
        bVar1 = (-((uVar5 & 3) != 0) & param_1._3_1_) + (*(char *)((int)this + uVar5 + 0x3d) << (bVar1 & 7));
        param_1 = (undefined2 *)((uint)bVar1 << 0x18);
        uVar4 = uVar5 >> 2;
        uVar5 = uVar5 + 1;
        *(byte *)(uVar4 + 2 + (int)puVar2) = bVar1;
      } while (iVar3 != 0xe);
      bVar1 = *(byte *)((int)puVar2 + 3);
      *(byte *)((int)puVar2 + 3) = (bVar1 >> 2 & 3) + (bVar1 & 3) * '\x04' + (bVar1 & 0xf0);
      return 4;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 7);
  return 0;
}


// ----- callee: KERNEL32.DLL::GetProcAddress @ EXTERNAL:0000005e
// decompile failed: Exception while decompiling EXTERNAL:0000005e: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_004200c0 @ 004200c0

void __fastcall FUN_004200c0(undefined1 *param_1,byte *param_2,byte *param_3)

{
  uint local_210 [20];
  uint local_1c0 [20];
  uint local_170 [20];
  uint local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  uint local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  byte local_2c;
  byte bStack_2b;
  byte bStack_2a;
  byte bStack_29;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte local_1c;
  byte bStack_1b;
  byte bStack_1a;
  byte bStack_19;
  byte bStack_18;
  byte bStack_17;
  byte bStack_16;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  bStack_2b = param_2[1];
  bStack_2a = param_2[2];
  bStack_29 = param_2[3];
  bStack_28 = param_2[4];
  bStack_27 = param_2[5];
  bStack_26 = param_2[6];
  bStack_25 = param_2[7];
  bStack_24 = param_2[8];
  bStack_23 = param_2[9];
  bStack_22 = param_2[10];
  bStack_21 = param_2[0xb];
  bStack_20 = param_2[0xc];
  bStack_1f = param_2[0xd];
  bStack_1e = param_2[0xe];
  bStack_1d = param_2[0xf];
  local_1c = param_2[0x10];
  bStack_1b = param_2[0x11];
  bStack_1a = param_2[0x12];
  bStack_19 = param_2[0x13];
  bStack_18 = param_2[0x14];
  bStack_17 = param_2[0x15];
  bStack_16 = param_2[0x16];
  bStack_15 = param_2[0x17];
  bStack_14 = param_2[0x18];
  bStack_13 = param_2[0x19];
  bStack_12 = param_2[0x1a];
  bStack_11 = param_2[0x1b];
  bStack_10 = param_2[0x1c];
  bStack_f = param_2[0x1d];
  bStack_e = param_2[0x1e];
  local_2c = *param_2 & 0xf8;
  bStack_d = param_2[0x1f] & 0x3f | 0x40;
  FUN_0041d7f0(local_170,param_3);
  FUN_0041e920(local_210,&local_88,(int)&local_2c,local_170);
  FUN_0041ec90(local_1c0,(int *)&local_88);
  FUN_0041cd80((longlong *)&local_120,(int *)local_210,(int *)local_1c0);
  FUN_0041d250(&local_120);
  FUN_0041d330(&local_120);
  local_88 = local_120;
  uStack_84 = uStack_11c;
  uStack_80 = uStack_118;
  uStack_7c = uStack_114;
  local_78 = local_110;
  uStack_74 = uStack_10c;
  uStack_70 = uStack_108;
  uStack_6c = uStack_104;
  local_68 = local_100;
  uStack_64 = uStack_fc;
  uStack_60 = uStack_f8;
  uStack_5c = uStack_f4;
  local_58 = local_f0;
  uStack_54 = uStack_ec;
  uStack_50 = uStack_e8;
  uStack_4c = uStack_e4;
  local_48 = local_e0;
  uStack_44 = uStack_dc;
  uStack_40 = uStack_d8;
  uStack_3c = uStack_d4;
  FUN_0041d330(&local_88);
  FUN_0041daf0(param_1,(int *)&local_88);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: FUN_0042b2e0 @ 0042b2e0

void * __fastcall FUN_0042b2e0(byte param_1,uint *param_2,undefined4 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *_Dst;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_ECX;
  int iVar6;
  undefined4 extraout_EDX;
  int local_20;
  int iStack_1c;
  
  _Dst = (void *)FUN_0042cfbe(0x1b8);
  plVar1 = (longlong *)((int)_Dst + 0xb0);
  *plVar1 = 0;
  iStack_1c = (int)((ulonglong)*plVar1 >> 0x20);
  local_20 = (int)*plVar1;
  while( true ) {
    LOCK();
    lVar2 = *plVar1;
    if (CONCAT44(iStack_1c,local_20) == lVar2) {
      *plVar1 = 0;
      iVar5 = local_20;
      iVar6 = iStack_1c;
    }
    else {
      iVar5 = (int)lVar2;
      iVar6 = (int)((ulonglong)lVar2 >> 0x20);
    }
    UNLOCK();
    if ((iVar5 == local_20) && (iVar6 == iStack_1c)) break;
    local_20 = iVar5;
    iStack_1c = iVar6;
  }
  _memset((void *)((int)_Dst + 0xb8),0,0x100);
  _memset(_Dst,0,0xb0);
  *(undefined4 *)((int)_Dst + 0x1c) = param_3;
  *(byte *)((int)_Dst + 9) = param_1;
  *(undefined1 *)((int)_Dst + 0x16) = 0x10;
  FUN_00419fe0((void *)((int)_Dst + (param_1 ^ 1) * 0x20 + 0x48),(undefined4 *)((uint)param_1 * 0x20 + 0x48 + (int)_Dst)
               ,extraout_ECX,(undefined4 *)0x0,extraout_ECX,(uint *)0x0,0,param_2);
  if (param_1 == 0) {
    uVar3 = *(undefined4 *)((int)_Dst + 0x88);
    uVar4 = *(undefined4 *)((int)_Dst + 0x8c);
    *(undefined4 *)((int)_Dst + 0x88) = *(undefined4 *)((int)_Dst + 0x98);
    *(undefined4 *)((int)_Dst + 0x8c) = *(undefined4 *)((int)_Dst + 0x9c);
    *(undefined4 *)((int)_Dst + 0x98) = uVar3;
    uVar3 = *(undefined4 *)((int)_Dst + 0x90);
    *(undefined4 *)((int)_Dst + 0x9c) = uVar4;
    uVar4 = *(undefined4 *)((int)_Dst + 0x94);
    *(undefined4 *)((int)_Dst + 0x90) = *(undefined4 *)((int)_Dst + 0xa0);
    *(undefined4 *)((int)_Dst + 0x94) = *(undefined4 *)((int)_Dst + 0xa4);
    *(undefined4 *)((int)_Dst + 0xa0) = uVar3;
    *(undefined4 *)((int)_Dst + 0xa4) = uVar4;
  }
  *(undefined2 *)((int)_Dst + 0x14) = 0x101;
  GetTickCount64();
  *(undefined4 *)((int)_Dst + 0x28) = extraout_EAX;
  *(undefined4 *)((int)_Dst + 0x2c) = extraout_EDX;
  return _Dst;
}


// ----- callee: FUN_0042b1c0 @ 0042b1c0

undefined4 __thiscall FUN_0042b1c0(void *this,int param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined3 uVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint uVar8;
  bool bVar9;
  
  if (param_3 == 0) {
    return CONCAT31((int3)((uint)param_1 >> 8),1);
  }
  uVar3 = param_1;
  if ((3 < param_3) && (uVar3 = *param_2 & 0xffffff, uVar3 == 0x5354)) {
    puVar7 = param_2 + 1;
    for (uVar8 = param_3 - 4; uVar4 = (undefined3)(uVar3 >> 8), 1 < uVar8; uVar8 = (uVar8 - 2) - uVar2) {
      uVar3 = CONCAT31(uVar4,*(byte *)((int)puVar7 + 1));
      uVar2 = (uint)*(byte *)((int)puVar7 + 1);
      if (uVar8 - 2 < uVar2) goto LAB_0042b2d1;
      if ((char)*puVar7 == '\x01') {
        uVar1 = uVar2 * 4;
        uVar3 = 0;
        uVar5 = 7;
        if (7 < uVar1) {
          uVar5 = uVar1;
        }
        if (uVar5 != 0) {
          do {
            if (uVar3 < uVar1) {
              bVar6 = *(byte *)((int)puVar7 + (uVar3 >> 2) + 2) >> ((char)uVar3 * '\x02' & 7U) & 3;
            }
            else {
              bVar6 = 0;
            }
            if (uVar3 < 7) {
              bVar6 = bVar6 * '\x04' + *(char *)((int)this + uVar3 + 0x3d);
              *(byte *)(param_1 + 0xb + uVar3) = (byte)(0xfec0 >> (bVar6 & 0x1f)) & 1;
              bVar9 = (bool)(~(byte)(0xeff7 >> (bVar6 & 0x1f)) & 1);
            }
            else {
              bVar9 = bVar6 == 3;
            }
            if (bVar9 != false) goto LAB_0042b2d1;
            uVar3 = uVar3 + 1;
          } while (uVar3 != uVar5);
        }
      }
      puVar7 = (uint *)((int)puVar7 + uVar2 + 2);
    }
    if (uVar8 == 0) {
      return CONCAT31(uVar4,1);
    }
  }
LAB_0042b2d1:
  return uVar3 & 0xffffff00;
}


// ----- callee: FUN_0041caa0 @ 0041caa0

void __fastcall
FUN_0041caa0(uint *param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,undefined4 param_6,undefined4 param_7,
            undefined4 *param_8,int *param_9)

{
  int *extraout_ECX;
  int iVar1;
  int *piVar2;
  uint local_188 [6];
  uint local_170;
  uint local_16c;
  uint local_168;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_a8;
  int local_a0 [16];
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_20 [3];
  undefined4 local_14;
  uint *local_c;
  
  local_c = param_1;
  FUN_0041c700(local_a0,param_8,param_6,param_7);
  FUN_0041c200(extraout_ECX,&local_60,&local_60,0x40);
  local_c8 = local_50;
  local_c4 = local_4c;
  local_c0 = local_48;
  local_bc = local_44;
  local_188[5] = local_60 & 0xfffffff;
  local_188[0] = 0;
  local_170 = local_5c & 0xffffffc;
  local_a8 = 0;
  local_16c = local_58 & 0xffffffc;
  local_168 = local_54 & 0xffffffc;
  local_188[1] = 0;
  local_188[2] = 0;
  local_188[3] = 0;
  local_188[4] = 0;
  FUN_0041c520(local_188,param_4,param_5);
  FUN_0041c520(local_188,(uint *)&DAT_004481d8,-param_5 & 0xf);
  FUN_0041c520(local_188,param_2,param_3);
  FUN_0041c520(local_188,(uint *)&DAT_004481d8,-param_3 & 0xf);
  local_20[0] = param_5;
  local_20[1] = 0;
  local_20[2] = param_3;
  local_14 = 0;
  FUN_0041c520(local_188,local_20,0x10);
  FUN_0041c5e0(local_188,param_9);
  FUN_0041c200(local_a0,local_c,param_2,param_3);
  piVar2 = local_a0;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  return;
}


// ----- callee: FUN_0042c760 @ 0042c760

void __thiscall FUN_0042c760(void *this,int *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  byte *pbVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  
  piVar1 = (int *)(*(int *)((int)this + 0xc) + (*(uint *)((int)this + 0x18) & param_3) * 8);
  piVar8 = (int *)piVar1[1];
  if (piVar8 == *(int **)((int)this + 4)) {
    *param_1 = (int)*(int **)((int)this + 4);
    param_1[1] = 0;
    return;
  }
  pbVar5 = (byte *)(piVar8 + 2);
  uVar7 = 0x1c;
  piVar4 = param_2;
  do {
    if (*piVar4 != *(int *)pbVar5) {
      bVar3 = (byte)*piVar4;
      bVar9 = bVar3 < *pbVar5;
      if ((((bVar3 == *pbVar5) &&
           (bVar9 = *(byte *)((int)piVar4 + 1) < pbVar5[1], *(byte *)((int)piVar4 + 1) == pbVar5[1])) &&
          (bVar9 = *(byte *)((int)piVar4 + 2) < pbVar5[2], *(byte *)((int)piVar4 + 2) == pbVar5[2])) &&
         (bVar9 = *(byte *)((int)piVar4 + 3) < pbVar5[3], *(byte *)((int)piVar4 + 3) == pbVar5[3])) {
        uVar7 = 0;
      }
      else {
        uVar7 = -(uint)bVar9 | 1;
      }
      goto LAB_0042c7da;
    }
    piVar4 = piVar4 + 1;
    pbVar5 = pbVar5 + 4;
    bVar9 = 3 < uVar7;
    uVar7 = uVar7 - 4;
  } while (bVar9);
  uVar7 = 0;
LAB_0042c7da:
  if (uVar7 == 0) {
LAB_0042c803:
    iVar2 = *piVar8;
    param_1[1] = (int)piVar8;
    *param_1 = iVar2;
    return;
  }
  do {
    if (piVar8 == (int *)*piVar1) {
      *param_1 = (int)piVar8;
      param_1[1] = 0;
      return;
    }
    piVar8 = (int *)piVar8[1];
    uVar7 = 0x1c;
    piVar4 = piVar8 + 2;
    piVar6 = param_2;
    while (*piVar6 == *piVar4) {
      piVar6 = piVar6 + 1;
      piVar4 = piVar4 + 1;
      bVar9 = uVar7 < 4;
      uVar7 = uVar7 - 4;
      if (bVar9) goto LAB_0042c803;
    }
  } while( true );
}


// ----- callee: __security_check_cookie @ 0042cf7c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 != DAT_0044f008) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_0040a7f0 @ 0040a7f0

undefined8 __cdecl
FUN_0040a7f0(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,uint param_7,uint param_8)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar6 = DAT_00451be4 ^ 0x646f7261;
  uVar4 = DAT_00451be4 ^ param_2 ^ 0x74656462;
  uVar1 = DAT_00451be0 ^ 0x6e646f6d;
  uVar5 = DAT_00451be0 ^ param_1 ^ 0x79746573;
  uVar9 = (DAT_00451bd8 ^ 0x70736575) + uVar1;
  uVar11 = (DAT_00451bdc ^ 0x736f6d65) + uVar6 + (uint)CARRY4(DAT_00451bd8 ^ 0x70736575,uVar1);
  uVar7 = (uVar1 << 0xd | uVar6 >> 0x13) ^ uVar9;
  uVar1 = (uVar6 << 0xd | uVar1 >> 0x13) ^ uVar11;
  uVar6 = (DAT_00451bd8 ^ 0x6e657261) + uVar5;
  uVar3 = (DAT_00451bdc ^ 0x6c796765) + uVar4 + (uint)CARRY4(DAT_00451bd8 ^ 0x6e657261,uVar5);
  uVar2 = (uVar5 << 0x10 | uVar4 >> 0x10) ^ uVar6;
  uVar5 = (uVar4 << 0x10 | uVar5 >> 0x10) ^ uVar3;
  uVar9 = uVar9 + uVar5 + (uint)CARRY4(uVar11,uVar2);
  uVar4 = uVar3 + uVar1 + (uint)CARRY4(uVar6,uVar7);
  uVar8 = (uVar5 << 0x15 | uVar2 >> 0xb) ^ uVar9 ^ param_4;
  uVar10 = (uVar2 << 0x15 | uVar5 >> 0xb) ^ uVar11 + uVar2 ^ param_3;
  uVar3 = (uVar7 << 0x11 | uVar1 >> 0xf) ^ uVar6 + uVar7;
  uVar12 = (uVar1 << 0x11 | uVar7 >> 0xf) ^ uVar4;
  uVar1 = uVar11 + uVar2 ^ param_1;
  uVar5 = uVar1 + uVar3;
  uVar11 = (uVar9 ^ param_2) + uVar12 + (uint)CARRY4(uVar1,uVar3);
  uVar2 = (uVar3 << 0xd | uVar12 >> 0x13) ^ uVar5;
  uVar1 = (uVar12 << 0xd | uVar3 >> 0x13) ^ uVar11;
  uVar9 = uVar4 + uVar10;
  uVar4 = uVar6 + uVar7 + uVar8 + (uint)CARRY4(uVar4,uVar10);
  uVar6 = (uVar10 << 0x10 | uVar8 >> 0x10) ^ uVar9;
  uVar3 = (uVar8 << 0x10 | uVar10 >> 0x10) ^ uVar4;
  uVar5 = uVar5 + uVar3 + (uint)CARRY4(uVar11,uVar6);
  uVar4 = uVar4 + uVar1 + (uint)CARRY4(uVar9,uVar2);
  uVar12 = (uVar3 << 0x15 | uVar6 >> 0xb) ^ uVar5 ^ param_6;
  uVar7 = (uVar6 << 0x15 | uVar3 >> 0xb) ^ uVar11 + uVar6 ^ param_5;
  uVar3 = (uVar2 << 0x11 | uVar1 >> 0xf) ^ uVar9 + uVar2;
  uVar8 = (uVar1 << 0x11 | uVar2 >> 0xf) ^ uVar4;
  uVar1 = uVar11 + uVar6 ^ param_3;
  uVar11 = uVar1 + uVar3;
  uVar10 = (uVar5 ^ param_4) + uVar8 + (uint)CARRY4(uVar1,uVar3);
  uVar5 = (uVar3 << 0xd | uVar8 >> 0x13) ^ uVar11;
  uVar1 = (uVar8 << 0xd | uVar3 >> 0x13) ^ uVar10;
  uVar6 = uVar4 + uVar7;
  uVar4 = uVar9 + uVar2 + uVar12 + (uint)CARRY4(uVar4,uVar7);
  uVar3 = (uVar7 << 0x10 | uVar12 >> 0x10) ^ uVar6;
  uVar2 = (uVar12 << 0x10 | uVar7 >> 0x10) ^ uVar4;
  uVar9 = uVar11 + uVar2 + (uint)CARRY4(uVar10,uVar3);
  uVar12 = uVar4 + uVar1 + (uint)CARRY4(uVar6,uVar5);
  uVar11 = (uVar2 << 0x15 | uVar3 >> 0xb) ^ uVar9 ^ param_8;
  uVar7 = (uVar3 << 0x15 | uVar2 >> 0xb) ^ uVar10 + uVar3 ^ param_7;
  uVar4 = (uVar5 << 0x11 | uVar1 >> 0xf) ^ uVar6 + uVar5;
  uVar2 = (uVar1 << 0x11 | uVar5 >> 0xf) ^ uVar12;
  uVar1 = uVar10 + uVar3 ^ param_5;
  uVar10 = uVar1 + uVar4;
  uVar9 = (uVar9 ^ param_6) + uVar2 + (uint)CARRY4(uVar1,uVar4);
  uVar8 = (uVar4 << 0xd | uVar2 >> 0x13) ^ uVar10;
  uVar3 = (uVar2 << 0xd | uVar4 >> 0x13) ^ uVar9;
  uVar4 = uVar12 + uVar7;
  uVar1 = uVar6 + uVar5 + uVar11 + (uint)CARRY4(uVar12,uVar7);
  uVar2 = (uVar7 << 0x10 | uVar11 >> 0x10) ^ uVar4;
  uVar6 = (uVar11 << 0x10 | uVar7 >> 0x10) ^ uVar1;
  uVar10 = uVar10 + uVar6 + (uint)CARRY4(uVar9,uVar2);
  uVar11 = (uVar2 << 0x15 | uVar6 >> 0xb) ^ uVar9 + uVar2;
  uVar12 = (uVar6 << 0x15 | uVar2 >> 0xb) ^ uVar10;
  uVar5 = uVar1 + uVar3 + (uint)CARRY4(uVar4,uVar8);
  uVar1 = uVar12 ^ 0x18000000;
  uVar7 = (uVar8 << 0x11 | uVar3 >> 0xf) ^ uVar4 + uVar8;
  uVar6 = (uVar3 << 0x11 | uVar8 >> 0xf) ^ uVar5;
  uVar3 = uVar9 + uVar2 ^ param_7;
  uVar13 = uVar3 + uVar7;
  uVar2 = (uVar10 ^ param_8) + uVar6 + (uint)CARRY4(uVar3,uVar7);
  uVar9 = (uVar7 << 0xd | uVar6 >> 0x13) ^ uVar13;
  uVar10 = (uVar6 << 0xd | uVar7 >> 0x13) ^ uVar2;
  uVar6 = uVar5 + uVar11;
  uVar3 = uVar4 + uVar8 + uVar1 + (uint)CARRY4(uVar5,uVar11);
  uVar4 = (uVar11 << 0x10 | uVar1 >> 0x10) ^ uVar6;
  uVar1 = (uVar12 << 0x10 | uVar11 >> 0x10) ^ uVar3;
  uVar8 = uVar2 + uVar4;
  uVar5 = uVar13 + uVar1 + (uint)CARRY4(uVar2,uVar4);
  uVar7 = (uVar4 << 0x15 | uVar1 >> 0xb) ^ uVar8;
  uVar4 = (uVar1 << 0x15 | uVar4 >> 0xb) ^ uVar5;
  uVar1 = uVar3 + uVar10 + (uint)CARRY4(uVar6,uVar9);
  uVar2 = (uVar9 << 0x11 | uVar10 >> 0xf) ^ uVar6 + uVar9;
  uVar3 = (uVar10 << 0x11 | uVar9 >> 0xf) ^ uVar1;
  uVar1 = uVar1 ^ 0xff;
  uVar10 = (uVar5 ^ 0x18000000) + uVar3 + (uint)CARRY4(uVar8,uVar2);
  uVar5 = (uVar2 << 0xd | uVar3 >> 0x13) ^ uVar8 + uVar2;
  uVar11 = (uVar3 << 0xd | uVar2 >> 0x13) ^ uVar10;
  uVar3 = uVar1 + uVar7;
  uVar1 = uVar6 + uVar9 + uVar4 + (uint)CARRY4(uVar1,uVar7);
  uVar6 = (uVar7 << 0x10 | uVar4 >> 0x10) ^ uVar3;
  uVar4 = (uVar4 << 0x10 | uVar7 >> 0x10) ^ uVar1;
  uVar12 = uVar10 + uVar6;
  uVar7 = uVar8 + uVar2 + uVar4 + (uint)CARRY4(uVar10,uVar6);
  uVar9 = (uVar6 << 0x15 | uVar4 >> 0xb) ^ uVar12;
  uVar4 = (uVar4 << 0x15 | uVar6 >> 0xb) ^ uVar7;
  uVar1 = uVar1 + uVar11 + (uint)CARRY4(uVar3,uVar5);
  uVar2 = (uVar5 << 0x11 | uVar11 >> 0xf) ^ uVar3 + uVar5;
  uVar6 = (uVar11 << 0x11 | uVar5 >> 0xf) ^ uVar1;
  uVar8 = uVar7 + uVar6 + (uint)CARRY4(uVar12,uVar2);
  uVar7 = (uVar2 << 0xd | uVar6 >> 0x13) ^ uVar12 + uVar2;
  uVar11 = (uVar6 << 0xd | uVar2 >> 0x13) ^ uVar8;
  uVar6 = uVar1 + uVar9;
  uVar1 = uVar3 + uVar5 + uVar4 + (uint)CARRY4(uVar1,uVar9);
  uVar3 = (uVar9 << 0x10 | uVar4 >> 0x10) ^ uVar6;
  uVar4 = (uVar4 << 0x10 | uVar9 >> 0x10) ^ uVar1;
  uVar9 = uVar8 + uVar3;
  uVar10 = uVar12 + uVar2 + uVar4 + (uint)CARRY4(uVar8,uVar3);
  uVar8 = (uVar3 << 0x15 | uVar4 >> 0xb) ^ uVar9;
  uVar2 = (uVar4 << 0x15 | uVar3 >> 0xb) ^ uVar10;
  uVar4 = uVar1 + uVar11 + (uint)CARRY4(uVar6,uVar7);
  uVar1 = (uVar7 << 0x11 | uVar11 >> 0xf) ^ uVar6 + uVar7;
  uVar3 = (uVar11 << 0x11 | uVar7 >> 0xf) ^ uVar4;
  uVar5 = (uVar1 << 0xd | uVar3 >> 0x13) ^ uVar9 + uVar1;
  uVar3 = (uVar3 << 0xd | uVar1 >> 0x13) ^ uVar10 + uVar3 + (uint)CARRY4(uVar9,uVar1);
  uVar9 = uVar4 + uVar8;
  uVar4 = uVar6 + uVar7 + uVar2 + (uint)CARRY4(uVar4,uVar8);
  uVar1 = (uVar8 << 0x10 | uVar2 >> 0x10) ^ uVar9;
  uVar6 = (uVar2 << 0x10 | uVar8 >> 0x10) ^ uVar4;
  uVar4 = uVar4 + uVar3 + (uint)CARRY4(uVar9,uVar5);
  return CONCAT44(uVar9 + uVar5 ^ (uVar3 << 0x11 | uVar5 >> 0xf) ^ (uVar6 << 0x15 | uVar1 >> 0xb) ^ uVar4,
                  uVar4 ^ (uVar5 << 0x11 | uVar3 >> 0xf) ^ (uVar1 << 0x15 | uVar6 >> 0xb) ^ uVar9 + uVar5);
}


// ----- callee: FUN_00429550 @ 00429550

void __thiscall FUN_00429550(void *this,uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_84 [7];
  undefined4 uStack_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  undefined4 local_10;
  char local_c;
  uint local_8;
  
  local_8 = DAT_0044f008 ^ (uint)(local_54 + 0x14);
  _memset(local_84,0,0x7c);
  local_84[0] = 0x1010020;
  local_10 = 0x20;
  uVar4 = 0;
  do {
    uVar1 = *(uint *)(&UNK_004481bc + uVar4);
    uVar2 = *(uint *)(&UNK_004481c0 + uVar4);
    uVar3 = *(uint *)(&UNK_004481c4 + uVar4);
    *(uint *)((int)local_84 + uVar4) = *(uint *)(&DAT_004481b8 + uVar4) ^ *(uint *)((int)local_84 + uVar4);
    *(uint *)((int)local_84 + uVar4 + 4) = uVar1 ^ *(uint *)((int)local_84 + uVar4 + 4);
    *(uint *)((int)local_84 + uVar4 + 8) = uVar2 ^ *(uint *)((int)local_84 + uVar4 + 8);
    *(uint *)((int)local_84 + uVar4 + 0xc) = uVar3 ^ *(uint *)((int)local_84 + uVar4 + 0xc);
    uVar4 = uVar4 + 0x10;
  } while (uVar4 < 0x20);
  FUN_00419bc0(local_84,param_1,param_2);
  FUN_00419bc0(local_84,param_3,param_4);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(local_84,local_54);
  *(uint *)this = local_84[0];
  *(uint *)((int)this + 4) = local_84[1];
  *(uint *)((int)this + 8) = local_84[2];
  *(uint *)((int)this + 0xc) = local_84[3];
  *(uint *)((int)this + 0x10) = local_84[4];
  *(uint *)((int)this + 0x14) = local_84[5];
  *(uint *)((int)this + 0x18) = local_84[6];
  *(undefined4 *)((int)this + 0x1c) = uStack_68;
  __security_check_cookie(local_8 ^ (uint)(local_54 + 0x14));
  return;
}


// ----- callee: FUN_0042b430 @ 0042b430

void __thiscall FUN_0042b430(void *this,int *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  *param_1 = (int)this;
  puVar1 = *(undefined4 **)((int)this + 0xc);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pvVar2 = *(void **)*puVar1;
    if (puVar1[1] != 0) {
      FUN_00429970(pvVar2,(int)puVar1);
    }
    if (puVar1[6] != 0) {
      FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
      puVar1[6] = 0;
    }
    *(undefined1 *)(puVar1 + 5) = 0;
    FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
  }
  if (*(char *)((int)param_1 + 9) == '\0') {
    puVar1 = *(undefined4 **)((int)this + 0x10);
    *(undefined4 *)((int)this + 0x10) = 0;
    if (puVar1 != (undefined4 *)0x0) {
      pvVar2 = *(void **)*puVar1;
      if (puVar1[1] != 0) {
        FUN_00429970(pvVar2,(int)puVar1);
      }
      if (puVar1[6] != 0) {
        FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
        puVar1[6] = 0;
      }
      *(undefined1 *)(puVar1 + 5) = 0;
      FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
    }
    *(int **)((int)this + 0x10) = param_1;
    return;
  }
  if (*(int *)((int)this + 0x10) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  else {
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0x10);
    *(undefined4 *)((int)this + 0x10) = 0;
    puVar1 = *(undefined4 **)((int)this + 8);
    *(undefined4 *)((int)this + 8) = 0;
    if (puVar1 != (undefined4 *)0x0) {
      pvVar2 = *(void **)*puVar1;
      if (puVar1[1] != 0) {
        FUN_00429970(pvVar2,(int)puVar1);
      }
      if (puVar1[6] != 0) {
        FUN_0042c360((void *)((int)pvVar2 + 0x1c),puVar1 + 6);
        puVar1[6] = 0;
      }
      *(undefined1 *)(puVar1 + 5) = 0;
      FUN_0040cb70((void *)((int)pvVar2 + 0x21e8),FUN_0042b190,(uint)puVar1);
      *(int **)((int)this + 8) = param_1;
      return;
    }
  }
  *(int **)((int)this + 8) = param_1;
  return;
}


// ----- callee: KERNEL32.DLL::ExitProcess @ EXTERNAL:0000006c
// decompile failed: Exception while decompiling EXTERNAL:0000006c: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_00429490 @ 00429490

uint __thiscall FUN_00429490(void *this,uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int local_10 [2];
  uint local_8;
  
  do {
    do {
      uVar3 = (uint)*(byte *)((int)this + 0x84);
      if (uVar3 == 0) {
        puVar5 = (uint *)((int)this + 0x140);
        FUN_00419c70((uint *)((int)this + 0x168),0x20,puVar5,0x28,(uint *)0x0,0);
        uVar3 = 8;
        uVar1 = *puVar5;
        *puVar5 = *puVar5 + 1;
        *(int *)((int)this + 0x144) = *(int *)((int)this + 0x144) + (uint)(0xfffffffe < uVar1);
      }
      *(char *)((int)this + 0x84) = (char)(uVar3 - 1);
      local_8 = *(uint *)((int)this + (uVar3 - 1) * 4 + 0x168);
    } while (local_8 == 0);
    piVar4 = (int *)FUN_0042c8f0((void *)((int)this + 0x1c),local_10,&local_8);
    iVar2 = *piVar4;
  } while (*(int *)(iVar2 + 0xc) != 0);
  *(uint *)(iVar2 + 0xc) = param_1;
  *(int *)(iVar2 + 0x10) = param_2;
  puVar5 = (uint *)(param_2 + 0x18);
  if (param_2 == 0) {
    puVar5 = (uint *)(param_1 + 0x24);
  }
  param_1 = *puVar5;
  *puVar5 = local_8;
  if (param_1 == 0) {
    return local_8;
  }
  FUN_0042c360((void *)((int)this + 0x1c),&param_1);
  return local_8;
}


// ----- callee: FUN_0042b590 @ 0042b590

void __thiscall FUN_0042b590(void *this,uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  int extraout_EDX;
  uint *puVar5;
  uint local_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54 [16];
  uint local_14;
  char local_c;
  int *local_8;
  
  *(undefined1 *)((int)this + 0x36) = 1;
  local_8 = this;
  FUN_00418620(&local_84,0x10,(uint *)((int)this + 0x1cc),0x20);
  FUN_00419bc0(&local_84,param_1,(int)param_2 - (int)param_1);
  local_64 = local_64 + local_14;
  local_5c = 0xffffffff;
  local_60 = local_60 + (uint)(local_64 < local_14);
  if (local_c != '\0') {
    local_58 = 0xffffffff;
  }
  _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
  FUN_004186e0(&local_84,local_54);
  *param_2 = local_84;
  param_2[1] = uStack_80;
  param_2[2] = uStack_7c;
  param_2[3] = uStack_78;
  *(uint *)((int)this + 0x1ec) = local_84;
  *(uint *)((int)this + 0x1f0) = uStack_80;
  *(uint *)((int)this + 500) = uStack_7c;
  *(uint *)((int)this + 0x1f8) = uStack_78;
  if (*(char *)((int)this + 0x38) != '\0') {
    GetTickCount64();
    if ((extraout_EDX - *(int *)((int)this + 0x214) == (uint)(extraout_EAX < *(uint *)((int)this + 0x210))) &&
       (extraout_EAX - *(uint *)((int)this + 0x210) < 0x1c138)) {
      FUN_00418620(&local_84,0x10,(uint *)((int)this + 0x1fc),0x10);
      FUN_00419bc0(&local_84,param_1,((int)param_2 - (int)param_1) + 0x10);
      local_64 = local_64 + local_14;
      local_5c = 0xffffffff;
      local_60 = local_60 + (uint)(local_64 < local_14);
      if (local_c != '\0') {
        local_58 = 0xffffffff;
      }
      _memset((void *)((int)local_54 + local_14),0,0x40 - local_14);
      FUN_004186e0(&local_84,local_54);
      param_2[4] = local_84;
      param_2[5] = uStack_80;
      param_2[6] = uStack_7c;
      param_2[7] = uStack_78;
      return;
    }
  }
  puVar5 = param_2 + 4;
  *(undefined1 *)((int)this + 0x38) = 0;
  if (*(char *)(*(int *)this + 0x188) == '\0') {
    *puVar5 = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    return;
  }
  param_1 = (uint *)0x4;
  do {
    iVar3 = *(int *)this;
    uVar4 = (uint)*(byte *)(iVar3 + 0x84);
    if (uVar4 == 0) {
      puVar1 = (uint *)(iVar3 + 0x140);
      FUN_00419c70((uint *)(iVar3 + 0x168),0x20,puVar1,0x28,(uint *)0x0,0);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      uVar4 = 8;
      *(int *)(iVar3 + 0x144) = *(int *)(iVar3 + 0x144) + (uint)(0xfffffffe < uVar2);
      this = local_8;
    }
    *(char *)(iVar3 + 0x84) = (char)(uVar4 - 1);
    *puVar5 = *(uint *)(iVar3 + 0x168 + (uVar4 - 1) * 4);
    puVar5 = puVar5 + 1;
    param_1 = (uint *)((int)param_1 + -1);
  } while (param_1 != (uint *)0x0);
  return;
}



// ===================== FUN_00402340 @ 00402340  anchors: [ObfuscateKey(win@00448308), ObfuscateKey(win@0044833c)] =====================

undefined4 * __fastcall FUN_00402340(undefined4 *param_1)

{
  param_1[1] = "bad array new length";
  *param_1 = &PTR_FUN_0044833c;
  return param_1;
}


// ----- caller: FUN_00402350 @ 00402350

void FUN_00402350(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 local_c [2];
  
  piVar2 = FUN_00402340(local_c);
  FUN_004022c0(piVar2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



// ===================== FUN_0042d6b3 @ 0042d6b3  anchors: [ObfuscateKey(win@00448308)] =====================

undefined4 * __fastcall FUN_0042d6b3(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[1] = "bad array new length";
  *param_1 = std::bad_array_new_length::vftable;
  return param_1;
}


// ----- caller: FUN_0042cfbe @ 0042cfbe

void __cdecl FUN_0042cfbe(size_t param_1)

{
  int iVar1;
  int aiStack_10 [2];
  
  do {
    aiStack_10[1] = 0x42cfd8;
    iVar1 = FUN_0042f99f(param_1);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffff) {
    FUN_0042d6b3(aiStack_10);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(aiStack_10,&DAT_0044bd9c);
  }
  FUN_0042d6cb();
  return;
}



// ===================== FUN_004037b0 @ 004037b0  anchors: [ObfuscateKey(win@00448320)] =====================

void FUN_004037b0(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0042cf49("vector too long");
}


// ----- caller: FUN_004184f0 @ 004184f0

void __thiscall FUN_004184f0(void *this,uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar3 = param_2 - (int)param_1;
  puVar5 = *(uint **)this;
  uVar2 = (int)uVar3 / 0x12;
  uVar1 = (*(int *)((int)this + 8) - (int)puVar5) / 0x12;
  if (uVar2 <= uVar1) goto LAB_004185ee;
  if (uVar2 < 0xe38e38f) {
    uVar6 = uVar2;
    if ((uVar1 <= 0xe38e38e - (uVar1 >> 1)) && (uVar6 = (uVar1 >> 1) + uVar1, uVar6 < uVar2)) {
      uVar6 = uVar2;
    }
    if (puVar5 != (uint *)0x0) {
      puVar4 = puVar5;
      if ((0xfff < uVar1 * 0x12) && (puVar4 = (uint *)puVar5[-1], 0x1f < (uint)((int)puVar5 + (-4 - (int)puVar4))))
      goto LAB_00418615;
      FUN_0042cf8d(puVar4);
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (uVar6 < 0xe38e38f) {
      uVar6 = uVar6 * 0x12;
      if (uVar6 < 0x1000) {
        if (uVar6 == 0) {
          puVar5 = (uint *)0x0;
        }
        else {
          puVar5 = (uint *)FUN_0042cfbe(uVar6);
        }
      }
      else {
        if (uVar6 + 0x23 <= uVar6) goto LAB_0041860b;
        uVar2 = FUN_0042cfbe(uVar6 + 0x23);
        if (uVar2 == 0) goto LAB_00418615;
        puVar5 = (uint *)(uVar2 + 0x23 & 0xffffffe0);
        puVar5[-1] = uVar2;
      }
      *(uint **)this = puVar5;
      *(uint **)((int)this + 4) = puVar5;
      *(uint *)((int)this + 8) = uVar6 + (int)puVar5;
LAB_004185ee:
      FUN_0042e660(puVar5,param_1,uVar3);
      *(uint *)((int)this + 4) = uVar3 + (int)puVar5;
      return;
    }
LAB_0041860b:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00418615:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_004181c0 @ 004181c0

uint * __thiscall FUN_004181c0(void *this,uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  uint *puVar10;
  uint uVar11;
  
  iVar2 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar2) / 0x1c;
  if (iVar5 != 0x9249249) {
    uVar11 = iVar5 + 1;
    uVar8 = (*(int *)((int)this + 8) - iVar2) / 0x1c;
    if (0x9249249 - (uVar8 >> 1) < uVar8) {
      uVar8 = uVar11;
    }
    else {
      uVar8 = (uVar8 >> 1) + uVar8;
      if (uVar8 < uVar11) {
        uVar8 = uVar11;
      }
    }
    if (uVar8 < 0x924924a) {
      uVar11 = uVar8 * 0x1c;
      if (uVar11 < 0x1000) {
        if (uVar11 == 0) {
          puVar10 = (uint *)0x0;
        }
        else {
          puVar10 = (uint *)FUN_0042cfbe(uVar11);
        }
      }
      else {
        if (uVar11 + 0x23 <= uVar11) goto LAB_00418384;
        uVar11 = FUN_0042cfbe(uVar11 + 0x23);
        if (uVar11 == 0) goto LAB_0041838e;
        puVar10 = (uint *)(uVar11 + 0x23 & 0xffffffe0);
        puVar10[-1] = uVar11;
      }
      puVar1 = puVar10 + (((int)param_1 - iVar2) / 0x1c) * 7;
      uVar11 = param_2[1];
      uVar6 = param_2[2];
      uVar7 = param_2[3];
      *puVar1 = *param_2;
      puVar1[1] = uVar11;
      puVar1[2] = uVar6;
      puVar1[3] = uVar7;
      *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_2 + 4);
      puVar1[6] = param_2[6];
      puVar3 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar10,puVar3,(int)*(uint **)((int)this + 4) - (int)puVar3);
      }
      else {
        FUN_0042e660(puVar10,puVar3,(int)param_1 - (int)puVar3);
        FUN_0042e660(puVar1 + 7,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_0041835a:
        *(uint **)this = puVar10;
        *(uint **)((int)this + 4) = puVar10 + (iVar5 + 1) * 7;
        *(uint **)((int)this + 8) = puVar10 + uVar8 * 7;
        return puVar1;
      }
      pvVar9 = pvVar4;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar4) / 0x1c) * 0x1c) < 0x1000) ||
         (pvVar9 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar9)) < 0x20)) {
        FUN_0042cf8d(pvVar9);
        goto LAB_0041835a;
      }
      goto LAB_0041838e;
    }
LAB_00418384:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_0041838e:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00422a20 @ 00422a20

int * __thiscall FUN_00422a20(void *this,int *param_1,undefined4 *param_2)

{
  int *this_00;
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  void *pvVar12;
  int *piVar13;
  
  iVar1 = *(int *)this;
  iVar4 = (*(int *)((int)this + 4) - iVar1) / 0x18;
  if (iVar4 != 0xaaaaaaa) {
    uVar10 = iVar4 + 1;
    uVar5 = (*(int *)((int)this + 8) - iVar1) / 0x18;
    if (0xaaaaaaa - (uVar5 >> 1) < uVar5) {
      uVar5 = uVar10;
    }
    else {
      uVar5 = (uVar5 >> 1) + uVar5;
      if (uVar5 < uVar10) {
        uVar5 = uVar10;
      }
    }
    if (uVar5 < 0xaaaaaab) {
      uVar10 = uVar5 * 0x18;
      if (uVar10 < 0x1000) {
        if (uVar10 == 0) {
          piVar11 = (int *)0x0;
        }
        else {
          piVar11 = (int *)FUN_0042cfbe(uVar10);
        }
      }
      else {
        if (uVar10 + 0x23 <= uVar10) goto LAB_00422bde;
        iVar6 = FUN_0042cfbe(uVar10 + 0x23);
        if (iVar6 == 0) goto LAB_00422be8;
        piVar11 = (int *)(iVar6 + 0x23U & 0xffffffe0);
        piVar11[-1] = iVar6;
      }
      this_00 = piVar11 + (((int)param_1 - iVar1) / 0x18) * 6;
      puVar2 = (uint *)*param_2;
      this_00[4] = 0;
      this_00[5] = 0xf;
      *(undefined1 *)this_00 = 0;
      puVar7 = puVar2;
      do {
        uVar10 = *puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
      } while ((char)uVar10 != '\0');
      FUN_004096e0(this_00,puVar2,(int)puVar7 - ((int)puVar2 + 1));
      piVar9 = *(int **)((int)this + 4);
      piVar8 = *(int **)this;
      piVar13 = piVar11;
      if (param_1 != piVar9) {
        FUN_00422d40(*(int **)this,param_1,piVar11);
        piVar9 = *(int **)((int)this + 4);
        piVar13 = this_00 + 6;
        piVar8 = param_1;
      }
      FUN_00422d40(piVar8,piVar9,piVar13);
      if (*(int **)this == (int *)0x0) {
LAB_00422bbd:
        *(int **)this = piVar11;
        *(int **)((int)this + 4) = piVar11 + (iVar4 + 1) * 6;
        *(int **)((int)this + 8) = piVar11 + uVar5 * 6;
        return this_00;
      }
      FUN_00414d70(*(int **)this,*(int **)((int)this + 4));
      pvVar3 = *(void **)this;
      pvVar12 = pvVar3;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar3) / 0x18) * 0x18) < 0x1000) ||
         (pvVar12 = *(void **)((int)pvVar3 + -4), (uint)((int)pvVar3 + (-4 - (int)pvVar12)) < 0x20)) {
        FUN_0042cf8d(pvVar12);
        goto LAB_00422bbd;
      }
      goto LAB_00422be8;
    }
LAB_00422bde:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00422be8:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00414a20 @ 00414a20

uint * __thiscall FUN_00414a20(void *this,uint *param_1,uint *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  void *pvVar8;
  uint *puVar9;
  
  iVar6 = *(int *)this;
  iVar2 = (*(int *)((int)this + 4) - iVar6) / 0x68;
  if (iVar2 != 0x2762762) {
    uVar4 = iVar2 + 1;
    uVar3 = (*(int *)((int)this + 8) - iVar6) / 0x68;
    if (0x2762762 - (uVar3 >> 1) < uVar3) {
      uVar3 = uVar4;
    }
    else {
      uVar3 = (uVar3 >> 1) + uVar3;
      if (uVar3 < uVar4) {
        uVar3 = uVar4;
      }
    }
    if (uVar3 < 0x2762763) {
      uVar4 = uVar3 * 0x68;
      if (uVar4 < 0x1000) {
        if (uVar4 == 0) {
          puVar7 = (uint *)0x0;
        }
        else {
          puVar7 = (uint *)FUN_0042cfbe(uVar4);
        }
      }
      else {
        if (uVar4 + 0x23 <= uVar4) goto LAB_00414bad;
        uVar4 = FUN_0042cfbe(uVar4 + 0x23);
        if (uVar4 == 0) goto LAB_00414bb7;
        puVar7 = (uint *)(uVar4 + 0x23 & 0xffffffe0);
        puVar7[-1] = uVar4;
      }
      puVar5 = puVar7 + (((int)param_1 - iVar6) / 0x68) * 0x1a;
      puVar9 = puVar5;
      for (iVar6 = 0x1a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = *param_2;
        param_2 = param_2 + 1;
        puVar9 = puVar9 + 1;
      }
      puVar9 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar7,puVar9,(int)*(uint **)((int)this + 4) - (int)puVar9);
      }
      else {
        FUN_0042e660(puVar7,puVar9,(int)param_1 - (int)puVar9);
        FUN_0042e660(puVar5 + 0x1a,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar1 = *(void **)this;
      if (pvVar1 == (void *)0x0) {
LAB_00414b8b:
        *(uint **)this = puVar7;
        *(uint **)((int)this + 4) = puVar7 + (iVar2 + 1) * 0x1a;
        *(uint **)((int)this + 8) = puVar7 + uVar3 * 0x1a;
        return puVar5;
      }
      pvVar8 = pvVar1;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar1) / 0x68) * 0x68) < 0x1000) ||
         (pvVar8 = *(void **)((int)pvVar1 + -4), (uint)((int)pvVar1 + (-4 - (int)pvVar8)) < 0x20)) {
        FUN_0042cf8d(pvVar8);
        goto LAB_00414b8b;
      }
      goto LAB_00414bb7;
    }
LAB_00414bad:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414bb7:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00403600 @ 00403600

uint * __thiscall FUN_00403600(void *this,uint *param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  void *pvVar11;
  
  iVar2 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar2) / 0x18;
  if (iVar5 != 0xaaaaaaa) {
    uVar9 = iVar5 + 1;
    uVar8 = (*(int *)((int)this + 8) - iVar2) / 0x18;
    if (0xaaaaaaa - (uVar8 >> 1) < uVar8) {
      uVar8 = uVar9;
    }
    else {
      uVar8 = (uVar8 >> 1) + uVar8;
      if (uVar8 < uVar9) {
        uVar8 = uVar9;
      }
    }
    if (uVar8 < 0xaaaaaab) {
      uVar9 = uVar8 * 0x18;
      if (uVar9 < 0x1000) {
        if (uVar9 == 0) {
          puVar10 = (uint *)0x0;
        }
        else {
          puVar10 = (uint *)FUN_0042cfbe(uVar9);
        }
      }
      else {
        if (uVar9 + 0x23 <= uVar9) goto LAB_004037a0;
        uVar9 = FUN_0042cfbe(uVar9 + 0x23);
        if (uVar9 == 0) goto LAB_004037aa;
        puVar10 = (uint *)(uVar9 + 0x23 & 0xffffffe0);
        puVar10[-1] = uVar9;
      }
      puVar1 = puVar10 + (((int)param_1 - iVar2) / 0x18) * 6;
      uVar9 = param_2[1];
      uVar6 = param_2[2];
      uVar7 = param_2[3];
      *puVar1 = *param_2;
      puVar1[1] = uVar9;
      puVar1[2] = uVar6;
      puVar1[3] = uVar7;
      *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_2 + 4);
      puVar3 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar10,puVar3,(int)*(uint **)((int)this + 4) - (int)puVar3);
      }
      else {
        FUN_0042e660(puVar10,puVar3,(int)param_1 - (int)puVar3);
        FUN_0042e660(puVar1 + 6,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_0040377a:
        *(uint **)this = puVar10;
        *(uint **)((int)this + 4) = puVar10 + (iVar5 * 3 + 3) * 2;
        *(uint **)((int)this + 8) = puVar10 + uVar8 * 6;
        return puVar1;
      }
      pvVar11 = pvVar4;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar4) / 0x18) * 0x18) < 0x1000) ||
         (pvVar11 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar11)) < 0x20)) {
        FUN_0042cf8d(pvVar11);
        goto LAB_0040377a;
      }
      goto LAB_004037aa;
    }
LAB_004037a0:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_004037aa:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_004098d0 @ 004098d0

uint * __thiscall FUN_004098d0(void *this,uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  uint uVar9;
  uint *puVar10;
  
  iVar3 = *(int *)this;
  iVar6 = *(int *)((int)this + 4) - iVar3 >> 2;
  if (iVar6 != 0x3fffffff) {
    uVar1 = iVar6 + 1;
    uVar9 = *(int *)((int)this + 8) - iVar3 >> 2;
    if (0x3fffffff - (uVar9 >> 1) < uVar9) {
      uVar9 = uVar1;
    }
    else {
      uVar9 = (uVar9 >> 1) + uVar9;
      if (uVar9 < uVar1) {
        uVar9 = uVar1;
      }
    }
    if (uVar9 < 0x40000000) {
      uVar7 = uVar9 * 4;
      if (uVar7 < 0x1000) {
        if (uVar7 == 0) {
          puVar10 = (uint *)0x0;
        }
        else {
          puVar10 = (uint *)FUN_0042cfbe(uVar7);
        }
      }
      else {
        if (uVar7 + 0x23 <= uVar7) goto LAB_00409a15;
        uVar7 = FUN_0042cfbe(uVar7 + 0x23);
        if (uVar7 == 0) goto LAB_00409a1f;
        puVar10 = (uint *)(uVar7 + 0x23 & 0xffffffe0);
        puVar10[-1] = uVar7;
      }
      puVar2 = puVar10 + ((int)param_1 - iVar3 >> 2);
      *puVar2 = *param_2;
      puVar4 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar10,puVar4,(int)*(uint **)((int)this + 4) - (int)puVar4);
      }
      else {
        FUN_0042e660(puVar10,puVar4,(int)param_1 - (int)puVar4);
        FUN_0042e660(puVar2 + 1,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar5 = *(void **)this;
      if (pvVar5 == (void *)0x0) {
LAB_004099f8:
        *(uint **)this = puVar10;
        *(uint **)((int)this + 4) = puVar10 + uVar1;
        *(uint **)((int)this + 8) = puVar10 + uVar9;
        return puVar2;
      }
      pvVar8 = pvVar5;
      if (((*(int *)((int)this + 8) - (int)pvVar5 & 0xfffffffcU) < 0x1000) ||
         (pvVar8 = *(void **)((int)pvVar5 + -4), (uint)((int)pvVar5 + (-4 - (int)pvVar8)) < 0x20)) {
        FUN_0042cf8d(pvVar8);
        goto LAB_004099f8;
      }
      goto LAB_00409a1f;
    }
LAB_00409a15:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00409a1f:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_0040e270 @ 0040e270

undefined4 * __thiscall FUN_0040e270(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  
  iVar3 = *(int *)this;
  iVar6 = *(int *)((int)this + 4) - iVar3 >> 3;
  if (iVar6 != 0x1fffffff) {
    uVar1 = iVar6 + 1;
    uVar9 = *(int *)((int)this + 8) - iVar3 >> 3;
    if (0x1fffffff - (uVar9 >> 1) < uVar9) {
      uVar9 = uVar1;
    }
    else {
      uVar9 = (uVar9 >> 1) + uVar9;
      if (uVar9 < uVar1) {
        uVar9 = uVar1;
      }
    }
    if (uVar9 < 0x20000000) {
      uVar7 = uVar9 * 8;
      if (uVar7 < 0x1000) {
        if (uVar7 == 0) {
          puVar12 = (undefined4 *)0x0;
        }
        else {
          puVar12 = (undefined4 *)FUN_0042cfbe(uVar7);
        }
      }
      else {
        if (uVar7 + 0x23 <= uVar7) goto LAB_0040e3ec;
        iVar6 = FUN_0042cfbe(uVar7 + 0x23);
        if (iVar6 == 0) goto LAB_0040e3f6;
        puVar12 = (undefined4 *)(iVar6 + 0x23U & 0xffffffe0);
        puVar12[-1] = iVar6;
      }
      puVar2 = puVar12 + ((int)param_1 - iVar3 >> 3) * 2;
      *puVar2 = *param_2;
      puVar2[1] = *param_3;
      puVar13 = *(undefined4 **)((int)this + 4);
      puVar10 = *(undefined4 **)this;
      puVar5 = puVar12;
      if (param_1 == puVar13) {
        for (; puVar10 != puVar13; puVar10 = puVar10 + 2) {
          *puVar5 = *puVar10;
          puVar5[1] = puVar10[1];
          puVar5 = puVar5 + 2;
        }
      }
      else {
        puVar11 = puVar12;
        puVar5 = param_1;
        if (puVar10 != param_1) {
          do {
            *puVar11 = *puVar10;
            puVar13 = puVar10 + 1;
            puVar10 = puVar10 + 2;
            puVar11[1] = *puVar13;
            puVar11 = puVar11 + 2;
          } while (puVar10 != param_1);
          puVar13 = *(undefined4 **)((int)this + 4);
        }
        for (; puVar5 != puVar13; puVar5 = puVar5 + 2) {
          *(undefined4 *)((int)puVar2 + (8 - (int)param_1) + (int)puVar5) = *puVar5;
          *(undefined4 *)((int)puVar2 + (0xc - (int)param_1) + (int)puVar5) = puVar5[1];
        }
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_0040e3cd:
        *(undefined4 **)this = puVar12;
        *(undefined4 **)((int)this + 4) = puVar12 + uVar1 * 2;
        *(undefined4 **)((int)this + 8) = puVar12 + uVar9 * 2;
        return puVar2;
      }
      pvVar8 = pvVar4;
      if (((*(int *)((int)this + 8) - (int)pvVar4 & 0xfffffff8U) < 0x1000) ||
         (pvVar8 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar8)) < 0x20)) {
        FUN_0042cf8d(pvVar8);
        goto LAB_0040e3cd;
      }
      goto LAB_0040e3f6;
    }
LAB_0040e3ec:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_0040e3f6:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00414dd0 @ 00414dd0

void __thiscall FUN_00414dd0(void *this,uint param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  
  if (param_1 < 0xaaaaaab) {
    piVar1 = *(int **)this;
    uVar4 = (*(int *)((int)this + 8) - (int)piVar1) / 0x18;
    uVar6 = param_1;
    if ((uVar4 <= 0xaaaaaaa - (uVar4 >> 1)) && (uVar6 = (uVar4 >> 1) + uVar4, uVar6 < param_1)) {
      uVar6 = param_1;
    }
    if (piVar1 != (int *)0x0) {
      FUN_00414d70(piVar1,*(int **)((int)this + 4));
      pvVar2 = *(void **)this;
      pvVar5 = pvVar2;
      if ((0xfff < (uint)(((*(int *)((int)this + 8) - (int)pvVar2) / 0x18) * 0x18)) &&
         (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5)))) goto LAB_00414f03;
      FUN_0042cf8d(pvVar5);
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (uVar6 < 0xaaaaaab) {
      uVar6 = uVar6 * 0x18;
      if (uVar6 < 0x1000) {
        if (uVar6 == 0) {
          *(undefined4 *)this = 0;
          *(undefined4 *)((int)this + 4) = 0;
          *(undefined4 *)((int)this + 8) = 0;
          return;
        }
        iVar3 = FUN_0042cfbe(uVar6);
        *(int *)this = iVar3;
        *(int *)((int)this + 4) = iVar3;
        *(uint *)((int)this + 8) = iVar3 + uVar6;
        return;
      }
      if (uVar6 < uVar6 + 0x23) {
        iVar3 = FUN_0042cfbe(uVar6 + 0x23);
        if (iVar3 != 0) {
          uVar4 = iVar3 + 0x23U & 0xffffffe0;
          *(int *)(uVar4 - 4) = iVar3;
          *(uint *)this = uVar4;
          *(uint *)((int)this + 4) = uVar4;
          *(uint *)((int)this + 8) = uVar4 + uVar6;
          return;
        }
        goto LAB_00414f03;
      }
    }
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414f03:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_0040cbf0 @ 0040cbf0

uint * __thiscall FUN_0040cbf0(void *this,uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  uint uVar9;
  uint *puVar10;
  
  iVar3 = *(int *)this;
  iVar6 = *(int *)((int)this + 4) - iVar3 >> 3;
  if (iVar6 != 0x1fffffff) {
    uVar1 = iVar6 + 1;
    uVar9 = *(int *)((int)this + 8) - iVar3 >> 3;
    if (0x1fffffff - (uVar9 >> 1) < uVar9) {
      uVar9 = uVar1;
    }
    else {
      uVar9 = (uVar9 >> 1) + uVar9;
      if (uVar9 < uVar1) {
        uVar9 = uVar1;
      }
    }
    if (uVar9 < 0x20000000) {
      uVar7 = uVar9 * 8;
      if (uVar7 < 0x1000) {
        if (uVar7 == 0) {
          puVar10 = (uint *)0x0;
        }
        else {
          puVar10 = (uint *)FUN_0042cfbe(uVar7);
        }
      }
      else {
        if (uVar7 + 0x23 <= uVar7) goto LAB_0040cd3b;
        uVar7 = FUN_0042cfbe(uVar7 + 0x23);
        if (uVar7 == 0) goto LAB_0040cd45;
        puVar10 = (uint *)(uVar7 + 0x23 & 0xffffffe0);
        puVar10[-1] = uVar7;
      }
      puVar2 = puVar10 + ((int)param_1 - iVar3 >> 3) * 2;
      *puVar2 = *param_2;
      puVar2[1] = param_2[1];
      puVar4 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar10,puVar4,(int)*(uint **)((int)this + 4) - (int)puVar4);
      }
      else {
        FUN_0042e660(puVar10,puVar4,(int)param_1 - (int)puVar4);
        FUN_0042e660(puVar2 + 2,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar5 = *(void **)this;
      if (pvVar5 == (void *)0x0) {
LAB_0040cd1e:
        *(uint **)this = puVar10;
        *(uint **)((int)this + 4) = puVar10 + uVar1 * 2;
        *(uint **)((int)this + 8) = puVar10 + uVar9 * 2;
        return puVar2;
      }
      pvVar8 = pvVar5;
      if (((*(int *)((int)this + 8) - (int)pvVar5 & 0xfffffff8U) < 0x1000) ||
         (pvVar8 = *(void **)((int)pvVar5 + -4), (uint)((int)pvVar5 + (-4 - (int)pvVar8)) < 0x20)) {
        FUN_0042cf8d(pvVar8);
        goto LAB_0040cd1e;
      }
      goto LAB_0040cd45;
    }
LAB_0040cd3b:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_0040cd45:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00414820 @ 00414820

undefined8 * __thiscall
FUN_00414820(void *this,undefined8 *param_1,undefined1 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  void *pvVar12;
  undefined8 *puVar13;
  
  iVar3 = *(int *)this;
  iVar8 = (*(int *)((int)this + 4) - *(int *)this) / 0xc;
  if (iVar8 != 0x15555555) {
    uVar1 = iVar8 + 1;
    uVar7 = (*(int *)((int)this + 8) - *(int *)this) / 0xc;
    if (0x15555555 - (uVar7 >> 1) < uVar7) {
      uVar7 = uVar1;
    }
    else {
      uVar7 = (uVar7 >> 1) + uVar7;
      if (uVar7 < uVar1) {
        uVar7 = uVar1;
      }
    }
    if (uVar7 < 0x15555556) {
      uVar7 = uVar7 * 0xc;
      if (uVar7 < 0x1000) {
        if (uVar7 == 0) {
          puVar11 = (undefined8 *)0x0;
        }
        else {
          puVar11 = (undefined8 *)FUN_0042cfbe(uVar7);
        }
      }
      else {
        if (uVar7 + 0x23 <= uVar7) goto LAB_00414a03;
        iVar8 = FUN_0042cfbe(uVar7 + 0x23);
        if (iVar8 == 0) goto LAB_00414a0d;
        puVar11 = (undefined8 *)(iVar8 + 0x23U & 0xffffffe0);
        *(int *)((int)puVar11 + -4) = iVar8;
      }
      puVar2 = (undefined8 *)((int)puVar11 + (((int)param_1 - iVar3) / 0xc) * 0xc);
      uVar4 = *param_4;
      uVar5 = *param_3;
      *(undefined1 *)puVar2 = *param_2;
      *(undefined4 *)(puVar2 + 1) = uVar4;
      *(undefined4 *)((int)puVar2 + 4) = uVar5;
      puVar13 = *(undefined8 **)((int)this + 4);
      puVar9 = *(undefined8 **)this;
      puVar10 = puVar11;
      if (param_1 == puVar13) {
        for (; puVar9 != puVar13; puVar9 = (undefined8 *)((int)puVar9 + 0xc)) {
          *puVar10 = *puVar9;
          *(undefined4 *)(puVar10 + 1) = *(undefined4 *)(puVar9 + 1);
          puVar10 = (undefined8 *)((int)puVar10 + 0xc);
        }
      }
      else {
        if (puVar9 != param_1) {
          do {
            *puVar10 = *puVar9;
            puVar13 = puVar9 + 1;
            puVar9 = (undefined8 *)((int)puVar9 + 0xc);
            *(undefined4 *)(puVar10 + 1) = *(undefined4 *)puVar13;
            puVar10 = (undefined8 *)((int)puVar10 + 0xc);
          } while (puVar9 != param_1);
          puVar13 = *(undefined8 **)((int)this + 4);
        }
        if (param_1 != puVar13) {
          puVar9 = puVar2;
          do {
            *(undefined8 *)((int)puVar9 + 0xc) = *param_1;
            puVar10 = param_1 + 1;
            param_1 = (undefined8 *)((int)param_1 + 0xc);
            *(undefined4 *)((int)puVar9 + 0x14) = *(undefined4 *)puVar10;
            puVar9 = (undefined8 *)((int)puVar9 + 0xc);
          } while (param_1 != puVar13);
        }
      }
      pvVar6 = *(void **)this;
      if (pvVar6 == (void *)0x0) {
LAB_004149e1:
        *(undefined8 **)this = puVar11;
        *(uint *)((int)this + 4) = (int)puVar11 + uVar1 * 0xc;
        *(uint *)((int)this + 8) = uVar7 + (int)puVar11;
        return puVar2;
      }
      pvVar12 = pvVar6;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar6) / 0xc) * 0xc) < 0x1000) ||
         (pvVar12 = *(void **)((int)pvVar6 + -4), (uint)((int)pvVar6 + (-4 - (int)pvVar12)) < 0x20)) {
        FUN_0042cf8d(pvVar12);
        goto LAB_004149e1;
      }
      goto LAB_00414a0d;
    }
LAB_00414a03:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414a0d:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00414680 @ 00414680

uint * __thiscall FUN_00414680(void *this,uint *param_1)

{
  int iVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *_Dst;
  void *pvVar8;
  
  iVar1 = *(int *)this;
  iVar4 = (*(int *)((int)this + 4) - iVar1) / 0x68;
  if (iVar4 != 0x2762762) {
    uVar6 = iVar4 + 1;
    uVar5 = (*(int *)((int)this + 8) - iVar1) / 0x68;
    if (0x2762762 - (uVar5 >> 1) < uVar5) {
      uVar5 = uVar6;
    }
    else {
      uVar5 = (uVar5 >> 1) + uVar5;
      if (uVar5 < uVar6) {
        uVar5 = uVar6;
      }
    }
    if (uVar5 < 0x2762763) {
      uVar6 = uVar5 * 0x68;
      if (uVar6 < 0x1000) {
        if (uVar6 == 0) {
          puVar7 = (uint *)0x0;
        }
        else {
          puVar7 = (uint *)FUN_0042cfbe(uVar6);
        }
      }
      else {
        if (uVar6 + 0x23 <= uVar6) goto LAB_00414806;
        uVar6 = FUN_0042cfbe(uVar6 + 0x23);
        if (uVar6 == 0) goto LAB_00414810;
        puVar7 = (uint *)(uVar6 + 0x23 & 0xffffffe0);
        puVar7[-1] = uVar6;
      }
      _Dst = puVar7 + (((int)param_1 - iVar1) / 0x68) * 0x1a;
      _memset(_Dst,0,0x68);
      puVar2 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar7,puVar2,(int)*(uint **)((int)this + 4) - (int)puVar2);
      }
      else {
        FUN_0042e660(puVar7,puVar2,(int)param_1 - (int)puVar2);
        FUN_0042e660(_Dst + 0x1a,param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar3 = *(void **)this;
      if (pvVar3 == (void *)0x0) {
LAB_004147e4:
        *(uint **)this = puVar7;
        *(uint **)((int)this + 4) = puVar7 + (iVar4 + 1) * 0x1a;
        *(uint **)((int)this + 8) = puVar7 + uVar5 * 0x1a;
        return _Dst;
      }
      pvVar8 = pvVar3;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar3) / 0x68) * 0x68) < 0x1000) ||
         (pvVar8 = *(void **)((int)pvVar3 + -4), (uint)((int)pvVar3 + (-4 - (int)pvVar8)) < 0x20)) {
        FUN_0042cf8d(pvVar8);
        goto LAB_004147e4;
      }
      goto LAB_00414810;
    }
LAB_00414806:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414810:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_00414bc0 @ 00414bc0

undefined4 * __thiscall FUN_00414bc0(void *this,uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  void *pvVar12;
  
  iVar2 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar2) / 0x12;
  if (iVar5 != 0xe38e38e) {
    uVar10 = iVar5 + 1;
    uVar9 = (*(int *)((int)this + 8) - iVar2) / 0x12;
    if (0xe38e38e - (uVar9 >> 1) < uVar9) {
      uVar9 = uVar10;
    }
    else {
      uVar9 = (uVar9 >> 1) + uVar9;
      if (uVar9 < uVar10) {
        uVar9 = uVar10;
      }
    }
    if (uVar9 < 0xe38e38f) {
      uVar9 = uVar9 * 0x12;
      if (uVar9 < 0x1000) {
        if (uVar9 == 0) {
          puVar11 = (uint *)0x0;
        }
        else {
          puVar11 = (uint *)FUN_0042cfbe(uVar9);
        }
      }
      else {
        if (uVar9 + 0x23 <= uVar9) goto LAB_00414d5c;
        uVar10 = FUN_0042cfbe(uVar9 + 0x23);
        if (uVar10 == 0) goto LAB_00414d66;
        puVar11 = (uint *)(uVar10 + 0x23 & 0xffffffe0);
        puVar11[-1] = uVar10;
      }
      puVar1 = (undefined4 *)((int)puVar11 + (((int)param_1 - iVar2) / 0x12) * 0x12);
      uVar6 = param_2[1];
      uVar7 = param_2[2];
      uVar8 = param_2[3];
      *puVar1 = *param_2;
      puVar1[1] = uVar6;
      puVar1[2] = uVar7;
      puVar1[3] = uVar8;
      *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(param_2 + 4);
      puVar3 = *(uint **)this;
      if (param_1 == *(uint **)((int)this + 4)) {
        FUN_0042e660(puVar11,puVar3,(int)*(uint **)((int)this + 4) - (int)puVar3);
      }
      else {
        FUN_0042e660(puVar11,puVar3,(int)param_1 - (int)puVar3);
        FUN_0042e660((uint *)((int)puVar1 + 0x12),param_1,*(int *)((int)this + 4) - (int)param_1);
      }
      pvVar4 = *(void **)this;
      if (pvVar4 == (void *)0x0) {
LAB_00414d36:
        *(uint **)this = puVar11;
        *(int *)((int)this + 4) = (int)puVar11 + (iVar5 * 9 + 9) * 2;
        *(uint *)((int)this + 8) = uVar9 + (int)puVar11;
        return puVar1;
      }
      pvVar12 = pvVar4;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar4) / 0x12) * 0x12) < 0x1000) ||
         (pvVar12 = *(void **)((int)pvVar4 + -4), (uint)((int)pvVar4 + (-4 - (int)pvVar12)) < 0x20)) {
        FUN_0042cf8d(pvVar12);
        goto LAB_00414d36;
      }
      goto LAB_00414d66;
    }
LAB_00414d5c:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_00414d66:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_0040c7d0 @ 0040c7d0

int * __thiscall FUN_0040c7d0(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  void *pvVar11;
  int *piVar12;
  int *piVar13;
  
  iVar1 = *(int *)this;
  iVar5 = (*(int *)((int)this + 4) - iVar1) / 0x34;
  if (iVar5 != 0x4ec4ec4) {
    uVar10 = iVar5 + 1;
    uVar7 = (*(int *)((int)this + 8) - iVar1) / 0x34;
    if (0x4ec4ec4 - (uVar7 >> 1) < uVar7) {
      uVar3 = uVar10;
    }
    else {
      uVar3 = (uVar7 >> 1) + uVar7;
      if (uVar3 < uVar10) {
        uVar3 = uVar10;
      }
    }
    if (uVar3 < 0x4ec4ec5) {
      uVar4 = uVar3 * 0x34;
      if (uVar4 < 0x1000) {
        if (uVar4 == 0) {
          piVar12 = (int *)0x0;
        }
        else {
          piVar12 = (int *)FUN_0042cfbe(uVar4);
          uVar7 = extraout_ECX_00;
        }
      }
      else {
        if (uVar4 + 0x23 <= uVar4) goto LAB_0040c957;
        iVar5 = FUN_0042cfbe(uVar4 + 0x23);
        if (iVar5 == 0) goto LAB_0040c961;
        piVar12 = (int *)(iVar5 + 0x23U & 0xffffffe0);
        piVar12[-1] = iVar5;
        uVar7 = extraout_ECX;
      }
      piVar6 = piVar12 + (((int)param_1 - iVar1) / 0x34) * 0xd;
      FUN_0040c720(uVar7,piVar6,param_2,param_3);
      puVar9 = *(undefined4 **)((int)this + 4);
      puVar8 = *(undefined4 **)this;
      piVar13 = piVar12;
      if (param_1 != puVar9) {
        FUN_0040c9d0(*(undefined4 **)this,param_1,piVar12);
        puVar9 = *(undefined4 **)((int)this + 4);
        piVar13 = piVar6 + 0xd;
        puVar8 = param_1;
      }
      FUN_0040c9d0(puVar8,puVar9,piVar13);
      if (*(int **)this == (int *)0x0) {
LAB_0040c939:
        *(int **)this = piVar12;
        *(int **)((int)this + 4) = piVar12 + uVar10 * 0xd;
        *(int **)((int)this + 8) = piVar12 + uVar3 * 0xd;
        return piVar6;
      }
      FUN_0040c970(*(int **)this,*(int **)((int)this + 4));
      pvVar2 = *(void **)this;
      pvVar11 = pvVar2;
      if (((uint)(((*(int *)((int)this + 8) - (int)pvVar2) / 0x34) * 0x34) < 0x1000) ||
         (pvVar11 = *(void **)((int)pvVar2 + -4), (uint)((int)pvVar2 + (-4 - (int)pvVar11)) < 0x20)) {
        FUN_0042cf8d(pvVar11);
        goto LAB_0040c939;
      }
      goto LAB_0040c961;
    }
LAB_0040c957:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_0040c961:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- caller: FUN_004183a0 @ 004183a0

void __thiscall FUN_004183a0(void *this,uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar2 = param_2 - (int)param_1;
  puVar5 = *(uint **)this;
  uVar6 = (int)uVar2 / 0x1c;
  uVar1 = (*(int *)((int)this + 8) - (int)puVar5) / 0x1c;
  if (uVar6 <= uVar1) goto LAB_004184bc;
  if (uVar6 < 0x924924a) {
    uVar3 = uVar6;
    if ((uVar1 <= 0x9249249 - (uVar1 >> 1)) && (uVar3 = (uVar1 >> 1) + uVar1, uVar3 < uVar6)) {
      uVar3 = uVar6;
    }
    if (puVar5 != (uint *)0x0) {
      puVar4 = puVar5;
      if ((0xfff < uVar1 * 0x1c) && (puVar4 = (uint *)puVar5[-1], 0x1f < (uint)((int)puVar5 + (-4 - (int)puVar4))))
      goto LAB_004184e5;
      FUN_0042cf8d(puVar4);
      *(undefined4 *)this = 0;
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
    }
    if (uVar3 < 0x924924a) {
      uVar6 = uVar3 * 0x1c;
      if (uVar6 < 0x1000) {
        if (uVar6 == 0) {
          puVar5 = (uint *)0x0;
        }
        else {
          puVar5 = (uint *)FUN_0042cfbe(uVar6);
        }
      }
      else {
        if (uVar6 + 0x23 <= uVar6) goto LAB_004184db;
        uVar6 = FUN_0042cfbe(uVar6 + 0x23);
        if (uVar6 == 0) goto LAB_004184e5;
        puVar5 = (uint *)(uVar6 + 0x23 & 0xffffffe0);
        puVar5[-1] = uVar6;
      }
      *(uint **)this = puVar5;
      *(uint **)((int)this + 4) = puVar5;
      *(uint **)((int)this + 8) = puVar5 + uVar3 * 7;
LAB_004184bc:
      FUN_0042e660(puVar5,param_1,uVar2);
      *(uint *)((int)this + 4) = uVar2 + (int)puVar5;
      return;
    }
LAB_004184db:
    FUN_00402350();
  }
  FUN_004037b0();
LAB_004184e5:
                    /* WARNING: Subroutine does not return */
  FUN_0042fb66();
}


// ----- callee: FUN_0042cf49 @ 0042cf49

void FUN_0042cf49(char *param_1)

{
  int local_10 [3];
  
  FUN_0042ceb4(local_10,param_1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_0044bcec);
}



// ===================== FUN_00402300 @ 00402300  anchors: [ObfuscateKey(win@00448330)] =====================

undefined4 * __thiscall FUN_00402300(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_00448330;
  if ((param_1 & 1) != 0) {
    FUN_0042cf8d(this);
  }
  return this;
}


// ----- callee: FUN_0042cf8d @ 0042cf8d

void __cdecl FUN_0042cf8d(void *param_1)

{
  thunk_FUN_0042f984(param_1);
  return;
}



// ===================== FUN_00405160 @ 00405160  anchors: [ObfuscateKey(win@00448348)] =====================

void __thiscall FUN_00405160(void *this,PSINGLE_LIST_ENTRY param_1)

{
  _SINGLE_LIST_ENTRY *p_Var1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  _SINGLE_LIST_ENTRY *p_Var6;
  _SINGLE_LIST_ENTRY *p_Var7;
  int extraout_EAX;
  undefined4 *puVar8;
  undefined4 extraout_EAX_00;
  char cVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 unaff_EDI;
  
LAB_00405171:
  do {
    if (param_1 == (PSINGLE_LIST_ENTRY)0x0) {
      return;
    }
    iVar13 = *(int *)(*(int *)((int)this + 4) + 0x90);
    p_Var1 = (param_1[8].Next)->Next;
    if (iVar13 != 0) {
      uVar10 = *(ushort *)&param_1[10].Next;
      while( true ) {
        uVar12 = (uint)(*(ushort *)(iVar13 + 0x1b8) ^ *(ushort *)&param_1[10].Next);
        if (uVar10 == 0x17) {
          uVar12 = (uint)(*(ushort *)(iVar13 + 0x1ba) ^ *(ushort *)((int)&param_1[10].Next + 2)) |
                   (uint)param_1[0xf].Next ^ *(uint *)(iVar13 + 0x1cc) |
                   *(uint *)(iVar13 + 0x1c4) ^ (uint)param_1[0xd].Next | uVar12 |
                   (uint)param_1[0xe].Next ^ *(uint *)(iVar13 + 0x1c8) |
                   *(uint *)(iVar13 + 0x1c0) ^ (uint)param_1[0xc].Next;
        }
        else {
          uVar12 = *(uint *)(iVar13 + 0x1bc) ^ (uint)param_1[0xb].Next |
                   (uint)(*(ushort *)(iVar13 + 0x1ba) ^ *(ushort *)((int)&param_1[10].Next + 2)) | uVar12;
        }
        if ((uVar12 == 0) && (*(char *)(iVar13 + 0x11) == *(char *)((int)&param_1[9].Next + 1))) break;
        iVar13 = *(int *)(iVar13 + 0x28);
        if (iVar13 == 0) goto LAB_0040529c;
        uVar10 = *(ushort *)&param_1[10].Next;
      }
      if (p_Var1 != (_SINGLE_LIST_ENTRY *)0x1) {
LAB_004052c1:
        p_Var1 = param_1->Next;
        *(undefined1 *)((int)&param_1[9].Next + 2) = 0;
        param_1->Next = (_SINGLE_LIST_ENTRY *)0x0;
        **(undefined4 **)(iVar13 + 0x24) = param_1;
        *(PSINGLE_LIST_ENTRY *)(iVar13 + 0x24) = param_1;
        param_1 = p_Var1;
        goto LAB_00405171;
      }
      GetTickCount64();
      uVar12 = (uint)(extraout_EAX - *(int *)(iVar13 + 0x14)) >> 10;
      *(int *)(iVar13 + 0x14) = *(int *)(iVar13 + 0x14) + uVar12 * 0x400;
      if (*(byte *)(iVar13 + 0x10) + 0x19 < uVar12) {
        *(undefined1 *)(iVar13 + 0x10) = 0;
        goto LAB_004052c1;
      }
      iVar11 = (*(byte *)(iVar13 + 0x10) - uVar12) + 0x19;
      *(char *)(iVar13 + 0x10) = (char)iVar11;
      if (iVar11 < 0x3c) goto LAB_004052c1;
      FUN_0040e0a0("Making new Tcp socket due to too many handshake failures",(char)unaff_EDI);
      if (*(HANDLE *)(iVar13 + 0x18) != (HANDLE)0xffffffff) {
        CancelIo(*(HANDLE *)(iVar13 + 0x18));
      }
      *(undefined1 *)(iVar13 + 0xe) = 1;
      *(undefined1 *)(iVar13 + 0x11) = 0;
    }
LAB_0040529c:
    if ((*(char *)((int)&param_1[9].Next + 1) < '\0') || (p_Var1 != (_SINGLE_LIST_ENTRY *)0x1)) {
      p_Var1 = param_1->Next;
      InterlockedPushEntrySList((PSLIST_HEADER)&DAT_00451c28,param_1);
      param_1 = p_Var1;
    }
    else {
      puVar8 = (undefined4 *)FUN_0042cfbe(600);
      pcVar2 = *(char **)((int)this + 0x14);
      iVar13 = *(int *)((int)this + 4);
      puVar8[2] = *(undefined4 *)((int)this + 0x10);
      *puVar8 = &PTR_FUN_00448720;
      *(undefined1 *)((int)puVar8 + 0x31) = 0;
      puVar8[0x10] = 0;
      puVar8[0x11] = puVar8 + 0x10;
      *(undefined1 *)((int)puVar8 + 0x33) = 0;
      puVar8[0xf] = 0;
      puVar8[0x12] = iVar13 + 0x94;
      puVar8[0x13] = 0;
      puVar8[0x14] = 0;
      puVar8[0x15] = puVar8 + 0x14;
      puVar8[0x16] = iVar13 + 0x94;
      if (*pcVar2 == '\0') {
        if (0 < *(int *)(pcVar2 + 4)) {
          FUN_0040e010("No ObfuscateKey specified. Disabling TCP obfuscation.",(char)unaff_EDI);
        }
      }
      else if (*(int *)(pcVar2 + 4) != 0) {
        uVar3 = *(undefined4 *)(pcVar2 + 0xc);
        uVar4 = *(undefined4 *)(pcVar2 + 0x10);
        uVar5 = *(undefined4 *)(pcVar2 + 0x14);
        puVar8[0x1f] = *(undefined4 *)(pcVar2 + 8);
        puVar8[0x20] = uVar3;
        puVar8[0x21] = uVar4;
        puVar8[0x22] = uVar5;
        uVar3 = *(undefined4 *)(pcVar2 + 0x1c);
        uVar4 = *(undefined4 *)(pcVar2 + 0x20);
        uVar5 = *(undefined4 *)(pcVar2 + 0x24);
        puVar8[0x23] = *(undefined4 *)(pcVar2 + 0x18);
        puVar8[0x24] = uVar3;
        puVar8[0x25] = uVar4;
        puVar8[0x26] = uVar5;
        uVar3 = *(undefined4 *)(pcVar2 + 0xc);
        uVar4 = *(undefined4 *)(pcVar2 + 0x10);
        uVar5 = *(undefined4 *)(pcVar2 + 0x14);
        puVar8[0x40] = *(undefined4 *)(pcVar2 + 8);
        puVar8[0x41] = uVar3;
        puVar8[0x42] = uVar4;
        puVar8[0x43] = uVar5;
        uVar3 = *(undefined4 *)(pcVar2 + 0x1c);
        uVar4 = *(undefined4 *)(pcVar2 + 0x20);
        uVar5 = *(undefined4 *)(pcVar2 + 0x24);
        puVar8[0x44] = *(undefined4 *)(pcVar2 + 0x18);
        puVar8[0x45] = uVar3;
        puVar8[0x46] = uVar4;
        puVar8[0x47] = uVar5;
        cVar9 = '\x01';
        if (*(int *)(pcVar2 + 4) != -1) {
          cVar9 = (char)*(undefined4 *)(pcVar2 + 4);
        }
        *(char *)((int)puVar8 + 0x31) = cVar9;
        *(bool *)((int)puVar8 + 0x32) = cVar9 != '\x01';
      }
      *(undefined2 *)(puVar8 + 0xd) = 0;
      *(undefined1 *)(puVar8 + 0xc) = 0;
      puVar8[0x18] = 0;
      puVar8[0x17] = 0;
      puVar8[0x1c] = 0;
      puVar8[0x1d] = 0;
      puVar8[0x1a] = 0;
      puVar8[0x1b] = 0;
      puVar8[10] = 0;
      puVar8[1] = iVar13;
      *(undefined2 *)(puVar8 + 3) = 0;
      *(undefined1 *)(puVar8 + 4) = 0;
      puVar8[5] = 0;
      *(undefined1 *)((int)puVar8 + 0xe) = 0;
      puVar8[8] = 0;
      puVar8[9] = puVar8 + 8;
      puVar8[6] = 0xffffffff;
      puVar8[10] = *(undefined4 *)(iVar13 + 0x90);
      *(undefined4 **)(iVar13 + 0x90) = puVar8;
      *(undefined1 *)((int)puVar8 + 0xe) = 4;
      p_Var1 = param_1[0xb].Next;
      p_Var6 = param_1[0xc].Next;
      p_Var7 = param_1[0xd].Next;
      puVar8[0x6e] = param_1[10].Next;
      puVar8[0x6f] = p_Var1;
      puVar8[0x70] = p_Var6;
      puVar8[0x71] = p_Var7;
      p_Var1 = param_1[0xf].Next;
      puVar8[0x72] = param_1[0xe].Next;
      puVar8[0x73] = p_Var1;
      puVar8[0x74] = param_1[0x10].Next;
      *(undefined1 *)((int)puVar8 + 0x11) = 2;
      GetTickCount64();
      puVar8[5] = extraout_EAX_00;
      p_Var1 = param_1->Next;
      *(undefined1 *)((int)&param_1[9].Next + 2) = 0;
      param_1->Next = (_SINGLE_LIST_ENTRY *)0x0;
      *(PSINGLE_LIST_ENTRY *)puVar8[9] = param_1;
      puVar8[9] = param_1;
      param_1 = p_Var1;
    }
  } while( true );
}


// ----- callee: KERNEL32.DLL::CancelIo @ EXTERNAL:0000007c
// decompile failed: Exception while decompiling EXTERNAL:0000007c: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0042cfbe @ 0042cfbe

void __cdecl FUN_0042cfbe(size_t param_1)

{
  int iVar1;
  int aiStack_10 [2];
  
  do {
    aiStack_10[1] = 0x42cfd8;
    iVar1 = FUN_0042f99f(param_1);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffff) {
    FUN_0042d6b3(aiStack_10);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(aiStack_10,&DAT_0044bd9c);
  }
  FUN_0042d6cb();
  return;
}


// ----- callee: KERNEL32.DLL::GetTickCount64 @ EXTERNAL:00000060
// decompile failed: Exception while decompiling EXTERNAL:00000060: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0040e0a0 @ 0040e0a0

void __cdecl FUN_0040e0a0(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(0,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}


// ----- callee: KERNEL32.DLL::InterlockedPushEntrySList @ EXTERNAL:0000004b
// decompile failed: Exception while decompiling EXTERNAL:0000004b: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0040e010 @ 0040e010

void __cdecl FUN_0040e010(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(1,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===================== FUN_00404560 @ 00404560  anchors: [ObfuscateKey(win@00448380), ObfuscateKey(win@004483b4)] =====================

void __thiscall FUN_00404560(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  HMODULE hModule;
  int iVar9;
  uint uVar10;
  undefined4 unaff_EDI;
  char *lpProcName;
  char cVar11;
  uint local_41c;
  int *local_418;
  void *local_414;
  uint local_410 [257];
  uint local_c;
  
  cVar11 = (char)unaff_EDI;
  local_c = DAT_0044f008 ^ (uint)&local_41c;
  cVar1 = *(char *)((int)this + 1);
  local_418 = param_1;
  local_414 = this;
  if (cVar1 == '\0') {
    local_418 = (int *)param_1[8];
    local_41c = param_1[7];
    iVar9 = *local_418;
    *(undefined1 *)((int)param_1 + 0x26) = 1;
    if (iVar9 == 4) {
      local_414 = (void *)local_418[1];
      iVar9 = local_418[2];
      iVar2 = local_418[3];
      iVar3 = *(int *)((int)this + 0x40);
      *(int *)((int)this + 0x40) = iVar9;
      iVar4 = *(int *)((int)this + 0x44);
      *(int *)((int)this + 0x44) = iVar2;
      if ((iVar9 + -1 == iVar3 && *(void **)((int)this + 0x30) == local_414) && iVar2 + -1 + (uint)(iVar9 != 0) == iVar4
         ) {
        param_1[8] = (int)local_418 + 0xe;
        param_1[7] = local_41c - 0xe;
        *(short *)((int)local_418 + 0xe) = (short)CONCAT31((int3)(local_41c + 0x7ff0),(char)(local_41c + 0x7ff0 >> 8));
        __security_check_cookie(local_c ^ (uint)&local_41c);
        return;
      }
      *(void **)((int)this + 0x30) = local_414;
    }
    param_1[7] = local_41c + 2;
    param_1[8] = (int)local_418 + -2;
    *(short *)((int)local_418 + -2) = (short)CONCAT31((int3)local_41c,(char)(local_41c >> 8));
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (*(char *)((int)this + 3) == '\x02') {
    if (cVar1 == '\x01') {
      FUN_004040a0(this,(int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
    uVar10 = 0;
    do {
      FUN_004040a0(this,(int)param_1);
      uVar10 = uVar10 + param_1[7];
      if (11999 < uVar10) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    local_418[8] = local_418[8] + -5;
    local_418[7] = local_418[7] + 5;
    *(undefined1 *)local_418[8] = 0x17;
    *(undefined1 *)(local_418[8] + 1) = 3;
    *(undefined1 *)(local_418[8] + 2) = 3;
    *(char *)(local_418[8] + 4) = (char)uVar10;
    *(char *)(local_418[8] + 3) = (char)(uVar10 >> 8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (cVar1 == '\x01') {
    do {
      if (DAT_00451dbc == (FARPROC)0x0) {
        lpProcName = "SystemFunction036";
        hModule = LoadLibraryA("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(hModule,lpProcName);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00404715;
      }
      iVar9 = (*DAT_00451dbc)(local_410,0x40);
      cVar11 = (char)unaff_EDI;
      if ((char)iVar9 == '\0') {
LAB_00404715:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
      uVar7 = CONCAT11((char)(undefined2)local_410[0],(char)((ushort)(undefined2)local_410[0] >> 8));
    } while ((uVar7 == 0x1603) || (uVar7 < 0x5dd));
    FUN_004039c0((undefined4 *)((int)this + 0x48),local_410,0x40);
    local_41c = 0x40;
  }
  else {
    if (*(char *)((int)this + 3) == '\0') {
      local_41c = FUN_00403ad0(this,(undefined2 *)local_410);
    }
    else {
      local_41c = FUN_00403ef0(this,(undefined2 *)local_410);
    }
    if (local_41c == 0xffffffff) {
      FUN_0040e010("Trying to send server message before client hello",cVar11);
      param_1[7] = 0;
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
  }
  uVar10 = local_41c;
  *(undefined1 *)((int)this + 3) = 2;
  FUN_00404560(this,param_1);
  uVar8 = local_41c;
  uVar5 = param_1[7];
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x76d) {
    param_1[7] = uVar10;
    puVar6 = (uint *)param_1[8];
    param_1[8] = (int)(param_1 + 0x21);
    FUN_0042e660((uint *)((int)param_1 + local_41c + 0x84),puVar6,uVar5);
    FUN_0042f280((uint *)(param_1 + 0x21),local_410,uVar8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  FUN_0040e010("Outgoing TCP packet too big.",cVar11);
  __security_check_cookie(local_c ^ (uint)&local_41c);
  return;
}


// ----- caller: FUN_00404bd0 @ 00404bd0

void __fastcall FUN_00404bd0(_SINGLE_LIST_ENTRY *param_1)

{
  char cVar1;
  _SINGLE_LIST_ENTRY *p_Var2;
  _SINGLE_LIST_ENTRY *p_Var3;
  _SINGLE_LIST_ENTRY *p_Var4;
  int iVar5;
  PSINGLE_LIST_ENTRY p_Var6;
  uint uVar7;
  _SINGLE_LIST_ENTRY *local_124;
  _SINGLE_LIST_ENTRY local_120;
  _SINGLE_LIST_ENTRY *local_11c;
  _SINGLE_LIST_ENTRY *local_118;
  _SINGLE_LIST_ENTRY *local_114;
  undefined4 local_110 [65];
  uint local_c;
  
  local_c = DAT_0044f008 ^ (uint)&local_124;
  cVar1 = *(char *)((int)&param_1[3].Next + 2);
  local_114 = param_1;
  if (cVar1 == '\x03') {
    if (*(char *)&param_1[3].Next == '\0') {
      p_Var2 = param_1[1].Next;
      p_Var4 = p_Var2[0x26].Next;
      if (p_Var4 == (_SINGLE_LIST_ENTRY *)0x0) {
        p_Var4 = FUN_0040e6a0();
        if (p_Var4 == (PSINGLE_LIST_ENTRY)0x0) goto LAB_00404cb6;
      }
      else {
        p_Var3 = p_Var4->Next;
        p_Var2[0x25].Next = (_SINGLE_LIST_ENTRY *)((int)&p_Var2[0x25].Next[-1].Next + 3);
        p_Var2[0x26].Next = p_Var3;
        p_Var4[8].Next = p_Var4 + 0x21;
        p_Var4[7].Next = (_SINGLE_LIST_ENTRY *)0x0;
      }
      p_Var4->Next = (_SINGLE_LIST_ENTRY *)0x0;
      p_Var4[1].Next = (_SINGLE_LIST_ENTRY *)0x0;
      p_Var4[2].Next = (_SINGLE_LIST_ENTRY *)0x0;
      p_Var4[3].Next = (_SINGLE_LIST_ENTRY *)0x0;
      p_Var4[4].Next = (_SINGLE_LIST_ENTRY *)0x0;
      *(undefined1 *)&p_Var4[9].Next = 0;
      p_Var4[5].Next = param_1;
      local_124 = (_SINGLE_LIST_ENTRY *)0x0;
      local_120.Next = (_SINGLE_LIST_ENTRY *)0x76c;
      local_11c = p_Var4[8].Next;
      iVar5 = WSARecv(param_1[6].Next,&local_120,1,0,&local_124,p_Var4,0);
      if ((iVar5 == 0) || (iVar5 = WSAGetLastError(), iVar5 == 0x3e5)) {
        *(undefined1 *)&param_1[3].Next = 1;
      }
      else {
        FUN_0040e010("TcpSocketWin32:WSARecv failed 0x%X",(char)iVar5);
        InterlockedPushEntrySList((PSLIST_HEADER)&DAT_00451c28,p_Var4);
      }
    }
LAB_00404cb6:
    local_118 = param_1 + 0xc;
    p_Var6 = FUN_00404850((undefined1 *)local_118);
    p_Var2 = local_118;
    while (local_118 = p_Var2, p_Var6 != (PSINGLE_LIST_ENTRY)0x0) {
      *(undefined1 *)((int)&p_Var6[9].Next + 1) = *(undefined1 *)((int)&param_1[4].Next + 1);
      p_Var2 = param_1[0x6f].Next;
      p_Var4 = param_1[0x70].Next;
      p_Var3 = param_1[0x71].Next;
      p_Var6[10].Next = param_1[0x6e].Next;
      p_Var6[0xb].Next = p_Var2;
      p_Var6[0xc].Next = p_Var4;
      p_Var6[0xd].Next = p_Var3;
      p_Var2 = param_1[0x73].Next;
      p_Var6[0xe].Next = param_1[0x72].Next;
      p_Var6[0xf].Next = p_Var2;
      p_Var6[0x10].Next = param_1[0x74].Next;
      p_Var6[5].Next = param_1[2].Next + 10;
      p_Var2 = param_1[2].Next;
      p_Var6->Next = (_SINGLE_LIST_ENTRY *)0x0;
      AcquireSRWLockExclusive((PSRWLOCK)(p_Var2 + 4));
      p_Var2[2].Next = (_SINGLE_LIST_ENTRY *)((int)&(p_Var2[2].Next)->Next + 1);
      (p_Var2[1].Next)->Next = p_Var6;
      p_Var2[1].Next = p_Var6;
      if (p_Var2[3].Next == (_SINGLE_LIST_ENTRY *)0x0) {
        ReleaseSRWLockExclusive((PSRWLOCK)(p_Var2 + 4));
      }
      else {
        p_Var2[3].Next = (_SINGLE_LIST_ENTRY *)0x0;
        ReleaseSRWLockExclusive((PSRWLOCK)(p_Var2 + 4));
        SetEvent(p_Var2[5].Next);
      }
      p_Var6 = FUN_00404850((undefined1 *)(param_1 + 0xc));
      p_Var2 = local_118;
    }
    if (*(char *)&param_1[0xc].Next == '\0') {
      if (*(char *)((int)&param_1[3].Next + 1) == '\0') {
        p_Var4 = param_1[8].Next;
        local_120.Next = param_1 + 8;
        uVar7 = 0;
        if (p_Var4 != (_SINGLE_LIST_ENTRY *)0x0) {
          local_124 = param_1 + 0x75;
          do {
            if (*(char *)((int)&p_Var4[9].Next + 2) == '\0') {
              FUN_00404560(p_Var2,(int *)p_Var4);
            }
            p_Var3 = local_114;
            local_110[uVar7 * 2 + 1] = p_Var4[8].Next;
            local_110[uVar7 * 2] = p_Var4[7].Next;
            uVar7 = uVar7 + 1;
            local_124->Next = p_Var4;
            local_124 = local_124 + 1;
            p_Var4 = p_Var4->Next;
          } while ((uVar7 < 0x20) && (p_Var4 != (_SINGLE_LIST_ENTRY *)0x0));
          (local_120.Next)->Next = p_Var4;
          if (p_Var4 == (_SINGLE_LIST_ENTRY *)0x0) {
            local_114[9].Next = local_120.Next;
          }
          p_Var6 = local_114[0x75].Next;
          *(char *)((int)&local_114[3].Next + 3) = (char)uVar7;
          p_Var6->Next = (_SINGLE_LIST_ENTRY *)0x0;
          p_Var6[1].Next = (_SINGLE_LIST_ENTRY *)0x0;
          p_Var6[2].Next = (_SINGLE_LIST_ENTRY *)0x0;
          p_Var6[3].Next = (_SINGLE_LIST_ENTRY *)0x0;
          p_Var6[4].Next = (_SINGLE_LIST_ENTRY *)0x0;
          *(undefined1 *)&p_Var6[9].Next = 1;
          p_Var6[5].Next = local_114;
          iVar5 = WSASend(local_114[6].Next,local_110,uVar7,0,0,p_Var6,0);
          if ((iVar5 == 0) || (iVar5 = WSAGetLastError(), iVar5 == 0x3e5)) {
            *(undefined1 *)((int)&p_Var3[3].Next + 1) = 1;
            __security_check_cookie(local_c ^ (uint)&local_124);
            return;
          }
          FUN_0040e010("TcpSocketWin32: WSASend failed 0x%X",(char)iVar5);
          InterlockedPushEntrySList((PSLIST_HEADER)&DAT_00451c28,p_Var6);
          if (p_Var3[6].Next != (_SINGLE_LIST_ENTRY *)0xffffffff) {
            CancelIo(p_Var3[6].Next);
          }
          *(undefined1 *)((int)&p_Var3[3].Next + 2) = 1;
          *(undefined1 *)((int)&p_Var3[4].Next + 1) = 0;
          __security_check_cookie(local_c ^ (uint)&local_124);
          return;
        }
      }
      goto LAB_00404ec5;
    }
    if (param_1[6].Next != (_SINGLE_LIST_ENTRY *)0xffffffff) {
      CancelIo(param_1[6].Next);
    }
    *(undefined1 *)((int)&param_1[3].Next + 2) = 1;
    *(undefined1 *)((int)&param_1[4].Next + 1) = 0;
  }
  else {
    if (cVar1 == '\x04') {
      FUN_004049d0((int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_124);
      return;
    }
    if (cVar1 != '\x01') goto LAB_00404ec5;
  }
  if ((uint)*(byte *)((int)&param_1[3].Next + 1) + (uint)*(byte *)&param_1[3].Next == 0) {
    FUN_00404ee0(param_1);
  }
LAB_00404ec5:
  __security_check_cookie(local_c ^ (uint)&local_124);
  return;
}


// ----- caller: FUN_00404560 @ 00404560

void __thiscall FUN_00404560(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  HMODULE hModule;
  int iVar9;
  uint uVar10;
  undefined4 unaff_EDI;
  char *lpProcName;
  char cVar11;
  uint local_41c;
  int *local_418;
  void *local_414;
  uint local_410 [257];
  uint local_c;
  
  cVar11 = (char)unaff_EDI;
  local_c = DAT_0044f008 ^ (uint)&local_41c;
  cVar1 = *(char *)((int)this + 1);
  local_418 = param_1;
  local_414 = this;
  if (cVar1 == '\0') {
    local_418 = (int *)param_1[8];
    local_41c = param_1[7];
    iVar9 = *local_418;
    *(undefined1 *)((int)param_1 + 0x26) = 1;
    if (iVar9 == 4) {
      local_414 = (void *)local_418[1];
      iVar9 = local_418[2];
      iVar2 = local_418[3];
      iVar3 = *(int *)((int)this + 0x40);
      *(int *)((int)this + 0x40) = iVar9;
      iVar4 = *(int *)((int)this + 0x44);
      *(int *)((int)this + 0x44) = iVar2;
      if ((iVar9 + -1 == iVar3 && *(void **)((int)this + 0x30) == local_414) && iVar2 + -1 + (uint)(iVar9 != 0) == iVar4
         ) {
        param_1[8] = (int)local_418 + 0xe;
        param_1[7] = local_41c - 0xe;
        *(short *)((int)local_418 + 0xe) = (short)CONCAT31((int3)(local_41c + 0x7ff0),(char)(local_41c + 0x7ff0 >> 8));
        __security_check_cookie(local_c ^ (uint)&local_41c);
        return;
      }
      *(void **)((int)this + 0x30) = local_414;
    }
    param_1[7] = local_41c + 2;
    param_1[8] = (int)local_418 + -2;
    *(short *)((int)local_418 + -2) = (short)CONCAT31((int3)local_41c,(char)(local_41c >> 8));
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (*(char *)((int)this + 3) == '\x02') {
    if (cVar1 == '\x01') {
      FUN_004040a0(this,(int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
    uVar10 = 0;
    do {
      FUN_004040a0(this,(int)param_1);
      uVar10 = uVar10 + param_1[7];
      if (11999 < uVar10) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    local_418[8] = local_418[8] + -5;
    local_418[7] = local_418[7] + 5;
    *(undefined1 *)local_418[8] = 0x17;
    *(undefined1 *)(local_418[8] + 1) = 3;
    *(undefined1 *)(local_418[8] + 2) = 3;
    *(char *)(local_418[8] + 4) = (char)uVar10;
    *(char *)(local_418[8] + 3) = (char)(uVar10 >> 8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (cVar1 == '\x01') {
    do {
      if (DAT_00451dbc == (FARPROC)0x0) {
        lpProcName = "SystemFunction036";
        hModule = LoadLibraryA("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(hModule,lpProcName);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00404715;
      }
      iVar9 = (*DAT_00451dbc)(local_410,0x40);
      cVar11 = (char)unaff_EDI;
      if ((char)iVar9 == '\0') {
LAB_00404715:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
      uVar7 = CONCAT11((char)(undefined2)local_410[0],(char)((ushort)(undefined2)local_410[0] >> 8));
    } while ((uVar7 == 0x1603) || (uVar7 < 0x5dd));
    FUN_004039c0((undefined4 *)((int)this + 0x48),local_410,0x40);
    local_41c = 0x40;
  }
  else {
    if (*(char *)((int)this + 3) == '\0') {
      local_41c = FUN_00403ad0(this,(undefined2 *)local_410);
    }
    else {
      local_41c = FUN_00403ef0(this,(undefined2 *)local_410);
    }
    if (local_41c == 0xffffffff) {
      FUN_0040e010("Trying to send server message before client hello",cVar11);
      param_1[7] = 0;
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
  }
  uVar10 = local_41c;
  *(undefined1 *)((int)this + 3) = 2;
  FUN_00404560(this,param_1);
  uVar8 = local_41c;
  uVar5 = param_1[7];
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x76d) {
    param_1[7] = uVar10;
    puVar6 = (uint *)param_1[8];
    param_1[8] = (int)(param_1 + 0x21);
    FUN_0042e660((uint *)((int)param_1 + local_41c + 0x84),puVar6,uVar5);
    FUN_0042f280((uint *)(param_1 + 0x21),local_410,uVar8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  FUN_0040e010("Outgoing TCP packet too big.",cVar11);
  __security_check_cookie(local_c ^ (uint)&local_41c);
  return;
}


// ----- callee: FUN_004039c0 @ 004039c0

void __fastcall FUN_004039c0(undefined4 *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [16];
  uint local_10;
  char local_8;
  
  puVar1 = param_1 + 1;
  FUN_00418620(&local_80,0x20,puVar1,0x20);
  FUN_00419bc0(&local_80,param_2,param_3);
  local_60 = local_60 + local_10;
  local_58 = 0xffffffff;
  local_5c = local_5c + (uint)(local_60 < local_10);
  if (local_8 != '\0') {
    local_54 = 0xffffffff;
  }
  _memset((void *)((int)local_50 + local_10),0,0x40 - local_10);
  FUN_004186e0(&local_80,local_50);
  *puVar1 = local_80;
  param_1[2] = uStack_7c;
  param_1[3] = uStack_78;
  param_1[4] = uStack_74;
  param_1[5] = local_70;
  param_1[6] = uStack_6c;
  param_1[7] = uStack_68;
  param_1[8] = uStack_64;
  *param_1 = 0;
  param_1[0x11] = 0x61707865;
  param_1[0x12] = 0x3320646e;
  param_1[0x13] = 0x79622d32;
  param_1[0x14] = 0x6b206574;
  param_1[0x15] = *puVar1;
  param_1[0x16] = param_1[2];
  param_1[0x17] = param_1[3];
  param_1[0x18] = param_1[4];
  param_1[0x19] = param_1[5];
  param_1[0x1a] = param_1[6];
  param_1[0x1b] = param_1[7];
  param_1[0x1c] = param_1[8];
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return;
}


// ----- callee: KERNEL32.DLL::LoadLibraryA @ EXTERNAL:0000005f
// decompile failed: Exception while decompiling EXTERNAL:0000005f: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_004040a0 @ 004040a0

void __thiscall FUN_004040a0(void *this,int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  puVar2 = *(uint **)(param_1 + 0x20);
  uVar9 = *(uint *)(param_1 + 0x1c);
  uVar3 = *puVar2;
  *(undefined1 *)(param_1 + 0x26) = 1;
  if (uVar3 == 4) {
    if (uVar9 < 0x21) {
      *(uint *)((int)this + 0x30) = puVar2[1];
      *(uint *)((int)this + 0x40) = puVar2[2];
      *(uint *)((int)this + 0x44) = puVar2[3];
      uVar9 = FUN_0042c2d0((int)puVar2,uVar9);
    }
    else {
      uVar3 = puVar2[1];
      uVar4 = puVar2[2];
      uVar5 = *(uint *)((int)this + 0x30);
      uVar6 = puVar2[3];
      *(uint *)((int)this + 0x30) = uVar3;
      iVar7 = *(int *)((int)this + 0x40);
      iVar8 = *(int *)((int)this + 0x44);
      *(uint *)((int)this + 0x40) = uVar4;
      *(uint *)((int)this + 0x44) = uVar6;
      if ((uVar4 - 1 == iVar7 && uVar5 == uVar3) && (uVar6 - 1) + (uint)(uVar4 != 0) == iVar8) {
        *(undefined2 **)(param_1 + 0x20) = (undefined2 *)((int)puVar2 + 0xe);
        *(uint *)(param_1 + 0x1c) = uVar9 - 0xe;
        *(undefined2 *)((int)puVar2 + 0xe) = (short)CONCAT31((int3)(uVar9 + 0x7ff0),(char)(uVar9 + 0x7ff0 >> 8));
        uVar9 = 2;
        goto LAB_00404180;
      }
    }
  }
  else if (uVar3 < 4) {
    pbVar1 = (byte *)((int)puVar2 + uVar3 * 4 + 0x23);
    *pbVar1 = *pbVar1 ^ *(byte *)((int)puVar2 + 0xf);
    uVar9 = FUN_0042c2d0((int)puVar2,uVar9);
  }
  *(uint *)(param_1 + 0x1c) = uVar9 + 2;
  *(undefined2 **)(param_1 + 0x20) = (undefined2 *)((int)puVar2 + -2);
  *(undefined2 *)((int)puVar2 + -2) = (short)CONCAT31((int3)uVar9,(char)(uVar9 >> 8));
  uVar9 = 0x12;
LAB_00404180:
  FUN_0041ccb0((uint *)((int)this + 0x48),*(uint **)(param_1 + 0x20),uVar9);
  return;
}


// ----- callee: __security_check_cookie @ 0042cf7c

/* Library Function - Single Match
    @__security_check_cookie@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release
   __fastcall __security_check_cookie,4 */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 != DAT_0044f008) {
                    /* WARNING: Subroutine does not return */
    ___report_gsfailure();
  }
  return;
}


// ----- callee: FUN_0042e660 @ 0042e660

ulonglong __cdecl FUN_0042e660(uint *param_1,uint *param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
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
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint *puVar49;
  undefined4 *puVar50;
  undefined4 *puVar51;
  undefined4 *puVar52;
  undefined4 *puVar53;
  uint *puVar54;
  uint uVar55;
  ulonglong uVar56;
  
  if ((param_2 < param_1) && (param_1 < (uint *)(param_3 + (int)param_2))) {
    puVar50 = (undefined4 *)((int)param_2 + param_3);
    puVar52 = (undefined4 *)((int)param_1 + param_3);
    uVar47 = param_3;
    uVar48 = param_3;
    if (0x1f < param_3) {
      if ((DAT_0044f00c >> 1 & 1) == 0) {
        if (((uint)puVar52 & 3) != 0) {
          uVar47 = (uint)puVar52 & 3;
          param_3 = param_3 - uVar47;
          do {
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            puVar50 = (undefined4 *)((int)puVar50 + -1);
            puVar52 = (undefined4 *)((int)puVar52 - 1);
            uVar47 = uVar47 - 1;
            uVar48 = 0;
          } while (uVar47 != 0);
        }
        uVar47 = param_3;
        if (0x1f < param_3) {
          uVar47 = param_3 >> 2;
          while( true ) {
            if (uVar47 == 0) break;
            uVar47 = uVar47 - 1;
            puVar52[-1] = puVar50[-1];
            puVar50 = puVar50 + -1;
            puVar52 = puVar52 + -1;
          }
          switch(param_3 & 3) {
          case 0:
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 1:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 2:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 3:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            *(undefined1 *)((int)puVar52 - 3) = *(undefined1 *)((int)puVar50 + -3);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          }
        }
      }
      else {
        while( true ) {
          puVar51 = puVar50;
          puVar53 = puVar52;
          if (((uint)puVar52 & 0xf) == 0) break;
          puVar50 = (undefined4 *)((int)puVar50 + -1);
          puVar52 = (undefined4 *)((int)puVar52 + -1);
          *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
          uVar47 = uVar47 - 1;
        }
        do {
          puVar50 = puVar51;
          puVar52 = puVar53;
          if (uVar47 < 0x80) break;
          puVar50 = puVar51 + -0x20;
          puVar52 = puVar53 + -0x20;
          uVar3 = puVar51[-0x1f];
          uVar4 = puVar51[-0x1e];
          uVar5 = puVar51[-0x1d];
          uVar6 = puVar51[-0x1c];
          uVar7 = puVar51[-0x1b];
          uVar8 = puVar51[-0x1a];
          uVar9 = puVar51[-0x19];
          uVar10 = puVar51[-0x18];
          uVar11 = puVar51[-0x17];
          uVar12 = puVar51[-0x16];
          uVar13 = puVar51[-0x15];
          uVar14 = puVar51[-0x14];
          uVar15 = puVar51[-0x13];
          uVar16 = puVar51[-0x12];
          uVar17 = puVar51[-0x11];
          uVar18 = puVar51[-0x10];
          uVar19 = puVar51[-0xf];
          uVar20 = puVar51[-0xe];
          uVar21 = puVar51[-0xd];
          uVar22 = puVar51[-0xc];
          uVar23 = puVar51[-0xb];
          uVar24 = puVar51[-10];
          uVar25 = puVar51[-9];
          uVar26 = puVar51[-8];
          uVar27 = puVar51[-7];
          uVar28 = puVar51[-6];
          uVar29 = puVar51[-5];
          uVar30 = puVar51[-4];
          uVar31 = puVar51[-3];
          uVar32 = puVar51[-2];
          uVar33 = puVar51[-1];
          *puVar52 = *puVar50;
          puVar53[-0x1f] = uVar3;
          puVar53[-0x1e] = uVar4;
          puVar53[-0x1d] = uVar5;
          puVar53[-0x1c] = uVar6;
          puVar53[-0x1b] = uVar7;
          puVar53[-0x1a] = uVar8;
          puVar53[-0x19] = uVar9;
          puVar53[-0x18] = uVar10;
          puVar53[-0x17] = uVar11;
          puVar53[-0x16] = uVar12;
          puVar53[-0x15] = uVar13;
          puVar53[-0x14] = uVar14;
          puVar53[-0x13] = uVar15;
          puVar53[-0x12] = uVar16;
          puVar53[-0x11] = uVar17;
          puVar53[-0x10] = uVar18;
          puVar53[-0xf] = uVar19;
          puVar53[-0xe] = uVar20;
          puVar53[-0xd] = uVar21;
          puVar53[-0xc] = uVar22;
          puVar53[-0xb] = uVar23;
          puVar53[-10] = uVar24;
          puVar53[-9] = uVar25;
          puVar53[-8] = uVar26;
          puVar53[-7] = uVar27;
          puVar53[-6] = uVar28;
          puVar53[-5] = uVar29;
          puVar53[-4] = uVar30;
          puVar53[-3] = uVar31;
          puVar53[-2] = uVar32;
          puVar53[-1] = uVar33;
          uVar47 = uVar47 - 0x80;
          puVar51 = puVar50;
          puVar53 = puVar52;
        } while ((uVar47 & 0xffffff80) != 0);
        puVar51 = puVar50;
        puVar53 = puVar52;
        if (0x1f < uVar47) {
          do {
            puVar50 = puVar51 + -8;
            puVar52 = puVar53 + -8;
            uVar3 = puVar51[-7];
            uVar4 = puVar51[-6];
            uVar5 = puVar51[-5];
            uVar6 = puVar51[-4];
            uVar7 = puVar51[-3];
            uVar8 = puVar51[-2];
            uVar9 = puVar51[-1];
            *puVar52 = *puVar50;
            puVar53[-7] = uVar3;
            puVar53[-6] = uVar4;
            puVar53[-5] = uVar5;
            puVar53[-4] = uVar6;
            puVar53[-3] = uVar7;
            puVar53[-2] = uVar8;
            puVar53[-1] = uVar9;
            uVar47 = uVar47 - 0x20;
            puVar51 = puVar50;
            puVar53 = puVar52;
          } while ((uVar47 & 0xffffffe0) != 0);
        }
      }
    }
    for (; (uVar47 & 0xfffffffc) != 0; uVar47 = uVar47 - 4) {
      puVar52 = puVar52 + -1;
      puVar50 = puVar50 + -1;
      *puVar52 = *puVar50;
    }
    for (; uVar47 != 0; uVar47 = uVar47 - 1) {
      puVar52 = (undefined4 *)((int)puVar52 - 1);
      puVar50 = (undefined4 *)((int)puVar50 + -1);
      *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
    }
    return CONCAT44(uVar48,param_1);
  }
  uVar47 = param_3;
  puVar54 = param_1;
  if (0x1f < param_3) {
    if (param_3 < 0x80) {
      if ((DAT_0044f00c >> 1 & 1) != 0) goto LAB_0042eb2d;
joined_r0x0042e88d:
      for (; ((uint)puVar54 & 3) != 0; puVar54 = (uint *)((int)puVar54 + 1)) {
        *(char *)puVar54 = (char)*param_2;
        param_3 = param_3 - 1;
        param_2 = (uint *)((int)param_2 + 1);
      }
    }
    else {
      if ((DAT_0044fd84 >> 1 & 1) != 0) {
        for (; uVar47 != 0; uVar47 = uVar47 - 1) {
          *(char *)puVar54 = (char)*param_2;
          param_2 = (uint *)((int)param_2 + 1);
          puVar54 = (uint *)((int)puVar54 + 1);
        }
        return CONCAT44(param_3,param_1);
      }
      if (((((uint)param_1 ^ (uint)param_2) & 0xf) == 0) && ((DAT_0044f00c >> 1 & 1) != 0)) {
        if (((uint)param_2 & 0xf) != 0) {
          uVar48 = 0x10 - ((uint)param_2 & 0xf);
          param_3 = param_3 - uVar48;
          for (uVar47 = uVar48 & 3; uVar47 != 0; uVar47 = uVar47 - 1) {
            *(char *)puVar54 = (char)*param_2;
            param_2 = (uint *)((int)param_2 + 1);
            puVar54 = (uint *)((int)puVar54 + 1);
          }
          for (uVar48 = uVar48 >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
            *puVar54 = *param_2;
            param_2 = param_2 + 1;
            puVar54 = puVar54 + 1;
          }
        }
        uVar47 = param_3 & 0x7f;
        uVar48 = param_3 >> 7;
        param_3 = 0;
        if (uVar48 != 0) {
          do {
            uVar55 = param_2[1];
            uVar2 = param_2[2];
            uVar34 = param_2[3];
            uVar35 = param_2[4];
            uVar36 = param_2[5];
            uVar37 = param_2[6];
            uVar38 = param_2[7];
            uVar39 = param_2[8];
            uVar40 = param_2[9];
            uVar41 = param_2[10];
            uVar42 = param_2[0xb];
            uVar43 = param_2[0xc];
            uVar44 = param_2[0xd];
            uVar45 = param_2[0xe];
            uVar46 = param_2[0xf];
            *puVar54 = *param_2;
            puVar54[1] = uVar55;
            puVar54[2] = uVar2;
            puVar54[3] = uVar34;
            puVar54[4] = uVar35;
            puVar54[5] = uVar36;
            puVar54[6] = uVar37;
            puVar54[7] = uVar38;
            puVar54[8] = uVar39;
            puVar54[9] = uVar40;
            puVar54[10] = uVar41;
            puVar54[0xb] = uVar42;
            puVar54[0xc] = uVar43;
            puVar54[0xd] = uVar44;
            puVar54[0xe] = uVar45;
            puVar54[0xf] = uVar46;
            uVar55 = param_2[0x11];
            uVar2 = param_2[0x12];
            uVar34 = param_2[0x13];
            uVar35 = param_2[0x14];
            uVar36 = param_2[0x15];
            uVar37 = param_2[0x16];
            uVar38 = param_2[0x17];
            uVar39 = param_2[0x18];
            uVar40 = param_2[0x19];
            uVar41 = param_2[0x1a];
            uVar42 = param_2[0x1b];
            uVar43 = param_2[0x1c];
            uVar44 = param_2[0x1d];
            uVar45 = param_2[0x1e];
            uVar46 = param_2[0x1f];
            puVar54[0x10] = param_2[0x10];
            puVar54[0x11] = uVar55;
            puVar54[0x12] = uVar2;
            puVar54[0x13] = uVar34;
            puVar54[0x14] = uVar35;
            puVar54[0x15] = uVar36;
            puVar54[0x16] = uVar37;
            puVar54[0x17] = uVar38;
            puVar54[0x18] = uVar39;
            puVar54[0x19] = uVar40;
            puVar54[0x1a] = uVar41;
            puVar54[0x1b] = uVar42;
            puVar54[0x1c] = uVar43;
            puVar54[0x1d] = uVar44;
            puVar54[0x1e] = uVar45;
            puVar54[0x1f] = uVar46;
            param_2 = param_2 + 0x20;
            puVar54 = puVar54 + 0x20;
            uVar48 = uVar48 - 1;
            param_3 = 0;
          } while (uVar48 != 0);
        }
LAB_0042eb2d:
        if (uVar47 == 0) goto LAB_0042eb90;
        for (uVar48 = uVar47 >> 5; param_3 = 0, uVar48 != 0; uVar48 = uVar48 - 1) {
          uVar55 = param_2[1];
          uVar2 = param_2[2];
          uVar34 = param_2[3];
          uVar35 = param_2[4];
          uVar36 = param_2[5];
          uVar37 = param_2[6];
          uVar38 = param_2[7];
          *puVar54 = *param_2;
          puVar54[1] = uVar55;
          puVar54[2] = uVar2;
          puVar54[3] = uVar34;
          puVar54[4] = uVar35;
          puVar54[5] = uVar36;
          puVar54[6] = uVar37;
          puVar54[7] = uVar38;
          param_2 = param_2 + 8;
          puVar54 = puVar54 + 8;
        }
        goto LAB_0042eb5b;
      }
      if (((DAT_0044fd84 & 1) == 0) || (((uint)param_1 & 3) != 0)) goto joined_r0x0042e88d;
      if (((uint)param_2 & 3) == 0) {
        if (((uint)param_1 >> 2 & 1) != 0) {
          uVar47 = *param_2;
          param_3 = param_3 - 4;
          param_2 = param_2 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if (((uint)param_1 >> 3 & 1) != 0) {
          uVar1 = *(undefined8 *)param_2;
          param_3 = param_3 - 8;
          param_2 = param_2 + 2;
          *(undefined8 *)param_1 = uVar1;
          param_1 = param_1 + 2;
        }
        if (((uint)param_2 & 7) == 0) {
          puVar54 = param_2 + -2;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          do {
            puVar49 = puVar54;
            uVar34 = puVar49[4];
            uVar35 = puVar49[5];
            param_3 = param_3 - 0x30;
            uVar36 = puVar49[6];
            uVar37 = puVar49[7];
            uVar38 = puVar49[8];
            uVar39 = puVar49[9];
            uVar55 = puVar49[0xe];
            uVar2 = puVar49[0xf];
            uVar40 = puVar49[10];
            uVar41 = puVar49[0xb];
            uVar42 = puVar49[0xc];
            uVar43 = puVar49[0xd];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar34;
            param_1[3] = uVar35;
            param_1[4] = uVar36;
            param_1[5] = uVar37;
            param_1[6] = uVar38;
            param_1[7] = uVar39;
            param_1[8] = uVar40;
            param_1[9] = uVar41;
            param_1[10] = uVar42;
            param_1[0xb] = uVar43;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar55;
            uVar48 = uVar2;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xe;
        }
        else if (((uint)param_2 >> 3 & 1) == 0) {
          puVar54 = param_2 + -1;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          uVar55 = param_2[2];
          do {
            puVar49 = puVar54;
            uVar36 = puVar49[4];
            param_3 = param_3 - 0x30;
            uVar37 = puVar49[5];
            uVar38 = puVar49[6];
            uVar39 = puVar49[7];
            uVar40 = puVar49[8];
            uVar2 = puVar49[0xd];
            uVar34 = puVar49[0xe];
            uVar35 = puVar49[0xf];
            uVar41 = puVar49[9];
            uVar42 = puVar49[10];
            uVar43 = puVar49[0xb];
            uVar44 = puVar49[0xc];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar55;
            param_1[3] = uVar36;
            param_1[4] = uVar37;
            param_1[5] = uVar38;
            param_1[6] = uVar39;
            param_1[7] = uVar40;
            param_1[8] = uVar41;
            param_1[9] = uVar42;
            param_1[10] = uVar43;
            param_1[0xb] = uVar44;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar2;
            uVar48 = uVar34;
            uVar55 = uVar35;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xd;
        }
        else {
          puVar54 = param_2 + -3;
          uVar47 = *param_2;
          do {
            puVar49 = puVar54;
            uVar55 = puVar49[4];
            uVar2 = puVar49[5];
            uVar34 = puVar49[6];
            param_3 = param_3 - 0x30;
            uVar35 = puVar49[7];
            uVar36 = puVar49[8];
            uVar37 = puVar49[9];
            uVar38 = puVar49[10];
            uVar48 = puVar49[0xf];
            uVar39 = puVar49[0xb];
            uVar40 = puVar49[0xc];
            uVar41 = puVar49[0xd];
            uVar42 = puVar49[0xe];
            *param_1 = uVar47;
            param_1[1] = uVar55;
            param_1[2] = uVar2;
            param_1[3] = uVar34;
            param_1[4] = uVar35;
            param_1[5] = uVar36;
            param_1[6] = uVar37;
            param_1[7] = uVar38;
            param_1[8] = uVar39;
            param_1[9] = uVar40;
            param_1[10] = uVar41;
            param_1[0xb] = uVar42;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar48;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xf;
        }
        for (; 0xf < param_3; param_3 = param_3 - 0x10) {
          uVar47 = *puVar49;
          uVar48 = puVar49[1];
          uVar55 = puVar49[2];
          uVar2 = puVar49[3];
          puVar49 = puVar49 + 4;
          *param_1 = uVar47;
          param_1[1] = uVar48;
          param_1[2] = uVar55;
          param_1[3] = uVar2;
          param_1 = param_1 + 4;
        }
        if ((param_3 >> 2 & 1) != 0) {
          uVar47 = *puVar49;
          param_3 = param_3 - 4;
          puVar49 = puVar49 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if ((param_3 >> 3 & 1) != 0) {
          param_3 = param_3 - 8;
          *(undefined8 *)param_1 = *(undefined8 *)puVar49;
        }
                    /* WARNING: Could not recover jumptable at 0x0042e885. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar56 = (*(code *)(&switchD_0042e8b5::switchdataD_0042e8c4)[param_3])();
        return uVar56;
      }
    }
    uVar47 = param_3;
    if (0x1f < param_3) {
      for (uVar47 = param_3 >> 2; uVar47 != 0; uVar47 = uVar47 - 1) {
        *puVar54 = *param_2;
        param_2 = param_2 + 1;
        puVar54 = puVar54 + 1;
      }
      switch(param_3 & 3) {
      case 0:
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 1:
        *(char *)puVar54 = (char)*param_2;
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 2:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 3:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        *(undefined1 *)((int)puVar54 + 2) = *(undefined1 *)((int)param_2 + 2);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      }
    }
  }
LAB_0042eb5b:
  if ((uVar47 & 0x1f) != 0) {
    for (uVar48 = (uVar47 & 0x1f) >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
      param_3 = *param_2;
      *puVar54 = param_3;
      puVar54 = puVar54 + 1;
      param_2 = param_2 + 1;
    }
    uVar47 = uVar47 & 3;
    if (uVar47 != 0) {
      do {
        *(char *)puVar54 = (char)*param_2;
        param_2 = (uint *)((int)param_2 + 1);
        puVar54 = (uint *)((int)puVar54 + 1);
        uVar47 = uVar47 - 1;
      } while (uVar47 != 0);
    }
  }
LAB_0042eb90:
  return CONCAT44(param_3,param_1);
}


// ----- callee: FUN_0042f280 @ 0042f280

ulonglong __cdecl FUN_0042f280(uint *param_1,uint *param_2,uint param_3)

{
  undefined8 uVar1;
  uint uVar2;
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
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint *puVar49;
  undefined4 *puVar50;
  undefined4 *puVar51;
  undefined4 *puVar52;
  undefined4 *puVar53;
  uint *puVar54;
  uint uVar55;
  ulonglong uVar56;
  
  if ((param_2 < param_1) && (param_1 < (uint *)(param_3 + (int)param_2))) {
    puVar50 = (undefined4 *)((int)param_2 + param_3);
    puVar52 = (undefined4 *)((int)param_1 + param_3);
    uVar47 = param_3;
    uVar48 = param_3;
    if (0x1f < param_3) {
      if ((DAT_0044f00c >> 1 & 1) == 0) {
        if (((uint)puVar52 & 3) != 0) {
          uVar47 = (uint)puVar52 & 3;
          param_3 = param_3 - uVar47;
          do {
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            puVar50 = (undefined4 *)((int)puVar50 + -1);
            puVar52 = (undefined4 *)((int)puVar52 - 1);
            uVar47 = uVar47 - 1;
            uVar48 = 0;
          } while (uVar47 != 0);
        }
        uVar47 = param_3;
        if (0x1f < param_3) {
          uVar47 = param_3 >> 2;
          while( true ) {
            if (uVar47 == 0) break;
            uVar47 = uVar47 - 1;
            puVar52[-1] = puVar50[-1];
            puVar50 = puVar50 + -1;
            puVar52 = puVar52 + -1;
          }
          switch(param_3 & 3) {
          case 0:
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 1:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 2:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          case 3:
            *(undefined1 *)((int)puVar52 - 1) = *(undefined1 *)((int)puVar50 + -1);
            *(undefined1 *)((int)puVar52 - 2) = *(undefined1 *)((int)puVar50 + -2);
            *(undefined1 *)((int)puVar52 - 3) = *(undefined1 *)((int)puVar50 + -3);
            return CONCAT44(param_3,param_1) & 0x3ffffffff;
          }
        }
      }
      else {
        while( true ) {
          puVar51 = puVar50;
          puVar53 = puVar52;
          if (((uint)puVar52 & 0xf) == 0) break;
          puVar50 = (undefined4 *)((int)puVar50 + -1);
          puVar52 = (undefined4 *)((int)puVar52 + -1);
          *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
          uVar47 = uVar47 - 1;
        }
        do {
          puVar50 = puVar51;
          puVar52 = puVar53;
          if (uVar47 < 0x80) break;
          puVar50 = puVar51 + -0x20;
          puVar52 = puVar53 + -0x20;
          uVar3 = puVar51[-0x1f];
          uVar4 = puVar51[-0x1e];
          uVar5 = puVar51[-0x1d];
          uVar6 = puVar51[-0x1c];
          uVar7 = puVar51[-0x1b];
          uVar8 = puVar51[-0x1a];
          uVar9 = puVar51[-0x19];
          uVar10 = puVar51[-0x18];
          uVar11 = puVar51[-0x17];
          uVar12 = puVar51[-0x16];
          uVar13 = puVar51[-0x15];
          uVar14 = puVar51[-0x14];
          uVar15 = puVar51[-0x13];
          uVar16 = puVar51[-0x12];
          uVar17 = puVar51[-0x11];
          uVar18 = puVar51[-0x10];
          uVar19 = puVar51[-0xf];
          uVar20 = puVar51[-0xe];
          uVar21 = puVar51[-0xd];
          uVar22 = puVar51[-0xc];
          uVar23 = puVar51[-0xb];
          uVar24 = puVar51[-10];
          uVar25 = puVar51[-9];
          uVar26 = puVar51[-8];
          uVar27 = puVar51[-7];
          uVar28 = puVar51[-6];
          uVar29 = puVar51[-5];
          uVar30 = puVar51[-4];
          uVar31 = puVar51[-3];
          uVar32 = puVar51[-2];
          uVar33 = puVar51[-1];
          *puVar52 = *puVar50;
          puVar53[-0x1f] = uVar3;
          puVar53[-0x1e] = uVar4;
          puVar53[-0x1d] = uVar5;
          puVar53[-0x1c] = uVar6;
          puVar53[-0x1b] = uVar7;
          puVar53[-0x1a] = uVar8;
          puVar53[-0x19] = uVar9;
          puVar53[-0x18] = uVar10;
          puVar53[-0x17] = uVar11;
          puVar53[-0x16] = uVar12;
          puVar53[-0x15] = uVar13;
          puVar53[-0x14] = uVar14;
          puVar53[-0x13] = uVar15;
          puVar53[-0x12] = uVar16;
          puVar53[-0x11] = uVar17;
          puVar53[-0x10] = uVar18;
          puVar53[-0xf] = uVar19;
          puVar53[-0xe] = uVar20;
          puVar53[-0xd] = uVar21;
          puVar53[-0xc] = uVar22;
          puVar53[-0xb] = uVar23;
          puVar53[-10] = uVar24;
          puVar53[-9] = uVar25;
          puVar53[-8] = uVar26;
          puVar53[-7] = uVar27;
          puVar53[-6] = uVar28;
          puVar53[-5] = uVar29;
          puVar53[-4] = uVar30;
          puVar53[-3] = uVar31;
          puVar53[-2] = uVar32;
          puVar53[-1] = uVar33;
          uVar47 = uVar47 - 0x80;
          puVar51 = puVar50;
          puVar53 = puVar52;
        } while ((uVar47 & 0xffffff80) != 0);
        puVar51 = puVar50;
        puVar53 = puVar52;
        if (0x1f < uVar47) {
          do {
            puVar50 = puVar51 + -8;
            puVar52 = puVar53 + -8;
            uVar3 = puVar51[-7];
            uVar4 = puVar51[-6];
            uVar5 = puVar51[-5];
            uVar6 = puVar51[-4];
            uVar7 = puVar51[-3];
            uVar8 = puVar51[-2];
            uVar9 = puVar51[-1];
            *puVar52 = *puVar50;
            puVar53[-7] = uVar3;
            puVar53[-6] = uVar4;
            puVar53[-5] = uVar5;
            puVar53[-4] = uVar6;
            puVar53[-3] = uVar7;
            puVar53[-2] = uVar8;
            puVar53[-1] = uVar9;
            uVar47 = uVar47 - 0x20;
            puVar51 = puVar50;
            puVar53 = puVar52;
          } while ((uVar47 & 0xffffffe0) != 0);
        }
      }
    }
    for (; (uVar47 & 0xfffffffc) != 0; uVar47 = uVar47 - 4) {
      puVar52 = puVar52 + -1;
      puVar50 = puVar50 + -1;
      *puVar52 = *puVar50;
    }
    for (; uVar47 != 0; uVar47 = uVar47 - 1) {
      puVar52 = (undefined4 *)((int)puVar52 - 1);
      puVar50 = (undefined4 *)((int)puVar50 + -1);
      *(undefined1 *)puVar52 = *(undefined1 *)puVar50;
    }
    return CONCAT44(uVar48,param_1);
  }
  uVar47 = param_3;
  puVar54 = param_1;
  if (0x1f < param_3) {
    if (param_3 < 0x80) {
      if ((DAT_0044f00c >> 1 & 1) != 0) goto LAB_0042f74d;
joined_r0x0042f4ad:
      for (; ((uint)puVar54 & 3) != 0; puVar54 = (uint *)((int)puVar54 + 1)) {
        *(char *)puVar54 = (char)*param_2;
        param_3 = param_3 - 1;
        param_2 = (uint *)((int)param_2 + 1);
      }
    }
    else {
      if ((DAT_0044fd84 >> 1 & 1) != 0) {
        for (; uVar47 != 0; uVar47 = uVar47 - 1) {
          *(char *)puVar54 = (char)*param_2;
          param_2 = (uint *)((int)param_2 + 1);
          puVar54 = (uint *)((int)puVar54 + 1);
        }
        return CONCAT44(param_3,param_1);
      }
      if (((((uint)param_1 ^ (uint)param_2) & 0xf) == 0) && ((DAT_0044f00c >> 1 & 1) != 0)) {
        if (((uint)param_2 & 0xf) != 0) {
          uVar48 = 0x10 - ((uint)param_2 & 0xf);
          param_3 = param_3 - uVar48;
          for (uVar47 = uVar48 & 3; uVar47 != 0; uVar47 = uVar47 - 1) {
            *(char *)puVar54 = (char)*param_2;
            param_2 = (uint *)((int)param_2 + 1);
            puVar54 = (uint *)((int)puVar54 + 1);
          }
          for (uVar48 = uVar48 >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
            *puVar54 = *param_2;
            param_2 = param_2 + 1;
            puVar54 = puVar54 + 1;
          }
        }
        uVar47 = param_3 & 0x7f;
        uVar48 = param_3 >> 7;
        param_3 = 0;
        if (uVar48 != 0) {
          do {
            uVar55 = param_2[1];
            uVar2 = param_2[2];
            uVar34 = param_2[3];
            uVar35 = param_2[4];
            uVar36 = param_2[5];
            uVar37 = param_2[6];
            uVar38 = param_2[7];
            uVar39 = param_2[8];
            uVar40 = param_2[9];
            uVar41 = param_2[10];
            uVar42 = param_2[0xb];
            uVar43 = param_2[0xc];
            uVar44 = param_2[0xd];
            uVar45 = param_2[0xe];
            uVar46 = param_2[0xf];
            *puVar54 = *param_2;
            puVar54[1] = uVar55;
            puVar54[2] = uVar2;
            puVar54[3] = uVar34;
            puVar54[4] = uVar35;
            puVar54[5] = uVar36;
            puVar54[6] = uVar37;
            puVar54[7] = uVar38;
            puVar54[8] = uVar39;
            puVar54[9] = uVar40;
            puVar54[10] = uVar41;
            puVar54[0xb] = uVar42;
            puVar54[0xc] = uVar43;
            puVar54[0xd] = uVar44;
            puVar54[0xe] = uVar45;
            puVar54[0xf] = uVar46;
            uVar55 = param_2[0x11];
            uVar2 = param_2[0x12];
            uVar34 = param_2[0x13];
            uVar35 = param_2[0x14];
            uVar36 = param_2[0x15];
            uVar37 = param_2[0x16];
            uVar38 = param_2[0x17];
            uVar39 = param_2[0x18];
            uVar40 = param_2[0x19];
            uVar41 = param_2[0x1a];
            uVar42 = param_2[0x1b];
            uVar43 = param_2[0x1c];
            uVar44 = param_2[0x1d];
            uVar45 = param_2[0x1e];
            uVar46 = param_2[0x1f];
            puVar54[0x10] = param_2[0x10];
            puVar54[0x11] = uVar55;
            puVar54[0x12] = uVar2;
            puVar54[0x13] = uVar34;
            puVar54[0x14] = uVar35;
            puVar54[0x15] = uVar36;
            puVar54[0x16] = uVar37;
            puVar54[0x17] = uVar38;
            puVar54[0x18] = uVar39;
            puVar54[0x19] = uVar40;
            puVar54[0x1a] = uVar41;
            puVar54[0x1b] = uVar42;
            puVar54[0x1c] = uVar43;
            puVar54[0x1d] = uVar44;
            puVar54[0x1e] = uVar45;
            puVar54[0x1f] = uVar46;
            param_2 = param_2 + 0x20;
            puVar54 = puVar54 + 0x20;
            uVar48 = uVar48 - 1;
            param_3 = 0;
          } while (uVar48 != 0);
        }
LAB_0042f74d:
        if (uVar47 == 0) goto LAB_0042f7b0;
        for (uVar48 = uVar47 >> 5; param_3 = 0, uVar48 != 0; uVar48 = uVar48 - 1) {
          uVar55 = param_2[1];
          uVar2 = param_2[2];
          uVar34 = param_2[3];
          uVar35 = param_2[4];
          uVar36 = param_2[5];
          uVar37 = param_2[6];
          uVar38 = param_2[7];
          *puVar54 = *param_2;
          puVar54[1] = uVar55;
          puVar54[2] = uVar2;
          puVar54[3] = uVar34;
          puVar54[4] = uVar35;
          puVar54[5] = uVar36;
          puVar54[6] = uVar37;
          puVar54[7] = uVar38;
          param_2 = param_2 + 8;
          puVar54 = puVar54 + 8;
        }
        goto LAB_0042f77b;
      }
      if (((DAT_0044fd84 & 1) == 0) || (((uint)param_1 & 3) != 0)) goto joined_r0x0042f4ad;
      if (((uint)param_2 & 3) == 0) {
        if (((uint)param_1 >> 2 & 1) != 0) {
          uVar47 = *param_2;
          param_3 = param_3 - 4;
          param_2 = param_2 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if (((uint)param_1 >> 3 & 1) != 0) {
          uVar1 = *(undefined8 *)param_2;
          param_3 = param_3 - 8;
          param_2 = param_2 + 2;
          *(undefined8 *)param_1 = uVar1;
          param_1 = param_1 + 2;
        }
        if (((uint)param_2 & 7) == 0) {
          puVar54 = param_2 + -2;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          do {
            puVar49 = puVar54;
            uVar34 = puVar49[4];
            uVar35 = puVar49[5];
            param_3 = param_3 - 0x30;
            uVar36 = puVar49[6];
            uVar37 = puVar49[7];
            uVar38 = puVar49[8];
            uVar39 = puVar49[9];
            uVar55 = puVar49[0xe];
            uVar2 = puVar49[0xf];
            uVar40 = puVar49[10];
            uVar41 = puVar49[0xb];
            uVar42 = puVar49[0xc];
            uVar43 = puVar49[0xd];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar34;
            param_1[3] = uVar35;
            param_1[4] = uVar36;
            param_1[5] = uVar37;
            param_1[6] = uVar38;
            param_1[7] = uVar39;
            param_1[8] = uVar40;
            param_1[9] = uVar41;
            param_1[10] = uVar42;
            param_1[0xb] = uVar43;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar55;
            uVar48 = uVar2;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xe;
        }
        else if (((uint)param_2 >> 3 & 1) == 0) {
          puVar54 = param_2 + -1;
          uVar47 = *param_2;
          uVar48 = param_2[1];
          uVar55 = param_2[2];
          do {
            puVar49 = puVar54;
            uVar36 = puVar49[4];
            param_3 = param_3 - 0x30;
            uVar37 = puVar49[5];
            uVar38 = puVar49[6];
            uVar39 = puVar49[7];
            uVar40 = puVar49[8];
            uVar2 = puVar49[0xd];
            uVar34 = puVar49[0xe];
            uVar35 = puVar49[0xf];
            uVar41 = puVar49[9];
            uVar42 = puVar49[10];
            uVar43 = puVar49[0xb];
            uVar44 = puVar49[0xc];
            *param_1 = uVar47;
            param_1[1] = uVar48;
            param_1[2] = uVar55;
            param_1[3] = uVar36;
            param_1[4] = uVar37;
            param_1[5] = uVar38;
            param_1[6] = uVar39;
            param_1[7] = uVar40;
            param_1[8] = uVar41;
            param_1[9] = uVar42;
            param_1[10] = uVar43;
            param_1[0xb] = uVar44;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar2;
            uVar48 = uVar34;
            uVar55 = uVar35;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xd;
        }
        else {
          puVar54 = param_2 + -3;
          uVar47 = *param_2;
          do {
            puVar49 = puVar54;
            uVar55 = puVar49[4];
            uVar2 = puVar49[5];
            uVar34 = puVar49[6];
            param_3 = param_3 - 0x30;
            uVar35 = puVar49[7];
            uVar36 = puVar49[8];
            uVar37 = puVar49[9];
            uVar38 = puVar49[10];
            uVar48 = puVar49[0xf];
            uVar39 = puVar49[0xb];
            uVar40 = puVar49[0xc];
            uVar41 = puVar49[0xd];
            uVar42 = puVar49[0xe];
            *param_1 = uVar47;
            param_1[1] = uVar55;
            param_1[2] = uVar2;
            param_1[3] = uVar34;
            param_1[4] = uVar35;
            param_1[5] = uVar36;
            param_1[6] = uVar37;
            param_1[7] = uVar38;
            param_1[8] = uVar39;
            param_1[9] = uVar40;
            param_1[10] = uVar41;
            param_1[0xb] = uVar42;
            param_1 = param_1 + 0xc;
            puVar54 = puVar49 + 0xc;
            uVar47 = uVar48;
          } while (0x2f < param_3);
          puVar49 = puVar49 + 0xf;
        }
        for (; 0xf < param_3; param_3 = param_3 - 0x10) {
          uVar47 = *puVar49;
          uVar48 = puVar49[1];
          uVar55 = puVar49[2];
          uVar2 = puVar49[3];
          puVar49 = puVar49 + 4;
          *param_1 = uVar47;
          param_1[1] = uVar48;
          param_1[2] = uVar55;
          param_1[3] = uVar2;
          param_1 = param_1 + 4;
        }
        if ((param_3 >> 2 & 1) != 0) {
          uVar47 = *puVar49;
          param_3 = param_3 - 4;
          puVar49 = puVar49 + 1;
          *param_1 = uVar47;
          param_1 = param_1 + 1;
        }
        if ((param_3 >> 3 & 1) != 0) {
          param_3 = param_3 - 8;
          *(undefined8 *)param_1 = *(undefined8 *)puVar49;
        }
                    /* WARNING: Could not recover jumptable at 0x0042f4a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar56 = (*(code *)(&switchD_0042f4d5::switchdataD_0042f4e4)[param_3])();
        return uVar56;
      }
    }
    uVar47 = param_3;
    if (0x1f < param_3) {
      for (uVar47 = param_3 >> 2; uVar47 != 0; uVar47 = uVar47 - 1) {
        *puVar54 = *param_2;
        param_2 = param_2 + 1;
        puVar54 = puVar54 + 1;
      }
      switch(param_3 & 3) {
      case 0:
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 1:
        *(char *)puVar54 = (char)*param_2;
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 2:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      case 3:
        *(char *)puVar54 = (char)*param_2;
        *(undefined1 *)((int)puVar54 + 1) = *(undefined1 *)((int)param_2 + 1);
        *(undefined1 *)((int)puVar54 + 2) = *(undefined1 *)((int)param_2 + 2);
        return CONCAT44(param_3,param_1) & 0x3ffffffff;
      }
    }
  }
LAB_0042f77b:
  if ((uVar47 & 0x1f) != 0) {
    for (uVar48 = (uVar47 & 0x1f) >> 2; uVar48 != 0; uVar48 = uVar48 - 1) {
      param_3 = *param_2;
      *puVar54 = param_3;
      puVar54 = puVar54 + 1;
      param_2 = param_2 + 1;
    }
    uVar47 = uVar47 & 3;
    if (uVar47 != 0) {
      do {
        *(char *)puVar54 = (char)*param_2;
        param_2 = (uint *)((int)param_2 + 1);
        puVar54 = (uint *)((int)puVar54 + 1);
        uVar47 = uVar47 - 1;
      } while (uVar47 != 0);
    }
  }
LAB_0042f7b0:
  return CONCAT44(param_3,param_1);
}


// ----- callee: FUN_00403ad0 @ 00403ad0

int __thiscall FUN_00403ad0(void *this,undefined2 *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  HMODULE pHVar4;
  int iVar5;
  FARPROC pFVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char *pcVar10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  *param_1 = 0x316;
  pcVar9 = LoadLibraryA_exref;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)((int)param_1 + 5) = 1;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 9) = 0x303;
  if (DAT_00451dbc == (FARPROC)0x0) {
    pcVar10 = "SystemFunction036";
    pHVar4 = LoadLibraryA("ADVAPI32.DLL");
    DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
    if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
  }
  iVar5 = (*DAT_00451dbc)((int)param_1 + 0xb,0x20);
  pFVar6 = DAT_00451dbc;
  if ((char)iVar5 != '\0') {
    *(undefined1 *)((int)param_1 + 0x2b) = 0x20;
    if (pFVar6 == (FARPROC)0x0) {
      pcVar10 = "SystemFunction036";
      pHVar4 = LoadLibraryA("ADVAPI32.DLL");
      pFVar6 = GetProcAddress(pHVar4,pcVar10);
      DAT_00451dbc = pFVar6;
      if (pFVar6 == (FARPROC)0x0) goto LAB_00403ed4;
    }
    iVar5 = (*pFVar6)(param_1 + 0x16,0x20);
    if ((char)iVar5 != '\0') {
      if (*(char *)((int)this + 1) == '\x02') {
        local_c = param_1 + 0x3a;
        *(undefined4 *)(param_1 + 0x26) = 0x1132400;
        *(undefined4 *)(param_1 + 0x28) = 0x2130313;
        *(undefined4 *)(param_1 + 0x2a) = 0x2fc02bc0;
        *(undefined4 *)(param_1 + 0x2c) = 0xa8cca9cc;
        *(undefined4 *)(param_1 + 0x2e) = 0x30c02cc0;
        *(undefined4 *)(param_1 + 0x30) = 0x9c00ac0;
        *(undefined4 *)(param_1 + 0x32) = 0x14c013c0;
        *(undefined4 *)(param_1 + 0x34) = 0x39003300;
        *(undefined8 *)(param_1 + 0x36) = 0x10a0035002f00;
        *(undefined4 *)(param_1 + 0x3b) = 0x16000000;
        *(undefined4 *)(param_1 + 0x3d) = 0x1400;
        *(undefined4 *)(param_1 + 0x3f) = 0x616e6511;
        builtin_strncpy((char *)(param_1 + 0x41),"bled",4);
        builtin_strncpy((char *)(param_1 + 0x43),".tls",4);
        builtin_strncpy((char *)(param_1 + 0x45),"13.c",4);
        *(undefined4 *)(param_1 + 0x47) = 0x17006d6f;
        *(undefined4 *)(param_1 + 0x49) = 0x1ff0000;
        param_1[0x4b] = 0x100;
        *(undefined1 *)(param_1 + 0x4c) = 0;
        *(undefined4 *)((int)param_1 + 0x99) = 0xe000a00;
        *(undefined4 *)((int)param_1 + 0x9d) = 0x1d000c00;
        *(undefined4 *)((int)param_1 + 0xa1) = 0x18001700;
        *(undefined4 *)((int)param_1 + 0xa5) = 0x11900;
        *(undefined4 *)((int)param_1 + 0xa9) = 0xb000101;
        *(undefined4 *)((int)param_1 + 0xad) = 0x10200;
        *(undefined4 *)((int)param_1 + 0xb1) = 0xe001000;
        *(undefined4 *)((int)param_1 + 0xb5) = 0x68020c00;
        *(undefined4 *)((int)param_1 + 0xb9) = 0x74680832;
        *(undefined4 *)((int)param_1 + 0xbd) = 0x312f7074;
        *(undefined4 *)((int)param_1 + 0xc1) = 0x500312e;
        *(undefined4 *)((int)param_1 + 0xc5) = 0x10500;
        *(undefined8 *)((int)param_1 + 0xc9) = 0x6b003300000000;
        *(undefined4 *)((int)param_1 + 0xd1) = 0x1d0069;
        *(undefined1 *)((int)param_1 + 0xd5) = 0x20;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)(param_1 + 0x6b,0x20);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        *(byte *)((int)param_1 + 0xf5) = *(byte *)((int)param_1 + 0xf5) & 0x7f;
        *(undefined4 *)(param_1 + 0x7b) = 0x41001700;
        *(undefined1 *)(param_1 + 0x7d) = 4;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)((int)param_1 + 0xfb,0x40);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        local_8 = param_1 + 0xbe;
        *(undefined4 *)((int)param_1 + 0x13b) = 0x2a00;
        *(undefined4 *)((int)param_1 + 0x13f) = 0x9002b00;
        *(undefined4 *)((int)param_1 + 0x143) = 0x3040308;
        *(undefined4 *)((int)param_1 + 0x147) = 0x3020303;
        *(undefined4 *)((int)param_1 + 0x14b) = 0xd0001;
        *(undefined4 *)((int)param_1 + 0x14f) = 0x4160018;
        *(undefined4 *)((int)param_1 + 0x153) = 0x6030503;
        *(undefined4 *)((int)param_1 + 0x157) = 0x8040803;
        *(undefined4 *)((int)param_1 + 0x15b) = 0x4060805;
        *(undefined4 *)((int)param_1 + 0x15f) = 0x6010501;
        *(undefined4 *)((int)param_1 + 0x163) = 0x2030201;
        *(undefined4 *)((int)param_1 + 0x167) = 0x2d0001;
        *(undefined4 *)((int)param_1 + 0x16b) = 0x10102;
        *(undefined4 *)((int)param_1 + 0x16f) = 0x4002001c;
        *(undefined4 *)((int)param_1 + 0x173) = 0x290001;
        *(undefined4 *)((int)param_1 + 0x177) = 0xc600eb;
        *(undefined1 *)((int)param_1 + 0x17b) = 0xc0;
      }
      else {
        local_c = param_1 + 0x39;
        *(undefined4 *)(param_1 + 0x26) = 0xdada2200;
        *(undefined4 *)(param_1 + 0x28) = 0x2130113;
        *(undefined4 *)(param_1 + 0x2a) = 0x2bc00313;
        *(undefined4 *)(param_1 + 0x2c) = 0x2cc02fc0;
        *(undefined4 *)(param_1 + 0x2e) = 0xa9cc30c0;
        *(undefined4 *)(param_1 + 0x30) = 0x13c0a8cc;
        *(undefined4 *)(param_1 + 0x32) = 0x9c0014c0;
        *(undefined4 *)(param_1 + 0x34) = 0x2f009d00;
        *(undefined4 *)(param_1 + 0x36) = 0xa003500;
        param_1[0x38] = 1;
        *(undefined4 *)(param_1 + 0x3a) = 0xaaaa;
        *(undefined4 *)(param_1 + 0x3c) = 0x16000000;
        *(undefined4 *)(param_1 + 0x3e) = 0x1400;
        *(undefined4 *)(param_1 + 0x40) = 0x616e6511;
        builtin_strncpy((char *)(param_1 + 0x42),"bled",4);
        builtin_strncpy((char *)(param_1 + 0x44),".tls",4);
        builtin_strncpy((char *)(param_1 + 0x46),"13.c",4);
        *(undefined4 *)(param_1 + 0x48) = 0x17006d6f;
        *(undefined4 *)(param_1 + 0x4a) = 0x1ff0000;
        param_1[0x4c] = 0x100;
        *(undefined1 *)(param_1 + 0x4d) = 0;
        puVar7 = &DAT_00448488;
        puVar8 = (undefined4 *)((int)param_1 + 0x9b);
        for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = *(undefined2 *)puVar7;
        pcVar9 = LoadLibraryA_exref;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)((int)param_1 + 0xf9,0x20);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) & 0x7f;
        local_8 = param_1 + 0xa1;
        *(undefined4 *)((int)param_1 + 0x119) = 0x2002d00;
        *(undefined4 *)((int)param_1 + 0x11d) = 0x2b000101;
        *(undefined4 *)((int)param_1 + 0x121) = 0x1a0a0b00;
        *(undefined4 *)((int)param_1 + 0x125) = 0x304031a;
        *(undefined4 *)((int)param_1 + 0x129) = 0x3020303;
        *(undefined4 *)((int)param_1 + 0x12d) = 0x1b0001;
        *(undefined4 *)((int)param_1 + 0x131) = 0x2000203;
        *(undefined4 *)((int)param_1 + 0x135) = 0x100eaea;
        *(undefined8 *)((int)param_1 + 0x139) = 0xc600eb00290000;
        *(undefined1 *)((int)param_1 + 0x141) = 0xc0;
      }
      puVar3 = local_8;
      if (DAT_00451dbc == (FARPROC)0x0) {
        pcVar10 = "SystemFunction036";
        pHVar4 = (HMODULE)(*pcVar9)("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
      }
      iVar5 = (*DAT_00451dbc)(local_8,0xc4);
      if ((char)iVar5 != '\0') {
        puVar2 = local_8 + 99;
        local_8[0x62] = 0x2100;
        uVar1 = (int)local_8 + 0xe7;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = (HMODULE)(*pcVar9)("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        local_8 = (undefined2 *)(uVar1 & 0xffff);
        iVar5 = (*DAT_00451dbc)(puVar2,0x21);
        if ((char)iVar5 != '\0') {
          iVar5 = ((uVar1 & 0xffff) - ((uint)param_1 & 0xffff)) + -5;
          *(short *)((int)param_1 + 3) = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          iVar5 = ((int)local_8 - ((uint)param_1 & 0xffff)) + -9;
          *(short *)((int)param_1 + 7) = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          iVar5 = ((uVar1 & 0xffff) - (int)local_c) + -2;
          *local_c = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          FUN_004039c0((undefined4 *)((int)this + 0x48),(uint *)((int)param_1 + 5),(uVar1 - (int)param_1) - 5);
          *(undefined4 *)((int)puVar3 + 0xe7) = 0x30314;
          *(undefined2 *)((int)puVar3 + 0xeb) = 0x101;
          return (uVar1 - (int)param_1) + 6;
        }
      }
    }
  }
LAB_00403ed4:
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}


// ----- callee: FUN_00404560 @ 00404560

void __thiscall FUN_00404560(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  HMODULE hModule;
  int iVar9;
  uint uVar10;
  undefined4 unaff_EDI;
  char *lpProcName;
  char cVar11;
  uint local_41c;
  int *local_418;
  void *local_414;
  uint local_410 [257];
  uint local_c;
  
  cVar11 = (char)unaff_EDI;
  local_c = DAT_0044f008 ^ (uint)&local_41c;
  cVar1 = *(char *)((int)this + 1);
  local_418 = param_1;
  local_414 = this;
  if (cVar1 == '\0') {
    local_418 = (int *)param_1[8];
    local_41c = param_1[7];
    iVar9 = *local_418;
    *(undefined1 *)((int)param_1 + 0x26) = 1;
    if (iVar9 == 4) {
      local_414 = (void *)local_418[1];
      iVar9 = local_418[2];
      iVar2 = local_418[3];
      iVar3 = *(int *)((int)this + 0x40);
      *(int *)((int)this + 0x40) = iVar9;
      iVar4 = *(int *)((int)this + 0x44);
      *(int *)((int)this + 0x44) = iVar2;
      if ((iVar9 + -1 == iVar3 && *(void **)((int)this + 0x30) == local_414) && iVar2 + -1 + (uint)(iVar9 != 0) == iVar4
         ) {
        param_1[8] = (int)local_418 + 0xe;
        param_1[7] = local_41c - 0xe;
        *(short *)((int)local_418 + 0xe) = (short)CONCAT31((int3)(local_41c + 0x7ff0),(char)(local_41c + 0x7ff0 >> 8));
        __security_check_cookie(local_c ^ (uint)&local_41c);
        return;
      }
      *(void **)((int)this + 0x30) = local_414;
    }
    param_1[7] = local_41c + 2;
    param_1[8] = (int)local_418 + -2;
    *(short *)((int)local_418 + -2) = (short)CONCAT31((int3)local_41c,(char)(local_41c >> 8));
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (*(char *)((int)this + 3) == '\x02') {
    if (cVar1 == '\x01') {
      FUN_004040a0(this,(int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
    uVar10 = 0;
    do {
      FUN_004040a0(this,(int)param_1);
      uVar10 = uVar10 + param_1[7];
      if (11999 < uVar10) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    local_418[8] = local_418[8] + -5;
    local_418[7] = local_418[7] + 5;
    *(undefined1 *)local_418[8] = 0x17;
    *(undefined1 *)(local_418[8] + 1) = 3;
    *(undefined1 *)(local_418[8] + 2) = 3;
    *(char *)(local_418[8] + 4) = (char)uVar10;
    *(char *)(local_418[8] + 3) = (char)(uVar10 >> 8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (cVar1 == '\x01') {
    do {
      if (DAT_00451dbc == (FARPROC)0x0) {
        lpProcName = "SystemFunction036";
        hModule = LoadLibraryA("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(hModule,lpProcName);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00404715;
      }
      iVar9 = (*DAT_00451dbc)(local_410,0x40);
      cVar11 = (char)unaff_EDI;
      if ((char)iVar9 == '\0') {
LAB_00404715:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
      uVar7 = CONCAT11((char)(undefined2)local_410[0],(char)((ushort)(undefined2)local_410[0] >> 8));
    } while ((uVar7 == 0x1603) || (uVar7 < 0x5dd));
    FUN_004039c0((undefined4 *)((int)this + 0x48),local_410,0x40);
    local_41c = 0x40;
  }
  else {
    if (*(char *)((int)this + 3) == '\0') {
      local_41c = FUN_00403ad0(this,(undefined2 *)local_410);
    }
    else {
      local_41c = FUN_00403ef0(this,(undefined2 *)local_410);
    }
    if (local_41c == 0xffffffff) {
      FUN_0040e010("Trying to send server message before client hello",cVar11);
      param_1[7] = 0;
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
  }
  uVar10 = local_41c;
  *(undefined1 *)((int)this + 3) = 2;
  FUN_00404560(this,param_1);
  uVar8 = local_41c;
  uVar5 = param_1[7];
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x76d) {
    param_1[7] = uVar10;
    puVar6 = (uint *)param_1[8];
    param_1[8] = (int)(param_1 + 0x21);
    FUN_0042e660((uint *)((int)param_1 + local_41c + 0x84),puVar6,uVar5);
    FUN_0042f280((uint *)(param_1 + 0x21),local_410,uVar8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  FUN_0040e010("Outgoing TCP packet too big.",cVar11);
  __security_check_cookie(local_c ^ (uint)&local_41c);
  return;
}


// ----- callee: FUN_00403ef0 @ 00403ef0

undefined4 __thiscall FUN_00403ef0(void *this,undefined2 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  HMODULE pHVar4;
  FARPROC pFVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  if (*(char *)((int)this + 5) == '\0') {
    return 0xffffffff;
  }
  *(undefined1 *)((int)param_1 + 5) = 2;
  *param_1 = 0x316;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 9) = 0x303;
  pFVar5 = DAT_00451dbc;
  *(undefined1 *)(param_1 + 1) = 3;
  if (pFVar5 == (FARPROC)0x0) {
    pcVar8 = "SystemFunction036";
    pHVar4 = LoadLibraryA("ADVAPI32.DLL");
    pFVar5 = GetProcAddress(pHVar4,pcVar8);
    DAT_00451dbc = pFVar5;
    if (pFVar5 == (FARPROC)0x0) goto LAB_0040408a;
  }
  iVar6 = (*pFVar5)((int)param_1 + 0xb,0x20);
  if ((char)iVar6 != '\0') {
    *(undefined1 *)((int)param_1 + 0x2b) = 0x20;
    uVar1 = *(undefined4 *)((int)this + 0x154);
    uVar2 = *(undefined4 *)((int)this + 0x158);
    uVar3 = *(undefined4 *)((int)this + 0x15c);
    *(undefined4 *)(param_1 + 0x16) = *(undefined4 *)((int)this + 0x150);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    *(undefined4 *)(param_1 + 0x1a) = uVar2;
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
    uVar1 = *(undefined4 *)((int)this + 0x164);
    uVar2 = *(undefined4 *)((int)this + 0x168);
    uVar3 = *(undefined4 *)((int)this + 0x16c);
    *(undefined4 *)(param_1 + 0x1e) = *(undefined4 *)((int)this + 0x160);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
    *(undefined4 *)(param_1 + 0x22) = uVar2;
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    param_1[0x26] = 0x113;
    *(undefined1 *)(param_1 + 0x27) = 0;
    *(undefined8 *)((int)param_1 + 0x51) = 0x3300000002002900;
    *(undefined4 *)((int)param_1 + 0x59) = 0x1d002400;
    *(undefined2 *)((int)param_1 + 0x5d) = 0x2000;
    if (DAT_00451dbc == (FARPROC)0x0) {
      pcVar8 = "SystemFunction036";
      pHVar4 = LoadLibraryA("ADVAPI32.DLL");
      DAT_00451dbc = GetProcAddress(pHVar4,pcVar8);
      if (DAT_00451dbc == (FARPROC)0x0) goto LAB_0040408a;
    }
    iVar6 = (*DAT_00451dbc)((int)param_1 + 0x5f,0x20);
    if ((char)iVar6 != '\0') {
      *(byte *)(param_1 + 0x3f) = *(byte *)(param_1 + 0x3f) & 0x7f;
      *(undefined4 *)((int)param_1 + 0x7f) = 0x2002b00;
      *(undefined2 *)((int)param_1 + 0x83) = 0x403;
      iVar6 = (int)param_1 + (0x80 - ((uint)param_1 & 0xffff));
      *(short *)((int)param_1 + 3) = (short)CONCAT31((int3)iVar6,(char)((uint)iVar6 >> 8));
      iVar6 = (int)param_1 + (0x7c - ((uint)param_1 & 0xffff));
      iVar7 = (int)param_1 + (0x83 - ((uint)((int)param_1 + 0x4f) & 0xffff));
      *(short *)((int)param_1 + 7) = (short)CONCAT31((int3)iVar6,(char)((uint)iVar6 >> 8));
      *(short *)((int)param_1 + 0x4f) = (short)CONCAT31((int3)iVar7,(char)((uint)iVar7 >> 8));
      FUN_004039c0((undefined4 *)((int)this + 0x48),(uint *)((int)param_1 + 5),0x80);
      *(undefined4 *)((int)param_1 + 0x85) = 0x30314;
      *(undefined2 *)((int)param_1 + 0x89) = 0x101;
      return 0x8b;
    }
  }
LAB_0040408a:
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}


// ----- callee: KERNEL32.DLL::ExitProcess @ EXTERNAL:0000006c
// decompile failed: Exception while decompiling EXTERNAL:0000006c: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::GetProcAddress @ EXTERNAL:0000005e
// decompile failed: Exception while decompiling EXTERNAL:0000005e: Cannot marshal address space: EXTERNAL

// ----- callee: FUN_0040e010 @ 0040e010

void __cdecl FUN_0040e010(char *param_1,char param_2)

{
  FILE *pFVar1;
  char local_210 [516];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = DAT_0044f008 ^ (uint)(auStack_8 + 4);
  FUN_00407150(local_210,0x200,param_1,&param_2);
  if (DAT_004504b4 == (code *)0x0) {
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs(local_210,pFVar1);
    pFVar1 = (FILE *)___acrt_iob_func(2);
    _fputs("\n",pFVar1);
    __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
    return;
  }
  (*DAT_004504b4)(1,local_210);
  __security_check_cookie(local_c ^ (uint)(auStack_8 + 4));
  return;
}



// ===================== FUN_00403ad0 @ 00403ad0  anchors: [ObfuscateKey(win@004483d4), ObfuscateKey(win@004483d8), ObfuscateKey(win@004483e8), ObfuscateKey(win@004483f8), ObfuscateKey(win@004483fc), ObfuscateKey(win@00448400), ObfuscateKey(win@00448404), ObfuscateKey(win@00448408), ObfuscateKey(win@00448418), ObfuscateKey(win@00448428), ObfuscateKey(win@00448430), ObfuscateKey(win@00448434), ObfuscateKey(win@00448444), ObfuscateKey(win@00448454), ObfuscateKey(win@0044845c), ObfuscateKey(win@00448460), ObfuscateKey(win@00448470), ObfuscateKey(win@00448480), ObfuscateKey(win@00448482), ObfuscateKey(win@00448488), ObfuscateKey(win@0044848c), ObfuscateKey(win@004484e8), ObfuscateKey(win@004484f8), ObfuscateKey(win@00448508), ObfuscateKey(win@00448518), ObfuscateKey(win@00448528), ObfuscateKey(win@0044853c)] =====================

int __thiscall FUN_00403ad0(void *this,undefined2 *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  HMODULE pHVar4;
  int iVar5;
  FARPROC pFVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char *pcVar10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  *param_1 = 0x316;
  pcVar9 = LoadLibraryA_exref;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)((int)param_1 + 5) = 1;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 9) = 0x303;
  if (DAT_00451dbc == (FARPROC)0x0) {
    pcVar10 = "SystemFunction036";
    pHVar4 = LoadLibraryA("ADVAPI32.DLL");
    DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
    if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
  }
  iVar5 = (*DAT_00451dbc)((int)param_1 + 0xb,0x20);
  pFVar6 = DAT_00451dbc;
  if ((char)iVar5 != '\0') {
    *(undefined1 *)((int)param_1 + 0x2b) = 0x20;
    if (pFVar6 == (FARPROC)0x0) {
      pcVar10 = "SystemFunction036";
      pHVar4 = LoadLibraryA("ADVAPI32.DLL");
      pFVar6 = GetProcAddress(pHVar4,pcVar10);
      DAT_00451dbc = pFVar6;
      if (pFVar6 == (FARPROC)0x0) goto LAB_00403ed4;
    }
    iVar5 = (*pFVar6)(param_1 + 0x16,0x20);
    if ((char)iVar5 != '\0') {
      if (*(char *)((int)this + 1) == '\x02') {
        local_c = param_1 + 0x3a;
        *(undefined4 *)(param_1 + 0x26) = 0x1132400;
        *(undefined4 *)(param_1 + 0x28) = 0x2130313;
        *(undefined4 *)(param_1 + 0x2a) = 0x2fc02bc0;
        *(undefined4 *)(param_1 + 0x2c) = 0xa8cca9cc;
        *(undefined4 *)(param_1 + 0x2e) = 0x30c02cc0;
        *(undefined4 *)(param_1 + 0x30) = 0x9c00ac0;
        *(undefined4 *)(param_1 + 0x32) = 0x14c013c0;
        *(undefined4 *)(param_1 + 0x34) = 0x39003300;
        *(undefined8 *)(param_1 + 0x36) = 0x10a0035002f00;
        *(undefined4 *)(param_1 + 0x3b) = 0x16000000;
        *(undefined4 *)(param_1 + 0x3d) = 0x1400;
        *(undefined4 *)(param_1 + 0x3f) = 0x616e6511;
        builtin_strncpy((char *)(param_1 + 0x41),"bled",4);
        builtin_strncpy((char *)(param_1 + 0x43),".tls",4);
        builtin_strncpy((char *)(param_1 + 0x45),"13.c",4);
        *(undefined4 *)(param_1 + 0x47) = 0x17006d6f;
        *(undefined4 *)(param_1 + 0x49) = 0x1ff0000;
        param_1[0x4b] = 0x100;
        *(undefined1 *)(param_1 + 0x4c) = 0;
        *(undefined4 *)((int)param_1 + 0x99) = 0xe000a00;
        *(undefined4 *)((int)param_1 + 0x9d) = 0x1d000c00;
        *(undefined4 *)((int)param_1 + 0xa1) = 0x18001700;
        *(undefined4 *)((int)param_1 + 0xa5) = 0x11900;
        *(undefined4 *)((int)param_1 + 0xa9) = 0xb000101;
        *(undefined4 *)((int)param_1 + 0xad) = 0x10200;
        *(undefined4 *)((int)param_1 + 0xb1) = 0xe001000;
        *(undefined4 *)((int)param_1 + 0xb5) = 0x68020c00;
        *(undefined4 *)((int)param_1 + 0xb9) = 0x74680832;
        *(undefined4 *)((int)param_1 + 0xbd) = 0x312f7074;
        *(undefined4 *)((int)param_1 + 0xc1) = 0x500312e;
        *(undefined4 *)((int)param_1 + 0xc5) = 0x10500;
        *(undefined8 *)((int)param_1 + 0xc9) = 0x6b003300000000;
        *(undefined4 *)((int)param_1 + 0xd1) = 0x1d0069;
        *(undefined1 *)((int)param_1 + 0xd5) = 0x20;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)(param_1 + 0x6b,0x20);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        *(byte *)((int)param_1 + 0xf5) = *(byte *)((int)param_1 + 0xf5) & 0x7f;
        *(undefined4 *)(param_1 + 0x7b) = 0x41001700;
        *(undefined1 *)(param_1 + 0x7d) = 4;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)((int)param_1 + 0xfb,0x40);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        local_8 = param_1 + 0xbe;
        *(undefined4 *)((int)param_1 + 0x13b) = 0x2a00;
        *(undefined4 *)((int)param_1 + 0x13f) = 0x9002b00;
        *(undefined4 *)((int)param_1 + 0x143) = 0x3040308;
        *(undefined4 *)((int)param_1 + 0x147) = 0x3020303;
        *(undefined4 *)((int)param_1 + 0x14b) = 0xd0001;
        *(undefined4 *)((int)param_1 + 0x14f) = 0x4160018;
        *(undefined4 *)((int)param_1 + 0x153) = 0x6030503;
        *(undefined4 *)((int)param_1 + 0x157) = 0x8040803;
        *(undefined4 *)((int)param_1 + 0x15b) = 0x4060805;
        *(undefined4 *)((int)param_1 + 0x15f) = 0x6010501;
        *(undefined4 *)((int)param_1 + 0x163) = 0x2030201;
        *(undefined4 *)((int)param_1 + 0x167) = 0x2d0001;
        *(undefined4 *)((int)param_1 + 0x16b) = 0x10102;
        *(undefined4 *)((int)param_1 + 0x16f) = 0x4002001c;
        *(undefined4 *)((int)param_1 + 0x173) = 0x290001;
        *(undefined4 *)((int)param_1 + 0x177) = 0xc600eb;
        *(undefined1 *)((int)param_1 + 0x17b) = 0xc0;
      }
      else {
        local_c = param_1 + 0x39;
        *(undefined4 *)(param_1 + 0x26) = 0xdada2200;
        *(undefined4 *)(param_1 + 0x28) = 0x2130113;
        *(undefined4 *)(param_1 + 0x2a) = 0x2bc00313;
        *(undefined4 *)(param_1 + 0x2c) = 0x2cc02fc0;
        *(undefined4 *)(param_1 + 0x2e) = 0xa9cc30c0;
        *(undefined4 *)(param_1 + 0x30) = 0x13c0a8cc;
        *(undefined4 *)(param_1 + 0x32) = 0x9c0014c0;
        *(undefined4 *)(param_1 + 0x34) = 0x2f009d00;
        *(undefined4 *)(param_1 + 0x36) = 0xa003500;
        param_1[0x38] = 1;
        *(undefined4 *)(param_1 + 0x3a) = 0xaaaa;
        *(undefined4 *)(param_1 + 0x3c) = 0x16000000;
        *(undefined4 *)(param_1 + 0x3e) = 0x1400;
        *(undefined4 *)(param_1 + 0x40) = 0x616e6511;
        builtin_strncpy((char *)(param_1 + 0x42),"bled",4);
        builtin_strncpy((char *)(param_1 + 0x44),".tls",4);
        builtin_strncpy((char *)(param_1 + 0x46),"13.c",4);
        *(undefined4 *)(param_1 + 0x48) = 0x17006d6f;
        *(undefined4 *)(param_1 + 0x4a) = 0x1ff0000;
        param_1[0x4c] = 0x100;
        *(undefined1 *)(param_1 + 0x4d) = 0;
        puVar7 = &DAT_00448488;
        puVar8 = (undefined4 *)((int)param_1 + 0x9b);
        for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = *(undefined2 *)puVar7;
        pcVar9 = LoadLibraryA_exref;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = LoadLibraryA("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        iVar5 = (*DAT_00451dbc)((int)param_1 + 0xf9,0x20);
        if ((char)iVar5 == '\0') goto LAB_00403ed4;
        *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) & 0x7f;
        local_8 = param_1 + 0xa1;
        *(undefined4 *)((int)param_1 + 0x119) = 0x2002d00;
        *(undefined4 *)((int)param_1 + 0x11d) = 0x2b000101;
        *(undefined4 *)((int)param_1 + 0x121) = 0x1a0a0b00;
        *(undefined4 *)((int)param_1 + 0x125) = 0x304031a;
        *(undefined4 *)((int)param_1 + 0x129) = 0x3020303;
        *(undefined4 *)((int)param_1 + 0x12d) = 0x1b0001;
        *(undefined4 *)((int)param_1 + 0x131) = 0x2000203;
        *(undefined4 *)((int)param_1 + 0x135) = 0x100eaea;
        *(undefined8 *)((int)param_1 + 0x139) = 0xc600eb00290000;
        *(undefined1 *)((int)param_1 + 0x141) = 0xc0;
      }
      puVar3 = local_8;
      if (DAT_00451dbc == (FARPROC)0x0) {
        pcVar10 = "SystemFunction036";
        pHVar4 = (HMODULE)(*pcVar9)("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
      }
      iVar5 = (*DAT_00451dbc)(local_8,0xc4);
      if ((char)iVar5 != '\0') {
        puVar2 = local_8 + 99;
        local_8[0x62] = 0x2100;
        uVar1 = (int)local_8 + 0xe7;
        if (DAT_00451dbc == (FARPROC)0x0) {
          pcVar10 = "SystemFunction036";
          pHVar4 = (HMODULE)(*pcVar9)("ADVAPI32.DLL");
          DAT_00451dbc = GetProcAddress(pHVar4,pcVar10);
          if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00403ed4;
        }
        local_8 = (undefined2 *)(uVar1 & 0xffff);
        iVar5 = (*DAT_00451dbc)(puVar2,0x21);
        if ((char)iVar5 != '\0') {
          iVar5 = ((uVar1 & 0xffff) - ((uint)param_1 & 0xffff)) + -5;
          *(short *)((int)param_1 + 3) = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          iVar5 = ((int)local_8 - ((uint)param_1 & 0xffff)) + -9;
          *(short *)((int)param_1 + 7) = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          iVar5 = ((uVar1 & 0xffff) - (int)local_c) + -2;
          *local_c = (short)CONCAT31((int3)iVar5,(char)((uint)iVar5 >> 8));
          FUN_004039c0((undefined4 *)((int)this + 0x48),(uint *)((int)param_1 + 5),(uVar1 - (int)param_1) - 5);
          *(undefined4 *)((int)puVar3 + 0xe7) = 0x30314;
          *(undefined2 *)((int)puVar3 + 0xeb) = 0x101;
          return (uVar1 - (int)param_1) + 6;
        }
      }
    }
  }
LAB_00403ed4:
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}


// ----- caller: FUN_00404560 @ 00404560

void __thiscall FUN_00404560(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  HMODULE hModule;
  int iVar9;
  uint uVar10;
  undefined4 unaff_EDI;
  char *lpProcName;
  char cVar11;
  uint local_41c;
  int *local_418;
  void *local_414;
  uint local_410 [257];
  uint local_c;
  
  cVar11 = (char)unaff_EDI;
  local_c = DAT_0044f008 ^ (uint)&local_41c;
  cVar1 = *(char *)((int)this + 1);
  local_418 = param_1;
  local_414 = this;
  if (cVar1 == '\0') {
    local_418 = (int *)param_1[8];
    local_41c = param_1[7];
    iVar9 = *local_418;
    *(undefined1 *)((int)param_1 + 0x26) = 1;
    if (iVar9 == 4) {
      local_414 = (void *)local_418[1];
      iVar9 = local_418[2];
      iVar2 = local_418[3];
      iVar3 = *(int *)((int)this + 0x40);
      *(int *)((int)this + 0x40) = iVar9;
      iVar4 = *(int *)((int)this + 0x44);
      *(int *)((int)this + 0x44) = iVar2;
      if ((iVar9 + -1 == iVar3 && *(void **)((int)this + 0x30) == local_414) && iVar2 + -1 + (uint)(iVar9 != 0) == iVar4
         ) {
        param_1[8] = (int)local_418 + 0xe;
        param_1[7] = local_41c - 0xe;
        *(short *)((int)local_418 + 0xe) = (short)CONCAT31((int3)(local_41c + 0x7ff0),(char)(local_41c + 0x7ff0 >> 8));
        __security_check_cookie(local_c ^ (uint)&local_41c);
        return;
      }
      *(void **)((int)this + 0x30) = local_414;
    }
    param_1[7] = local_41c + 2;
    param_1[8] = (int)local_418 + -2;
    *(short *)((int)local_418 + -2) = (short)CONCAT31((int3)local_41c,(char)(local_41c >> 8));
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (*(char *)((int)this + 3) == '\x02') {
    if (cVar1 == '\x01') {
      FUN_004040a0(this,(int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
    uVar10 = 0;
    do {
      FUN_004040a0(this,(int)param_1);
      uVar10 = uVar10 + param_1[7];
      if (11999 < uVar10) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    local_418[8] = local_418[8] + -5;
    local_418[7] = local_418[7] + 5;
    *(undefined1 *)local_418[8] = 0x17;
    *(undefined1 *)(local_418[8] + 1) = 3;
    *(undefined1 *)(local_418[8] + 2) = 3;
    *(char *)(local_418[8] + 4) = (char)uVar10;
    *(char *)(local_418[8] + 3) = (char)(uVar10 >> 8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (cVar1 == '\x01') {
    do {
      if (DAT_00451dbc == (FARPROC)0x0) {
        lpProcName = "SystemFunction036";
        hModule = LoadLibraryA("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(hModule,lpProcName);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00404715;
      }
      iVar9 = (*DAT_00451dbc)(local_410,0x40);
      cVar11 = (char)unaff_EDI;
      if ((char)iVar9 == '\0') {
LAB_00404715:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
      uVar7 = CONCAT11((char)(undefined2)local_410[0],(char)((ushort)(undefined2)local_410[0] >> 8));
    } while ((uVar7 == 0x1603) || (uVar7 < 0x5dd));
    FUN_004039c0((undefined4 *)((int)this + 0x48),local_410,0x40);
    local_41c = 0x40;
  }
  else {
    if (*(char *)((int)this + 3) == '\0') {
      local_41c = FUN_00403ad0(this,(undefined2 *)local_410);
    }
    else {
      local_41c = FUN_00403ef0(this,(undefined2 *)local_410);
    }
    if (local_41c == 0xffffffff) {
      FUN_0040e010("Trying to send server message before client hello",cVar11);
      param_1[7] = 0;
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
  }
  uVar10 = local_41c;
  *(undefined1 *)((int)this + 3) = 2;
  FUN_00404560(this,param_1);
  uVar8 = local_41c;
  uVar5 = param_1[7];
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x76d) {
    param_1[7] = uVar10;
    puVar6 = (uint *)param_1[8];
    param_1[8] = (int)(param_1 + 0x21);
    FUN_0042e660((uint *)((int)param_1 + local_41c + 0x84),puVar6,uVar5);
    FUN_0042f280((uint *)(param_1 + 0x21),local_410,uVar8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  FUN_0040e010("Outgoing TCP packet too big.",cVar11);
  __security_check_cookie(local_c ^ (uint)&local_41c);
  return;
}


// ----- callee: FUN_004039c0 @ 004039c0

void __fastcall FUN_004039c0(undefined4 *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [16];
  uint local_10;
  char local_8;
  
  puVar1 = param_1 + 1;
  FUN_00418620(&local_80,0x20,puVar1,0x20);
  FUN_00419bc0(&local_80,param_2,param_3);
  local_60 = local_60 + local_10;
  local_58 = 0xffffffff;
  local_5c = local_5c + (uint)(local_60 < local_10);
  if (local_8 != '\0') {
    local_54 = 0xffffffff;
  }
  _memset((void *)((int)local_50 + local_10),0,0x40 - local_10);
  FUN_004186e0(&local_80,local_50);
  *puVar1 = local_80;
  param_1[2] = uStack_7c;
  param_1[3] = uStack_78;
  param_1[4] = uStack_74;
  param_1[5] = local_70;
  param_1[6] = uStack_6c;
  param_1[7] = uStack_68;
  param_1[8] = uStack_64;
  *param_1 = 0;
  param_1[0x11] = 0x61707865;
  param_1[0x12] = 0x3320646e;
  param_1[0x13] = 0x79622d32;
  param_1[0x14] = 0x6b206574;
  param_1[0x15] = *puVar1;
  param_1[0x16] = param_1[2];
  param_1[0x17] = param_1[3];
  param_1[0x18] = param_1[4];
  param_1[0x19] = param_1[5];
  param_1[0x1a] = param_1[6];
  param_1[0x1b] = param_1[7];
  param_1[0x1c] = param_1[8];
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return;
}


// ----- callee: KERNEL32.DLL::LoadLibraryA @ EXTERNAL:0000005f
// decompile failed: Exception while decompiling EXTERNAL:0000005f: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::ExitProcess @ EXTERNAL:0000006c
// decompile failed: Exception while decompiling EXTERNAL:0000006c: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::GetProcAddress @ EXTERNAL:0000005e
// decompile failed: Exception while decompiling EXTERNAL:0000005e: Cannot marshal address space: EXTERNAL


// ===================== FUN_00403ef0 @ 00403ef0  anchors: [ObfuscateKey(win@00448400), ObfuscateKey(win@00448404), ObfuscateKey(win@0044852c), ObfuscateKey(win@00448534), ObfuscateKey(win@00448538)] =====================

undefined4 __thiscall FUN_00403ef0(void *this,undefined2 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  HMODULE pHVar4;
  FARPROC pFVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  if (*(char *)((int)this + 5) == '\0') {
    return 0xffffffff;
  }
  *(undefined1 *)((int)param_1 + 5) = 2;
  *param_1 = 0x316;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined2 *)((int)param_1 + 9) = 0x303;
  pFVar5 = DAT_00451dbc;
  *(undefined1 *)(param_1 + 1) = 3;
  if (pFVar5 == (FARPROC)0x0) {
    pcVar8 = "SystemFunction036";
    pHVar4 = LoadLibraryA("ADVAPI32.DLL");
    pFVar5 = GetProcAddress(pHVar4,pcVar8);
    DAT_00451dbc = pFVar5;
    if (pFVar5 == (FARPROC)0x0) goto LAB_0040408a;
  }
  iVar6 = (*pFVar5)((int)param_1 + 0xb,0x20);
  if ((char)iVar6 != '\0') {
    *(undefined1 *)((int)param_1 + 0x2b) = 0x20;
    uVar1 = *(undefined4 *)((int)this + 0x154);
    uVar2 = *(undefined4 *)((int)this + 0x158);
    uVar3 = *(undefined4 *)((int)this + 0x15c);
    *(undefined4 *)(param_1 + 0x16) = *(undefined4 *)((int)this + 0x150);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    *(undefined4 *)(param_1 + 0x1a) = uVar2;
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
    uVar1 = *(undefined4 *)((int)this + 0x164);
    uVar2 = *(undefined4 *)((int)this + 0x168);
    uVar3 = *(undefined4 *)((int)this + 0x16c);
    *(undefined4 *)(param_1 + 0x1e) = *(undefined4 *)((int)this + 0x160);
    *(undefined4 *)(param_1 + 0x20) = uVar1;
    *(undefined4 *)(param_1 + 0x22) = uVar2;
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    param_1[0x26] = 0x113;
    *(undefined1 *)(param_1 + 0x27) = 0;
    *(undefined8 *)((int)param_1 + 0x51) = 0x3300000002002900;
    *(undefined4 *)((int)param_1 + 0x59) = 0x1d002400;
    *(undefined2 *)((int)param_1 + 0x5d) = 0x2000;
    if (DAT_00451dbc == (FARPROC)0x0) {
      pcVar8 = "SystemFunction036";
      pHVar4 = LoadLibraryA("ADVAPI32.DLL");
      DAT_00451dbc = GetProcAddress(pHVar4,pcVar8);
      if (DAT_00451dbc == (FARPROC)0x0) goto LAB_0040408a;
    }
    iVar6 = (*DAT_00451dbc)((int)param_1 + 0x5f,0x20);
    if ((char)iVar6 != '\0') {
      *(byte *)(param_1 + 0x3f) = *(byte *)(param_1 + 0x3f) & 0x7f;
      *(undefined4 *)((int)param_1 + 0x7f) = 0x2002b00;
      *(undefined2 *)((int)param_1 + 0x83) = 0x403;
      iVar6 = (int)param_1 + (0x80 - ((uint)param_1 & 0xffff));
      *(short *)((int)param_1 + 3) = (short)CONCAT31((int3)iVar6,(char)((uint)iVar6 >> 8));
      iVar6 = (int)param_1 + (0x7c - ((uint)param_1 & 0xffff));
      iVar7 = (int)param_1 + (0x83 - ((uint)((int)param_1 + 0x4f) & 0xffff));
      *(short *)((int)param_1 + 7) = (short)CONCAT31((int3)iVar6,(char)((uint)iVar6 >> 8));
      *(short *)((int)param_1 + 0x4f) = (short)CONCAT31((int3)iVar7,(char)((uint)iVar7 >> 8));
      FUN_004039c0((undefined4 *)((int)this + 0x48),(uint *)((int)param_1 + 5),0x80);
      *(undefined4 *)((int)param_1 + 0x85) = 0x30314;
      *(undefined2 *)((int)param_1 + 0x89) = 0x101;
      return 0x8b;
    }
  }
LAB_0040408a:
                    /* WARNING: Subroutine does not return */
  ExitProcess(1);
}


// ----- caller: FUN_00404560 @ 00404560

void __thiscall FUN_00404560(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  HMODULE hModule;
  int iVar9;
  uint uVar10;
  undefined4 unaff_EDI;
  char *lpProcName;
  char cVar11;
  uint local_41c;
  int *local_418;
  void *local_414;
  uint local_410 [257];
  uint local_c;
  
  cVar11 = (char)unaff_EDI;
  local_c = DAT_0044f008 ^ (uint)&local_41c;
  cVar1 = *(char *)((int)this + 1);
  local_418 = param_1;
  local_414 = this;
  if (cVar1 == '\0') {
    local_418 = (int *)param_1[8];
    local_41c = param_1[7];
    iVar9 = *local_418;
    *(undefined1 *)((int)param_1 + 0x26) = 1;
    if (iVar9 == 4) {
      local_414 = (void *)local_418[1];
      iVar9 = local_418[2];
      iVar2 = local_418[3];
      iVar3 = *(int *)((int)this + 0x40);
      *(int *)((int)this + 0x40) = iVar9;
      iVar4 = *(int *)((int)this + 0x44);
      *(int *)((int)this + 0x44) = iVar2;
      if ((iVar9 + -1 == iVar3 && *(void **)((int)this + 0x30) == local_414) && iVar2 + -1 + (uint)(iVar9 != 0) == iVar4
         ) {
        param_1[8] = (int)local_418 + 0xe;
        param_1[7] = local_41c - 0xe;
        *(short *)((int)local_418 + 0xe) = (short)CONCAT31((int3)(local_41c + 0x7ff0),(char)(local_41c + 0x7ff0 >> 8));
        __security_check_cookie(local_c ^ (uint)&local_41c);
        return;
      }
      *(void **)((int)this + 0x30) = local_414;
    }
    param_1[7] = local_41c + 2;
    param_1[8] = (int)local_418 + -2;
    *(short *)((int)local_418 + -2) = (short)CONCAT31((int3)local_41c,(char)(local_41c >> 8));
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (*(char *)((int)this + 3) == '\x02') {
    if (cVar1 == '\x01') {
      FUN_004040a0(this,(int)param_1);
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
    uVar10 = 0;
    do {
      FUN_004040a0(this,(int)param_1);
      uVar10 = uVar10 + param_1[7];
      if (11999 < uVar10) break;
      param_1 = (int *)*param_1;
    } while (param_1 != (int *)0x0);
    local_418[8] = local_418[8] + -5;
    local_418[7] = local_418[7] + 5;
    *(undefined1 *)local_418[8] = 0x17;
    *(undefined1 *)(local_418[8] + 1) = 3;
    *(undefined1 *)(local_418[8] + 2) = 3;
    *(char *)(local_418[8] + 4) = (char)uVar10;
    *(char *)(local_418[8] + 3) = (char)(uVar10 >> 8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  if (cVar1 == '\x01') {
    do {
      if (DAT_00451dbc == (FARPROC)0x0) {
        lpProcName = "SystemFunction036";
        hModule = LoadLibraryA("ADVAPI32.DLL");
        DAT_00451dbc = GetProcAddress(hModule,lpProcName);
        if (DAT_00451dbc == (FARPROC)0x0) goto LAB_00404715;
      }
      iVar9 = (*DAT_00451dbc)(local_410,0x40);
      cVar11 = (char)unaff_EDI;
      if ((char)iVar9 == '\0') {
LAB_00404715:
                    /* WARNING: Subroutine does not return */
        ExitProcess(1);
      }
      uVar7 = CONCAT11((char)(undefined2)local_410[0],(char)((ushort)(undefined2)local_410[0] >> 8));
    } while ((uVar7 == 0x1603) || (uVar7 < 0x5dd));
    FUN_004039c0((undefined4 *)((int)this + 0x48),local_410,0x40);
    local_41c = 0x40;
  }
  else {
    if (*(char *)((int)this + 3) == '\0') {
      local_41c = FUN_00403ad0(this,(undefined2 *)local_410);
    }
    else {
      local_41c = FUN_00403ef0(this,(undefined2 *)local_410);
    }
    if (local_41c == 0xffffffff) {
      FUN_0040e010("Trying to send server message before client hello",cVar11);
      param_1[7] = 0;
      __security_check_cookie(local_c ^ (uint)&local_41c);
      return;
    }
  }
  uVar10 = local_41c;
  *(undefined1 *)((int)this + 3) = 2;
  FUN_00404560(this,param_1);
  uVar8 = local_41c;
  uVar5 = param_1[7];
  uVar10 = uVar5 + uVar10;
  if (uVar10 < 0x76d) {
    param_1[7] = uVar10;
    puVar6 = (uint *)param_1[8];
    param_1[8] = (int)(param_1 + 0x21);
    FUN_0042e660((uint *)((int)param_1 + local_41c + 0x84),puVar6,uVar5);
    FUN_0042f280((uint *)(param_1 + 0x21),local_410,uVar8);
    __security_check_cookie(local_c ^ (uint)&local_41c);
    return;
  }
  FUN_0040e010("Outgoing TCP packet too big.",cVar11);
  __security_check_cookie(local_c ^ (uint)&local_41c);
  return;
}


// ----- callee: FUN_004039c0 @ 004039c0

void __fastcall FUN_004039c0(undefined4 *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [16];
  uint local_10;
  char local_8;
  
  puVar1 = param_1 + 1;
  FUN_00418620(&local_80,0x20,puVar1,0x20);
  FUN_00419bc0(&local_80,param_2,param_3);
  local_60 = local_60 + local_10;
  local_58 = 0xffffffff;
  local_5c = local_5c + (uint)(local_60 < local_10);
  if (local_8 != '\0') {
    local_54 = 0xffffffff;
  }
  _memset((void *)((int)local_50 + local_10),0,0x40 - local_10);
  FUN_004186e0(&local_80,local_50);
  *puVar1 = local_80;
  param_1[2] = uStack_7c;
  param_1[3] = uStack_78;
  param_1[4] = uStack_74;
  param_1[5] = local_70;
  param_1[6] = uStack_6c;
  param_1[7] = uStack_68;
  param_1[8] = uStack_64;
  *param_1 = 0;
  param_1[0x11] = 0x61707865;
  param_1[0x12] = 0x3320646e;
  param_1[0x13] = 0x79622d32;
  param_1[0x14] = 0x6b206574;
  param_1[0x15] = *puVar1;
  param_1[0x16] = param_1[2];
  param_1[0x17] = param_1[3];
  param_1[0x18] = param_1[4];
  param_1[0x19] = param_1[5];
  param_1[0x1a] = param_1[6];
  param_1[0x1b] = param_1[7];
  param_1[0x1c] = param_1[8];
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return;
}


// ----- callee: KERNEL32.DLL::LoadLibraryA @ EXTERNAL:0000005f
// decompile failed: Exception while decompiling EXTERNAL:0000005f: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::ExitProcess @ EXTERNAL:0000006c
// decompile failed: Exception while decompiling EXTERNAL:0000006c: Cannot marshal address space: EXTERNAL

// ----- callee: KERNEL32.DLL::GetProcAddress @ EXTERNAL:0000005e
// decompile failed: Exception while decompiling EXTERNAL:0000005e: Cannot marshal address space: EXTERNAL

