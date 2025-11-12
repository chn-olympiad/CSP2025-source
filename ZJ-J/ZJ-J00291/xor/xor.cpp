#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) ans++;
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	else if(k==1){
		cout<<n-ans;
		return 0;
	}
	return 0;
}
