#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,n,a[N][3],ans;
struct node{
	int x,y,z;
	operator <(const node t)const{
		if(x!=t.x)
			return x<t.x;
		return y>t.y;
	}
};
priority_queue<node>q1,q2,q3;
void solve(int x){
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3]){//选择1 
		if(q1.size()==(int)(n/2)){//1满了 
			int t=q1.top().z;
			if(max(a[t][2],a[t][3])+a[x][1]>max(a[x][2],a[x][3])+a[t][1]){
				if(a[t][2]>a[t][3]){
					q2.push({max(a[t][1],a[t][3])-a[t][2],a[t][2],t});
				}else{
					q3.push({max(a[t][1],a[t][2])-a[t][3],a[t][3],t});
				}
				q1.pop();
				q1.push({max(a[x][2],a[x][3])-a[x][1],a[x][1],x});
			}else{
				if(a[x][2]>a[x][3]){
					q2.push({max(a[x][1],a[x][3])-a[x][2],a[x][2],x});
				}else{
					q3.push({max(a[x][1],a[x][2])-a[x][3],a[x][3],x});
				}
			}
		}else{
			q1.push({max(a[x][2],a[x][3])-a[x][1],a[x][1],x});
		}
	}else if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3]){
		if(q2.size()==(int)(n/2)){//1满了 
			int t=q2.top().z;
			if(max(a[t][1],a[t][3])+a[x][2]>max(a[x][1],a[x][3])+a[t][2]){
				if(a[t][1]>a[t][3]){
					q1.push({max(a[t][2],a[t][3])-a[t][1],a[t][1],t});
				}else{
					q3.push({max(a[t][3],a[t][2])-a[t][3],a[t][3],t});
				}
				q2.pop();
				q2.push({max(a[x][1],a[x][3])-a[x][2],a[x][2],x});
			}else{
				if(a[x][1]>a[x][3]){
					q1.push({max(a[x][2],a[x][3])-a[x][1],a[x][1],x});
				}else{
					q3.push({max(a[x][1],a[x][2])-a[x][3],a[x][3],x});
				}
			}
		}else{
			q2.push({max(a[x][1],a[x][3])-a[x][2],a[x][2],x});
		}
	}else{
		if(q3.size()==(int)(n/2)){//1满了 
			int t=q3.top().z;
			if(max(a[t][2],a[t][1])+a[x][3]>max(a[x][2],a[x][1])+a[t][3]){
				if(a[t][1]>a[t][2]){
					q1.push({max(a[t][2],a[t][3])-a[t][1],a[t][1],t});
				}else{
					q2.push({max(a[t][1],a[t][4])-a[t][2],a[t][2],t});
				}
				q3.pop();
				q3.push({max(a[x][2],a[x][1])-a[x][3],a[x][3],x});
			}else{
				if(a[x][1]>a[x][2]){
					q1.push({max(a[x][2],a[x][3])-a[x][1],a[x][1],x});
				}else{
					q2.push({max(a[x][1],a[x][3])-a[x][2],a[x][2],x});
				}
			}
		}else{
			q3.push({max(a[x][2],a[x][1])-a[x][3],a[x][3],x});
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			solve(i);
		}
		ans=0; 
		while(q1.size()){
			ans+=a[q1.top().z][1]; 
			q1.pop();
		}
		while(q2.size()){
			ans+=a[q2.top().z][2]; 
			q2.pop();
		}
		while(q3.size()){
			ans+=a[q3.top().z][3]; 
			q3.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*3

4
 
4 2 1
 
3 2 4
 
5 3 4
 
3 5 1
 
4
 
0 1 0
 
0 1 0
 
0 2 0
 
0 2 0
 
2
 
10 9 8
 
4 0 0
 */
