#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 7; int n;
struct node{
	ll x, y, z;
	int com;
}a[maxn];
bool cmp(node p, node q){
	return max(p.x, p.y) > max(q.x, q.y);
}

ll f(int x, ll y, int s1, int s2, int s3){
	if(x == n + 1) return y;
	ll t1 = INT_MIN, t2 = INT_MIN, t3 = INT_MIN;
	if(s1 < n / 2) t1 = f(x + 1, y + a[x].x, s1 + 1, s2, s3);
	if(s2 < n / 2) t2 = f(x + 1, y + a[x].y, s1, s2 + 1, s3);
	if(s3 < n / 2) t3 = f(x + 1, y + a[x].z, s1, s2, s3 + 1);
	return max(t1, max(t2, t3));
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; cin >> t;
	while(t--){
		int b1 = 0, b2 = 0, b3 = 0;
		ll s = 0, s1 = 0, s2 = 0, s3 = 0; cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x != 0) b1 = 1;
			if(a[i].y != 0) b2 = 1;
			if(a[i].z != 0) b3 = 1;
		}
		if(b2 == 0 && b3 == 0){
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n; ++i){
				s += a[i].x;
			}
			cout << s << endl;
			continue;
		}else if(b3 == 0){
			for(int i = 1; i <= n; ++i){
				ll m = min(a[i].x, a[i].y);
				s += m; a[i].x -= m; a[i].y -= m;
			}
			sort(a + 1, a + n + 1, cmp);
			for(int i = 1; i <= n; ++i){
				if(a[i].x){
					if(s1 < n / 2) s += a[i].x, s1++;
					else s += a[i].y, s2++;
				}else{
					if(s2 < n / 2) s += a[i].y, s2++;
					else s += a[i].x, s1++;
				}
			}
			cout << s << endl;
			continue;
		}
		cout << f(1, 0, 0, 0, 0) << endl;
	}
	
	return 0;
}
