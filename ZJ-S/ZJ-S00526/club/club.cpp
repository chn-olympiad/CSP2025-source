#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=5;
int a[N][M],maxx[N],cnt[M];
int chongtu[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int m=n/2;
		int ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				cnt[1]++;
				maxx[i]=1;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				cnt[2]++;
				maxx[i]=2;
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				cnt[3]++;
				maxx[i]=3;
			}
		}
		int id=0;
		if(cnt[1]>m) id=1;
		else if(cnt[2]>m) id=2;
		else if(cnt[3]>m) id=3;
		else{
			cout<<ans<<"\n";
			continue;
		}
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(maxx[i]==id){
				int x=INT_MIN;
				for(int j=1;j<=3;j++){
					if(j!=id){
						x=max(x,a[i][j]);
					}
				}
				chongtu[++cntt]=a[i][id]-x;
			}
		}
		sort(chongtu+1,chongtu+1+cntt);
		int duo=cnt[id]-m;
		for(int i=1;i<=duo;i++) ans-=chongtu[i];
		cout<<ans<<"\n";
	}
	return 0;
}
