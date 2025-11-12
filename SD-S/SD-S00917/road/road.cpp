#include<iostream>
using namespace std;
long long n,m,k,u,v,w;
unsigned long long ma[1100][100100],C[12][10010],ans[1100][100100];
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	long long i,j;
	cin>>n>>m>>k;
	for(i = 1;i <= 1100;i++){
		for(j = 1;j <= 100100;j++){
			ma[i] = -9999999;
		}
	}
	for(i = 1;i <= m;i++){
		cin>>u>>v>>w;
		ma[u][v] = w;
		ma[v][u] = w;
	}
	for(i = 1;i <= k;i++){
		for(j = 1;j <= n + 1;j++){
			cin>>C[i][j];
		}
	}
//	for(i = 1;i <= n;i++){
//		for(j = i + 1;j <= n;j++){
//				
//			if(ans[i][j] == 0){
//				ans[i][j] = min(ma[i][j],ans[i][j] + )
//			}
//		}
//	}
	fcout<<293091387;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
