#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	bool f;
};
bool cmp(const int &a,const int &b){
	return a>b;
}
bool cmpx(const node &a,const node &b){
	return a.x>b.x;
}
bool cmpy(const node &a,const node &b){
	return a.y>b.y;
}
bool cmpz(const node &a,const node &b){
	return a.z>b.z;
}
node a[100005];
int x[100005],y[100005],z[100005];
int t,n,hn,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		hn=n/2;
		for(int i=1;i<=n;i++) a[i].x=0,a[i].y=0,a[i].z=0,a[i].f=false;
		if(n==2)
		{
			cin>>a[1].x>>a[1].y>>a[1].z;
			cin>>a[2].x>>a[2].y>>a[2].z;
			int sum1=max(a[1].x+a[2].y,a[1].x+a[2].z),sum2=max(a[1].y+a[2].x,a[1].y+a[2].z);
			int sum3=max(a[1].z+a[2].y,a[1].z+a[2].x);
			sum=max(sum1,max(sum2,sum3));
			cout<<sum<<endl;
			continue;
		}
		else if(n==4)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i].x>>a[i].y>>a[i].z;
				x[i]=a[i].x,y[i]=a[i].y,z[i]=a[i].z;
			}
			sort(x+1,x+n+1,cmp),sort(y+1,y+n+1,cmp),sort(z+1,z+n+1,cmp);
			int xx=0,yy=0,zz=0;
			for(int i=1;i<=hn;i++)
			{
				xx+=x[i],yy+=y[i],zz+=z[i];
			}
			if(xx>yy && (yy>=zz || xx>zz))
			{
				sum+=xx;
				sort(a+1,a+n+1,cmpx);
				for(int i=1;i<=hn;i++) a[i].f=true;
				int smf=y[1]+z[1];
				int smy=0,smz=0;
				sort(a+1,a+n+1,cmpy);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smy+=a[i].y;
				}
				sort(a+1,a+n+1,cmpz);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smz+=a[i].z;
				}
				sum=max(sum+smf,max(sum+smy,sum+smz));
				cout<<sum<<endl;
				continue;
			}
			else if(yy>xx && (xx>=zz || yy>zz))
			{
				sum+=yy;
				sort(a+1,a+n+1,cmpy);
				for(int i=1;i<=hn;i++) a[i].f=true;
				int smf=x[1]+z[1];
				int smx=0,smz=0;
				sort(a+1,a+n+1,cmpx);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smx+=a[i].x;
				}
				sort(a+1,a+n+1,cmpz);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smz+=a[i].z;
				}
				sum=max(sum+smf,max(sum+smx,sum+smz));
				cout<<sum<<endl;
				continue;
			}
			else if(zz>xx && (xx>=yy || zz>yy))
			{
				sum+=zz;
				sort(a+1,a+n+1,cmpz);
				for(int i=1;i<=hn;i++) a[i].f=true;
				int smf=x[1]+y[1];
				int smx=0,smy=0;
				sort(a+1,a+n+1,cmpx);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smx+=a[i].x;
				}
				sort(a+1,a+n+1,cmpy);
				for(int i=1,r=hn;i<=r;i++)
				{
					if(a[i].f) {
						r++;
						continue;
					}
					smy+=a[i].y;
				}
				sum=max(sum+smf,max(sum+smx,sum+smy));
				cout<<sum<<endl;
				continue;
			}
		}
	}
	return 0;
}
