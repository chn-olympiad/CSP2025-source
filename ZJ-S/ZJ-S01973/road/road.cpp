#include<bits/stdc++.h>
using namespace std;
long long fa[114511],n,m,k,ans=1e9;
long long lt[11][114511];
bool ad[11];
struct road
{
	long long a,b,c;
}r[1145141],r1[1145141],r2[1145141];
long long fat(long long i)
{
	if(fa[i]!=i)fa[i]=fat(fa[i]);
	return fa[i];
}
bool cmp(road x,road y)
{
	return x.a<y.a;
}
bool f(long long j)
{
	if(j==k)
	{
		long long an=0,sum=m,n1=n;
		for(long long i=1;i<=k;i++)
		{
			if(ad[i]==1)
			{
				++n1;
				an+=lt[i][0];
				for(long long j=1;j<=n;j++)
				{	
					r1[++sum].a=lt[i][j];
					r1[sum].b=n1;
					r1[sum].c=j;
				}
			}
		}
		for(long long i=0;i<=n1;i++)
		{
			fa[i]=i;
		}
		for(long long i=1;i<=sum;i++)
		{
			r2[i]=r1[i];
		}
		sort(r2+1,r2+1+sum,cmp);
//		for(long long i=1;i<=20;i++)
//		{
//			cout<<r2[i].c<<r2[i].b<<r2[i].a<<endl;
//		}	
		long long tot=1;
		for(long long i=1;i<=sum;i++)
		{
			if(fat(r2[i].b)!=fat(r2[i].c))
			{
//				if(ad[1]==1&&ad[2]==0)
//				{
//					cout<<fat(r2[i].b)<<' '<<fat(r2[i].c)<<' '<<r2[i].a<<' '<<an<<endl;
//				}
				fa[fat(r2[i].b)]=fat(r2[i].c);
				an+=r2[i].a;
				tot++;
			}
			if(tot==n1) break;
		}
	//	cout<<ad[1]<<' '<<ad[2]<<' '<<an<<endl;
		ans=min(ans,an);
		return 0;
	}
	j++;
	f(j);
	ad[j]=1;
	f(j);
	ad[j]=0;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>r[i].c>>r[i].b>>r[i].a;
		r1[i].c=r[i].c;
		r1[i].a=r[i].a;
		r1[i].b=r[i].b;
	}
	
	long long fl1=0;
	for(long long i=1;i<=k;i++)
	{
		long long fl=0;	
		for(long long j=0;j<=n;j++)
		{
			cin>>lt[i][j];
			if(lt[i][j]!=0) fl=1;
		}
		if(fl==0)fl1=1;
	}
	if(fl1==1)
	{
		cout<<0;
		return 0;
	}
	f(0);
	cout<<ans;
	return 0;
}



