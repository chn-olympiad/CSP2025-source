#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int u = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == u)
		{
			cout << (i - 1) / n + 1 << ' ' << (((i - 1) / n + 1) % 2 == 0 ? n - (i - 1) % n : (i - 1) % n + 1);
			return 0;
		}
	}
	return 0;
}
