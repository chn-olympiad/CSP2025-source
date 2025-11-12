#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL t,n,a[100005],d[200005],ans,b[100005],c[100005],e[100005],m1,m2,m3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i],b[i]-=a[i],c[i]-=a[i],a[i]-=a[i],m1++,e[i]=1;
			else if (b[i]>=a[i]&&b[i]>=c[i]) ans+=b[i],a[i]-=b[i],c[i]-=b[i],b[i]-=b[i],m2++,e[i]=2;
			else if (c[i]>=b[i]&&c[i]>=a[i]) ans+=c[i],a[i]-=c[i],b[i]-=c[i],c[i]-=c[i],m3++,e[i]=3;
		}
		if (m1<=n/2&&m2<=n/2&&m3<=n/2){
			cout<<ans<<"\n";
			m1=0;m2=0;m3=0;ans=0;
			continue;
		}
		if (m1>n/2){
			LL zz=0;
			for (int i=1;i<=n;i++){
				if (e[i]==1){
					zz++;
					d[zz]=max(b[i],c[i]);	
				}
			}
			sort (d+1,d+1+zz);
			for (int i=zz;i>=max(zz-(m1-n/2-1),1ll);i--) ans+=d[i];
			cout<<ans<<"\n";
			m1=0;m2=0;m3=0;ans=0;
			continue;
		}
		if (m2>n/2){
			LL zz=0;
			for (int i=1;i<=n;i++){
				if (e[i]==2){
					zz++;
					d[zz]=max(a[i],c[i]);
				}
			}
			sort (d+1,d+1+zz);
			for (int i=zz;i>=max(zz-(m2-n/2-1),1ll);i--)
			 ans+=d[i];
			cout<<ans<<"\n";
			m1=0;m2=0;m3=0;ans=0;
			continue;
		}
		if (m3>n/2){
			LL zz=0;
			for (int i=1;i<=n;i++){
				if (e[i]==3){
					zz++;
					d[zz]=max(b[i],a[i]);
				}
			}
			sort (d+1,d+1+zz);
			for (int i=zz;i>=max(zz-(m3-n/2-1),1ll);i--)
			 ans+=d[i];
			cout<<ans<<"\n";
			m1=0;m2=0;m3=0;ans=0;
			continue;
		}
	}
}//pts 100!!!!!!!!!!!!!
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
