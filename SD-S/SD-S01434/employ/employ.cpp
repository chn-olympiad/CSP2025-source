#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,na[505],ans=1;
	char a[505];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>na[i];
	for(int i=1;i<=n;i++) ans*=i;
	cout<<ans%998244353; 
	return 0;
}
