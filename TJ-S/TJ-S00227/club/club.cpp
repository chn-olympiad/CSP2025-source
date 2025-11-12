#include<iostream>
#include<cstring>
using namespace std;
int t,n,cnt=-114514;
int sts[100005][4];
int vis[5]={0};
void dfs(int x,int su){
	if(x>n){
		cnt=max(cnt,su);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>=(n/2)) continue;
		vis[i]++;
		dfs(x+1,su+sts[x][i]);
		vis[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			cin>>sts[i][1]>>sts[i][2]>>sts[i][3];
			sts[i][0]=i;
		}
		dfs(1,0);
		cout<<cnt<<"\n";
		cnt=-114514;
	}
	
	return 0;
}
//CSP-S Journal
//16:27 Complete Violence DFS.
//      To Be Checked Another Day...
//      Hope To Get 55pts.
//freopen
