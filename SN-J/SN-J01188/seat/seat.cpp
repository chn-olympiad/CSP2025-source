#include <bits/stdc++.h>
using namespace std;
int m,n,Ma[105],rma,cnt;
bool cmp (int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> Ma[i];
	}
	rma = Ma[1];
	sort(Ma+1,Ma+n*m+1,cmp);
	for (int i = 1;i <= n;i++)
	{
		if (i % 2 == 0)
		{
			for (int j = m;j >= 1;j--)
			{
				cnt++;
				if (Ma[cnt] == rma)
				{
					cout << i << ' ' << j;
					break;
				}
			}
		}
		else
		{
			
			for (int j = 1;j <= m;j++)
			{
				cnt++;
				if (Ma[cnt] == rma)
				{
					cout << i << ' ' << j;
					break;
				}
			}
		}
			
	}
	return 0;
}
