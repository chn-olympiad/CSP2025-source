#include <bits/stdc++.h>
using namespace std;
int n,a[5005],m[5005],ans,maxn[5005],sum;
void dfs(int p,int len)
{
	if (len >= 3 && sum > 2*maxn[len]);
	{
		/*cout << len << endl;
		for (int i = 1;i <= len;i++)
		{
			cout << m[p] << " ";
		}
		cout << endl;*/
		//cout << sum << " " << len <<" " <<(len >= 3 && sum > 2*maxn[len]) << endl;
		if (len >= 3 && sum > 2*maxn[len])
		ans++;
	}
	if (p > n+1) return;
	dfs(p+1,len);
	m[len+1] = a[p];
	maxn[len+1] = max(maxn[len],a[p]);
	sum+=a[p];
	dfs(p+1,len+1);
	sum-=a[p];
	maxn[len+1] = 0;
	m[len+1] = 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	cout << ans%998244353;
}
