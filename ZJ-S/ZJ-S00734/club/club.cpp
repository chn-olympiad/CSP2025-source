#include<bits/stdc++.h>
using namespace std;
int T,a[100010],b[100010],c[100010],d[100010],p[100010],n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n;
		int x=0,y=0,z=0,ans=0;
		int s1=0,s2=0,s3=0,cnt=0;
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (a[i]>=b[i]){
				if (a[i]>=c[i]) ans+=a[i],s1++,p[i]=1;
					else ans+=c[i],s3++,p[i]=3;
			}
			else{
				if (b[i]>=c[i]) ans+=b[i],s2++,p[i]=2;
					else ans+=c[i],s3++,p[i]=3;
			}
		}
		if (s1<=n/2&&s2<=n/2&&s3<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int s=max(max(s1,s2),s3);
		for (int i=1;i<=n;i++){
			if (s1>n/2&&p[i]==1) d[++cnt]=a[i]-max(b[i],c[i]);
			if (s2>n/2&&p[i]==2) d[++cnt]=b[i]-max(a[i],c[i]);
			if (s3>n/2&&p[i]==3) d[++cnt]=c[i]-max(b[i],a[i]);
		}
		sort(d+1,d+1+cnt);
		for (int i=1;i<=cnt;i++){
			if (s<=n/2) break;
			ans-=d[i];s--;
		}
		cout<<ans<<endl;
	}
	return 0;
}