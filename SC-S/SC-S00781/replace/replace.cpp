#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	vector<pair<string, string> > S(n + 1);
	_loopc(i, 1, n) cin >> S[i].first >> S[i].second;
	while(q --){
		string t1, t2; cin >> t1 >> t2;
		cout << n << '\n';
	}
	return 0;
}