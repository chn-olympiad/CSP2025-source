#include<bits/stdc++.h>
using namespace std;
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
const int _=1e5+5;
int T,n,ma,pl,c[3],a[_][3],b[_],p[_];
ll ans;
signed main()
{	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	FIO("club1");
	FIO("club");
	cin>>T;
	while(T--)
	{	cin>>n,c[0]=c[1]=c[2]=pl=0,ans=0;
		for(int i=1;i<=n;i++)
		{	cin>>a[i][0]>>a[i][1]>>a[i][2],ma=max(a[i][0],max(a[i][1],a[i][2]));
			for(int j=0;j<3;j++)	if(a[i][j]==ma)
			{	b[i]=j,c[j]++;
				break;
			}
			ans+=ma;
		}
		if(c[0]>n/2)
		{	for(int i=1;i<=n;i++)	if(b[i]==0)	p[++pl]=a[i][0]-max(a[i][1],a[i][2]);
			sort(p+1,p+pl+1);
			for(int i=1;i<=c[0]-n/2;i++)	ans-=p[i];
		}
		else if(c[1]>n/2)
		{	for(int i=1;i<=n;i++)	if(b[i]==1)	p[++pl]=a[i][1]-max(a[i][0],a[i][2]);
			sort(p+1,p+pl+1);
			for(int i=1;i<=c[1]-n/2;i++)	ans-=p[i];
		}
		else if(c[2]>n/2)
		{	for(int i=1;i<=n;i++)	if(b[i]==2)	p[++pl]=a[i][2]-max(a[i][0],a[i][1]);
			sort(p+1,p+pl+1);
			for(int i=1;i<=c[2]-n/2;i++)	ans-=p[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
