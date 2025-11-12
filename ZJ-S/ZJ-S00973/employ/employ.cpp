#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[510]= {0};
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	long long res=0;
	for(long long i=1;i<=n;i++){
		res=res*i%998244353;
	}
	cout<<res;
	return 0;
}
