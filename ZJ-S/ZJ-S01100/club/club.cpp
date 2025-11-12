#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int T,n;
struct Node {
	int v[3];
	int col;
} a[maxn];
int sum[3];
vector<int>tmp;
int flag;
bool cmp(int x,int y) {
	int mx=-1,my=-1;
	for(int i=0; i<=2; i++) {
		if(i==flag) continue;
		mx=max(mx,a[x].v[i]), my=max(my,a[y].v[i]);
	}
	return a[x].v[flag]-mx<a[y].v[flag]-my;
}
void check(int fl) {
	tmp.clear();
	if(sum[fl]<=n/2) return;
	flag=fl;
	for(int i=1; i<=n; i++) {
		if(a[i].col!=fl) continue;
		tmp.push_back(i);
	}
	sort(tmp.begin(),tmp.end(),cmp);
	int s=sum[fl]-n/2-1;
	for(int i=0; i<=s; i++) {
		int j=tmp[i];
		a[j].v[fl]=-1,sum[fl]--;
		int x=a[j].v[0],y=a[j].v[1],z=a[j].v[2];
		if(x>=y&&x>=z) a[j].col=0,sum[0]++;
		else if(y>=x&&y>=z) a[j].col=1,sum[1]++;
		else a[j].col=2,sum[2]++;
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		sum[0]=sum[1]=sum[2]=0;
		cin>>n;
		for(int i=1,x,y,z; i<=n; i++) {
			cin>>x>>y>>z;
			a[i]= {x,y,z,0};
			if(x>=y&&x>=z) a[i].col=0,sum[0]++;
			else if(y>=x&&y>=z) a[i].col=1,sum[1]++;
			else a[i].col=2,sum[2]++;
		}
		if(max({sum[0],sum[1],sum[2]})<=n/2) {
			int ans=0;
			for(int i=1; i<=n; i++) ans+=a[i].v[a[i].col];
			cout<<ans<<"\n";
			continue;
		}
		check(0),check(1),check(2);
		int ans=0;
		for(int i=1; i<=n; i++) ans+=a[i].v[a[i].col];
		cout<<ans<<"\n";
	}
	return 0;
}