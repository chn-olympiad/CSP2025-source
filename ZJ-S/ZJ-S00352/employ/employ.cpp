#include<bits/stdc++.h>
#define endl "\n"
#define f(n) for(int i=1;i<=n;i++)
#define int long long
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int n,m,c[505],vis[505],k[505],mod=998244353,cnt,ans;
string s;
bitset<505>b;
void check(){
	int fq=0,ppl=0;
	f(n)if(fq>=k[i]||!b[i])fq++;
	else ppl++;
	if(ppl>=m)ans++;
}
void dfs(int x){
	if(x>n){
		check();
		return;
	}
	f(n)if(!vis[i])k[x]=c[i],vis[i]=1,dfs(x+1),vis[i]=0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS;cin>>n>>m>>s;
	for(int i=0;i<n;i++)b[i+1]=s[i]-48;
	f(n)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
