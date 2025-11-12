#include<bits/stdc++.h>
using namespace std;
int a[105],b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=0,l=0;
	for(int i=1;i>=n*m;i++){
		cin>>a[i];
		x=a[i];
		if(a[i]>x){
			l++; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			if(i*m+j==l)cout<<i<<" "<<j;
		}
		
	}
	
	return 0;
}
 
