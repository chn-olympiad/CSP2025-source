#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+7;

int cnt[7];
int n;

struct node{
	int x,y,xpos,ypos;
}a[N];

struct edge{
	int pos,val;
}b[7];

bool cmp(node a,node b){
	return a.x-a.y>b.x-b.y;
}

bool cmp1(edge a,edge b){
	return a.val>b.val;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>b[j].val;
			b[j].pos=j;
		}
		sort(b+1,b+4,cmp1);
		//for(int j=1;j<=3;j++) cout<<b[j].val<<" ";
		a[i]={b[1].val,b[2].val,b[1].pos,b[2].pos};
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		if(cnt[a[i].xpos]>=n/2){
			cnt[a[i].ypos]++;
			ans+=a[i].y;
		} else {
			ans+=a[i].x;
			cnt[a[i].xpos]++;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
