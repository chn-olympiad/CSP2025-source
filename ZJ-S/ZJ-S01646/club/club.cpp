#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int n;
int a[N][3];
int d1[N], d2[N];
vector<int> p[3];
int num[N];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T -- )
	{
		scanf("%d", &n);
		
		memset(d1, 0, sizeof d1);
		memset(d2, -1, sizeof d2);
		for (int i = 0; i < 3; i ++ ) p[i].clear();		
		
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j < 3; j ++ ) 
				scanf("%d", &a[i][j]);
				
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j < 3; j ++ )
			{
				if (a[i][j] >= a[i][d1[i]]) d2[i] = d1[i], d1[i] = j;
				else if (d2[i] == -1 || a[i][j] > a[i][d2[i]]) d2[i] = j;
			}			
		}
				
		int res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			p[d1[i]].push_back(i);
			res += a[i][d1[i]];
		}
				
		int t = -1;
		for (int i = 0; i < 3; i ++ )
			if (p[i].size() > n / 2)
			{
				t = i;
				break;
			}
		
		if (t != -1)
		{
			for (int i = 0; i < p[t].size(); i ++ )
			{
				
				int id = p[t][i];
				num[i] = a[id][d2[id]] - a[id][d1[id]];
			}
			sort(num, num + p[t].size());
			reverse(num, num + p[t].size());
			for (int i = 0; i < p[t].size() - n / 2; i ++ ) res += num[i];
		}
		
		
		printf("%d\n", res);
	}
	
	return 0;
}
