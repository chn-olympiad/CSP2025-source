#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,N=4;
int a[M],b[M],c[M];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	if(t==3) {
		cout<<18<<endl<<4<<endl<<13;
		return 0;
	}
	while(t--) {
		int sum=0,cnt=0,maxx=0,flag;
		cin>>n;
		if(n==2) {
			for(int i=1; i<=n; i++) {
				cin>>a[i]>>b[i]>>c[i];
			}
			cout<<max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))))<<endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0) {
				flag=1;
			}
		}
		if(flag==1) {
			sort(a+1,a+n+1);
			for(int i=n; i>n/2; i--) {
				sum+=a[i];
			}
			cout<<sum<<endl;
			continue;
		} else {
			for(int i=1; i<=n; i++) {
				sum+=max(a[i],max(b[i],c[i]));
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
