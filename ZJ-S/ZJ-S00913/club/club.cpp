#include <bits/stdc++.h>
#define LL long long int

using namespace std;

const LL N = 1e5 + 5;
struct Node1 {
	LL a[5];
	LL flag;
}node[N];
vector<LL> v[5];
LL f[5];
LL c[5];

void q(LL x,LL y,LL z,LL n) {
	LL fl = 0;
	LL maxn = -1e9,maxid = 0;
	for(LL i = 1;i <= n;i++) {
		if(node[i].flag == x) {
			LL o = max(node[i].a[y],node[i].a[z]);
			if(node[i].a[y] > node[i].a[z]) {
				fl = y;
			}else {
				fl = z;
			}
			if(f[y] == 1) {
				o = node[i].a[z];
				fl = z;
			}
			if(f[z] == 1) {
				o = node[i].a[y];
				fl = y;
			}
			if(maxn < o) {
				maxn = o;
				maxid = i;
			}
		}
	}
	for(LL i = 0;i < v[x].size();i++) {
		if(v[x].size() - c[x] <= n / 2) {
			break;
		}
		if(node[maxid].a[x] == v[x][i]) {
			v[x][i] = -1;
			c[x]++;
			if(fl == y) {
				v[y].push_back(maxn);
			}
			if(fl == z) {
				v[z].push_back(maxn);
			}
		}
	}
}

int main(void) {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL T;
	cin >> T;
	while(T--) {
		LL n;
		cin >> n;
		for(LL i = 1;i <= n;i++) {
			cin >> node[i].a[1] >> node[i].a[2] >> node[i].a[3];
			LL maxn = max(max(node[i].a[1],node[i].a[2]),node[i].a[3]);
			if(maxn == node[i].a[1]) {
				node[i].flag = 1;
				v[1].push_back(node[i].a[1]);
			}else if(maxn == node[i].a[2]) {
				node[i].flag = 2;
				v[2].push_back(node[i].a[2]);
			}else if(maxn == node[i].a[3]) {
				node[i].flag = 3;
				v[3].push_back(node[i].a[3]);
			}
		}
		for(LL i = 1;i <= 3;i++) {
			if(v[i].size() - c[i] == n / 2) {
				f[i] = 1;
			}
		}
		if(v[1].size() - c[1] > n / 2) {
			q(1,2,3,n);
		}
		for(LL i = 1;i <= 3;i++) {
			if(v[i].size() - c[i] == n / 2) {
				f[i] = 1;
			}
		}
		if(v[2].size() - c[2] > n / 2) {
			q(2,1,3,n);
		}
		for(LL i = 1;i <= 3;i++) {
			if(v[i].size() - c[i] == n / 2) {
				f[i] = 1;
			}
		}
		if(v[3].size() - c[3] > n / 2) {
			q(3,1,2,n);
		}
		c[1] = c[2] = c[3] = f[1] = f[2] = f[3] = 0;
		LL ans = 0;
		for(LL i = 1;i <= 3;i++) {
			for(LL j = 0;j < v[i].size();j++) {
				if(v[i][j] != -1) {
					ans += v[i][j];
				}
			}
			v[i].clear();
		}
		cout << ans << endl;
	}
	return 0;
}

