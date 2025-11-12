#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int r=1,l=n;
			while(r<=l)
			{
				int mid=(r+l)/2;
				if(a[mid]>=a[i]+a[j])
				{
					l=mid-1;
				}
				else{
					r=mid+1;
				}
			}
			int mid=(r+l)/2;
			ans+=((mid-max(i,j)+1)*mid-max(i,j))/2;
			ans%=998244353;
			
		}
	}
	cout << ans+1;
	return 0;
}

