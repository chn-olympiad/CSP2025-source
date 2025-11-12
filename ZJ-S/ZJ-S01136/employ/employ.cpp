#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const long long mod = 998244353;
int c[N];
char s[N];
int n,m;
int t[N];
int vis[N];
long long ans = 0;
void dfs(int x){
	if(x>n){
		int w = 0;
		int as = 0;
		for(int i = 1;i<=n;i++){
			if(c[t[i]]<=w){
				w++;
				continue;
			}
			if(s[i]=='0'){
				w++;
				continue;
			}
			as++;
		}
		if(as>=m){
			ans++;
		}
		ans%=mod;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		vis[i] = 1;
		t[x] = i;
		dfs(x+1);
		vis[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long ss = 0;
	for(int i = 1;i<=n;i++){
		cin>>s[i];
		ss+=s[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	if(m>ss){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

