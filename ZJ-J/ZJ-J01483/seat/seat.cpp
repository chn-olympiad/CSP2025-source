#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],yang;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	cin>>yang;
	a[0]=yang;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+0,a+(n*m),cmp);
	for(int i=0;i<=n*m;i++){
		if(a[i]==yang){
			yang=i;
			break;
		}
	}
	if(yang/n==0){
		cout<<1<<' '<<yang+1<<'\n';
		return 0;
	}
	else if((yang/n)%2==1){
		cout<<(yang/n+1)<<' '<<(n-yang%n)<<'\n';		
	}
	else{
		cout<<(yang/n+1)<<' '<<(yang%n)+1<<'\n';
	}
	return 0;
}