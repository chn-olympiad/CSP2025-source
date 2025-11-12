#include<bits/stdc++.h>
using namespace std;

int n, k, num[500005], dis[500005][2];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	//Find out all the disrict (checked)
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int xorh = 0;
		for(int j = i; j <= n; j++)
		{
			xorh = int(xorh ^ num[j]);
			if(int(xorh) == k)
			{
				dis[i][0] = j;
				break;
			}
		}
		if(dis[i][0] == 0) dis[i][1] = 1;
		for(int j = 1; j < i; j++)
		{
			if(dis[j][0] >= dis[i][0] && dis[j][1] == 0 && dis[i][1] == 0)
			{
				dis[j][1] = 1;
			}
		} 
	}
	
	// search the ANSWER!
	int now = 1;
	int ans = 0;
	while(now <= n)
	{
		if(dis[now][1] == 0)
		{
			ans++;
			now = dis[now][0] + 1;
		}
		else
		{
			now++;
		}
	}
	cout << ans;
	
	return 0;
} 

