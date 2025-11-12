#include<bits/stdc++.h>
using namespace std;
struct l{
	int u,v,w;
}a[1000005];
int chen[10005];
int b[15][10005];
int n,m,k;
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int minn=199999999,mi_d1=0,mi_d2=0,maxx=-1;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		if(minn>a[i].w){
			minn=a[i].w;
			mi_d1=a[i].u;
			mi_d2=a[i].v;
		}
		if(maxx<a[i].w) maxx=a[i].w;
	}
	sum+=minn,chen[mi_d1]=1,chen[mi_d2]=1;
	minn=199999999;
	int mi_d3=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(n+1);j++){
			cin>>b[i][j];
		}
		if(b[i][1]<minn) minn=b[i][1],mi_d3=i;
	}
	if(minn!=199999999){
		n++;
		sum+=b[mi_d3][1];
		chen[mi_d3]=1;
	}
	for(int i=1;i<=n;i++){
		if(chen[i]==0){
			int da=-1,db=-1;
			minn=199999999;
			for(int j=1;j<=m;j++){
				if(chen[j]!=1)	minn=min(minn,a[j].w),da=a[j].u,db=a[j].v;
			}
			for(int j=2;j<=n;j++){
				if(chen[j]!=1)	minn=min(minn,b[mi_d3][j]),da=j,db=0;
			}
			if(db!=-1&&da!=-1){
				sum+=minn;
				chen[da]=1;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
