#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string st;
long long ans=1;
int n,m,s[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>st;
	for(int j=1;j<=n;j++)
	cin>>s[j];
	for(int i=1;i<=n;i++)
	ans=((ans%998244353)*(i%998244353))%998244353;
	cout<<ans%998244353;
	return 0;
}     
