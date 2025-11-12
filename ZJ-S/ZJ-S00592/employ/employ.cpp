#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,m,c[501],s[501];
void A(){
	int t[501],cnt=0,b[501];
	memset(t,0,sizeof(t));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		if(s[i]){
			t[++cnt]=i;
		}
		for(int j=c[i]+1;j<=n;j++)b[j]++;
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int l=0;
		for(int j=1;j<=n;j++){
			if(c[j]>=t[i])l++;
		}
		for(int j=1;j<i;j++){
			l=l*(b[t[j]]-j+1)%mod;
		}
		for(int j=1;j<=n-i;j++)l=l*j%mod;
		ans=(ans+l)%mod;
	}
	cout<<ans<<endl;
//	cerr<<ans<<endl;
}
void B(){
	return;
}
int a[11],vis[11];
int check(){
	int now=0,oks=0;
	for(int i=1;i<=n;i++){
		if(now>=c[a[i]]){
			now++;
			continue;
		}
		if(s[i])oks++;
		else now++;
	}
	return oks>=m?1:0;
}
int dfs(int d){
	if(d==n)return check();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[d+1]=i;
		ans+=dfs(d+1);
		vis[i]=0;
	}
	return ans;
}
void C(){
	cout<<dfs(0)<<endl;
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;
	getline(cin,st);
	getline(cin,st);
	int ones=0;
	for(int i=1;i<=n;i++){
		s[i]=st[i-1]^'0';
		ones+=s[i];
	}
	if(ones<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)C();
	else if(m==n)B();
	else if(m==1)A();
	else cout<<0<<endl;
	return 0;
}
//11.1 18:27
//code by K.S.
//want 35 pts.
