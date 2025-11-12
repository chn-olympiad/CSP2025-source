#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=205;
struct stu
{
	int fi,se,th;
	int dt_1,dt_2,ans_1,ans_2;
} a[N]; 
bool cmp1(stu x,stu y)
{
	return x.dt_1>y.dt_1;
}
bool cmp2(stu x,stu y)
{
	return x.dt_2>y.dt_2;
}
int n,T;
ll ans=0;
void dfs(int dep,int fi,int se,ll now_ans)
{
	if(dep==n+1)
	{
		ans=max(ans,now_ans);
		return;
	}
	if(fi<n/2)
		dfs(dep+1,fi+1,se,now_ans+a[dep].fi);
	if(se<n/2)
		dfs(dep+1,fi,se+1,now_ans+a[dep].se);
	if(dep-fi-se<n/2)
		dfs(dep+1,fi,se,now_ans+a[dep].th);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		if(n<=30)
		{
			for(int i=1;i<=n;i++)
				cin>>a[i].fi>>a[i].se>>a[i].th;
			dfs(0,0,0,0);
		}
		else
		{
			for(int i=1;i<=n;i++)
				cin>>a[i].fi>>a[i].se>>a[i].th,a[i].dt_1=a[i].fi-a[i].se; 
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				a[i].ans_1=a[i].fi,a[i].dt_2=a[i].ans_1-a[i].th;
			for(int i=n/2+1;i<=n;i++)
				a[i].ans_1=a[i].se,a[i].dt_2=a[i].ans_1-a[i].th;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++)
				if(i>=n/2&&a[i].dt_2<0)
					ans+=a[i].th;
				else
					ans+=a[i].ans_1;
		}
		cout<<ans<<endl;	
	}
	
	
	return 0;
}
