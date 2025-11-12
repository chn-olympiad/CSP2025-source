# include <bits/stdc++.h>
# define endl '\n'
typedef long long i64;

const int _ = 2e5 + 10;

//namespace achoc{
//	const int __ = 5e6 + 10;
//	int tr[_][27], cnt[_], tot = 0;
//	int ctoi(char c){
//		if(c == '#') return 26;
//		return c - 'a';
//	}
//	void ins(std::string x){
//		int p = 0;
//		for(int i = 0;i < x.size();i++){
//			int c = ctoi(x[i]);
//			if(!tr[p][c]) tr[p][c] = ++ tot;
//			p = tr[p][c];
//		}
//		cnt[p] ++;
//		return ;
//	}
//	
//	int lst[27], fail[_];
//	void get_fail(){
//		std::queue<int> q;
//		q.emplace(0);
//		fail[0] = 0;
//		while(!q.empty()){
//			int p = q.front();
//			q.pop();
//			for(int c = 0;c <= 26;c++){
//				if(!tr[p][c]) fail[p][c] = lst[c];
//				else lst[c] = p;
//			}
//		}
//		return ;
//	}
//	
//	void clear(){
//		for(int i = 1;i <= tot;i++){
//			for(int j = 0;j <= 26;j++) tr[i][j] = 0;
//			cnt[i] = fail[i] = 0;
//		}
//		tot = 0;
//	}
//}

int n, q;
std::string s[_][2], t[_][2];
std::string ss[_], tt[_], ns[_], nt[_];

const int P = 998244853;
const int B = 233;
int pw[5000010];

std::vector<int> hnt[_];
int hss[_], htt[_], hns[_];

int ans[_];
std::unordered_map<int, std::vector<int> > to_s, to_t;

signed main(){
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::cin >> n >> q;
	pw[0] = 1;
	for(int i = 1;i <= 5000000;i++){
		pw[i] = 1LL * pw[i - 1] * B % P;
	}
	for(int i = 1;i <= n;i++){
		std::cin >> s[i][0] >> s[i][1];
		int sz = s[i][0].size();
		ns[i] = " ";
		int l, r;
		for(l = 0;l < sz;l++){
			if(s[i][0][l] != s[i][1][l]) break ;
		}
		for(r = sz - 1;r >= 0;r--){
			if(s[i][0][r] != s[i][1][r]) break ;
		}
		ns[i] = s[i][0].substr(0, l) + "#" + s[i][0].substr(r + 1, sz - r);
		ss[i] = s[i][0].substr(l, r - l + 1) + s[i][1].substr(l, r - l + 1);
	}
	for(int i = 1;i <= q;i++){
		std::cin >> t[i][0] >> t[i][1];
		if(t[i][0].size() != t[i][1].size()) continue;
		int sz = t[i][0].size();
		nt[i] = " ";
		int l, r;
		for(l = 0;l < sz;l++){
			if(t[i][0][l] != t[i][1][l]) break ;
		}
		for(r = sz - 1;r >= 0;r--){
			if(t[i][0][r] != t[i][1][r]) break ;
		}
		nt[i] = t[i][0].substr(0, l) + "#" + t[i][0].substr(r + 1, sz - r);
		tt[i] = t[i][0].substr(l, r - l + 1) + t[i][1].substr(l, r - l + 1);
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < ss[i].size();j++) hss[i] = (1LL * hss[i] * B % P + ss[i][j]) % P;
		for(int j = 0;j < ns[i].size();j++) hns[i] = (1LL * hns[i] * B % P + ns[i][j]) % P;
		to_s[hss[i]].emplace_back(i);
	}
	for(int i = 1;i <= q;i++){
		if(t[i][0].size() != t[i][1].size()) continue;
		for(int j = 0;j < tt[i].size();j++) htt[i] = (1LL * htt[i] * B % P + tt[i][j]) % P;
		hnt[i].emplace_back(0);
		for(int j = 0;j < nt[i].size();j++){
			int h = (1LL * hnt[i][j] * B % P + nt[i][j]) % P;
			hnt[i].emplace_back(h);
		}
		to_t[htt[i]].emplace_back(i);
	}
	
	for(auto &pp : to_t){
		for(auto &y : pp.second){
			int py;
			for(py = 0;py < nt[y].size();py++){
				if(nt[y][py] == '#') break ;
			}
			for(auto &x : to_s[pp.first]){
				int px;
				for(px = 0;px < ns[x].size();px++){
					if(ns[x][px] == '#') break ;
				}
				
				int l = py - px, r = py - px + ns[x].size() - 1;
				if(l < 0 || r >= nt[y].size()) continue ;
				int hsh = (hnt[y][r + 1] - 1LL * hnt[y][l] * pw[r - l + 1] % P + P) % P;
				if(hsh == hns[x]) ans[y] ++;
			}
		}
	}
	
	for(int i = 1;i <= q;i++){
		std::cout << ans[i] << endl;
	}
	return 0;
} 
