#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[101];
char s[101];
long long ans;
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=m+1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
}