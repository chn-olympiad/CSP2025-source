#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,mod=998244353;
int n,m,a[N],cnt=0;
bool vis[N];
string s;
void dfs(int x,int y,int z){
	if(y>=m) cnt=(cnt+1)%mod;
	if(z==s.size()) return;
	if(s[z]=='0'){
		for (int i=1;i<=n;i++){
			if(!vis[i] && a[i]>x){
				vis[i]=1;
				dfs(x+1,y,z+1);
				vis[i]=0;
			}
		}
	}
	else{
		for (int i=1;i<=n;i++){
			if(!vis[i] && a[i]>x){
				vis[i]=1;
				dfs(x,y+1,z+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	for (int i=1;i<=n;i++){
		if(s[i]=='0') flag=false;
	}
	if(flag==true){
		int ans=1;
		for (int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}