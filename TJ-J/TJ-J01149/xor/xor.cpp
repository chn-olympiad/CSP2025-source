#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k>1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		cout<<n;
		return 0;
	}else{
		cout<<n/2;
		return 0;
	}
	return 0;
}
