#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int a[N]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k,ans=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) 
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0 || a[i-1]==a[i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(k==1)
	{
		for(int i=1;i<n;i++)
		{
			if(i==1)
			{
				if(a[i+1]==1) ans++;
			}
			if(a[i]!=0)
			{
				if(a[i+1]==0)
				{
					ans++;
					continue;
				}
				if(a[i-1]==0 && i!=1) 
				{
					ans++;
					continue; 
				} 
				if(a[i-1]!=0 && a[i+1]!=0)
				{
					ans++;
					continue;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
