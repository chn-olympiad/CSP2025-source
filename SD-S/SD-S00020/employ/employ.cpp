#include<iostream>
#include<cstdio> 
#include<string>
using namespace std;
const long long M=998244353;
long long jc[505];int n,m;
bool vis[505];int c[505];
string s;
long long dfs(int d,int cnt){
	if(d==n+1){
		if(cnt>=m)return 1ll;
		else return 0ll;
	}
	if(cnt>=m){
		return jc[n-d+1];
	}
	if(d-cnt-1>n-m)return 0ll;
	long long ans=0ll;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		ans+=dfs(d+1,cnt+int((s[d-1]-'0')&&(c[i]>d-cnt-1)));
		vis[i]=0;
	}return ans%M;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	jc[0]=1ll;
	cin>>s;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%M;
		vis[i]=0;
		cin>>c[i];
	}
	cout<<dfs(1,0);
	return 0; 
} 
