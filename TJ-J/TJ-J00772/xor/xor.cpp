#include<bits/stdc++.h>

using namespace std;
int n,a[500005];
long long k,ans,gh,maxx=-100;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			maxx=max(maxx,ans);
			//cout<<ans<<' ';
			//ans=0;
			gh=a[i];
			for(int g=i+1;g<=j;g++){
				gh^=a[g];
				
			}
			if(gh==k){
				ans++;
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}
