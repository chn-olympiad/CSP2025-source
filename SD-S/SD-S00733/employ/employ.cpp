#include<iostream>
using namespace std;
#define int long long
const int N=3e4+5,M=3e6+5;
int n,m,cheng[N],mod=998244353,ans=0,a[N],vis[N];
string s;
void dfs(int cnt,int ok,int lost,int x){//要选第cnt个，成功几个，连续失败几个 第x个人要来了 
	if(cnt==n){
		if(s[cnt]=='1'){
			if(lost<a[x]) ok++;
		}
		if(ok>=m) ans++;
		ans%=mod;
		return ;
	}
	if(s[cnt]=='1'){
		if(lost<a[x]){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				vis[i]=1;
				dfs(cnt+1,ok+1,lost,i);
				vis[i]=0;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				vis[i]=1;
				dfs(cnt+1,ok,lost+1,i);
				vis[i]=0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
				//cout<<x<<" "<<i<<" "<<cnt<<" "<<lost<<endl;
			dfs(cnt+1,ok,lost+1,i);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,0,0,i);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
