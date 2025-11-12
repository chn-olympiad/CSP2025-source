#include<bits/stdc++.h>
using namespace std;
long long T,q,ans,n,a[100001][5],f[100001];
void dfs(long long x,long long b,long long c,long long d,long long s){
	if(x==n+1){
		ans=max(ans,s);
		return;
	}
	if(b+1<=n/2)dfs(x+1,b+1,c,d,s+a[x][1]);
	if(c+1<=n/2)dfs(x+1,b,c+1,d,s+a[x][2]);
	if(d+1<=n/2)dfs(x+1,b,c,d+1,s+a[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		q=0;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][2]!=0)q=1;
			}
		}
		if(q==0){
			for(int i=1;i<=n;i++){
				f[i]=a[i][1];
			}
			sort(f+1,f+n+1);
			for(int i=1;i<=n/2;i++)ans+=f[i];
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
