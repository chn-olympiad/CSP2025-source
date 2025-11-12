#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum=0,ans,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k) {
			sum=0;
			ans++;
			continue;
		}
		cout<<sum<<endl;
		sum=(sum^a[i]);
		if(sum==k){
			sum=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
