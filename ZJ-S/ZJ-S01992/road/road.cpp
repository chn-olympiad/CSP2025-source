#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e6+15;
int n,m,k,len,p[15][N],c[15],fa[N];
struct node{
	int x,y,z;
}a[M],b[M];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y){
	fa[find(x)]=find(y);
}
ll Kruskal(){
	for(int i=1;i<N;i++) fa[i]=i;
	int i=0,j=0; ll cnt=0;
	while(i<m||j<len){
		node tmp;
		if(j==len||a[i+1].z<b[j+1].z) tmp=a[++i];
		else tmp=b[++j];
		if(find(tmp.x)==find(tmp.y)) continue;
		unionn(tmp.x,tmp.y),cnt+=tmp.z;
	}
	return cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&p[i][j]);
	}
	sort(a+1,a+m+1,cmp);
	ll minn=1e17;
	for(int i=0;i<=(1<<k+1)-2;i+=2){
		len=0; ll cnt=0;
		for(int j=1;j<=k;j++)
			if(i>>j&1){
				cnt+=c[j];
				for(int l=1;l<=n;l++)
					b[++len]={n+j,l,p[j][l]};
			}
		sort(b+1,b+len+1,cmp);
		minn=min(minn,cnt+Kruskal());
	}
	printf("%lld\n",minn);
	return 0;
}