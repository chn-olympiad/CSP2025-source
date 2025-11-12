#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5 + 5;
int n;
struct node{
	LL a, b, c;
}p[N];
vector<int> v[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < 3; i++) v[i].clear();
		for(int i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", &p[i].a, &p[i].b, &p[i].c);
			LL maxn = max(max(p[i].a, p[i].b), p[i].c);
			if(maxn == p[i].a) {
				v[0].push_back(i);
			}else if(maxn == p[i].b) {
				v[1].push_back(i);
			}else if(maxn == p[i].c) {
				v[2].push_back(i);
			}
		}
		LL ans = 0, tmp[N];
		for(int i = 1; i <= n; i++) {
			LL maxn = max(max(p[i].a, p[i].b), p[i].c);
			ans += maxn;
		}
		if(v[0].size() > n / 2) {
			for(int i = 0; i < v[0].size(); i++) {
				int id = v[0][i];
				tmp[i + 1] = p[id].a - max(p[id].b, p[id].c);
			}
			sort(tmp + 1, tmp + 1 + v[0].size());
			for(int i = 1; i <= v[0].size() - (n / 2); i++) {
				ans -= tmp[i];
			}
			
		}else if(v[1].size() > n / 2) {
			for(int i = 0; i < v[1].size(); i++) {
				int id = v[1][i];
				tmp[i + 1] = p[id].b - max(p[id].a, p[id].c);
			}
			sort(tmp + 1, tmp + 1 + v[1].size());
			for(int i = 1; i <= v[1].size() - (n / 2); i++) {
				ans -= tmp[i];
			}
			
		}else if(v[2].size() > n / 2) {
			for(int i = 0; i < v[2].size(); i++) {
				int id = v[2][i];
				tmp[i + 1] = p[id].c - max(p[id].b, p[id].a);
			}
			sort(tmp + 1, tmp + 1 + v[2].size());
			for(int i = 1; i <= v[2].size() - (n / 2); i++) {
				ans -= tmp[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
