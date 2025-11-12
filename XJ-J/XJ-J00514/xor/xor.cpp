#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010];
int flag=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0)flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1 && a[i+1]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0; 
	}
	if(k==1){
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0; 
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}
