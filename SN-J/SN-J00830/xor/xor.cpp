#include<bits/stdc++.h>
#define int long long
using namespace std;
int u[2000000];
bool vis[2000000];
struct st {
	int a,b;
} h[2000000];
int cmp(st a,st b) {
	if(a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin >> a >> b;
	for(int i = 1; i <= a; i ++) {
		cin >> u[i];
	}
	int ans = 0,anss = 0;
	for(int i =1; i <= a; i ++) {
		int t = 0;
		for(int j = i; j <= a; j ++) {
			t = t^u[j];
			if(t == b) {
				ans ++;
				h[ans].a = i;
				h[ans].b = j;
			}
		}
	}
	sort(h + 1,h + ans + 1,cmp);
	for(int i = 1; i <= ans; i ++) {
		bool r = 1;
		for(int j = h[i].a; j <= h[i].b; j ++) {
			if(vis[j] != 1) vis[j] = 1;
			else {
				r = 0;
				break;
			}
		}
		if(r == 1) anss ++;
	}
	cout << anss;
	return 0;
}
