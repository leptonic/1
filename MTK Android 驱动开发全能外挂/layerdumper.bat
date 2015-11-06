:: ICS SF layerdump batch
::
:: [usage]
::
:: $> ./SF_layerdump_all [IS_RAW] [DUMP_ID]
::
:: IS_RAW: 0 for PNG and 1 for RAW (default 0)
:: DUMP_ID: layer identity to dump, or -1 for all (defulat -1)
@echo off
SET raw=%1
SET layerdump=%2

IF "%raw%"=="" SET raw=0
IF "%layerdump%"=="" SET layerdump=-1

adb shell setprop debug.sf.layerdump.raw %raw%
adb shell setprop debug.sf.layerdump %layerdump%
adb shell dumpsys SurfaceFlinger > SF_layerdump_all.log
adb shell mkdir /data/SF_dump
adb shell mv /data/*.png /data/SF_dump
adb shell mv /data/*.i420 /data/SF_dump
adb shell mv /data/*.yv12 /data/SF_dump
adb shell mv /data/*.RGBA /data/SF_dump
adb shell mv /data/*.RGB565 /data/SF_dump
rmdir /S /Q SF_layerdump_all
md SF_layerdump_all
move SF_layerdump_all.log SF_layerdump_all
adb pull /data/SF_dump SF_layerdump_all/
adb shell rm /data/SF_dump/*
explorer SF_layerdump_all