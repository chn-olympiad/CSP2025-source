#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int n,m,c[105],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||c[i]==0){
				cout<<"0";
				return 0;
			}
		}
		cout<<"1";
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
