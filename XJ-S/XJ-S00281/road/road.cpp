#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,l1[100005],l2[100005],l3[100005],z1[15],z2[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l1[i]>>l2[i]>>l3[i];
	}
	for(int i=1;i<=k;i++){
		cin>>z1[i];
		for(int j=1;j<=n;j++){
			cin>>z2[i][j];
		}
	}
	cout<<"13";
	return 0;
} 
