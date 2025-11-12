#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int dg[1011][1011],dis[10100],ff[10100],du,dv,dw,dk[10][10100],pre[10100];
int dn,dm,dk;
struct pt{
	int u=0,v=0,w=0;
}pts[1000010];

bool cmp(pt a1,pt a2){
	return a1.w>a2.w;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		
	memset(dis,0x3f,sizeof(dis));
	
	cin>>dn>>dm>>dk;
	for(int i=0;i<dm;i++){
		cin>>pts[i].u>>pts[i].v>>pts[i].w;
		pre[i] = i;
	}
	for(int i=0;i<dk){
		for(int j=0;j<=dn;j++){
			cin>>dk[i][j];
		}
	}
	sort(pts,pts+1+dm,cmp);
	q.push(pts[0].u);
	ff[u] = 1;
	while(!q.empty()){
		
	}

		

	
	
	return 0;
	
} 
