#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
string s;
int c[25];
int p[25];
int cnt=0;
void dfs(int pos,int gs){
	if(pos==n+1){
		int ans=0,sh_b=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]<=sh_b){
				sh_b++;
			}
			else if(s[i]=='0'){
				sh_b++;
			}
			else{
				ans++;
			}
		}
		if(ans>=m){
			cnt++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if((gs&(1<<(i-1)))==0){
			p[pos]=i;
			dfs(pos+1,gs|(1<<(i-1)));
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<cnt<<'\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
