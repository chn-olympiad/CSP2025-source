#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[550];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0,cnt=n;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0){
			cnt--;
		}
	}
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=cnt;
		cnt--;
		ans%=mod;
	}
	for(int j=m+1;j<=n;j++){
		ans*=n-j+1;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
