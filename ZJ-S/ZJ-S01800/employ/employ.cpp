#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N=505,Mod=998244353;
int n,m,c[N];
char s[N];
int ans,p[N];
bool vis[N];
bool check(){
	rint aw=0,ok=0;
	for(rint i=1;i<=n;i++){
		if(aw>=c[p[i]])aw++;
		else if(s[i]=='0')aw++;
		else ok++;
	}
	return ok>=m;
}
void dfs(rint x){
	if(x>n){
		ans=(ans+check())%Mod;
		return ;
	}
	for(rint i=1;i<=n;i++)
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(rint i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	else cout<<0;
	return 0;
}
