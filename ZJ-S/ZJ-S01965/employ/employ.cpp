#include <bits/stdc++.h>
using namespace std;
const int MAXN=505;
const long long mod=998244353;
char a[MAXN];
long long c[MAXN],ans=0,path[MAXN],n,m;
bool vis[MAXN];
void dfs(int cnt){
	if(cnt>n){
		int count=0,now=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				now++;
				continue;
			}
			if(c[path[i]]<=now){
				now++;
			}else{
				count++;
			}
		}
		if(count>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			path[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool oka=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!='1'){
			oka=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(oka){
		int cnt=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cnt--;
			}
		}
		n=cnt;
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
