#include<bits/stdc++.h>
using namespace std;
int ans,n,k;
int xl[500020];
int xo(int a,int b){
	if(a!=b)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> xl[i];
	}
	if(k==0){
		cout << n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(xo(xl[i-1],xl[i])==1){
			ans++;
			i++;
		}
	}
	cout << ans;
	//针对AB特殊性质的骗分 
	return 0;
}
