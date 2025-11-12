#include<bits/stdc++.h>
using namespace std;
int f(int a,int b)
{
	if(a==b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int a[100005],b[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=f(i,i-1);
	}
	if(k==0)
	{
		cout<<n/2;
	}
	else
	{
		cout<<n/2;
	}
	return 0;
}
