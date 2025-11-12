#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n;cin>>n; 
	cout<<n*(n-1)*(n-2)%998244353;
	return 0;
}
