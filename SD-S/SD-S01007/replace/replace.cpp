#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
template<typename T>void cmax(T &x, T y){x = max(x, y);}
template<typename T>void cmin(T &x, T y){x = min(x, y);}
const int N = 5e5 + 5, M = 5e6 + 5;
bool M1;
int n, q, tot = 1, ch[M][26], fail[M];
int pos[N][2], lt[N];
int insert(string s){
	int now = 1;
	for(auto c : s){
		if(!ch[now][c - 'a']) ch[now][c - 'a'] = ++tot;
		now = ch[now][c - 'a'];
	}
	return now;
}
vector<int> e[M];
void build(){
	queue<int> q;
	For(i, 0, 25){
		if(!ch[1][i]) ch[1][i] = 1;
		else fail[ch[1][i]] = 1, q.push(ch[1][i]);
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
		For(i, 0, 25){
			if(!ch[now][i]) ch[now][i] = ch[fail[now]][i];
			else fail[ch[now][i]] = ch[fail[now]][i], q.push(ch[now][i]);
		}
	}
	For(i, 2, tot) e[fail[i]].push_back(i);
}
int tim, L[M], R[M];
bool in(int x, int l, int r){return x >= l && x <= r;}
void dfs(int now){
	L[now] = ++tim;
	for(int to : e[now]) dfs(to);
	R[now] = tim;
}
bool M2;
void Solve(){
	cin >> n >> q;
	For(i, 1, n){
		string s1, s2; cin >> s1 >> s2;
		pos[i][0] = insert(s1); pos[i][1] = insert(s2); lt[i] = s1.size();
	}
	build(); dfs(1);
	For(id, 1, q){
		string t1, t2; cin >> t1 >> t2;
		int len = t1.size(), u = 1, v = 1, ans = 0;
		int l1 = 0, l2 = 0;
		while(l1 < t1.size() && t1[l1] == t2[l1]) l1++;
		while(l2 < t1.size() && t1[len - l2 - 1] == t2[len - l2 - 1]) l2++;
		For(i, 0, len - 1){
			u = ch[u][t1[i] - 'a']; v = ch[v][t2[i] - 'a'];
			if(i + 1 + l2 < len) continue;
			For(j, 1, n) if(in(L[u], L[pos[j][0]], R[pos[j][0]]) && in(L[v], L[pos[j][1]], R[pos[j][1]]) && lt[j] >= i - l1 + 1) ++ans;
		}
		cout << ans << '\n';
	}
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1; //cin >> T;
	while(T--) Solve();
	return 0;
}

