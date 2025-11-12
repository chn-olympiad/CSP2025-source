#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool vis[5010];
void dfs(int t,int num,int sum,int mx){
	if (num>=3){
		if (sum>mx*2){
			ans++;
		}
	}
	if (t>n){
		return ;
	}
	for (int i=t;i<=n;i++){
		if (vis[i]){
			continue;
		}
		vis[i]=1;
		dfs(i+1,num+1,sum+a[i],max(mx,a[i]));
		vis[i]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,-1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

