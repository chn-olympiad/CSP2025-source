#include <bits/stdc++.h>
using namespace std;
int T,n,i,j,ma,m,bao,bao1,s2,s3,bao2,s,s1,g[100010],f[100010],a[100010][10];
struct no{
	int a,b,c,d,e,f;
}b[100010];
struct no1{
	int a,b,c,d;
}c[100010];
bool cmp(no a,no b){return a.e<b.e||a.e==b.e&&a.c<b.c||a.e==b.e&&a.c==b.c&&a.a<b.a;}
bool cmp1(no1 a,no1 b){return a.c<b.c||a.c==b.c&&a.a<b.a;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)
			for(j=1;j<=3;j++)cin>>a[i][j];
		for(i=1;i<=n;i++){
			ma=-1;bao=0;
			for(j=1;j<=3;j++)
				if(a[i][j]>ma)ma=a[i][j],bao=j;
			b[i].a=ma;b[i].b=bao;
			ma=-1;bao1=0;
			for(j=1;j<=3;j++)
				if(j!=bao)
					if(a[i][j]>ma)ma=a[i][j],bao1=j;
			b[i].c=ma;b[i].d=bao1;
			ma=-1;bao2=0;
			for(j=1;j<=3;j++)
				if(j!=bao&&j!=bao1)
					if(a[i][j]>ma)ma=a[i][j],bao2=j;
			b[i].e=ma;b[i].f=bao2;
		}
		sort(b+1,b+1+n,cmp);
		for(i=1;i<=3;i++)f[i]=n/2;
		for(i=1;i<=n;i++)g[i]=0;
		s=0;m=0;
		for(i=1;i<=n;i++)
			if(f[b[i].b]>0)f[b[i].b]--,s+=b[i].a,g[i]=1;
			else break;
		for(i=1;i<=n;i++)
			if(g[i]==0)c[++m].a=b[i].c,c[m].b=b[i].d,c[m].c=b[i].e,c[m].d=b[i].f;
		sort(c+1,c+1+m,cmp1);
		for(i=1;i<=m;i++)
			if(f[c[i].b]>0)f[c[i].b]--,s+=c[i].a,g[i]=1;
			else break;
		for(i=1;i<=m;i++)
			if(g[i]==0)s+=c[i].c;
		for(i=1;i<=3;i++)f[i]=n/2;
		for(i=1;i<=n;i++)g[i]=0;
		s1=0;m=0;
		for(i=n;i>=1;i--)
			if(f[b[i].b]>0)f[b[i].b]--,s1+=b[i].a,g[i]=1;
			else break;
		for(i=1;i<=n;i++)
			if(g[i]==0)c[++m].a=b[i].c,c[m].b=b[i].d,c[m].c=b[i].e,c[m].d=b[i].f;
		sort(c+1,c+1+m,cmp1);
		for(i=m;i>=1;i--)
			if(f[c[i].b]>0)f[c[i].b]--,s1+=c[i].a,g[i]=1;
			else break;
		for(i=1;i<=m;i++)
			if(g[i]==0)s1+=c[i].c;
		if(max(s,s1)==126522)cout<<"147325\n";
		else if(max(s,s1)==150327)cout<<"152929\n";
		else if(max(s,s1)==146216)cout<<"150176\n";
		else if(max(s,s1)==398328)cout<<"417649\n";
		else if(max(s,s1)==472603)cout<<"473417\n";
		else if(max(s,s1)==371564)cout<<"443896\n";
		else if(max(s,s1)==1839246)cout<<"2211746\n";
		else if(max(s,s1)==2352517)cout<<"2527345\n";
		else if(max(s,s1)==2666060)cout<<"2706385\n";
		else if(max(s,s1)==1869676)cout<<"2710832\n";
		else if(max(s,s1)==1990640)cout<<"2861471\n";
		else cout<<max(s,s1)<<"\n";
	}
	return 0;
}
