#	***************************************************
#		^> File Name: header.mk
#		^> Author: AoEiuV020
#		^> Mail: 490674483@qq.com
#		^> Created Time: 2015/08/14 - 18:23:23
#	***************************************************
#######自动判断操作系统
ifeq ($(shell uname 2>&1),Linux)
	WINDOWS=0
else
	WINDOWS=1
endif
#######上面是判断系统是不是WINDOWS,准不准无所谓了，能用就好。。。
ifeq ($(WINDOWS),1)
	PS=\\
#PathSeparator
	TAREXT=exe
	RM=del /f
else
	PS=/
	TAREXT=out
	RM=rm -f
endif
#######上面是WINDOWS不一样的地方。。。
