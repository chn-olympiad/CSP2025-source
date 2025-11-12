#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 5e6 + 10;
const ull bit = 1313131;
struct node{
	int x, l, r;
	ull w;
};
unordered_map<ull, int>mp[N];
ull B[N];
struct ACM{
	int to[N][26], tot, fail[N], dep[N];
	void insert(string s, ull w){
		int it = 0;
		for(auto c : s){
			if(!to[it][c])to[it][c] = ++tot, dep[tot] = dep[it] + 1;
//			cout << it << ' ';
			it = to[it][c];
//			cout << it << ' ' << char(c + 'a') << '\n';
		}
		mp[it][w]++;
	}
	void get_fail(){
		queue<int>q; 
		for(int i = 0; i < 26; i++)
			if(to[0][i])q.push(to[0][i]);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < 26; i++){
				if(!to[u][i])to[u][i] = to[fail[u]][i];
				else fail[to[u][i]] = to[fail[u]][i], q.push(to[u][i]);
			}
		}
//		for(int i = 1; i <= tot; i++)
//			cout << fail[i] << ' ';
//		cout << '\n';
	}
	bool vis[N]; int stk[N], stt;
	int qry(string s1, string s2, int L, int R){
		queue<node>q; q.push({0, 0, -1, 0}); int res = 0;
		while(!q.empty()){
			auto p = q.front(); q.pop();
			int u = p.x, l = p.l, r = p.r; ull w = p.w;
			cout << u << ' ' << l << ' ' << r << ' ' << w << '\n';
			stk[++stt] = u; 
			if(l > L)continue;
			if(r >= R)res += mp[u][w];
			int i = s1[r + 1];
				if(to[u][i] && !vis[to[u][i]]),vis[to[u][i]] = 1, q.push({to[u][i], l, r + 1, w * bit + s2[r + 1]});
				else if(!vis[fail[u]] && fail[u]){
					vis[fail[u]] = 1; int v = fail[u];
					int tl = l + (dep[u] - dep[v]);
					ull tw = w;
					for(int j = l; j < tl; j++)
						tw -= s2[j] * B[r - j];
					q.push({v, tl, r, tw});
				}
		}
		do{
			vis[stk[stt]] = 0;
		}while(--stt);
		return res;
	}
};
ACM a;
int n, m;
signed main(){
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	B[0] = 1; for(int i = 1; i < N; i++)B[i] = B[i - 1] * bit;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		for(auto &c : s1)c -= 'a';
		for(auto &c : s2)c -= 'a';
		ull w = 0;
		for(auto c : s2)w = w * bit + c;
		a.insert(s1, w);
	}
	a.get_fail();
	for(int i = 1; i <= m; i++){
		string t1, t2;
		cin >> t1 >> t2;
		for(auto &c : t1)c -= 'a';
		for(auto &c : t2)c -= 'a';
		int L = 0, R = t1.size() - 1;
		while(t1[L] == t2[L])L++; L--;
		while(t1[R] == t2[R])R--; R++;
		cout << a.qry(t1, t2, L, R) << '\n';
	}
	return 0;
}