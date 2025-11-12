#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5;

int a[N][5];
int n; 
struct Node{
    int dep;
    ll cost;
};
Node person[N];


int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
	while(T--) {
        ll ans = 0;
        cin >> n;
        priority_queue<int,vector<int>, greater<int>> dep1, dep2, dep3;
        for (int i=1;i<=n;i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (a[i][1] >= max(a[i][2], a[i][3])) {
                ans += a[i][1];
                person[i].dep = 1;
                person[i].cost = a[i][1] - max(a[i][2], a[i][3]);
                dep1.push(person[i].cost);
                // cnt1++;
            } else if (a[i][2] >= max(a[i][1], a[i][3])) {
                ans += a[i][2];
                person[i].dep = 2;
                person[i].cost = a[i][2] - max(a[i][1], a[i][3]);
                dep2.push(person[i].cost);
                // cnt2++;
            } else {
                ans += a[i][3];
                person[i].dep = 3;
                person[i].cost = a[i][3] - max(a[i][1], a[i][2]);
                dep3.push(person[i].cost);
                // cnt3++;
            }
            while (int(dep1.size())>n/2) {
                ans -= dep1.top();
                dep1.pop();
            }
            while (int(dep2.size())>n/2) {
                ans -= dep2.top();
                dep2.pop();
            }
            while (int(dep3.size())>n/2) {
                ans -= dep3.top();
                dep3.pop();
            }
        }
		cout << ans << endl;
	}
	
	
	return 0;
}
