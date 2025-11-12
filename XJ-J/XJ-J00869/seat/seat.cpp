#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int a=b[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-1;j++){
			if(b[j]<b[j+1]){
				int x=b[j];
				b[j]=b[j+1];
				b[j+1]=x;
			}
		}
	}
	for(int i=1;i<m*n;i++){
		if(b[i-1]==a){
			if(i%n==0){
				if(i/n%2==1){
					cout<<i/n<<' '<<n;
				}else{
					cout<<i/n<<' '<<1;
				}
			}else{
				if((i/n+1)%2==1){
					cout<<i/n+1<<' '<<i%n;
				}else{
					cout<<i/n+1 <<' '<<n-(i%n)+1;
				}
			}
		}
	}
	return 0;
}	
