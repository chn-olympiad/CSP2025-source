#include<cstdio>
#include<string>
#include<iostream>
const int MAXN = 110;
int n, q;
std::string s1[MAXN], s2[MAXN];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++ i) std::cin >> s1[i] >> s2[i];
	while(q --)
	{
		std::string t1, t2;
		std::cin >> t1 >> t2;
		int ans = 0;
		for(int i = 1; i <= n; ++ i)
		{
			for(int j = 0; j <= (int)t1.size() - (int)s1[i].size(); ++ j)
			{
				std::string tmp = t1.substr(j, s1[i].size());
				if(tmp == s1[i]) 
				{
					for(int k = j; k < j + (int)s1[i].size(); ++ k) t1[k] = s2[i][k - j];
					if(t1 == t2) ans ++;
					for(int k = j; k < j + (int)s1[i].size(); ++ k) t1[k] = s1[i][k - j];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

