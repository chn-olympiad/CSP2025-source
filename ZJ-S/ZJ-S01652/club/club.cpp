#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int a[N],b[N],c[N];
vector<int> x,y,z;
bool cmp1(int &n,int &m) {
	return a[n]-max(b[n],c[n])>a[m]-max(b[m],c[m]);
}
bool cmp2(int &n,int &m) {
	return b[n]-max(a[n],c[n])>b[m]-max(a[m],c[m]);
}
bool cmp3(int &n,int &m) {
	return c[n]-max(a[n],b[n])>c[m]-max(a[m],b[m]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n,ans=0;
		cin>>n;
		x.clear();
		y.clear();
		z.clear();
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) {
				x.push_back(i);
			} else if(b[i]>=a[i]&&b[i]>=c[i]) {
				y.push_back(i);
			} else if(c[i]>=b[i]&&c[i]>=a[i]) {
				z.push_back(i);
			}
		}
		if(x.size()>n/2+1) {
			cout<<1<<endl;
			sort(x.begin(),x.end(),cmp1);
			for(int i=0; i<y.size(); i++) {
				ans+=b[y[i]];
			}
			for(int i=0; i<x.size(); i++) {
				ans+=a[x[i]];
			}
			for(int i=0; i<z.size(); i++) {
				ans+=c[z[i]];
			}
			for(int i=n/2; i<x.size(); i++) {
				ans-=min(a[x[i]]-b[x[i]],a[x[i]]-c[x[i]]);
			}
		} else if(y.size()>n/2+1) {
			cout<<2<<endl;
			sort(y.begin(),y.end(),cmp2);
			for(int i=n/2; i<y.size(); i++) {
				ans+=max(a[y[i]],c[y[i]]);
			}
			for(int i=0; i<x.size(); i++) {
				ans+=a[x[i]];
			}
			for(int i=0; i<n/2; i++) {
				ans+=b[y[i]];
			}
			for(int i=0; i<z.size(); i++) {
				ans+=c[z[i]];
			}
		} else if(z.size()>n/2+1) {
			cout<<3<<endl;
			sort(z.begin(),z.end(),cmp3);
			
			for(int i=0; i<x.size(); i++) {
				ans+=a[x[i]];
			}
			for(int i=0; i<z.size();i++) {
				ans+=c[z[i]];
			}
			for(int i=0; i<y.size(); i++) {
				ans+=b[y[i]];
			}
			for(int i=n/2; i<z.size(); i++) {
				ans-=min(c[z[i]]-a[z[i]],c[z[i]]-b[z[i]]);
			}
		} else {
			cout<<4<<endl;
			for(int i=0; i<x.size(); i++) {
				ans+=a[x[i]];
			}
			for(int i=0; i<z.size(); i++) {
				ans+=c[z[i]];
			}
			for(int i=0; i<y.size(); i++) {
				ans+=b[y[i]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
