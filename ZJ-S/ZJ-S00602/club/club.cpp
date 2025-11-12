#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
struct Node
{
	int x,y,z,xx,yy,cha,ma;
}a[M];
bool cmp(Node aa,Node bb)
{
	return aa.cha<bb.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,ans=0,k=0,chao;
		scanf("%d",&n);
		int s1=n/2,s2=n/2,s3=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].xx=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].xx==a[i].x)a[i].yy=max(a[i].y,a[i].z),s1--,a[i].ma=1;
			if(a[i].xx==a[i].y)a[i].yy=max(a[i].x,a[i].z),s2--,a[i].ma=2;
			if(a[i].xx==a[i].z)a[i].yy=max(a[i].x,a[i].y),s3--,a[i].ma=3;
			a[i].cha=a[i].xx-a[i].yy,ans+=a[i].xx;
		}
		sort(a+1,a+1+n,cmp);
		if(s1<0)k-=s1,chao=1;
		if(s2<0)k-=s2,chao=2;
		if(s3<0)k-=s3,chao=3;
		for(int i=1;i<=k;i++)
			if(a[i].ma==chao)ans-=a[i].cha;
			else k++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			a[i].x=0,a[i].y=0,a[i].z=0,a[i].xx=0,a[i].yy=0,a[i].cha=0,a[i].ma=0;
	}
	return 0;
}
