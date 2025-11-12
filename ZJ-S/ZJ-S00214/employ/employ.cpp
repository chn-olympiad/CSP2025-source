#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005],tot,ans=1;
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])tot++;
	}
	if(m==n){
		cout<<"0";
		return 0;
	}
	if(tot<m){
		cout<<"0";
		return 0;
	}
	else {
		for(int i=1;i<=tot;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
