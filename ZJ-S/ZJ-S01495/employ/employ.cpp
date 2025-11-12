#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000;

ll n,m,ans,cnt,fail;
string s;
ll c[N];
ll p[N];

void dfs(ll x){
	if(x>=n){
		if(cnt>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==1) continue;
		bool flag=0;
		if(s[x]=='0'||fail>=c[i]){
			fail++;
			flag=1;
		}
		else{
			cnt++;
		}
		p[i]=1;
		dfs(x+1);
		p[i]=0;
		if(flag==1) fail--;
		else cnt--;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	
	return 0;
}
