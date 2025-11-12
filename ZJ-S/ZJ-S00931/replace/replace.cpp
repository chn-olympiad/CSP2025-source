#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e16+2137,base=233;
int n,ca,son[5000005][26],cnt,ans[200005];
vector<ll> has[5000005];
vector<int>as[5000005];
unordered_map<ll,int>mp;
vector<ll>p[200005];
string s,t;
void dfs(int u){
	for(auto x:has[u]) mp[x]++;
	for(auto x:as[u]) for(auto y:p[x]) ans[x]+=mp[y];
	for(int i=0;i<26;i++) if(son[u][i]) dfs(son[u][i]);
	for(auto x:has[u]) mp[x]--;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>ca;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int pre=0;
		while(s[pre]==t[pre]) pre++;
		int now=0;
		for(int j=pre-1;j>=0;j--){
			int x=s[j]-'a';
			if(!son[now][x]) son[now][x]=++cnt;
			now=son[now][x];
		}
		ll ha=0;
		for(int j=pre;s[j];j++) ha=(ha*base+s[j])%mod,ha=(ha*base+t[j])%mod;
		has[now].emplace_back(ha);
	}
	for(int i=1;i<=ca;i++){
		cin>>s>>t;
		if(s.length()!=t.length()) continue;
		int pre=0,suf=s.length()-1;
		while(s[pre]==t[pre]) pre++;
		while(s[suf]==t[suf]) suf--;
		int now=0;
		for(int j=pre-1;j>=0;j--){
			int x=s[j]-'a';
			if(!son[now][x]) break;
			now=son[now][x];
		}
		as[now].emplace_back(i);
		ll ha=0;
		for(int j=pre;s[j];j++){
			ha=(ha*base+s[j])%mod,ha=(ha*base+t[j])%mod;
			if(j>=suf) p[i].emplace_back(ha);
		}
	}
	dfs(0);
	for(int i=1;i<=ca;i++) cout<<ans[i]<<"\n";
	return 0;
}