#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int x,y,z; 
}a[N];
struct point{
	int x,id;
}b[N];
bool cmp(point p,point q)
{
	return p.x<q.x;
}
int bl[N];
int tong[5];
int qiu(int x,int y,int z)
{
	int mx=max(x,max(y,z)),mi=min(x,min(y,z));
	if(x!=mx&&x!=mi) return x;
	if(y!=mx&&y!=mi) return y;
	if(z!=mx&&z!=mi) return z;
	if(x==y) return x;
	if(x==z) return x;
	if(y==z) return y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=3;i++) tong[i]=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[i]={0,0};
			bl[i]=0; 
		}
		long long ans=0;
		for(int i=1;i<=n;i++) ans+=max(a[i].x,max(a[i].y,a[i].z));
		for(int i=1;i<=n;i++)
		{
			int mx=max(a[i].x,max(a[i].y,a[i].z)),mi=min(a[i].x,min(a[i].y,a[i].z));
			if(a[i].x>a[i].y&&a[i].x>a[i].z) bl[i]=1,tong[1]++;
			if(a[i].y>a[i].x&&a[i].y>a[i].z) bl[i]=2,tong[2]++;
			if(a[i].z>a[i].x&&a[i].z>a[i].y) bl[i]=3,tong[3]++;
			else
			{
				if(a[i].x==mx&&a[i].y==mx) 
				{
					if(tong[1]>tong[2]) bl[i]=2,tong[2]++;
					else bl[i]=1,tong[1]++;
				}
				else if(a[i].x==mx&&a[i].z==mx)
				{
					if(tong[1]>tong[3]) bl[i]=3,tong[3]++;
					else bl[i]=1,tong[1]++;
				} 
				else if(a[i].y==mx&&a[i].z==mx)
				{
					if(tong[2]>tong[3]) bl[3]=1,tong[3]++;
					else bl[i]=2,tong[2]++;
				} 
			}
			int mid=qiu(a[i].x,a[i].y,a[i].z);
			b[i]={mx-mid,bl[i]};
		}
		sort(b+1,b+1+n,cmp);
		if(tong[1]<=n/2&&tong[2]<=n/2&&tong[3]<=n/2) cout<<ans<<endl;
		else
		{
			if(tong[1]>n/2)
			{
				int x=tong[1]-n/2;
				int cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(b[i].id==1) 
					{
						cnt++;
						ans-=b[i].x;
						if(cnt==x) break;
					}
				}
				cout<<ans<<endl;
			}
			if(tong[2]>n/2)
			{
				int x=tong[2]-n/2;
				int cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(b[i].id==2) 
					{
						cnt++;
						ans-=b[i].x;
						if(cnt==x) break;
					}
				}
				cout<<ans<<endl;
			}
			if(tong[3]>n/2)
			{
				int x=tong[3]-n/2;
				int cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(b[i].id==3) 
					{
						cnt++;
						ans-=b[i].x;
						if(cnt==x) break;
					}
				}
				cout<<ans<<endl;
			}
		}
	} 
	return 0;
}

