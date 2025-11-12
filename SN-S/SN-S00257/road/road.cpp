#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	if(x>y) return x;
}
struct ro{
	int a;
	int b;
	int rpr;//road price
};
struct ci{
	bool co;
	int fi;
	int cpr[10005];//connect price
	
};
ro road[1000005];
ci con[10005];

int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int m,n,k;
	cin>>n>>m>>k;
	
	
	for(int i=1;i<=m;i++){
		cin>>road[i].a>>road[i].b>>road[i].rpr;
	}
	for(int i=1;i<=k;i++){
		cin>>con[i].fi;
		for(int j=1;j<=m;j++){
			cin>>con[i].cpr[j];
		}
		con[i].co=0;
	}
	
	
	int cnt=0;
	for(int i=1;i<=m;i++){
		cnt+=road[i].rpr;
		
	}
	
	if(k==0){
		cout<<cnt<<endl;
	}else{
		int max[100000];
		for(int i=1;i<=m;i++){
			max[i]=road[i].rpr;
		}
		sort(max,max+m);
		sort(max,max+m,cmp);
		for(int i=0;i<k;i++){
			cnt-=max[i];
		}
		cout<<cnt<<endl;
	}
//	for(int i=1;i<=m;i++){
//		int ev[15];
//		for(int j=1;j<=k;j++){
//			ev[j]=con[j].fi+con[j].cpr[road[i].a]+con[j].cpr[road[i].b];
//		}
////		sort
////		sort(ev,ev+15,cmp);
//		for(int j=1;j<=k;j++){
//			if(con[j].co==1){
//				continue;
//			}
//			for(int l=1;l<=k;l++){
//				if()
//			}
////			if(road[i].rpr>con[j].fi+con[j].cpr[road[i].a]+con[j].cpr[road[i].b]){
////				cnt=cnt-road[i].rpr+con[j].fi+con[j].cpr[road[i].a]+con[j].cpr[road[i].b];
////			}
//		}
//		
//		
//	}
	return 0;
} 
