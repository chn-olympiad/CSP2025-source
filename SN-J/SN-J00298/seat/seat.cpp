#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
bool cmp(int x,int y)
{
	return x > y;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int r;
	cin >> r;
	a[1] = r;
	for(int i = 2;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	int x;
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == r)
		{
			x = i - 1;
			break;
		}
	}
    int c =x / n + 1;
    if(c % 2 == 1)
    {
    	cout << c << ' '<<x % n + 1;
	}
	else
	{
		cout << c << ' '<<n -x % n;
	}
	return 0;
}
