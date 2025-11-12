#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,flag=1;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.length();i++){
		if(s[i]!=1) flag=0;
	}
	int ans=1;
	if(flag){
		int sum0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) sum0++;
		}
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}