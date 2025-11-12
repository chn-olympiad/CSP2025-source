#include <bits/stdc++.h>

int main()
{
	std::freopen("seat.in", "r", stdin);
	std::freopen("seat.out", "w", stdout);
	
	int n, m;
	std::vector<int> vec;
	std::cin >> n >> m;
	int r;
	for(int i = 0; i < n*m; i++)
	{
		int a;
		std::cin >> a;
		vec.push_back(-a);
	}
	r = vec[0];
	std::sort(vec.begin(), vec.end());
	int x, y;
	for(int i = 0; i < n*m; i++)
	{
		if(vec[i] == r)
		{
			r = i;
			break;
		}
	}
	r++;
	x = (r + (n - 1)) / n;
	std::vector<int> a;
	
	if(x % 2 == 1)
	{
		for(int i = (x-1) * n; i < x*n; i++)
			a.push_back(vec[i]);
		for(int i = 0; i < n; i++)
			if(a[i] == vec[r-1])
			{
				y = i + 1;
				break;
			}
	}
	else
	{
		for(int i = (x-1) * n; i < x*n; i++)
			a.push_back(-vec[i]);
		std::sort(a.begin(), a.end());
		for(int i = 0; i < n; i++)
			if(a[i] == -vec[r-1])
			{
				y = i + 1;
				break;
			}
		//r %= m;
		//y = m - r + 1;
	}
	std::cout << x << ' ' << y << '\n';
	
	return 0;
}
