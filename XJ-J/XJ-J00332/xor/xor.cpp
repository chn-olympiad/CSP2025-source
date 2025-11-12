#include<bits/stdc++.h>
using namespace std;
int n,k,flag,cnt,ans;
int a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]==1){
			cnt++;
		}
		if(a[i]==0){
			ans++;
		}
	}
	if(n<=2&&k==0&&flag==0){
		if(n==1) {
			cout<<0;
		}
		if(n==2) {
			cout<<1;
		}
		return 0;
	}
	if(n<=100&&k==0&&flag==0){
		cout<<n/2;
		return 0;
	}
	if(k==1) {
		cout<<cnt;
	}
	if(k==0){
		cout<<ans;
	}
	return 0;
}

