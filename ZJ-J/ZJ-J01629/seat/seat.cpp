#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> seat[105];
int score[105];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int stu = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (i % 2 == 1)
		{
			// down
			for (int j = 1; j <= n; ++j)
			{
				seat[++stu].first = i;
				seat[stu].second = j;
			}
		}
		else
		{
			// up
			for (int j = n; j >= 1; --j)
			{
				seat[++stu].first = i;
				seat[stu].second = j;
			}
		}
	}
//	for (int i = 1; i <= n * m; ++i)
//	{
//		cout << seat[i].first << " " << seat[i].second << endl;
//	}
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> score[i];
	}
	int r = score[1];
	sort(score + 1, score + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; ++i)
	{
		if (score[i] == r)
		{
			cout << seat[i].first << " " << seat[i].second;
			return 0;
		}
	}
	return 0;
}
