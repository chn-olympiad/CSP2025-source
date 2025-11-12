#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,ans=0,maxn=-45;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n==1||n==2)
		cout<<0%998244353;
	else if(n==3)
	{
		for(int i=0;i<n;i++)
		{
			maxn=max(maxn,a[i]);
			cnt+=a[i];
		}
		if(cnt>maxn*2)
			cout<<1%998244353;
		else 
			cout<<0%998244353;
	}	
	
	return 0;
}
