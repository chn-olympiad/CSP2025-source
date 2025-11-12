#include<bits/stdc++.h>
using namespace std;
char ss[509];
string s;
long long fac=1;
long long c[509],p[509],q[509],num=0;
long long n,m;
long long ans=0;
void dfs(long long x,long long ac){
	if(x>=n){
		if(ac>=m){
			ans++;
		}
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(p[i]==0){
			p[i]=1;
			if(s[x]=='0'||c[i]<=x-ac){
				dfs(x+1,ac);
			}
			else{
				dfs(x+1,ac+1);
			}
			p[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",ss);
	s=ss;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		q[c[i]]++;
	}
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
} 
