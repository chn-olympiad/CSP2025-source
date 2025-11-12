#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m]={0},b[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}int c=b[0];
	sort(b,b+n*m);
	int zhi=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				a[i][j]=b[n*m-zhi-1];
				zhi++;	
				if(a[i][j]==c){
					cout<<i+1<<" "<<j+1;
					return 0;
				}		
			}
		}else{
			for(int j=n-1;j>=0;j--){
				a[i][j]=b[n*m-zhi-1];
				zhi++;
					if(a[i][j]==c){
					cout<<i+1<<" "<<n-j+1;
					return 0;
				}				
			}
		}
	}return 0;
	
}
