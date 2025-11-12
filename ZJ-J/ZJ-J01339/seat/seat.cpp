#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x,a[1000];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	x = a[1];
	sort(a + 1,a + n * m + 1,greater <int>());
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			if (a[(i - 1) * n + j] == x)
			{
				if (i & 1) cout << i << ' ' << j << endl;
				else cout << i << ' ' << n - j + 1 << endl;
				return 0;
			}
	return 0;
} 
