/*****************************************************
	^> File Name: txt.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/15 - 16:39:34
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv)
{
	int i;
	srand(time(0));
	for(i=0;i<200;++i)
	{
		printf("%c",random()%(0x7F-0x21)+0x21);
	}
	return 0;
}
