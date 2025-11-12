#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1e1;
int x[N][5],ny[N][5],T,n,ans;
priority_queue< pair<int,int> > q[4];
int Max[N],Mid[N],Min[N],Maxpos[N],Midpos[N],Minpos[N];
inline void read(int &x)
{
 char c=getchar();	x=0;
 while(c<'0'||c>'9')	c=getchar();
 while(c>='0'&&c<='9')
 	x=(x<<3)+(x<<1)+c-48,c=getchar();
}
signed main()
{
 freopen("club.in","r",stdin);	freopen("club.out","w",stdout);
 read(T);
 while(T--)
 {
 	int pos=0;	read(n),ans=0;
 	while(!q[1].empty())	q[1].pop();
 	while(!q[2].empty())	q[2].pop();
 	while(!q[3].empty())	q[3].pop();
 	for(int i=1;i<=n;i++)
 		read(x[i][1]),read(x[i][2]),read(x[i][3]);
 	for(int i=1;i<=n;i++)
 	{
 		Max[i]=-1e9,Mid[i]=0,Min[i]=1e9,Maxpos[i]=0,Midpos[i]=0,Minpos[i]=0;
 		Max[i]=max(x[i][1],max(x[i][2],x[i][3]));
 		Min[i]=min(x[i][1],min(x[i][2],x[i][3]));
 		if(x[i][1]>=min(x[i][2],x[i][3])&&x[i][1]<=max(x[i][2],x[i][3]))	Mid[i]=x[i][1];
 		if(x[i][2]>=min(x[i][1],x[i][3])&&x[i][2]<=max(x[i][1],x[i][3]))	Mid[i]=x[i][2];
 		if(x[i][3]>=min(x[i][2],x[i][1])&&x[i][3]<=max(x[i][2],x[i][1]))	Mid[i]=x[i][3];
 		ny[i][1]=Max[i]-Mid[i],ny[i][2]=Mid[i]-Min[i];
 		for(int j=1;j<=3;j++)
 			if(x[i][j]==Max[i]&&Maxpos[i]==0)			Maxpos[i]=j;
 			else if(x[i][j]==Min[i]&&Minpos[i]==0)		Minpos[i]=j;
 			else										Midpos[i]=j;
 		q[Maxpos[i]].push(make_pair(-ny[i][1],i)),ans+=Max[i],pos=Maxpos[i];
 		while(q[pos].size()>n/2)
 		{
 			int Pos=q[pos].top().second;	q[pos].pop();
 			if(ny[Pos][1]==-1)
 			{
 				ans-=ny[Pos][2];
 				q[Minpos[Pos]].push(make_pair(-1e18,Pos)),pos=Minpos[Pos];
			}
			else
			{
				ans-=ny[Pos][1],ny[Pos][1]=-1;
				q[Midpos[Pos]].push(make_pair(-ny[Pos][2],Pos)),pos=Midpos[Pos];
			}
		}
	}
	printf("%lld\n",ans);
 }
 return 0;
}
