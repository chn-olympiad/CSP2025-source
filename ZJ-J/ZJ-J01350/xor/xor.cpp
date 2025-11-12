#include <bits/stdc++.h>
using namespace std;
long long n,k,mi,i,a[500010],s,s1,s0,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;mi=2e9;
	for (i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]);
	if(!k){
		if(mi) cout<<n/2;
		else{
			for (i=2;i<=n;i++){
				if(a[i]==1) s1++;
				else s0++;
				if(s1%2==0&&s0%2==0) ans++;
			}
			cout<<ans;
		}
	}
	else{
		if(mi) cout<<0;
		else{
			for (i=1;i<=n;i++){
				if(a[i]==1) s1++;
				else s0++;
				if(s1==s0) ans++;
			}
			cout<<ans;
		}	
		
	}
}
