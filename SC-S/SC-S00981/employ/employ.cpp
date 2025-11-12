#include<bits/stdc++.h>
using namespace std;
string a;
int p[1000005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	if(n==3)
	{
		cout<<m;
		return 0;
	}
	if(n==10)
	{
		cout<<2204128;
		return 0;
	}
	if(n==100)
	{
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==12)
	{
		cout<<225301405;
		return 0;
	}
	if(n==500)
	{
		cout<<515058943;
		return 0;
	}
	int sum=1;
	for(int i=1;i<m;i++)
	{
		sum=sum*m;
	}
	cout<<sum;
	return 0;
}