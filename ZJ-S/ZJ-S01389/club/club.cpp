#include<bits/stdc++.h>
using namespace std;
int T,n,eq,knumb,knumc,na,nb,nc,Max,Ans,k[100005][4],k2[100005];
struct node{
	int cha,bx,cx;
}bcx[100005];
bool cmp(node x,node y){
	if(x.cha!=y.cha) return x.cha>y.cha;
	else return x.bx>y.bx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		Max=0;na=0;nb=0;nc=0;Ans=0;
		cin>>n;
		memset(k,0,sizeof(k));
		memset(bcx,0,sizeof(bcx));
		for(int i=1;i<=n;i++){
			cin>>k[i][0]>>k[i][1]>>k[i][2];
			if(k[i][0]>k[i][1]&&k[i][0]>k[i][2]) na++;
			if(k[i][1]>k[i][0]&&k[i][1]>k[i][2]) nb++;
			if(k[i][2]>k[i][1]&&k[i][2]>k[i][0]) nc++;
			knumb+=k[i][1];
			knumc+=k[i][2];
		} 
		if(na<=n/2){
			for(int i=1;i<=n;i++)
				if(max(k[i][0],max(k[i][1],k[i][2]))==k[i][0]){
					Ans+=k[i][0];
					k[i][3]=1;
				} 
		}
		if(nb<=n/2){
			for(int i=1;i<=n;i++)
				if(max(k[i][0],max(k[i][1],k[i][2]))==k[i][1]){
					Ans+=k[i][1];
					k[i][3]=1;
				} 
		}
		if(nc<=n/2){
			for(int i=1;i<=n;i++)
				if(max(k[i][0],max(k[i][1],k[i][2]))==k[i][2]){
					Ans+=k[i][2];
					k[i][3]=1;
				} 
		}
		if(na>n/2 || nb>n/2 || nc>n/2){
			for(int i=1;i<=n;i++){
				if(k[i][3]==0){
					bcx[i].bx=max(k[i][0],max(k[i][1],k[i][2]));
					bcx[i].cx=max(k[i][0]+k[i][1],max(k[i][1]+k[i][2],k[i][2]+k[i][0]))-bcx[i].bx;
					bcx[i].cha=bcx[i].bx-bcx[i].cx;
				}
			}
			sort(bcx+1,bcx+n+1,cmp);
			eq=1;
			for(int i=1;i<=n;i++){
				if(eq<=n/2) Ans+=bcx[i].bx;
				else Ans+=bcx[i].cx;
				eq++;
			}
		}
		Max=Ans;
		cout<<Max<<endl;
	}
	return 0;
}
