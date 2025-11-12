#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N],r;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		ll c=(i+n-1)/n;
		//cout<<c<<endl;
		if(a[i]!=r) continue;
		if(c%2==1){
			if(i%n!=0) cout<<c<<" "<<i%n;
			else cout<<c<<" "<<n;
			return 0;
		}else{
			if(i%n!=0) cout<<c<<" "<<n-(i%n)+1;
			else cout<<c<<" "<<1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
