#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int T;
int n;
int ans;
int a[MAXN][5];
int c[MAXN];
int tot;
int h[MAXN];
void dfs(int u,int s_1,int s_2,int s_3,int sum){
	if(u>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&s_1>0){
			dfs(u+1,s_1-1,s_2,s_3,sum+a[u][i]);
		}
		else if(i==2&&s_2>0){
			dfs(u+1,s_1,s_2-1,s_3,sum+a[u][i]);
		}
		else if(i==3&&s_3>0){
			dfs(u+1,s_1,s_2,s_3-1,sum+a[u][i]);
		}
	}
}
struct p{
	int w,id,cl;
}g[MAXN];
bool cmp(p x,p y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		if(n>=200){
			int flag=0;
			for(int i=1;i<=n;i++){
				if(!(a[i][2]==a[i][3]&&a[i][3]==0)){
					flag=1;
					break;
				}
			}
			if(flag==0){
				for(int i=1;i<=n;i++){
					c[i]=a[i][1];
				}
				sort(c+1,c+1+n,greater<int>());
				for(int i=1;i<=n/2;i++){
					ans+=c[i];
				}
				cout<<ans<<endl;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			dfs(1,n/2,n/2,n/2,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}


