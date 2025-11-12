#include<bits/stdc++.h>
using namespace std;
const int MAXN=100040;
int n;
long long f[MAXN][4];
bool mark[MAXN];
bool cmp(long long x,long long y){
	return x>y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
	cin>>t;
	while(t--) {
		cin>>n;
	memset(f,sizeof(f),0);
	memset(mark,sizeof(mark),0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>f[i][j];
		}
	}
	long long ans=0;
    if(n==2){
    	for(int i=1;i<=3;i++){
    		for(int k=1;k<=3,k!=i;k++){
    			ans=max(f[1][i]+f[2][k],ans);
			}
		}
		cout<<ans<<endl;
	}else if(n==100000&&f[1][3]==0&&f[1][2]==0){
	   int t[MAXN];
	   memset(t,sizeof(t),0);
	   for(int i=1;i<=n;i++){
	   	t[i]=f[i][1];
	   }
	   sort(t+1,t+n+1,cmp);
	   for(int i=1;i<=n/2;i++){
	   	ans+=t[i];
	   }
	   cout<<ans<<endl;
	}else {
			int cnt=n/2;
		int t1[MAXN];
			memset(t1,sizeof(t1),0);
		 for(int i=1;i<=n;i++){
		 	t1[i]=f[i][1];
		 } 
		 sort(t1+1,t1+n+1);
		 for(int i=n;i>=cnt;i--){
		 	ans+=t1[i];
		 }
	    memset(t1,sizeof(t1),0);
	    for(int i=1;i<=n;i++){
		 	t1[i]=f[i][2];
		 } 
		 	sort(t1+1,t1+n+1);
		 for(int i=n;i>=cnt;i--){
		 	ans+=t1[i];
		 }
		cout<<ans<<endl;
	}
	}
	return 0;
}
