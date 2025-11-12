#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans,f[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int l=1,r=1,p=1;
	while(r<=n){
		if((sum[r]^sum[l-1])==k){
			ans++;
			r++;
			l=r;
			p=0;
		}
		if(p)r++;
		p=1;
	}
	cout<<ans;
	return 0;
}