#include<iostream>
using namespace std;
int n,k,a[5000005]
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=k) cout<<a[i];
	}
	return 0;
}
