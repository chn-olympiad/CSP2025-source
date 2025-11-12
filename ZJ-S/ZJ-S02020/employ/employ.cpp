#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],dig[510],cnt[510],ans,is[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char C;
		cin>>C;
		if(C=='1')is[i]=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)dig[i]=i;
	do{
		int num=0;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[dig[i]]>=c[dig[i]]||is[i]==0)
				for(int j=i+1;j<=n;j++)cnt[dig[j]]++;
			else num++;
		}
		if(num>=m)ans++;
	}while(next_permutation(dig+1,dig+n+1));
	cout<<ans%mod;
	return 0;
}
