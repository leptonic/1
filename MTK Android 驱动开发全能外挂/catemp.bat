@echo
del /q cctemp.txt
adb shell < catemp.txt
adb pull data/1.txt cctemp.txt
adb rm data/1.txt
