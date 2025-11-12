#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int num[10]={0},j=1,flag[10]={0};
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]-'0'>=0 && a[i]-'0'<=9)
		{
			num[j]=a[i]-'0';
			j++;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==9 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==8 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==7 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==6 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==5 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==4 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==3 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==2 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==1 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	for(int i=1;i<j;i++)
	{
		if(num[i]==0 && flag[i]==0)
		{
			cout<<num[i];
			flag[i]==1;
		}
	}
	return 0;
}
