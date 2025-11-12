#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int MOD=998244353;
const int MAXN=5e4+10;
int n,a[MAXN],cnt;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)cout<<1;
	else
	{
		int sums=0;
		for(int i=3;i<=n;i++)
		{
			int sum=1;
			for(int j=n;j>=n-i+1;j--)
			{
				sum*=j;
				sum%=MOD;
			}
			for(int j=1;j<=i;j++)
			{
				sum/=j;
			}
			sums+=sum;
		}cout<<sums%MOD;
	}
	return 0;
}
