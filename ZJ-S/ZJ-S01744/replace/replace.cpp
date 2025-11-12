#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=2e7+5;
const int maxm=1e4+5;
const ll INF=1e18;
ll n,q;
struct node{
	ll l,r,len;
};
map<ll,vector<node> >del;
ll diff(string a,string b) {
	ll pos1,pos2;
	for(int i=0;i<a.size();i++) {
		if(a[i]=='b') pos1=i; 
		if(b[i]=='b') pos2=i; 
	}
	return pos1-pos2;
}
void solve() {
	cin >> n >> q;
	for(int i=1;i<=n;i++) {
		string t1,t2;
		cin >> t1 >> t2;
		ll pos1,pos2;
		for(int i=0;i<t1.size();i++) {
			if(t1[i]=='b') pos1=i; 
			if(t2[i]=='b') pos2=i; 
		}
		del[pos1-pos2].push_back({pos1-1,t1.size()-pos1-1,t1.size()});
	}
	while(q--) {
		string s1,s2;
		cin >> s1>> s2;
		if(s1.size()!=s2.size()) {
			cout << 0 << "\n";
			continue;
		}
		ll target=diff(s1,s2);
//		cout << target << "\n";
		ll pos;
		for(int i=0;i<s1.size();i++) {
			if(s1[i]=='b') pos=i;
		}
		ll lef=pos-1;
		ll rig=s1.size()-pos-1;
		ll res=0;
		for(auto x:del[target]) {
			if(x.len>s1.length()) continue;
			if(x.l<=lef&&rig>=x.r) res++;
//			cout << x.l << " "<< x.r << "\n";
		}
		cout << res << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cin >> T;
//	while(T--) {
		solve();
//	}
}
