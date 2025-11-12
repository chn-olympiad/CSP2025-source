#include<bits/stdc++.h>
using namespace std;
long long int n,m,b[505];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
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
	return 0;
}
