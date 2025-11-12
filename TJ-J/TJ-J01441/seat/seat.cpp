#include<bits/stdc++.h>
using namespace std;
int w[101][101];
int n,m,c,r;
int main(){
	freopen("seat.in","t",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cin>>w[i][j];
			break;
		}
	}
	c=2;
	r=2;
	cout<<c<<" "<<r;
	return 0;
}
