#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;

signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m ;
	set<ll,greater<int> > st;
	int R;
	cin >> R;
	st.insert(R);
	for (size_t i = 2; i <= n * m; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	int x = 1,y = 1;
	for(auto it : st) {
		if(it == R) {
			cout << x << " " << y << endl;
			exit(0);
		}
		if(x & 1) {
			y++;
		} else {
			y--;
		}

		if(y > n) {
			x ++;
			y = n;
		}
		if(y < 1) {
			x ++;
			y = 1;
		}
	}

	return 0;
}
