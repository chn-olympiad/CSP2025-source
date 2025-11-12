#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb emplace_back
inline ll read(){ ll x; cin>>x; return x; }
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define mkp make_pair

const ull mod = (ll)1e18 + 3, base = rnd() % (ll)1e18;

int N,n,q,ans[200005];
string s1[200005],s2[200005],sL[200005],sR[200005];
string t1[200005],t2[200005],tL[200005],tR[200005];
ull hs[200005], ht[200005];

vector<int>upd[400005], qry[400005];

inline ull Hash(string &S){
	ull ans = 0;
	for(auto ch: S)
		ans = ((__int128)ans * base + ch) % mod;
	return ans;
}
ull ud[400005]; int tmp;

namespace SOLVE{
	const int NN = 10000005;
	int son[NN][26], id, low[NN]; vector<int>uu[NN], qq[NN];

	inline int ins(string &S){
		int now = 1;
		for(auto x: S){
			if(!son[now][x-'a']) son[now][x-'a']=(++id);
			now = son[now][x-'a'];
		}
		return now;
	}

	void dfs(int pos){
		for(auto x: uu[pos]){
			int fw = ins(sR[x]);
			low[fw] ++;

			// cout<<"insert "<<x<<" at "<<fw<<endl;
		}
		for(auto y: qq[pos]){
			int now = 1;

			// cout<<"query "<<y<<" at "<<now<<endl;
			ans[y] += low[now];

			for(auto x: tR[y]){
				if(!son[now][x-'a']) son[now][x-'a']=(++id);
				now = son[now][x-'a'];
				ans[y] += low[now];
				// cout<<"query "<<y<<" at "<<now<<endl;
			}
		}
		for(int x=0; x<26; x++)
			if(son[pos][x]) dfs(son[pos][x]);

		for(auto x: uu[pos]){
			int fw = ins(sR[x]);
			low[fw] --;

			// cout<<"delete "<<x<<" at "<<fw<<endl;
		}
	}
	void main(int o){
		for(int i=1;i<=id;i++) memset(son[i],0,sizeof(son[i])), low[i] = 0;
		for(int i=1;i<=id;i++) uu[i].clear(), qq[i].clear();
		id = 1;

		#define U upd[o]
		#define Q qry[o]

		for(int x: U){
			// cout<<"upd "<<x<<" as "<<sL[x]<<" "<<sR[x]<<endl;
			// cout<<"act "<<s1[x]<<" "<<s2[x]<<endl;
			uu[ins(sL[x])].pb(x);
		}
		for(int y: Q){
			// cout<<"qry "<<y<<" as "<<tL[y]<<" "<<tR[y]<<endl;
			// cout<<"act "<<t1[y]<<" "<<t2[y]<<endl;
			qq[ins(tL[y])].pb(y);
		}

		dfs(1);
	}
}
void procedure(){
	N=read(),q=read();
	// int fw = 0;
	while(N--){
		string A,B; cin>>A>>B;
		if(A==B) continue;

		// if(A=="r" && B =="p") fw++;
		s1[++n] = A, s2[n] = B;
		int l=0, r=A.size()-1;
		while(s1[n][l] == s2[n][l]) l++;
		while(s1[n][r] == s2[n][r]) r--;

		for(int i=l-1;i>=0;i--) sL[n].push_back(s1[n][i]);
		for(int i=r+1;i<s1[n].size();i++) sR[n].push_back(s1[n][i]);

		string TMP = s1[n].substr(l,r-l+1) + s2[n].substr(l,r-l+1);
		hs[n] = Hash(TMP); ud[++tmp] = hs[n];
	}
	// cout<<"fw = "<<fw<<endl;
	// q = 1;
	// t1[1] = "r", t2[1] = "p";

	for(int i=1;i<=q;i++){
		cin >> t1[i] >> t2[i];
		// if(i == 1175){
		// 	cerr<<t1[i]<<" "<<t2[i]<<endl;
		// }
		if(t1[i].size() != t2[i].size()) continue;

		int l=0, r=t1[i].size()-1;
		while(t1[i][l] == t2[i][l]) l++;
		while(t1[i][r] == t2[i][r]) r--;

		for(int j=l-1;j>=0;j--) tL[i].push_back(t1[i][j]);
		for(int j=r+1;j<t1[i].size();j++) tR[i].push_back(t1[i][j]);

		string TMP = t1[i].substr(l,r-l+1) + t2[i].substr(l,r-l+1);
		ht[i] = Hash(TMP); ud[++tmp] = ht[i];
	}

	sort(ud+1, ud+tmp+1); tmp=unique(ud+1, ud+tmp+1)-(ud+1);

	for(int i=1;i<=n;i++){
		hs[i] = lower_bound(ud+1, ud+tmp+1, hs[i])-ud;
		upd[hs[i]].pb(i);
	}

	for(int i=1;i<=q;i++){
		if(t1[i].size() == t2[i].size()){
			ht[i] = lower_bound(ud+1, ud+tmp+1, ht[i])-ud;
			qry[ht[i]].pb(i);
		}
	}

	for(int i=1;i<=tmp;i++){
		if(upd[i].size() && qry[i].size()) SOLVE::main(i);
	}

	for(int i=1;i<=q;i++) printf("%d\n", ans[i]);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	assert(freopen("replace.in","r",stdin));
	assert(freopen("replace.out","w",stdout));
	ll T=1;
	while(T--) procedure();
}