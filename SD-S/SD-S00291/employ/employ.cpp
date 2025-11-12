#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans=0;
int n,m;
char s[510];
int c[510];
int a[510];
bool ok1=true;
bool ok2=false;
bool vis[510];
void check(){
	int unused=0;
	for(int i=1;i<=n;i++){
		if(!(s[i]=='1' && a[i]>unused)){
			unused++;
		}
	}
	if((n-unused)>=m) ans=(ans+1)%mod;
	else if(ok1) ok2=true;
}
void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			a[x]=-c[i];
			dfs(x+1);
			if(ok2) return;
			vis[i]=false;
		} 
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1');
		else ok1=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		c[i]=(-c[i]);
	}
	stable_sort(c+1,c+n+1);
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

