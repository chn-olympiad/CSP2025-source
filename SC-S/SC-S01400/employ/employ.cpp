#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
const int N=1e5+5,mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	string s;cin>>s;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		ans=(x*rand()%mod*rand()%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}
