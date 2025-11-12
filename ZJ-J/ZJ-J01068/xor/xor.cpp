#include<iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const int N=5e5+5;
ll a[N];
int main(){
	FASTIO;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0,temp=0;
	for(int i=1;i<=n;i++){
		temp=temp^a[i];
		if(temp==k){
			ans++;
			temp=0;
		}
	}
	cout<<ans;
	return 0;
}
