#include<bits/stdc++.h>
using namespace std;
string a;
int b[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i;
	}
	cout<<ans%998244353;
}
