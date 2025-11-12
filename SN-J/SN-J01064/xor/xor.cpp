#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005],b[500005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		int ans=0,c=1;
		for(int j=c;j<=n;j++){
			
		}
	}
	return 0;
}
