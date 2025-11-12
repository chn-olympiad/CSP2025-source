#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
const int N = 1e5 + 2;
int T, n;
int a[N], b[N], c[N];
priority_queue<pair<int, int> > as, bs, cs;

int main() {
	cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
        	cin >> a[i] >> b[i] >> c[i];
        	int p = min(a[i], min(b[i], c[i]));
        	ans += p;
        	a[i] -= p, b[i] -= p, c[i] -= p;
        	if(a[i] >= b[i] && a[i] >= c[i]) as.push(make_pair(-min(a[i] - b[i], a[i] - c[i]), i));
        	else if(b[i] >= a[i] && b[i] >= c[i]) bs.push(make_pair(-min(b[i] - a[i], b[i] - c[i]), i));
        	else if(c[i] >= b[i] && c[i] >= a[i]) cs.push(make_pair(-min(c[i] - a[i], c[i] - b[i]), i));
		}
		int lmt = n >> 1;
		if(as.size() > lmt) {
			while(as.size() > lmt) {
				int p = as.top().second;
				as.pop();
				if(b[p] > 0) bs.push(make_pair(-b[p], p));
				else if(c[p] > 0) cs.push(make_pair(-c[p], p));
			}
		}else if(bs.size() > lmt) {
			while(bs.size() > lmt) {
				int p = bs.top().second;
				bs.pop();
				if(a[p] > 0) as.push(make_pair(-a[p], p));
				else if(c[p] > 0) cs.push(make_pair(-c[p], p));
			}
		}else if(cs.size() > lmt) {
			while(cs.size() > lmt) {
				int p = cs.top().second;
				cs.pop();
				if(a[p] > 0) as.push(make_pair(-a[p], p));
				else if(b[p] > 0) bs.push(make_pair(-b[p], p));
			}
		}
		while(!as.empty()) {
			ans += a[as.top().second];
			as.pop();
		}
		while(!bs.empty()) {
			ans += b[bs.top().second];
			bs.pop();
		}
		while(!cs.empty()) {
			ans += c[cs.top().second];
			cs.pop();
		}
		cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
