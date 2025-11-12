//杨昕然  西安高新第一中学   SN-S00399
#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],f[105][105][105];
bool flag;
vector<long long> V;
long long dfs(long long x,long long y,long long z){
	if(x<0||y<0||z<0)return -20000;
	long long N=x+y+z-n/2;
	if(N==0)return 0;
	if(f[x][y][z]!=-1)return f[x][y][z];
	long long ans=max(max(dfs(x-1,y,z)+a[N],dfs(x,y-1,z)+b[N]),dfs(x,y,z-1)+c[N]);
	return f[x][y][z]=ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,-1,sizeof(f));
		flag=false;
		V.clear();
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0)flag=true;
			if(c[i]!=0)flag=true;
			V.push_back(a[i]);
		}
		if(flag==false){
			stable_sort(V.begin(),V.end());
			long long ans=0;
			for(long long i=V.size()-1; i>=n/2; i--){
				ans+=V[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<dfs(n/2,n/2,n/2)<<'\n';
	}
	return 0;
}
/*
1.见大样例 

longlong

1.DP(暴力)
*/
