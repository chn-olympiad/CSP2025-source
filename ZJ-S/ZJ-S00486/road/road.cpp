#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
bool fsub1,fsub2;
struct edge{
	int head,next,to,val;
}e[M*2+K*2];
int tot,n,m,k,x,y,z[M],c[K],a[K][N],ans;
void add(int x,int y,int z){
	tot++;
	e[tot].to=y;
	e[tot].val=z;
	e[tot].next=e[x].head;
	e[x].head=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n,&m,&k);
	if(k!=0)fsub2=true;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z[i]);
		add(x,y,z[i]);
		add(y,x,z[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)fsub1=true;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)fsub1=true;
		}
	}
	if(!fsub1){
		printf("0\n");
		return 0;
	}
	sort(z+1,z+m+1);
	for(int i=1;i<n;i++){
		ans+=z[i];
	}
	printf("%d\n",ans);
	return 0;
}