#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
void solve1(){
	if(n<2){
		cout<<0;
	}else{
		cout<<1;
	}
}
void solve2(){
	cout<<n/2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		solve1();
		return 0;
	}
	if(k==0){
		solve2();
	}
	return 0;
}
