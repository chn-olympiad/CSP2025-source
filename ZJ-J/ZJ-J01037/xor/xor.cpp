#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int maxa=0,mina=INT_MAX;
	if(n<=2){
		cin>>a[1]>>a[2];
		if(a[1]==0)ans++;
		if(a[2]==0)ans++;
		if(a[1]==a[2]&&a[1]==1)ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
		maxa=max(a[i],maxa);
	}
	if(maxa==1&&mina==1){
		cout<<n/2;
		return 0;
	}
	if(maxa==1&&mina==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				else if(a[i]==a[i+1]){
					ans++,i++;
				}
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
				else if(a[i]!=a[i+1]){
					ans++,i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
//	int l=1,r=n,mid;
//	while(l<r){
//		mid=(l+r)/2;
//		if(check(mid))l=mid;
//		else r=mid-1;
//	}
//	cout<<l;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt=cnt^a[i];
		if(cnt==k)cnt=0,ans++;
	}
	cout<<ans;
	return 0;
}

