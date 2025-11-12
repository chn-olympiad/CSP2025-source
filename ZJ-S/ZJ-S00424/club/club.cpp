#include<bits/stdc++.h>
#define N 100050
using namespace std;
vector<int>g[5];
int a[N][5];
void solve(){
	g[1].clear();
	g[2].clear();
	g[3].clear();
	int n;scanf("%d",&n);
	int ans=0,xuan1=0,xuan2=0,xuan3=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			g[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
			ans+=a[i][1];xuan1++;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			g[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
			ans+=a[i][2];xuan2++;
		}
		else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
			g[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
			ans+=a[i][3];xuan3++;
		}
	}
	if(xuan1<=n/2&&xuan2<=n/2&&xuan3<=n/2){
		printf("%d\n",ans);
		return;
	}
	else if(xuan1>n/2){
		sort(g[1].begin(),g[1].end());
		for(int i=0;i<xuan1-n/2;i++)ans-=g[1][i];
	}
	else if(xuan2>n/2){
		sort(g[2].begin(),g[2].end());
		for(int i=0;i<xuan2-n/2;i++)ans-=g[2][i];
	}
	else if(xuan3>n/2){
		sort(g[3].begin(),g[3].end());
		for(int i=0;i<xuan3-n/2;i++)ans-=g[3][i];
	}
	printf("%d\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}