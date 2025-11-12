#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen(" xor.in","r",stdin);
	freopen(" xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(k==0){
		int ans=0;
		if(a[0]==0)ans++;
		for(int i=1;i<n;i++){
			
			if(a[i]==0)ans++;
			if(a[i-1]==1&&a[i]==1){
				a[i-1]=0;
				a[i]=0;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	if(k!=1&&k!=0){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==k)ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
