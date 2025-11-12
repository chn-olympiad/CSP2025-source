#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
int c[505];
char s[505];
bool vis[505];
vector<int> v;
bool check()
{
	int cnt=0,num=0;
	for(int i=0;i<v.size();i++)
	{
		if(cnt>=c[v[i]]) cnt++;
		else if(s[i+1]=='0') cnt++;
		else num++;
	}
	if(num<m) return false;
	return true;
}
void dfs(int x)
{
	if(x==n+1)
	{
		if(check()) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1; v.push_back(i);
		dfs(x+1);
		vis[i]=0; v.pop_back();
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> s[i];
	for(int i=1;i<=n;i++) cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}
