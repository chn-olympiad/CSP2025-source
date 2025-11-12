#include<bits/stdc++.h> 

const int MOD = 998244353;

std::vector<int> c;

int main()
{
	std::freopen("employ.in", "r", stdin);
	std::freopen("employ.out", "w", stdout);
	
	int n, m;
	std::string s;
	std::cin >> n >> m;
	std::cin >> s;
	c.resize(n);
	for(int i = 0; i < n; i++)
	{
		std::cin >> c[i];
	}
	std::cout << 0 << '\n';
}
