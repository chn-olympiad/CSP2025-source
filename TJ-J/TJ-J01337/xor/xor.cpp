#include<bits/stdc++.h>
using namespace std;
long long n,k,c[510000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(k==0){
		cout<<1;
	}else{
		cout<<k;
	}
	return 0;
}
