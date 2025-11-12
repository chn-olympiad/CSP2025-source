#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,a[maxn][4],ans,t,T;
struct node{int amax,dif;};
vector<int> v[4];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=3;i++)v[i].clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int c=1,mx=0,smx=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>mx)smx=mx,mx=a[i][j],c=j;
				else if(a[i][j]>smx)smx=a[i][j];
			}
			v[c].push_back(mx-smx);
			ans+=mx;
		}
		for(int i=1;i<=3;i++)
		{
//			cout<<v[i].size()<<' ';
			if(v[i].size()>n/2)t=i;
		}
//		cout<<'!'<<endl;
		if(t)
		{
			sort(v[t].begin(),v[t].end());
			for(int i=v[t].size();i>n/2;i--)
			{
//				cout<<'?'<<endl;
				ans-=v[t][v[t].size()-i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
