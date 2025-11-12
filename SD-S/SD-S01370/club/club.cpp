#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}q[N];
int t,n;
ll cnt;
ll ans;
int maxx=-1;
int dp[N][5],a[N][5];
int vis[N];
int cmp(node x,node y){
	return x.a>y.a;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int v1,v2,v3;
		int flag1=0,flag2=0;
		int flag=0;
		maxx=-1;
		cnt=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0;
		v1=v2=v3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=cnt;i++){
			if(a[i][2]!=0){
				flag1=1;
			}
			if(a[i][3]!=0){
				flag2=1;
			}
				if(v1<=0){
					break;
				}
				ans+=a[i][1];
				v1--;
			cout<<ans;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]!=a[i][2]&&a[i][2]!=a[i][3]){
				swap(a[i][1],a[1][1]);
				swap(a[i][2],a[2][2]);
				swap(a[i][3],a[3][3]);
				break;
			}
		}
		for(int i=1;i<=n;i++){
			int v11=0,v22=0,v33=0;
			v1-=v11;
			v2-=v22;
			v3-=v33;
			for(int j=1;j<=3;j++){
				if(v1>0){
					if(v2>0){
						if(v3>0){
							if(dp[i-1][1]>=max(dp[i-1][2],dp[i-1][3])){
								dp[i][j]=dp[i-1][1]+a[i][j];
								v11++;
							}else if(dp[i-1][2]>=max(dp[i-1][1],dp[i-1][3])){
								dp[i][j]=dp[i-1][2]+a[i][j];
								v22++;
							}else{
								dp[i][j]=dp[i-1][3]+a[i][j];
								v33++;
							}
						}else{
							if(dp[i-1][1]>=dp[i-1][2]){
								dp[i][j]=dp[i-1][1]+a[i][j];
								v11++;
							}else{
								dp[i][j]=dp[i-1][2]+a[i][j];
								v22++;
							}
						}
					}else{
						if(v3>0){
							if(dp[i-1][1]>=dp[i-1][3]){
								dp[i][j]=dp[i-1][1]+a[i][j];
								v11++;
							}else{
								dp[i][j]=dp[i-1][3]+a[i][j];
								v33++;
							}
						}else{
							dp[i][j]=dp[i-1][1]+a[i][j];
							v11++;
						}
					}
				}else{
					if(v2>0){
						if(v3>0){
							if(dp[i-1][2]>=dp[i-1][3]){
								dp[i][j]=dp[i-1][2]+a[i][j];
								v22++;
							}else{
								dp[i][j]=dp[i-1][3]+a[i][j];
								v33++;
							}
						}else{
							dp[i][j]=dp[i][2]+a[i][j];
							v22++;
						}
					}else{
						if(v3>0){
							dp[i][j]=dp[i][3]+a[i][j];
							v33++;
						}else{
							break;
						}
					}
				}
				maxx=max(dp[i][j],maxx);	
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<maxx;
	} 
	return 0;
}

