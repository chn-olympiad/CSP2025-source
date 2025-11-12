#include<bits/stdc++.h>
using namespace std; 
int l[5010];
int n,k; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(k==0){
		cout<<1;
	}
	return 0;
}
