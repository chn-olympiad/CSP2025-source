#include<bits/stdc++.h>
using namespace std;
int g[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>g[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(g[i]==0) ans++;
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(g[i]==1) ans++;
		}
	}else{
		ans=(n+k)/2;
	}
	cout<<ans;
	return 0;
}
