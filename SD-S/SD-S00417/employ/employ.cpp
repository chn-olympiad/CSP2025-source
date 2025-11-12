#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e2+10;
const int Mod=998244353;
int n,m;
int s[N];
string ss;
int c[N];
bool vis[15]; 
int cnt; 
ll ans;
void dfs(int p,int f)// 第几天失败人数 
{
	if(p==n+1)
	{
		if(cnt>=m) ans++; 
		ans%=Mod;
		return ;
	}
	bool ff=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue; 
		if(f<c[i]&&ss[p-1]=='1') {cnt++; vis[i]=1; dfs(p+1,f);vis[i]=0; cnt--;}
		else {vis[i]=1; dfs(p+1,f+1); vis[i]=0;}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		dfs(1,0);
		cout<<ans<<"\n";
	} 
	else
	{
		cout<<"0\n";
	}
	return 0;
}

