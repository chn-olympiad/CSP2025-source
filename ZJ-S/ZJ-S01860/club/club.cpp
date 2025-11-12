#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N],ans,m;
vector<int>va,vb,vc,d;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		va.clear(),vb.clear(),vc.clear(),d.clear();
		ans=m=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			ans+=max(a[i],max(b[i],c[i]));
			if(a[i]>=b[i]&&a[i]>=c[i])
				va.push_back(i);
			else if(b[i]>=a[i]&&b[i]>=c[i])
				vb.push_back(i);
			else
				vc.push_back(i);
		}
		//m ge bian
		if(va.size()>(n>>1)){
			m=va.size()-(n>>1);
			for(int j=0;j<va.size();j++){
				int i=va[j];
				d.push_back(a[i]-max(b[i],c[i]));
			}
				
		}
		if(vb.size()>(n>>1)){
			m=vb.size()-(n>>1);
			for(int j=0;j<vb.size();j++){
				int i=vb[j];
				d.push_back(b[i]-max(a[i],c[i]));
			}
				
		}
		if(vc.size()>(n>>1)){
			m=vc.size()-(n>>1);
			for(int j=0;j<vc.size();j++){
				int i=vc[j];
				d.push_back(c[i]-max(a[i],b[i]));
			}
		}
		//tan xin bian m ge cha min
		sort(d.begin(),d.end());
		for(int i=0;i<m;i++)
			ans-=d[i];
		printf("%d\n",ans);
	}
	return 0;
}
