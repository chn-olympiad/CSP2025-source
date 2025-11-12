#include <bits/stdc++.h>
using namespace std;
int n,k,a[511111],pm=0,p[511111],la=0,ans,fl=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	p[i]=a[i]^p[i-1];
    	if(a[i]>1) fl=1;
	} 
	if(fl==0){
		for(int i=1;i<=n;i++){
			if(a[i]==k) ans++;
		}
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}		
		}
		cout<<ans;
		return 0;
	}
    for(int i=1;i<=n;i++){
    	for(int j=la+1;j<=i;j++){
    		if((p[i]^p[j-1])==k){
    			ans++;
    			la=i;
    			break;
			}
		}
	}
	cout<<ans;	
	return 0;
}
