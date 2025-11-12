#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[510];
int z[510],dis[510];
long long dfs(int x,int res,int cut){
	long long zzz=0;
	if(x>=n){
		if(res>=m) return 1; 
		else return 0;
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==0){
			dis[i]=1;
			if(z[i]<=cut||a[x+1]=='0') zzz+=dfs(x+1,res,cut+1);
			else zzz+=dfs(x+1,res+1,cut);
			dis[i]=0;
		}
	}
	return zzz;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>z[i];
	long long ans=dfs(0,0,0);
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
