#include<bits/stdc++.h>
using namespace std;

long long n,m,i,a[505],s,x,mod=998244353;
char c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
	}
	for(i=1;i<=n;i++){
		cin>>c;
		s*=x;
		s%=mod;
	}
	cout<<s<<"\n";
	return 0;
}