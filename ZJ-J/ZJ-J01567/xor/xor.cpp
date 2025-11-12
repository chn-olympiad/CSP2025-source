#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000001],n,k,ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[i+1]){
				a[i]=-1;
				a[i+1]=-1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				a[i]=-1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
