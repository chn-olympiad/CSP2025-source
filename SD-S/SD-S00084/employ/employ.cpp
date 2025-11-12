#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=520;
const int mod=998244353;

int n,m;
char s[N];
int c[N];
int ans=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) flag=false;
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	if(!flag){
		cout<<0;
	}else{
		cout<<ans;
	}
	return 0;
}
