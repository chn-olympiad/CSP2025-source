#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], seatx, seaty, b[105], sum;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
	seatx = 1, seaty = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
	    cin >> a[i];	
	}
	int r = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m; i >= 1; i--)
	{
		b[i] = a[i];
	}
	int pos;
	for (int i = 1; i <= n * m; i++)
	{
		if (b[i] == r)
		{
			pos = i;
			break;
		}
	}
	int step = 1;
	for (int i = 1; i <= pos; i++)
	{
	    if (seaty % 2)
		{
		    for (int i = 1; i <= n - 1; i++)
			{
			    if (step >= pos)
			    {
			    	cout << seaty << " " << seatx;
			    	return 0;
				}
				seatx++;
				step++;		
			}	
		}
		seaty++;
		step++;
		if (seaty % 2 == 0)
		{
			for (int i = 1; i <= n - 1; i++)
			{
				if (step >= pos)
				{
					cout << seaty << " " << seatx;
					return 0;
				}
				seatx--;
				step++;	
			}	
		}	
	}
	cout << seaty << " " << seatx;
	return 0;
}
