#include<bits/stdc++.h>
using namespace std;
struct A{
	long long x[5],fi,se;
}a[100005];
bool cmp(A c,A d){
	if(c.fi==d.fi){
		return c.se>d.se;
	}
	return c.fi>d.fi;
}
long long n,t,ans,r[5],last[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--){
		ans=0,r[1]=r[2]=r[3]=last[1]=last[2]=last[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			a[i].fi=max(a[i].x[1],max(a[i].x[2],a[i].x[3]));
			a[i].se=a[i].x[1]+a[i].x[2]+a[i].x[3]-min(a[i].x[1],min(a[i].x[2],a[i].x[3]))-a[i].fi;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i].fi==a[i].x[j]){
					if(r[j]+1<=n/2){
						if(r[j]+1==n/2){
							last[j]=i;	
						}
						ans+=a[i].fi;
						r[j]++;
					}
					else{
						if(a[last[j]].fi+a[i].se<a[last[j]].se+a[i].fi){
							ans-=a[last[j]].fi;
							ans+=a[last[j]].se+a[i].fi;
						}
						else{
							ans+=a[i].se;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			a[i].x[1]=a[i].x[2]=a[i].x[3]=a[i].fi=a[i].se=0;
		} 
	}
	return 0;
}
