#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n,k,i,ans,t,a[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	if(k==1){
		for(i=1;i<=n;i++)if(a[i]==k)ans++;
		cout<<ans;
	}
	else{
		for(i=1;i<=n;i++)
			if(a[i]==k)ans+=t/2+1,t=0;
			else t++;
		ans+=t/2;
		cout<<ans;
	}
}