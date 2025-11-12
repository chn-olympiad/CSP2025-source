#include<bits/stdc++.h>
using namespace std; 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[105],a[11][11];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int q=b[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(b[j]<b[j+1]&&j<n*m){
				int t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j<=1;j++){
				a[i][j]=b[p];
				p++;
			}	
		}else{
			for(int j=1;j<=n;j++){
				a[i][j]=b[p];
				p++;
			}
		}

	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==q){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
