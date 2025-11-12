//张爱熙 SN-S00246 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,dp[205][205][205],ans,f;
struct node{
	int a,b,c;
}v[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		ans=0,f=1;
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			if(v[i].b>0 || v[i].c>0) f=0;
		}
		if(f){
			sort(v+1,v+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=v[i].a;
			cout<<ans;
			continue;
		}
		dp[1][1][0]=v[1].a,dp[1][0][1]=v[1].b,dp[1][0][0]=v[1].c;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					int x=0,y=0,z=0;
					if(j>0) x=dp[i-1][j-1][k]+v[i].a;
					if(k>0) y=dp[i-1][j][k-1]+v[i].b;
					if(n/2>=i-j-k && i-j-k>0) z=dp[i-1][j][k]+v[i].c;
					dp[i][j][k]=max(max(x,y),z);
					if(i==n) ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
