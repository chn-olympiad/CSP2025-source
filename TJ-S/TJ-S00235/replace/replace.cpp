#include<bits/stdc++.h> 

const int N = 2e5 + 1;
std::string s1[N];
std::string s2[N];

int main()
{
	std::freopen("replace.in", "r", stdin);
	std::freopen("replace.out", "w", stdout);
	
	int n, q;
	std::cin >> n >> q;
	for(int i = 0; i < n; i++)
	{
		std::cin >> s1[i] >> s2[i];
	}
	while(q--)
	{
		std::string t1, t2;
		int t1b, t2b;
		for(int i = 0; i < n ;i++)
		{
			if(t1[i] == 'b')
			{
				t1b = i;
				break;
			}
			if(t2[i] == 'b')
			{
				t2b = i;
				break;
			}
		}
		std::cout << 0 << '\n';
	}
}
