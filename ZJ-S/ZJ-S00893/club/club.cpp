#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T, n;
struct group{
	int id, be, x[4];
	bool operator < (const group &y) const{
		return y.x[be] < x[be];
	}
} a[N];
signed main(){
    freopen("club.in","r",stdin); freopen("club.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--){
    	cin >> n; priority_queue<group> q[4];
    	int ans = 0;
    	for (int i = 1; i <= n; i++)
    		cin >> a[i].x[1] >> a[i].x[2] >> a[i].x[3], 
			a[i].id = i, a[i].be = 0, a[i].x[0] = -1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++)
				if (q[j].size() < n/2 && a[i].x[j] > a[i].x[a[i].be]) a[i].be = j; 
			ans += a[i].x[a[i].be], q[a[i].be].push(a[i]);
		}
//		for (int i = 1; i <= n; i++) cout << a[i].be << " "; cout << endl; 
//		cout << ans << endl;
		for (int i = 1; i <= 3; i++)
			for (int j = i+1; j <= 3; j++){
				if (q[i].empty() || q[j].empty()) continue;
				int u = q[i].top().id, v = q[j].top().id;
//				cout << i << " " << j << endl;
				while (a[u].x[j]+a[v].x[i] > a[u].x[i]+a[v].x[j]){
//					cout << "  " << u << " " << v << endl;
					q[i].pop(), q[j].pop();
					ans += a[u].x[j]+a[v].x[i]-a[u].x[i]-a[v].x[j];
					a[v].be = i, a[u].be = j;
					q[i].push(a[v]), q[j].push(a[u]);
					u = q[i].top().id, v = q[j].top().id;
				}
			}
		cout << ans << "\n";
	}
    return 0;
}

