#include<bits/stdc++.h>
using namespace std;
int n;
int v[20005];
long sum[5],ans,fans,anpai;
struct node
{
	int da,bi;
};
node a[20005],b[20005],c[20005];
bool cmp(node x,node y)
{
	if(x.da>y.da) return true;
	return false;
}
void dfs(int dd)
{
	int i,j;
	if(dd>3||anpai==n)
	{
		fans=max(fans,ans);
		return;
	}
	if(dd==1)
	{
		for(i=1;i<=n;i++)
		if(sum[1]<n/2&&v[a[i].bi]==0)
		{
			ans+=a[i].da;v[a[i].bi]=1;sum[1]++;anpai++;
			if(anpai==n)
			{
				fans=max(fans,ans);
				ans-=a[i].da;v[a[i].bi]=0;sum[1]--;anpai--;
				continue;
			}
			if(sum[1]+1<=n/2) dfs(1);
			dfs(2);
			ans-=a[i].da;v[a[i].bi]=0;sum[1]--;anpai--;
		}
	}
	if(dd==2)
	{
		for(i=1;i<=n;i++)
		if(sum[2]<n/2&&v[b[i].bi]==0)
		{
			ans+=b[i].da;v[b[i].bi]=1;sum[2]++;anpai++;
			if(anpai==n)
			{
				fans=max(fans,ans);
				ans-=b[i].da;v[b[i].bi]=0;sum[2]--;anpai--;
				continue;
			}
			if(sum[2]+1<=n/2) dfs(2);
			dfs(3);
			ans-=b[i].da;v[b[i].bi]=0;sum[2]--;anpai--;
		}
	}
	if(dd==3)
	{
		for(i=1;i<=n;i++)
		if(sum[3]<n/2&&v[c[i].bi]==0)
		{
			ans+=c[i].da;v[c[i].bi]=1;sum[3]++;anpai++;
			if(anpai==n)
			{
				fans=max(fans,ans);
				ans-=c[i].da;v[c[i].bi]=0;sum[3]--;anpai--;
				continue;
			}
			if(sum[3]+1<=n/2) dfs(3);
			dfs(4);
			ans-=c[i].da;v[c[i].bi]=0;sum[3]--;anpai--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;fans=0;anpai=0;
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++)
		{
			cin>>a[i].da>>b[i].da>>c[i].da;
			a[i].bi=b[i].bi=c[i].bi=i;
		}
		sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);sort(c+1,c+n+1,cmp);
		
		dfs(1);
		cout<<fans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
