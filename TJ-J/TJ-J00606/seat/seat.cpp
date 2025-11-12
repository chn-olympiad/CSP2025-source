#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int a[n*m+5];int b[m+5][n+5];
	for(int i=0;i<n*m;i++){
		
			cin>>a[i];
		
	}int c=a[0];
	
	int j=n*m;
	for(int k=0;k<j;k++){
		int maxx=k;
		for(int i=k;i<j;i++){
			if(a[maxx]<a[i]){
				maxx=i;
			}
		}
		int temp=a[k];
		a[k]=a[maxx];a[maxx]=temp;     //cout<<a[k];
		
	}/*int y;
	for(int i=1;i<=j;i++){
		if(a[i-1]==c)y=i;
	}cout<<y;
	//cout<<y%n+1<<' '<<y/n+1;

	
		if((y/n+1)%2==1){
			if()
			cout<<y/n+1<<' '<<y%n-1;
		}
		else{
			cout<<y/n+1<<' '<<y%n;
		} */int u=0;
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				
				b[i][j]=a[u];u++;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				b[i][j]=a[u];u++;
				
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==c)cout<<i+1<<' '<<j+1;
		}
	}
	
	
	return 0;
}
