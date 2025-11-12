#include <bits/stdc++.h>
using namespace std;
int t,n;
bool p1,p2,p3,f[100005];
struct node
{
	int fi,se,th,ma,id;
};
node a[100005];
bool cmp1(node x,node y)
{
	return x.fi>y.fi;
}
bool cmp2(node x,node y)
{
	return x.se>y.se;
}
bool cmp3(node x,node y)
{
	return x.th>y.th;
}
int one1()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int one2()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int two1()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
			if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int two2()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
		sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int three1()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int three2()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (a[i].ma==3&&sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (a[i].ma==1&&sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
		sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (a[i].ma==2&&sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int one11()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int one21()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int two11()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int two21()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int three11()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
			else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int three21()
{
	int sum,sum1,sum2,sum3;
	bool p1,p2,p3;
	p1=p2=p3=0;
	sum=sum1=sum2=sum3=0;
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<=n;i++)
		if (sum3!=n/2&&f[a[i].id]==0) sum+=a[i].th,f[a[i].id]=1,sum3++;
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<=n;i++)
		if (sum1!=n/2&&f[a[i].id]==0) sum+=a[i].fi,f[a[i].id]=1,sum1++;
		sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=n;i++)
		if (sum2!=n/2&&f[a[i].id]==0) sum+=a[i].se,f[a[i].id]=1,sum2++;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]!=1)
		{
			int x,y,z,idx,idy,idz;
			x=a[i].fi;
			y=a[i].se;
			z=a[i].th;
			if (x>y&&x>z) idx=1;
			else if (x>y&&x<=z||x>z&&x<=y) idx=2;
			else idx=3;
			if (y>x&&y>z) idy=1;
			else if (y>x&&y<=z||y>z&&y<=x) idy=2;
			else idz=3;
			if (z>x&&z>y) idz=1;
			else if (z>x&&z<=y||z>y&&z<=x) idz=2;
			else idz=0;
			if (idx==1&&sum1<n/2||idx==2&&idy==1&&sum2>=n/2&&sum1<n/2||idx==2&&idz==1&&sum3>=n/2&&sum1<n/2||idx==3&&sum1<n/2&&sum2>=n/2&&sum3>=n/2) ans+=x,sum1++;
				else if (idy==1&&sum2<n/2||idy==2&&idx==1&&sum1>=n/2&&sum2<n/2||idy==2&&idz==1&&sum3>=n/2&&sum2<n/2||idy==3&&sum2<n/2&&sum1>=n/2&&sum3==n/2) ans+=y,sum2++;
			else if (idz==1&&sum3<n/2||idz==2&&idx==1&&sum1>=n/2&&sum3<n/2||idz==2&&idy==1&&sum2>=n/2&&sum3<n/2||idz==3&&sum3<n/2&&sum1>=n/2&&sum2==n/2) ans+=z,sum3++;
		}
	return sum+ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (int g=1;g<=t;g++)
	{
		p1=p2=p3=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].fi>>a[i].se>>a[i].th;
			if (a[i].fi>a[i].se&&a[i].fi>a[i].th) a[i].ma=1;
			else if (a[i].se>a[i].fi&&a[i].se>a[i].th) a[i].ma=2;
			else if (a[i].th>a[i].se&&a[i].fi<a[i].th) a[i].ma=3;
			a[i].id=i;
		}
		int x1=one1();
		for (int i=1;i<=n;i++) f[i]=0;
		int x2=one2();
		for (int i=1;i<=n;i++) f[i]=0;
		int y1=two1();
		for (int i=1;i<=n;i++) f[i]=0;
		int y2=two2();
		for (int i=1;i<=n;i++) f[i]=0;
		int z1=three1();
		for (int i=1;i<=n;i++) f[i]=0;
		int z2=three2();
		for (int i=1;i<=n;i++) f[i]=0;
		int x11=one11();
		for (int i=1;i<=n;i++) f[i]=0;
		int x21=one21();
		for (int i=1;i<=n;i++) f[i]=0;
		int y11=two11();
		for (int i=1;i<=n;i++) f[i]=0;
		int y21=two21();
		for (int i=1;i<=n;i++) f[i]=0;
		int z11=three11();
		for (int i=1;i<=n;i++) f[i]=0;
		int z21=three21();
		for (int i=1;i<=n;i++) f[i]=0;
		cout<<max(x11,max(x21,max(y11,max(y21,max(z11,max(z21,max(x1,max(x2,max(y1,max(y2,max(z1,z2)))))))))))<<endl;
	}
	return 0;
}
