#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10005],s=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(t<a[i])
		{
			t=a[i];
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			flag=0;
		 } 
	}
	if(flag==1)
	{
		for(int j=1;j<=n-2;j++)
		{
			s+=j;
		 } 
		 cout<<s;
		 return 0;
	} 
	else
	{
		cout<<t;
	}
	cout<<t;
	return 0;
}
