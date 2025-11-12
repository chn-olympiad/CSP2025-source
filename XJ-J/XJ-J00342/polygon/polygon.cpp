#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1001],ji=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
			  if(a[i]+a[j]>a[k]){
			  	ji++;
			  }
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
			   for(int x=k+1;x<=n;x++){
			   	  if(a[i]+a[j]+a[x]>a[k]){
			  	ji++;
			  }
			   }
			  }
			}
		}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
			   for(int x=k+1;x<=n;x++){
			   	for(int b=x+1;b<=n;b++){
			   		if(a[i]+a[j]+a[x]+a[b]>a[k]){
			  	        ji++;
			       }
				}
			   }
			  }
			}
		}
	cout<<ji;
	return 0;
}
