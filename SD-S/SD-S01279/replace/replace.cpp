#include<bits/stdc++.h>
using namespace std;
bool STSTST;

const int N = 2e5 + 5;

int n,q,pre[2][N],suf[2][N];

bool EDEDED;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
//	struct _timeb TT;
//	_ftime(&TT);
//	default_random_engine rng(TT.millitm);
//	mt19937 rnd(TT.millitm);
	
	cin >> n >> q;
	for (int i = 1;i <= n;++i){
		string s,t;
		cin >> s >> t;
		int j = 0;
		for (;s[j] != 'b';++j) pre[0][i]++;
		j++;
		for (;j < s.size();++j) suf[0][i]++;
		j = 0;
		for (;t[j] != 'b';++j) pre[1][i]++;
		j++;
		for (;j < t.size();++j) suf[1][i]++;
	}while (q--){
		string s,t;
		cin >> s >> t;
		int x = 0,y = 0;
		for (;s[x] != 'b';x++);
		for (;t[y] != 'b';y++);
		int cnt = 0;
		for (int i = 1;i <= n;++i){
			if (pre[0][i] <= x && suf[0][i] <= (int)s.size() - x - 1 && x - pre[0][i] + pre[1][i] == y && (int)s.size() - x - 1 - suf[0][i] + suf[1][i] == (int)t.size() - y - 1){
				cnt++;
			}
		} cout << cnt << '\n';
	} 
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms\n";
//	cerr << "memory used: " << abs(&STSTST - &EDEDED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}

