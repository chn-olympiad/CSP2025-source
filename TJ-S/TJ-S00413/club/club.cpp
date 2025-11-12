#include<bits/stdc++.h>
using namespace std;
int t,n,a[10000][4],all;

int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		int m = n / 2;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
			int ans1 = max(a[i-1][1],a[i][1]);
			int ans2 = max(a[i-1][2],a[i][2]);
			int ans3 = max(a[i-1][3],a[i][3]);
			 all = ans1 + ans2 + ans3;
		}
		cout << all;
	}

	return 0;
} 
