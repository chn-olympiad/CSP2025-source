#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],p[100005],ans;
string x;
bool fA,o[100005];
bool check(){
	int sum=0,op=0;
	for(int i=1;i<=n;i++){
		if(x[i-1]=='1'){
			if(sum<c[p[i]]){
				op++;
				if(op>=m)return 1;
			}
			else sum++;
		}
		else sum++;
	}
	return op>=m;
}
void dfs(int x){
	if(x>n){
		if(check())ans++,ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!o[i]){
			o[i]=1;
			p[x]=i;
			dfs(x+1);
			o[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
}