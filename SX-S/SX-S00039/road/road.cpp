#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4,K=10;
struct road{
	int u,v,w;
}coun[1e6];
int qz[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		if(u>v){
			swap(u,v);
		}
		cin>>coun[i].u>>coun[i].v>>coun[i].w;
		int i1=i;
		while(i1!=1&&coun[i1].w<coun[i1-1].w){
			swap(coun[i1],coun[i1-1]);
			i1--;
		}
	}
	int price=0,sy=n-1;
	for(int i=1;i<=m;i++){
		int from=coun[i].u,to=coun[i].v;
		int point1=qz[from],point2=qz[to];
		price+=coun[i].w;
		if(point1<point2){
			qz[point2]=point1;
			qz[to]=point1;
			if(point1==1){
				sy=sy-2;
			}
			for(int i=point2+1;i<=n;i++){
				if(qz[i]=point2){
					qz[i]=point1;
					if(point1==1){
						sy--;
					}
				}
			}
		}else if(point1>point2){
			qz[point1]=point2;
			qz[from]=point2;
			if(point2==1){
				sy=sy-2;
			}
			for(int i=point1+1;i<=n;i++){
				if(qz[i]=point1){
					qz[i]=point2;
					if(point2==1){
						sy--;
					}
				}
			}
		}else{
			price=price-coun[i].w;
		}
		if(sy==0){
			break;
		}
	}
	cout<<price;
	return 0;
}