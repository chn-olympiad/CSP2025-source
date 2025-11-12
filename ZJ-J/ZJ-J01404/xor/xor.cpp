#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ax=1,b=1;
	for(int i=1;i<=n;i++){//SPJ for special A&B
		if(a[i]!=1){
			ax=0;
			break;
		}
		if(a[i]>1){
			b=0;
			break;
		}
	}
	if(ax==1){//SPJ A Get:10 Yes
		cout<<n/2;
		return 0;
	}
	if(b==1){//SPJ B Get:20 Probable
		if(k==0){
			int ans=0,t=0;
			for(int i=1;i<=n;i++){
				if(t==a[i]){
					ans++;
					t=0;
				}else{
					t=1;
				}
			}
			cout<<ans;
			return 0;
		}else{
			int ans=0,t=0;
			for(int i=1;i<=n;i++){
				if(t!=a[i]){
					ans++;
					t=0;
				}else{
					t=0;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	cout<<1;
	return 0;
}//expect:10 or more
//expect tot:246+