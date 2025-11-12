#include <bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
string s;
int c[N];
bool vis[N];
int q[N];	//用于全排列 
int ans;
void dfs(int d){
	if(d==n+1){
		int sum=0;	//放弃、拒绝 
		for(int i=1;i<=n;i++){
			if(sum>=c[q[i]]){
				sum++;
				continue;
			}
			if(s[i]=='0'){
				sum++;
			}
		}
		if((n-sum)>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			q[d]=i;
			dfs(d+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

