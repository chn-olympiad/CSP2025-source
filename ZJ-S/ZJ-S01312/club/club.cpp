#include<bits/stdc++.h>
using namespace std;
int T,n,i,a[100010][5],f[100010],b[100010],t,c[100010];long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		f[1]=0;f[2]=0;f[3]=0;
		for(i=1;i<=n;i++)
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) b[i]=1,f[1]++;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) b[i]=2,f[2]++;
			else b[i]=3,f[3]++;
		for(i=1;i<=n;i++) ans=ans+a[i][b[i]];
		if(f[1]>n/2){
			t=0;
			for(i=1;i<=n;i++)
				if(b[i]==1) c[++t]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			sort(c+1,c+1+t);
			for(i=1;i<=t-n/2;i++) ans=ans-c[i];
			cout<<ans<<"\n";continue;
		}
		if(f[2]>n/2){
			t=0;
			for(i=1;i<=n;i++)
				if(b[i]==2) c[++t]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			sort(c+1,c+1+t);
			for(i=1;i<=t-n/2;i++) ans=ans-c[i];
			cout<<ans<<"\n";continue;
		}
		if(f[3]>n/2){
			t=0;
			for(i=1;i<=n;i++)
				if(b[i]==3) c[++t]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			sort(c+1,c+1+t);
			for(i=1;i<=t-n/2;i++) ans=ans-c[i];
			cout<<ans<<"\n";continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}