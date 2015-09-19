/*****************************************************
	^> File Name: a.cpp
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/15 - 14:06:07
****************************************************/
#include <iostream>
#include <list>
#include <string>
//#define isvar(CH) (((CH)>='0'&&(CH)<='9')||((CH)>='a'&&(CH)<='z')||((CH)>='A'&&(CH)<='Z'))
bool isvar(const char &ch)
{
	return (((ch)>='0'&&(ch)<='9')||((ch)>='a'&&(ch)<='z')||((ch)>='A'&&(ch)<='Z'));
}
using namespace std;
int main(int argc, char **argv)
{
	string str;
	list<char> li;
	cin>>str;
	cout<<"::::"<<str<<"::::"<<endl;
	for(char ch:str)
	{
		
		if(isvar(ch))
		{
			cout.put(ch);
		}
		else if(ch==' ')
		{
			continue;
		}
		else
		{
			li.push_front(ch);
		}
	}
	for(char ch:li)
	{
		cout<<ch;
	}
	cout<<endl;
	return 0;
}
