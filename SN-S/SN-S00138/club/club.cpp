// 夏菁阳 SN-S00138 西安高新第一中学
#include<bits/stdc++.h>
#define il inline
using namespace std;

constexpr int MAXN=1e5+5;
int T,n,a[MAXN][3];
priority_queue<int>q[3];

il void sve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			q[0].push(max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
			ans+=a[i][0];
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			q[1].push(max(a[i][0]-a[i][1],a[i][2]-a[i][1]));
			ans+=a[i][1];
		}else{
			q[2].push(max(a[i][0]-a[i][2],a[i][1]-a[i][2]));
			ans+=a[i][2];
		}
	}
	int fk=n>>1;
	if((int)max({q[0].size(),q[1].size(),q[2].size()})<=fk) return cout<<ans<<'\n',void();
	while((int)q[0].size()>fk) ans+=q[0].top(),q[0].pop();
	while((int)q[1].size()>fk) ans+=q[1].top(),q[1].pop();
	while((int)q[2].size()>fk) ans+=q[2].top(),q[2].pop();
	cout<<ans<<'\n';
}
il void cls(){
	priority_queue<int>().swap(q[0]);
	priority_queue<int>().swap(q[1]);
	priority_queue<int>().swap(q[2]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>T;
	while(T--) sve(),cls();
	return 0;
}

