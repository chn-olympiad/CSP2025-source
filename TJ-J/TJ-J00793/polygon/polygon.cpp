#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],h[5005],maxx=-1e9,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=h[i-1]+a[i];
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		if(h[n]>maxx*2){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxx=-1e9;
				for(int k=i;k<=j;k++){
					maxx=max(maxx,a[k]);
				}
				if(abs(j-i)+1>=3&&h[j]-h[i-1]>maxx*2){
					ans++;
					ans%=998244353;
				}
			}
		}
		cout<<ans;
	} 
	return 0;
}
