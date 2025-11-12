#include<bits/stdc++.h>
using namespace std;
long long m,n,x,j=1,k=1,i;
int a[101];
int main(){
	cin>>m>>n;
	for(i=0;i<m*n;i++){
		cin>>a[i];
	}
	x=a[0];
	for(i=1;i<m*n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i])	swap(a[j], a[i]);
		}
	}
	for(i=0;i<n*m;i++){
		if(x==a[i]){
			break;
		}
		if(k%2!=0){
			if(j==m){
				k++;
			}else{
				j++;
			}
		}else{
			if(j==1){
				k++;
			}else{
				j--;
			}
		}
		
	}
	cout<<k<<' '<<j;
	return 0;
}
