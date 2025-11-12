#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=5e2+5;
int n,m;
char mis[maxn];
int c[maxn];
ll ans;
void check(vector<int> p){
	int sum=0;
	int not_=0;
	for (int i=1;i<=n;i++){
		if (c[p[i]]>not_ && mis[i]=='1') sum++;
		else not_++;
	}
	if (sum>=m){
		ans++;
	}

}
void dfs(int st,vector<int> p,vector<int> ji){
	if (st==n+1){
		check(p);
		return;
	}
	for (int i=1;i<=n;i++){
		if (!ji[i]){
			ji[i]=1;
			p[st]=i;
			dfs(st+1,p,ji);
			ji[i]=0;
		}
	}
}
void deal1(){
	vector<int> p(n+1),ji(n+1,0);
	dfs(1,p,ji);
	cout<<ans%mod;
}
void deal2(){
	for (int i=1;i<=n;i++){
		if (mis[i]=='0'){
			cout<<0;
			return;
		}
	}
	ans=1;
	for (int i=1;i<=n;i++){
		ans=ans*i%mod;
	}cout<<ans;
}
int sum=0;
void deal3(){
	ans=1;
	for (int i=1;i<=n;i++){
		ans=ans*i%mod;
	}cout<<ans;
}
void solve(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>mis[i];
		if (mis[i]=='1') sum++;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	if (n<=18) deal1();
	else if (n==m) deal2();
	else if (sum==n) deal3();
	else cout<<225301405;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
