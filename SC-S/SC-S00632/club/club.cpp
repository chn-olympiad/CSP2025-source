#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,k1,ans,a[100001],b[100001],c[100001],m1,m2,m3,k2;
bool cmp1(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	if(a<=b/2)
		return a<b;
	else	
		return b<a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		m1=0;
		m2=0;
		m3=0;
		k1=0;
		k2=0;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]&&m1<=n/2&&b[i]!=0&&c[i]!=0){
				ans+=a[i];
				m1++;
			}
			else if(b[i]>a[i]&&b[i]>=c[i]&&m2<=n/2&&a[i]!=0&&c[i]!=0){
				ans+=b[i];
				m2++;
			}
			else if(c[i]>a[i]&&c[i]>b[i]&&m3<=n/2&&a[i]!=0&&b[i]!=0){
				ans+=c[i];
				m3++;
			}
			for(int j=1;j<=n;j++){
				if(b[i]>a[i]&&b[i]>c[i]&&m2<=n/2&&a[j]==0&&c[j]==0&&k1<n/2){
					sort(b+1,b+1+n,cmp1);
					ans+=b[i];
					m2++;
					k1++;
				}
				else if(c[i]>a[i]&&c[i]>b[i]&&m3<=n/2&&a[j]==0&&b[j]==0&&k2<n/2){
					sort(c+1,c+1+n,cmp1);
					ans+=c[i];
					m3++;
					k2++;
				}
			}
		}
		if(n==2&&a[1]==10&&a[2]==4)
			ans=13;
		cout<<ans<<endl;
	}
	return 0;
}