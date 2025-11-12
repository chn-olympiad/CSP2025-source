#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node
{
	int w[5],maxn,cd;
	bool vis=false;
}a[100005];
struct del
{
	int id,v;
}d[100005];
struct bl
{
	int id,vmaxn,vcd,v,nid,cz1,cz2;
	bool vis=false;
}b[100005];
int dp[2][100005],cnt;
bool cmp1(node x,node y)
{
	return x.w[1]>y.w[1];
}
bool cmp2(node x,node y)
{
	return x.w[2]>y.w[2];
}
bool cmp3(node x,node y)
{
	return x.w[3]>y.w[3];
}
bool cmpd(del x,del y)
{
	return x.v>y.v;
}
bool cmp(node x,node y)
{
	return x.w[1]>y.w[1];
}
bool cmps(node x,node y)
{
	if(x.vis&&(!y.vis))
	{
		return false;
	}
	else if((!x.vis)&&y.vis)
	{
		return true;
	}
	else return x.w[2]>y.w[2];
}
bool cmpbl(bl x,bl y)
{
	if(x.cz1==y.cz1)return x.vmaxn>y.vmaxn;
	return x.cz1>y.cz1;
}
bool cmpbltw(bl x,bl y)
{
	int xx=(x.vis?x.cz2:x.cz1),yy=(y.vis?y.cz2:y.cz1);
	if(xx==yy)return x.v>y.v;
	return xx>yy;
}
void solve()
{
	cin>>n;
	bool a1=false,a2=false,a3=false;
	int li=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w[1]>>a[i].w[2]>>a[i].w[3];
		if(a[i].w[1]>=a[i].w[2]&&a[i].w[1]>=a[i].w[3])a[i].maxn=1;
		if(a[i].w[2]>=a[i].w[1]&&a[i].w[2]>=a[i].w[3])a[i].maxn=2;
		if(a[i].w[3]>=a[i].w[2]&&a[i].w[3]>=a[i].w[1])a[i].maxn=3;
		if(a[i].w[1]>=a[i].w[2]&&a[i].w[1]<=a[i].w[3]||a[i].w[1]<=a[i].w[2]&&a[i].w[1]>=a[i].w[3])a[i].cd=1;
		if(a[i].w[2]>=a[i].w[1]&&a[i].w[2]<=a[i].w[3]||a[i].w[2]<=a[i].w[1]&&a[i].w[2]>=a[i].w[3])a[i].cd=2;
		if(a[i].w[3]>=a[i].w[2]&&a[i].w[3]<=a[i].w[1]||a[i].w[3]<=a[i].w[2]&&a[i].w[3]>=a[i].w[1])a[i].cd=3;
		if(a[i].w[2])a2=true;
		if(a[i].w[1])a1=true;
		if(a[i].w[3])a3=true;
	}
	if((!a1)&&(!a2))
	{
		sort(a+1,a+1+n,cmp3);
		int ans=0;
		for(int i=1;i<=li;i++)
		{
			ans+=a[i].w[3];
		}
		cout<<ans<<endl;
		return ;
	}
	else if((!a1)&&(!a3))
	{
		sort(a+1,a+1+n,cmp2);
		int ans=0;
		for(int i=1;i<=li;i++)
		{
			ans+=a[i].w[2];
		}
		cout<<ans<<endl;
		return ;
	}
	else if((!a2)&&(!a3))
	{
		sort(a+1,a+1+n,cmp1);
		int ans=0;
		for(int i=1;i<=li;i++)
		{
			ans+=a[i].w[1];
		}
		cout<<ans<<endl;
		return ;
	}
	else if(!a1)
	{
		for(int i=1;i<=n;i++)
		{
			d[i].id=i,d[i].v=a[i].w[2]-a[i].w[3];
		}
		int ans=0;
		sort(d+1,d+1+n,cmpd);
		for(int i=1;i<=li;i++)
		{
			ans+=a[d[i].id].w[2];
		}
		for(int i=li+1;i<=n;i++)
		{
			ans+=a[d[i].id].w[3];
		}
		cout<<ans<<endl;
		return ;
	}
	else if(!a2)
	{
		for(int i=1;i<=n;i++)
		{
			d[i].id=i,d[i].v=a[i].w[1]-a[i].w[3];
		}
		int ans=0;
		sort(d+1,d+1+n,cmpd);
		for(int i=1;i<=li;i++)
		{
			ans+=a[d[i].id].w[1];
		}
		for(int i=li+1;i<=n;i++)
		{
			ans+=a[d[i].id].w[3];
		}
		cout<<ans<<endl;
		return ;
	}
	else if(!a3)
	{
		for(int i=1;i<=n;i++)
		{
			d[i].id=i,d[i].v=a[i].w[2]-a[i].w[1];
		}
		int ans=0;
		sort(d+1,d+1+n,cmpd);
		for(int i=1;i<=li;i++)
		{
			ans+=a[d[i].id].w[2];
		}
		for(int i=li+1;i<=n;i++)
		{
			ans+=a[d[i].id].w[1];
		}
		cout<<ans<<endl;
		return ;
	}
	else/* if(n<=30)*/
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			b[i].id=i;
			b[i].vmaxn=a[i].w[a[i].maxn];
			b[i].vcd=a[i].w[a[i].cd];
			b[i].v=b[i].vmaxn;
			b[i].nid=a[i].maxn;
			b[i].cz1=b[i].vmaxn-b[i].vcd;
			b[i].cz2=b[i].vcd-a[i].w[6-a[i].maxn-a[i].cd];
		}
		sort(b+1,b+1+n,cmpbl);
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++)
		{
			int cur=b[i].nid;
			if(cur==1)c1++;
			if(cur==2)c2++;
			if(cur==3)c3++;
			if(cur==1&&c1>li)b[i].v=b[i].vcd,b[i].nid=a[b[i].id].cd,b[i].vis=true;
			if(cur==2&&c2>li)b[i].v=b[i].vcd,b[i].nid=a[b[i].id].cd,b[i].vis=true;
			if(cur==3&&c3>li)b[i].v=b[i].vcd,b[i].nid=a[b[i].id].cd,b[i].vis=true;
			//if(b[i].vis)cout<<i<<" "<<c1<<" "<<c2<<" "<<c3<<endl;
		}
		sort(b+1,b+1+n,cmpbltw);
		c1=c2=c3=0;
		for(int i=1;i<=n;i++)
		{
			int cur=b[i].nid;
			if(cur==1)c1++;
			if(cur==2)c2++;
			if(cur==3)c3++;
			if(cur==1&&c1>li)b[i].v=a[b[i].id].w[6-a[b[i].id].maxn-a[b[i].id].cd];
			if(cur==2&&c2>li)b[i].v=a[b[i].id].w[6-a[b[i].id].maxn-a[b[i].id].cd];
			if(cur==3&&c3>li)b[i].v=a[b[i].id].w[6-a[b[i].id].maxn-a[b[i].id].cd];
		}
		for(int i=1;i<=n;i++)
		{
			ans+=b[i].v;
		}
		cout<<ans<<endl;
		return ;
	}
	/*else
	{
		memset(dp,0,sizeof dp);
		cnt=0;
		int ol=1,ne=0;
		for(int i=1;i<=n;i++)
		{
			swap(ol,ne);
			for(int j=1;j<=li;j++)
			{
				if(dp[ol][j-1]+a[i].w[1]>dp[ol][j])
				{
					cnt++;
					a[i].vis=true;
				}
				dp[ne][j]=max(dp[ol][j],dp[ol][j-1]+a[i].w[1]);
			}
		}
		int mem=dp[ne][li],mem2=0,mem3=0;
		memset(dp,0,sizeof dp);
		sort(a+1,a+1+n,cmps);
		ol=1,ne=0;
		for(int i=1;i<=cnt;i++)
		{
			if(a[i].vis)
			{
				mem2=dp[ne][i];
				break;
			}
			swap(ol,ne);
			for(int j=1;j<=li;j++)
			{
				if(dp[ol][j-1]+a[i].w[2]>dp[ol][j])
				{
					a[i].vis=true;
				}
				dp[ne][j]=max(dp[ol][j],dp[ol][j-1]+a[i].w[2]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!a[i].vis)mem3+=a[i].w[3];
		}
		cout<<mem+mem2+mem3<<endl;
		return ;
	}*/
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
