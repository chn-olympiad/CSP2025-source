#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int h[1000005],arr[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>arr[1];
	h[1]=arr[1];
	for(int i=2;i<=n;i++){
		cin>>arr[i];
		h[i]=h[i-1]^arr[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			h[i]^=h[j];
			if(h[i]==k){
				int k=h[i];
				//cout<<k<<" "<<i<<" "<<j<<endl;
				ans++;
			}	
			h[i]^=h[j];
		}
	}
	cout<<ans;
	return 0;
} 
