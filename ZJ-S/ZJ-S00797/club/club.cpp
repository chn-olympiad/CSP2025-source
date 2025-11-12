#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int t,n,res;
int m[5];
struct data{
	int pos[5];
	int sel;
	int lst;
}a[N];
bool cmpx(data q1,data q2){return  q1.pos[1]<q2.pos[1];}
bool cmpy(data q1,data q2){return  q1.pos[2]<q2.pos[2];}
bool cmpz(data q1,data q2){return  q1.pos[3]<q2.pos[3];}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qx,qy,qz;
int gt(int u){
	int tot=0;
	if(u==1)sort(a+1,a+n+1,cmpx);
	if(u==2)sort(a+1,a+n+1,cmpy);
	if(u==3)sort(a+1,a+n+1,cmpz);
	for(int i=1;i<=n;i++){
		if(u==1){
			if(qx.size()<n/2){
				if(a[i].pos[a[i].sel]<a[i].pos[u]){
					res-=a[i].pos[a[i].sel];
					qx.push(make_pair(i,a[i].pos[u]));
					a[i].sel=u;
				}
			}
			if(qx.size()==n/2){
				tot=qx.top().second;
				if(a[i].pos[a[i].sel]+tot<a[i].pos[u]+a[qx.top().first].lst){
					res-=a[i].pos[a[i].sel];
					a[qx.top().first].sel=0;
					a[qx.top().first].lst=tot;
					qx.pop();
					qx.push(make_pair(i,a[i].pos[u]));
						a[i].sel=u;
				}
			}
		}
		if(u==2){
			if(qy.size()<n/2){
				if(a[i].pos[a[i].sel]<a[i].pos[u]){
					res-=a[i].pos[a[i].sel];
					qy.push(make_pair(i,a[i].pos[u]));
					a[i].sel=u;
				}
			}
			if(qy.size()==n/2){
				tot=qy.top().second;
				if(a[i].pos[a[i].sel]+tot<a[i].pos[u]+a[qy.top().first].lst){
					res-=a[i].pos[a[i].sel];
					a[qy.top().first].sel=0;
					a[qy.top().first].lst=tot;
					qy.pop();
					qy.push(make_pair(i,a[i].pos[u]));
						a[i].sel=u;
				}
			}
		}
		if(u==3){
			if(qz.size()<n/2){
				if(a[i].pos[a[i].sel]<a[i].pos[u]){
					res-=a[i].pos[a[i].sel];
					qz.push(make_pair(i,a[i].pos[u]));
					a[i].sel=u;
				}
			}
			if(qz.size()==n/2){
				tot=qz.top().second;
				if(a[i].pos[a[i].sel]+tot<a[i].pos[u]+a[qz.top().first].lst){
					res-=a[i].pos[a[i].sel];
					a[qz.top().first].sel=0;
					a[qz.top().first].lst=tot;
					qz.pop();
					qz.push(make_pair(i,a[i].pos[u]));
						a[i].sel=u;
				}
			}
		}
	}
}
void init();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].pos[1]>>a[i].pos[2]>>a[i].pos[3];
			a[i].sel=0;
			m[1]+=a[i].pos[1];m[2]+=a[i].pos[2];m[3]+=a[i].pos[3];
			a[i].pos[0]=0;
		}
		if(m[1]<m[2]){
			if(m[1]<m[3]){gt(1);if(m[2]<m[3]){gt(2);gt(3);}else{gt(3);gt(2);}}else{gt(3);gt(1);gt(2);}
		}else{
			if(m[1]<m[3]){gt(2);gt(1);gt(3);}else{if(m[2]<m[3]){gt(2);gt(3);}else{gt(3);gt(2);}gt(1);}
		}
//		gt(1);gt(2);gt(3);gt(1);gt(2);gt(3);
		while(!qx.empty()){res+=qx.top().second;qx.pop();}
		while(!qy.empty()){res+=qy.top().second;qy.pop();}
		while(!qz.empty()){res+=qz.top().second;qz.pop();}
		cout<<res<<'\n';
	}
	return 0;
}
void init(){
	res=0;
	m[1]=0,m[2]=0,m[3]=0;
}
/*
dp[i][x][y][z]=max(dp[i-1][x-1][y][z]+a[i].pos[2],max(dp[i-1][x][y-1][z]+a[i].y,dp[i-1][x][y][z-1]+a[i].z)); 

1
2
10 9 8
4 0 0

*/
