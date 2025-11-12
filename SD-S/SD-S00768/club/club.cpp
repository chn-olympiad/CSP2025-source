#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int a[maxn][5],vis[5];
long long ans;
struct node{
	int n1,n2,n3,a1,a2,a3,n4;
}cnt[maxn];
int cmp(node a,node b){
	if(a.n4>=b.n4){
		if(a.n4==b.n4){
			if(a.n1>=b.n1){
				return 1;
			}
			else{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		ans=0;
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[i].n1=a[i][1];
				cnt[i].a1=1;
				if(a[i][2]>=a[i][3]){
					cnt[i].n2=a[i][2];
					cnt[i].a2=2;
					cnt[i].n3=a[i][3];
					cnt[i].a3=3;
				}
				else{
					cnt[i].n3=a[i][2];
					cnt[i].a3=2;
					cnt[i].n2=a[i][3];
					cnt[i].a2=3;
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[i].n1=a[i][2];
				cnt[i].a1=2;
				if(a[i][1]>=a[i][3]){
					cnt[i].a2=1;
					cnt[i].n2=a[i][1];
					cnt[i].a3=3;
					cnt[i].n3=a[i][3];
				}
				else{
					cnt[i].a3=1;
					cnt[i].n3=a[i][1];
					cnt[i].a2=3;
					cnt[i].n2=a[i][3];
				}
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt[i].n1=a[i][3];
				cnt[i].a1=3;
				if(a[i][1]>=a[i][2]){
					cnt[i].a2=1;
					cnt[i].n2=a[i][1];
					cnt[i].a3=2;
					cnt[i].n3=a[i][2];
				}
				else{
					cnt[i].a3=1;
					cnt[i].n3=a[i][1];
					cnt[i].a2=2;
					cnt[i].n2=a[i][2];
				}
			}
			cnt[i].n4=cnt[i].n1-cnt[i].n2;
		}
		sort(cnt+1,cnt+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(vis[cnt[i].a1]<n/2){
				ans+=cnt[i].n1;
				vis[cnt[i].a1]++;
			}
			else{
				ans+=cnt[i].n2;
				vis[cnt[i].a2]++;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
//longlong±©Á¦Àä¾²rp++ 
//Ren5Jie4Di4Ling5% 
