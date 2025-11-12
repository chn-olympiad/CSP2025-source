#include <bits/stdc++.h>
using namespace std;
const int sed = 233;
int n, q, val[200005], ans[200005];
string str[200005];
unsigned long long lsh[200005], hs[200005], pw[5000005];

int C[5000005];
int rt, ch[5000005][26], tot, dfn[5000005], dfntot, sz[5000005];
vector<string> vec[200005];
vector<pair<int, int> > que[200005];
pair<int, int> S[200005];
int Stot;

void dfs(int x){
	if(!x) return ;
	dfn[x] = ++dfntot;
	sz[x] = 1;
	for(int i = 0; i < 26; i++){
		dfs(ch[x][i]);
		sz[x] += sz[ch[x][i]]; 
	}
}

void add(int x, int c){
	for(int i = x; i <= sz[1]; i += (i & (-i))) C[i] += c;
}
int ask(int x){
	int res = 0;
	for(int i = x; i; i -= (i & (-i))) res += C[i];
	return res;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	pw[0] = 1;
	for(int i = 1; i <= 5000000; i++) pw[i] = pw[i - 1] * sed;
	
	rt = tot = 1;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s, t;
		cin >> s >> t;
		if(s == t) continue;
		
		int l = -1, r = -1;
		for(int j = 0; j < (int)s.size(); j++){
			if(s[j] != t[j]){
				if(l == -1) l = j;
				r = j;
			} 
		}
		
		for(int j = 0; j <= r; j++) hs[i] = hs[i] * sed + s[j];
		for(int j = l; j <= r; j++) hs[i] = hs[i] * sed + t[j];
		
		for(int j = r + 1; j < (int)s.size(); j++) str[i] += s[j];
		
		lsh[i] = hs[i];
	}
	sort(lsh + 1, lsh + n + 1);
	for(int i = 1; i <= n; i++) val[i] = lower_bound(lsh + 1, lsh + n + 1, hs[i]) - lsh;
	
	for(int i = 1; i <= n; i++){
		vec[val[i]].push_back(str[i]);
	}
	
//	cout << "val: ";
//	for(int i = 1; i <= n; i++) cout << val[i] << " ";
//	cout << "\n";
//	cout << "str: ";
//	for(int i = 1; i <= n; i++) cout << str[i] << " ";
//	cout << "\n";
	
	for(int i = 1; i <= q; i++){
		string s, t;
		cin >> s >> t;
		if((int)s.size() != (int)t.size()){
			ans[i] = 0;
			continue;
		}
		
		int l = -1, r = -1;
		for(int j = 0; j < (int)s.size(); j++){
			if(s[j] != t[j]){
				if(l == -1) l = j;
				r = j;
			} 
		}
		
		unsigned long long HS = 0;
		for(int j = l; j <= r; j++) HS = HS * sed + s[j];
		for(int j = l; j <= r; j++) HS = HS * sed + t[j];
		
		int u = rt;
		for(int j = r + 1; j < (int)s.size(); j++){
			if(!ch[u][s[j] - 'a']){
				ch[u][s[j] - 'a'] = ++tot;
			}
			u = ch[u][s[j] - 'a'];
		}
		
		int len = (r - l + 1) * 2;
		
		for(int j = l; j >= 0; j--){
			if(j != l){
				HS += pw[len] * s[j];
				len++;
			}
			
			int p = lower_bound(lsh + 1, lsh + n + 1, HS) - lsh;
			if(p != n + 1 && lsh[p] == HS){
//				cout << "insert " << i << " " << j << " " << p << endl;
				que[p].push_back(make_pair(u, i));
			}
		}
	}
//	cout << "tot = " << tot << endl;
//	for(int i = 1; i <= tot; i++) {
//		for(int j = 0; j < 26; j++){
//			cout << ch[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	dfs(rt);
	for(int i = 1; i <= n; i++){
		if((int)que[i].size() == 0) continue;
		Stot = 0;
		
		for(int j = 0; j < (int)vec[i].size(); j++){
			int u = rt, len = vec[i][j].size();
			for(int k = 0; k < len; k++){
				u = ch[u][vec[i][j][k] - 'a'];
				if(!u) break;
			}
			
			if(u){
				S[++Stot] = {dfn[u], dfn[u] + sz[u]};
				add(dfn[u], 1);
				add(dfn[u] + sz[u], -1);
			}
		}
		
		for(int j = 0; j < (int)que[i].size(); j++){
			int u = dfn[que[i][j].first];
			ans[que[i][j].second] += ask(u);
		}
		
		for(int j = 1; j <= Stot; j++){
			add(S[j].first, -1);
			add(S[j].second, 1);
		}
	}
	
	for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
	return 0;
}
