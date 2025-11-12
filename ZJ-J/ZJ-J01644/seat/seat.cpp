#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a;
	bool f;
}s[1005];
ll n,m,k,sum;
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>s[i].a;
		s[i].f=0;
	}
	s[1].f=1;
	sort(s+1,s+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(s[i].f==1){
			sum=i;
			break;
		}
	}
	ll num=(sum-1)/n+1;
	cout<<num<<' ';
	ll ans=(sum-1)%n+1;
	if(num%2==1){
		cout<<ans;
	}else{
		cout<<n-ans+1;
	}
	return 0;
}
