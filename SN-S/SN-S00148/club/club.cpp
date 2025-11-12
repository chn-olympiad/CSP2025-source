#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
long long maxn;
void dfs(int step,int n1,int n2,int n3,long long cnt){
	if(n1>n/2||n2>n/2||n3>n/2)return;
	if(step>n){
		maxn=max(cnt,maxn);
		return;
	}dfs(step+1,n1+1,n2,n3,cnt+a[step][0]);
	dfs(step+1,n1,n2+1,n3,cnt+a[step][1]);
	dfs(step+1,n1,n2,n3+1,cnt+a[step][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin >> a[i][j];
		maxn=0;
		dfs(1,0,0,0,0);
		cout << maxn << "\n";
	}return 0;
}
