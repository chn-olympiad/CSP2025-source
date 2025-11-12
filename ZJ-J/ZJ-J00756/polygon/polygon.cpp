#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e4+1;
const ll M=998244353;
ll n;
ll ans=0;
ll num[N];
void f(ll k,ll zh,ll ma,ll m){
	if(k>=n or m>=n)
		return;
	for(int i=k;i<n;i++){
		if(m+1>=3 and (num[i]+zh+1)/2>max(ma,num[i])){
			ans++;
//			cout<<m<<' ';
		}f(i+1,zh+num[i],max(ma,num[i]),m+1);
	}ans=ans%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}f(0,0,0,0);
	cout<<ans;
	return 0;
}
