#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+21;
int dp[N][3],vis[N];

struct node{
	int a,b,c;
}cl[N];
int t,n,s = 0;
void dfs(int k,int d,int x,int y,int z){
	if(d == n){
		s = max(k,s);
		return ;
	}
	for(int i=1;i<=3;i++){
		int sum = 0;
		for(int j=d+1;j<=n;j++){
			sum+=vis[j];
			
		}
		if(sum + k <= s){
			return ;
		}
		if(i == 1){
			if(x+1 > n/2) continue;
			dfs(k+cl[d+1].a,d+1,x+1,y,z);
		}
		if(i == 2){
			
			if(y+1 > n/2) continue;
			dfs(k+cl[d+1].b,d+1,x,y+1,z);
		}
		if(i == 3){
			if(z+1 > n/2) continue;
			dfs(k+cl[d+1].c,d+1,x,y,z+1);
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
			vis[i] = max(cl[i].a,max(cl[i].b,cl[i].c));
		}
		dfs(0,0,0,0,0);
		cout<<s<<endl;
	}
	return 0;
} 

