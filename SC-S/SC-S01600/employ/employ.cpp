#include<bits/stdc++.h>
#define F(i,l,r) for(int i(l); i <= (r); ++ i)
#define G(i,r,l) for(int i(r); i >= (l); -- i)
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
//#define int ll
using namespace std;
using ll = long long;
const int N = 2e6;
int c[N], p[N];
int n, m;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> (s + 1);
	F(i, 1, n){
		cin >> c[i];	
		p[i] = i;
	}
	int sum = 0;
	do{
		int cnt = 0;
		F(i, 1, n){
			int nw = p[i];
			if(i - cnt - 1 >= c[nw]){
				continue;
			}
			if(cnt + n - i + 1 < m) break;
			if(s[i] == '1') ++ cnt;
		}
		if(cnt >= m) ++ sum;
	}while(next_permutation(p + 1, p + n + 1));
	cout << sum << '\n';
	return fflush(0), 0;
}