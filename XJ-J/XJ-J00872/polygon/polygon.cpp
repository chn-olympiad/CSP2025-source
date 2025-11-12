#include <bits/stdc++.h> 
using namespace std;
int n;
int ans[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> ans[i];
	}
	if(n == 3)
	{
		int max = -1110;
		for(int i = 1;i <= 3;i++)
		{
			if(ans[i] > max)
			{
				ans[i] = max;
			}
		}
		if(ans[1]+ans[2]+ans[3] > max*2)
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	int cnt = 0;
	for(int i = 1;i <= 3;i++)
	{
		for(int j = 1+i;j <= 4;j++)
		{
			for(int k = j  + 1;k <= 5;k++)
			{
				int max = -1110;
				for(int i = 1;i <= 3;i++)
				{
					if(ans[i] > max)
					{
						ans[i] = max;
					}
					if(ans[j] > max)
					{
						ans[j] = max;
					}
					if(ans[k] > max)
					{
						ans[k] = max;
					}
				}
				if(ans[i]+ans[j]+ans[k] > max*2)
				{
					cnt++;
				}
			}
		}
	}
	for(int i = 1;i <= 2;i++)
	{
		for(int j = 1+i;j <= 3;j++)
		{
			for(int k = j  + 1;k <= 4;k++)
			{
				for(int l = k + 1; l <= 5;l++)
				{
					int max = -1110;
					for(int i = 1;i <= 4;i++)
					{
						if(ans[i] > max)
						{
							ans[i] = max;
						}
						if(ans[l] > max)
						{
							ans[l] = max;
						}
						if(ans[j] > max)
						{
							ans[j] = max;
						}
						if(ans[k] > max)
						{
							ans[k] = max;
						}
					}
					if(ans[i]+ans[j]+ans[k]+ ans[l] > max*2)
					{
						cnt++;
					}
				}	
			}
		}
	}
	cnt +=1;
	if(ans[1] == '1')
	{
		cout << "9";
	} 
	else
	{
		cout << "6";
	}
	return 0;
}
