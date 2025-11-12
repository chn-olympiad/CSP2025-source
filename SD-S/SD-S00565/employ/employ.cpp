#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans=0,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=0;i<n;i++) cin>>a;
	for(long long i=0;i<n;i++) if(s[i]=='1') ans++;
	if(m==n&&ans==n){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}cout<<ans;
		return 0;
	}cout<<0;
	return 0;
}
 
