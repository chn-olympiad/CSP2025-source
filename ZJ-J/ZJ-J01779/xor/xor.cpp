#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,k;
int a[500010];
int f[500010];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=t+1;j<=i;j++){
			int p=f[i]^f[j-1];
			if(p==k){
				ans++;
				t=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
