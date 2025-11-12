#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=505;
char b[N];
int main(){
	freopen("empoly.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	ll ch=1,mod=998244353;
	for(ll i=1;i<=n;i++){
		ch=(ch*i)%mod;
		cout<<i<<"\n";
	}
	cout<<ch<<"\n";
	return 0;
}

