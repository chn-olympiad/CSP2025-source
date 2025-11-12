#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int T;
int Ace=0;
int n;
int dp[1005][1005];
int d[maxn];
struct node{
	int va,vb,vc;
}Scout[maxn];
bool aflag,bflag;
bool cmp(node x,node y){
	return x.va>y.va;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int ldd=1;ldd<=n;ldd++){
			cin>>Scout[ldd].va>>Scout[ldd].vb>>Scout[ldd].vc;
			if(Scout[ldd].vb!=0||Scout[ldd].vc!=0){
				aflag=1;
			}if(Scout[ldd].vc!=0){
				bflag=1;
			}
		}
		if(!aflag){
			sort(Scout+1,Scout+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				Ace+=Scout[i].va;
			}
			cout<<Ace<<endl;
			aflag=0;
			bflag=0;
			Ace=0;
			continue;
		}else if(!bflag){
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=1;j--){
					d[j]=max(d[j]+Scout[i].vb,d[j-1]+Scout[i].va);
				}
			}
			for(int i=1;i<=n/2;i++){
				Ace=max(Ace,d[i]);
			}
			cout<<Ace;
			aflag=0;
			bflag=0;
			Ace=0;
			continue;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=1;j--){
					for(int k=n/2;k>=1;k--){
						dp[j][k]=max(dp[j][k]+Scout[i].vc,max(dp[j-1][k]+Scout[i].va,dp[j][k-1]+Scout[i].vb));
//						cout<<dp[j][k]<<" "<<dp[j-1][k]<<" "<<dp[j][k-1]<<" "<<dp[1][2]<<endl;
					}
				}
			}
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=n/2;k++){
	//				cout<<dp[j][k]<<" ";
					Ace=max(Ace,dp[j][k]);
				}
			}
			cout<<Ace<<endl;
			aflag=0;
			bflag=0;
			Ace=0;
			continue;
		}
	}
	
	return 0;
}