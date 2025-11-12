#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100],sum[500100],ans,st[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1] ^ a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				ans++;
				i=j;
			}
		}
	}
	cout<<ans;
}
