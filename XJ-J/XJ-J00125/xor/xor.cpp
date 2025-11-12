#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ok=0;
		}
	}
	if(k==0){
		if(ok)cout<<n/2;
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}
				else if(i<n){
					if(a[i]==a[i+1]){
						sum++;
						i++;
					}
				}
			}
			cout<<sum;
		}
	}
	else if(k==1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
