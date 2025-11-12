#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct hbc{
	ll s,sum;
}a[110];
ll n,m,k,c,r;
bool cmp(hbc x,hbc y){
	if(x.sum>y.sum)return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(ll i=1;i<=k;i++){
		cin>>a[i].sum;
		a[i].s=i;
	}
	sort(a+1,a+k+1,cmp);
	c=1;
	bool f=1;
	for(ll i=1;i<=k;i++){
		if(f==1)r++;
		if(f==0)r--;
		if(r>n){
			r=n;
			c++;
			f=0;
		}
		if(r<1){
			r=1;
			c++;
			f=1;
		}
		if(a[i].s==1){
			cout<<c<<" "<<r;
		}
	}
}