#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n;
int b[maxn][4],c[maxn][4],sum,sum1,sum2;
int ans=0;
int cnt[4];
bool used[maxn][4];
struct node{
	int x,y,z;
}a[maxn];
bool cmp(node t,node t1){
	return t.x>t1.x;
}
bool cmp1(node t,node t1){
	return t.y>t1.y;
}
bool cmp2(node t,node t1){
	return t.z>t1.z;
}
void dfs(int dep,int sum){
	if(dep==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(used[dep][i]||cnt[i]==n/2) continue;
		used[dep][i]=1;
		cnt[i]++;
		dfs(dep+1,sum+b[dep][i]);
		used[dep][i]=0;
		cnt[i]--;
	}
}
void dfs1(int dep,int sum){
	if(dep==n+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=2;i++){
		if(used[dep][i]||cnt[i]==n/2) continue;
		used[dep][i]=1;
		cnt[i]++;
		dfs(dep+1,sum+b[dep][i]);
		used[dep][i]=0;
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(used,0,sizeof(used));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==a[i].y&&a[i].x==0) sum1++;
			if(a[i].x==a[i].z&&a[i].x==0) sum2++;
			if(a[i].z==a[i].y&&a[i].y==0) sum++;
			c[i][1]=b[i][1]=a[i].x;
			c[i][2]=b[i][2]=a[i].y;
			c[i][3]=b[i][3]=a[i].z;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					ans=max(ans,b[1][i]+b[2][j]);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(sum==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<"\n";
			continue;
		}
		else if(sum1==n){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++) ans+=a[i].z;
			cout<<ans<<"\n";
			continue;
		}
		else if(sum2==n){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=a[i].y;
			cout<<ans<<"\n";
			continue;
		}
		else{
			dfs(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}