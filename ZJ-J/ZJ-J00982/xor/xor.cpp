#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=0,a[500001],f[1001][1001];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				ans+=(cnt/2);
				cnt=0;
			}
			if(a[i]==1)cnt++;
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=255;j++){
			f[i][j]=max(f[i][j],f[i-1][j^a[i]]);
		}
		f[i][0]=max(f[i][0],f[i][k]+1);
	}
	for(int i=0;i<=255;i++){
		ans=max(ans,f[n][i]);
	}
	cout<<ans;
}
