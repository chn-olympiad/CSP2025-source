#include<bits/stdc++.h>
using namespace std;
struct qwq
{
	int x,y,z;
}a[200010];
int t,n,bo,k1,k2,s,mk,mx,b[200010],bo2,cnt,c[200010],cnt1,cnt2;
int cmp(qwq a,qwq b)
{
	return a.y-a.x>b.y-b.x;
}
int cmp2(int x,int y)
{
	return x>y;
}
void dfs(int k,int x1,int x2,int x3)
{
	if(x1>n/2||x2>n/2||x3>n/2) return;
	if(k==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1) sum+=a[i].x;
			if(b[i]==2) sum+=a[i].y;
			if(b[i]==3) sum+=a[i].z;
		}
		mx=max(mx,sum);
		return;
	}
	b[k]=1;
	dfs(k+1,x1+1,x2,x3);
	b[k]=2;
	dfs(k+1,x1,x2+1,x3);
	b[k]=3;
	dfs(k+1,x1,x2,x3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bo=bo2=0;mx=-1;s=0;cnt=0;cnt1=0;cnt2=0;
		for(int i=1;i<=100000;i++) c[i]=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			s+=a[i].x;
			if(a[i].z!=0||a[i].y!=0) bo=1;
			if(a[i].z!=0) bo2=1;
		}
		if(bo==0)
		{
			s=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) s+=a[i].x;
			cout<<s<<endl;
			continue;
		}
		else if(n<=10)
		{
			dfs(1,0,0,0);
			cout<<mx<<endl;
		}
		else if(bo2==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) s+=a[i].y-a[i].x;
			cout<<s<<endl;
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			//for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
			for(int i=1;i<=n/2;i++) s+=a[i].y-a[i].x;
			for(int i=1;i<=n/2;i++)
				if(a[i].z>a[i].y) {c[++cnt]=a[i].z-a[i].y;cnt1++;}
			for(int i=n/2+1;i<=n;i++)
				if(a[i].z>a[i].x) {c[++cnt]=a[i].z-a[i].x;cnt2++;}
			sort(c+1,c+cnt+1,cmp2);
			//cout<<cnt<<endl;
			//for(int i=1;i<=cnt;i++) cout<<c[i]<<" ";
			//cout<<endl;
			for(int i=1;i<=min(cnt,n/2);i++) s+=c[i];
			cout<<s<<endl;
		}
	}
	return 0;
}