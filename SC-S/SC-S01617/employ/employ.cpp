/*
xg333 CSP-S must win!!!
T4代码
xg333:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int a[501];
int c[501];
int ans=0;
string s;
int n,m;
int check(){
	int ms=0;
	int wly=0;
	for(int i=1;i<=n;i++){
		if(wly>=c[a[i]]){
			wly++;
			continue;
		}
		if(s[i]=='0'){
			wly+=1;
		}
		else{
			ms++;
		}
	}
	return ms;
}
void dfs(int d){
	if(d==n+1){
		if(check()>=m){
			ans++;
			ans=ans%998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=d;
			dfs(d+1);
			a[i]=0;
		}
	}
}
void solve(){
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}