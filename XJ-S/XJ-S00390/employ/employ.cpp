#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[505],b[505];
	cin>>n;
	long long c=1;
	for(int i=1;i<=n;i++){
		c=c*i%998244353;
	}
	cout<<c;
	return 0;
}
