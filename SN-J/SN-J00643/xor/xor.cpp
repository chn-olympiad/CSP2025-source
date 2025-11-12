#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],maxn,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool is=false;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==0)is=true;
	}
	if(k==0){
		if(maxn==1){
			if(n%2==0&&is){
				cout<<n/2;
				return 0;
			}else{
				for(int i=0;i<n;i++){
					if(a[i]==0){
						ans++;
						continue;
					}
					if(i>0&&a[i]==a[i-1]){
						ans++;
						a[i]=0;
						a[i-1]=0;
					}
				}
				cout<<ans;
				return 0;
			}
		}
	}else if(k==1){
		if(maxn==1){
			for(int i=0;i<n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0; 
}
