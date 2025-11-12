#include<bits/stdc++.h>
using namespace std;
const int N=20,MOD=998244353;
int n,m;
int vis[N];
long long ans=0;
string s;
int c[N];
int p[N];
void dfs(int x,int re,int ac){
//	cout << x << ' ' << re << ' ' << ac << endl;
//	for(int i=1;i<=n;i++) cout << p[i] << ' ';
//	cout << endl;
	if(x>n){
		if(ac>=m){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		p[x]=i;
		int res=0;
		if(re>=c[i]) res=1;
		else{
			if(s[x-1]=='0') res=1;
		}
		if(res) dfs(x+1,re+1,ac);
		else dfs(x+1,re,ac+1); 
		vis[i]=0;
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> s; 
	for(int i=1;i<=n;i++) cin >> c[i];
	dfs(1,0,0);
	cout << ans;
	return 0;
}
