#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>roads;
struct road{
	int u,v,w;
	road(int u,int v,int w){
		roads[u][v]=w;
	}
};
int main(){
	int n,m,k;
	vector<int>tmpa(n,-1);
	roads.reshape(n,tmpa);
	scanf("%d%d%d"&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		
	}
	return 0;
}
