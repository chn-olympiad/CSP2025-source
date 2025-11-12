#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]!=0){
			cout<<0;
			return;
		}else{
			cout<<1;
			return;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long t=1;
	while(t--){
		solve();
	}
	
	
	return 0;
}
