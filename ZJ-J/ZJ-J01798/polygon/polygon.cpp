#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+5;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,ans;
ll MAX;
int b[N],c[N];
ll a[N];
bool vis[N];
map<string,bool> mp; 
inline void fre()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
void dfs(int x,int l,ll MAX,int op)
{
	if(x==op+1)
	{
		ll res=0;
		string res2;
		for(int i=1;i<=op;i++) 
		{
			res+=a[c[i]];
			res2=res2+char(c[i]);
		}
		if(res>MAX*2&&!mp[res2]) 
		{
			mp[res2]=1;
			ans++;
		}
		return;
	}
	//cout<<l<<'\n';
	for(int i=l;i<=n;i++)
	{
		//if(!vis[1]) cout<<1<<'\n';
		if(!vis[i]) 
		{
			vis[i]=1;
			c[x]=i;
			//if(x==1) cout<<i<<'\n';
			dfs(x+1,i,max(a[i],MAX),op);
			vis[i]=0;
		}
	}
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[1]==n)
	{
		for(int i=3;i<=n;i+=2)//i bian xing
		{
			ll res=1;
			for(int j=i+1;j<=n;j++) res*=j;
			for(int j=1;j<=(n-i);j++) res/=j;
			ans=(ans+res)%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		for(int len=3;len<=n;len++) 
		{
			memset(vis,0,sizeof(vis));
			dfs(0,0,0,len);
		}
		cout<<ans%mod<<'\n';
	}
	return 0;
}
/*
5
2 2 3 8 10
*/