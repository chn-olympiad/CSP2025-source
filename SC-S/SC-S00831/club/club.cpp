#include<bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int ind;
	int val;
}gr1[100005],gr2[100005],gr3[100005];
bool cmp(node a,node b)
{
	return a.val>b.val;
}
int main()
{
	cin>>t;
	while(t--)
	{
		int n,flag1=0,flag2=0,flag3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j==1) cin>>gr1[i].val;
				if(j==2) cin>>gr2[i].val;
				if(j==3) cin>>gr3[i].val;
				if(j==1&&gr1[i].val!=0) flag1=1;
				if(j==2&&gr2[i].val!=0) flag2=1;
				if(j==3&&gr3[i].val!=0) flag3=1;
			}
			gr1[i].ind=gr2[i].ind=gr3[i].ind=i;
		}
		sort(gr1+1,gr1+n+1,cmp);
		sort(gr2+1,gr2+n+1,cmp);
		sort(gr3+1,gr3+n+1,cmp);
		if(!flag2&&!flag3&&flag1)
		{
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=gr1[i].val;
			cout<<ans<<'\n';
			continue; 
		}
		if(flag1&&flag2&&!flag3)
		{
			int ans1=0,ans2=0;
			int ans=0;
			for(int i=1;i<=n/2;i++) ans1+=gr1[i].val;
			for(int i=1;i<=n/2;i++) ans2+=gr2[i].val;
			if(ans1>ans2)
			{
				ans=ans1;
				bool b[100005];
				memset(b,false,sizeof(b));
				for(int i=1;i<=n/2;i++) b[gr1[i].ind]=1;
				for(int i=1;i<=n;i++)
				{
					if(b[i]!=1) ans+=gr2[i].val;
				} 
			}else
			{
				ans=ans2;
				bool b[100005];
				memset(b,false,sizeof(b));
				for(int i=1;i<=n/2;i++) b[gr2[i].ind]=1;
				for(int i=1;i<=n;i++)
				{
					if(b[i]!=1) ans+=gr1[i].val;
				} 
			}
			cout<<ans<<'\n';
		} 
	}
	return 0;
}