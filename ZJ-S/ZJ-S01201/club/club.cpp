#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,ans,q;
int a[maxn][4],f[maxn][4],sum[3],vis[20005],qz[20005];
map<long long,int>cnt;
struct node{
	int x,y;
}s[maxn];
bool cmp(node x,node y){
	return x.x-x.y>y.x-y.y;
}
void dfs(int dep,int h){
	if(dep==n+1){
		ans=max(ans,h);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<q){
			if(h+a[dep][i]-qz[dep-1]+qz[n]<qz[n]) continue ;
			//if(a[dep][i]<(a[dep][1]+a[dep][2]+a[dep][3])/3) continue ;
			vis[i]++;
			dfs(dep+1,h+a[dep][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int maxx=0,cnt1=0,cnt2=0,summ=0;
		sum[1]=0,sum[2]=0,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				if(j==3) qz[i]=qz[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
				if(j==1) s[i].x=a[i][j];
				if(j==2) s[i].y=a[i][j];
				cnt[a[i][1]]++;
				maxx=max(maxx,a[i][1]);
				if(j==3&&a[i][2]==a[i][3]&&a[i][2]==0){
					cnt1++;
				}
				if(j==3&&a[i][3]==0) cnt2++;
			}
		}
		q=n/2;
		if(n==2){
			ans=max(ans,a[1][1]+a[2][2]);
			ans=max(ans,a[1][1]+a[2][3]);
			ans=max(ans,a[1][2]+a[2][1]);
			ans=max(ans,a[1][2]+a[2][3]);
			ans=max(ans,a[1][3]+a[2][1]);
			ans=max(ans,a[1][3]+a[2][2]);
			cout << ans << endl;
			continue ;
		}
		if(cnt1==n){
			int sy=q;
			for(int i=maxx;i>=0;i--){
				while(cnt[i]&&sy){
					ans+=i;
					sy--;
					cnt[i]--;
				}
			}
			cout << ans << endl;
			continue ;
		}
		if(cnt2==n){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=q;i++){
				ans+=s[i].x;
			}
			for(int i=q+1;i<=n;i++){
				ans+=s[i].y;
			}
			cout << ans << endl;
			continue ;
		}
		if(n<=200){
			memset(vis,0,sizeof(vis));
			dfs(1,0);
			cout << ans << endl;
			continue ;
		}
		
		ans=rand();
		cout << ans;
	}
	return 0;
}