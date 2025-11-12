#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e2+5,mod=998244353;
int n,m,s[N],c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;string ss;cin>>ss;int cnt=0;
	for(int i=1;i<=n;i++) s[i]=ss[i-1]-'0',cnt+=s[i],cin>>c[i],c[i]+=i*(n+1);
	if(cnt<m) cout<<0;
	else{
		int ans=0;
		sort(c+1,c+1+n);
		do{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(s[i]==0) sum++;
				else if(sum>=c[i]%(n+1)) sum++;
			}
			if(sum<=n-m) ans++;
		}while(next_permutation(c+1,c+1+n));
		cout<<ans;
	}
	return 0;
}
