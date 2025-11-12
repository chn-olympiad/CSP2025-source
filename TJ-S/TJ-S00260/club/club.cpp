#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
struct mydd{
	int fi,se,th;
	int mxnum,mx;
	int minum,mi;
	int semxi,semxinum;
	int cha;
}myd[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>myd[i].fi>>myd[i].se>>myd[i].th;
		int maxx=max(max(myd[i].fi,myd[i].se),myd[i].th);
		int minx=min(min(myd[i].fi,myd[i].se),myd[i].th);
		
		if(maxx==myd[i].fi) myd[i].mx=1;
		else if(maxx==myd[i].se) myd[i].mx=2;
		else if(maxx==myd[i].th) myd[i].mx=3;
		
		if(minx==myd[i].fi and myd[i].mx!=1) myd[i].mi=1;
		else if(minx==myd[i].se and myd[i].mx!=2) myd[i].mi=2;
		else if(minx==myd[i].th and myd[i].mx!=3) myd[i].mi=3;
		
		myd[i].minum=minx;
		myd[i].mxnum=maxx;
		
		if(myd[i].mx!=1 and myd[i].mi!=1){
			myd[i].semxinum=myd[i].fi;
			myd[i].semxi=1;
		} 
		else if(myd[i].mx!=2 and myd[i].mi!=2){
			myd[i].semxinum=myd[i].se;
			myd[i].semxi=2;
		} 
		else if(myd[i].mx!=3 and myd[i].mi!=3){
			myd[i].semxinum=myd[i].th;
			myd[i].semxi=3;
		}
		myd[i].cha=maxx-myd[i].semxinum;
	}
	int t1=0,t2=0,t3=0;
	for(int i=1;i<=n;i++){
		if(myd[i].mx==1){
			t1++;
		}
		else if(myd[i].mx==2){
			t2++;
		}
		else if(myd[i].mx==3){
			t3++;
		}
	}
	int man=0;
	if(t1<=n/2 and t2<=n/2 and t3<=n/2){
		for(int i=1;i<=n;i++){
			man+=myd[i].mxnum;
		}
		cout<<man<<'\n';
		return;
	}
	else if(t1>n/2){
		bool flaag[n+5];
		memset(flaag,true,sizeof flaag);
		int minn=1e9;
		for(int i=1;i<=n;i++){
			if(myd[i].mx==1){
				minn=(minn>=myd[i].cha?i:minn);
				flaag[i]==false;
			}
		}
		for(int i=1;i<=n;i++){
			if(myd[i].cha==minn) t1--;
		}
		if(t1<=n/2){
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minn){
					man+=myd[i].semxinum;
					continue;
				}
				man+=myd[i].mxnum;
			}
			cout<<man<<'\n';
		}
		else{
			int minnn=1e9;
			for(int i=1;i<=n;i++){
				if(myd[i].mx==1 and flaag[i]){
					minnn=(minnn>=myd[i].cha?i:minnn);
				}
			}
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minnn) t3--;
			}
				for(int i=1;i<=n;i++){
					if(myd[i].cha==minnn){
						man+=myd[i].semxinum;
						continue;
					}
					man+=myd[i].mxnum;
				}
				cout<<man<<'\n';
			
			
		}
	}
	else if(t2>n/2){
		bool flaag[n+5];
		memset(flaag,true,sizeof flaag);
		int minn=1e9;
		for(int i=1;i<=n;i++){
			if(myd[i].mx==2){
				minn=(minn>=myd[i].cha?i:minn);
				flaag[i]==false;
			}
		}
		for(int i=1;i<=n;i++){
			if(myd[i].cha==minn) t2--;
		}
		if(t2<=n/2){
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minn){
					man+=myd[i].semxinum;
					continue;
				}
				man+=myd[i].mxnum;
			}
			cout<<man<<'\n';
		}
		else{
			int minnn=1e9;
			for(int i=1;i<=n;i++){
				if(myd[i].mx==2 and flaag[i]){
					minnn=(minnn>=myd[i].cha?i:minnn);
				}
			}
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minnn) t2--;
			}
				for(int i=1;i<=n;i++){
					if(myd[i].cha==minnn){
						man+=myd[i].semxinum;
						continue;
					}
					man+=myd[i].mxnum;
				}
				cout<<man<<'\n';
			
		}
	}
	else if(t3>n/2){
		bool flaag[n+5];
		memset(flaag,true,sizeof flaag);
		int minn=1e9;
		for(int i=1;i<=n;i++){
			if(myd[i].mx==3){
				minn=(minn>=myd[i].cha?i:minn);
				flaag[i]==false;
			}
		}
		for(int i=1;i<=n;i++){
			if(myd[i].cha==minn) t3--;
		}
		if(t3<=n/2){
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minn){
					man+=myd[i].semxinum;
					continue;
				}
				man+=myd[i].mxnum;
			}
			cout<<man<<'\n';
		}
		else{
			int minnn=1e9;
			for(int i=1;i<=n;i++){
				if(myd[i].mx==3 and flaag[i]){
					minnn=(minnn>=myd[i].cha?i:minnn);
				}
			}
			for(int i=1;i<=n;i++){
				if(myd[i].cha==minnn) t3--;
			}
				for(int i=1;i<=n;i++){
					if(myd[i].cha==minnn){
						man+=myd[i].semxinum;
						continue;
					}
					man+=myd[i].mxnum;
				}
				cout<<man<<'\n';
			
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
