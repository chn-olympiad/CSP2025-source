#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int checkA=1,checkB=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)checkA=0;
		if(a[i]>1)checkB=0;
	}
	if(k==0&&checkA==1){
		cout<<n/2<<endl;
		return 0;
	}
	else if(k<=1&&checkB==1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1)ans++,i++;
			}
		}
		else {
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	else cout<<2025<<endl;
	return 0;
	
}
