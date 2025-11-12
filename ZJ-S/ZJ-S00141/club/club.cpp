#include<bits/stdc++.h>
using namespace std;


struct node
{
	int a1,a2,a3;
}a[100011];
int t,n;
int s[4],ans;
int ff[100011],vis[100011];

bool cmp1(node a,node b)
{
	return a.a1>b.a1;
}
bool cmp2(node a,node b)
{
	return a.a2>b.a2;
}

int fm(int i)
{
	if(a[i].a1>a[i].a2) 
	{
		if(a[i].a1>a[i].a3) return 1;
		else return 3;
	}
	else if(a[i].a1<a[i].a2)
	{
		if(a[i].a2>a[i].a3) return 2;
		else return 3;
	}
	else
	{
	    if(a[i].a1<a[i].a3) return 3;
		else return 1;
	}
}

void solve()
{
	for(int i=1;i<=n;i++) ff[i]=fm(i);
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(ff[i]!=1) continue;
		ans+=a[i].a1;
		s[1]++;
		vis[i]=1;
		if(s[1]>=n/2) break;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]||ff[i]!=2) continue;
		ans+=a[i].a2;
		s[2]++;
		vis[i]=1;
		if(s[2]>=n/2) break;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ans+=a[i].a3;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		t--;
		n=0;
		ans=0;
		memset(ff,0,sizeof(ff));
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		solve();
	}
	return 0;
}
