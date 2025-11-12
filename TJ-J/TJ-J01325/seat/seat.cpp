#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int t=n*m; 
    int sum[t];
    int a[n][m];
    
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
	    }
	} 
	int v=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int d=1;d<=n*m;d++){
			if(a[i][j]>=sum[d]){
		    	sum[d]=i*10+j;
	    }
			}
			
	}
	
}
for(int i=1;i<n*m;i++){
	if(sum[i]=v){
		cout<<sum[i];
		break;
	}
}
	return 0;
} 
