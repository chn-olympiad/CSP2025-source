#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],fl=1,v[500],qupai[90000][110],lin[110],top,ans;
char s[510];
void dfs(int cen){
	if(cen==n+1){
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(lin[i]<=cnt||s[i]=='0')cnt++;
			else cnt1++;
		}
		if(cnt1>=m)ans++;
		ans%=mod;
		return;
	}for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			lin[i]=c[cen];
			dfs(cen+1);
			lin[i]=-1;
			v[i]=0;
		}
	}
}
void solve(){
	if(!fl)cout<<0;
	else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans%mod*i*mod)%mod;
		}
		cout<<ans;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')fl=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)fl=0;
	}
	if(m==n){
		solve();
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}