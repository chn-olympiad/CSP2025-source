#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector <char> s[N], t[N], fr, to, mi;
int len[N], n, q;
string tmp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		len[i] = tmp.length();
		s[i].resize(len[i] + 9);
		s[i].clear();
		for(int j = 1; j <= len[i]; j++)
			s[i][j] = tmp[j - 1];
		cin >> tmp;
		t[i].resize(len[i] + 9);
		t[i].clear();
		for(int j = 1; j <= len[i]; j++)
			t[i][j] = tmp[j - 1];
	}
	for(int T = 1; T <= q; T++){
		cin >> tmp;
		int len1 = tmp.length();
		fr.resize(len1 + 9);
		fr.clear();
		for(int j = 1; j <= len1; j++)
			fr[j] = tmp[j - 1];
		cin >> tmp;
		int len2 = tmp.length();
		to.resize(len2 + 9);
		to.clear();
		for(int j = 1; j <= len2; j++)
			to[j] = tmp[j - 1];
		if(len1 != len2){
			printf("0\n");
			continue;
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j + len[i] - 1 <= len1; j++){
				mi.resize(len1 + 9);
				mi.clear();
				for(int k = 1; k <= len1; k++)
					mi[k] = fr[k];
				bool flag = true;
				for(int k = j; k <= j + len[i] - 1; k++){
					if(mi[k] != s[i][k - j + 1]){
						flag = false;
						break;
					}
				}
				if(!flag)
					continue;
				for(int k = j; k <= j + len[i] - 1; k++)
					mi[k] = t[i][k - j + 1];
				flag = true;
				for(int k = 1; k <= len1; k++){
					if(mi[k] != to[k]){
						flag = false;
						break;
					}
				}
				if(flag)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}