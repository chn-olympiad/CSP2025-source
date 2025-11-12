#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c-'0'),c=getchar();
	return x;
}
struct node{
	int x,y,k;
	long long z;
}a[1200005],c[150005],d[150005];
struct bb{
	long long c;
	node b[10005];
}b[15];
bool cmp(node a,node b){
	return a.z<b.z;
}
bool cmp1(bb a,bb b){
	return a.c<b.c;
}
int n,m,q,top,top1,fa[150005],f1[15];
long long f2[15];
int Findf(int k){
	if(fa[k]==k) return k;
	return fa[k]=Findf(fa[k]);
}
long long ff(int kk,int k){
	int p1=1,p2=1;
	for(int i=1;i<=kk;i++) fa[i]=i;
	long long sum=0;
	int cnt=k;
	while(1){
		if(p2<=top&&c[p2].z<a[p1].z){
			int x=Findf(c[p2].x),y=Findf(c[p2].y);
			if(x!=y) fa[x]=y,sum+=c[p2].z,cnt--,
				f1[c[p2].k]++,f2[c[p2].k]+=c[p2].z;
			if(cnt==1) break;
			p2++;continue;
		}
		else{
			int x=Findf(a[p1].x),y=Findf(a[p1].y);
			if(x!=y) fa[x]=y,sum+=a[p1].z,cnt--;
			if(cnt==1) break;
			p1++;continue;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++) a[i]={read(),read(),0,read()};
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=q;i++){
		b[i].c=read();
		for(int j=1;j<=n;j++) b[i].b[j]={n+i,j,i,read()};
	}
	sort(b+1,b+1+q,cmp1);
	long long minn=ff(n,n);
	int pp=0;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=top;j++) c[j]=d[j];
		for(int j=1;j<=n;j++) c[++top]=b[i].b[j],d[top]=b[i].b[j];
		sort(c+1,c+1+top,cmp);
		for(int j=1;j<=i;j++) f1[j]=f2[j]=0;
		long long k=ff(n+i,n+i-pp);
		for(int j=1;j<=i;j++){
			if(f1[j]<=1) k-=f2[j];
			else k+=b[j].c;
		}
		minn=min(minn,k);
		if(k>minn) top-=n,pp++;
		else minn=k;
	}
	printf("%lld",minn);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
