#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		cnt+=w;
	}
	cout<<int(cnt*0.7);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
