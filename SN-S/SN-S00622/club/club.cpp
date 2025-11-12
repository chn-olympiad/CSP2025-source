#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n, a[100005], b[100005], c[100005], ans;
		cin >> n;
		for(int i = 1; i<= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];	
		}
		sort (a + 1, a + 1 + n);
		sort (b + 1, b + 1 + n);
		for(int i = 1; i<= n; i++)
		{
			if(a[i] < b[i]) ans += b[i];
			else ans += a[i];
		}
		cout << ans << ' ';
	}
	
	return 0;
}


