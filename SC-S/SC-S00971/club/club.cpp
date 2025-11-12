#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T> inline void read(T &x){
	x = 0;
	int f = 1;
	char c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template<typename T> inline void print(T x){
	if(x < 0) x = -x, putchar('-');
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
int a[100005], b[100005], c[100005];
int dp[100005][3];
int n;
bool check(int *x){
	int sum = 0;
	for(int i = 1;i <= n;i ++){
		sum += x[i];
	}
	if(sum == 0) return 1;
	return 0;
}
struct Node{
	int a, b;
}w[100005];
bool cmp(Node x, Node y){
	if(x.a == y.a) return x.b > y.b;
	return x.a > y.a;
}
bool cmp2(Node x, Node y){
	if(x.b == y.b) return x.a > y.a;
	return x.b > y.b;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;read(T);
	while(T --){
		read(n);
		for(int i = 1;i <= n;i ++){
			read(a[i]);
			read(b[i]);
			read(c[i]);
		}
		if(n == 2){
			int ans = 0;
			ans = max({a[1] + b[2], a[1] + b[3], a[1] + c[2], a[1] + c[3], b[1] + a[2], b[1] + a[3],b[1] + c[2], b[1] + c[3], c[1] + a[2], c[1] + a[3], c[1] + b[2], c[1] + b[3]
					,a[2] + b[3], a[2] + c[3], b[2] + a[3], b[2] + c[3], c[2] + a[3], c[2] + b[3]});
			cout << ans << "\n";
			continue;
		}
		if(check(b) && check(c)){
			sort(a + 1, a + n + 1, greater<int>());
			int ans = 0;
			for(int i = 1;i <= n / 2;i ++){
				ans += a[i];
			}
			cout << ans << '\n';
			continue;
		} else if(check(c) && !check(a) && !check(b)){
			for(int i = 1;i <= n;i ++){
				w[i].a = a[i];
				w[i].b = b[i];
			}
			sort(w + 1, w + n + 1, cmp);
			int ans = 0;
			for(int i = 1;i <= n / 2;i ++){
				ans += w[i].a;
			}
			for(int i = n / 2 + 1;i <= n;i ++){
				ans += w[i].b;
			}
			
			int ans2 = 0;
			sort(w + 1, w + n + 1, cmp);
			for(int i = 1;i <= n / 2;i ++){
				ans2 += w[i].a;
			}
			for(int i = n / 2 + 1;i <= n;i ++){
				ans2 += w[i].b;
			}
			cout << max(ans, ans2) << "\n";
		} else{
			for(int i = 1;i <= n;i ++){
				int tmp = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
				dp[i][0] = tmp + a[i]; 
				dp[i][1] = tmp + b[i];
				dp[i][2] = tmp + c[i];
			}
			cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
		}
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/