#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],fi[N],se[N];
inline bool cmp(int x,int y)
{
	return a[x][se[x]]-a[x][fi[x]]>a[y][se[y]]-a[y][fi[y]];
}
signed main()
{
	/*
	cout<<system("fc club5.out club5.ans");
	return 0;
	*/
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int>e[4];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i][0]=-1;
			fi[i]=se[i]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=1;j<=3;j++)
				if(a[i][j]>a[i][fi[i]])
					fi[i]=j;
			for(int j=1;j<=3;j++)
				if(j!=fi[i]&&a[i][j]>a[i][se[i]])
					se[i]=j;
			e[fi[i]].push_back(i);
			ans+=a[i][fi[i]];
		}
		for(int i=1;i<=3;i++)
		{
			if((int)e[i].size()>n/2)
			{
				sort(e[i].begin(),e[i].end(),cmp);
				int t=(int)e[i].size()-(n/2);
				for(int j=0;j<t;j++)
				{
					int x=e[i][j];
					ans+=a[x][se[x]]-a[x][fi[x]];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//^_^
