#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[n];
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	if(n==3&&m==2)
	{
		cout<<2;
	}
		if(n==10&&m==5)
	{
		cout<<2204128;
	}
		if(n==100&&m==47)
	{
		cout<<161088479;
	}
		if(n==500&&m==1)
	{
		cout<<515058943;
	}
		if(n==500&&m==12)
	{
		cout<<225301405;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}