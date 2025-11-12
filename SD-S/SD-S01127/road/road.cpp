#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,k,b[10005];
struct node{
	int l,r,c;
}a[2000005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int f[10015];
int Find(int x){
	if(x==f[x])return f[x];
	return f[x]=Find(f[x]);
}
void Union(int x,int y){
	f[Find(x)]=Find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	long long sum=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=n+1;i<=n+k;i++)f[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[i].l=u;
		a[i].r=v;
		a[i].c=w;
	}
	long long cnt=0;
	for(int i=n+1;i<=n+k;i++){
		int c;
		scanf("%d",&c);cnt+=c;
		for(int j=1;j<=n;j++)scanf("%d",&b[j]);
		for(int j=1;j<=n;j++){
			a[++m].l=i;
			a[m].r=j;
			a[m].c=b[j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=Find(a[i].l),y=Find(a[i].r);
		if(x!=y){
			Union(x,y);
			sum+=a[i].c;
			//cout<<a[i].l<<' '<<a[i].r<<'\n';
		}
	}
	/*cout<<m;
	for(int i=1;i<=m;i++){
		cout<<a[i].l<<' '<<a[i].r<<' '<<a[i].c<<'\n';
	}*/
	printf("%lld",(long long)(sum+cnt));
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
