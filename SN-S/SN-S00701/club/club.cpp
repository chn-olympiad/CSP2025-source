#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll t,n,a[maxn][3],lm=-1,x[maxn],y[maxn],z[maxn];
int b[3];
void dfs(int i,int u,int yu[3],ll tot){
	if(i==n){
		lm=max(lm,tot);
		return ;
	}
	yu[u]++;
	for(int v=0;v<=2;v++){
		if(yu[v]<(n/2))dfs(i+1,v,yu,tot+a[i+1][v]);
	}yu[u]--;
	return ;
}
void clear(){
	b[0]=0,b[1]=0,b[2]=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		lm=-1;
		bool flaga=1;
		cin>>n;
		if(n<=30){
			for(int i=1;i<=n;i++){
				cin>>a[i][0]>>a[i][1]>>a[i][2];
				if(a[i][1]!=0||a[i][2]!=0)flaga=0;
			}
			clear();dfs(1,0,b,a[1][0]);
			clear();dfs(1,1,b,a[1][1]);
			clear();dfs(1,2,b,a[1][2]);
			cout<<lm<<endl;
		}else if(flaga==1){
			for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>z[i];
			ll tot=0;
			sort(x+1,x+n+1);
			for(int i=1;i<=(n/2);i++){
				tot+=a[i][0];
			}
			cout<<tot<<endl;
		}
	}
	return 0;
}
