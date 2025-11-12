#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,a[5005],mlen=-1,slen;

signed main(){
	FI("polygon");
	FO("polygon");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mlen=max(mlen,a[i]);
		slen+=a[i];
	}
	if(slen>mlen*2) cout<<1;
	else cout<<0;
	return 0;
}
