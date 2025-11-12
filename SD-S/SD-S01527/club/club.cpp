#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 10;

bool m1;

long long n, a[N][4];

void read() {
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
}

void init() {

}

priority_queue<long long,vector<long long>,greater<long long> > q[4];

void compute() {
	long long ans = 0;
	for(long long i = 1; i <= n; i++) {
		for(long long j = 1; j <= 3; j++) {
			if(a[i][j] == max(a[i][1],max(a[i][2],a[i][3]))) {
				ans += a[i][j];
				long long w = INT_MAX;
				for(long long k = 1; k <= 3; k++) if(j != k) w = min(w,a[i][j]-a[i][k]);
				q[j].push(w);
				break;
			}
		}
	}
	for(long long i = 1; i <= 3; i++) {
		while((long long)q[i].size() > n / 2) {
			ans -= q[i].top();
			q[i].pop();
		}
	}
	cout << ans << '\n';
}

void clear() {
	for(long long i = 1; i <= 3; i++) while(q[i].size()) q[i].pop();
}

void run() {
	read();
	init();
	compute();
	clear();
}

bool m2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--) run();
	return 0;
}

