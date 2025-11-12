#include<bits/stdc++.h>
using namespace std;
bool STSTST;

const int N = 5e2 + 5;
const int mod = 998244353;

int n,m,s[N],c[N],a[N];

bool EDEDED;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
//	struct _timeb TT;
//	_ftime(&TT);
//	default_random_engine rng(TT.millitm);
//	mt19937 rnd(TT.millitm);
	
	cin >> n >> m;
	bool fleg = 1;
	int cnt = 0;
	for (int i = 1;i <= n;++i){
		char ch;
		cin >> ch;
		s[i] = (ch == '1');
		fleg &= s[i];
	}for (int i = 1;i <= n;++i){
		cin >> c[i];
		if (!c[i]) cnt++;
	}//if (fleg){
//		if (cnt < m) cout << 0,exit(0);
//		int fac = 1;
//		for (int i = 1;i <= n;++i) fac = 1ll * fac * i % mod;
//		cout << fac,exit(0);
//	}else{
		for (int i = 1;i <= n;++i) a[i] = i;
		int ans = 0;
		do{
			int tmp = 0,eit = 0;
			for (int i = 1;i <= n;++i){
				if (s[i] && eit < c[a[i]]) tmp++;
				else eit++;
			}if (tmp >= m) ans++;
		}while (next_permutation(a + 1,a + n + 1));
		cout << ans;
//	}
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms\n";
//	cerr << "memory used: " << abs(&STSTST - &EDEDED) / 1024.0 / 1024.0 << " MB\n";
	return 0;
}
