#include<bits/stdc++.h>
using namespace std;
const int N=517;
const int mod=998244353;
int a[N];
bool vis[N];
int t[N];
int n,m,ans;
string s;
bool check(){
	int x=0;
	for(int i=1;i<=n;i++){
		if(x>=a[t[i]]||s[i-1]=='0'){
			x++;
		}
	}
	if(n-x>=m)return true;
	return false;
}
void dfs(int step){
	if(step>n){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			t[step]=i;
			dfs(step+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int k=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
/*

3 2
101
1 1 2 
*/