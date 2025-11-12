/*防伪标识：十年OI一场空，不开long long见祖宗*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long mod=998244353;
int n,m,a[N],ans=0;
long long sum[N];
bool vis[N];
string s;
vector<int> vc;
void dfs(int o,int cnt)
{
	if(o>n)
	{
		if(n-cnt>=m) ans++;
		return ;
	}
	if(o-cnt-1>=m)
	{
		ans=(ans+sum[n-o+1])%mod;
		return ;
	}
	if(o<=n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				//vc.push_back(i);
				vis[i]=1;
				if(cnt>=a[i]||s[o]=='0') dfs(o+1,cnt+1);
				else dfs(o+1,cnt);
				//vc.pop_back();
				vis[i]=0;
			}
		}
		return ;
	}
	//for(int i:vc) cout<<i<<" ";
	//cout<<"\n";
	/*int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=a[vc[i-1]]||s[i]=='0') cnt++;
	}
	if(n-cnt>=m) ans++;*/
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	/*bool flA=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1') flA=0;
	}*/
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]*i%mod;
	}
	dfs(1,0);
	/*if(flA)
	{
		solveA();
		return 0;
	}*/
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
