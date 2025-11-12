#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int M=1e5;
struct Node {
	int x,id,idx;
}a[N],b[N],c[N],f[N];
int T,n,uid[N],uidx[5];
bool cmp(Node x,Node y) {
	return x.x>y.x;
}
int main() {
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) {
		for(int i=1;i<=M;i++) {
			a[i].x=0,a[i].id=0,a[i].idx=0;b[i].x=0,b[i].id=0,b[i].idx=0;c[i].x=0,c[i].id=0,c[i].idx=0;f[i].x=0,f[i].id=0,f[i].idx=0;
		}
		cin>>n;int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i].x>>b[i].x>>c[i].x;cnt1+=b[i].x;cnt2+=c[i].x;
			a[i].id=i,a[i].idx=1;b[i].id=i,b[i].idx=2;c[i].id=i,c[i].idx=3;
		}
		int r=n/2;
		sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);sort(c+1,c+n+1,cmp);
		if(n==2) {
			int maxn=-0x3f3f3f3f;
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(i==j) continue;
					maxn=max(maxn,max(a[i].x+b[j].x,a[i].x+c[j].x));
				}
			}
			cout<<maxn<<"\n"; 
		}
		else if(cnt1==0&&cnt2==0) {
			long long ans=0;
			for(int i=1;i<=r;i++) {
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
		}
		else {
			int cnt=0;long long ans=0;
			memset(uid,0,sizeof uid);memset(uidx,0,sizeof uidx);
			for(int i=1;i<=n;i++) {
				f[++cnt].x=a[i].x,f[cnt].id=a[i].id,f[cnt].idx=1;f[++cnt].x=b[i].x,f[cnt].id=b[i].id,f[cnt].idx=2;f[++cnt].x=c[i].x,f[cnt].id=c[i].id,f[cnt].idx=3;
			}
			sort(f+1,f+cnt+1,cmp);int cs=0;
			for(int i=1;cs<=n;i++) {
				if(uid[f[i].id]==0&&uidx[f[i].idx]<r) {
					ans+=f[i].x;uid[f[i].id]=114;uidx[f[i].idx]++;cs++;
				}
			}
			cout<<ans<<"\n"; 
		}
	} 
	return 0;
} 
