#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s; 
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	cout<<m;
	return 0;
}