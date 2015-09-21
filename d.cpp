/*****************************************************
	^> File Name: a.cpp
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/15 - 14:06:07
****************************************************/
#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;
map<char,unsigned int> priority;
void initpri(const map<char,unsigned int> &pri)
{
	string spri="&2|2+3-3*4/4%4^5";
	for(unsigned int i=0;i<spri.length();i+=2)
	{
		priority[spri[i]]=spri[i+1]-'0';
	}
}
bool isvar(const char &ch)
{
	return (((ch)>='0'&&(ch)<='9')||((ch)>='a'&&(ch)<='z')||((ch)>='A'&&(ch)<='Z'));
}
bool high(const char &high,const char &low)
{
	return priority[high]>=priority[low];
}
int main(int argc, char **argv)
{
	string str;
	initpri(priority);
	list<char> li;
	getline(cin,str);
	cout<<"::::"<<str<<"::::"<<endl;
	for(const char &ch:str)
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
			if(!li.empty()&&high(front=li.front(),ch))
			{
				cout<<front;
				li.pop_front();
			}
			li.push_front(ch);
		}
	}
	for(const char &ch:li)
	{
		cout<<ch;
	}
	cout<<endl;
	return 0;
}
