#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[5005];
bool vis[5005];
int sum()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += a[i];
	return cnt;
}
int Max()
{
	int maxans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] = 0)
		{
			maxans = max(maxans,a[i]);
		}
	}
	return maxans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n < 3)
	{
		cout << 0 << "\n";
		return 0;
	}
	else if(n == 3)
	{
		sort(a+1,a+1+n);
		if(sum() > a[n] * 2)
		{
			cout << 1 << "\n";
			return 0;
		}
		else cout << 0 << "\n";
	}
	else if(n <= 10)
	{
		for(int i = 1; i <= n; i++) vis[i] = 0;
		if(n == 4)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 5)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 6)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++)//选5个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							for(int r = l + 1; r <= n; r++)
							{
								if(a[i] + a[j] + a[k] + a[l] + a[r] > max(a[i],max(a[j],max(a[k],max(a[l],a[r])))) * 2) ans++;
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 7)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++)//选5个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							for(int r = l + 1; r <= n; r++)
							{
								if(a[i] + a[j] + a[k] + a[l] + a[r] > max(a[i],max(a[j],max(a[k],max(a[l],a[r])))) * 2) ans++;
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选6个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							vis[i] = vis[j] = vis[k] = vis[l] = 1;
							if(sum() - (a[i] + a[j] + a[k] + a[l]) > Max() * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 8)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++)//选5个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							for(int r = l + 1; r <= n; r++)
							{
								if(a[i] + a[j] + a[k] + a[l] + a[r] > max(a[i],max(a[j],max(a[k],max(a[l],a[r])))) * 2) ans++;
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选6个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							vis[i] = vis[j] = vis[k] = vis[l] = 1;
							if(sum() - (a[i] + a[j] + a[k] + a[l]) > Max() * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选7个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						vis[i] = vis[j] = vis[k] = 1;
						if(sum() - (a[i] + a[j] + a[k]) > Max() * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 9)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++)//选5个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							for(int r = l + 1; r <= n; r++)
							{
								if(a[i] + a[j] + a[k] + a[l] + a[r] > max(a[i],max(a[j],max(a[k],max(a[l],a[r])))) * 2) ans++;
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选6个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							vis[i] = vis[j] = vis[k] = vis[l] = 1;
							if(sum() - (a[i] + a[j] + a[k] + a[l]) > Max() * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选7个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						vis[i] = vis[j] = vis[k] = 1;
						if(sum() - (a[i] + a[j] + a[k]) > Max() * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选8个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					vis[i] = vis[j] = 1;
					if(sum() - (a[i] + a[j]) > Max() * 2) ans++;
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
		else if(n == 10)
		{
			for(int i = 1; i <= n; i++)//选3个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						if(a[i] + a[j] + a[k] > max(a[i],max(a[j],a[k])) * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++)//选4个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							if(a[i] + a[j] + a[k] + a[l] > max(a[i],max(a[j],max(a[k],a[l]))) * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++)//选5个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							for(int r = l + 1; r <= n; r++)
							{
								if(a[i] + a[j] + a[k] + a[l] + a[r] > max(a[i],max(a[j],max(a[k],max(a[l],a[r])))) * 2) ans++;
							}
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选6个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						for(int l = k + 1; l <= n; l++)
						{
							vis[i] = vis[j] = vis[k] = vis[l] = 1;
							if(sum() - (a[i] + a[j] + a[k] + a[l]) > Max() * 2) ans++;
						}
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选7个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					for(int k = j + 1; k <= n; k++)
					{
						vis[i] = vis[j] = vis[k] = 1;
						if(sum() - (a[i] + a[j] + a[k]) > Max() * 2) ans++;
					}
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选8个 
			{
				for(int j = i + 1; j <= n; j++)
				{
					vis[i] = vis[j] = 1;
					if(sum() - (a[i] + a[j]) > Max() * 2) ans++;
				}
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			for(int i = 1; i <= n; i++)//选9个 
			{
				vis[i] = 1;
				if(sum() - a[i] > Max() * 2) ans++;
			}
			for(int i = 1; i <= n; i++) vis[i] = 0;
			if(sum() > Max() * 2) ans++;
			cout << ans << "\n";
			return 0;
		}
	}
	return 0;
}
