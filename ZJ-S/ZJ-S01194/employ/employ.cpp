#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int Mod = 998244353;
int c[N];
int trybest[15];
int n,m;
string s;
long long ans=0;
bool flag=true;
bool vis[15];
void dfs(int now,int *zl){
	if(now==n+1){
		int cntfalse=0;
		int cnttrue=0;
		for(int i=1;i<=n;i++){
			int pre=zl[i];
			if(s[i-1]=='0' || cntfalse>=c[pre]){
				cntfalse++;
			}
			else{
				cnttrue++;
			}
		}
		if(cnttrue>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			zl[i]=now;
			vis[i]=true;
			dfs(now+1,zl);
			vis[i]=false;
		}
	}
}
int main() {
	memset(vis,false,sizeof(vis));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(1,trybest);
	cout<<ans<<endl;
	return 0;
}