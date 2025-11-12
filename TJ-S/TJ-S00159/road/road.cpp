#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m1,k,ans,sum;
LL m[10001][10001];
struct node{
	LL num;
	LL v[10001];
}a[11];
LL dfs(LL x,LL y,LL cnt){
	LL c=1e9;
	for(LL i=1;i<=n;i++){
		if(m[x][i]){
			if(i==y){
				if(cnt==0){
					continue;
				}
				return m[x][i]+cnt;
			}
			c=min(c,dfs(i,y,cnt+m[x][i]));
		}
	}
	return c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m1>>k;
	for(LL i=1;i<=m1;i++){
		LL x,y,z;
		cin>>x>>y>>z;
		m[x][y]=m[y][x]=z;
		sum+=z;
	}
	for(LL i=1;i<=k;i++){
		cin>>a[i].num;
		for(LL j=1;j<=n;j++){
			cin>>a[i].v[j];
		}
	}
	for(LL i=1;i<n;i++){
		for(LL j=i+1;j<=n;j++){
			if(m[i][j]){
				LL k=m[i][j];
				m[i][j]=min(m[i][j],dfs(i,j,0));
				if(m[i][j]!=k){
					m[i][j]=0;
					sum-=k;
				}
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

