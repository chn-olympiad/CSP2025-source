#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define PII pair<int, int>
#define Kg putchar(' ')
#define Ed putchar('\n')
bool __begin__;
using namespace std;
const ll N = 5e6 + 10, inf = 1e9, INF = 1e18, p = 998244353;
template<class T> inline void read(T &x){x = 0;int f = 1;char ch = getchar();for(; ch < '0' || ch > '9'; ch = getchar()){if(ch == '-'){f = -1;}}for(; ch >= '0' && ch <= '9'; ch = getchar()){x = (x << 3) + (x << 1) + (ch ^ 48);}x *= f;}
template<class T> inline void print(T x){if(x < 0){putchar('-'), print(-x);}else if(x < 10){putchar(x ^ 48);}else{print(x / 10), putchar((x % 10) ^ 48);}}
int T, q;
int n;
int h1, h2, base = 31;
map<PII, int>mp;
char s[N], t[N];
bool __end__;
signed main(){
//	printf("%dMB", (int)(&__begin__ - &__end__) >> 20);
//	freopen("replace3.in", "r", stdin);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(T), read(q);
	while(T--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1);
		h1 = h2 = 0;
		for(int i = 1; i <= n; i++){
			h1 = ((ll)h1 * (ll)base % (ll)p + (ll)(s[i] - 'a' + 1)) % (ll)p;
			h2 = ((ll)h2 * (ll)base % (ll)p + (ll)(t[i] - 'a' + 1)) % (ll)p;
		}mp[{h1, h2}]++;
	}
	while(q--){
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1);
		int L = 1, R = n;
		while(s[L] == t[L]) L++;
		while(s[R] == t[R]) R--;
		int ans = 0;
		for(int i = 1; i <= L; i++){
			h1 = h2 = 0;
			for(int j = i; j <= n; j++){
				h1 = ((ll)h1 * (ll)base % (ll)p + (ll)(s[j] - 'a' + 1)) % (ll)p;
				h2 = ((ll)h2 * (ll)base % (ll)p + (ll)(t[j] - 'a' + 1)) % (ll)p;
				if(j < R) continue;
				ans += mp[{h1, h2}];
			}
		}
		print(ans), Ed;
	}
	return 0;
}

