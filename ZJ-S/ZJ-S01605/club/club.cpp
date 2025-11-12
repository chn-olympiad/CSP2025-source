#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int cnt[4],sum,n;
vector<int> d[4];

void solve(){
	int a[4];
	sum=0;
	for(int i=1;i<=3;i++) d[i].clear(), cnt[i]=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) scanf("%d",a+j);
		int mx=a[1],id=1;
		for(int j=2;j<=3;j++) if(a[j]>mx) mx=a[j], id=j;
		sum+=mx;
		cnt[id]++;
		int dt=1e9+7;
		for(int j=1;j<=3;j++){
			if(j==id) continue;
			dt=min(dt,a[id]-a[j]);
		}
		d[id].push_back(dt);
	}
	
	for(int i=1;i<=3;i++){
		if(cnt[i]<=n/2) continue;
		sort(d[i].begin(),d[i].end());
		int j=-1;
		while(cnt[i]>n/2){
			sum-=d[i][++j];
			cnt[i]--;
		}
	}
	printf("%d\n",sum);
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}