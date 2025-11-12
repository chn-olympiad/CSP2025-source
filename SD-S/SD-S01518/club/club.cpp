#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
int a[maxn][3];
int maxx;
pair<int,int> cnt[maxn][maxn / 2][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; 
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			cnt[i][1][0].second = a[i][0];
			cnt[i][1][1].second = a[i][1];
			cnt[i][1][2].second = a[i][2];
		}
		k = n / 2;
		for(int m = 1; m <= k; m++)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 0; j < 3; i++)
				{
					cnt[i][m][j].first = max(cnt[i - 1][m][j].first,cnt[i - 1][m][j].second);
					cnt[i][m][j].second = max(cnt[i - 1][m - 1][j].first,cnt[i - 1][m - 1][j].second) + a[i][j];
				}
			}
		}
		maxx = 0;
		int flag = 0;
		for(int i = 0; i < 3; i++)
		{
			if(maxx < cnt[n][k][i].second)
			{
				flag = i;
			}
		}	
		for(int i = 0; i < 3; i++)
		{
			if(flag == i)
				maxx += cnt[n][k][i].second;
			else
				maxx = cnt[n][k][i].first;
		}
		cout << maxx << endl;
	}
	fclose(0);
	return 0;
}
