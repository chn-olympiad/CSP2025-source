#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,nd[1017],nx[1017],vis[1017],ans=0,cnt0=0;
string a;
void dfs(long long id,long long fl){
	if(n-fl<m){
		return;
	}
	if(id==n&&(n-fl)>=m){
		ans=((ans+1)%MOD+MOD)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			bool flag=false;
			if(nd[id+1]==0||nx[i]<=fl){
				fl++;
				flag=true;
			}
			dfs(id+1,fl);
			vis[i]=0;
			if(flag){
				fl--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			nd[i+1]=1;
		}else{
			nd[i+1]=0;
			cnt0++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>nx[i];
	}
	if(n-cnt0<m){
		cout<<0<<endl;
		return 0;
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}