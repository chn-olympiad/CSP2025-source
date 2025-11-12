#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,in1;
ll k=1,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(ll i=1;i<n*m;++i){
		cin>>in1;
		if(in1>r){
			++k;
		}
	}
	ll zs=(k-1)/(n<<1)+1;
	ll is=(k-1)%(n<<1)+1;
	cout<<((zs-1)*2+(is<=n?1:2))<<' '<<(is<=n?is:(n<<1)-is+1);
	return 0;
}
