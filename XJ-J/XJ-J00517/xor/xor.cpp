#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll k,n,a[N],t[N],ans=0;
int sum=0,sum1=0;
unsigned long long mod=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=33;i++){
		mod*=2;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum++;
		}
		if(a[i]==0){
			sum1++;
		}
		if(a[i]==k){
			ans++;
			a[i]=mod;
		}
	}
	if(sum==n){
		cout<<n/2;
		return 0;
	}
	if(sum1+sum==n){
		if(k==1){
			cout<<sum;
		}else{
			cout<<sum1+sum/2; 
		}
		return 0;
	}
	for(int i=1;i<n;i++){
		t[i]=(a[i]^a[i+1]);
		if(t[i]==k){
			ans++;
			t[i]=mod;
		}
	}
	int i=1;
	while(i<n-1){
		for(int j=1;j<=n-i;j++){
			if(t[j]!=mod){
				t[j]=(t[j]^t[j+1]); 
			}
			
		}
		for(int j=1;j<=n-i;j++){
			if(t[j]==k){
				ans++;
				t[j]=mod;
			}
		}
		i++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

