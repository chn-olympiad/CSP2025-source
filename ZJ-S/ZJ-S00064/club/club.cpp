#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;


int t,n,a[maxn][3];
int gp[3][maxn],cnt[3],ans,fk[maxn],tot;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
//		cout<<t;
		tot=ans=0;
		memset(fk,0,sizeof(fk));
		memset(gp,0,sizeof(gp));
		memset(cnt,0,sizeof(cnt));
		
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) gp[0][++cnt[0]]=i, ans+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) gp[1][++cnt[1]]=i, ans+=a[i][1];
			else gp[2][++cnt[2]]=i, ans+=a[i][2]; 
		}
		
		if(cnt[0]>=n/2){
			for(int x=1;x<=cnt[0];x++){
				int i=gp[0][x];
				fk[++tot]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}
			sort(fk+1,fk+tot+1);
			for(int i=1;i<=cnt[0]-n/2;i++)ans-=fk[i];
			cout<<ans<<'\n';
		}
		else if(cnt[1]>=n/2){
			for(int x=1;x<=cnt[1];x++){
				int i=gp[1][x]; 
				fk[++tot]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			} 
			sort(fk+1,fk+tot+1);
			for(int i=1;i<=cnt[1]-n/2;i++)ans-=fk[i];
			cout<<ans<<'\n';
		}
		else if(cnt[2]>=n/2){
			for(int x=1;x<=cnt[2];x++){
				int i=gp[2][x]; 
				fk[++tot]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
			} 
			sort(fk+1,fk+tot+1);
			for(int i=1;i<=cnt[2]-n/2;i++)ans-=fk[i];
			cout<<ans<<'\n';
		}
		else cout<<ans<<'\n';
	}
	
	
	
	
	
	return 0;
}
