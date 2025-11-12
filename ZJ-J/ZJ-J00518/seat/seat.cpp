#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[10005],p;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == k)
		{
			p = i;
		}
	}
	int x = p % n,y = ceil(1.0 * p / n);  
	//cout << x << " " << y << "\n";
	if (y % 2 == 1)
	{
		cout << y << " " << (x == 0 ? n : x);
	}
	else
	{
		cout << y << " " << (x == 0 ? 1 : (n - x + 1));
	}
	return 0;
}

