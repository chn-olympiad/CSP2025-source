#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,k,a[N],f[N],ans,r[N],l[N],num = 1;
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	f[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i],f[i] = f[i-1]^a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			int x = f[i-1]^f[j];
			if(x == k)
			{
				if(i <= r[num-1])
				{
					if(j-i < r[num-1] - l[num-1] && j <= r[num-1])
					{
						l[num] = i,r[num] = j,num++;
					}
				}
				else
				{
					ans++;
					l[num] = i,r[num] = j;
					num++;
			    }
		    }
		}
	}
	cout << ans;
	return 0;
}

