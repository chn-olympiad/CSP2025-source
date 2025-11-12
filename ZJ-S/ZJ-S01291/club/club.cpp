// ni hao \(·v·)/
// rp++
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010][4];
int mx[100010], A[100010];
bool B[100010][4];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		memset(B, 0, sizeof(B));
		int n;
		cin >> n;
		int mx_n = n / 2;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			mx[i] = max({a[i][1], a[i][2], a[i][3]});
		}
		int tot_a = 0, tot_b = 0, tot_c = 0;
		for(int i = 1; i <= n; i++) {
			if(mx[i] == a[i][1]) {
				tot_a++;
				A[i] = 1;
			} else if(mx[i] == a[i][2]) {
				tot_b++;
				A[i] = 2;
			} else {
				tot_c++;
				A[i] = 3;
			}
		}
		while(tot_a > mx_n || tot_b > mx_n || tot_c > mx_n) {
//			cout << tot_a << ' ' << tot_b << ' ' << tot_c << endl;
			if(tot_a > mx_n) {
				vector<pair<int, pair<int, int> > /*C_value, xuan, id*/ > v;
				for(int i = 1; i <= n; i++) {
					if(A[i] == 1) {
						if(B[i][2] && B[i][3]) {
							continue;
						}
						if(B[i][2]) {
							v.push_back(make_pair(a[i][1] - a[i][3], make_pair(3, i)));
						} else if(B[i][3]) {
							v.push_back(make_pair(a[i][1] - a[i][2], make_pair(2, i)));
						} else {
							if(a[i][2] >= a[i][3]) {
								v.push_back(make_pair(a[i][1] - a[i][2], make_pair(2, i)));
							} else v.push_back(make_pair(a[i][1] - a[i][3], make_pair(3, i)));
						}
					}
				}
				sort(v.begin(), v.end());
				int len = v.size();
				for(int i = 0; i < tot_a - mx_n; i++) {
					B[v[i].second.second][v[i].second.first] = true;
					A[i] = v[i].second.first;
					if(A[i] == 1) {
						tot_a++;
					} else if(A[i] == 2) {
						tot_b++;
					} else tot_c++;
				}
				tot_a = mx_n;
			} else if(tot_b > mx_n) {
				vector<pair<int, pair<int, int> > > v;
				for(int i = 1; i <= n; i++) {
					if(A[i] == 2) {
						if(B[i][1] && B[i][3]) {
							continue;
						}
						if(B[i][1]) {
							v.push_back(make_pair(a[i][2] - a[i][3], make_pair(3, i)));
						} else if(B[i][3]) {
							v.push_back(make_pair(a[i][2] - a[i][1], make_pair(1, i)));
						} else {
							if(a[i][1] >= a[i][3]) {
								v.push_back(make_pair(a[i][2] - a[i][1], make_pair(1, i)));
							} else v.push_back(make_pair(a[i][2] - a[i][3], make_pair(3, i)));
						}
					}
				}
				sort(v.begin(), v.end());
				int len = v.size();
				for(int i = 0; i < tot_b - mx_n; i++) {
					A[i] = v[i].second.first;
					B[v[i].second.second][A[i]] = true;
					if(A[i] == 1) {
						tot_a++;
					} else if(A[i] == 2) {
						tot_b++;
					} else tot_c++;
				}
				tot_b = mx_n;
			} else {
				vector<pair<int, pair<int, int> > > v;
				for(int i = 1; i <= n; i++) {
					if(A[i] == 3) {
						if(B[i][1] && B[i][2]) {
							continue;
						}
						if(B[i][1]) {
							v.push_back(make_pair(a[i][3] - a[i][2], make_pair(2, i)));
						} else if(B[i][2]) {
							v.push_back(make_pair(a[i][3] - a[i][1], make_pair(1, i)));
						} else {
							if(a[i][1] >= a[i][2]) {
								v.push_back(make_pair(a[i][3] - a[i][1], make_pair(1, i)));
							} else v.push_back(make_pair(a[i][3] - a[i][2], make_pair(2, i)));
						}
					}
				}
				sort(v.begin(), v.end());
				int len = v.size();
				for(int i = 0; i < tot_c - mx_n; i++) {
					B[v[i].second.second][v[i].second.first] = true;
					A[i] = v[i].second.first;
					if(A[i] == 1) {
						tot_a++;
					} else if(A[i] == 2) {
						tot_b++;
					} else tot_c++;
				}
				tot_c = mx_n;
			}
		}
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			sum += a[i][A[i]];
		}
		cout << sum << endl;
	}
	return 0;
}