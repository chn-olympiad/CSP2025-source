#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=507,mod=998244353;
int n,m,c[N],ans,p[N],used[N];
string s;

void dfs(int x){
	if(x>n){
		int fail=0;
		for(int i=1;i<=n;++i){
			if(c[p[i]]<=fail||!(s[i]-'0')){
				++fail;
				continue;
			}
		}
		if(n-fail>=m)
			(++ans)%=mod;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!used[i]){
			used[i]=1;
			p[x]=i;
			dfs(x+1);
			used[i]=0;
		}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s='7'+s;
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	if(m==n){
		for(int i=1;i<=s.size();++i)
			if(s[i]=='0'){
				cout<<"0\n";
				return 0;
			}
		for(int i=1;i<=n;++i)
			if(c[i]==0){
				cout<<"0\n";
				return 0;
			}
		int res=1;
		for(int i=1;i<=n;++i)
			(res*=i)%=mod;
		cout<<(res%mod+mod)%mod;
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
