#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
struct stu
{
	int s[3],maxx=0,scd=1,minn=2;
}d[maxn+10];
int t,n,a[maxn+10],b[maxn+10],c[maxn+10],anum,bnum,cnum,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		anum=0;
		bnum=0;
		cnum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i].s[0]>>d[i].s[1]>>d[i].s[2];
			int k=0;
			for(int j=0;j<=2;j++)
			{
				if(k<d[i].s[j])
				{
					k=d[i].s[j];
					d[i].maxx=j;
				}
			}
			k=d[i].s[0];
			for(int j=0;j<=2;j++)
			{
				if(k>d[i].s[j])
				{
					k=d[i].s[j];
					d[i].minn=j;
				}
			}
			for(int j=0;j<=2;j++)if(j!=d[i].maxx&&j!=d[i].minn)d[i].scd=j;
			if(d[i].maxx==0)a[++anum]=i;
			if(d[i].maxx==1)b[++bnum]=i;
			if(d[i].maxx==2)c[++cnum]=i;
		}
		bool f=true;
		while(f)
		{
			f=false;
			bool flag=false;
			for(int i=anum+1;i<=n/2;i++)
			{
				f=true;
				flag=true;
				--anum;
				if(d[a[i]].scd==1)b[++bnum]=a[i];
				if(d[a[i]].scd==2)c[++cnum]=a[i];
			}
			if(flag)sort(a+1,a+1+anum);
			flag=false;
			for(int i=bnum+1;i<=n/2;i++)
			{
				f=true;
				flag=true;
				--bnum;
				if(d[b[i]].scd==0)a[++anum]=b[i];
				if(d[b[i]].scd==2)c[++cnum]=b[i];
			}
			if(flag)sort(b+1,b+1+bnum);
			flag=false;
			for(int i=cnum+1;i<=n/2;i++)
			{
				f=true;
				flag=true;
				--cnum;
				if(d[c[i]].scd==0)a[++anum]=c[i];
				if(d[c[i]].scd==1)b[++bnum]=c[i];
			}
			if(flag)sort(c+1,c+1+cnum);
			if(f)
			{
				for(int i=anum+1;i<=n/2;i++)
				{
					f=true;
					flag=true;
					--anum;
					if(d[a[i]].minn==1)b[++bnum]=a[i];
					if(d[a[i]].minn==2)c[++cnum]=a[i];
				}
				if(flag)sort(a+1,a+1+anum);
				flag=false;
				for(int i=bnum+1;i<=n/2;i++)
				{
					f=true;
					flag=true;
					--bnum;
					if(d[b[i]].minn==0)a[++anum]=b[i];
					if(d[b[i]].minn==2)c[++cnum]=b[i];
				}
				if(flag)sort(b+1,b+1+bnum);
				flag=false;
				for(int i=cnum+1;i<=n/2;i++)
				{
					f=true;
					flag=true;
					--cnum;
					if(d[c[i]].minn==0)a[++anum]=c[i];
					if(d[c[i]].minn==1)b[++bnum]=c[i];
				}
				if(flag)sort(c+1,c+1+cnum);
			}
		}
		for(int i=1;i<=anum;i++)ans+=d[a[i]].s[0];
		for(int i=1;i<=bnum;i++)ans+=d[b[i]].s[1];
		for(int i=1;i<=cnum;i++)ans+=d[c[i]].s[2];
		cout<<ans<<endl;
	}
	return 0;
}