#include<bits/stdc++.h>
using namespace std;
int t, n, afa[200010], a[200010], b[200010], c[200010];
int cnt1, cnt2, cnt3, cnt4;
long long ans, ans1;
struct st{
	int a, b, c;
}p[200010];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cnt1 = cnt2 = cnt3 = ans = ans1 = 0;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			if(p[i].a >= p[i].b and p[i].a >= p[i].c) {
				a[++cnt1] = i;
			}
			else if(p[i].b >= p[i].a and p[i].b >= p[i].c) {
				b[++cnt2] = i;
			}			
			else {
				c[++cnt3] = i;
			}
		}
		for(int i = 1;i <= cnt1;i++) ans += p[a[i]].a;
		for(int i = 1;i <= cnt2;i++) ans += p[b[i]].b;
		for(int i = 1;i <= cnt3;i++) ans += p[c[i]].c;		
		cnt4 = 0;
		if(cnt1 > n / 2) {
			for(int i = 1;i <= cnt1;i++) {
				afa[++cnt4] = p[a[i]].a - max(p[a[i]].b, p[a[i]].c);
			}
		}
		sort(afa + 1, afa + cnt4 + 1);
		for(int i = 1;i <= cnt1 - n / 2;i++) {
			ans1 += afa[i];
		}
		cnt4 = 0;
		if(cnt2 > n / 2) {
			for(int i = 1;i <= cnt2;i++) {
				afa[++cnt4] = p[b[i]].b - max(p[b[i]].a, p[b[i]].c);
			}
		}
		sort(afa + 1, afa + cnt4 + 1);
		for(int i = 1;i <= cnt2 - n / 2;i++) {
			ans1 += afa[i];
		}
		cnt4 = 0;
		if(cnt3 > n / 2) {
			for(int i = 1;i <= cnt3;i++) {
				afa[++cnt4] = p[c[i]].c - max(p[c[i]].b, p[c[i]].a);
			}
		}
		sort(afa + 1, afa + cnt4 + 1);
		for(int i = 1;i <= cnt3 - n / 2;i++) {
			ans1 += afa[i];
		}				
		cout << ans - ans1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}