#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+2;
int n,w[maxn];
long long k,ans;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int tmpf = w[i];
			for(int hk=i+1;hk<=j;hk++)
			{
				tmpf^=w[hk];
			}
			if(tmpf==k)ans++;
		}
	}
	cout << ans;
	return 0;
}
