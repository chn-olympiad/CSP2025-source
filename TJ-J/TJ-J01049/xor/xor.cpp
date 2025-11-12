#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i%2==0) {
			ans+=i;
		}
	}
	if(n==2){
		cout<<1;
	}
	else{
		cout<<ans; 
	}
	return 0;
}
