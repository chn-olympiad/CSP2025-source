#include <bits/stdc++.h>
using namespace std;
long long n,m,r,l = 1,h = 1;
bool g = true;
priority_queue<long long> t;
int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		int b;
		cin >> b;
		if (i == 1)
		{
			r = b;
		}
		t.push(b);
	}
	while (!t.empty())
	{
		if (g == true)
		{
			g = false;
			for (int i = 1; i <= n; i++)
			{
				int q = t.top();
				if (q == r)
				{
					cout << h << " " << i;
					return 0;
				}
				t.pop();
			}
		}
		else if (g == false)
		{
			for (int i = n; i >= 1; i--)
			{
				int q = t.top();
				if (q == r)
				{
					cout << h << " " << i;
					return 0;
				}
				t.pop();
			}
			g = true;
		}
		h++;
	}
	return 0;
}
