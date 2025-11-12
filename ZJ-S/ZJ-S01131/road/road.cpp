#include<bits/stdc++.h>
using namespace std;
int u[500050],v[500050],w[500050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long rr=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		rr+=w[i];
	}
	cout<<rr;
	fclose(stdin);
	fclose(stdout);
}
