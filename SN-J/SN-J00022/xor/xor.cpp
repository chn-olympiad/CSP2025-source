#include<bits/stdc++.h>
using namespace std;
int a[1005],vis[1005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a1=0,a0=0;cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			a1++;
		}else{
			a0++;
		}
	}
	if(k==1) cout<<a1;
	else{
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i-1]==1&&!vis[i]&&!vis[i-1]){
				a0++;
				vis[i]=vis[i-1]=1;
			}
		}
		cout<<a0;
	}
}
