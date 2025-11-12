#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i<=n||j<=n){
				sum++;
			}
		}
		
	}
	cout<<sum;
	return 0;
}