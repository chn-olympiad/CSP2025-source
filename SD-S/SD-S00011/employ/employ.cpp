#include<bits/stdc++.h>
using namespace std;
int n,m,r[505],a,sum[505],ma;
long long int ans;
char c[505];
void dfs(int x,int d,__int128 ss){
	if(x-1-d>=m){
		for(int i=n-x+1;i>=2;i--){
			ss*=i;
		}
		ans+=ss%998244353;
		ans%=998244353;
		return;
	}
	if(n-sum[d]+d<m)return;
	for(int i=0;i<=ma;i++){
		if(r[i]!=0){
			if(c[x]=='1'){
				if(i<=d){
					r[i]--;
					dfs(x+1,d+1,ss*(r[i]+1));
					r[i]++;
				}
				else{
					r[i]--;
					dfs(x+1,d,ss*(r[i]+1));
					r[i]++;
				}
			}
			else{
				r[i]--;
				dfs(x+1,d+1,ss*(r[i]+1));
				r[i]++;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		r[a]++;
		ma=max(ma,a);
	}
	sum[0]=r[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+r[i];
	dfs(1,0,1);
	printf("%d",ans);
}
