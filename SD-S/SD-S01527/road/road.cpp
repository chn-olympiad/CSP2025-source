#include <bits/stdc++.h>
using namespace std;

bool m1;

const long long N = 1e4 + 30;

long long n, m, k;

struct edge {
	long long u, v, w, s;
};

vector<edge> e;

long long c[11];

void read() {
	cin >> n >> m >> k;
	for(long long i = 1; i <= m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		e.push_back({u,v,w,0});
	}
	for(long long i = 1; i <= k; i++) {
		cin >> c[i];
		for(long long j = 1; j <= n; j++) {
			long long x;
			cin >> x;
			e.push_back({n+i,j,x,i});
		}
	}
}

long long f[N];

long long find(long long x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

long long vis[N];

void init() {
	for(long long i = 1; i <= n+k; i++) f[i] = i, vis[i] = 0;
}

long long K(long long S) {
	init();
	long long num = 0;
	long long ans = 0;
	for(edge i : e) {
		long long x = find(i.u);
		long long y = find(i.v);
		long long s = i.s;
		if(s==0 || ((S>>(s-1))&1)) {
			if(x != y) {
				ans += i.w;
				if(x > n || y > n) num--;
				f[max(x,y)] = min(x,y);
				num++;
			}
		}
		if(num == n - 1) return ans;
	}
	return -1;
}

long long get(long long x) {
	long long ans = 0;
	for(long long i = 1; i <= k; i++) {
		if((x>>(i-1))&1) ans += c[i];
	}
	return ans;
}

void compute() {
	long long ans = LLONG_MAX;
	sort(e.begin(),e.end(),[](edge x,edge y){
		return x.w < y.w;
	});
	for(long long i = 0; i < (1<<k); i++) {
		ans = min(ans,K(i)+get(i));
	}
	cout << ans;
}

void clear() {

}

void run() {
	read();
	compute();
	clear();
}

bool m2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	run();
	return 0;
}

