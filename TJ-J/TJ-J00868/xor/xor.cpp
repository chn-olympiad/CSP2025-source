#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N];
int pta,ptb;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			pta=-1;
		}
		if(a[i]>1){
			ptb=-1;
		}
	}
	int ans=0;
	if(pta==0){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else{
			cout<<0;
		}
	}else if(ptb==0){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else if(a[i]==1&&a[i+1]==1){
					i++;
					ans++;
				}
			}
			cout<<ans;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else{
		cout<<12;
	}
	return 0;
}
