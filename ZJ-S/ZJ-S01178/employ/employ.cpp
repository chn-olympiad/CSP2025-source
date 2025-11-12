#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,cnt,cnt1,ans;
char s[1001];
long long c[1001],vis[1001],p[1001];
void dfs(int step){
	if(step==n+1){
		cnt=cnt1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[p[i]]<=cnt) cnt++;
			else cnt1++;
		}
		if(cnt1>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			p[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
void solve1(){
	int tmp=n;
	ans=1;
//	for(int i=1;i<=n;i++){
//		ans=(ans*i)%mod;
//		if(ans==161088479) cout<<"Yes"<<'\n';
//		cout<<i<<" ";
//	}
	for(int i=1;i<=n;i++) if(c[i]==0) tmp--;
	if(tmp<m){
		cout<<0<<endl;
		return;
	}
	ans=1;
//	cout<<tmp<<'\n';
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	if(flag==1){
		solve1();
		return 0;
	}
	cout<<0<<endl;
	return 0;
}