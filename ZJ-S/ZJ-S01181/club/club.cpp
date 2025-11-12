#include<bits/stdc++.h>
using namespace std;
long long const N=1e5+1;
long long t,n,maxx,sum1,sum2,sum3;
struct wlx
{
	long long x,y,z,d,d2,vis;
}a[N];
/*void dfs(long long q)
{
	if(s>n/2||o>n/2||p>n/2) return;
	if(q==n+1)
	{
		maxx=max(maxx,sum);
		return;
	}
	o++;
	sum+=a[q].x;
	dfs(q+1);
	o--;
	sum-=a[q].x;
	p++;
	sum+=a[q].y;
	dfs(q+1);
	p--;
	sum-=a[q].y;
	s++;
	sum+=a[q].z;
	dfs(q+1);
	s--;
	sum-=a[q].z;
}*/
bool cmp(wlx a1,wlx a2)
{
	return a1.d<a2.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//不会做！！！救命！！！我要死了！！！
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=sum1=sum2=sum3=0;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++)
		{
			long long maxxx=max(max(a[i].x,a[i].y),a[i].z);
			maxx+=maxxx;
			if(maxxx==a[i].x) 
			{
				a[i].vis=1;
				sum1++;
			}
			else if(maxxx==a[i].y) 
			{
				a[i].vis=2;
				sum2++;
			}
			else if(maxxx==a[i].z) 
			{
				a[i].vis=3;
				sum3++;
			}
		}
		//cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<maxx<<endl;
		if(sum1>n/2)
		{
			for(int i=1;i<=n;i++)
				a[i].d=a[i].x-max(a[i].y,a[i].z);
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=sum1-n/2;i++)
				if(a[i].vis==1)
					maxx-=a[i].d;
				else
					sum1++;
		}
		else if(sum2>n/2)
		{
			for(int i=1;i<=n;i++)
				a[i].d=a[i].y-max(a[i].x,a[i].z);
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=sum2-n/2;i++)
				if(a[i].vis==2)
					maxx-=a[i].d;
				else
					sum2++;
		}
		else if(sum3>n/2)
		{
			for(int i=1;i<=n;i++)
				a[i].d=a[i].z-max(a[i].x,a[i].y);
			sort(a+1,a+n+1,cmp);
			//for(int i=1;i<=n;i++) cout<<a[i].d<<" ";
			//cout<<endl;
			for(int i=1;i<=sum3-n/2;i++)
				if(a[i].vis==3)
					maxx-=a[i].d;
				else
					sum3++;
		}
		cout<<maxx<<endl;
		//dfs(1);
	}
	return 0;
}