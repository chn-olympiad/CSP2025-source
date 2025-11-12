#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long a[n*m + 5],q;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int w = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == w)
		{
			q = n * m - i + 1;
		}
	}
	long long yu = q % n,chu = q / n;
	if(chu % 2 == 1 && yu > 0)
	{
		cout << chu + 1 << " " << n + 1 - yu;
	}
	if(chu % 2 == 1 && yu == 0)
	{
		cout << chu << " " << n;
	}
	if(chu % 2 == 0 && yu == 0)
	{
		cout << chu << " " << 1;
	}
	if(chu % 2 == 0 && yu > 0)
	{
		cout << chu + 1 << " " << yu;
	}
	return 0;
} 
