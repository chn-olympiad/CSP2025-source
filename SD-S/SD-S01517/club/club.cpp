#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10; 
int n;
int t;
int ans;
int a[maxn];
int b[maxn];
int c[maxn];
int main() 
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i]; 
		}
		int bj[n];
		int num[n][3];
		for(int i = 1;i <= n;i++)
		{
			bj[i] = 0;
			for(int j = 1;j <= 3;j++)
			{
				num[i][j] = 0;
			}	
		}
					
		for(int i = 1;i <= n;i++)
		{
			int x = 1;
			for(int j = 2;j <= n/2;j++)
			{
				if(num[x][1] > a[j])
				{
					x = j;
				}
			}
				if(bj[x] == 0)
				{
					num[x][1] = a[i];
//					bj[x] = 1;
				}
				
				continue;
		}
		for(int i = 1;i <= n;i++)
		{
			int x = 1;
			for(int j = 2;j <= n/2;j++)
			{
				if(num[x][2] > b[j])
				{
					x = j;
				}
			}
			if(bj[x] == 0)
			{
				num[x][2] = b[i];
				bj[x] = 1;
			}
			else
			{
				
			}
				continue;
		}
		for(int i = 1;i <= n;i++)
		{
			int x = 1;
			for(int j = 2;j <= n/2;j++)
			{
				if(num[x][3] > c[j])
				{
					x = j;
				}
			}
			if(bj[x] == 0)
			{
				num[x][3] = c[i];
				bj[x] = 1;
			}
				continue;
		}
				
		cout << ans << endl;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
