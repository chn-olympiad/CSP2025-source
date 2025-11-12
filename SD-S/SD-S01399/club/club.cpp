using namespace std;
#include<bits/stdc++.h>
#define ll long long
const ll N=1e6+7;
struct abc{
	ll onee,twoo,id1,id2;
}yg[N];
bool cmp(abc a,abc b){
	if(a.onee!=b.onee){
		return a.onee>b.twoo;
		
	}else{
		return a.twoo<b.twoo;
	}
}


ll nummm[100];
ll n,m;ll t;ll anss=0;
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int qqq=1;qqq<=t;qqq++){
		anss=0;
		nummm[1]=0;nummm[2]=0;nummm[3]=0;
		cin>>n;
		memset(yg,0,sizeof(yg));
		for(int i=1;i<=n;i++){
			for(int ii=1;ii<=3;ii++){
				if(ii==1){
					ll ttt=0;
					cin>>ttt;
					yg[i].id1=1;
					yg[i].id2=1;
					yg[i].onee=ttt;
					yg[i].twoo=ttt;
				}else{
					ll ttt;cin>>ttt;
					if(yg[i].onee<ttt){
						yg[i].id2=yg[i].id1;yg[i].twoo=yg[i].onee;
						yg[i].id1=ii;yg[i].onee=ttt;
					}else if(yg[i].twoo<ttt){
						yg[i].id2=ii;yg[i].twoo=ttt;
					}
				}
				
			}
			
		}
		sort(yg+1,yg+1+n,cmp);
		for(int i=1;i<=n;i++){
			ll fmax=yg[i].onee;ll fid=yg[i].id1;
			ll smax=yg[i].twoo;ll sid=yg[i].id2;
			if(nummm[fid]<=(n/2)){
				nummm[fid]++;
				anss+=fmax;
				
			}else{
				nummm[sid]++;
				anss+=smax;
			}
		}
		cout<<anss<<endl;
	}
	
	
	
	
	
	return 0;
}



