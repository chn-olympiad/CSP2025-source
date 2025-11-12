//王铭轩-SN-S00530-陕西省安康中学
#include <iostream>
using namespace std;
const int N = 1e6+10;

int n,m,k,a[N][N],u,v,w,c[N][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u>>v>>w,a[u][v]=w,a[v][u]=w;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=m;j++){
			cin>>c[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=m-1;i++){
		for(int j=i+1;j<=m;j++){
			sum+= a[i][j];
		}
	} 
	
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
