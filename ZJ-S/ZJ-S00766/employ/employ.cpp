#include <bits/stdc++.h>
using namespace std;
long long n,m,i,ak,ans,a[1000];
const long long Mod=998244353;
char s[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++)
		cin>>a[i],ak+=a[i]-48;
	if(m>ak){
		cout<<"0";
		return 0;
	}
	ans=1;
	for(i=1;i<=n;i++){
		ans=ans*i;
		ans=ans%Mod;
	}
	cout<<ans;
	return 0;
}
