#include<bits/stdc++.h>
using namespace std;
const int Maxn = 100100;
int t=0,a[Maxn][4];
int ans = -1;
void dfs(int a1,int s1,int a2,int s2,int a3,int s3,int t,int n){
	if(t>n) return;
	
	ans = max(ans,a1+a2+a3);
	if(s1<(n/2)) dfs(a1+a[t+1][1],s1+1,a2,s2,a3,s3,t+1,n);
	if(s2<(n/2)) dfs(a1,s1,a2+a[t+1][2],s2+1,a3,s3,t+1,n);
	if(s3<(n/2)) dfs(a1,s1,a2,s2,a3+a[t+1][3],s3+1,t+1,n);
	return;
}
void dfs2(int a1,int s1,int a2,int s2,int t,int n){
	if(t>n) return;
	
	ans = max(ans,a1+a2);
	if(s1<(n/2)) dfs2(a1+a[t+1][1],s1+1,a2,s2,t+1,n);
	if(s2<(n/2)) dfs2(a1,s1,a2+a[t+1][2],s2+1,t+1,n);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(;t>0;t--){
		
		int n=0;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		bool s1=true,s2=true;
		for(int i=1;i<=n;i++){
			if(a[i][2]!=a[i][3]||a[i][3]!=0||a[i][2]!=0) s1=false;
			if(a[i][3]!=0) s2 = false;
		}
		if(s1){
			int ans1=0;
			for(int i=1;i<=n/2;i++){
				int maxm = -1;
				for(int j=1;j<=n;j++) maxm = max(maxm,a[j][1]);
				for(int j=1;j<=n;j++){
					if(a[j][1] == maxm) a[j][1] = -1; 
				}
				ans1+=maxm;
			}
			cout << ans1 << endl;
		}else if(s2){
			dfs2(a[1][1],1,0,0,1,n);
			dfs2(0,0,a[1][2],1,1,n);
			cout << ans << endl;
			ans = -1;
		}else{
			dfs(a[1][1],1,0,0,0,0,1,n);
			dfs(0,0,a[1][2],1,0,0,1,n);
			dfs(0,0,0,0,a[1][3],1,1,n);
			cout << ans << endl;
			ans=-1;
		}
	}
	return 0;
}