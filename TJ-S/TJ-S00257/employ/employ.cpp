#include<bits/stdc++.h>

using namespace std;
int a[505],n,m,ans;
bool v[505];
string s;
struct node{
	int x,y,z;
};
vector<node> d;
void dfs(int x,int y){
	if(y>n){
		if(x>=m){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(y-x-1<a[i]){
				if(s[y-1]=='0'){
					dfs(x,y+1);
				}else{
					dfs(x+1,y+1);
				}
			}else{
				dfs(x,y+1);
			}
			v[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0,1);
	cout << ans;
	return 0;
}
