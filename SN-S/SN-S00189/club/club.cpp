#include <bits/stdc++.h>
using namespace std;
long long a[1000020], b[1000020], c[1000020];
long long n, o[10], T;
long long ans;


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --){
		ans = 0;
		long long x = 0, y = 0, z = 0;
		scanf("%lld", &n);
		for (int i = 1; i <= n; i ++){
			scanf("%lld%lld%lld", &o[1], &o[2], &o[3]);
			ans += max(max(o[1], o[2]), o[3]);
			if (o[1] > o[2] && o[1] > o[3]){
				if (o[2] > o[3]){
					a[++x] = o[1] - o[2];
				}else{
					a[++x] = o[1] - o[3];
				}
			}else if (o[1] < o[2] && o[3] < o[2]){
				if (o[1] > o[3]){
					b[++y] = o[2] - o[1];
				}else{
					b[++y] = o[2] - o[3];
				}
			}else{
				if (o[1] > o[2]){
					c[++z] = o[3] - o[1];
				}else{
					c[++z] = o[3] - o[2];
				}
			}
		}
		if (x <= n / 2 && y <= n / 2 && z <= n / 2){
			printf("%lld\n", ans);
			continue;
		}
		sort(a + 1, a + 1 + x);
		sort(b + 1, b + 1 + y);
		sort(c + 1, c + 1 + z);
		
		if (x > n / 2){
			for (int i = 1; i <= x - n / 2; i ++){
				ans -= a[i];
			}
		}else if (y > n / 2){
			for (int i = 1; i <= y - n / 2; i ++){
				ans -= b[i];
			}
		}else if (z > n / 2){
			for (int i = 1; i <= z - n / 2; i ++){
				ans -= c[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
