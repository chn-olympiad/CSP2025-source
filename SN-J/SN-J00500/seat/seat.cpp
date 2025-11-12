#include<bits/stdc++.h>
using namespace std;
int a[114],a0,s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		a0=a[0];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=0;j<m*n-i;j++){
			if(a[j]<a[j+1]){
				int c=a[j+1];
				a[j+1]=a[j];
				a[j]=c;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==a0){
			int n1=i/n,m1=i%n;
			if((n1+1)%2==1){
				cout<<n1+1<<" "<<m1+1;
				return 0;
			}
			else{
				cout<<n1+1<<" "<<m-m1;
				return 0;
			}
		}
	}
	
}
	
	
	
