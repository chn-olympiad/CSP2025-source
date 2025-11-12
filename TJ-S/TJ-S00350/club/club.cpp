#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
struct st{
	int a,b,c,maxx,smaxx,tmaxx,idx,sidx,tidx;
};
st x[200005];
bool cmp(st p,st q){
	if(p.maxx<q.maxx){
		swap(p,q);
	}
}
int cnt[4],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>max(x[i].b,x[i].c)){
				x[i].maxx=x[i].a;
				if(x[i].b>x[i].c){
					x[i].smaxx=x[i].b;
					x[i].tmaxx=x[i].c;
					x[i].sidx=2;
					x[i].sidx=3;
				}
				else{
					x[i].smaxx=x[i].c;
					x[i].tmaxx=x[i].b;
					x[i].sidx=3;
					x[i].sidx=2;
				}
				x[i].idx=1;
			}
			else if(x[i].b>max(x[i].a,x[i].c)){
				x[i].maxx=x[i].b;
				if(x[i].a>x[i].c){
					x[i].smaxx=x[i].a;
					x[i].tmaxx=x[i].c;
					x[i].sidx=1;
					x[i].sidx=3;
				}
				else{
					x[i].smaxx=x[i].c;
					x[i].tmaxx=x[i].a;
					x[i].sidx=3;
					x[i].sidx=1;
				}
				x[i].idx=2;
			}
			if(x[i].c>max(x[i].a,x[i].b)){
				x[i].maxx=x[i].c;
				if(x[i].a>x[i].b){
					x[i].smaxx=x[i].a;
					x[i].tmaxx=x[i].b;
					x[i].sidx=1;
					x[i].sidx=2;
				}
				else{
					x[i].smaxx=x[i].b;
					x[i].tmaxx=x[i].a;
					x[i].sidx=2;
					x[i].sidx=1;
				}
				x[i].idx=3;
			}
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[x[i].idx]<n/2){
				cnt[x[i].idx]++;
				ans+=x[i].maxx;
			}
			else{
				cnt[x[i].sidx]++;
				ans+=x[i].smaxx;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
