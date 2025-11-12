#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=998244353;
int n,m,c[11],ans=0,cnt=0;
string s;
int vis[11]={},a[11];
void dfs(int cs){
	if(cs==n){
		int goaway=0,goin=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0')goaway++;
			else if(goaway>=c[a[i]])goaway++;
			else goin++;
		}
		if(goin==m)ans=(ans+1)%M;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[cs]=i;
			dfs(cs+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=0;
			break;
		}
	}
	
	if(flag&&cnt==0){
		if(n==m){
			ll ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%M;
			cout<<ans;
		}else{
			cout<<0;
		}
	}if(m==n){
		if(flag==0||cnt!=0)cout<<0;
		else{
			dfs(0);
			cout<<ans;
		}
	}else{
		dfs(0);
		cout<<ans;
	}
	return 0;
}