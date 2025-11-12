#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5500;
const ll mod=998244353;
ll n,a[N],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<n);i++){
		ll mx=0,sum=0;
		for(int j=0;j<=n;j++){
			if((i>>j)&1){
				sum+=a[j+1];
				mx=max(mx,a[j+1]);
			}
		}
		if(sum>2*mx){
			ans+=1;
			ans=ans%mod;
		}
	}
	cout<<ans;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
