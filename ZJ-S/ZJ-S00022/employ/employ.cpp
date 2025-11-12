#include<bits/stdc++.h>
#define int long long
#define inf 2000000000000000
using namespace std;
const int N=505;
const int mod=998244353;
char s[N];
int c[N];int n,m;
bool checkA()
{
	for(int i=1;i<=n;i++)
		if(s[i]=='0')return 0;
	return 1;
}
void calA()
{
	sort(c+1,c+n+1);
	vector<pair<int,int>>g;
	c[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=c[i-1])
			g.push_back({c[i],1});
		else
		{
			g[g.size()-1].second++;
		}
	}
}
bool check0()
{
	sort(c+1,c+n+1);
	int pos=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			if(i==pos)pos++;
		}
		else
		{
			while(c[pos]<i-cnt&&pos<=n)pos++;
			if(pos<=n)pos++,cnt++;
		}
	}
	return cnt<m;
}
int f[105][105][105];
int a[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	if(check0())
	{
		printf("0");
		return 0;
	}
	{
		for(int i=1;i<=n;i++)
			a[i]=i;
		int ans=0;
		int T=1;
		for(int i=1;i<=n;i++)T*=i;
		while(T--)
		{
		//	for(int i=1;i<=n;i++)
			//	printf("%lld ",a[i]);puts("");
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='0'||c[a[i]]<=cnt)cnt++;
			}	
			ans+=(n-cnt>=m);
			next_permutation(a+1,a+n+1);
		}
		printf("%lld",ans);
	}
	return 0;
}
