#include <bits/stdc++.h> 
using namespace std;
int m,n,ans;
int a[105];
int num[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m>>n;
	for(int i = 1;i <= m * n;i++)
	{
		cin >> a[i];
	}
	ans = a[1];
	sort(a+1,a+n*m+1);
	for(int i = 1;i<= m;i++)
	{
		if(i % 2== 1)
		{
			for(int j = 1;j <= n;j++)
			{
				num[i][j] = a[(i - 1)*m + j];
				if(num[i][j] == ans)
				{
					cout << j<<" "<<i;
					return 0;
				}	
			}
		}
		if(i % 2== 0)
		{
			for(int j = 1;j <= n;j++)
			{
				num[i][j] = a[(i - 1)*m + n -j+1];
				if(num[i][j] == ans)
				{
					cout << j<<" "<<i;
					return 0;
				}
				
			}
		}
	}
}
