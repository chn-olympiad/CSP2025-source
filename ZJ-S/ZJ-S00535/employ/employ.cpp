#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,mod=998244353;
ll f[1<<18][19];
int a[N],pre[N];
void add(ll &x,ll y){
	x=((x+y)%mod+mod)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int n,m,_=0;cin>>n>>m;string s;cin>>s;s="*"+s;
	for(int i=1;i<=n;i++) _=_+s[i]-'0';
	if(_<m){
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<n;i++) cin>>a[i];
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<=n;j++){
				int k=__builtin_popcount(i),w=f[i][j];
				if(!w) continue;
				if(s[k+1]=='0'){
					for(int p=0;p<n;p++){
						if((i>>p)&1) continue;
						add(f[i|(1<<p)][j],w);
					}
				}else{
					int bad=k-j;
					for(int p=0;p<n;p++){
						if((i>>p)&1) continue;
						if(a[p]>bad) add(f[i|(1<<p)][j+1],w);
						else add(f[i|(1<<p)][j],w);
					}
				}
			}
		}
		ll ans=0;
		for(int i=m;i<=n;i++) add(ans,f[(1<<n)-1][i]);
		cout<<ans<<"\n";
		return 0;
	}
	if(n==m){
		ll f=1;
		for(int i=1;i<=n;i++){
			if(!a[i]){
				f=0;
				break;
			}
		}
		for(int i=1;i<=n;i++) f=f*i%mod;
		cout<<f<<"\n";
		return 0;
	}
	cout<<"0\n";
	return 0;
}
