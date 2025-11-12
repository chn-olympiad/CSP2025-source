#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,t,to=0,peo[4]={},hope[maxn]={};

struct ll{
	int f1,f2,f3;
	int al1,al2,al3;
}per[maxn];
int ans=0;
void dfs(int x,int stp,int a,int b,int c){
	if(x==n+1){
		ans=max(ans,stp);
	}
	if(a<n/2){
		dfs(x+1,stp+per[x].f1,a+1,b,c);
	}
	if(b<n/2){
		dfs(x+1,stp+per[x].f2,a,b+1,c);
	}
	if(c<n/2){
		dfs(x+1,stp+per[x].f3,a,b,c+1);
	}
	return ;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			int f1,f2,f3;
			cin>>f1>>f2>>f3;
			per[i].f1=f1;
			per[i].f2=f2;
			per[i].f3=f3;
			
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
		
	}
}
