#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
const int mod=998244353;
int n,m,c[N],vis[20],a[20],cnt;
long long ans;
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&c[a[i]]>i-cnt-1)cnt++;
	}
	return cnt>=m;
}
void dfs(int step){
	if(step==n+1){
		if(check()){
			ans=(ans+1)%mod;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				a[step]=i;
				vis[i]=1;
				dfs(step+1);
				a[step]=0;
				vis[i]=0;
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==1){
		
	}else if(m==n){
		bool flag=true;
		for(int i=0;i<n;i++)if(s[i]=='0')flag=false;
		if(flag){
			ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans;
		}else cout<<0;
	}else if(n<18){
		dfs(1);
		cout<<ans;
	}else{
		ans=1;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)if(c[i]==0)cnt++;
		cnt=max(cnt-c[n-m+1],0);
		for(int i=1;i<=n-cnt;i++)ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
} //ÆÚÍû12~32 
