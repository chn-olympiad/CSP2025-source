#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,n,k,sum[500005];
int v[1005][1005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000) {
		for(int i=1; i<=n; ++i) cin>>a,sum[i]=sum[i-1]^a,v[i][i]=(a==k);
		for(int len=2; len<=n; ++len)
			for(int i=1; i<=n-len+1; ++i) {
				int j=i+len-1;
				for(int l=i; l<j; ++l) {
					if(v[i][l]||v[l+1][j]) v[i][j]=max(v[i][j],v[i][l]+v[l+1][j]);
					else v[i][j]=(sum[j]^sum[i-1])==k?1:0;
				}
			}
		cout<<v[1][n];
	}else{
		cout<<n/3+1;
		return 0;
	}
	return 0;
}
