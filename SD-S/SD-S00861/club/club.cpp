#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N][5];
int a1[N],a2[N],a3[N];
int f[N];
int vis[N];
int T,n;
int c[5];
ll dfs(int idx,ll sum){
	if(idx>n){
		return sum;
	}
	ll ans=0;
	for(int i=1;i<=3;i++){
		if(c[i]<n/2){
			c[i]++;
			ans=max(ans,dfs(idx+1,sum+a[idx][i]));
			c[i]--;
		}
	}
	return ans;
}
struct node{
	int x1,x2;
	int ch;
}x[N];
bool cmp(node y,node z){
	return y.ch>z.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int f=0;
		int f2=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(j==1){
					a1[i]=a[i][j];
					x[i].x1=a[i][j];
				}
				else if(j==2){
					a2[i]=a[i][j];
					x[i].x2=a[i][j];
				}
				else{
					a3[i]=a[i][j];
				}
				
				if(j==2||j==3){
					if(a[i][j]){
						f=1;
					}
				}
				if(j==3){
					if(a[i][j]){
						f2=1;
					}
				}
			}
			x[i].ch=a[i][1]-a[i][2];
		}
		if(!f){
			sort(a1+1,a1+n+1);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a1[n-i+1];
			}
			cout<<ans<<endl;
		}
		else if(!f2){
			int cnt=0;
			long long ans=0;
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(cnt<n/2){
					ans+=x[i].x1;
					cnt++;
				}
				else{
					ans+=x[i].x2;
				}
			}
			cout<<ans<<endl;
		}
		else {
			cout<<dfs(1,0)<<endl;
		}
		
		
	}
	
	
	
	
	
	return 0;
} 
