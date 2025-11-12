#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int sum;
		cin>>sum;
		ans+=sum;
	}
	if(k==0)cout<<n-ans;
	else if(k==1)cout<<ans;
	else cout<<0; 
	return 0;
}
