#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,vis[N],dif[N];
vector<int>f[4];
bool cmp(int x,int y){return dif[x]>dif[y];}
struct Num
{
	int x,stu,grp;
	bool operator<(const Num& oth)const
	{
		return x>oth.x;
	}
}a[N*3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int CaseNum;cin>>CaseNum;
	while(CaseNum--)
	{
		cin>>n;
		int idx=0;
		f[1].clear();
		f[2].clear();
		f[3].clear();
		for(int i=1,c,cc,ccc;i<=n;i++)
		{
			vis[i]=0;
			cin>>c>>cc>>ccc;
			a[++idx]=(Num){c,i,1};
			a[++idx]=(Num){cc,i,2};
			a[++idx]=(Num){ccc,i,3};
			if(c>ccc) swap(c,ccc);
			if(cc>ccc) swap(cc,ccc);
			if(c>cc) swap(c,cc);
			dif[i]=ccc-cc;
		}
		sort(a+1,a+3*n+1);
		int ans=0;
		for(int i=1;i<=3*n;i++)
		{
			if(vis[a[i].stu]) continue;
			ans+=a[i].x;
			vis[a[i].stu]=1;
			f[a[i].grp].push_back(a[i].stu);
		}
		if(f[1].size()>n/2)
		{
			sort(f[1].begin(),f[1].end(),cmp);
			while(f[1].size()>n/2)
			{
				ans-=dif[f[1][f[1].size()-1]];
				f[1].pop_back();
			}
		}
		if(f[2].size()>n/2)
		{
			sort(f[2].begin(),f[2].end(),cmp);
			while(f[2].size()>n/2)
			{
				ans-=dif[f[2][f[2].size()-1]];
				f[2].pop_back();
			}
		}
		if(f[3].size()>n/2)
		{
			sort(f[3].begin(),f[3].end(),cmp);
			while(f[3].size()>n/2)
			{
				ans-=dif[f[3][f[3].size()-1]];
				f[3].pop_back();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
