#include <iostream>
#include <cstdio>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[510];
long long ans;
bool vis[510];
int b[510];
void dfs(int t,int sum){
	if((t>n)&&(sum>=m)){
		int tmp=sum;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[b[i]]){
				cnt++;
				tmp--;
			}else if(s[i-1]=='0')cnt++;
		}
		if(tmp>=m)ans++;
		ans%=mod;
		return ;
	}
	if(t>n&&sum<m)return ;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}else{
			vis[i]=1;
			b[t]=i;
			if(s[t-1]=='1'){
				dfs(t+1,sum+1);
			}else{
				dfs(t+1,sum);
			} 
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}

