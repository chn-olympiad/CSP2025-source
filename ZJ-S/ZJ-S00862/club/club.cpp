#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int _,n,a[N][4],m[N],ma[N],gs[4];
struct C{
	int x,xb;
};
bool cmp(C a,C b){
	return a.x<b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_;
	while(_--){
		memset(a,0,sizeof(a));
		memset(m,0,sizeof(m));
		memset(ma,0,sizeof(ma));
		memset(gs,0,sizeof(gs));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ma[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if(ma[i]==a[i][1])m[i]=1;
			else if(ma[i]==a[i][2])m[i]=2;
			else m[i]=3;
			gs[m[i]]++;
			ans+=ma[i];
		}
		int could=n/2;
		while(gs[1]>could||gs[2]>could||gs[3]>could){
			if(gs[1]>could){
				C ts[N];
				for(int i=1;i<=n;i++){
					if(m[i]==1){
						if(a[i][1]-a[i][2]==a[i][1]-a[i][3]){
							ts[i].x=a[i][1]-a[i][2];
							if(gs[2]<gs[3]){
								ts[i].xb=2;
							}else{
								ts[i].xb=3;
							}
						}else if(a[i][1]-a[i][2]<a[i][1]-a[i][3]){
							ts[i].x=a[i][1]-a[i][2];
							ts[i].xb=2;
						}else{
							ts[i].x=a[i][1]-a[i][3];
							ts[i].xb=3;
						}
					}else{
						ts[i].x=-1;
					}
				}
				sort(ts+1,ts+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(ts[i].x>=0){
						ans-=ts[i].x;
						gs[1]--;
						gs[ts[i].xb]++;
					}
					if(gs[1]<=could){
						break;
					}
				}
			}
			if(gs[2]>could){
				int chenge=gs[2]-could;
				C ts[N];
				for(int i=1;i<=n;i++){
					if(m[i]==2){
						if(a[i][2]-a[i][1]==a[i][2]-a[i][3]){
							ts[i].x=a[i][2]-a[i][1];
							if(gs[1]<gs[3]){
								ts[i].xb=1;
							}else{
								ts[i].xb=3;
							}
						}else if(a[i][2]-a[i][1]<a[i][2]-a[i][3]){
							ts[i].x=a[i][2]-a[i][1];
							ts[i].xb=1;
						}else{
							ts[i].x=a[i][2]-a[i][3];
							ts[i].xb=3;
						}
					}else{
						ts[i].x=-1;
					}
				}
				sort(ts+1,ts+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(ts[i].x>=0){
						ans-=ts[i].x;
						gs[2]--;
						gs[ts[i].xb]++;
					}
					if(gs[2]<=could){
						break;
					}
				}
			}
			if(gs[3]>could){
				C ts[N];
				for(int i=1;i<=n;i++){
					if(m[i]==3){
						if(a[i][3]-a[i][2]==a[i][3]-a[i][1]){
							ts[i].x=a[i][3]-a[i][2];
							if(gs[1]<gs[2]){
								ts[i].xb=1;
							}else{
								ts[i].xb=2;
							}
						}else if(a[i][3]-a[i][2]<a[i][3]-a[i][1]){
							ts[i].x=a[i][3]-a[i][2];
							ts[i].xb=1;
						}else{
							ts[i].x=a[i][3]-a[i][1];
							ts[i].xb=2;
						}
					}else{
						ts[i].x=-1;
					}
				}
				sort(ts+1,ts+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(ts[i].x>=0){
						ans-=ts[i].x;
						gs[3]--;
						gs[ts[i].xb]++;
					}
					if(gs[3]<=could){
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}