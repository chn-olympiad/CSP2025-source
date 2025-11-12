#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],max1[105];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>max1[i]){
		max1[i]=a[i];
		}
		if(a[1]==max1[i]){
			cout<<i<<" "<<i+1; 
		}
	}
	return 0;
}
