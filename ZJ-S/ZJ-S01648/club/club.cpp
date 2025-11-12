#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int read(){
	int x; scanf("%lld", &x); return x;
}
struct node{
	int num, pos;
};
int k, n, ans, pos1, pos2, pos3;
node a1[N], a2[N], a3[N];
int t[4], t1[4];
bool cmp(node x, node y){
	return x.num > y.num;
}
void dfs(int a, int b, int c, int t, int res){
	if(a > n / 2 || b > n / 2 || c > n / 2) return;
	if(t == n + 1){
		//cout << a << ' ' << b << ' ' << c << " " << t << endl;
		ans = max(ans, res);
		return;
	}
	if(a < n / 2) dfs(a + 1, b, c, t + 1, res + a1[t].num);
	if(b < n / 2) dfs(a, b + 1, c, t + 1, res + a2[t].num);
	if(c < n / 2) dfs(a, b, c + 1, t + 1, res + a3[t].num);
}
void solve(){
	int res = 0, res1 = 0;
	n = read();
	for(int i = 1; i <= n; i++){
		a1[i].num = read(); a2[i].num = read(); a3[i].num = read();
		if(a2[i].num == 0) res++;
		if(a3[i].num == 0) res1++;
		a1[i].pos = a2[i].pos = a3[i].pos = i;
	}
	if(n <= 10){
		dfs(0, 0, 0, 1, 0);
		printf("%lld\n", ans);
		ans = 0;
		return;
	} 
	if(res == n && res1 == n){
		sort(a1 + 1, a1 + 1 + n, cmp);
		for(int i = 1; i <= n / 2; i++)
			res += a1[i].num;
		printf("%lld\n", res);
		return;
	}
	for(int i = 1; i <= n; i++){
		int maxn = max(a1[i].num, max(a2[i].num, a3[i].num));
		if(a1[i].num == maxn) t[1]++, t1[1] += a1[i].num;
		if(a2[i].num == maxn) t[2]++, t1[2] += a2[i].num;
		if(a3[i].num == maxn) t[3]++, t1[3] += a3[i].num;
	}
	if(t[1] <= n / 2) res += t1[1];
	else{
		sort(a1 + 1, a1 + 1 + n, cmp);
		for(int i = 1; i <= n / 2; i++)
			res += a1[i].num;
		for(int i = n / 2 + 1; i <= t[1]; i++)
			res += max(a2[a1[i].pos].num, a3[a1[i].pos].num);
	}
	if(t[2] <= n / 2) res += t1[2];
	else{
		sort(a2 + 1, a2 + 1 + n, cmp);
		for(int i = 1; i <= n / 2; i++)
			res += a2[i].num;
		for(int i = n / 2 + 1; i <= t[2]; i++)
			res += max(a1[a2[i].pos].num, a3[a2[i].pos].num);
	}
	if(t[3] <= n / 2) res += t1[3];
	else{
		sort(a3 + 1, a3 + 1 + n, cmp);
		for(int i = 1; i <= n / 2; i++)
			res += a3[i].num;
		for(int i = n / 2 + 1; i <= t[3]; i++)
			res += max(a1[a3[i].pos].num, a2[a3[i].pos].num);
	}
	printf("%lld\n", res);
	//ans = 0;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	k = read();
	while(k--){
		solve();
	}
	return 0;
}
