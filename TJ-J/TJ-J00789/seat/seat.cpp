#include<bits/stdc++.h>
using namespace std;
int a[11000],b[11000];
int main(){
	long long n,m,q;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>=a[j-1]){
				b[i]=a[j];
				if(a[j]==a[1]){
					q=i;
				}
			}
		}
	}
	if(b[q]%n%2==0){
		
	}else{
		
	}
	return 0;
}
