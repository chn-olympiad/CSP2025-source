#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int s1,s2,s3,x;
};
node a[N],st1[N],st2[N],st3[N];
void solve()
{
	int n,m1=0,m2=0,m3=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].s1,&a[i].s2,&a[i].s3);
		a[i].x=i;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3) st1[m1+=1]=a[i],ans+=a[i].s1;
		else if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3) st2[m2+=1]=a[i],ans+=a[i].s2;
		else if(a[i].s3>=a[i].s1&&a[i].s3>=a[i].s2) st3[m3+=1]=a[i],ans+=a[i].s3;
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(a[i].s1>=a[i].s2&&a[i].s1>=a[i].s3)
		{
			if(m1<n/2) st1[m1+=1]=a[i],ans+=a[i].s1;
			else
			{
				int td_shi=1e9,td_de=a[i].s1,k,huan_shi,huan_de;
				if(a[i].s1-a[i].s2>a[i].s1-a[i].s3) huan_shi=a[i].s1-a[i].s3,huan_de=a[i].s3;
				else huan_shi=a[i].s1-a[i].s2,huan_de=a[i].s2;
				for(int j=1;j<=m1;j++)
				{
					if(td_shi>min(st1[j].s1-st1[j].s2,st1[j].s1-st1[j].s2)) k=j;
					td_shi=min(td_shi,min(st1[j].s1-st1[j].s2,st1[j].s1-st1[j].s2));
				}
				td_de-=td_shi;
				ans+=max(td_de,huan_de);
				if(td_de>huan_de) st1[k]=a[i];
			}
		}
		else if(a[i].s2>=a[i].s1&&a[i].s2>=a[i].s3)
		{
			if(m2<n/2) st2[m2+=1]=a[i],ans+=a[i].s2;
			else
			{
				int td_shi=1e9,td_de=a[i].s2,k,huan_shi,huan_de;
				if(a[i].s2-a[i].s1>a[i].s2-a[i].s3) huan_shi=a[i].s2-a[i].s3,huan_de=a[i].s3;
				else huan_shi=a[i].s2-a[i].s1,huan_de=a[i].s1;
				for(int j=1;j<=m2;j++)
				{
					if(td_shi>min(st2[j].s2-st2[j].s1,st2[j].s2-st2[j].s3)) k=j;
					td_shi=min(td_shi,min(st2[j].s2-st2[j].s1,st2[j].s2-st2[j].s3));
				}
				td_de-=td_shi;
				ans+=max(td_de,huan_de);
				if(td_de>huan_de) st2[k]=a[i];
			}
		}
		else if(a[i].s3>=a[i].s1&&a[i].s3>=a[i].s2)
		{
			if(m3<n/2) st3[m3+=1]=a[i],ans+=a[i].s3;
			else
			{
				int td_shi=1e9,td_de=a[i].s3,k,huan_shi,huan_de;
				if(a[i].s3-a[i].s1>a[i].s3-a[i].s2) huan_shi=a[i].s3-a[i].s2,huan_de=a[i].s2;
				else huan_shi=a[i].s3-a[i].s1,huan_de=a[i].s1;
				for(int j=1;j<=m3;j++)
				{
					if(td_shi>min(st3[j].s3-st3[j].s1,st3[j].s3-st3[j].s2)) k=j;
					td_shi=min(td_shi,min(st3[j].s3-st3[j].s1,st3[j].s3-st3[j].s2));
				}
				td_de-=td_shi;
				ans+=max(td_de,huan_de);
				if(td_de>huan_de) st3[k]=a[i];
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
