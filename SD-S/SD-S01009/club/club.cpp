#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int a,b,c;
};
bool cmp(node x,node y){
	if((x.a+x.b+x.c)!=(y.a+y.b+y.c)) return (x.a+x.b+x.c)>(y.a+y.b+y.c);
	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b>y.b;
	if(x.c!=y.c) return x.c>y.c;
}
node f[N];
int dp[N][4];
int cnt[4];
int x,y,z;
int temp1,temp2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		x=y=z=temp1=temp2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			x+=f[i].a;
			y+=f[i].b;
			z+=f[i].c;
		}
		sort(f+1,f+1+n,cmp);
		if((x!=0 && y==0 && z==0) || (x==0 && y!=0 && z==0) || (x==0 && y==0 && z!=0)){
			for(int i=1;i<=n/2;i++){
				if(x!=0) temp1+=f[i].a;
				else if(y!=0) temp1+=f[i].b;
				else if(z!=0) temp1+=f[i].c;
			}
			cout<<temp1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(cnt[1]<n/2){	
				dp[i][1]=max(dp[i-1][1]+f[i].a,max(dp[i-1][2]+f[i].a,dp[i-1][3]+f[i].a));
				if(dp[i][1]==dp[i-1][1]+f[i].a) cnt[1]++;
			}else{
				dp[i][1]=max(dp[i-1][2]+f[i].a,dp[i-1][3]+f[i].a);
			}
			if(cnt[2]<n/2){	
				dp[i][2]=max(dp[i-1][1]+f[i].b,max(dp[i-1][2]+f[i].b,dp[i-1][3]+f[i].b));
				if(dp[i][2]==dp[i-1][2]+f[i].b) cnt[2]++;
			}else{
				dp[i][2]=max(dp[i-1][1]+f[i].b,dp[i-1][3]+f[i].b);
			}
			if(cnt[3]<n/2){	
				dp[i][3]=max(dp[i-1][1]+f[i].c,max(dp[i-1][2]+f[i].c,dp[i-1][3]+f[i].c));
				if(dp[i][3]==dp[i-1][3]+f[i].c) cnt[3]++;
			}else{
				dp[i][3]=max(dp[i-1][1]+f[i].c,dp[i-1][2]+f[i].c);
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
