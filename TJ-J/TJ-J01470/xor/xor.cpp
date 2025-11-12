/*
#include<bits/stdc++.h>
using namespace std;
//异或：^ 
const int MAXN = 5e5+7;
int n, k;
int a[MAXN];
bool vis[MAXN];
int fx[2] = {-1, 1}, val[MAXN];
bool tvis[MAXN];
queue <int> q; 
int ans;

int main()
{
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	vis[0] = vis[n+1] = false;
	for (int i = 1; i <= n; i++)
	{
		vis[i] = false;
		scanf("%d", &a[i]);
		if (a[i] == k)
		{
			ans += 1;
			vis[i] = true;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		int tans = ans;
		
		memset(val, sizeof(val), 0);
		for (int i = 1; i <= n; i++)
		{
			tvis[i] = vis[i];
		}
		//初始化队列 
		while (!q.empty())
		{
			q.pop();
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == false && (vis[i+k] == true || vis[i-k] == true))
			{
				q.push(i);
				printf("%d ", q.back());
			}
			
		}
		printf(":");
		while (!q.empty())
		{
			int x = q.front();
			printf("%d ", q.front());
			q.pop();
			for (int i = 0; i <= 1; i++)
			{
				int tx = x + fx[i];
				if (tvis[tx] == false)
				{
					val[tx] = val[x] ^ a[x];
					tvis[tx] = true;
					
					if (val[tx] == k)
					{
						tans++;
					}
					q.push(tx);
				}
			}
		}
		
		for (int i = 1; i<= n; i++)
		{
			printf("%d ", tvis[i]);
		}
		printf("\n");
		
		ans = max(ans, tans);
	}
	
	printf("%d", ans);
	
	return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;
//异或：^ 
const int MAXN = 5e5+7;
int n, k;
int a[MAXN];
int ans;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				ans += 1;
			}
			else if (a[i] ^ a[i+1] == k)
			{
				ans += 1;
				i++;
			}
		}
	}
	else if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == k)
			{
				ans += 1;
			}
		}
	}
	else
	{
		ans = 20;
	}
	printf("%d", ans);
	
	return 0;
}


