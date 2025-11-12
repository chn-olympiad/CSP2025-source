#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define PII pair<int, int>
#define Kg putchar(' ')
#define Ed putchar('\n')
bool __begin__;
using namespace std;
const ll N = 1e5 + 10, inf = 1e9, INF = 1e18;
template<class T> inline void read(T &x){x = 0;int f = 1;char ch = getchar();for(; ch < '0' || ch > '9'; ch = getchar()){if(ch == '-'){f = -1;}}for(; ch >= '0' && ch <= '9'; ch = getchar()){x = (x << 3) + (x << 1) + (ch ^ 48);}x *= f;}
template<class T> inline void print(T x){if(x < 0){putchar('-'), print(-x);}else if(x < 10){putchar(x ^ 48);}else{print(x / 10), putchar((x % 10) ^ 48);}}
int T, n, a[N][4];
vector<int>vt[4];
int ans;
int su[4];
void ck(int s){
	sort(vt[s].begin(), vt[s].end());
	for(int i = 0; i < su[s] - n / 2; i++){
		ans -= vt[s][i];
	}
}
bool __end__;
signed main(){
//	printf("%dMB", (int)(&__begin__ - &__end__) >> 20);
//	freopen("club5.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(T);
while(T--){
	ans = 0;
	vt[1].clear(), vt[2].clear(), vt[3].clear();
	su[1] = su[2] = su[3] = 0;
	read(n);
	for(int i = 1; i <= n; i++){
		read(a[i][1]), read(a[i][2]), read(a[i][3]);
		if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) su[1]++, ans += a[i][1], vt[1].push_back(a[i][1] - max(a[i][2], a[i][3]));
		else if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) su[2]++, ans += a[i][2], vt[2].push_back(a[i][2] - max(a[i][1], a[i][3]));
		else if(a[i][3] > a[i][1] && a[i][3] > a[i][2]) su[3]++, ans += a[i][3], vt[3].push_back(a[i][3] - max(a[i][1], a[i][2]));
		else if(a[i][1] == a[i][2]) ans += a[i][1];
		else if(a[i][1] == a[i][3]) ans += a[i][1];
		else if(a[i][2] == a[i][3]) ans += a[i][2];
	}
//	print(ans), Ed;
	if(su[1] > n / 2) ck(1);
	if(su[2] > n / 2) ck(2);
	if(su[3] > n / 2) ck(3);
	print(ans), Ed;
}return 0;}
/*
1
2
10 9 8
4 0 0
*/
