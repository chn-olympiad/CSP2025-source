#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
struct node{
	int a,b,c;
}s[100005];
int t[5],T,n,ans,dp[205][105][105],cnt,num,f[100005];
bool flag,p;
bool cmp(node x,node y){
	return x.a>y.a;
}
bool com(node x,node y){
	return max(x.a,x.b)>max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		flag=p=0;
		ans=0;
		t[1]=t[2]=t[3]=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n/2;++j){
				for(int k=0;j+k<=i;++k){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;++i){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0) flag=1;
			if(s[i].c!=0) p=1;
		}
		if(!flag){
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;++i){
				ans+=s[i].a;
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;++i){
				for(int j=0;j<=n/2;++j){
					for(int k=0;j+k<=i;++k){
						if(i-j-k>n/2) continue;
						if(j>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+s[i].a);
						} 
						if(k>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+s[i].b);
						} 
						if(i-j-k>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+s[i].c);
						} 
					}
				}
			}
			for(int i=0;i<=n/2;++i){
				for(int j=0;j<=n/2;++j){
					if(n-i-j>n/2) continue;
					ans=max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
		
//		cout<<"HGFDSSAA\n";
	}
	return 0;
}