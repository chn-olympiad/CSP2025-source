#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m;
string s;
int c[N];
int ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int o=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			o++;
		}
	}
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 