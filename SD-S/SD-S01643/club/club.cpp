#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,t,ans,a[maxn][4],f[maxn],num[4];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x){
	if(x>n){
		ans=max(ans,f[n]);
		return;
	}
	for(int i=1;i<=3;i++){
		if(num[i]==n/2) continue;
		num[i]++,f[x]=f[x-1]+a[x][i];
		dfs(x+1);
		num[i]--,f[x]-=a[x][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f)),memset(num,0,sizeof(num));
		bool vaild=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][2]||a[i][3]) vaild=false;
		}
		if(vaild){
			int b[maxn]={0};
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2) ans+=b[i];
		}
		else{
			ans=0;
		    dfs(1);
		}
		cout<<ans<<'\n';
	}
}
