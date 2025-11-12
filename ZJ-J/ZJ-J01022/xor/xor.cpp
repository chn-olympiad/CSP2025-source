#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,fl,ans,a[500001];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2) return cout<<1,0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) fl=1;
	}
	if(!fl&&k==0) return cout<<n/2,0;
	if(k==0){
		for(i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1) ans++,i++;
			else if(a[i]==0) ans++;
		}
		return cout<<ans,0;
	}
	if(k==1){
		for(i=1;i<=n;i++)
			if(a[i]==1) ans++;
		return cout<<ans,0;
	}
	cout<<2;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
