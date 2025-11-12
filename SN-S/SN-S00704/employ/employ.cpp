#include<bits/stdc++.h>
using namespace std;
const int N=18,M=505;
const long long mod=998244353;
int n,m,a[N],b[N],v[N];
string s;
long long p[M];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	p[0]=1;
	for(long long i=1;i<M;i++)
		p[i]=(p[i-1]*i)%mod;
	cin>>n>>m;
	if(n<=11)
	{
		cin>>s;
		for(int i=1;i<=n;i++)
			v[i]=s[i-1]-'0';
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			b[i]=i;
		int ans=0;
		do
		{
			int fail=0,pass=0;
			for(int i=1;i<=n;i++)
			{
				if(a[b[i]]<=fail||v[i]==0)fail++;
				else pass++;
			}
			if(pass>=m)ans++;
		}while(next_permutation(b+1,b+n+1));
		cout<<ans<<"\n";
	}
	else
	{
		cin>>s;
		for(int i=1;i<=n;i++)
			v[i]=s[i-1]-'0';
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int l=n;
		for(int i=1;i<=n;i++)
			if(a[i]==0)l--;
		bool fl=0;
		for(int i=0;i<n;i++)
			if(s[i]=='0')fl=1;
		if(!fl)cout<<p[l];
		else cout<<0;
	}
	return 0;
}

