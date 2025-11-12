#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
int ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			int maxx=-100000000;
			for(int k=i;k<=j;k++)
			{
				maxx=max(maxx,a[k]-a[k-1]);
			}
			if(a[j]-a[i-1]>2*maxx) ans=(ans+1)%MOD;
		}
	}
	cout<<ans;
	return 0;
}
//mycode
//??????
//fangqi
