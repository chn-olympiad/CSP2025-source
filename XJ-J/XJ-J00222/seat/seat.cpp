#include <bits/stdc++.h>
using namespace std;
int n,m,a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n==1&&m==1){
		cout<<1<<" "<<1;	
		return 0;
	} 
	if(n==1){
		int x=a[1]; 
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m-i;j++){
				if(a[i]<a[i+1]){
					int temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(a[i]==x){
				cout<<1<<" "<<i;
				return 0;
			}
			 
		}
	}
	if(m==1){
		int y=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-i;j++){
				if(a[i]<a[i+1]){
					int temp=a[i];
					a[i]=a[i+1];
					a[i+1]=temp;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==y){
				cout<<i<<" "<<1; 
				return 0;
			}
			
		}
	}
}
