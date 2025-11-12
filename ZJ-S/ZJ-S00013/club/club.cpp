#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,j,y;
};
node c[100010];
int T,n,a[100010][4],d[100010],maxans,ans,cnt[4],used[100010];
bool cmp1(node aa,node bb)
{
	return max(aa.w,max(aa.j,aa.y))>max(bb.w,max(bb.j,bb.y));
}
void cx2()
{
	ans=0;cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++)
	  c[i].w=a[i][1],c[i].j=a[i][2],c[i].y=a[i][3];
	sort(c+1,c+n+1,cmp1);
	for(int i=1;i<=n;i++)
	  a[i][1]=c[i].w,a[i][2]=c[i].j,a[i][3]=c[i].y;
	for(int i=1;i<=n;i++)
	{
		int Max=-1;
		for(int j=1;j<=3;j++)
		  Max=max(Max,a[i][j]);
		bool flag=1;
		int k1;
		for(int j=1;j<=3;j++)
		if(a[i][j]==Max)
		{
			if(cnt[j]+1<=n/2)
			{
				cnt[j]++,ans+=Max;
				used[i]=j;
				flag=0;
				break;
			}
			k1=j;
		}
		if(flag)
		{
			int tmax=INT_MIN;
			int t=-1,k2;
			for(int j=1;j<=3;j++)
			if(a[i][j]!=Max && cnt[j]+1<=n/2)
			{
				if(t<a[i][j])
				{
					t=a[i][j];
					k2=j;
				}
			}
			int kkk,kkkk;
			cnt[k1]++;
			for(int j=1;j<i;j++)
			{
				if(a[i][used[j]]!=Max) continue;
				int ttmax=a[j][used[j]];
				int tt=-1,tj;
				for(int k=1;k<=3;k++)
				if((a[j][k]<a[j][used[j]] || a[j][k]==a[j][used[j]] && k>used[j]) && (cnt[k]+1)<=n/2)
				{
					if(tt<a[j][k]) tt=a[j][k],tj=k;
				}
				if(tt!=-1)
				{
					if(ttmax+t<Max+tt) tmax=max(tmax,Max+tt-ttmax-t),kkk=j,kkkk=tj;
				}
			}
			if(tmax<0) ans+=t,used[i]=k2,cnt[k2]++,cnt[k1]--;
			else ans+=tmax+t,cnt[used[kkk]]--,cnt[kkkk]++,used[kkk]=kkkk,used[i]=k1;
		}
	}
	cout<<ans<<endl;
}
void dfs(int x,int sum)
{
	if(x>n)
	{
		maxans=max(maxans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	if(cnt[i]+1<=n/2)
	{
		cnt[i]++;
		dfs(x+1,sum+a[x][i]);
		cnt[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		  cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=10)
		{
			maxans=0;
			dfs(1,0);
			cout<<maxans<<endl;
		}
		else
		{
			bool flag2=1,flag3=1;
			for(int i=1;i<=n;i++)
			if(a[i][2]!=0)
			{
				flag2=0;
				break;
			}
			for(int i=1;i<=n;i++)
			if(a[i][3]!=0)
			{
				flag3=0;
				break;
			}
			if(flag2 && flag3)
			{
				for(int i=1;i<=n;i++)
				  d[i]=a[i][1];
				sort(d+1,d+n+1);
				int tt=0;
				for(int i=n;i>n-n/2;i--)
				  tt+=d[i];
				cout<<tt<<endl;
			}
			else cx2();
		}
	}
}