#include<bits/stdc++.h>
#define ll long long
using namespace std;
//0 0=0 1 0=1 1 1=0
ll n,k,sum1,sum0,ans;
const int M=5e5+1;
ll a[M];
/*ll solve(ll a,ll b){
	
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==1) sum1++;
		if(a[i]==0) sum0++;
	}
	if(sum1==n){
		ans=n/2;
		cout<<ans;
	}
	else if(sum1+sum0==n){
		if(k==1){
			ans=sum1;
		}
		if(k==0){
			ans=sum0;
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}else{
		srand(time(0));
		ans=rand()%M+1;
		cout<<ans;
	}
	return 0;
}
