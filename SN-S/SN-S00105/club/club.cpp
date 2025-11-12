#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int T,n,a[maxn][4],t[4],ying[maxn],ans,tp,st[maxn],jie;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		t[1]=0;
		t[2]=0;
		t[3]=0;
		cin>>n;
		jie=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ying[i]=1;
			}
			else if(a[i][2]>=a[i][3]){
				ying[i]=2;
			}
			else{
				ying[i]=3;
			}
			ans+=a[i][ying[i]];
			t[ying[i]]++;
		}
		for(int i=1;i<=3;i++){
			if(t[i]>jie){
				tp=0;
				for(int j=1;j<=n;j++){
					if(ying[j]==i){
						st[++tp]=1e9;
						if(i!=1){
							st[tp]=min(st[tp],a[j][i]-a[j][1]);
						}
						if(i!=2){
							st[tp]=min(st[tp],a[j][i]-a[j][2]);
						}
						if(i!=3){
							st[tp]=min(st[tp],a[j][i]-a[j][3]);
						}
					}
				}
				sort(st+1,st+1+tp);
				for(int j=1;j<=t[i]-jie;j++){
					ans-=st[j];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
