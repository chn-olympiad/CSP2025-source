#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		for(int j = 1; j <=	m; j ++ ) {
			if(a[i] < a[i +1]) {
				int q = a[i];
				a[i] = a[i + 1];
				a[i + 1] = q;
			}
			if(a[1] = a[i]){
				c = n;
				r = m;
			}
		}
	}
    cout << c << r;
	return 0;
}
