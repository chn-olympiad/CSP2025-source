#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n*m],cnt[n*m];
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	cout << n << " " << m;
	return 0;
}
