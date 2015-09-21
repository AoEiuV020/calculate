/*****************************************************
	^> File Name: m.cpp
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/09/21 - 19:39:27
****************************************************/
#include <iostream>
#include <string>
#include <cstring>/*strtok*/
#include <map>
using namespace std;
map<string,bool> var;
void scan(const string &input)
{
	const string op="&|-+*/%^()";
	string item;
	unsigned int i,j;
	for(i=0;i<input.length();++i)
	{
		for(j=0;j<op.length();++j)
		{
			if((input[i]==op[j]))
			{
				if(item.length()>0)
				{
					var[item]=false;
					item.clear();
				}
				break;
			}
		}
		if(j<op.length())
		{
			continue;
		}
		else
		{
			item.push_back(input[i]);
		}
	}
}
void calc(const string &input)
{
	string value;
	for(int i=0;i<value.length();++i)
	{
	}

}
void prin(const map<string,bool> var)
{
	for(map<string,bool>::const_iterator it=var.begin();it!=var.end();++it)
	{
		cout<<it->first<<" => "<<it->second<<endl;
	}
}
int main(int argc, char **argv)
{
	string input;
	getline(cin,input);
	scan(input);
	prin(var);
	cout<<input<<endl;
	return 0;
}
