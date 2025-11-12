#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,mod=998244353;
int p[N],c[N],n,m,ans,checka=1,flag[N],xl[N];
char s[N];
bool check(){
	int f=0,l=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'&&f<c[xl[i]])l++;
		else f++;
	}
	return (l>=m);
}
void dfs(int now){
	if(now==n+1){
		if(check())ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1,xl[now]=i;
			dfs(now+1);
			flag[i]=0;
		}
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i],checka&=(s[i]-'0');
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(checka){
		int sum=1;
		for(int i=2;i<=n;i++)
			sum*=i,sum%=mod;
		cout<<sum<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
