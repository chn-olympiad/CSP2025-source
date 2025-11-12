#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace	std;
const int N=505;
int n,m,c[N],numA;
char s[N];
bool flagA=1;
int code_A(){
	if(n!=m)return 0;
	int mel=1;
	for(int i=1;i<=n;i++){
		mel=mel*i%mod;
	}
	return mel;
}
signed main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int t=s[i]-'0';
		if(!t)flagA=0;
	}
	if(flagA)cout<<code_A();
	return 0;
}