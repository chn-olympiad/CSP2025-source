#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	bool operator<(node x){
		return w<x.w;
	}
}a[2000005],b[2000005],c[2000005],x;
bool cmp(node x,node y){
	return x<y;
}
long long ans=0x3f3f3f3f3f3f3f3fll,sum;
int fa[20005],p,tot,n,m,k,W[15],w[15][20005],o,f,y;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
void kruscal(){
	for(int i=1;i<=p;i++){
		if(find(c[i].u)!=find(c[i].v)){
			tot--;
			sum+=c[i].w;
			merge(c[i].u,c[i].v);
		}
		if(tot==1)return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>W[i];
		for(int j=1;j<=n;j++)cin>>w[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		f=0;
		for(int j=0;j<k;j++){
			if((i&(1<<j))==0&&W[j+1]==0){
				f=1;
				break;
			}
		}
		if(f)continue;
		o=0;
		sum=0;
		f=0;
		for(int j=1;j<=k;j++)if(i&(1<<(j-1))){
			sum+=W[j];
			x.u=n+j;
			for(int l=1;l<=n;l++){
				x.v=l;
				x.w=w[j][l];
				b[++o]=x;
			}
			f++;
		}
		sort(b+1,b+o+1,cmp);
		p=0;
		y=1;
		for(int j=1;j<=o;j++){
			while(y<=m&&a[y]<b[j]){
				c[++p]=a[y];
				y++;
			}
			c[++p]=b[j];
		}
		for(;y<=m;y++)c[++p]=a[y];
		for(int j=1;j<=n+k;j++)fa[j]=j;
		tot=n+f;
		kruscal();
		ans=min(ans,sum);
	}
	cout<<ans;
}
