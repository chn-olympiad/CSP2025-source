#include<bits/stdc++.h>
using namespace std;
int a[500099];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num_1=0,num_0=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			num_1++; 
		}
		if(a[i]==0){
			num_0++;
		}
	}
	if(num_1==n){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}
	}else if(num_0+num_1==n){
		if(k==0){
			cout<<num_0+num_1/2;
		}else if(k==1){
			cout<<num_1;
		} 
	}
	return 0;
}

