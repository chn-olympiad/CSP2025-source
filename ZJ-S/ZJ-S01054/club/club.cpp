#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+10;

struct node
{
	int cnt1,cnt2,num;
};

int a[N][10];
int c[N][10];
int x[N],y[N],z[N];

bool cmp(node v,node vv)
{
	if(max(v.cnt1,v.cnt2)==max(v.cnt1,v.cnt2))
		return min(v.cnt1,v.cnt2)>min(v.cnt1,v.cnt2);
	return max(v.cnt1,v.cnt2)>max(v.cnt1,v.cnt2);
}

void solve()
{
	int n;
	cin>>n;
	int ans=0;
	int numx=0,numy=0,numz=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		c[i][1]=a[i][2]-a[i][1],c[i][2]=a[i][3]-a[i][2],c[i][3]=a[i][1]-a[i][3];
		if(a[i][1]>a[i][2])
			if(a[i][1]>a[i][3]) ans+=a[i][1],x[++numx]=i;
			else ans+=a[i][3],z[++numz]=i;
		else if(a[i][2]>a[i][3]) ans+=a[i][2],y[++numy]=i;
			else ans+=a[i][3],z[++numz]=i;
	}
	while(1)
	{
		int anss=ans;
		if(numx>n/2)
		{
			node f[N];
			for(int i=1;i<=numx;i++)
				f[i].cnt1=c[x[i]][1],f[i].cnt2=-c[x[i]][3],f[i].num=x[i];
			sort(f+1,f+numx+1,cmp);
			for(int i=1;i<=numx-n/2;i++)
			{
				if(f[x[i]].cnt1>f[x[i]].cnt2)
					y[++numy]=x[i],ans+=f[i].cnt1;
				else z[++numz]=x[i],ans+=f[i].cnt2;
			}
			numx=n/2;
		}
		if(numy>n/2)
		{
			node f[N];
			for(int i=1;i<=numy;i++)
				f[i].cnt1=c[y[i]][2],f[i].cnt2=-c[y[i]][1],f[i].num=y[i];
			sort(f+1,f+numy+1,cmp);
			for(int i=1;i<=numy-n/2;i++)
			{
				if(f[y[i]].cnt1>f[y[i]].cnt2)
					z[++numz]=y[i],ans+=f[i].cnt1;
				else x[++numx]=y[i],ans+=f[i].cnt2;
			}
			numy=n/2;
		}
		if(numz>n/2)
		{
			node f[N];
			for(int i=1;i<=numz;i++)
				f[i].cnt1=c[z[i]][3],f[i].cnt2=-c[z[i]][2],f[i].num=z[i];
			sort(f+1,f+numz+1,cmp);
			for(int i=1;i<=numz-n/2;i++)
			{
				if(f[z[i]].cnt1>f[z[i]].cnt2)
					x[++numy]=x[i],ans+=f[i].cnt1;
				else y[++numz]=y[i],ans+=f[i].cnt2;
			}
			numz=n/2;
		}
		if(anss==ans) break;
		if(numx<=n/2&&numy<=n/2&&numz<=n/2) break;
	}
	if(numx>n/2)
	{
		node f[N];
		for(int i=1;i<=numx;i++)
			f[i].cnt1=c[x[i]][1],f[i].cnt2=-c[x[i]][3],f[i].num=x[i];
		sort(f+1,f+numx+1,cmp);
		for(int i=1;i<=numx-n/2;i++)
			if(numy<n/2&&numz<n/2)
				if(f[x[i]].cnt1>f[x[i]].cnt2)
					y[++numy]=x[i],ans+=f[i].cnt1;
				else z[++numz]=x[i],ans+=f[i].cnt2;
			else if(numy<n/2)
				y[++numy]=x[i],ans+=f[i].cnt1;
			else z[++numz]=x[i],ans+=f[i].cnt2;
		
	}
	if(numy>n/2)
	{
		node f[N];
		for(int i=1;i<=numy;i++)
			f[i].cnt1=c[y[i]][2],f[i].cnt2=-c[y[i]][1],f[i].num=y[i];
		sort(f+1,f+numy+1,cmp);
		for(int i=1;i<=numy-n/2;i++)
			if(numx<n/2&&numz<n/2)
				if(f[x[i]].cnt1>f[x[i]].cnt2)
					z[++numz]=y[i],ans+=f[i].cnt1;
				else x[++numx]=y[i],ans+=f[i].cnt2;
			else if(numz<n/2)
				z[++numz]=y[i],ans+=f[i].cnt1;
			else x[++numx]=y[i],ans+=f[i].cnt2;
	}
	if(numz>n/2)
	{
		node f[N];
		for(int i=1;i<=numz;i++)
			f[i].cnt1=c[z[i]][3],f[i].cnt2=-c[z[i]][2],f[i].num=z[i];
		sort(f+1,f+numz+1,cmp);
		for(int i=1;i<=numz-n/2;i++)
			if(numx<n/2&&numy<n/2)
				if(f[z[i]].cnt1>f[z[i]].cnt2)
					x[++numx]=z[i],ans+=f[i].cnt1;
				else y[++numy]=z[i],ans+=f[i].cnt2;
			else if(numx<n/2)
				x[++numx]=z[i],ans+=f[i].cnt1;
			else y[++numy]=z[i],ans+=f[i].cnt2;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
