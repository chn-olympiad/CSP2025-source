#include<bits/stdc++.h>
using namespace std;
#define int long long

struct SSSSS
{
	int a1;
	int a2;
	int a3;
};

int t;
int n;
SSSSS a[100005];
int flag[5];
int sortt=0;
int ans=-1;

int over_()
{
	return flag[1]>n/2+flag[2]>n/2+flag[3]>n/2;
}
bool cmp1(SSSSS x,SSSSS y)
{
	return max(max(x.a1,x.a2),x.a3)>max(max(y.a1,y.a2),y.a3);
}
bool cmp2(SSSSS x,SSSSS y)
{
	if(flag[1]>n/2)
		return max(x.a2,x.a3)>max(y.a2,y.a3);
	if(flag[1]>n/2)
		return max(x.a1,x.a3)>max(y.a1,y.a3);
	if(flag[1]>n/2)
		return max(x.a2,x.a1)>max(y.a2,y.a1);
}
bool cmp3(SSSSS x,SSSSS y)
{
	if(flag[1]<=n/2)
		return x.a1>y.a1;
	if(flag[2]<=n/2)
		return x.a2>y.a2;
	if(flag[3]<=n/2)
		return x.a3>y.a3;
}
void dfs(int id,int cnt)
{
	ans=max(cnt,ans);
	if(id>n)
		return ;
	if(sortt==0&&over_()==0)
	{
		sort(a+1,a+n+1,cmp1);
		sortt++;
	}
	else if(sortt==1&&over_()==1)
	{
		sort(a+id,a+n+1,cmp2);
		sortt++;
	}
	else if(sortt==2&&over_()==2)
	{
		sort(a+id,a+n+1,cmp3);
		sortt++;
	}
	
	int maxx;
	if(over_()==0)
	{
		maxx=max(max(a[id].a1,a[id].a2),a[id].a3);
	}
	else if(over_()==1)
	{
		if(flag[1]>n/2)
			maxx=max(a[id].a2,a[id].a3);
		if(flag[2]>n/2)
			maxx=max(a[id].a1,a[id].a3);
		if(flag[3]>n/2)
			maxx=max(a[id].a2,a[id].a1);
	}
	else if(over_()==2)
	{
		if(flag[1]<=n/2)
			maxx=a[id].a1;
		if(flag[2]<=n/2)
			maxx=a[id].a2;
		if(flag[3]<=n/2)
			maxx=a[id].a3;
	}
	
	if(flag[1]<=n/2)
	{
		flag[1]++;
		dfs(id+1,cnt+maxx);
		flag[1]--;
	}
	if(flag[2]<=n/2)
	{
		flag[2]++;
		dfs(id+1,cnt+maxx);
		flag[2]--;
	}
	if(flag[3]<=n/2)
	{
		flag[3]++;
		dfs(id+1,cnt+maxx);
		flag[3]--;
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sortt=0;
		flag[1]=0;
		flag[2]=0;
		flag[3]=0;
		ans=-1;
		dfs(0,0);
		cout<<ans<<" ";
		
		
	}
	
	return 0;
}