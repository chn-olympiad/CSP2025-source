#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N],c[N];
int ma[N],mb[N],mc[N];
int jla,jlb,jlc;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		jla=0;
		jlb=0;
		jlc=0;
		int n;
		cin>>n;
		int maxx=n/2;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				sum+=a[i];
				jla++;
				ma[jla]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				sum+=b[i];
				jlb++;
				mb[jlb]=b[i]-max(a[i],c[i]);
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				sum+=c[i];
				jlc++;
				mc[jlc]=c[i]-max(b[i],a[i]);
			}
		}
		sort(ma+1,ma+1+jla);
		sort(mb+1,mb+1+jlb);
		sort(mc+1,mc+1+jlc);
		if(jla>=maxx){
			for(int i=1;i<=jla-maxx;i++){
				sum-=ma[i];
			}
		}
		if(jlb>=maxx){
			for(int i=1;i<=jlb-maxx;i++){
				sum-=mb[i];
			}
		}
		if(jlc>=maxx){
			for(int i=1;i<=jlc-maxx;i++){
				sum-=mc[i];
			}
		}
		cout<<sum<<endl;
		cout<<jlc<<" "<<maxx<<endl;
	}
}
