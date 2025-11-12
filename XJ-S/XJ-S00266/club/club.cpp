#include<bits/stdc++.h>
using namespace std;
struct node1{
	int y1,r1,s1,zh,cd,zx,cz;
}a[200005];
bool cmp(node1 a,node1 b)
{
	return a.zh>b.zh;
}
bool cmp1(int a1,int b1)
{
	return a1<b1;
}
struct node{
	int wz,val;
}y[100005],r[100005],s[100005]; 
int yyy[100005],rrr[100005],sss[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int j=1;j<=T;j++)
	{
		int n;
		cin>>n;
		long long qweqwe=0;
		int yy=0,rr=0,ss=0,yyr=0,yys=0,rrs=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].y1>>a[i].r1>>a[i].s1;
//			if(a[i].y1<=a[i].r1)cout<<"*"<<i<<'\n';
			a[i].zh=max(max(a[i].y1,a[i].r1),a[i].s1);
			a[i].zx=min(min(a[i].y1,a[i].r1),a[i].s1);
//			if(a[i].y1!=a[i].zh&&a[i].y1!=a[i].zx) a[i].cd=a[i].y1;
//			else if(a[i].r1!=a[i].zh&&a[i].r1!=a[i].zx) a[i].cd=a[i].r1;
//			else if(a[i].s1!=a[i].zh&&a[i].s1!=a[i].zx) a[i].cd=a[i].s1;
			int zd=-1e9,cd1=-1e9,ccd=-1e9;
			if(zd<a[i].y1)
			zd=a[i].y1;
			if(zd<a[i].r1)
			zd=a[i].r1,cd1=a[i].y1;
			else
			cd1=a[i].r1;
			if(zd<a[i].s1)
			{
				cd1=zd;
			}
			else
			{
				if(a[i].s1>cd1)
				cd1=a[i].s1;
			}
			a[i].cd=cd1;
			a[i].cz=a[i].zh-cd1;
//			cout<<i<<" "<<a[i].zh<<" "<<cd1<<" "<<a[i].cz<<endl;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].y1>a[i].r1&&a[i].y1>a[i].s1)
			{
				y[++yy].wz=i;
				y[yy].val=a[i].y1;
				qweqwe+=a[i].y1;
				yyy[yy]=a[i].cz;
			}
			else if(a[i].r1>a[i].y1&&a[i].r1>a[i].s1)
			{
				r[++rr].wz=i;
				r[rr].val=a[i].r1;
				qweqwe+=a[i].r1;
				rrr[rr]=a[i].cz;
			}
			else if(a[i].s1>a[i].r1&&a[i].s1>a[i].y1)
			{
				s[++ss].wz=i;
				s[ss].val=a[i].s1;
				qweqwe+=a[i].s1;
				sss[ss]=a[i].cz;
			}
			else if(a[i].r1==a[i].y1&&a[i].r1==a[i].s1)
			{
				qweqwe+=a[i].r1;
			}
			else if(a[i].r1==a[i].y1&&a[i].y1>a[i].s1)
			{
				y[++yy].wz=i;
				y[yy].val=a[i].y1;
				qweqwe+=a[i].y1;
				yyy[yy]=a[i].cz;
			}
			else if(a[i].s1==a[i].y1&&a[i].y1>a[i].r1)
			{
				y[++yy].wz=i;
				y[yy].val=a[i].y1;
				qweqwe+=a[i].y1;
				yyy[yy]=a[i].cz;
			}
			else if(a[i].r1==a[i].s1&&a[i].r1>a[i].y1)
			{
				r[++rr].wz=i;
				r[rr].val=a[i].r1;
				qweqwe+=a[i].r1;
				rrr[rr]=a[i].cz;
			}
		//	cout<<qweqwe<<'\n';
		}
		if(yy>n/2)
		{
			sort(yyy+1,yyy+1+yy,cmp1);
//			for(int i=1;i<=yy;i++)
//			cout<<i<<" "<<yyy[i]<<'\n';
//			cout<<"))))"<<endl;
			for(int i=1;i<=yy-n/2;i++)
			{
				qweqwe-=yyy[i];
	//			cout<<i<<" "<<qweqwe<<endl;
			}
	//		cout<<endl;
		}
//		cout<<qweqwe<<'\n';
		if(rr>n/2)
		{
			sort(rrr+1,rrr+1+rr,cmp1);
			for(int i=1;i<=rr-n/2;i++)
			{
				qweqwe-=rrr[i];
			}
		}
//		cout<<qweqwe<<'\n';
		if(ss>n/2)
		{
			sort(sss+1,sss+1+ss,cmp1);
			for(int i=1;i<=ss-n/2;i++)
			{
				qweqwe-=sss[i];
			}
		}
		cout<<qweqwe<<'\n';
//		cout<<endl;
	}
	return 0;
}
