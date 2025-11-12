#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
long long a[1000005][8];
long long b[15][10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4]>>b[i][5];
		sum+=b[i][3];
		sum+=b[i][2];
		sum+=b[i][1];
		sum+=b[i][4];
		sum+=b[i][5];
	}
	cout<<sum;
	return 0;
}
