#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 0x7f7f7f7f;

struct node {
	int x,y,z;
} a[maxn];

int cntx,cnty,cntz;
int res;
int n;
int flag = 0;

void dfs(int step,int cen,int x,int y,int z) {

	if(step == n + 1) {
		if(cen == 147325)
			flag = 1;
		res = max(res,cen);
		return ;
	}

	if(x < n/2) {
		dfs(step + 1,cen + a[step].x,x + 1,y,z);
		if(flag == 1) {
			cout <<cen + a[step].z << " " << a[step].x << "\n";
			return;
		}
	}
	if(y < n/2) {
		dfs(step + 1,cen + a[step].y,x,y + 1,z);
		if(flag == 1) {
			cout << cen + a[step].y	<< " " << a[step].y << "\n";
			return;
		}
	}
	if(z < n/2) {
		dfs(step + 1,cen + a[step].z,x,y,z + 1);
		if(flag == 1) {
			cout << cen + a[step].z << " " << a[step].z << "\n";
			return;
		}
	}
}

void solve() {
	res = 0;

	cin >> n;

	cntx = cnty = cntz = 0;

	for (size_t i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}

	sort(a + 1, a + n + 1, [](node x,node y) {
		int maxx = max(max(x.y,x.z),x.x);
		int maxy = max(max(y.x,y.y),y.z);
		int nexx = 0,nexy = 0;

		if(maxx == x.x) {
			nexx = max(x.y,x.z);
		}
		if(maxx == x.y) {
			nexx = max(x.x,x.z);
		}
		if(maxx == x.z) {
			nexx = max(x.y,x.x);
		}

		if(maxy == y.x) {
			nexy = max(y.y,y.z);
		}
		if(maxy == y.y) {
			nexy = max(y.x,y.z);
		}
		if(maxy == y.z) {
			nexy = max(y.y,y.x);
		}

		return (maxx - nexx) > (maxy - nexy);
	});

	int cntx = 0,cnty = 0,cntz = 0;

	for(int i = 1; i <= n; i++) {
		int maxi = max(max(a[i].x,a[i].y),a[i].z);
		if(a[i].x == maxi) {
			if(cntx == n/2) {
				res += max(a[i].y,a[i].z);
			} else {
				res += a[i].x;
				cntx++;
			}
		}

		if(a[i].y == maxi) {
			if(cnty == n/2) {
				res += max(a[i].x,a[i].z);
			} else {
				res += a[i].y;
				cnty++;
			}
		}

		if(a[i].z == maxi) {
			if(cntz == n/2) {
				res += max(a[i].y,a[i].x);
			} else {
				res += a[i].z;
				cntz++;
			}
		}
	}

	cout << res << endl;

	return;
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}

	return 0;
}