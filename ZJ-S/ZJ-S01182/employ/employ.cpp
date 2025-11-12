#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000,mod=998244353;
int n,m,c[MAXN],cntt,ans,vis[MAXN];
string s;

void dfs(int x,int cntf){
	//cout<<x<<" ";
	if(x>n){
		if(cntt>=m)ans++;
		ans%=mod;
		//cout<<ans<<endl;
		return;
	}
	int f=0,opt=s[x]-'0';
	//cout<<opt<<endl;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(cntf>=c[i]){
			//cout<<1<<" ";
			f++;
			continue;
		}
		vis[i]=1;
		if(opt==1){
			//cout<<2<<" ";
			cntt++;
			dfs(x+1,f);
			cntt--;
		}
		if(opt==0){
			//cout<<3<<" ";
			dfs(x+1,f+1);
		}
		vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')flag=0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(flag==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
//	for(int i=1;i<=n;i++)cout<<c[i]<<endl;
	dfs(1,0);
	cout<<ans<<endl;
}
