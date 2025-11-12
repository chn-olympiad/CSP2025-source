#include<bits/stdc++.h>
using namespace std;
struct cl{
	long long a,b,c,da,db,dc,wh,dd;
}st[100005];
bool comda(cl aa,cl bb){
	return aa.da<bb.da;
}
bool comb(cl aa,cl bb){
	return aa.b>bb.b;
}
bool comdb(cl aa,cl bb){
	return aa.db<bb.db;
}
bool comcom(cl aa,cl bb){
	return aa.dd<bb.dd;
}
long long numa,numc,t,n,ans,cona,conb,conc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long tt=1;tt<=t;tt++){
		numa=0;numc=0;ans=0;cona=0;conc=0;conb=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
			if(st[i].a==0)numa++;
			if(st[i].c==0)numc++;
			long long maxn=max(st[i].a,max(st[i].b,st[i].c));
			if(st[i].a==maxn){
				cona++;ans+=st[i].a;
				st[i].db=st[i].a-st[i].b;
				st[i].dc=st[i].a-st[i].c;
				st[i].da=20007;
				st[i].wh=1;
				st[i].dd=min(st[i].da,min(st[i].db,st[i].dc));
			}
			else if(st[i].b==maxn){
				conb++;ans+=st[i].b;
				st[i].da=st[i].b-st[i].a;
				st[i].dc=st[i].b-st[i].c;
				st[i].db=20007;
				st[i].wh=2;
				st[i].dd=min(st[i].da,min(st[i].db,st[i].dc));
			}
			else{
				conc++;ans+=st[i].c;
				st[i].db=st[i].c-st[i].b;
				st[i].da=st[i].c-st[i].a;
				st[i].dc=20007;
				st[i].wh=3;
				st[i].dd=min(st[i].da,min(st[i].db,st[i].dc));
			}
		}
		if(cona<=n/2 && conb<=n/2 && conc<=n/2){
			cout<<ans<<endl;
		}
		else if(numa==n && numc==n){
			ans=0;
			sort(st+1,st+n+1,comb);
			for(long long i=1;i<=n/2;i++)ans+=st[i].b;
			cout<<ans<<endl;
		}
		else if(numc==n){
			if(conb>n/2){
				sort(st+1,st+n+1,comda);
				for(long long i=1;i<=conb-n/2;i++)ans-=st[i].da;
				cout<<ans<<endl;
			}
			else{
				sort(st+1,st+n+1,comdb);
				for(long long i=1;i<=cona-n/2;i++)ans-=st[i].db;
				cout<<ans<<endl;
			}
		}
		else{
			sort(st+1,st+n+1,comcom);
			long long i=1;
			if(cona>n/2){
				while(cona>n/2){
					if(st[i].wh==1){
						ans-=st[i].dd;
						cona--;
					}
					i++;
				}
			}
			if(conb>n/2){
				while(conb>n/2){
					if(st[i].wh==2){
						ans-=st[i].dd;
						conb--;
					}
					i++;
				}
			}
			if(conc>n/2){
				while(conc>n/2){
					if(st[i].wh==3){
						ans-=st[i].dd;
						conc--;
					}
					i++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
