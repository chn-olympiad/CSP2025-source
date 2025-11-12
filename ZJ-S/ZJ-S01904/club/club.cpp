#include<bits/stdc++.h>
using namespace std;
int d[200005][3];
struct P{
	int id;
	int m;
	int dm;
}d1[200005],d2[200005],d3[200005];
int p1[200005],p2[200005];
int dl1=0,dl2=0,dl3=0;
bool cmp(P x,P y){
	if(x.dm>y.dm)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		dl1=dl2=dl3=0;
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
		memset(d,0,sizeof(d));
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>d[i][0]>>d[i][1]>>d[i][2];
			if(d[i][0]>=d[i][1]&&d[i][0]>=d[i][2]){
				p1[i]=0;
				if(d[i][1]>d[i][2]){
					p2[i]=1;
				}else{
					p2[i]=2;
				}
				d1[dl1].id=i;
				d1[dl1].dm=d[i][p1[i]]-d[i][p2[i]];
				d1[dl1++].m=d[i][0];
			}else if(d[i][1]>=d[i][0]&&d[i][1]>=d[i][2]){
				p1[i]=1;
				if(d[i][0]>d[i][2]){
					p2[i]=0;
				}else{
					p2[i]=2;
				}
				d2[dl2].id=i;
				d2[dl2].dm=d[i][p1[i]]-d[i][p2[i]];
				d2[dl2++].m=d[i][1];
			}else{
				p1[i]=2;
				if(d[i][0]>d[i][1]){
					p2[i]=0;
				}else{
					p2[i]=1;
				}
				d3[dl3].id=i;
				d3[dl3].dm=d[i][p1[i]]-d[i][p2[i]];
				d3[dl3++].m=d[i][2];
			}
		}
		if(dl1>n/2){
			sort(d1,d1+dl1,cmp);
			for(int i=n/2;i<dl1;i++){
				if(p2[d1[i].id]==1){
					d2[dl2].id=d1[i].id;
					d2[dl2++].m=d[d1[i].id][1];
				}else{
					d3[dl3].id=d1[i].id;
					d3[dl3++].m=d[d1[i].id][2];
				}
				d1[i].id=0;
				d1[i].m=0;
			}
			dl1=n/2;
		}
		if(dl2>n/2){
			sort(d2,d2+dl2,cmp);
			for(int i=n/2;i<dl2;i++){
				if(p2[d2[i].id]==0){
					d1[dl1].id=d2[i].id;
					d1[dl1++].m=d[d2[i].id][0];
				}else{
					d3[dl3].id=d2[i].id;
					d3[dl3++].m=d[d2[i].id][2];
				}
				d2[i].id=0;
				d2[i].m=0;
			}
			dl2=n/2;
		}
		if(dl3>n/2){
			sort(d3,d3+dl3,cmp);
			for(int i=n/2;i<dl3;i++){
				if(p2[d3[i].id]==0){
					d1[dl1].id=d3[i].id;
					d1[dl1++].m=d[d3[i].id][0];
				}else{
					d2[dl2].id=d3[i].id;
					d2[dl2++].m=d[d3[i].id][1];
				}
				d3[i].id=0;
				d3[i].m=0;
			}
			dl3=n/2;
		}
		int ans=0;
		for(int i=0;i<dl1;i++){
			ans+=d1[i].m;
		}
		for(int i=0;i<dl2;i++){
			ans+=d2[i].m;
		}
		for(int i=0;i<dl3;i++){
			ans+=d3[i].m;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
