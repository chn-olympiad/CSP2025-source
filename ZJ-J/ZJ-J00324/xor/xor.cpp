#include<bits/stdc++.h>
using namespace std;
int n,k,a[6006];
bool fl=0,fll=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			fl=1;
		}
		if(a[i]!=0)
		{
			fll=1;
		}
	}
	if(n==1)
	{
		if(n==k) cout<<1;
		else cout<<0;
		return 0;
	}
	if(fl==0)
	{
		cout<<n/2;
		return 0;
	}
	if(fll==0)
	{
		if(k==0) cout<<n/2;
		else cout<<0;
		return 0;
	}
	if(k==1)
	{
		cout<<n/2;
	}
	return 0;
}
