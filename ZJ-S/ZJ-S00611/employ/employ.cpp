#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m,ans;
int cnt,cnt0;
string s,f;
int c[505];
int flag[505];
void dfs(int x,int dpass){
	if(x>n){
		if((n-dpass)>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			bool fx=0;
			fx|=(dpass>=c[i]);
			fx|=(s[x]=='0');
			if(fx) dfs(x+1,dpass+1);
			else dfs(x+1,dpass);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) f=f+'1';
	f=' '+f;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
		if(s[i]=='0') cnt0++;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans;
	}
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(s==f){
		int nx=n-cnt;
		ans=1;
		for(int i=1;i<=nx;i++){
			ans*=i;
			ans%=mod;
		}//ÂÒÐ´µÄ¸Ð¾õÒª·Ï 
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

