#include<bits/stdc++.h>
using namespace std;
long long t,n,memo[31][31][31],ans,a[100005][4],b[100005];
bool flagA;
void dfs1(long long i,long long s,long long d,long long b,long long c){
	if(i==(n+1)){
		ans=max(ans,s);
		return;
	}
	if(memo[d][b][c]>s)
		return;
	memo[d][b][c]=s;
	if(d+1<=(n>>1))
		dfs1(i+1,s+a[i][1],d+1,b,c);
	if(b+1<=(n>>1))
		dfs1(i+1,s+a[i][2],d,b+1,c);
	if(c+1<=(n>>1))
		dfs1(i+1,s+a[i][3],d,b,c+1);
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		flagA=1;
		ans=0;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1) b[i]=a[i][j];
				if((j==2||j==3)&&a[i][j]!=0)
					flagA=0;
			}
		if(!flagA){
			memset(memo,0,sizeof memo);
			dfs1(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		else{
			sort(b+1,b+1+n,cmp);
			for(long long i=1;i<=(n>>1);i++)
				ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
