#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==m){
		char s;
		for(int i=1;i<=n;i++){
			cin>>s;
			if(s!=1) {
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans%=998244353;
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
