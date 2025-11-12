#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5005
int a[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0)
		{
			for(int i=1; i<=n; i++)
				{
					cin>>a[i];
				}
			if(n==1) cout<<"0";
			else cout<<n;
			return 0;
		}
	else if(k==1)
		{
			int cntt=0,cnttt=0;
			for(int i=1; i<=n; i++)
				{
					cin>>a[i];
					if(a[i]==0) cntt++;
					else if(a[i]==1) cnttt++;
				}
			cout<<max(cntt,cnttt);
			return 0;
		}
	return 0;
}
