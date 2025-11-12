#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,k,a[N],ans,sum1[N],sum2[N],f;
void ta1(){
	sum1[1]=a[1];
	for(int i=2;i<=n;i++){
		sum1[i]=a[i]^sum1[i-1];
	}
	sum2[n]=a[n];
	for(int i=n-1;i>=1;i--){
		sum2[i]=sum2[i+1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){//j~i
			if(((sum1[n]^sum1[j-1])^sum2[i+1])==k){
				ans++;
			}
		}
	} 
	cout<<ans;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	if(f==1){
		ta1();
	} else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else{
				if(i<n&&a[i+1]==1){
					ans++;
					i++;
				} 
			}
		}
		cout<<ans;
	} else{
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	return 0;
}
