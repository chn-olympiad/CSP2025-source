#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int mx,cmx,minn,pmx,pcmx,pminn;
}q[N];
struct data
{
	int pos,x;
}d[10];
int cmp2(data o,data p)
{
	return o.x>p.x;
}
int cmp(node o,node p)
{
	return o.mx-o.cmx>p.mx-p.cmx;
}
int f[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++) d[j].pos=j,cin>>d[j].x;
			sort(d,d+3,cmp2);
			q[i].mx=d[0].x,q[i].pmx=d[0].pos;
			q[i].cmx=d[1].x,q[i].pcmx=d[1].pos;
			q[i].minn=d[2].x,q[i].pminn=d[2].pos;
		}
		sort(q+1,q+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(f[q[i].pmx]>=n/2)
			{
				if(q[i].cmx==q[i].minn)
				{
					if(f[q[i].pcmx]>f[q[i].pminn]) f[q[i].pminn]++,ans+=q[i].minn;
					else f[q[i].pcmx]++,ans+=q[i].cmx;
				}
				else f[q[i].pcmx]++,ans+=q[i].cmx;
			}
			else f[q[i].pmx]++,ans+=q[i].mx;
		}
		cout<<ans<<'\n';
		f[0]=f[1]=f[2]=0;
	}
	return 0;
}
