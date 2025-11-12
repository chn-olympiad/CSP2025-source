// club.cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N][4],ch[N];
vector<int> vec[4];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0,p=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=mx;
			for(int j:{1,2,3}) if(a[i][j]==mx) {ch[i]=j,vec[j].push_back(i);break;}
		}
		for(int i=1;i<=3;i++) if((int)vec[i].size()>n/2) {p=i;break;}
		if(p)
		{
			vector<int> del;
			for(int i=1;i<=n;i++) if(ch[i]==p)
			{
				int mn=1e9;
				for(int j:{1,2,3}) if(j!=p) mn=min(mn,a[i][p]-a[i][j]);
				del.push_back(mn);
			}
			sort(del.begin(),del.end());
			for(int i=0;i<(int)vec[p].size()-n/2;i++) ans-=del[i];
		}
		cout<<ans<<"\n";
		for(int i:{1,2,3}) vec[i].clear();
	}
	return 0;
}

/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/

// AVENGER_M & sanyueyetu
// zhu wo bu yao gua fen

// I MISS HER
