#include<bits/stdc++.h>

using namespace std;

int score[105];
int mp[15][15];

void init(int x, int y)
{
	int now = 1;
	for(int j = 1; j <= y; j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1; i <= x; i++)
			{
//				cout << i << " " << j << " " << now << endl;
				mp[i][j] = now;
				now++;
			}
		}
		else
		{
			for(int i = x; i >= 1; i--)
			{
//				cout << i << " " << j << " " << now << endl;
				mp[i][j] = now;
				now++;
			}
		}
//		cout << x << " " << y << " " << now << endl;
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++)
	{
		cin >> score[i];
	}
	
	int me = score[1];
	int p = 1;
	
	for(int i = 2; i <= n * m; i++)
	{
		if(score[i] > me)
		{
			p++;
		}
	}
	
	init(n, m);
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
//			cout << mp[i][j] << " ";
			if(mp[i][j] == p)
			{
				cout << j << " " << i << endl;
				break;
			}
		}
//		cout << endl;
	}
 	
	return 0;
}
