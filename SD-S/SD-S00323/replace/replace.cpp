#include<bits/stdc++.h>
#define endl '\n'
#define rep(A, B, C) for(int (A) = (B); (A) <= (C); A++)
#define dwn(A, B, C) for(int (A) = (B); (A) >= (C); A--)
#define debug "--------------\n"
using namespace std;

const int N = 2e5 + 5, L = 5e6 + 5;
string s[N][4];
int n;
int nxt[N], f[N];

vector<int> kmp(string t, string s){
	int n = s.size();
	int m = t.size();
	memset(nxt, 0, sizeof(nxt));
	memset(f, 0, sizeof(f));
	for(int i = 2, j = 0; i <= m; i++){
		while(s[i] != s[j + 1] && j) j = nxt[j];
		nxt[i] = j;
		if(s[i] == s[j + 1]) nxt[i]++;
	}
	rep(i, 1, m) cout << nxt[i] << " ";
	cout << endl;
	vector<int> pos;
	for(int i = 2, j = 1; i <= n; i++){
		while(t[i] != s[j + 1] && j) j = nxt[j];
		f[i] = j;
		if(t[i] == s[j + 1]) f[i]++;
		if(f[i] == m) pos.push_back(i - m + 1); 
	}
	return pos;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int q;
	cin >> n >> q;
	rep(i, 1, n){
		cin >> s[i][1] >> s[i][2];
		s[i][1] = " " + s[i][1];
		s[i][2] = " " + s[i][2];
	}
	
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		s1 = " " + s1;
		s2 = " " + s2;
		int ans = 0;
		rep(i, 1, n){
			vector<int> pos = kmp(s1, s[i][1]);
			for(int p : pos){
				string pre;
				for(int i = 0; i <= p - 1; i++) pre += s1[i];
				string suf;
				for(int i = p + s[i][1].size() - 1; i <= s1.size(); i++) suf += s1[i];
				string cur = pre + s[i][1] + suf;
				if(cur == s2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

