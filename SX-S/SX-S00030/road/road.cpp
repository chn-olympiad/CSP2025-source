#include<bits/stdc++.h>
using namespace std;
int m,n,k,m1,m2;
long long hw;
int f[10004];//城市
struct V{
	int u,v,w;
}a[100000005];//路
struct Z{
	int c,a1[1000006];
}b[15];//扶贫
bool G(V x,V y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int l=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		f[a[i].u]++,f[a[i].v]++;
		hw+=a[i].w;
	}//全部连接
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i].c);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i].a1[j]);
			for(int ij=j-1;ij>=1;ij--){
				f[ij]++,f[j]++;
				a[++l].u=ij,a[l].v=j,a[l].w=b[i].c+b[i].a1[j]+b[i].a1[ij];
				hw+=a[l].w;
			}
		}//村转路
	}
	sort(a+1,a+l+1,G);
	for(int i=1;l>=n;i++){//去多余路：非必要&&花费最多
		if(f[a[i].u]-1>=1&&f[a[i].v]-1>=1){
			f[a[i].u]--;
			f[a[i].v]--;
			l--;
			hw-=a[i].w;
		}
	}
	cout<<hw;
	return 0;
}

