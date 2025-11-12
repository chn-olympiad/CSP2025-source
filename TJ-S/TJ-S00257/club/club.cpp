#include<bits/stdc++.h>

using namespace std;
int a[100005][8],n,ans;
int v[100005];
bool v2[100005];
void dfs(int x,int p,int ni){
	if(x>n){
		ans=max(ans,p);
		return ;
	}
	for(int i=ni;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(v[j]+1>n/2 || v2[i]==1){
				continue;
			}
			v[j]++;
			v2[i]=1;
			dfs(x+1,p+a[i][j],ni+1);
			v[j]--;
			v2[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		ans=0;
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v2));
		dfs(1,0,1);
		cout << ans << endl;
	}
	return 0;
}
