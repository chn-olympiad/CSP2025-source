#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],s1,s2,f[505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
		if(s[i]=='1') s1++;
		else s2++;
	}
	if(m==1){
		if(s[1]!='0'||(s[1]=='0'&&f[0]==0)){
			long long ans=1;
			for(int i=n;i>=1;i--){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}else{
			long long ans=1;
			for(int i=n-f[0];i>=1;i--){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}
		return 0;
	}
	long long ans=1;
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
		}
	cout<<ans;
	return 0;
}
