#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C(int x){
	ll ans=1;
	for(int i=1;i<=x;i++)ans=ans*i%998244353;
	return ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	cout<<C(n);
	return 0;
}

