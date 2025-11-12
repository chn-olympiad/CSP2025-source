#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 200050
#define M 5000050
typedef long long ll;
typedef pair<ll,ll> pii;
#define int long long
#define mod 998244353

bitset<1005> b;
int n,m;
ll cnt=0,ans=1;
int a[505];
ll mul(int n){
	ll res=1;
	for(int i=1; i<=n; i++)
		res=res*i%mod;
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	cin>>b;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]!=0) cnt++;
	}
	if(m==n){
		if(b.count()==n&&cnt==n){
			cout<<mul(n);
		}
		else cout<<0;
	}else cout<<0;
	
	return 0;
}
