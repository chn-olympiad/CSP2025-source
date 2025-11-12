#include<bits/stdc++.h>
using namespace std;
int t,n,Ans,cnta,cntb,cntc,a[100005],b[100005],c[100005];
vector<int>va,vb,vc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie();
	cin>>t;
	while(t--){
		va.clear();vb.clear();vc.clear(); 
		Ans=0;cnta=0;cntb=0;cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnta++;Ans+=a[i];
				va.push_back(min(a[i]-b[i],a[i]-c[i])); 
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				cntb++;Ans+=b[i];
				vb.push_back(min(b[i]-a[i],b[i]-c[i]));
			}
			else{
				cntc++;Ans+=c[i];
				vc.push_back(min(c[i]-a[i],c[i]-b[i]));
			}
		}
		if(cnta>n/2){
			sort(va.begin(),va.end());
			for(int i=0;i<cnta-n/2;i++)
			    Ans-=va[i];
		}
		if(cntb>n/2){
			sort(vb.begin(),vb.end());
			for(int i=0;i<cntb-n/2;i++)
			    Ans-=vb[i];
		}
		if(cntc>n/2){
			sort(vc.begin(),vc.end());
			for(int i=0;i<cntc-n/2;i++)
			    Ans-=vc[i];
		}
		cout<<Ans<<endl; 
	}
	return 0;
}
