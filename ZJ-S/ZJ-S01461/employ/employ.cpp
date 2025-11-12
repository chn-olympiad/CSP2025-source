#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>inline void read(T &x){
	x = 0; T w = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-')	w = -1; ch = getchar();}
	while (isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x *= w;
}
template<typename T>inline void write(T x){
	if (x < 0)	putchar('-'), x = ~(x - 1);
	if (x > 9)	write(x / 10);
	putchar(x % 10 ^ 48);
}

const ll mo = 998244353;

const ll N = 505;

int n, m, s[N], c[N];
char ch[N];
bool ck = true;

ll ans;
bool vis[N];
void dfs(int k, int t, int l){
	if (k > n && t >= m){
		++ans;
		return;
	}
	if (t + n - k + 1 < m)	return ;
	for (int i = 1; i <= n; ++i)
		if (!vis[i]){
			vis[i] = true;
			if (l >= c[i])	dfs(k + 1, t, l + 1);
			else{
				if (s[k] == 0)	dfs(k + 1, t, l + 1);
				else	dfs(k + 1, t + 1, l);
			}
			vis[i] = false;
		}
}

int tong[N], tp;
int jc[N];

int main(){
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
//	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

	read(n), read(m);
	scanf("%s", ch + 1);
	for (int i = 1; i <= n; ++i)	read(c[i]);
	for (int i = 1; i <= n; ++i){
		if (ch[i] == '0')	s[i] = 0, ck = false;
		else	s[i] = 1;
	}
	if (ck){
		ans = 1;
		for (int i = 1; i <= n; ++i)	ans = ans * i % mo;
		write(ans);
		return 0;
	}
	dfs(1, 0, 0);
	write(ans % mo);

	return 0;
}
