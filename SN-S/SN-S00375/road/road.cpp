#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[5][10005];
int main(){
	cin>>n>>m>>k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=0;i<m;i++){
		cin>>w[1][i]>>w[2][i]>>w[3][i];
	}
	int ans=0;
	for(int i=0;i<m;i++){
		ans+=w[3][i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
