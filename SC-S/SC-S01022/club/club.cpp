#include<bits/stdc++.h>
using namespace std;
int n,t;
long long maxx;
long long a[100005][4];
int forbid[4];
void dfs(int s,long long sum){
	if(s==n+1){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(forbid[i]>=n/2) continue;
		forbid[i]++;
		dfs(s+1,sum+a[s][i]);
		forbid[i]--;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int bj=0;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			forbid[1]=forbid[2]=forbid[3]=0;
			if(a[i][2]!=a[i][2]||a[i][2]!=0) bj=1;
		}
		if(bj==0){
			int sz[100005];
			for(int i=1;i<=n;i++) sz[i]=a[i][1];
			sort(sz+1,sz+n+1,cmp);
			cout<<sz[1]+sz[2]<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<maxx<<'\n';
	}
	return 0;
}
//注意关注释