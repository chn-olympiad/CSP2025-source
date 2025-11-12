#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4],dp[N][4],g[N][3][2],t[4];
struct Node{
	int a,b,c,maxn;
}b[N];
bool cmp(Node x,Node y){
	return x.maxn>y.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	frepoen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(g,0,sizeof(g));
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[i].a>>b[i].b>>b[i].c;
			b[i].maxn=max(b[i].a,max(b[i].b,b[i].c));
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			a[i][1]=b[i].a;
			a[i][2]=b[i].b;
			a[i][3]=b[i].c;
		}
		int last=0;
		for(int i=1;i<=n;i++){
			int t1=0,t2=0,t3=0,maxn=0,now=0;
			
			for(int j=1;j<=3;j++){
				if(g[i-1][j][0]==n/2) continue;
				for(int k=1;k<=3;k++){
					if(k!=j){
						if(dp[i][j]<dp[i-1][k]) t[j]=k;
						dp[i][j]=max(dp[i-1][k]+a[i][j],dp[i][j]);
					}
					else{
						if(g[i-1][j][1]<n/2){
							//cout<<i<<' '<<j<<' '<<g[i-1][j][1]<<endl; 
							if(dp[i][j]<dp[i-1][k]) t[j]=k;
							dp[i][j]=max(dp[i-1][k]+a[i][j],dp[i][j]);
						}
					} 
				}
				for(int k=1;k<=3;k++){
					if(j==k){
						if(dp[i][j]==dp[i-1][k]+a[i][j]) g[i][j][1]=g[i-1][j][1]+1;
						else g[i][j][1]=g[i-1][j][0]+1;
						
					}
				}
				g[i][j][0]=g[i][j][1]-1;
				if(maxn<dp[i][j]){
					maxn=dp[i][j];
					now=j;
				}
			}
			if(last){
				if(t[now]==last) {
					g[i][last][0]=g[i-1][last][1];
				}
			}
			last=now;
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	
	return 0;
}