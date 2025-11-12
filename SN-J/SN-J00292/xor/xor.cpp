#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int b[n];
	int s0=0; 
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]==0){
			s0++;
		}
	}
	if(s0==n){
		cout<<n;
		return 0;
	}
	int ans=0;
	if(k==0){
		
		for(int i=0;i<n;i++){
			if(b[i]==0){
				ans++;
			}
			else if(b[i]==1){
				if(b[i+1]==1){
					ans++;
					i++;
				}
			}
		}
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(b[i]==1){
				ans++;
			}
			if(b[i]==0&&b[i+1]==1){
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
}
