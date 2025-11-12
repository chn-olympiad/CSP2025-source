#include<bits/stdc++.h>
using namespace std;
int T,ans,n,a[4][100005];
void dfs(int s,int X,int Y,int Z,int step){
	if(step==n+1){
		ans=max(ans,s);
		return;
	}
	if(X<n/2)dfs(s+a[1][step],X+1,Y,Z,step+1);
	if(Y<n/2)dfs(s+a[2][step],X,Y+1,Z,step+1);
	if(Z<n/2)dfs(s+a[3][step],X,Y,Z+1,step+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	T++;
	while(--T){
		cin>>n;
		int tA=1,tB=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				if(a[j][i]!=0&&(j==2||j==3))tA=0;
				if(a[j][i]!=0&&j==3)tB=0;
			}
		}
		if(n<=30){
			ans=0;
			dfs(0,0,0,0,1);
			cout<<ans<<endl;
		}
		if(tA){
			ans=0;
			sort(a[1]+1,a[1]+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[1][i];
			}
		}
		if(tB){
			int DP[100005];
			
		}
	}
	return 0;
}