#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[110],x,id,ansx,ansy;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++)if(a[i]==x)id=i;
	ansx=(id+n-1)/n;
	if(ansx%2==1){
		if(id%m==0)ansy=m;
		else ansy=id%m;
	}else{
		if(id%m==0)ansy=1;
		else ansy=m-(id%m)+1;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
}

