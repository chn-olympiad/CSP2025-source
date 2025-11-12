#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=5e2+5,mod=998244353;
int n,m,c[MAX];
ll a[MAX];
ll A(int x,int y){
	return(a[x]/a[x-y]);
}
string s;
void init(){
	a[0]=1;
	ll mul=1;
	for(ll i=1;i<=505;i++){
		mul=((mul*i)+mod)%mod;
		a[i]=mul;
	}
}
void solve(){
	cin>>n>>m>>s;
	init();
	for(int i=1;i<=n;i++)cin>>c[i];
	int len=s.size();
	bool flag=false;
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			flag=true;
			break;
		}
	}
	if(flag){
		if(m==1)cout<<A(n-1,n-1)<<'\n';
		else cout<<A(n,m)<<'\n';
	}else cout<<"0\n";
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}