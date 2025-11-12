#include<bits/stdc++.h>
using namespace std;

int a[500005],dp[500005],n,k;
int ans;
int c = 1;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(i > 1) dp[i] = (a[i] ^ dp[i-1]);
		else dp[i] = a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j >= c;j--)
		{
			if((dp[i] ^ dp[j-1]) == k)
			{
				ans++;
				c = i + 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
//oooooooooooooooooooppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp 
