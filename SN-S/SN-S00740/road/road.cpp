#include <bits/stdc++.h>
using namespace std;
int n,m,k,p,q[10025],f[10025],cnt,ans;
struct qwert {
	int x,y,z;
} a[2000025];
bool cmp(qwert i,qwert j) {
	return i.z<j.z;
}
int fa(int r) {
	if(f[r]==r)return r;
	else f[r]=fa(f[r]);
	return f[r];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n+1; i++) f[i]=i;
	for(int i=0; i<m; i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	if(k==0) {
		sort(a,a+m,cmp);
		for(int i=0; i<m; i++) {
			if(fa(a[i].x)!=fa(a[i].y)) {
				f[max(f[a[i].x],f[a[i].y])]=min(f[a[i].x],f[a[i].y]);
				ans+=a[i].z;
				cnt++;
				if(cnt==n-1)break;
			}
		}
		cout<<ans;
	} else {
		for(int i=0; i<k; i++) {
			cin>>p;
			if(p==0) {
				int j=1;
				for(; j<=n; j++,m++) {
					cin>>q[i];
					a[m].x=n+1;
					a[m].y=j;
					a[m].z=q[i];
				}
			}
		}
		sort(a,a+m,cmp);
		for(int i=0; i<m; i++) {
			if(fa(a[i].x)!=fa(a[i].y)) {
				f[max(f[a[i].x],f[a[i].y])]=min(f[a[i].x],f[a[i].y]);
				ans+=a[i].z;
				cnt++;
				if(cnt==n)break;
			}
		}
		cout<<ans;
	}
}
