#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1 and A)A=1;
		else A=0;
	}
	if(A){
		cout<<n/2;
		return 0;
	}
	bool B=1;
	for(int i=1;i<=n;i++){
		if(a[i]>=0 and a[i]<=1 and B)B=1;
		else B=0;
	}
	if(B){
		ll ones=0;
		for(int i=1;i<=n;i++){
			ones+=a[i];
		}
		if(k==1)cout<<ones;
		else{
			int now=0,ans=0;
			for(int i=1;i<=n;i++){
				if(now==2){
					ans++;
					now=0;
				}
				if(a[i]==0){
					now=0;
				}else{
					now++;
				}
			}
			if(now==2){
				ans++;
				now=0;
			}
			cout<<n-ones+ans;
		}
	}
	return 0;
}
