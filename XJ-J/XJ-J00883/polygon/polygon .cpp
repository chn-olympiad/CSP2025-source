#include <bits/stdc++.h> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int ci=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	int max=0;
	for(int i=0;i<n;i++){
		if(n>=3){
			for(int j=3;j<n;j++){
				for(int k=0;k<j;k++){
					sum=sum+a[i+k];
					if(max<a[i+k]){
						max=a[i+k];
					}
				}
				if(sum>(max*2)){
					ci++;
				}
			}
		}
	}
	cout<<ci;
	return 0;
}
