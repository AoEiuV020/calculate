/*****************************************************
^> File Name: junctive.cpp
^> Author: AoEiuV020
^> Mail: 490674483@qq.com
^> Created Time: 2015/09/15 - 14:06:07
****************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
using namespace std;
map<char, unsigned int> priority;
map<char, bool> variable;
queue<bool> reallist;
void init();
void hint();
bool isvar(const char &ch);
bool highpri(const char &high, const char &low);
list<char> tran(const string &bin);
bool calculate(const list<char> &infix);
bool next();
void truthtable(list<char> infix);
void junctive();
int main()
{
	init();
	hint();
	string suffix;//suffix expression...
	list<char> infix;//infix expression...
	getline(cin, suffix);
	cout << "suffix expression:::" << suffix << ":::" << endl;
	cout << "infix  expression:::";
	infix = tran(suffix);
	for (const char &ch : infix)
	{
		cout << ch;
	}
	cout << ":::" << endl;
	for (map<char, bool>::iterator it = variable.begin(); it != variable.end(); ++it)
	{
		if (it->first == 'T' || it->first == 'F')
		{
			continue;
		}
		cout << '\t' << it->first;
	}
	cout << '\t' << suffix << endl;
	truthtable(infix);
	junctive();
	return 0;
}
void init()
{
	string spri = "(0|1&2+3-3*4/4%4^5!6";
	for (unsigned int i = 0; i<spri.length(); i += 2)
	{
		priority[spri[i]] = spri[i + 1] - '0';
	}
	variable['T'] = true;
	variable['F'] = false;
}
void hint()
{
	cout << "变量名为单个字母或数字，" << endl;
	cout << "T和F为永真永假不能作为变量，" << endl;
	cout << "&为合取，/\\，" << endl;
	cout << "|为合取，\\/，" << endl;
	cout << "!为非，-/，" << endl;
	cout << "---输入中辍表达示---" << endl;
}

/*
	judging whether ch is a variable...
// */
bool isvar(const char &ch)
{
	return (((ch) >= '0' && (ch) <= '9') || ((ch) >= 'a' && (ch) <= 'z') || ((ch) >= 'A' && (ch) <= 'Z'));
}
/*
	priority...
// */
bool highpri(const char &high, const char &low)
{
	return priority[high] >= priority[low];
}
/*
   transform from infix expression to suffix expression...
// */
list<char> tran(const string &bin)
{
	list<char> infix;
	stack<char> op;
	for (const char &ch : bin)
	{
		if (isvar(ch))
		{
			infix.push_back(ch);
			if (ch != 'T'&&ch != 'F')
			{
				variable[ch] = false;//map variable...
			}
		}
		else if (')' == ch)
		{

			while ('(' != op.top())
			{
				infix.push_back(op.top());
				op.pop();
			}
			op.pop();
		}
		else
		{
			if (!op.empty() && highpri(op.top(), ch))
			{
				infix.push_back(op.top());
				op.pop();
			}
			op.push(ch);
		}
	}
	while (!op.empty())
	{
		infix.push_back(op.top());
		op.pop();
	}
	return infix;
}
/*
	calulate truth-value ,with suffix expression...
// */
bool calculate(const list<char> &infix)
{
	stack<char> result;
	char last1, last2;
	bool real;
	for (const char &ch : infix)
	{
		if (isvar(ch))
		{
			result.push(ch);
		}
		else if ('!' == ch)
		{
			last1 = result.top();
			result.pop();
			result.push(!variable[last1] ? 'T' : 'F');
		}
		else
		{
			last1 = result.top();
			result.pop();
			last2 = result.top();
			result.pop();
			switch (ch)
			{
			case '&':
				real = variable[last1] && variable[last2];
				break;
			case '|':
				real = variable[last1] || variable[last2];
				break;
			default:
				real = false;
			}
			result.push(real ? 'T' : 'F');
		}
	}
	return result.top() == 'T' ? true : false;
}
/*
   next case...
   return false if all done...
// */
bool next()
{
	map<char, bool>::iterator it = variable.end();
	while (it != variable.begin())
	{
		--it;
		if (it->first == 'T' || it->first == 'F')
		{
			continue;
		}
		if (it->second)
		{
			it->second = false;
		}
		else
		{
			it->second = true;
			return true;
		}
	}

	return false;
}
/*
	output truth table...
// */
void truthtable(list<char> infix)
{
	bool real;
	do
	{
		for (map<char, bool>::const_iterator it = variable.begin(); it != variable.end(); ++it)
		{
			if (it->first == 'T' || it->first == 'F')
			{
				continue;
			}
			cout << '\t' << (it->second ? 'T' : 'F');
		}
		real=calculate(infix);
		reallist.push(real);
		cout << '\t' << ( real ? 'T' : 'F') << endl;
	} while (next());
}
/*
   output conjunctive and disjunctive...
// */
void junctive()
{
	bool real;
	ostringstream conjunctive,disjunctive;
	conjunctive<<"T";
	disjunctive<<"F";
	for(int i=0;!reallist.empty();++i)
	{
		real=reallist.front();
		if(real)
		{
			conjunctive<<"\\/"<<"m("<<i<<")";
		}
		else
		{
			disjunctive<<"/\\"<<"M("<<i<<")";
		}
		reallist.pop();
	}
	cout<<"主析取范式:"<<endl;
	cout<<conjunctive.str()<<endl;
	cout<<"主合取范式:"<<endl;
	cout<<disjunctive.str()<<endl;
}
