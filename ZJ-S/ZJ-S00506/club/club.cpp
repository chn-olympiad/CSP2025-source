#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll T,n,a[maxn][5],ans;
struct node{
	ll x,cnt[5];
}f[maxn][5];

void dfs(int x,int cnt1,int cnt2,int cnt3,ll sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
	if(cnt2<n/2) dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
	if(cnt3<n/2) dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		ll cnt1=0,cnt2=0,cnt3=0;
		memset(f,0,sizeof(f));
		cin>>n; ll m=n/2;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		
		ll cnta=0,cntb=0;
		for(int i=1;i<=n;i++){
			if(a[i][2]==0&&a[i][3]==0){
				cnta++;
			}
			if(a[i][3]==0){
				cntb++;
			}
		}
		if(cnta==n){
			ll b[maxn];
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(1+b,1+b+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=10){
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
			continue;			
		}

		f[1][1].x=a[1][1],f[1][1].cnt[1]=1;
		f[1][2].x=a[1][2],f[1][2].cnt[2]=1;
		f[1][3].x=a[1][3],f[1][3].cnt[3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(f[i-1][j].cnt[k]<m){
						if(f[i-1][j].x+a[i][k]>f[i][k].x){
							f[i][k].x=f[i-1][j].x+a[i][k];
							f[i][k].cnt[k]=f[i-1][j].cnt[k]+1;
							if(k==1){
								f[i][k].cnt[2]=f[i-1][j].cnt[2];
								f[i][k].cnt[3]=f[i-1][j].cnt[3];
							}							
							if(k==2){
								f[i][k].cnt[1]=f[i-1][j].cnt[1];
								f[i][k].cnt[3]=f[i-1][j].cnt[3];
							}
							if(k==3){
								f[i][k].cnt[1]=f[i-1][j].cnt[1];
								f[i][k].cnt[2]=f[i-1][j].cnt[2];				
							}
						}
					}
				}			
			}
		}
		cout<<max(f[n][1].x,max(f[n][2].x,f[n][3].x))<<endl;
	}
	return 0;
}
