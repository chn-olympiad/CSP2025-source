#include <iostream>
using namespace std;

int a[1001010], n, cnt, c[1001010];

void dfs(int step, int last)
{
	if(last > n)
	{
		int sum = 0;
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			if(c[i] != 0) 
			{
				sum += a[i];
				maxn = max(maxn, a[i]);
			}
		}
		if(step >= 3 && maxn * 2 < sum) cnt++;
		return;
	}
	c[last] = 1;
	dfs(step+1, last+1);
	c[last] = 0;
	dfs(step, last + 1);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(0,1);
	cout << cnt;
}

