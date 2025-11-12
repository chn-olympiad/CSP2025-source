#include<bits/stdc++.h>
using namespace std;
bool na[505],a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	long long ans=1;
	string st;cin>>st;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
}