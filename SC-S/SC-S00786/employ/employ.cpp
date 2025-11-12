#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[505],jc[505];
int b[505],d[505],ans,res;
const int p=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,f=1;char c;
	cin>>n>>m;
	jc[0]=1;
	for(i=1;i<=n;i++)jc[i]=jc[i-1]*i%p;
	for(i=1;i<=n;i++)
	{
		cin>>c;
		a[i]=c-'0';
		f&=a[i];
	}
	for(i=1;i<=n;i++)cin>>d[i];
	if(f)
	{
		cout<<jc[n]<<"\n";
	}
	for(i=1;i<=n;i++)b[i]=i;
	do
	{
		res=0;
		for(i=1;i<=n;i++)
		{
			if(res>=d[b[i]]||a[i]==0)
			{
				res++;
				continue;
			}
		}
		if(n-res>=m)ans++;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans<<"\n";
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/