#include<bits/stdc++.h>
using namespace std;

struct Info{
	string s, t;
} a[200010];

int n, m, q, ans;
map<string, int> b;
string s, t;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i].s >> a[i].t;
		b[a[i].s] = i;
	}
	while(q--){
		ans = 0;
		cin >> s >> t;
		m = s.size();
		s = " " + s;
		t = " " + t;
		for(int l = 1; l <= m; l++){
			for(int r = l; r <= m; r++){
				string S = "", T = "";
				for(int i = l; i <= r; i++){
					S += s[i];
					T += t[i];
				}
				if(S == T){
					continue;
				}
				int d = b[S];
				if(d == 0){
					continue;
				}
				S = s;
				for(int i = l; i <= r; i++){
					S[i] = a[d].t[i - l];
				}
				if(S == t){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
//	cout << "You have no egg!!!";
	return 0;
}
