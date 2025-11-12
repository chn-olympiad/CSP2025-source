#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=550;
const ll MOD=998244353;
int n,m,c[N],a[N],ans,one;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		iota(a+1,a+n+1,1);
		do{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++){
				if(cnt+n-i+1<m) break;
				if(sum<c[a[i]]){
					if(s[i]=='1') cnt++;
					else sum++;
				}else sum++;
			}
			if(cnt>=m){
				ans++;
			}
			ans%=MOD;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
	}else{
		if(m==n){
			bool flag1=1;
			for(int i=1;i<=n;i++) if(s[i]=='0') flag1=0;
			if(flag1){
				ll ans1=1;
				for(ll i=1;i<=n;i++) ans1=ans1*i%MOD;
				cout<<ans1;
			}else{
				cout<<0;
			}
		}else{
			bool flag1=1;
			for(int i=1;i<=n;i++) if(s[i]=='0') flag1=0;
			if(flag1){
				ll cnt1=1;
				for(ll i=1;i<=n;i++) cnt1=cnt1%MOD*i%MOD;
				cout<<cnt1*(ll)ceil((n+1)/m)%MOD;
			}
		}
	}
	return 0;
}

