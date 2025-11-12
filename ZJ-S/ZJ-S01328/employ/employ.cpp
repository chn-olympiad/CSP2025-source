#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
const int mod=998244353;
int a[110];
bool v[110];
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
void dfs(int x,int fal){
	if(x==n+1){
//		cout<<fal<<"\n";
		if(n-fal>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(v[i]==false){
			v[i]=true;
			if(fal>=a[i]||s[x-1]=='0') dfs(x+1,fal+1);
			else dfs(x+1,fal);
			v[i]=false;
		}
}
int main(){
	youhua();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<ans;
}


