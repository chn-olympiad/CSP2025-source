#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string a[N], b[N], aa[N], bb[N];
int ans[N];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> aa[i];
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> b[i] >> bb[i];
		if(b[i] == a[i] && aa[i] == bb[i]) ans[i] += 2;
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
