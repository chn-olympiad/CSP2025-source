#include<bits/stdc++.h>
using namespace std;
int T;
int a[200010][4],n;
pair<int,int> b[4][200010];
int cnt[4];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[1][i]={a[i][1]-max(a[i][2],a[i][3]),-max(a[i][2],a[i][3])};
			b[2][i]={a[i][2]-max(a[i][1],a[i][3]),-max(a[i][1],a[i][3])};
			b[3][i]={a[i][3]-max(a[i][1],a[i][2]),-max(a[i][1],a[i][2])};
			int X=max(max(a[i][1],a[i][2]),a[i][3]);
			for(int j=1;j<=3;j++){
				if(a[i][j]==X){
					cnt[j]++;
					break;
				}
			}
			ans+=X;
		}
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			ans=-1e18;
			for(int i=1;i<=3;i++){
				long long now=0;
				sort(b[i]+1,b[i]+n+1);
				reverse(b[i]+1,b[i]+n+1);
				for(int j=1;j<=n/2;j++) now+=b[i][j].first;
				for(int j=1;j<=n;j++) now-=b[i][j].second;
				ans=max(ans,now);
			}
		}
		cout<<ans<<'\n';
	}
}
