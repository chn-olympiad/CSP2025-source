#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long cnt;
const int MOD=998244353;
void bp(int step,long long sum,long long mx,int m)
{
	if (step>n)
	{
		if (m<3)
			return;
		if (sum>2*mx)
			cnt=(cnt+1)%MOD;
		return;
	}
	bp(step+1,sum,mx,m);
	bp(step+1,sum+a[step],max(mx,a[step]),m+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	bp(1,0,0,0);
	cout << cnt%MOD;
	return 0;
}
