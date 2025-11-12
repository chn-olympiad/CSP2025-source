#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int t,n,m,ans,b1,b2,b3;
bool flag1;

struct node{
	int x,y,z,maxk;
}a[maxn];

bool cmp1(node a,node b) {
	if(a.x==b.x) {
		if(a.y==b.y) return a.z>b.z;
		return a.y>b.y;
	} 
	return a.x>b.x;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		ans=0;
		for(int i=1; i<=n; ++i) {
			a[i].x=0;
			a[i].y=0;
			a[i].z=0;
		}
		cin>>n;
		for(int i=1; i<=n; ++i) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		m=n/2;
		sort(a+1,a+n+1,cmp1);
		for(int i=1; i<=n; ++i) {
			ans+=a[i].x;
		}
		cout<<ans<<'\n';
		break;
	}	
	return 0;
} 
