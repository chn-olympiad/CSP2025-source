#include<bits/stdc++.h>
using namespace std;
int a[110],b[110],n,m,tot;
int main(){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		cin>>a[i];
	}
	
	for(int j=0;j<=n*m;j++){
		cin>>b[j];
	}
	cout<<a[i]<<" "<<b[j];
	return 0;
}
