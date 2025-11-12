#include<bits/stdc++.h>
using namespace std;
#define int long long
const int cd=5005,mod=998244353;
int n,a[cd],cnt1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt1+=(a[i]==1);
	} 
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) cout<<1;
		else cout<<0;
	}
	else if(cnt1==n){
		cout<<n%mod*(n-1)*mod/2-2;
	}
	return 0;
}
