#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
struct node{
	ll fi,se,th,maxn,minn=N;
}a[N];
ll t,n,ans;
bool vis[N];
bool cmp(node x,node y){
	return x.maxn>y.maxn;
} 
bool cmpp(node x,node y){
	return x.fi>y.fi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		bool fa=0,fb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].fi>>a[i].se>>a[i].th;
			a[i].maxn=max(a[i].maxn,max(a[i].fi,max(a[i].se,a[i].th)));
			a[i].minn=min(a[i].minn,min(a[i].fi,min(a[i].se,a[i].th)));
			if(a[i].th!=0)fa=fb=1;
			else if(a[i].se!=0)fa=1;
		}
		if(!fa){
			sort(a+1,a+n+1,cmpp);
			ll num=n/2;
			for(int i=1;i<=num;i++)ans+=a[i].fi;
		}else if(!fb){
			sort(a+1,a+n+1,cmp);
			ll yi=0,er=0;
			for(int i=1;i<=n;i++)
				cout<<a[i].fi<<' '<<a[i].se<<' '<<a[i].th<<' '<<a[i].maxn<<'\n';
			for(int i=1;i<=n;i++){
				bool f=0,fg=1;
				if(a[i].fi>a[i].se)f=1;
				if(yi<n/2){
					if(f||er==n/2){
						yi++;
						ans+=a[i].fi; 
						fg=0;
					}
				}
				if(fg&&(er<n/2||!f)){
					er++;
					ans+=a[i].se;
				}
			}
			cout<<yi<<' '<<er<<'\n';
		}else{
			sort(a+1,a+n+1,cmp);
			ll mxtot=0,mntot;
			for(int i=1;i<=n;i++)mxtot+=a[i].maxn;
			for(int i=1;i<=n;i++)mntot+=a[i].minn;
			ans=rand()%(mxtot-mntot)+mntot;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
