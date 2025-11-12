#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,ans=1,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
