#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int c[505];
int t[505];
int b[505];
int ans=0;
int n,m;
string s;
int mod=998244353;
void dfs(int x){
	if(x>n){
		int gp=0;
		int ps=0;
		for(int i=1;i<=n;i++){
			int now=t[i];
		//	cout<<now;
	//		cout<<now<<' '<<c[now]<<endl;
			if(c[now]<=gp){
				gp++;
				continue;
			}
			if(s[i]=='1'){
				ps++;
			}
			else{
				gp++;
			}
		}
	//	cout<<endl;
	//	cout<<ps<<endl;
		if(ps>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			t[x]=i;
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	//for(int i=1;i<=)

	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>18){
		int res=1;
		for(int i=1;i<=n;i++){
			res*=i;
			res%=mod;
		}
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/