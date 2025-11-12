#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,ans;
const int MA=5e5+10;
int a[MA];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f&&k==0){
		for(int i=2;i<=n;i+=2){
			ans=ans+1+n-i;
		}
		cout<<ans;
	}
	return 0;
}
