#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll x,ll y){
	return x>y;
}
ll n,m,s,p,q;
ll a[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			p=i;
			break;
		}
	}
	q=p%n;
	if(q!=0){
		p=p/n+1;
	}else{
		p/=n;
	}
	cout<<p<<" ";
	if(p%2==0){
		if(q==0){
			cout<<1;
		}else{
			cout<<n-q+1;
		}
	}else{
		if(q==0){
			cout<<n;
		}else{
			cout<<q;
		}
	}
	return 0;
}

