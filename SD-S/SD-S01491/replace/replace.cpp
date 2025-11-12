#include<bits/stdc++.h>
#define N 1000010
#define M 1000010
#define fo(a, b, c) for(int b = a; b <= c; b++)
#define _fo(a, b, c) for(int b = a; b >= c; b--)
#define Fo(a, b) for(auto a : b)
#define pb push_back
#define lb lower_bound
using namespace std;
//#define int long long
#define ull unsigned long long
ull hsh1[N], hsh2[N], p[N], hsh3[N], hsh4[N];
string s1[M], s2[M], t1, t2;
int n, q;
void solve(){
	int ans = 0;
	cin >> t1 >> t2; t1 = " " + t1, t2 = " " + t2;
	int szt = t1.size(); szt--;
	fo(1, i, szt){
		ull c1 = t1[i] - 'a', c2 = t2[i] - 'a';
		hsh3[i] = hsh3[i - 1] + c1 * p[i - 1];
		hsh4[i] = hsh4[i - 1] + c2 * p[i - 1];
	}
	hsh3[szt + 1] = hsh3[szt], hsh4[szt + 1] = hsh4[szt];
	fo(1, i, n){
		int sz = s1[i].size(); sz--;
		fo(1, j, sz){
			ull c1 = s1[i][j] - 'a', c2 = s2[i][j] - 'a';
			hsh1[j] = hsh1[j - 1] + c1 * p[j - 1];
			hsh2[j] = hsh2[j - 1] + c2 * p[j - 1];
		}
		hsh1[sz + 1] = hsh1[sz], hsh2[sz + 1] = hsh2[sz];
		if(szt >= sz){
			fo(sz, j, szt){
				int r = j, l = j - sz + 1;
				ull tmp = hsh1[sz] * p[l - 1];
				if(hsh3[r] - hsh3[l - 1] == tmp){
					ull cmp = hsh3[r + 1] - hsh3[r] + hsh2[sz] * p[l - 1] + hsh3[l - 1];
					if(cmp == hsh4[szt]) ans++;  
				} 
			}
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	fo(1, i, 1000000) p[i] = p[i - 1] * 26;
	if(n <= 1000){
		fo(1, i, n) cin >> s1[i] >> s2[i], s1[i] = " " + s1[i], s2[i] = " " + s2[i];
		fo(1, i, q) solve();
	}
	//fo()
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

