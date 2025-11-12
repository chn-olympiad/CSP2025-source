#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1ll*998244353;
int n,m,c[510];
bool vis[510];
string s;
ll ans,fra[510];
void dfs(int x,int sum,int cnt){
	if(x>n){
		if(cnt>=m) ans++,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;int p=sum,q=cnt;
			if(sum>=c[i] || s[x]=='0'){
				sum++;
			}else{
				cnt++;
			}
			dfs(x+1,sum,cnt);
			vis[i]=0;sum=p;cnt=q;
		}
	}
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;s=" "+s;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1) flag=false;
	}
	if(flag==true){
		int i;
		ll t=1;
		for(i=1;i<=n;i++){
			t=(t*(n-i+1))%mod;
			if(s[i]=='1'){
				break;
			}
		}
		if(i<m){
			cout<<0<<'\n';
			return 0;
		}
		for(int j=i-1;j>=1;j--){
			t=(t*j)%mod;
		}
		cout<<t<<'\n';
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
