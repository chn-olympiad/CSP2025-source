#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],res;
struct tt{
	int i,x,y;
	tt(int _i=0,int _x=0,int _y=0){
		i=_i,x=_x,y=_y;
	}
};
bool operator<(const tt&x,const tt&y){
	return a[x.i][x.y]-a[x.i][x.x]<a[y.i][y.y]-a[y.i][y.x];
}
priority_queue<tt>q[4];
void Findxy(int i,int&x,int&y){
	int mx=max(a[i][1],max(a[i][2],a[i][3]));
	for(int j=1;j<=3;j++){
		if(a[i][j]==-1)y=j;
		if(a[i][j]==mx)x=j;
	}
	y=6-x-y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][1]<=a[i][2]&&a[i][1]<=a[i][3])a[i][1]=-1;
			if(a[i][2]<a[i][1]&&a[i][2]<=a[i][3])a[i][2]=-1;
			if(a[i][3]<a[i][1]&&a[i][3]<a[i][2])a[i][3]=-1;
		}
		for(int i=1;i<=3;i++){
			while(!q[i].empty())q[i].pop();
		}
		for(int i=1,x,y;i<=n;i++){
			Findxy(i,x,y);
			if(q[x].size()<n/2){
				q[x].push(tt(i,x,y));
			}
			else{
				tt o=q[x].top();
				if(a[o.i][o.y]-a[o.i][o.x]>a[i][y]-a[i][x]){
					q[x].pop();
					q[x].push(tt(i,x,y));
					q[o.y].push(tt(o.i,o.y,o.x));
				}
				else q[y].push(tt(i,y,x));
			}
		}
		res=0;
		for(int k=1;k<=3;k++){
			while(!q[k].empty()){
				tt o=q[k].top();
				res=res+a[o.i][o.x];
				q[k].pop();
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
