#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n;
int a[N][5],lin[5];
vector<int> vv[5],vvv;
#define endl "\n"
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=3;i++)
			vv[i].clear();
		vvv.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int maxx=-1,idd=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>maxx)
				{
					maxx=a[i][j];
					idd=j;
				}
			}
			ans+=maxx;
			vv[idd].push_back(i);
		}
		int id=0;
		for(int i=1;i<=3;i++)
		{
			int len=vv[i].size();
			if(len>n/2)
				id=i;
		}
		if(id==0)
		{
			cout<<ans<<endl;
			continue;
		}
		else
		{
			int len=vv[id].size();
			for(int i=0;i<len;i++)
			{
				int u=vv[id][i];
				for(int j=1;j<=3;j++)
					lin[j]=a[u][j];
				sort(lin+1,lin+1+3);
				vvv.push_back(lin[3]-lin[2]);
			}
			sort(vvv.begin(),vvv.end());
			len-=(n/2);
			for(int i=0;i<len;i++)
				ans-=vvv[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
*/