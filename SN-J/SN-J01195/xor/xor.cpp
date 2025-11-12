#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],sum[maxn],cnt;
struct ST
{
	int l,r;
};
ST b[maxn];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//cout<<i<<" "<<j<<" "<<(sum[j]^sum[i-1])<<endl;
			if((sum[j]^sum[i-1])==k)
			{
				cnt++;
				i=j;
				break;
			}
		}
		//cout<<i<<endl;
	}
	cout<<cnt;
	return 0;
}
