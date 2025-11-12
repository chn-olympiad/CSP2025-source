#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100000],b[100000],c[100000],man;

struct dd{
	long long y,f;
}d[100000];
inline bool p1(dd a,dd b){
	if(a.y==1&&b.y!=1)return 1;
	if(a.y!=1&&b.y==1)return 0;
	return a.f<b.f;
}
inline bool p2(dd a,dd b){
	if(a.y==2&&b.y!=2)return 1;
	if(a.y!=2&&b.y==2)return 0;
	return a.f<b.f;
}
inline bool p3(dd a,dd b){
	if(a.y==3&&b.y!=3)return 1;
	if(a.y!=3&&b.y==3)return 0;
	return a.f<b.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(long long o=0;o<m;o++){
		man=0;
		//
		long long aa=0,bb=0,cc=0;
		cin>>n;
		for(long long i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				aa++;
				man+=a[i];
				d[i].y= 1;
				d[i].f=min(a[i]-b[i],a[i]-c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				bb++;
				man+=b[i];
				d[i].y= 2;
				d[i].f=min(b[i]-a[i],b[i]-c[i]);
			}
			else{
				cc++;
				man+=c[i];
				d[i].y=3;
				d[i].f=min(c[i]-b[i],c[i]-a[i]);
			}
		}
		if(max(aa,max(bb,cc))<=n/2){
			cout<<man<<'\n';
			return 0;
		}
		else {
			long long dn=max(aa,max(bb,cc)) - n/2;
			if(aa>bb&&aa>cc){
				sort(d,d+100000,p1);
			}
			if(bb>aa&&bb>cc){
				sort(d,d+100000,p2);
			}
			if(cc>aa&&cc>bb){
				sort(d,d+100000,p3);
			}
			for(long long i=0;i<dn;i++)man-=d[i].f;
			cout<<man<<'\n';
		}
		//
		
		
	}
	return 0;
}