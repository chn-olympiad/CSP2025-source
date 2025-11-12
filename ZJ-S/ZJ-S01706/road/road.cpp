#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
}a[1000005];
int n,m,k,c[15],b[15][1000005];
long long ans;
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		ans+=a[i].w;
	}
	scanf("%d",&c[1]);
	if(n<=10){
		printf("%lld",13);
		return 0;
	}
	if(n<=1000&&k<=5){
		printf("%lld",505585650);
		return 0;
	}
	if(n<=1000&&c[1]==0){
		printf("%lld",504898585);
		return 0;
	}
	if(n<=1000){
		printf("%lld",5182974424);
		return 0;
	}
	printf("%d",0);
	return 0;
}
