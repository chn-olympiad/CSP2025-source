#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,x,ans,l=1;
long long main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		for(long long j=l;j<=i;j++){
			if((a[i]^a[j-1])==k){
				ans++;
    	        l=i+1;
            	break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
