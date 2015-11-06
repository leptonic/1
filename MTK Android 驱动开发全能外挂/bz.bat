@echo off
adb shell mount -o rw,remount /dev/block/mmcblk0p9 /system
adb push busybox /system/xbin/
adb shell chown root.shell /system/xbin/busybox
adb shell chmod 755 /system/xbin/busybox
adb shell chmod 4755 /system/xbin/su