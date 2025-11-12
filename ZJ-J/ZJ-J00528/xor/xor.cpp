#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],sum[500005],su,ans;
bool flag=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1){
			flag=true;
		}
	}
	if(!flag&&k==0){
		cout<<n/2;
		return 0;
	}
	else  if(!flag&&k==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum[i-1]^sum[j]==k){
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
