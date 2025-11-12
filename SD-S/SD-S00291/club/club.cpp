#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int a,b,c;
}S[114514];
int t,n;
int ans=-1;
void check(int sum){
	ans=max(ans,sum);
	return;
}
void dfs(int x,int a,int b,int c,int sum){
	if(x==n+1){
		check(sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && a<n/2){
			dfs(x+1,a+1,b,c,sum+S[x].a);
		}if(i==2 && b<n/2){
			dfs(x+1,a,b+1,c,sum+S[x].b);
		}if(i==3 && c<n/2){
			dfs(x+1,a,b,c+1,sum+S[x].c);
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>S[i].a>>S[i].b>>S[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
