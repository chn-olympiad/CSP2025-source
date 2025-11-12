#include <bits/stdc++.h>
#include <map>
#define PB push_back
#define ll long long
#define ull unsigned long long
//#define int long long

using namespace std;

void rd(int &x){
	int flag = 1; x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= flag;
}

//const int mod = 998244353;
const ull base = 131;
const int N = 2e6;
char a1[N], a2[N];
ull Bs[N], Hs1[N], Hs2[N];

map <pair<ull, ull>, int> m;  

ull getH(int L, int R){
	return Hs1[R] - Hs1[L] * Bs[R - L + 1];
}

signed main(){

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	
	int n, q;
	rd(n), rd(q);
	
	for(int i = 1; i <= n; i ++){
		scanf("%s", a1), scanf("%s", a2); 
		int l = strlen(a1);
		ull hs1 = 0, hs2 = 0;
		for(int j = 0; j < l; j ++){
			hs1 = hs1 * base + (ull)a1[j];
			hs2 = hs2 * base + (ull)a2[j];
		}
		m[{hs1, hs2}] ++;
	}
	Bs[0] = 1;
	for(int i = 1; i <= N; i ++) Bs[i] = Bs[i - 1] * base;
	for(int i = 1; i <= q; i ++){
		scanf("%s", a1), scanf("%s", a2); 
		
		int l = strlen(a1);
		if(l >= 1e5){
			puts("0");
			continue;
		}
		for(int j = 1; j <= l; j ++){
			Hs1[j] = Hs1[j - 1] * base + (ull)a1[j - 1];
			Hs2[j] = Hs2[j - 1] * base + (ull)a2[j - 1];
		}
		int ans = 0;
		for(int L = 1; L <= l; L ++){
			if(L - 2 >= 0) if(a1[L - 2] != a2[L - 2]) break;
			for(int R = l; R >= L; R --){
				if(l != R && a1[R] != a2[R]) break;
				ull Hx1 = Hs1[R] - Hs1[L - 1] * Bs[R - L + 1];
				ull Hx2 = Hs2[R] - Hs2[L - 1] * Bs[R - L + 1];
				ans += m[{Hx1, Hx2}];
				if(m[{Hx1, Hx2}]){
					
				}
			}
		}
		cout << ans << '\n';
	}
		

	return 0;
}

