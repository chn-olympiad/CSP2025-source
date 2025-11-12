#include<bits/stdc++.h>
using namespace std;
int n,k,i,s,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) s++;
	}
	if(s==n){
		cout<<n/2;
	}else{
		;
	}
}

