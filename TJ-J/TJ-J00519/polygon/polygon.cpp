#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD=998244353;
ll n,cnt=0,sum=0,maxn=INT_MIN;
ll a[5000+10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=3;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll l=j;l<=j+i;l++){
				sum+=a[l];
				maxn=max(maxn,a[l]);
			}
			if(sum>maxn*2){
				cnt++;
			}
			sum=0;
			maxn=INT_MIN;
		}
	}
	cout<<cnt%MOD;
	return 0;
}
