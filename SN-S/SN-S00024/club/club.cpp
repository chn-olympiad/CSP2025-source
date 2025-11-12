#include <bits/stdc++.h>
using namespace std;

long long t, n, sum;
long long a[100010], b[100010], c[100010];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	cin >> t;
	for(int i = 0; i < t; i++) {
		sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
	
		sort(a, a+n);
	
		for(int i = 1; i <= n/2; i++) sum += a[i];
		cout << sum << endl;
	} 
	
	return 0;
}
