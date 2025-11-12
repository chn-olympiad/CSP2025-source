#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c[4],mid,dis[4],ma,ans,midd,t,ddd[100001];

struct node{
	int a,b,c,ac,bc,cb,ca,ba,ab,x;
}a[100001];

struct fff{
	int z,q,x;
}d[200004];

bool emp(fff xx,fff yy){
	return xx.z >yy.z ;
}


signed main() 
{
		freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
	for(int i=1;i<=n;i++)
	{
		
		ddd[i]=0;
	}
	dis[1]=0;
	dis[2]=0;
	dis[3]=0;
	c[1]=0;
	c[2]=0;
	c[3]=0;
		cin>>n;
		ma=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].x=i;
			a[i].ab=a[i].b-a[i].a;
			a[i].ba=0-a[i].ab;
			a[i].ac=a[i].c-a[i].a;
			a[i].ca=0-a[i].ac;
			a[i].bc=a[i].c-a[i].b;
			a[i].cb=0-a[i].bc;
			c[1]+=a[i].a;
			c[2]+=a[i].b;
			c[3]+=a[i].c;
		}
		
		mid=0;
		if(c[3]>=c[2]&&c[3]>=c[1])
		{
			ans=c[3];
			for(int i=1;i<=n;i++)
			{
				mid++;
				d[mid].z=a[i].cb;
				d[mid].q=2;
				d[mid].x=i;
				mid++;
				d[mid].z=a[i].ca;
				d[mid].q=1;
				d[mid].x=i;
			}
			sort(d+1,d+mid+1,emp);
			for(int i=1;i<=ma;i++)
			{
				if(ddd[d[i].x ]==0){
				ddd[d[i].x ]=1;
				ans+=d[i].z;
				dis[d[i].q]++;
			}
			else{
			ma++;
		}
			}
			midd=ma+1;
			while(d[midd].z>0){
				if(dis[midd]<ma&&ddd[d[midd].x ]==0){
					ddd[d[midd].x ]=1;
					ans+=d[midd].z;
					dis[d[midd].q]++;
				}
				midd++;
			}
			cout<<ans<<endl;	
			continue;
		}
		
		if(c[2]>=c[1]&&c[2]>=c[3])
		{
			ans=c[2];
			for(int i=1;i<=n;i++)
			{
				mid++;
				d[mid].z=a[i].bc;
				d[mid].q=3;
				d[mid].x=i;
				mid++;
				d[mid].z=a[i].ba;
				d[mid].q=1;
				d[mid].x=i;
			}
			sort(d+1,d+mid+1,emp);
			for(int i=1;i<=ma;i++)
			{
				if(ddd[d[i].x ]==0){
				ddd[d[i].x ]=1;
				ans+=d[i].z;
				dis[d[i].q]++;
			}
			else
			ma++;
			}
			midd=ma+1;
			while(d[midd].z>0){
				if(dis[midd]<ma&&ddd[d[midd].x ]==0){
					ddd[d[midd].x ]=1;
					ans+=d[midd].z;
					dis[d[midd].q]++;
				}
				midd++;
			}
			cout<<ans<<endl;	
			continue;
		}
		
		if(c[1]>=c[2]&&c[1]>=c[3])
		{
			ans=c[1];
			for(int i=1;i<=n;i++)
			{
				mid++;
				d[mid].z=a[i].ab;
				d[mid].q=2;
				d[mid].x=i;
				mid++;
				d[mid].z=a[i].ac;
				d[mid].q=3;
				d[mid].x=i;
			}
			sort(d+1,d+mid+1,emp);
			for(int i=1;i<=ma;i++)
			{
				if(ddd[d[i].x ]==0){
				ddd[d[i].x ]=1;
				ans+=d[i].z;
				dis[d[i].q]++;
			}
			else
		ma++;
		}
			midd=ma+1;
			while(d[midd].z>0){
				if(dis[midd]<ma&&ddd[d[midd].x ]==0){
					ddd[d[midd].x ]=1;
					ans+=d[midd].z;
					dis[d[midd].q]++;
				}
				midd++;
			}
			cout<<ans<<endl;	
			continue;
		}
	}
	return 0;
}






