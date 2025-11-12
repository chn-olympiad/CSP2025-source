#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
ll n,l[5005],sum[5005],maxn[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(i==0){
			sum[i]=l[i];
			maxn[i]=l[i];
		}
		sum[i]=sum[i-1]+l[i];
		maxn[i]=max(maxn[i-1],l[i]);
	}
	if(n<3) {
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(sum[2]*2>maxn[2]) cout<<1;
	}
	
	return 0;
} 
