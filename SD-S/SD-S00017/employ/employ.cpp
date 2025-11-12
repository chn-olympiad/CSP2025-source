#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=505,M=4e6+5;
int n,m,c[N],p[N];
string s;
int f[M][20];
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		int flag=0;
		for(int i=1;i<=n;i++) if(s[i]=='0') flag=1;
		for(int i=1;i<=n;i++) if(!c[i]) flag=1;
		if(flag) cout<<0;
		else{
			int ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			cout<<ans;
		}
		return 0;
	}
	if(n<=20){
		iota(p+1,p+1+n,1);
		int ans=0;
		do{
			int now=0,num=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'){
					if(now<c[p[i]]) num++;
					else now++;
				}
				else now++;
			}
			if(num>=m) ans=(ans+1)%mod;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans;
		return 0;
	}
	return 0;
}
