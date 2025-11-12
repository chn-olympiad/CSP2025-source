#include<bits/stdc++.h>
#define lowbit(x) x&-x 
#define int long long
#define c(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
const int N=510,mod=998244353;
int c[N];
string s;
int n,m;
int p[N];
int jie[N];
int pocount(int x)
{
	int res=0;
	while(x)
	{
		res++;
		x-=lowbit(x);
	}
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jie[0]=1;
	for(int i=1;i<=500;i++)	jie[i]=jie[i-1]*i%mod;
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	bool flag=1;
	for(int i=1;i<=n;i++) if(s[i]=='0')	flag=0;
	if(n<=10)
	{
		int ans=0;
		do
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=c[p[i]])
				{
					cnt++;
					continue;
				} 
				if(s[i]=='0') cnt++;
			}
			if(n-cnt>=m)	ans++,ans%=mod;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		bool flag=1;
		for(int i=1;i<=n;i++)	if(s[i]=='0') flag=0;
		for(int i=1;i<=n;i++)	if(c[i]==0)	flag=0;
		if(flag)
		{
			cout<<jie[n]<<endl;
		}
		else cout<<0<<endl;
	}
	else cout<<0<<endl;
	return 0;
}


