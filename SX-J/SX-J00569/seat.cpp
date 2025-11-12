#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> a[i];
	sort (a, a + n *m);
	return 0;
}
