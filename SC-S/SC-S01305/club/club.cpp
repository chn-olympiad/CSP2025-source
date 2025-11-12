#include<bits/stdc++.h>
using namespace std;
struct A{
	int a1, a2, a3, fx, fid, sx, sid, tx, tid;
}a[100010];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		int c[5] = {0, 0, 0, 0};
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;a[i].fx = max({a[i].a1, a[i].a2, a[i].a3});
			if(a[i].a1 == a[i].fx) a[i].fid = 1;
			else if(a[i].a2 == a[i].fx) a[i].fid = 2;
			else a[i].fid = 3;
			if(a[i].fid == 1){
				a[i].sx = max(a[i].a2, a[i].a3);
				if(a[i].sx == a[i].a2) a[i].sid = 2, a[i].tid = 3;
				else a[i].sid = 3, a[i].tid = 2;
			}else if(a[i].fid == 2){
				a[i].sx = max(a[i].a1, a[i].a3);
				if(a[i].sx == a[i].a1) a[i].sid = 1, a[i].tid = 3;
				else a[i].sid = 3, a[i].tid = 1;
			}else{
				a[i].sx = max(a[i].a1, a[i].a2);
				if(a[i].sx == a[i].a1) a[i].sid = 1, a[i].tid = 2;
				else a[i].sid = 2, a[i].tid = 1;
			}
		}
		sort(a + 1, a + n + 1, [](A x, A y){return x.fx > y.fx;});
		for(int i = 1; i <= n; i++){
			if(c[a[i].fid] + 1 <= n / 2){
				ans += a[i].fx;
				c[a[i].fid]++;
			}else if(c[a[i].sid] + 1 <= n / 2){
				ans += a[i].sx;
				c[a[i].sid]++;
			}else{
				ans += a[i].tx;
				c[a[i].tid]++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}