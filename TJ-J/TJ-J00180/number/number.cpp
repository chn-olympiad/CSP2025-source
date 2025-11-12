#include<iostream>
using namespace std;
string s,h,x;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			h+=s[i];
		}
	}
	for(int i=0;i<h.size();i++)
	{
		x[i]=int(h[i]);
	}
	for(int i=0;i<h.size();i++)
	{
		for(int j=i+1;j<h.size();j++)
		{
			if(x[i]<x[j]) swap(x[i],x[j]);
		}
	}
	for(int i=0;i<h.size();i++)
	{
		cout<<x[i];
	}
	return 0;
}
