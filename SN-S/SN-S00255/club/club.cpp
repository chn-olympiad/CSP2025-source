//00255 ÕÅº²•N 
#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int t,n,a[3][maxn];
int vis[maxn],ans;
int v[maxn];
bool cmp(int aa,int b){
	return a[0][aa]-a[1][aa]>a[0][b]-a[1][b];
}
bool cmpp(int aa,int b){
	return max(a[0][aa],a[1][aa])>max(a[0][b],a[1][b]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			ans+=a[2][i];
			a[0][i]-=a[2][i],a[1][i]-=a[2][i];
		}
		int tt=0;
		for(int i=1;i<=n;i++)vis[i]=i;
		for(int i=1;i<=n;i++){
			if(a[0][vis[i]]<=0&&a[1][vis[i]]<=0&&tt<n/2)tt++;
		}
		if(tt>=n/2){
			sort(vis+1,vis+n+1,cmpp);
			for(int i=1;i<=n/2;i++)ans+=max(a[0][vis[i]],a[1][vis[i]]);
		}
		else{
			sort(vis+1,vis+n+1,cmp);
			int tt0=0,tt1=0;
			for(int i=1;i<=n;i++){
				if(a[0][vis[i]]<=0&&a[1][vis[i]]<=0){continue;}
				if((a[0][vis[i]]>=a[1][vis[i]]&&tt0<n/2)||(tt0<n/2-tt)){
					ans+=a[0][vis[i]];
					tt0++;
					continue;
				}
				ans+=a[1][vis[i]];
				tt1++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
