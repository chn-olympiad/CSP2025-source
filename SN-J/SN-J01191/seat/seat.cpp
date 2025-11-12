#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,m,a[1001][1001]={},b[10001]={},p=0,q=1;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			p=b[i];
		}
	}
	sort(b,b+n*m+1,cmp);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			a[i][j]=b[q];
			q++;
		}
	}
	q=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(i%2)
			a[i][j]=b[q];
			else if(i%2==0)a[i][m-j+1]=b[q];
			q++;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i][j]==p)
			cout<<i<<' '<<j;
		}
	}
	return 0;
}
