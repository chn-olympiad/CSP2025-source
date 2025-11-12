#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(k==1){
		cout<<ans;
	}
	return 0;
} 
