#include  <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,ans,vis[500005],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) sum++;
		if(a[i]==1 || a[i]==0) ans++;
	}
	if(sum==n){
		cout<<n/2;
		return 0;
	}
	if(ans==n){
		if(k==1) cout<<sum;
		if(k==0) cout<<n-sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=a[i];
			if(i==j && a[i]==k && !vis[i]){
				sum++;
				vis[i]=1;
			}
			if(i!=j){
				for(int l=i+1;l<=j;l++) ans^=a[l];
				if(ans==k){
					for(int l=i;l<=j;l++){
						if(vis[l]){
							flag=1;
							break;
						}
					}
					if(!flag){
						sum++;
						for(int l=i;l<=j;l++) vis[l]=1;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
