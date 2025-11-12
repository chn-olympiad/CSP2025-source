#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 1e5 + 5, mod = 998244353;
int T, n, a[N][5], b[5], k, daan; 

template< typename T, typename ... L > inline void read(T &x){
	bool f = true;
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template< typename T, typename ... L > inline void read(T &a, L && ... b){
	read(a);
	read(b ...);
}
int ksm(int a, int b, int p){
	int ans = 1;
	while (b){
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
void solve(){
	read(n);
	daan = k = b[1] = b[2] = b[3] = 0;
	for (int i = 1; i <= n; i++){
		read(a[i][1], a[i][2], a[i][3]);
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) b[1]++;
		else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) b[2]++;
		else b[3]++;
		daan += max(a[i][1], max(a[i][2], a[i][3]));
	}
	if (b[1] > n / 2) k = 1;
	if (b[2] > n / 2) k = 2;
	if (b[3] > n / 2) k = 3;
	if (!k){
		printf("%lld\n", daan);
		return ;
	}
	priority_queue< int > q;
	for (int i = 1; i <= n; i++){
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && k == 1) q.push(-a[i][1] + max(a[i][2], a[i][3]));
		if (a[i][2] > a[i][1] && a[i][2] >= a[i][3] && k == 2) q.push(-a[i][2] + max(a[i][1], a[i][3]));
		if (a[i][3] > a[i][1] && a[i][3] > a[i][2] && k == 3) q.push(-a[i][3] + max(a[i][1], a[i][2]));
	}
	while (b[k] > n / 2){
		b[k]--;
		daan += q.top();
		q.pop();
	}
	printf("%lld\n", daan);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	read(T);
	while (T--) solve();
	return 0;
}
//freopen("a.in", "w", stdin);
//freopen("a.in", "r", stdout);
//freopen("a.out", "w", stdin);
//freopen("a.out", "r", stdout);

