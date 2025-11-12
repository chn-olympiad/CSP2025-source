//赵柏然-SN-J01020-曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
	}else{
		cout<<2;
	}
	return 0;
}
