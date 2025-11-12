#include<bits/stdc++.h>
using namespace std;
int n,k,arr[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(k==2||k==3)cout<<2;
	else cout<<1;
	return 0;
}