#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5001],ans;
void dg(int t,long long s,long long mx,int x){
	if(t==n+1){
		if(x>=3&&s>2*mx)
			ans++;
		return ;
	}
	dg(t+1,s,mx,x);
	mx=max(mx,a[t]);
	s+=a[t];
	dg(t+1,s,mx,x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dg(1,0,0,0);
	cout<<ans%mod;
}
