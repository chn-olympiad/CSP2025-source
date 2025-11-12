#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node {
	int a,b,c;
}f[N];
bool cmpa(node x, node y) {
	return x.a > y.a;
}
bool cmpb(node x, node y) {
	return x.b > y.b;
}
bool cmpc(node x, node y) {
	return x.c > y.c;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> f[i].a >> f[i].b >> f[i].c;
		int maxx = 0, max1 = 0, max2 = 0, max3 = 0;
		sort(f + 1, f + n + 1, cmpa);
		for(int i = 1; i <= n / 2; i++) max1 += f[i].a;
		sort(f + 1, f + n + 1, cmpb);
		for(int i = 1; i <= n / 2; i++) max2 += f[i].b;
		sort(f + 1, f + n + 1, cmpc);
		for(int i = 1; i <= n / 2; i++) max3 += f[i].c;
		int ans1 = max1, ans2 = max2, ans3 = max3;
		sort(f + 1, f + n + 1, cmpa);
		for(int i = n / 2 + 1; i <= n; i++) {
			if(f[i].b < f[i].c) ans1 += f[i].c;
			else ans1 += f[i].b;
		}
		sort(f + 1, f + n + 1, cmpb);
		for(int i = n / 2 + 1; i <= n; i++) {
			if(f[i].a < f[i].c) ans2 += f[i].c;
			else ans2 += f[i].a;
		}
		sort(f + 1, f + n + 1, cmpc);
		for(int i = n / 2 + 1; i <= n; i++) {
			if(f[i].a < f[i].b) ans3 += f[i].b;
			else ans3 += f[i].a;
		}
		cout << max(ans1, max(ans2, ans3)) << endl;
	}
	return 0;
} 