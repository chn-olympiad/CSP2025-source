#include<bits/stdc++.h>
using namespace std;
long long T,n,i,j,t,pl,ans,mo[100005][5],c[5][100005],s[100005];
long long read()
{
	char c=getchar();
	long long x=0,y=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(t=1;t<=T;t++)
	{
		n=read();
		for(i=1;i<=3;i++)c[i][0]=0;
		for(i=1;i<=n;i++)
		{
			mo[i][1]=read();
		    mo[i][2]=read();
		    mo[i][3]=read();
		    if(mo[i][1]>=mo[i][2])
		    {
			    if(mo[i][1]>=mo[i][3])c[1][++c[1][0]]=i;else c[3][++c[3][0]]=i;
		    }else
		    {
			    if(mo[i][2]>=mo[i][3])c[2][++c[2][0]]=i;else c[3][++c[3][0]]=i;
		    }
		}
		ans=0;
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=c[i][0];j++)ans+=mo[c[i][j]][i];
		}
		pl=0;
		for(i=1;i<=3;i++)
		{
			if(c[i][0]>n/2)pl=i;
		}
		if(pl==0)
		{
			cout<<ans<<endl;
			continue;
		}
		for(i=1;i<=c[pl][0];i++)
		{
			s[i]=INT_MAX;
			for(j=1;j<=3;j++)
			{
				if(j!=pl)s[i]=min(s[i],mo[c[pl][i]][pl]-mo[c[pl][i]][j]);
			}
		}
		sort(s+1,s+c[pl][0]+1);
		for(i=1;i<=c[pl][0]-n/2;i++)ans-=s[i];
		cout<<ans<<endl;
	}
}
