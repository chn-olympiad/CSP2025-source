#include<bits/stdc++.h>
using namespace std;
vector<int> res; //it's need to clear.
int a[100008][5]; //it's need to clear.
int sprstatus[100008];

bool cmp(int x, int y)
{
	return x > y;
}

void dfs(int d0, int d1, int d2, int nx, int nr, int now_i)
{
    nr = a[now_i][d0] + a[now_i][d1] + a[now_i][d2];
	if(d0 == 3 && d1 == 3 && d2 == 3)
	{
		return;
	}
	if(d0 <= nx / 2 && d1 <= nx / 2 && d2 <= nx / 2)
	{
//		int result;
		res.push_back(nr);
	}
	else
	{
		dfs(d0 + 1, d1, d2, nx, nr, now_i);
		dfs(d0, d1 + 1, d2, nx ,nr, now_i);
		dfs(d0, d1, d2 + 1, nx, nr, now_i);
//		dfs(d0 + 1, d1 + 1, d2)
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n ; i++)
		{
			res.push_back(0);
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < 3; j++)
			{
				a[i][j] = 0;
			}
		}
        for(int i = 0 ; i < n ; i++)
        {
            sprstatus[i] = 0;
        }

		for(int i = 0 ; i <n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			dfs(0, 0, 0, n, 0, i);
		}
		sort(res.begin(), res.end(), cmp);
		cout << res[0] << endl;
	}


	return 0;
}

