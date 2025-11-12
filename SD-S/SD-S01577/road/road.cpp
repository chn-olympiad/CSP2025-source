#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e4+10;
const int M=3e6+10;
int ff,cnt,ans,nn,mm,s[N],n,m,k,f[N],b[N];
struct node{
	int x,y,z,id;
}a[M];
int read()
{
	int sss=0,fff=1;
	char xxx=getchar();
	while(xxx<'0'||xxx>'9'){if(xxx=='-')fff=-1;xxx=getchar();}
	while(xxx>='0'&&xxx<='9'){
		sss=sss*10+xxx-'0';
		xxx=getchar();
	}
	return sss*fff;
}
bool cmp(node aa,node bb){return aa.z<bb.z||aa.z==bb.z&&aa.id<bb.id;}
int fnd(int sx){if(f[sx]==sx)return sx;return f[sx]=fnd(f[sx]);}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();nn=n,mm=m;
	for(int i=1;i<=m;i++)
		a[i].x=read(),a[i].y=read(),a[i].z=read(),a[i].id=i;
	for(int i=1;i<=k;i++)
	{
		if(s[i]!=0)ff=1;
		scanf("%d",&s[i]);
		int hh[N];
		for(int j=1;j<=n;j++)scanf("%d",&hh[j]);
		for(int j=1;j<=n;j++)
		for(int jj=j+1;jj<=n;jj++)
			a[++mm].x=j,a[mm].y=jj,a[mm].z=hh[j]+hh[jj]+s[i],a[mm].id=mm;
	}
	if(k==0)
	{
		for(int i=1;i<=nn;i++)f[i]=i;
		sort(a+1,a+mm+1,cmp);
		for(int i=1;i<=mm;i++)
		{
			int ux=fnd(a[i].x);
			int uy=fnd(a[i].y);
			if(ux!=uy)
			{
				f[ux]=uy;
				if(!b[a[i].id])ans+=s[i],b[a[i].id]=1;
				ans+=a[i].z;
			}
		}  
		printf("%d",ans);
		return 0;
	}
	if(ff==0)
	{
		printf("0");
		return 0;;
	}
	for(int i=1;i<=nn;i++)f[i]=i;
	sort(a+1,a+mm+1,cmp);
	for(int i=1;i<=mm;i++)
	{
		int ux=fnd(a[i].x);
		int uy=fnd(a[i].y);
		if(ux!=uy)
		{
			f[ux]=uy;
			ans+=a[i].z;
			if(a[i].id>m&&!b[a[i].id])
			{
				for(int j=i;j<=mm;j++)
				if(a[j].id>m)a[j].z-=s[a[j].id-m];
				b[a[i].id]=1;
				sort(a+1,a+mm+1,cmp);
				i=1;
			}
			
		}
	}  
	printf("%d",ans);
 	return 0;
}

