#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s[N][2],x,y;
int ans=0,n,q;
bool used[N];
bool can(int st,string s){
	for(int i=0;i<s.size();i++){
		if(x[st+i]!=s[i])return false;
	}
	return true;
}
void work(int st,string s){
	for(int i=0;i<s.size();i++){
		x[st+i]=s[i];
	}
}
void dfs(){
	if(x==y){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			for(int j=0;j<x.size();j++){
				if(can(j,s[i][0])){
					work(j,s[i][1]);
					used[i]=1;
					dfs();
					used[i]=0;
					work(j,s[i][0]);
				}
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		dfs();
		cout<<ans<<"\n";
	}
	return 0;
}

