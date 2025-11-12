#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define re register
const int maxn=5e2+10;
const int mod=998244353;
int n,m;
string ss;
int c[maxn];
bool s[maxn];
ll jc(ll x){
	ll ret=1;
	for(ll i=1;i<=x;++i) ret=ret*i%mod;
	return ret;
}
int ans;
bool vi[maxn];
void dfs(int pos,int num,int del){
	if(pos>n){
		ans+=(num>=m);
		ans-=(ans>=mod)*mod;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vi[i]) continue;
		vi[i]=1;
		dfs(pos+1,num+(s[pos]&&c[i]>del),del+((!s[pos])||c[i]<=del));
		vi[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;++i) s[i]=(ss[i-1]=='1');
	for(int i=1;i<=n;++i) cin>>c[i];
	bool p1=1;int num=0,num2=0;
	for(int i=1;i<=n;++i){
		if(!s[i]) p1=0;
		if(!c[i]) ++num;
		if(s[i]) ++num2;
	}
	if(m==n){
		if(!p1||num) cout<<0<<"\n";
		else cout<<jc(n)<<"\n";
		return 0; 
	}
	if(num2<m){
		cout<<0<<"\n";
		return 0;
	}
	if(p1||m==1){
		cout<<jc(n)<<"\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
/*

*/