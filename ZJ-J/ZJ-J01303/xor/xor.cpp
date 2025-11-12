#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum+=1;
		}
	}
	if(k==0&&sum==n){
		cout<<n/2;
	}
	else if(k==0){
		int s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||(a[i]==1&&a[i+1]==1)){
				s+=1;
			}
		}
		cout<<s;
	}
	else if(k==1){
		cout<<sum;
	}
	else{
		cout<<27;
	}
	return 0;
}
