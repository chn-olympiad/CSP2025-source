#include<bits/stdc++.h>
using namespace std;
long long a[15][15],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	if(a[n][m]==1){
		cout<<"1"<<" "<<"1";
		return 0;
	}	
	if(a[n][m]==m*n){
		cout<<m<<" "<<n;
		return 0;
	}
	return 0;
} 
