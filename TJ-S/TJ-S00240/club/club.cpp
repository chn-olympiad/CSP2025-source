#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
struct s{
	long long a,b,c;
}d[100007];
long long f1=true,f2=true;
bool cmp(s x,s y){
	return x.a>y.a;
}
long long p;
long long dfs(long long x,long long a1,long long b1,long long c1,long long a2,long long b2,long long c2){
	if(x>n && max(max(a1,b1),c1)<=n/2){
		return a2+b2+c2;
	}
	else if(x>n || max(max(a1,b1),c1)>n/2){
		return 0;
	}
	return max(max(dfs(x+1,a1+1,b1,c1,a2+d[x].a,b2,c2),dfs(x+1,a1,b1+1,c1,a2,b2+d[x].b,c2)),dfs(x+1,a1,b1,c1+1,a2,b2,c2+d[x].c));
}
long long dp[207][107][107];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;++i){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].b!=0){
				f1=false;
			}
		
			if(d[i].c!=0){
				f2=false;
			}
		}
		if(f1 && f2){
			sort(d+1,d+1+n,cmp);
			for(long long i=1;i<=n/2;++i){
				p+=d[i].a; 
			}
			cout<<p<<endl;
			p=0;
		}
		else if(f2){
			for(long long k=1;k<=n;++k){
				for(long long i=1;i<=n/2;++i){
					for(long long j=1;j<=n/2;++j){
						dp[k][i][j]=max(dp[k][i][j],max(dp[k][i-1][j]+d[k].a,dp[k][i][j-1]+d[k].b));
					}
				}
			}
			cout<<dp[n][n/2][n/2]<<endl;
		}
		else{
			cout<<dfs(1,0,0,0,0,0,0)<<endl;
		}		
	}
	return 0;
} 
