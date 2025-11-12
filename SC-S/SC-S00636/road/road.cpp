#include<bits/stdc++.h>
using namespace std;
int n,m,k,roads[1000001][3],news[10][10001],costm[1000001],costk[10],Min; 
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		for(int j=0;j<2;j++)
			cin>>roads[i][j];
		cin>>costm[i];
	}
	if(k){
		for(int i=0;i<k;i++){
			cin>>costk[i];
			for(int j=0;j<n;j++)
				cin>>news[i][j];
		}
	}
	sort(costm,costm+m);
	for(int i=0;i<m-k;k++)
		Min+=costm[i];
	cout<<Min;
	fclose(stdin);fclose(stdout);
	return 0;
}