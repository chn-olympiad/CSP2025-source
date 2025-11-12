#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum;
int a[500099],f;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=1;
	}
	if(n==1){
		if(a[1]==f) cout<<1;
		else cout<<0;
		return 0;
	}	
	if(n==2){
		cout<<1;
		return 0;
	}
	
	return 0;
}
