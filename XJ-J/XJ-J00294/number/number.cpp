#include <bits/stdc++.h>
using namespace std;
char a[10005];
int main()
{
//	freopen("number.in",r,stdin);
//	freopen("number.out",w,stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==57)
		{
			cout<<"9";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==56)
		{
			cout<<"8";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==55)
		{
			cout<<"7";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==54)
		{
			cout<<"6";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==53)
		{
			cout<<"5";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==52)
		{
			cout<<"4";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==51)
		{
			cout<<"3";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==50)
		{
			cout<<"2";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==49)
		{
			cout<<"1";
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==48)
		{
			cout<<"0";
		}
	}
	return 0;
}
