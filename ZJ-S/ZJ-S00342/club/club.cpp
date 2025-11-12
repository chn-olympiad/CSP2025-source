#include<bits/stdc++.h>
using namespace std;
long long n,cnt,cnt1,cnt2,cnt3,ans,a[100005],b[100005],c[100005],f[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cnt=cnt1=cnt2=cnt3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(a[i],max(b[i],c[i]));
			if(a[i]==max(a[i],max(b[i],c[i]))){cnt1++;continue;}
			if(b[i]==max(a[i],max(b[i],c[i]))){cnt2++;continue;}
			if(c[i]==max(a[i],max(b[i],c[i]))){cnt3++;continue;}
		}
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				if(a[i]==max(a[i],max(b[i],c[i])))f[++cnt]=a[i]-max(b[i],c[i]);
			}
		}
		if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				if(b[i]==max(a[i],max(b[i],c[i])))f[++cnt]=b[i]-max(a[i],c[i]);
			}
		}
		if(cnt3>n/2){
			for(int i=1;i<=n;i++){
				if(c[i]==max(a[i],max(b[i],c[i])))f[++cnt]=c[i]-max(a[i],b[i]);
			}
		}
		sort(f+1,f+1+cnt);
		for(int i=1;i<=cnt-n/2;i++)ans-=f[i];
		cout<<ans<<"\n";
	}
	return 0;
}
