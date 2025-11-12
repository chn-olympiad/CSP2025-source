#include<bits/stdc++.h>
using ll = long long;
using db = double;
#define For(i,j,k) for(ll i = j;i <= k;i++)
#define Rep(i,j,k) for(ll i = j;i >= k;i--)
#define fi first
#define se second
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define pb push_back
#define eb emplace_back
using namespace std;
const ll N = 5e6 + 10,p = 998244353,inf = 1e18;
struct BIT{ll n;vector<ll> a;void it(ll _n){n = _n,a.assign(n,0);}
	void ad(ll x,ll v){for(;x <= n;x += x & (-x)) a[x] += v;}
	ll qry(ll x){ll o = 0;for(;x;x -= x & (-x)) o += a[x];return o;}
};void sol(){ll n,m;cin >> n >> m;vector<string> s1(n + 1),s2(n + 1),t1(m + 1),t2(m + 1);
	For(i,1,n) cin >> s1[i] >> s2[i];For(i,1,m) cin >> t1[i] >> t2[i];bool fl = 1;
	For(i,1,n) fl &= count(s1[i].begin(),s1[i].end(),'a') == s1[i].size() - 1;
	For(i,1,n) fl &= count(s1[i].begin(),s1[i].end(),'b') == 1;
	For(i,1,n) fl &= count(s2[i].begin(),s2[i].end(),'a') == s2[i].size() - 1;
	For(i,1,n) fl &= count(s2[i].begin(),s2[i].end(),'b') == 1;
	For(i,1,m) fl &= count(t1[i].begin(),t1[i].end(),'a') == t1[i].size() - 1;
	For(i,1,m) fl &= count(t1[i].begin(),t1[i].end(),'b') == 1;
	For(i,1,m) fl &= count(t2[i].begin(),t2[i].end(),'a') == t2[i].size() - 1;
	For(i,1,m) fl &= count(t2[i].begin(),t2[i].end(),'b') == 1;
	if(fl){
		vector<pll> a1(n + 1),a2(n + 1),b1(m + 1),b2(m + 1);
		For(i,1,n) For(j,0,(ll)s1[i].size() - 1) if(s1[i][j] == 'b') a1[i] = {j,s1[i].size() - j - 1};
		For(i,1,n) For(j,0,(ll)s2[i].size() - 1) if(s2[i][j] == 'b') a2[i] = {j,s2[i].size() - j - 1};
		For(i,1,m) For(j,0,(ll)t1[i].size() - 1) if(t1[i][j] == 'b') b1[i] = {j,t1[i].size() - j - 1};
		For(i,1,m) For(j,0,(ll)t2[i].size() - 1) if(t2[i][j] == 'b') b2[i] = {j,t2[i].size() - j - 1};
		vector<pair<pll,pll>> a(n + 1),b(m + 1);For(i,1,n) a[i] = {a1[i],a2[i]};
		For(i,1,m) b[i] = {b1[i],b2[i]};map<pll,ll> mp;ll to = 0;
		For(i,1,n) if(!mp.count({a[i].fi.fi - a[i].se.fi,a[i].fi.se - a[i].se.se})) 
			mp[{a[i].fi.fi - a[i].se.fi,a[i].fi.se - a[i].se.se}] = ++to;
		For(i,1,m) if(!mp.count({b[i].fi.fi - b[i].se.fi,b[i].fi.se - b[i].se.se})) 
			mp[{b[i].fi.fi - b[i].se.fi,b[i].fi.se - b[i].se.se}] = ++to;
		vector<vector<pair<pair<pll,pll>,pll>>> g(to + 1);vector<ll> as(m + 1);
		For(i,1,n) g[mp[{a[i].fi.fi - a[i].se.fi,a[i].fi.se - a[i].se.se}]].pb({a[i],{i,0}});
		For(i,1,m) g[mp[{b[i].fi.fi - b[i].se.fi,b[i].fi.se - b[i].se.se}]].pb({b[i],{i,1}});
		for(auto &v : g) if(!v.empty()){
			sort(v.begin(),v.end(),[&](auto x,auto y){return x.fi.fi.fi == y.fi.fi.fi ? x.se.se < y.se.se : x.fi.fi.fi < y.fi.fi.fi;});
			vector<ll> tb;for(auto p : v) tb.pb(p.fi.fi.se);
			sort(tb.begin(),tb.end()),tb.erase(unique(tb.begin(),tb.end()),tb.end());
			for(auto &p : v) p.fi.fi.se = lower_bound(tb.begin(),tb.end(),p.fi.fi.se) - tb.begin() + 1;
			BIT tr;tr.it(tb.size() + 10);
			for(auto &p : v) if(p.se.se) as[p.se.fi] = tr.qry(p.fi.fi.se);else tr.ad(p.fi.fi.se,1);
		}For(i,1,m) cout << as[i] << '\n';return;
	}auto ck = [&](string t1,string t2,string s1,string s2){map<ll,ll> v1,v2; 
		if(t1.size() != t2.size() || t1.size() < s1.size() || t2.size() < s2.size()) return false;
		For(i,0,(ll)t1.size() - (ll)s1.size()) if(t1.substr(i,s1.size()) == s1) v1[i] = 1;
		For(i,0,(ll)t2.size() - (ll)s2.size()) if(t2.substr(i,s2.size()) == s2) v2[i] = 1;
		if(v1.size() > 1 || v2.size() > 1) return false;
		for(auto p : v1) if(v2[p.fi]){
			t1 = t1.substr(0,p.fi) + s2 + t1.substr(p.fi + s1.size());
			return t1 == t2;
		}return false;
	};For(i,1,m){ll o = 0;For(j,1,n){if(ck(t1[i],t2[i],s1[j],s2[j])) o++;}cout << o << '\n';} 
}int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T = 1;while(T--) sol();return 0; 
}

//5 5
//aabaa abaaa
//aba aab
//aab baa
//aba baa
//baa aab
//aaaabaaaa aaabaaaaa
//baaaaaaaa abaaaaaaa
//aabaa baaaa
//abaaa baaaa
//aabaa aaaab
