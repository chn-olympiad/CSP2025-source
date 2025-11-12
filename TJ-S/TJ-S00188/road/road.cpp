#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,m,k,v[N],fa[20011],b[12],cnt,pp[11],num;
long long ans;
struct node{
	int u,v,w,id;
}a[N];
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
int f(int x){
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
bool cmp(node c,node d){
	return c.w<d.w;
}
void q(int u,int v,int w,int id){
	int c=f(u),d=f(v);
	if(c!=d){
		num++;
		if(b[id]) ans-=pp[id];
		else b[id]++;
		fa[d]=c;
		ans+=w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].id=0;
	}
	for(int i=1,x;i<=k;i++){
		scanf("%d",&pp[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&v[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				a[++m]={j,k,v[j]+v[k]+pp[i],i};
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	int flag=0;
	for(int j=1;j<=m;j++){
			q(a[j].u,a[j].v,a[j].w,a[j].id);
			if(num==n-1){
				flag=1;
				break;
			}
		if(flag) break;
	}
	cout<<ans;
	return 0;
} 
