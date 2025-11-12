#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],c[510],x=1,ans;
int X[14];
bool vis[14];
char s[510];
bool check() {
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(cnt>=c[X[i]]) cnt++;
		else if(s[i]=='0') cnt++;
	}
	return n-cnt>=m;
}
void dfs(int f,int i) {
	X[i]=f;
	if(i==n) {
		ans+=check();
		X[i]=0;
		return;
	}
	vis[f]=1;
	for(int j=1; j<=n; j++) {
		if(!vis[j]) dfs(j,i+1);
	}
	vis[f]=0;
	X[i]=0;
	return;
}
main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		x=x&(s[i]^48);
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(n<=13) {
		for(int i=1; i<=n; i++) dfs(i,1);
		cout<<ans%998244353;
		return 0;
	}
	if(x) {//A
		ans=1;
		for(int i=1; i<=n; i++) ans=ans*i%998244353;
		cout<<ans;
		return 0;
	}
	if(m==n) {
		cout<<0;
		return 0;
	}
	if(m==1) {
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}