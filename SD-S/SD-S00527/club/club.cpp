#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long t, n, mx;
struct node{
	long long x, y, z;
}a[N];
bool cmp (node f, node g){
	if (f.x != g.x) return f.x < g.x;
	if (f.y != g.y) return f.y < g.y;
	return f.z < g.z;
}
void dfs (int k, int xx, int yy, int zz, long long my){
	if (k == n+1){
		mx = max(mx,my);
		return;
	}
	for (int i = 1; i <= 3; i++){
		if (xx < n/2){
			dfs(k+1,xx+1,yy,zz,my+a[k].x);
		}
		if (yy < n/2){
			dfs(k+1,xx,yy+1,zz,my+a[k].y);
		}
		if (zz < n/2){
			dfs(k+1,xx,yy,zz+1,my+a[k].z);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		mx = -1;
		bool f1 = 1;
		for (int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0 || a[i].z != 0) f1 = 0;
		}
		if (f1 == 1){
			sort(a+1,a+n+1, cmp);
			int cnt = 0, sum = 0;
			for (int i = n; i >= 1; i--){
				if (cnt < n/2){
					cnt++;
					sum += a[i].x;
				}
			}
			cout << sum << "\n";
		}else{
			dfs(1,0,0,0,0);
			cout << mx << "\n";
		}
	}
	return 0;
}
