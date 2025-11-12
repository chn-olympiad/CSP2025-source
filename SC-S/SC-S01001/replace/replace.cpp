#include<bits/stdc++.h>
//#undef STDIO
const int N = 2e5 + 10, L = 5e6 + 10;
int n, q, pi[L];
std::string s[N][2], t[2];
long long ans = 0;
namespace bf{
	int pos[2][L], cnt[2];
	bool ep[L], er[L];
	void kmp(std::string s, std::string p, int id){
		s = p + '#' + s;
		cnt[id] = 0;
		int n = s.size(), m = p.size();
		for(int i = 1; i < n; i++){
			int j = pi[i - 1];
			while(j && s[j] != s[i]) j = pi[j - 1];
			if(s[j] == s[i]) j++;
			pi[i] = j;
			if(pi[i] == m) pos[id][++cnt[id]] = i - m - 1;
		}
	}
	void solve(){
		while(q--){
			std::cin >> t[0] >> t[1];
			if(t[0].size() != t[1].size()){
				printf("0\n");
				continue;
			}
			int l = t[0].size();
			ep[0] = t[0][0] == t[1][0];
			for(int i = 1; i < l; i++){
				ep[i] = ep[i - 1];
				ep[i] &= t[0][i] == t[1][i];
			}
			er[l - 1] = t[0][l - 1] == t[1][l - 1];
			for(int i = l - 2; i >= 0; i--){
				er[i] = er[i + 1];
				er[i] &= t[0][i] == t[1][i];
			}
			ans = 0;
			for(int i = 1; i <= n; i++){
				kmp(t[0], s[i][0], 0);
				kmp(t[1], s[i][1], 1);
				int ptr = 0;
				for(int j = 1; j <= cnt[0]; j++){
					while(ptr <= cnt[1] && pos[1][ptr] < pos[0][j]) ptr++;
					if(ptr <= cnt[1] && pos[0][j] == pos[1][ptr]){
						if(pos[0][j] >= (int)s[i][0].size()){
							if(!ep[pos[0][j] - (int)s[i][0].size()]) continue;
						}
						if(pos[0][j] + 1 < (int)t[0].size()){
							if(!er[pos[0][j] + 1]) continue;
						}
//						printf("%s -> %s, pos = %d\n", s[i][0].data(), s[i][1].data(), pos[0][j]);
						ans++;
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
}
int main(){
#ifndef STDIO
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	std::cin >> n >> q;
	for(int i = 1; i <= n; i++){
		std::cin >> s[i][0] >> s[i][1];
	}
	bf::solve();
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}