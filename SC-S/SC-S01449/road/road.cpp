#include<bits/stdc++.h>
using namespace std;
int n,m,k,vil[11][10000005],ans;
struct Road{
	int u,v,w;
}rd[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>rd[i].u>>rd[i].v>>rd[i].w;
		ans+=rd[i].w; 
	}
	for(int i=0;i<n;i++){
		cin>>vil[i][0];
		for(int j=0;j<n;j++){
			cin>>vil[i][j];
		}
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}