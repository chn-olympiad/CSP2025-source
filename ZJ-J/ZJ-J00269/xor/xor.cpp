#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],f[1010],ans=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}

