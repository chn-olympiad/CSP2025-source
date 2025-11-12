#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define int long long

string s;
int n,m,c[N],a[N],ans,mod=998244353;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int vi=1;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		if(a[i]==0)	vi=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(vi==1){
		ans=1;
		for(int i=m;i>=1;i--){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
161088479

*/