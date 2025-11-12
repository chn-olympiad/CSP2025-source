#include<bits/stdc++.h>
using namespace std;
long long const Q=1e5+50;
struct aaa{
	long long a,b,c,d,e,flag;
}x[Q];
bool cmp(aaa l,aaa r){
	return l.d<r.d;
}
int main () {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long ans=0,ap=0,bp=0,cp=0;
		long long n;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			long long maxx=max(x[i].a,max(x[i].b,x[i].c));
			long long minn=min(x[i].a,min(x[i].b,x[i].c));
			long long midd=x[i].b+x[i].a+x[i].c-maxx-minn;
			x[i].d=maxx-midd;
			x[i].e=maxx;
			if(maxx==x[i].a)x[i].flag=1;
			if(maxx==x[i].b)x[i].flag=2;
			if(maxx==x[i].c)x[i].flag=3;
		}
		sort(x+1,x+1+n,cmp);
		for(long long i=1;i<=n;i++){
			ans+=x[i].e;
			if(x[i].flag==1)ap++;
			if(x[i].flag==2)bp++;
			if(x[i].flag==3)cp++;
		}
		if(ap>n/2){
			for(long long i=1;i<=n;i++){
				if(ap<=n/2){
					break;
				}
				if(x[i].e==x[i].a){
					ans-=x[i].d;
					ap--;
				}
			}
		}
		if(bp>n/2){
			for(long long i=1;i<=n;i++){
				if(bp<=n/2){
					break;
				}
				if(x[i].e==x[i].b){
					ans-=x[i].d;
					bp--;
				}
			}
		}
		if(cp>n/2){
			for(long long i=1;i<=n;i++){
				if(cp<=n/2){
					break;
				}
				if(x[i].e==x[i].c){
					ans-=x[i].d;
					cp--;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}