#include<bits/stdc++.h>
using namespace std;
mt19937 mrand(1);
const int N = 201000;
int n,m,t;
int a[N][3];
array<int,2>ma[N][3];
priority_queue<array<int,3>> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i = 1;i <= n;i++){
    		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    		ma[i][0] = {a[i][0],0};
    		ma[i][1] = {a[i][1],1};
			ma[i][2] = {a[i][2],2};
			sort(ma[i],ma[i]+3);
			swap(ma[i][0],ma[i][2]);
		}for(int i = 1;i <= n;i++){
			if(q[ma[i][0][1]].size() < n/2){
				q[ma[i][0][1]].push({-ma[i][0][0]+ma[i][1][0],ma[i][0][0],i});
				
			}else{
				array<int,3> x = q[ma[i][0][1]].top();
				
				if(-x[0] < ma[i][0][0]-ma[i][1][0]){
					q[ma[i][0][1]].pop();
					q[ma[i][0][1]].push({-ma[i][0][0]+ma[i][1][0],ma[i][0][0],i});
					q[ma[x[2]][1][1]].push({x[0],ma[x[2]][1][0],x[2]});
				}else{
					q[ma[i][1][1]].push({-ma[i][0][0]+ma[i][1][0],ma[i][1][0],i});
				}
			}
		}int ans = 0;
		for(int i = 0;i <= 2;i++){
			while(!q[i].empty()){
				ans += q[i].top()[1];
				
				q[i].pop();
			}
		}printf("%d",ans);
		if(t){
			puts("");
		}
	}
    return 0;
}
