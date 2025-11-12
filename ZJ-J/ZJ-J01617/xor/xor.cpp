#include <bits/stdc++.h>
using namespace std;
int n,k,a[11];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(n==2){
		int ans=0;
		if(a[1]==k){
			ans++;
		}
		if(a[2]==k){
			ans++;
		}
		if(a[1]==a[2] && a[1]!=0){
			ans++;
		}
		cout<<ans;
	}
	return 0;
}