#include <bits/stdc++.h>
using namespace std;
int n,ans,k,flaga=1,flagb=1,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			flaga=0;
		}
		if(a[i]>=2){
			flaga=0;
			flagb=0;
		}
	}
	if(flaga==1){
	cout<<n/2;
	return 0;
	}
	if(flagb==1){
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){ans++;}
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		int times=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){ans++;times=0;}
			if(a[i]==1){
				times++;
				if(times==2){ans++;times=0;}
			}
		}
		cout<<ans;
		return 0;
	}
	}
	for(int lo=1;lo<=n;lo++){
		int temp=0;
		for(int i=1;i<=n-lo+1;i++){
			int now=0;
			for(int j=i;j<=i+lo-1;j++){
				now=now^a[j];
				if(now==k){
					temp++;
					i=j;
					break;
				} 
			}
		}
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
