#include <bits/stdc++.h>
using namespace std;
int n, m, idx;
int a[200];
int seat[15][15];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
		

	int target = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	
	int row = 1, col = 1;
	
	bool f = true;//向下 
	while(idx < n * m)
	{
//		cout << "row=" << row << " col=" << col << " value=" << a[idx+1] << '\n'; 
		seat[row][col] = a[++idx];
		
		if(f && row <= n)
		{
			row++;
			if(row == n + 1)
			{
				col++;
				row = n;
				f = false;//向上 
			}
		}
		else if(!f && row >= 1)
		{
			row--;
			if(row == 0)
			{
				col++;
				row = 1;
				f = true;//向下 
			}
			
		}	
	}
	//输出 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(seat[i][j] == target)
			{
				cout << j << ' ' << i;//先列后行 
			}
		}
	}
	return 0;
} 
