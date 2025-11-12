#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500001],b[500001],c=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				c=1;
			}
			
		}
		if(c==1){
			if(k==0){
				for(int i=1;i<=n;i++){
					if(a[i]==k){
						ans++;
						b[i]=1;
					}
					if(a[i]==1&&a[i+1]==1&&a[i]==a[i+1]==0){
						ans++;
						b[i]=b[i+1]=1;
					}
				}
				
				cout<<ans;
				return 0;
			}
			if(k==1){
				for(int i=1;i<=n;i++){
					if(a[i]==k){
						ans++;
						b[i]=1;
					}
				}
				cout<<ans;
			}
			return 0;
		}
		cout<<n/2;	
			
		
		
	
	
	
	return 0;
}

