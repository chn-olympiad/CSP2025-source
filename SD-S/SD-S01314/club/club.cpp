#include<bits/stdc++.h>
using namespace std;
int t,n,dp[1010][5][1010];
struct p{
	int a,b,c;
};
p s[100010];
int dfs(int x,int y,int ss,int aa,int bb,int cc){
	if(aa>n/2||bb>n/2||cc>n/2){
		return 0;
	}
	if(x==n){
		return ss;
	}
	return max(max(dfs(x+1,1,s[x+1].a+ss,aa+1,bb,cc),dfs(x+1,2,s[x+1].b+ss,aa,bb+1,cc)),dfs(x+1,3,s[x+1].c+ss,aa,bb,cc+1));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		cout<<max(max(dfs(1,1,s[1].a,1,0,0),dfs(1,2,s[1].b,0,1,0)),dfs(1,3,s[1].c,0,0,1))<<"\n";
	}
	return 0;
}
