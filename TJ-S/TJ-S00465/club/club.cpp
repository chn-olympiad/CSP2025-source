#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
int m[110][110][110];
int dfs(int na,int nb,int nc){
	int x=0,y=0,z=0;
	int i=na+nb+nc;
	if(i==n-1){
		if(na<(n/2)) x=a[i];
		if(nb<(n/2)) y=b[i];
		if(nc<(n/2)) z=c[i];
		return max(x,max(y,z));
	}
	if(na<(n/2)){
		if(m[na+1][nb][nc]) x=m[na+1][nb][nc]+a[i];
		else x=dfs(na+1,nb,nc)+a[i];
	}
	if(nb<(n/2)){
		if(m[na][nb+1][nc]) y=m[na][nb+1][nc]+b[i];
		else y=dfs(na,nb+1,nc)+b[i];
	}
	if(nc<(n/2)){
		if(m[na][nb][nc+1]) z=m[na][nb][nc+1]+c[i];
		else z=dfs(na,nb,nc+1)+c[i];
	}
	m[na][nb][nc]=max(x,max(y,z));
	return max(x,max(y,z));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n>200){
			sort(a,a+n);
			int ans=0;
			for(int i=n;i>=n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					m[i][j][k]=0;
				}
			}
		}
		cout<<dfs(0,0,0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
