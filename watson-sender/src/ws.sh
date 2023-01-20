#!/bin/bash

MAIN_DIR=/home/studentas/Documents/openwrt-gpl-ipq40xx-generic.Linux-x86_64
echo "Going to the main directory.."

cd $MAIN_DIR

echo "Compiling the package.."
make package/watson-sender/compile V=s

echo "Transfering the package.."
sshpass -p 'Admin123' scp bin/packages/arm_cortex-a7_neon-vfpv4/base/watson-sender_1.0.0-1_arm_cortex-a7_neon-vfpv4.ipk root@192.168.1.1:/tmp

echo "Transfer complete !"
