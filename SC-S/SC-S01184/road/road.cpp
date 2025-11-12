#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k,tot=1;
long long f[N],c[N],ans,how,i;
struct edge{
	int a,b,c,idd;
}a[N];
bool cmp(edge a,edge b){
	return a.c<b.c;
}
int findd(int x){
	if(f[x]==x) return x;
	else return f[x]=findd(f[x]);
}
void unite(int x,int y){
	f[x]=f[findd(y)];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k*n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++,tot++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		a[i].idd=tot;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[++tot].c);
			a[tot].a=n+i;
			a[tot].b=j;
		}
	}
	sort(a+1,a+1+tot,cmp);
	i=1;
	while(how<n){
		i++;
//		cout<<a[i].c;
		int x=a[i].a,y=a[i].b;
		if(f[x]!=f[y]){
			unite(x,y);
			ans+=a[i].c;
			how++;
		}
	}
	printf("%lld",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}