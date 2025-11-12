#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],as,mn=500005,re,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	re=1;
	while(re<=n){
		for(int l=re;l<=n;l++){
			for(int r=re;r<=n;r++){
				as=a[l];
				for(int i=l+1;i<=r;i++){
					as^=a[i];
				}
				if(as==k && r<mn){
					mn=r;
					re=r+1;
				}
			}
		}
		ans++;
		mn=500005;
	}
	cout<<ans;
	return 0;
}
