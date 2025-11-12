#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
void swapp(int &a,int &b){
	int t;
	t=a;a=b;b=t;
	return;
}
int p[100005],q[100005],r[100005],cntp,cntq,cntr;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	int ans;
	while(T--){
		int n;
		cin>>n;
		ans=0;
		cntp=0;cntq=0;cntr=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c){
				if(b<c)swapp(b,c);
				ans+=a;
				p[++cntp]=a-b;
			}
			else if(b>=a&&b>=c){
				if(a<c)swapp(a,c);
				ans+=b;
				q[++cntq]=b-a;
			}
			else if(c>=b&&c>=a){
				if(b<a)swapp(b,a);
				ans+=c;
				r[++cntr]=c-b;
			}
		}
		if(cntp>(n/2)){
			sort(p+1,p+cntp+1);
			cntp=cntp-(n/2);
			for(int i=1;i<=cntp;i++){
				ans-=p[i];
			}
		}
		if(cntq>(n/2)){
			sort(q+1,q+cntq+1);
			cntq=cntq-(n/2);
			for(int i=1;i<=cntq;i++){
				ans-=q[i];
			}
		}
		if(cntr>(n/2)){
			sort(r+1,r+cntr+1);
			cntr=cntr-(n/2);
			for(int i=1;i<=cntr;i++){
				ans-=r[i];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
