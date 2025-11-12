#include<bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define mid(l, r) ((l + r) >> 1)
#define pii pair<int, int>
#define sec second
#define fir first
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n, q;
string s1[N], s2[N];
int f[26], p[N], p1[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	bool g = 1;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		if(!g) continue;
		for(char c : s1[i]) f[c - 'a']++;
		for(char c : s2[i]) f[c - 'a']++;
		for(int j = 2; j < 26; j++) if(f[j] > 0){
			g = 0; break;
		}
		if(f[1] != 2) g = 0;
		for(int j = 0; j < 26; j++) f[j] = 0;
	}
	if(g){
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < int(s1[i].size()); j++) if(s1[i][j] == 'b'){
				p[i] = j;
				break;
			}
			for(int j = 0; j < (int)(s2[i].size()); j++) if(s2[i][j] == 'b'){
				p1[i] = j;
				break;
			}		
		}
	}
	while(q--){
		string a1, b1; cin >> a1 >> b1;
		if(int(a1.size()) != int(b1.size())){
			cout << 0 << "\n";
			continue;
		}
		if(g){
			int pos, pos1;
			for(int j = 0; j < int(a1.size()); j++) if(a1[j] == 'b'){
				pos = j;
				break;
			}
			for(int j = 0; j < int(int(b1.size())); j++) if(b1[j] == 'b'){
				pos1 = j;
				break;
			}
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(p[i] > pos || (int(s1[i].size()) - p[i]) > (int(a1.size()) - pos) || p1[i] > pos1 || (int(s2[i].size()) - p1[i]) > ((int)(b1.size()) - pos1) || (p[i] - p1[i]) != (pos - pos1)) continue;
				++ans;
			}
			cout << ans << "\n";
			continue;
		}
		int L = -1, R = 0;
		for(int i = 0; i < int(a1.size()); i++){
			if(a1[i] != b1[i]){
				if(L == -1) L = i;
				R = i;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(R - L + 1 > int(s1[i].size())) continue;
			for(int j = 0; j < int(a1.size()); j++){
				if(s1[i][0] == a1[j] && i + int(s1[i].size()) >= R){
					bool f = 1;
					for(int k = j, l = 0; k < int(a1.size()) && l < int(s1[i].size()); k++, l++){
						if(s1[i][l] != a1[k] || s2[i][l] != b1[k]){
							f = 0;
							break;
						}
					}
					if(f) ++ans;
				}
			}
		}
		cout << ans;
	}
	return 0;
}

