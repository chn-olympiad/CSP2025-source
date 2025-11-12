#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+100;
const ll M=998244353;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll sum=1;
	int x=n;
	int o=0;
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		if(z==o){
			x--;
			o++;
		}
	}
	for(ll i=1;i<=x;i++){
		sum*=i;
		sum%=M;
	}
	cout<<sum;

}
