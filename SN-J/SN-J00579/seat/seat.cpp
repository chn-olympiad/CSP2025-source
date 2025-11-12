#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1000],k,e,b[15][15];
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(a[i]>a[j]){
				e=a[i];
				a[i]=a[j];
				a[j]=e;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
		int ww=i/n;
			if(i%n==0){
				if((i/n)%2==0){
					cout<<n<<" "<<1;
				}
				else{
					cout<<n-1<<" "<<n;
				}
			}
			else if(i<n){
				cout<<1<<" "<<i;
			}
			else if(i>n){
				if((i/n)%2==1){
					int y=i-n*ww;
					cout<<ww+1<<" "<<(n+1)-y;
				}else if((i/n)%2==0){
					cout<<ww+1<<" "<<i-n*ww;
				}
			}
			
		}
	}
	return 0;
 }
	
