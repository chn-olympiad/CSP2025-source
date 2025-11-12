#include<bits/stdc++.h>
using namespace std;
int t,n;
struct no{
	int a,b,c;
}m[100005];
inline int dfs(int a,int b,int c,int i,int s){
	if(i>n){
		return s;
	}
	int x=0;
	if(a<n/2){
		x=max(x,dfs(a+1,b,c,i+1,s+m[i].a));
	}
	if(b<n/2){
		x=max(x,dfs(a,b+1,c,i+1,s+m[i].b));
	}
	if(c<n/2){
		x=max(x,dfs(a,b,c+1,i+1,s+m[i].c));
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		cout<<dfs(0,0,0,1,0)<<"\n";
	}
	return 0;
}