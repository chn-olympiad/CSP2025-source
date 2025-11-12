#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int a[maxn];
int n;
int vis[maxn];
int ans=0;
void dfs(int depth,int start,int num){
	if (num>=depth+1||start>=n+1){
		int sum=0;
		int maxi=0;
		for (int i=1;i<=n;i++){
			if (vis[i]==1)sum+=a[i];
			maxi=max(maxi,a[i]);
		}
		if (maxi*2<sum)ans++;
		cout << endl;
	}else {
		vis[start]=1;
		cout << start << " ";
		dfs(depth,start+1,num+1);
		vis[start]=0;
		dfs(depth,start+1,num+1);
	}
	
}
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	for (int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout << ans;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
/*
5
1 2 3 4 5
*/
