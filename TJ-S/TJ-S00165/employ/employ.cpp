#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);///
	cin>>n>>m;
	string s;
	cin>>s;
	int x;
	for(int i=0;i<n;i++){
		if(s[i]=='1')cnt++;
		else break; 
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		ans*=i%998244353;
		ans%=998244353;
	}
	for(int i=1;i<=n-cnt;i++){
		ans/=i;
	}
	cout<<ans;
	return 0;
}
