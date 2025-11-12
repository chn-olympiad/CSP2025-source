//SN-J00674 段宇晨 西安滨河学校 
#include <bits/stdc++.h>
int a[105];
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat,out","w",stdout);
	int n,m;
	cin >> n >> m;
	int y = n * m;
	for(int i = 1;i <= y;i++)
	{
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1;i <= y;i++)
	{
 		if(x == a[i])
		{
			int g = y - i + 1;
			int z = (g + n - g % n) / n;
			if(g <= n)
			{
				cout << 1 << " " << g;
				return 0;
			}
			else
			{
				cout << z << " ";
			}
			if(z % 2 == 0)
			{
				cout << z * n - g + 1;
			}
			else
			{
				cout << g + n - z * n;
			}
		}
	}
}
