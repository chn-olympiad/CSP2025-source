#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
const int N=505,mod=998244353;
int n,m;
char s[N];
int op[N],c[N];
ll calc(int n){
	ll res=1;
	for(int i=1;i<=n;++i) res=res*i%mod;
	return res;
}
namespace S1{
	int a[15];
	void solve(){
		ll ans=0;
		for(int i=1;i<=n;++i) a[i]=i;
		do{
			int cnt=0,sum=0;
			for(int i=1;i<=n;++i){
				if(cnt>=c[a[i]]){
					cnt++;
					continue;
				}
				if(op[i]==0) cnt++;
				else sum++;
			}
			if(sum>=m) ans++;
		}while(next_permutation(a+1,a+1+n));
		cout<<ans%mod<<endl;
	}
}
namespace S2{
	void solve(){
		cout<<0<<endl;
	}
}
namespace S3{
	void solve(){
		if(m==n){
			int flag=0;
			for(int i=1;i<=n;++i){
				if(op[i]==0||c[i]==0) flag=1;
			}
			if(flag) cout<<0<<endl;
			else cout<<calc(n)<<endl;
			return ;
		}
		cout<<calc(n)<<endl;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		op[i]=s[i-1]-'0';
		cin>>c[i];
	}
	if(n<=10) S1::solve();
	else if(m==1) S2::solve();
	else S3::solve();
	return 0;
}
