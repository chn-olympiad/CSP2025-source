#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005],sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}if(k==1ll){
		for(int i=1;i<=n;i++){
			if(a[i]==1ll){
				ans++;
			}
		}
	}else if(k==0ll){
		for(int i=1;i<=n;i++){
			if(a[i]==0ll){
				ans++;
			}else if(a[i]==1ll){
				if(a[i+1]==a[i]){
					ans++;
					i++;
				}
			}
		}
	}else{
		for(int i=1,j=1;j<=n;){
			if((sum[j]^sum[i-1])==k){
				cout<<i<<" "<<j<<"\n";
				ans++;
				i=j+1;
				j=i;
			}else{
				j++;
			}
		}
	}cout<<ans;
	return 0;
}
