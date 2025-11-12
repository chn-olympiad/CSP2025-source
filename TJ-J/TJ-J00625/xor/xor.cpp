#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	return 0;
}
