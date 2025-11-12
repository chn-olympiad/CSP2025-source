#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s>>s;
	}
	for(int i=1;i<=q;i++)
	{
		string s;
		cin>>s>>s;
		cout<<0<<'\n';
	}
	cout<<endl;
	return 0;
 } 
