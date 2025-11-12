#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
int n,m,k;
int a[N][5],mx[N],cmx[N],v[N],mns[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		int p[5];
		p[1]=p[2]=p[3]=0;
		int des=n/2,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>mx[i])
				{
					mx[i]=a[i][j];
					v[i]=j;
				}
			}
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>cmx[i]&&j!=v[i])
					cmx[i]=a[i][j];
			}
			p[v[i]]++;
			ans+=mx[i];
		}
		if(max(p[1],max(p[2],p[3]))<=n/2)
		{
			cout<<ans<<endl;
		}
		else
		{
			int mp=0,cnt=0;
			for(int i=1;i<=3;i++)if(p[i]>des)mp=i;
			for(int i=1;i<=n;i++)
			{
				if(v[i]==mp)
				{
					mns[++cnt]=mx[i]-cmx[i];
				}
			}
			sort(mns+1,mns+cnt+1);
			for(int i=1;i<=cnt-n/2;i++)ans-=mns[i];
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)mx[i]=cmx[i]=v[i]=mns[i]=0;
	}
	return 0;
 } 
