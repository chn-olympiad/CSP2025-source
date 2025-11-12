//SN-J00460  把小煜  西安辅轮中学
#include<bits/stdc++.h>
#define int long long
//#define int unsigned long long
using namespace std;
int n,k,a[500010],x[500010],f[500010];
vector<int>t[500010];
int dfs(int x)
{
	if(x>=n) return 0;
	if(f[x]) return f[x];
	f[x]=dfs(x+1);
	for(int y:t[x]) f[x]=max(f[x],dfs(y+1)+1);
	return f[x];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],x[i]=x[i-1]^a[i];
	for(int l=1;l<=n;l++) for(int r=l;r<=n;r++) if((x[r]^x[l-1])==k) t[l].push_back(r);
	cout<<dfs(1);
	return 0;
}
