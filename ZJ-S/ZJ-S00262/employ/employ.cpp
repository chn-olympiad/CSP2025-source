#include<iostream>
using namespace std;
const int N=550,mod=998244353;
int c[N],a[N],ans,vt[N],n,m,t[N];
bool vis[N];
void dfs(int x,int cntt,int cntf){
	//cnt 雇佣的
	if(x==n || cntt+n-x<m){
		if(cntt>=m){
			ans++;
			if(ans>=mod) ans%=mod;
		}
		return ;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			t[x+1]=i;
			vis[i]=1;
			if(!vt[x+1] || cntf>=c[i]){//不能招
				dfs(x+1,cntt,cntf+1);
			}
			else{
				dfs(x+1,cntt+1,cntf);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		vt[i+1]=s[i]-'0';
	}
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
