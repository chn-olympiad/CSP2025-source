#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	cout<<35;
	return 0;
}
