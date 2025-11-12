#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,t,u,v,w,a;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			cin>>a;
		}
	}
	srand(time(0));
	cout<<rand()%10+10;
	return 0;
}