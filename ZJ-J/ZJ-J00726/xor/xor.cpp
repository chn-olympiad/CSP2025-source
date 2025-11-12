#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
bool vis[500010];
int xorsum(int l,int r)
{
	int res = 0;
	for(int i = l;i <= r;i++) res ^= a[i];
	return res;
}
bool check(int l,int r)
{
	for(int i = l;i <= r;i++) if(vis[i]) return false;
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++)
	{
		for(int l = 1;l <= n - i + 1;l++)
		{
			int r = l + i - 1;
			if(check(l,r))
			{
				int sum = xorsum(l,r);
				if(sum == k)
				{
					ans++;
					for(int j = l;j <= r;j++) vis[j] = true;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
