#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
const long long mod = 998244353;
int n,m;
long long ans;
int s[N],c[N],p[N],vis[N];
void dfs(int id,int cnt){
	if(n-cnt<m) return ;
	if(id==n+1){
		if(n-cnt>=m){
			ans++;
		}
		ans%=mod;
	}else{
		for(int i = 1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=true;
			p[id]=i;
			if(cnt>=c[i]||s[id]==0) dfs(id+1,cnt+1);
			else dfs(id+1,cnt);
			vis[i]=false;
		}
	}
}
long long A(int x){
	long long ans = 1;
	for(int i = x;i>=2;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int pre[N];
int all[N];
queue<int> q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;
	cin>>str;
	bool can = true;
	int zero = 0;
	for(int i = 1;i<=n;i++){
		s[i]=str[i-1]-'0';
		if(s[i]==0) can = false;
	}
	for(int j = 1;j<=n;j++){
		cin>>c[j];
		if(c[j]==0) zero++;
		if(c[j]==0) pre[j]++;
		all[c[j]]++;
	}
	for(int i = 1;i<=n;i++){
		all[i]+=all[i-1];
		pre[i]+=pre[i-1];
	}
	if(can){
		cout<<A(n);
	}else if(m==1){
		cout<<A(n);
	}else{
		dfs(1,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
