#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,mod=998244353,a[525],q[525],sum,cnt;
bool b[525],bj[525];
string s;
void dfs(int r) {
	if(r==n-1&&sum>=m) {
		ans++,ans%=mod;
		return;
	}else if(r==n){
		return;
	}
	for(int i=0;i<n;i++){
		if(!bj[i]){
			bj[i]=1;
			if(q[r]<a[i]&&b[r])sum++;
//			cout<<i<<" ";
			dfs(r+1);
			bj[i]=0;
			if(q[r]<a[i]&&b[r])sum--;
		}
	}
}
signed main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=0; i<n; i++) {
		if(s[i]=='1')b[i]=1,cnt++;
		q[i]=q[i-1];
		if(!b[i])q[i]++;
	}
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	if(cnt<m)cout<<0;
	else if(n<=10) {
		dfs(0);
		cout<<ans;
	}
}
