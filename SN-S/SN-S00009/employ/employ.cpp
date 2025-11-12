#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int vis[15];
long long ans;
void bs(int now,int cnt)
{
	if(now>n)
	{
		if(cnt<=n-m) ans++;
		return;
	}
	if(cnt>n-m) return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		int f=1;
		if(cnt<c[i] && s[now]=='1') f=0;
		bs(now+1,cnt+f);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=12) bs(1,0);
	cout<<ans%mo<<endl;
	return 0;
}
