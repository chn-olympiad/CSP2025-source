#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans;
string s;
void dfs(int x,int pos,map<int,int> mp,int cnt){
	if(pos>n){
		if(cnt>=m){
			ans++;
		}
		return ;
	}
	if(s[pos]=='0'){
		mp[x]++;
		for(int i=1;i<=n;i++){
			if(!mp[i]){
				dfs(i,pos+1,mp,cnt);
			}
		}
	}
	else{
		mp[x]++;
		for(int i=1;i<=n;i++){
			if(!mp[i]){
				dfs(i,pos+1,mp,cnt+1);
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		dfs(i,1,mp,0);
	}
	cout<<ans;
	return 0;
} 
