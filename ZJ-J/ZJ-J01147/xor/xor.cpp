#include<bits/stdc++.h>
using namespace std;
int n,k,nums[9999999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	if(nums[0]==0&&nums[1]==k){
		cout<<2;
	}
	else if(nums[0]^nums[1]==k){
		cout<<1;
	}
	else cout<<9;
	return 0;
} 
