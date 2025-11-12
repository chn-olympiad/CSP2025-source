/*
	SN-J00158 
	华紫陌
	西安辅轮中学 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5001];
int ans=0;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<pow(2,n);i++)
	{
		int sum=0,marx=0;
		for(int j=1;j<=n;j++)
			if((i>>(j-1))&1)
			{
				sum+=a[j];
				marx=max(marx,a[j]);
			}
		if(sum>marx*2) ans++;
	}
	cout<<ans;
	return 0;
}
