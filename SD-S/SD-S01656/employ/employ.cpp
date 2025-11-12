#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m,c[505],vis[505],a[505],flag;
ll f[505],ans;
char s[505];
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=cnt) cnt++;
			else if(s[i]=='0') cnt++;
		}
		ans+=(cnt<m);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;a[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		f[i]=f[i-1]*i%mod;
		if(s[i]!='1') flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag==0){
		cout<<f[n];
	}
	else if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
//CSP-S RP++;
//不要挂分 orz 
//luogu 关注 lain_yc (帮忙宣传 并非本人) 
//今年应该还有迷惑行为大赏吧(我要上) 
//最终就100多pts，希望能过 

