#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
  		vector<vector<int>> a(n,vector<int> (3));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		int maxn=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				maxn=max(a[i][j],maxn);
			}
			ans+=maxn;
		}
		cout<<ans<<endl;
	}
	return 0;
}