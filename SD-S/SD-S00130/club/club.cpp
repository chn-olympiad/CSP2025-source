#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010],b[100010],c[100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%lld",&n);
		vector<int> va,vb,vc,vd;
		int cnta=0,cntb=0,cntc=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",a+i,b+i,c+i);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnta++,ans+=a[i];
				va.push_back(i);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				cntb++,ans+=b[i];
				vb.push_back(i);
			}
			else{
				cntc++,ans+=c[i];
				vc.push_back(i);
			}
		}
		if(va.size()<=n/2&&vb.size()<=n/2&&vc.size()<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		if(va.size()>n/2){
			for(int i:va)vd.push_back(max(b[i],c[i])-a[i]);
		}
		if(vb.size()>n/2){
			for(int i:vb)vd.push_back(max(a[i],c[i])-b[i]);
		}
		if(vc.size()>n/2){
			for(int i:vc)vd.push_back(max(a[i],b[i])-c[i]);
		}
		sort(vd.begin(),vd.end(),greater<int>());
		for(int i=0;i<max(max(va.size(),vb.size()),vc.size())-n/2;i++)ans+=vd[i];
		printf("%lld\n",ans);
	}
}
