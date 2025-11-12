#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;


int a[N], b[N], c[N];

priority_queue<pair<int, int> > q;


int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int mid = n / 2;
		for (int i = 1; i <= n; i++) 
			cin >> a[i] >> b[i] >> c[i];
		sort(a + 1, a + n + 1);
		int sum = 0;
		for (int i = mid + 1; i <= n; i++) sum += a[i];
		cout << sum << endl;
	}
	
	fclose(stdin);
	fcolse(stdout);
	return 0;
}