#include<bits/stdc++.h>
using namespace std;
long long n, m, b, ans;
long long a[1005];
long long x, y;
void swa()
{
	for (int i = 1; i <= n*m/2; i++)
	{
		swap(a[i], a[n*m+1-i]);
	}
}
int find(int x)
{
	for (int i = 1; i <= n*m; i++)
	{
		if(a[i] == x)
		{
			//cout << i << " " << a[i] << " " << x << endl;
			return i;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a+1, a+n*m+1);
	swa();
	ans = find(b);
	x = (ans-1)/m + 1;
	if (x%2 == 1)
	{
		y = ans - (x-1)*m;
	}else
	{
		y = m - (ans - (x-1)*m) + 1;
	}
	cout << x << " " << y << endl;
	return 0;
}
