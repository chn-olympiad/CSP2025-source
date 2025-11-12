#include <bits/stdc++.h>

const int N = 1e3 + 1;

std::vector<unsigned> a;
unsigned p[N][N];

int main()
{
	std::freopen("xor.in", "r", stdin);
	std::freopen("xor.out", "w", stdout);
	
	int n;
	unsigned k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		unsigned in;
		std::cin >> in;
		a.push_back(in);
	}
	for(int i = 0; i < n; i++)
	{
		p[i][i] = a[i];
	}
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		unsigned x = a[i];
		for(int j = i; j < n; j++)
		{
			unsigned x = a[j] ^ p[i][j-1];
			p[i][j] = x;
			//x ^= a[j];
			if(x == k)
			{
				res++;
				i = j;
				//x = 0; 
				break;
			}
		}
	}
	//for(int i = 0; i < n; i++)
	//	std::cout << p[0][i] << ' ';
	std::cout << res << '\n';
	return 0;
}
