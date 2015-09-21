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
bool isvar(const char &ch)
{
	return (((ch)>='0'&&(ch)<='9')||((ch)>='a'&&(ch)<='z')||((ch)>='A'&&(ch)<='Z'));
}
bool low(const char &low,const char &high)
{
	return low<high;
}
int main(int argc, char **argv)
{
	string str;
	list<char> li;
	getline(cin,str);
	cout<<"::::"<<str<<"::::"<<endl;
	for(char ch:str)
	{
		
		if(isvar(ch))/*number or alpha...*/
		{
			cout.put(ch);
		}
		else if(ch==' ')
		{
			continue;
		}
		else
		{
			char front;
			if(!li.empty()&&low(front=li.front(),ch))
			{
				cout<<front;
				li.pop_front();
			}
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
