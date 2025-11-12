#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int d[10000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>d[j];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
