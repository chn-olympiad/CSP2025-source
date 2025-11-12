#include<bits/stdc++.h>

using namespace std;
const int N = 100010;
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> heap[5];

int g[5][N];


int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while(t --)
	{
		int n;
		scanf("%d", &n);
		
		if(n == 2)
		{
			int a1, a2, a3, b1, b2, b3;
			scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3);
			int max1 = max(a1 + b2, a1 + b3);
			int max2 = max(a2 + b1, a2 + b3);
			int max3 = max(a3 + b1, a3 + b2);
			cout << max(max1, max(max2, max3)) << "\n";
			continue;
		}
		
		for(int i = 1; i <= n ; i ++)
		{
			int maxn = -1, maxnn;
			for(int j = 1; j <= 3 ; j ++)
			{
				cin >> g[j][i];
				if(g[j][i] > maxn)
				{
					maxn = g[j][i];
					maxnn = j;
				}	
			}
			heap[maxnn].push({g[maxnn][i], i});
			
			if(heap[maxnn].size() > n / 2)
			{
				PII t = heap[maxnn].top();
				heap[maxnn].pop();
				int ver = t.second;
				g[maxnn][ver] = 0;
				maxn = -1, maxnn = 0;
				for(int j = 1; j <= 3; j ++)
				{
					if(g[j][ver] > maxn)
					{
						maxn = g[j][ver];
						maxnn = j;
					}
				}
				heap[maxnn].push({g[maxnn][ver], ver});
				if(heap[maxnn].size() > n / 2)
				{
					PII t = heap[maxnn].top();
					heap[maxnn].pop();
					ver = t.second;
					g[maxnn][ver] = 0;
					maxn = -1, maxnn = 0;
					for(int j = 1; j <= 3; j ++)
					{
						if(g[j][ver] > maxn)
						{
							maxn = g[j][ver];
							maxnn = j;
						}
					}
					heap[maxnn].push({g[maxnn][ver], ver});
				}
			}
		}
		
		int sum = 0;
		for(int i = 1; i <= 3; i ++)
		{
			while(heap[i].size())
			{
				PII t = heap[i].top();
				sum += t.first;
				heap[i].pop();
			}
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}
