#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int c[600];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		ans+=(((i+c[i])*114)+s[i])%998244353;
	}
	cout<<ans;
	return 0;

}
