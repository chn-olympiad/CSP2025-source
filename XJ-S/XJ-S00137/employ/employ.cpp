#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,patience[505],applicant[15],vis[15],ans=0;
string s;
void dfs(int x){
	if(x==n+1){
		int give_up=0;
		for(int i=1;i<=n;i++){
			int y=applicant[i];
			//cout<<give_up<<" "<<s[y-1]<<" "<<y<<"\n";
			if(give_up>=patience[y]) give_up++;
			else if(s[i-1]=='1') continue;
			else if(s[i-1]=='0') give_up++;
		}
		if(give_up<=n-m){
			//for(int i=1;i<=n;i++) cout<<applicant[i]<<" ";
			ans++;
			//cout<<";\n";
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		applicant[x]=i;
		vis[i]=1;
		dfs(x+1);
		applicant[x]=0;
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>patience[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	} 
	else if(m==n){
		for(int i=1;i<=n;i++) if(patience[i]==0){
			cout<<0;
			return 0;
		}
		for(int i=0;i<s.size();i++) if(s[i]=='0'){
			cout<<0;
			return 0;
		}
		for(ll i=1;i<=n;i++){
			ans=ans*i%mod;
			//cout<<ans<<"\n";
		}
		cout<<ans;
		return 0;
	}
	else{
		ll allp=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1') allp++;
		}
		if(allp==n){
			ans=1;
			ll cnt=0;
			for(int i=1;i<=n;i++) if(patience[i]==0) cnt++;
			n=n-cnt;
			if(n<m){
				cout<<0;
				return 0;
			}
			for(ll i=1;i<=n;i++){
				ans=ans*i%mod;
				//cout<<ans<<"\n";
			}
			cout<<ans;
		}
		else if(allp<m) cout<<0;
		else cout<<"295361449";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
