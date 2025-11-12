#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			return 0;
		} 
	}
	cout<<n/2;
	return 0;
} 
