#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int kk=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)kk=0;
	}
	if(kk==1)cout<<n/2;
	else{
		int ans=0;
		if(k==1){
			for(int i=1;i<n;i++){
				if((a[i]==1 and a[i+1]==0)or(a[i]==0 and a[i+1]==1)){
					ans++;
					i++;
				}
			}
		}
		else{
			for(int i=1;i<n;i++){
				if((a[i]==1 and a[i+1]==1)or(a[i]==0 and a[i+1]==0)){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
