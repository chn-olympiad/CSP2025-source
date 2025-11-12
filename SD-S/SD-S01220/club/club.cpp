#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int a[N][3],b[N],c[N];
int x=0,y=0,z=0;
int t;
int m[N],p[N],q[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n;
	int maxn1=0,maxn2=0,maxn3=0;
	while(t--) {
		int ans=0;
		int cnt=0,sum=0;
		cin>>n;
		if(n==2) {
			for(int i=1; i<=n; i++)
				for(int j=1; j<=3; j++)
					cin>>a[i][j];
			for(int i=1; i<=3; i++) {
				for(int j=1; j<=3,j!=i; j++)
					ans=max(ans,a[1][i]+a[2][j]);
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++)
				cin>>a[i][j];
			b[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				b[i]=a[i][1],c[i]=1,x++;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				b[i]=a[i][2],c[i]=2,y++;
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
				b[i]=a[i][3],c[i]=3,z++;
			if(a[i][2]==0&&a[i][3]==0)
				cnt++,m[i]=a[i][1];
			if(a[i][3]==0&&a[i][2]!=0) {
				sum++;
				m[i]=a[i][1];
				p[i]=a[i][2];
			}

		}
		if(x<=n/2&&y<=n/2&&z<=n/2) {
			for(int i=1; i<=n; i++)
				ans+=b[i];
			cout<<ans<<endl;
			continue;
		} else if(cnt==n) {
			sort(m+1,m+n+1);
			for(int i=n; i>n/2; i--)
				ans+=m[i];
			cout<<ans<<endl;
			continue;
		} else if(sum==n) {
			int s=0;
			for(int i=1; i<=n; i++) {
				if(a[i][1]>=a[i][2]&&s<n/2)
					ans+=a[i][1],s++,q[i]=i;
				if(q[i]==0)
					ans+=a[i][2];
			}
			cout<<ans<<endl;
			continue;
		} else {
			for(int i=1; i<=n; i++)
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<ans<<endl;
		}
//		else if(x>=n/2){
//			int m[n];
//			for(int i=1;i<=n;i++){
//				if(c[i]==1)
//				m[i]=b[i];
//				if(c[i]!=1)
//				ans+=b[i];
//			}
//			sort(m+1,m+n+1);
//			for(int i=n/2;i>=1;i--)
//			ans+=m[i];
//			for(int i=1;i<=n;i++){
//				for(int j=n/2;j>=1;j--){
//					if(b[i])
//				}
//			}
//		}

		cout<<ans<<endl;
	}
	return 0;
}
