#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number","r","stdin");
	freopen("number","w","stdout");
	string s,ss="";
	char a;
	getline(cin,s);
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='1'&&s[i]<='9')
		{
			ss+=s[i];
		}
	}
	for(int i=0;i<=ss.size();i++)
	{
		if(ss[i]<ss[i+1])
		{
			a=ss[i];
			ss[i]=ss[i+1];
			ss[i+1]=a;
		}
	}
	cout<<ss;
	return 0;
}