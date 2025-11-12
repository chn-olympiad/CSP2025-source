#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
long long mod=998244353;
string s;
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n;i++){
		cin>>c[i];
		ans=ans*i%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
