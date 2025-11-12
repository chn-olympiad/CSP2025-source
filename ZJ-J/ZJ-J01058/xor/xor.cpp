#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10; 
int n,k,sum,ans;
bool x=1;
int a[N],b[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sum++;
		if(a[i]>1)x=0;
		b[i]=b[i-1]^a[i];
	}
	if(sum==n){
		if(k==1)cout<<n;
		else if(k==0)cout<<n/2;
		else cout<<0;
		return 0;
	}else if(x){
		sum=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)sum++;	
				else if(a[i+1]==1){
					sum++;
					i++;
				}
			}
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
				else if(a[i+1]==1){
					sum++;
					i++;
				}
			}
		}else{
			cout<<0;
			return 0;
		}
		cout<<sum;
		return 0;
	}else{
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((b[r]^b[l-1])==k){
					ans++;
					l=r;
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}