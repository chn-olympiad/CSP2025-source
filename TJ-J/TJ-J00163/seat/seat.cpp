#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n*m];
	int b;
	int xiaor;
	for (int i = 0; i < n*m; i++)
	{
		cin >> b;
		if (i == 0)
		{
			xiaor = b;
		}
		a[i] = b;
	}
	sort(a, a+n*m+1);
	for (int i = 0; i < n*m; i++)
	{
		if (a[i] == xiaor)
		{
			int mingci = i+1;
			if (mingci < n)
			{
				cout << 1 << " " << mingci;
			}
			else
			{
				if (mingci % n == 0)
				{
					int mingci2 = mingci / n;
					cout << mingci2 << " ";
					if (mingci2 % 2 == 0)
					{
						cout << 1;
					}
					else
					{
						cout << n;
					}
				}
				else
				{
					int mingci2 = mingci / n + 1;
					int mingci3 = mingci % n;
					cout << mingci2 << " ";
					if (mingci2 % 2 == 0)
					{
						cout << n + 1 - mingci3;
					}
					else
					{
						cout << mingci3;
					}
				}	
			}
		}
	}
	return 0;
}
