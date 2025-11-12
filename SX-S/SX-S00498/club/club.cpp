#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100005][5];
int m1, m2,m3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			
			cin >> a[1][1] >> a[1][2] >> a[1][3];
			m1 = max(a[1][1], max(a[1][2], a[1][3]) );
			cin >> a[1][1] >> a[2][2] >> a[2][3];
			m2 = max(a[2][1], max(a[2][2], a[2][3]) );
			cout<<m1+m2;
			return 0;
		}
		if (n == 4) {
			
			cin >> a[1][1] >> a[1][2] >> a[1][3];
			m1 = max(a[1][1], max(a[1][2], a[1][3]) );
			cin >> a[1][1] >> a[2][2] >> a[2][3];
			m2 = max(a[2][1], max(a[2][2], a[2][3]) );
			m3=m3+m1+m2;
			cin >> a[1][1] >> a[1][2] >> a[1][3];
			m1 = max(a[1][1], max(a[1][2], a[1][3]) );
			cin >> a[1][1] >> a[2][2] >> a[2][3];
			m2 = max(a[2][1], max(a[2][2], a[2][3]) );
			m3=m3+m1+m2;
			cout<<m3;
			return 0;
		}

	}
	return 0;
}
