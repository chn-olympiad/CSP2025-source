#include<bits/stdc++.h>
using namespace std;
int n,m,k,f=1;
int fa[10025];
struct node{
	int x,y,z;
}t[1000005],p[1500005];
struct stu{
	int v,w;
};
int c[15][10005];
bool flag[15];
long long ans=1e18;
bool cmp(node a,node b){
	return a.z<b.z;
}
int Find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=Find(fa[x]);
}
void pun(long long sum,int n){
	sort(p+1,p+1+m,cmp);
	int tot=0;
	for(int i=1;i<=m;i++){
		int x=p[i].x,y=p[i].y,z=p[i].z;
		int fx=Find(x),fy=Find(y);
		if(fx==fy){
			continue;
		}
		fa[fy]=fx;
		sum+=z;
		if(sum>=ans){
			return ;
		}
		tot++;
		if(tot==n-1){
			ans=min(ans,sum);
			return ;
		}
	}
}
void zhuibei(long long sum){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		p[i].x=t[i].x;
		p[i].y=t[i].y;
		p[i].z=t[i].z;
	}
	int l=n,q=m;
	for(int i=1;i<=k;i++){
		if(flag[i]==0){
			continue;
		}
		for(int j=1;j<=n;j++){
			m++;
			p[m].x=n+i,p[m].y=j,p[m].z=c[i][j];
		}
		l++;
	}
	pun(sum,l);
	m=q;
} 
void fun(int x,long long sum){
	if(sum>=ans){
		return ;
	}
	if(x==k+1){
		zhuibei(sum);
		return ;
	}
	fun(x+1,sum);
	flag[x]=1;
	fun(x+1,sum+c[x][0]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&t[i].x,&t[i].y,&t[i].z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
		if(c[i][0]!=0){
			f=0;
		}
	}
	zhuibei(0ll);
	if(f){
		for(int i=1;i<=k;i++){
			flag[i]=1;
		}
		zhuibei(0ll);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(c[i][0]>c[j][0]){
				for(int x=0;x<=n;x++){
					swap(c[i][x],c[j][x]);
				} 
			}
		}
	}
	while(c[k][0]>=ans){
		k--;
	}
	fun(1,0ll);
	printf("%lld",ans);
	return 0;
}

