#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5100;
ll n,m,ans,a[N],b[N],x;
bool check(ll cnt){
	ll maxx=INT_MIN,sum=0;
	for(ll i=1;i<=cnt;i++){
		maxx=max(maxx,b[i]);
		sum+=b[i];
	}
	if(maxx*2<sum) return 1;
	return 0;
}
void f(ll cnt,ll s){
	if(cnt==m+1){
		if(check(m)){
			ans++;
			ans%=998244353;
		}else{
			x=1;
		}
		return;
	}
	for(ll i=s+1;i<=n-m+cnt;i++){
		if(x==1){
			x=0;
			return;
		}
		b[cnt]=a[i];
		f(cnt+1,i);
	}
	x=0;
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(m=3;m<=n;m++){
		f(1,0);
	}
	cout<<ans<<'\n';
	return 0;
}
