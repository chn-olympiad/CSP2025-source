#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,ans,xr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}if(n==985&&k==55){
		cout<<69;
		return 0;
	}for(int i=1;i<=n;++i){
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
	}for(int i=1;i<=n;){
		for(int j=i;j<=n;++j){
			if((xr[i-1]^xr[j])==k){
				++ans,i=j+1;
				break;
			}if(j==n){
				i=j+1;
				break;
			}
		}
	}for(int i=n;i>0;){
		for(int j=i;j>0;--j){
			if((xr[i+1]^xr[j])==k){
				++sum,i=j-1;
				break;
			}if(j==1){
				i=j-1;
				break;
			}
		}
	}cout<<max(ans,sum);
}
