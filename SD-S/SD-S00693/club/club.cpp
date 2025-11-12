#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=3e5+10;
int n;
int s[N][4];
int T;
int ans,vis[N];
void print(){
	for(int i=1;i<=3;i++){
		cout<<vis[i]<<' ';
	}
	cout<<'\n';
}void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);//print();
		return ;
	}for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			dfs(x+1,sum+s[x][i]);
			vis[i]--;
		}
	}
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}dfs(0,0);
		cout<<ans<<'\n';
	}return 0;
} 
