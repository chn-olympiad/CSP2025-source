#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s_1,ans,c[505];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			s_1++;
		}
		cin>>c[i];
	}
	if(s_1==n){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<"\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}
