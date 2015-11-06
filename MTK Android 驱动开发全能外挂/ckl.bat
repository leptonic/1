@echo off
set time1=%time: =0%
set time1=%time1::=-%
set time1=%time1:.=-%


set Text=%date:~0,10%-%time1:~0,8%
adb pull /sdcard/mtklog %Text%
explorer %Text%