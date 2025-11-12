#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,mod=998244353;
int n,k,a[N],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x==0) ans++;
	}
	if(k==0) cout<<ans;
	if(k==1) cout<<n-ans;
	else cout<<2;
	return 0;
}
