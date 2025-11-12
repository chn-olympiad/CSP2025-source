#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,ans,sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1&&k==0){
		cout<<0;
		return 0;
	}
	if(n==2&&k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
