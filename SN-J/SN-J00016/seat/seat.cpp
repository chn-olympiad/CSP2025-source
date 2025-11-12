//SN-J00016
//666这么糖的题目卡半个小时 (我好像写假了 
#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ll n,m,a[100005]; 
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	cout<<"RP++";
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
			break;
		}
	}
	//cout<<b<<" ";
	int c=(b%n==0?b/n:b/n+1);
	cout<<c<<" ";
	if(c%2==1)cout<<(b%n==0?n:b%n);
	else cout<<(b%n==0?1:n-b%n+1);
	return 0;
}
