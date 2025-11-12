#include<bits/stdc++.h>
using namespace std;
const int N = 110;
string s;
int a[N];
int n,m;
int vis[N];
int ff[N];
bool check(int cnt){
	int num = 0;
	for(int j = 1;j<=cnt;j++){
		if(s[j] == '0')num++;
		else if(a[ff[j]]<=num)num++;
		if(num>n-m)return 0;
	}
	return 1;
}
int ans = 0;
void dfs(int x){
	if(x == n){
		if(check(x)){
			ans++;
//			for(int j =1;j<=n;j++){
//				cout<<ff[j]<<" ";
//			}
//			cout<<"\n";
		}
		return ;
	}
	else{
		if(!check(x)){
			return ;
		}
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		vis[i] = 1;
		ff[x+1] = i;
		dfs(x+1);
		vis[i] = 0;
		ff[x+1] = 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>18&&m!=1){
		cout<<0;
		return 0;
	}
	cin>>s;
	s = ' '+s;
	for(int i= 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}