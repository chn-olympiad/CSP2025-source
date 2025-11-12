#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","read",stdin)
	//freout("seat.out","wri",stdout)
	int n,m,r,i,j,k=0;
	cin>>n>>m;
	int a[n*m];
	for(i=0;i<n*m;i++) cin>>a[i];
	sort(a,a+n*m,greater<int>());
	int ma[n][m];
	if(j%2==0){
		for(i=0;i<n;i++) ma[i][j]=a[k+1];
	}else{
		for(i=n-1;i>0;i--) ma[i][j]=a[k+1];
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(ma[i][j]==r){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
} 


