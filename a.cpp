/*****************************************************
	^> File Name: a.cpp
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/15 - 14:06:07
****************************************************/
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
	string str;
	list<char> li;
	cin>>str;
	cout<<str<<",,,"<<endl;
	for(char ch:str)
	{
		if(ch>='a'&&ch<='z')
		{
			li.push_front(ch);
		}
		else
		{
			cout<<ch;
		}
	}
	for(char ch:li)
	{
		cout<<ch;
	}
	return 0;
}
