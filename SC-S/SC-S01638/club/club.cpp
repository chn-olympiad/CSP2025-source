#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c;
}p[100005];
int t,n,mx,my,mz,m;
void dfs(int k,int x,int y,int z,int s){
	if(x>n/2||y>n/2||z>n/2)return ;
	if(k>n){
		m=max(m,s);
		return; 
	}
	dfs(k+1,x+1,y,z,s+p[k].a);
	dfs(k+1,x,y+1,z,s+p[k].b);
	dfs(k+1,x,y,z+1,s+p[k].c);
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<m<<"\n";
	}
	return 0;
} 