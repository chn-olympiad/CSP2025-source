#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=100005;
struct node{
	ll n,id;
};
struct club{
	ll mx,mxd,c;
}a[N];
bool cmp(node x,node y){
	return x.n>y.n;
}
bool cmp2(club x,club y){
	return x.mx>y.mx;
}

void solve(){
	ll n;
	cin>>n;
	vector<ll>count(4);
	vector<vector<node>>m(n,vector<node>(4));
	ll mxm=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			cin>>m[i][j].n;
			m[i][j].id=j;
		}
		sort(m[i].begin(),m[i].end(),cmp);
		a[i].mx=m[i][0].n;
		a[i].mxd=m[i][0].id;
		a[i].c=m[i][0].n-m[i][1].n;
		count[a[i].mxd]++;
		mxm+=a[i].mx;
	}
	ll bc=-1;
	for(ll i=0;i<=2;i++){
		if(count[i]>n/2)bc=i;
	}
	if(bc==-1){
		cout<<mxm<<endl;
		return;
	}
	ll cz[N],ci=0;
	for(ll i=0;i<n;i++){
		if(a[i].mxd==bc){
			cz[ci]=a[i].c;
			ci++;
		}
	}
	sort(cz,cz+ci);
	ll cg=ci-n/2;
	for(ll i=0;i<cg;i++){
		mxm-=cz[i];
	}
	cout<<mxm<<endl;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;cin>>t;
	while(t--)solve();
	return 0;
}