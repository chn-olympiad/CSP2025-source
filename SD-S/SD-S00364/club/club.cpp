#include<bits/stdc++.h>
#define i64 long long
#define u64 unsigned long long
#define prs " \n"
#define iinf 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
int t,n;
i64 a[N][4],q[N],w[N],e[N];
i64 ans;
void dfss(int o,int ac,int bc,int cc,i64 sum)
{
	if(o==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(ac<(n>>1)) dfss(o+1,ac+1,bc,cc,sum+a[o][1]);
	if(bc<(n>>1)) dfss(o+1,ac,bc+1,cc,sum+a[o][2]);
	if(cc<(n>>1)) dfss(o+1,ac,bc,cc+1,sum+a[o][3]);
	return;
}
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		bool fl1=0;
		int ac=0,bc=0,cc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3]) fl1=1;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1])
				ac++;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2])
				bc++;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3])
				cc++;
		}
		if(!fl1)
		{
			vector<int> ft;
			for(int i=1;i<=n;i++)
				ft.push_back(a[i][1]);
			sort(ft.begin(),ft.end());
			for(int i=0;i<(n>>1);i++)
				ans+=ft[i];
			cout<<ans<<'\n';
			continue;
		}
		if(ac<=(n>>1)&&bc<=(n>>1)&&cc<=(n>>1))
		{
			for(int i=1;i<=n;i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<ans<<'\n';
			continue;
		}
		dfss(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
