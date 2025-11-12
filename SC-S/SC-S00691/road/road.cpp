#include<bits/stdc++.h>
using namespace std;
const long long LL=0x3fffffffffffffff;
long long ans,n,m,k,lsbl,cnt,t,h=1;
long long hor[10005],bjs[10005],q[10005],W[10005],u[10005],from[10005];
struct road{
	long long next,to,w;
}R[2000005];
//306W+
void addroad_city(int x,int y,int z){
	cnt++;
	R[cnt].to=y;
	R[cnt].w=z;
	R[cnt].next=hor[x];
	hor[x]=cnt;
}
int main(){
	freopen("raod.in","r",stdin);
	freopen("raod.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		bjs[i]=LL;
	}
	for(int i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		addroad_city(x,y,z);
		addroad_city(y,x,z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&lsbl);
		for(int j=1;j<=n;j++)scanf("%lld",&lsbl);
	}
	for(int i=hor[1];i!=0;i=R[i].next){
		bjs[R[i].to]=R[i].w;
		from[R[i].to]=1;
		W[R[i].to]=R[i].w;
		if(!u[R[i].to])q[++t]=R[i].to;
		u[R[i].to]=1;
	}
	while(h-t+1!=0){
		long long L=q[h];
		for(int i=hor[L];i!=0;i=R[i].next){
			long long TO=R[i].to;
			if(bjs[TO]>bjs[L]+R[i].w){
				bjs[TO]=bjs[L]+R[i].w;
				from[TO]=L;
				W[TO]=R[i].w;
				if(!u[TO])q[++t]=TO;
				u[TO]=1;
			}
		}
		h++;
	}
	for(int i=1;i<=n;i++){
		ans+=W[i];
	}
	cout<<ans;
	return 0;
}
/*

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/