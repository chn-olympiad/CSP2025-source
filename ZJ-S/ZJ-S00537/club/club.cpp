#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

long long A,B;

int n;

int a[N][4];
int b[N];
int c[N];

struct node{
	int x,id;
}s[N];


long long dp[205][205][205];

long long ans;

void init(){
	
	memset(dp,0,sizeof dp);
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	A=B=0;
	ans=0;
	
	return;
}

long long dfs(int x,int a1,int a2,long long c){
	
	if(a1>n/2||a2>n/2||x-a1-a2>n/2)return 0;
	
	if(dp[x][a1][a2]!=0)return c+dp[x][a1][a2];
	
	if(x==n+1){
		return c;
	}
	
	long long res=0;
	res=max(res,dfs(x+1,a1+1,a2,c+a[x][1]));
	res=max(res,dfs(x+1,a1,a2+1,c+a[x][2]));
	res=max(res,dfs(x+1,a1,a2,c+a[x][3]));
	
	dp[x][a1][a2]=res-c;
	return res;
}

long long solve(){
	
	long long cnt;
	
	for(int i=1;i<=n;i++){
		s[i]={a[i][2]-a[i][1],i};
		c[i]=a[i][1];
	}
	sort(s+1,s+1+n,[](node x,node y){
		return x.x>y.x;
	});
	for(int i=1;i<=n/2;i++){
		c[s[i].id]=a[s[i].id][2];
//				cout<<s[i].x<<" "<<s[i].id<<"\n";
	}
	
	for(int i=1;i<=n;i++){
		b[i]=a[i][3]-c[i];
		cnt+=c[i];
//				cout<<c[i]<<" ";
	}
//			cout<<"\n";
	sort(b+1,b+1+n,[](int x,int y){
		return x>y;
	});
	for(int i=1;i<=n/2;i++){
		if(b[i]<=0)break;
		cnt+=b[i];
	}
	
	return cnt;
}

void sw(int x,int y){
	for(int i=1;i<=n;i++){
		swap(a[i][x],a[i][y]);
	}
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;cin>>T;
	while(T--){
		
		init();
		
		cin>>n;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			A+=a[i][2]+a[i][3];
			B+=a[i][3];
		}
		
		if(A==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			
			sort(b+1,b+1+n,[](int x,int y){
				return x>y;
			});
			
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			
			cout<<ans<<"\n";
		}else if(B==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][2]-a[i][1];
				ans+=a[i][1];
			}
			
			sort(b+1,b+1+n,[](int x,int y){
				return x>y;
			});
			
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			
			cout<<ans<<"\n";
			
		}else if(n>200){
			
			ans=solve();
			sw(2,3);
			ans=max(ans,solve());
			sw(1,3);
			ans=max(ans,solve());
			sw(2,3);
			ans=max(ans,solve());
			sw(1,3);
			ans=max(ans,solve());
			sw(2,3);
			ans=max(ans,solve());
			
			cout<<ans<<"\n";
			
		}else{
			cout<<dfs(1,0,0,0)<<"\n";
		}
		
	}
	
	return 0;
}