#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 200050, L = 5000050, MOD = 1e9 + 7, base = 131;

int hs(string s){
	int h = 0;
	for(char i : s)
		h = ((ll)h * base + i) % MOD;
	return h;
}

void HS(string s, int H[]){
	int len = s.size();
	s = " " + s;
	for(int i = 1; i <= len; i ++){
		H[i] = ((ll)H[i - 1] * base + s[i]) % MOD;
	}
}

int n, q;
int h1[N], h2[N], H1[L], H2[L], p[L], len[N];
string a, b;

int geth(int H[], int l, int r){
	return ((H[r] - (ll)H[l - 1] * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> a >> b;
		len[i] = (int)a.size();
		h1[i] = hs(a), h2[i] = hs(b);
	}
	p[0] = 1;
	for(int i = 1; i < L; i ++)
		p[i] = (ll)p[i - 1] * base % MOD;
	while(q --){
		cin >> a >> b;
		HS(a, H1); HS(b, H2);
		int ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= (int)a.size() - len[i] + 1; j ++){
				if(geth(H1, j, j + len[i] - 1) == h1[i] && geth(H2, j, j + len[i] - 1) == h2[i] && (j == 1 || geth(H1, 1, j - 1) == geth(H2, 1, j - 1)) && (j == (int)a.size() - len[i] + 1 || geth(H1, j + len[i], (int)a.size()) == geth(H2, j + len[i], a.size()))){
					ans ++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}