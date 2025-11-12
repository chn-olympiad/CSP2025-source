#include<bits/stdc++.h>
using namespace std;
struct m{
	int f,s,t;
};
bool cmpf(m a1,m b1){
	return a1.f<b1.f;
}
bool cmps(m a1,m b1){
	return a1.s<b1.s;
}
bool cmpt(m a1,m b1){
	return a1.t<b1.t;
}
int check(m a1){
	if(a1.f>=a1.s&&a1.f>=a1.t){
		return 1;
	}
	if(a1.s>=a1.f&&a1.s>=a1.t){
		return 2;
	}
	if(a1.t>=a1.s&&a1.t>=a1.f){
		return 3;
	}
}

m af[50005],as[50005],at[50005];
m a[100005];
int main(){
	freopen(club.in,"r",stdin);
	freopen(club.out,"w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,nf=0,ns=0,nt=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		for(int i=0;i<n;i++){
			if(check(a[i])==1){
				if(nf<n/2){
					af[nf++]=a[i];
					a[i].f=0;
					a[i].s=0;
					a[i].t=0;
				}else{
					sort(af,af+nf,cmpf);
					if(af[0].f>=a[i].f){
						continue;
					}else{
						m ls;
						ls=af[0];
						af[0]=a[i];
						a[i]=ls;
						a[i].f=-1;
					}
				}
			}
			if(check(a[i])==2){
				if(ns<n/2){
					as[ns++]=a[i];
					a[i].f=0;
					a[i].s=0;
					a[i].t=0;
				}else{
					sort(as,as+ns,cmps);
					if(as[0].s>=a[i].s){
						continue;
					}else{
						m ls;
						ls=as[0];
						as[0]=a[i];
						a[i]=ls;
						a[i].s=-1;
					}
				}
			}
			if(check(a[i])==3){
				if(nt<n/2){
					at[nt++]=a[i];
					a[i].f=0;
					a[i].s=0;
					a[i].t=0;
				}else{
					if(at[nt].t>=a[i].t){
						continue;
					}else{
						m ls;
						ls=at[nt];
						at[nt]=a[i];
						a[i]=ls;
						a[i].t=-1;
					}
				}
			}
		}
		for(int i=0;i<nf;i++){
			ans+=af[i].f;
		}
		cout<<endl;
		for(int i=0;i<ns;i++){
			ans+=as[i].s;
		}
		for(int i=0;i<nt;i++){
			ans+=at[i].t;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
