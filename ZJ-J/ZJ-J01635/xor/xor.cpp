#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],vis[N],cnt0,cnt1,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		cnt0+=(a[i]==0);
		cnt1+=(a[i]==1);
	}
	if(k==0&&n<=2){
		cout<<max(cnt0,1);
		return 0;
	}
	if(k==0&&n<=100&&cnt1==n){
		cout<<n/2;
		return 0;
	}
	if(k<=1){
		if(k==1){
			cout<<cnt1;
			return 0;
		}
		if(k==0){
			int ans=cnt0;
			for(int i=1;i<n;++i){
				if(!vis[i]) ans+=(a[i]==1&&a[i+1]==1);
				vis[i]=1;
				vis[i+1]=1;
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
