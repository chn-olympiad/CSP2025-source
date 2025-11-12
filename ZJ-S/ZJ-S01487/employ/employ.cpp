#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
//qian zhui he 
#define N 510
typedef unsigned long long ll;
ll ans=0;
ll mod=998244353;
int n,m,a[N],p[N],s[N],vis[N];//s[i]:failed people vis[i]:if it is full
char c;
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1)return false;
	}
	return true;
}
ll chu(){
	ll sum=1;
	for(int i=2;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	return sum;
}
void dfs(int i,int *g,int cnt){//id qianzhuihe luqurenshu
	if(i==n+1){
		if(cnt>=m)ans++;
		return;
	}
	int pl=lower_bound(g+1,g+n+1,p[i])-g;
	for(int l=1;l<=pl;l++){
		if(vis[l]==1)continue;//have person
		vis[l]=1;
		if(a[l]==0){
			dfs(i+1,g,cnt);
		}else{
			dfs(i+1,g,cnt+1);
		}
		vis[l]=0;
	}
	for(int l=pl+1;l<=n;l++){
		if(vis[l]==1)continue;
		vis[l]=1;
		int *f=g;
		for(int k=l+1;k<=n;k++)f[k]++;
		dfs(i+1,f,cnt);
		vis[l]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
		s[i]=s[i-1]+a[i]^1;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	int tp=0;
	for(int i=1;i<=n;i++){
		if(p[i]==0)tp++;
	}
	if(m==n){
		if(s[n]==0 && p[1]!=0)cout<<chu()%mod<<endl;
		else cout<<"0"<<endl;
		exit(0);
	}
	if(check()){
		int n1=n;
		for(int i=1;i<=n1;i++){
			if(p[i]==0)n--;
			else break;
		}
		cout<<chu()%mod<<endl;
	}
	dfs(1,s,0);
	cout<<ans<<endl;
	return 0;
}