#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int t, a[N][4], b[N];
struct str{
	int x; int y;
}c[N];
bool cmp (int x, int y){
	return x > y; 
}
bool cmpc (str p, str q){
	return p.x > q.x;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int z = 1; z <= t; z++){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n; bool f[4] = {0, 1, 1, 1}; long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
				if (a[i][j] != 0) f[j] = 0;
			}
		}
		if (n == 2){
			cout << max (a[1][1] + a[2][2], max (a[1][1] + a[2][3], max (a[1][2] + a[2][1], max (a[1][2] + a[2][3], max(a[1][3] + a[2][1], a[1][3] + a[2][2])))));
			cout << endl; continue;
		}
		else if (f[2] == 1 && f[3] == 1){
			for (int i = 1; i <= n; i++) b[i] = a[i][1];
			sort (b + 1, b + n + 1, cmp);
			for (int i = 1; i <= n/2; i++) ans += b[i];
			cout << ans << endl; continue;
		}
		else if (f[1] == 1 && f[3] == 1){
			for (int i = 1; i <= n; i++) b[i] = a[i][2];
			sort (b + 1, b + n + 1, cmp);
			for (int i = 1; i <= n/2; i++) ans += b[i];
			cout << ans << endl; continue;
		}
		else if (f[1] == 1 && f[2] == 1){
			for (int i = 1; i <= n; i++) b[i] = a[i][3];
			sort (b + 1, b + n + 1, cmp);
			for (int i = 1; i <= n/2; i++) ans += b[i];
			cout << ans << endl; continue;
		}
		else if (f[3] == 1){
			for (int i = 1; i <= n; i++){
				c[i].x = a[i][1]; c[i].y = a[i][2];
			}
			sort (c + 1, c + n + 1, cmpc);
			for (int i = 1; i <= n/2; i++) ans += c[i].x;
			for (int i = n/2 + 1; i <= n; i++) ans += c[i].y;
			for (int i = n/2; i >= 1; i--){
				int j = n/2 + 1;
				if (c[i].y + c[j].x > c[i].x + c[j].y){
					ans -= (c[i].x + c[j].y); ans += (c[i].y + c[j].x); j++;
				}
			}
			cout << ans << endl; continue;
		}
		else if (f[2] == 1){
			for (int i = 1; i <= n; i++){
				c[i].x = a[i][1]; c[i].y = a[i][3];
			}
			sort (c + 1, c + n + 1, cmpc);
			for (int i = 1; i <= n/2; i++) ans += c[i].x;
			for (int i = n/2 + 1; i <= n; i++) ans += c[i].y;
			for (int i = n/2; i >= 1; i--){
				int j = n/2 + 1;
				if (c[i].y + c[j].x > c[i].x + c[j].y){
					ans -= (c[i].x + c[j].y); ans += (c[i].y + c[j].x); j++;
				}
			}
			cout << ans << endl; continue;
		}
		else if (f[1] == 1){
			for (int i = 1; i <= n; i++){
				c[i].x = a[i][2]; c[i].y = a[i][3];
			}
			sort (c + 1, c + n + 1, cmpc);
			for (int i = 1; i <= n/2; i++) ans += c[i].x;
			for (int i = n/2 + 1; i <= n; i++) ans += c[i].y;
			for (int i = n/2; i >= 1; i--){
				int j = n/2 + 1;
				if (c[i].y + c[j].x > c[i].x + c[j].y){
					ans -= (c[i].x + c[j].y); ans += (c[i].y + c[j].x); j++;
				}
			}
			cout << ans << endl; continue;
		}
		else {
			for (int i = 1; i <= n; i++) ans += max (a[i][1], max (a[i][2], a[i][3]));
			cout << ans << endl; continue;
		}
	}
	return 0;
} 
