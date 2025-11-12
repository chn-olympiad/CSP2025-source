#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int t,n,a[100005],b[100005],c[100005],ans;
vector<int> va,vb,vc;
bool cmpa(int cx,int cy){
	int mxx=max(b[cx],c[cx]),mxy=max(b[cy],c[cy]);
	return (a[cx]-mxx)>(a[cy]-mxy);
}
bool cmpb(int cx,int cy){
	int mxx=max(a[cx],c[cx]),mxy=max(a[cy],c[cy]);
	return (b[cx]-mxx)>(b[cy]-mxy);
}
bool cmpc(int cx,int cy){
	int mxx=max(b[cx],a[cx]),mxy=max(b[cy],a[cy]);
	return (c[cx]-mxx)>(c[cy]-mxy);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		va.clear();
		vb.clear();
		vc.clear();
//		int sum=0,sa=0,sb=0;////////
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
//			ans+=max(a[i],max(b[i],c[i]));
			if((a[i]>=b[i])&&(a[i]>=c[i])){
				va.push_back(i);
				ans+=a[i];
			}
			else if((b[i]>=a[i])&&(b[i]>=c[i])){
				vb.push_back(i);
				ans+=b[i];
			}
			else{
				vc.push_back(i);
				ans+=c[i];
			}
		}
//		cout<<sum<<" "<<ans<<" "<<sa<<" "<<sb<<endl;
		if(va.size()>n/2){
			sort(va.begin(),va.end(),cmpa);
			int len=va.size(); 
			while(len>n/2){
				int xb=va[len-1];
				ans-=a[xb];
				ans+=max(b[xb],c[xb]);
				len--;
			}
		}
		if(vb.size()>n/2){
			sort(vb.begin(),vb.end(),cmpb);
			int len=vb.size();
			while(len>n/2){
				int xb=vb[len-1];
				ans-=b[xb];
				ans+=max(a[xb],c[xb]);
				len--;
			}
		}
		if(vc.size()>n/2){
			sort(vc.begin(),vc.end(),cmpc);
			int len=vc.size(); 
			while(len>n/2){
				int xb=vc[len-1];
				ans-=c[xb];
				ans+=max(a[xb],b[xb]);
				len--;
			}
		}
//		cout<<sum<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
