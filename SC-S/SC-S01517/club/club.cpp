#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N][4],b[N][2],use[N],cnt[4],g[N],T,n,res,X,Y,Z;
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T; while(T--){ res=0;
		cin>>n; for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,g[i]=1,res+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,g[i]=2,res+=a[i][2];
			else cnt[3]++,g[i]=3,res+=a[i][3];
		} X=Y=Z=0;
		if(cnt[1]>n/2) X=1,Y=2,Z=3;
		if(cnt[2]>n/2) X=2,Y=1,Z=3;
		if(cnt[3]>n/2) X=3,Y=1,Z=2;
		if(X==0){cout<<res<<endl;continue;}
		else{
			int r1=cnt[X]-n/2,r2=n/2-cnt[Y],r3=n/2-cnt[Z],t=0;
			for(int i=1;i<=n;i++) if(g[i]==X)
				b[++t][0]=a[i][Y]-a[i][X],b[t][1]=a[i][Z]-a[i][X];
			priority_queue<pair<int,pair<int,int>>> pq;
			memset(use,0,sizeof(use));
			for(int i=1;i<=cnt[X];i++) pq.push({b[i][0],{i,0}}),pq.push({b[i][1],{i,1}});
			while(r1){
				int u=pq.top().first,v=pq.top().second.first,w=pq.top().second.second;
				pq.pop(); if(use[v]) continue;
				if(w==0) r2--,res+=u,use[v]=1,r1--;
				if(w==1) r3--,res+=u,use[v]=1,r1--
					;
			}
		} cout<<res<<endl;
	} return 0;
}