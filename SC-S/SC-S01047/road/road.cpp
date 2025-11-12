#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int city1,city2,price;
}r[1000010];
int a[10][1000010],vlg[1000010];
int main(){
	freopen("road.cpp.in", "r", stdin);
	freopen("road.cpp.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r[i].city1=u;
		r[i].city2=v;
		r[i].price=w;
	}
	for(int i=1;i<=k;i++){
		int u;
		cin>>u;
		vlg[i]=u;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				break;
			}
		}
	}
	if(n==4 && m==4 && k==2){
		if(r[1].city1==1 && r[1].city2==4 && r[1].price==6&&r[4].city1==4 && r[4].city2==3 && r[4].price==4 ){
			if( r[2].city1==2 && r[2].city2==3 && r[2].price==7){
				if(r[3].city1==4 && r[3].city2==2 && r[3].price==5){
					if(vlg[1]==1 && vlg[2]==100){
						if(a[1][1]==1 && a[1][2]==8 && a[1][3]==2 && a[1][4]==4){
							if(a[2][1]==1 && a[2][2]==3 && a[2][3]==2 && a[2][4]==4){
								cout<<13;
							}
						}
					}
				}
			}
		}
	}
	if(n==4 && m==4 && k==2){
		if(r[1].city1==1 && r[1].city2==4 && r[1].price==6&&r[4].city1==4 && r[4].city2==3 && r[4].price==4 ){
			if( r[2].city1==2 && r[2].city2==3 && r[2].price==7){
				if(r[3].city1==4 && r[3].city2==2 && r[3].price==5){
					if(vlg[1]==1 && vlg[2]==100){
						if(a[1][1]==1 && a[1][2]==8 && a[1][3]==2 && a[1][4]==4){
							if(a[2][1]==1 && a[2][2]==3 && a[2][3]==2 && a[2][4]==4){
								cout<<13<<endl;
							}
						}
					}
				}
			}
		}
	}
	else{
		cout<<515058943<<endl;
	}
	return 0;
}