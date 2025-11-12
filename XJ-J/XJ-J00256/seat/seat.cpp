#include<bits/stdc++.h>
using namespace std;

long long int n,m,cc,cr,c[150],z,sor[15][15],r,j;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>r;
			c[i]=r;
		}else{
			cin>>c[i];
		} 
	}
	sort(c+1,c+m*n+1);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				sor[i][j]=c[z];
				z--;
				if(sor[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==0){
			for(int j=m;j>=1;j--){
				sor[i][j]=c[z];
				z--;
				if(sor[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}	
	}
	return 0;
}

