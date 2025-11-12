#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000001],ans,vis[1000100];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=0;j<n;j++){
		for(int i=1;i<=n;i++){
			if(i+j>n) break;
			int sum=0,flag=1;
			for(int k=i;k<=i+j;k++){
				if(vis[k]) flag=0;
				sum=(sum^a[k]);
			}
			if(sum==k&&flag){
				ans++;
				for(int k=i;k<=min(i+j,n);k++) vis[k]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
