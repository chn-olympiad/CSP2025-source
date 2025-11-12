#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500009]={};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
		for(int i=1;i<=n;i++){
		int q=0;
			for(int j=i;j<n;j++){
				if(a[j]==k){
					q=1;
					
				}
				else{
				a[j]=a[j]^a[j+1];
				}
				
	}
	sum+=q;
	}
	cout<<sum;

	
	
	
	return 0;
}
