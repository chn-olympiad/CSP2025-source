#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T;
int n;
int anss;
struct node{
	int tp1,tp2,tp3;
}q[N];
bool cmp(node x,node y)
{
	int a[5],b[5];
	a[1]=x.tp1,a[2]=x.tp2,a[3]=x.tp3;
	b[1]=y.tp1,b[2]=y.tp2,b[3]=y.tp3;
	sort(a+1,a+1+3),sort(b+1,b+1+3);
	if(a[3]!=b[3])	return a[3]>b[3];
	if(a[2]!=b[2])	return a[2]>b[2];
	return a[1]>b[1];
}
int tot[N],ans;
int tot1,tot2,tot3;
void dfs(int x,int tot1,int tot2,int tot3)
{
	if(x==n+1)
	{
		int res=0;
		for(int i=1;i<=n;i++)	res+=tot[i];
//		if(res==147325)
//		{
//			sort(tot+1,tot+1+n);
//			for(int i=1;i<=n;i++)	cout<<tot[i]<<' ';
//			cout<<'\n';
//		}
		ans=max(ans,res);
	}
	if(tot1<n/2)	tot[x]=q[x].tp1,dfs(x+1,tot1+1,tot2,tot3);
	if(tot2<n/2)	tot[x]=q[x].tp2,dfs(x+1,tot1,tot2+1,tot3);
	if(tot3<n/2)	tot[x]=q[x].tp3,dfs(x+1,tot1,tot2,tot3+1);
}
int gettp(int x)
{
	int maxx=max(q[x].tp1,max(q[x].tp2,q[x].tp3));
	if(maxx==q[x].tp1)	return 1;
	if(maxx==q[x].tp2)	return 2;
	if(maxx==q[x].tp3)	return 3;
}
bool cmp2(node x,node y)
{
	return x.tp1>y.tp1;
}
void workall()
{
	tot1=tot2=tot3=0;
	for(int i=1;i<=n;i++)
	{
		int tp=gettp(i);
		if(tp==1)
		{
			if(tot1<n/2)	tot1++,anss+=q[i].tp1;
			else
			{
				if(q[i].tp2<q[i].tp3)
				{
					if(tot3<n/2)	tot3++,anss+=q[i].tp3;
					else			tot2++,anss+=q[i].tp2;
				}
				else
				{
					if(tot2<n/2)	tot2++,anss+=q[i].tp2;
					else			tot3++,anss+=q[i].tp3;
				}
			}
		}
		if(tp==2)
		{
			if(tot2<n/2)	tot2++,anss+=q[i].tp2;
			else
			{
				if(q[i].tp1<q[i].tp3)
				{
					if(tot3<n/2)	tot3++,anss+=q[i].tp3;
					else			tot1++,anss+=q[i].tp1;
				}
				else
				{
					if(tot1<n/2)	tot1++,anss+=q[i].tp1;
					else			tot3++,anss+=q[i].tp3;
				}
			}
		}
		if(tp==3)
		{
			if(tot3<n/2)	tot3++,anss+=q[i].tp3;
			else
			{
				if(q[i].tp2<q[i].tp1)
				{
					if(tot1<n/2)	tot1++,anss+=q[i].tp1;
					else			tot2++,anss+=q[i].tp2;
				}
				else
				{
					if(tot2<n/2)	tot2++,anss+=q[i].tp2;
					else			tot1++,anss+=q[i].tp1;
				}
			}
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		tot1=tot2=tot3=0;
		bool subA=1,subB=1;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)	
		{
			cin>>q[i].tp1>>q[i].tp2>>q[i].tp3;
			if(q[i].tp2!=0||q[i].tp3!=0)	subA=0;
			if(q[i].tp3!=0)					subB=0;
		}
		if(subA)
		{
			sort(q+1,q+1+n,cmp2);
			int res=0;
			for(int i=1;i<=n/2;i++)	res+=q[i].tp1;
			cout<<res<<'\n';
			continue;
		}
		if(n<=30)
		{
			sort(q+1,q+1+n,cmp2); 
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		anss=0;
		for(int i=1;i<=n;i++)
		{
			int tp=gettp(i);
			if(tp==1)
			{
				if(tot1<n/2)	tot1++,ans+=q[i].tp1;
				else
				{
					if(q[i].tp2<q[i].tp3)
					{
						if(tot3<n/2)	tot3++,ans+=q[i].tp3;
						else			tot2++,ans+=q[i].tp2;
					}
					else
					{
						if(tot2<n/2)	tot2++,ans+=q[i].tp2;
						else			tot3++,ans+=q[i].tp3;
					}
				}
			}
			if(tp==2)
			{
				if(tot2<n/2)	tot2++,ans+=q[i].tp2;
				else
				{
					if(q[i].tp1<q[i].tp3)
					{
						if(tot3<n/2)	tot3++,ans+=q[i].tp3;
						else			tot1++,ans+=q[i].tp1;
					}
					else
					{
						if(tot1<n/2)	tot1++,ans+=q[i].tp1;
						else			tot3++,ans+=q[i].tp3;
					}
				}
			}
			if(tp==3)
			{
				if(tot3<n/2)	tot3++,ans+=q[i].tp3;
				else
				{
					if(q[i].tp2<q[i].tp1)
					{
						if(tot1<n/2)	tot1++,ans+=q[i].tp1;
						else			tot2++,ans+=q[i].tp2;
					}
					else
					{
						if(tot2<n/2)	tot2++,ans+=q[i].tp2;
						else			tot1++,ans+=q[i].tp1;
					}
				}
			}
		}
		workall();
		cout<<max(ans,anss)<<'\n';
	}
	return 0;
}