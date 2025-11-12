#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct node{
	ll num,s;
}a[210];
bool cmp(node q,node h){
	return q.s>h.s;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(i%2==1){
			for(ll j=1;j<=m;j++){
				cnt++;
				if(a[cnt].num==1){
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
			}
		}else{
			for(ll j=m;j>=1;j--){
				cnt++;
				if(a[cnt].num==1){
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
