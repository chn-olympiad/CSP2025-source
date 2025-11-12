#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int n, m;
string t[2][200050];
int nxt[5000050];

string rep(string s, int l, int len, string u){
	string res = "";
	for(int i = 0;i < l;i ++) res += s[i];
	res += u;
	for(int i = l + len;i < s.length();i ++) res += s[i];
	return res;
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> t[0][i] >> t[1][i];
	for(int k = 1;k <= m;k ++){
		int ans = 0;
		string s, u;
		cin >> s >> u;
		nxt[0] = -1;
		for(int i = 1, j = 0;i < s.length();i ++){
			while(s[i] != s[j] && j >= 0) j = nxt[j];
			nxt[i] = ++ j;
		}
		for(int l = 1;l <= n;l ++){
			for(int i = 0, j = 0;i < s.length();i ++){
				if(s[i] == t[0][l][j]){
					j ++;
				}else{
					j = max(0, nxt[i]);
				}
				if(j == t[0][l].length()){
//					cout << s << " " << i - j + 1 << " " << j << " " << t[1][l] << endl;
					if(rep(s, i - j + 1, j, t[1][l]) == u){
						ans ++;
						break;
					}
					j = nxt[i];
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
