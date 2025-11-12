#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=2e6+5;
int n,m,k,tot,cnt,c[MAXN],f[MAXN];
ll ans;
struct node{
	int x,y,w;
}p[MAXN];
bool cmp(node a,node b){
	return a.w<b.w;
}
void init(){
	for(int i=1;i<=n;i++) f[i]=i;	
}
int fnd(int x){
	if(f[x]==x) return x;
	else return f[x]=fnd(f[x]);
}
void krs(){
	sort(p+1,p+1+cnt,cmp); 
	for(int i=1;i<=cnt;i++){
		int x=p[i].x;
		int y=p[i].y;
		int fx=fnd(x);
		int fy=fnd(y);
		if(fx==fy) continue;
		f[fx]=fy;
		ans+=p[i].w;
		tot++;
		if(tot==n-1) return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&p[++cnt].x,&p[cnt].y,&p[cnt].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++){
			p[++cnt].x=i;
			p[cnt].y=j;
			scanf("%d",&p[cnt].w);
		}
	}
	krs();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

