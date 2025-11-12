#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct node{
	int x,id;
	bool operator < (const node &q) const{
		return x<q.x;
	}
};
node sum[4][N];
int a[N][4],cnt[4];
void solve(){
	memset(cnt,0,sizeof cnt);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max(a[i][1],max(a[i][2],a[i][3]));
		int ff=a[i][1]+a[i][2]+a[i][3]-mx-min(a[i][1],min(a[i][2],a[i][3]));
		for(int j=1;j<=3;j++){
			if(a[i][j]==mx){
				sum[j][++cnt[j]]={mx-ff,i};
				break;
			}
		}
	}
	long long ans=0;
	for(int j=1;j<=3;j++){
		int l=1;
		if(cnt[j]>n/2){
			sort(sum[j]+1,sum[j]+cnt[j]+1);
			for(int i=1;i<=cnt[j]-n/2;i++){
				int x=sum[j][i].id;
				int mx=max(a[x][1],max(a[x][2],a[x][3]));
				int ff=a[x][1]+a[x][2]+a[x][3]-mx-min(a[x][1],min(a[x][2],a[x][3]));
				ans+=ff;
			}
			l=cnt[j]-n/2+1;
		}
		for(int i=l;i<=cnt[j];i++){
			int x=sum[j][i].id;
			int mx=max(a[x][1],max(a[x][2],a[x][3]));
			ans+=mx;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}