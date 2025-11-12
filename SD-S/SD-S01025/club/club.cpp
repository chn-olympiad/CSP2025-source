#include<bits/stdc++.h>
using namespace std;
long long tt,she[10];
struct node{
	long long a,b,c;
}r[100005];
struct node2{
	long long wei,x,to;
};
bool cmp(node a,node b){
	long long aa = max(a.a,max(a.b,a.c));
	long long bb = max(b.a,max(b.b,b.c));
	return aa > bb;
}
priority_queue<node2> q[5];
bool operator<(node2 a,node2 b){
	return a.x > b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> tt;
	while(tt--){
		
		long long n,ans = 0,ar,br,cr;
		cin >> n;
		she[1] = 0,she[2] = 0,she[3] = 0;
		for(long long i = 1;i <= n;i++){
			long long wala1,wala2,wala3;
			cin >> wala1 >> wala2 >> wala3;
			r[i].a = wala1;
			r[i].b = wala2;
			r[i].c = wala3;
		}
		sort(r+1,r+n+1,cmp);
		long long lt = n/2;
		for(long long i = 1;i <= n;i++){
			long long ma = r[i].a,mb = r[i].b,mc = r[i].c;
			if(ma >= mb && ma >= mc){
				if(she[1] == lt){
					if(ma-q[1].top().x > mb && ma-q[1].top().x > mc){
						node2 g = q[1].top();
						she[g.to]++;
						ans += ma;
						ans -= g.x;
						q[1].pop();
						q[1].push((node2){i,ma-mb,2});
						q[1].push((node2){i,ma-mc,3});
						if(g.to == 2){
							she[2]++;
							q[2].push((node2){g.wei,r[g.wei].b - r[g.wei].c,3});
						}
						else{
							she[3]++;
							q[3].push((node2){g.wei,r[g.wei].c - r[g.wei].b,2});
						}
					}
					else{
						if(mb >= mc){
							she[2]++;
							q[2].push((node2){i,mb-mc,3});
							ans += mb;
						}
						else{
							she[3]++;
							q[3].push((node2){i,mc-mb,2});
							ans += mc;
						}
					}
				}
				else{
					she[1]++;
					q[1].push((node2){i,ma-mb,2});
					q[1].push((node2){i,ma-mc,3});
					ans += ma;	
				}
			}
			else if(mb >= mc && mb >= ma){
				if(she[2] == lt){
					if(mb-q[2].top().x > ma && mb-q[2].top().x > mc){
						node2 g = q[2].top();
						she[g.to]++;
						ans += mb;
						ans -= g.x;
						q[2].pop();
						q[2].push((node2){i,mb-ma,1});
						q[2].push((node2){i,mb-mc,3});
						if(g.to == 1){
							she[1]++;
							q[1].push((node2){g.wei,r[g.wei].a - r[g.wei].c,3});
						}
						else{
							she[3]++;
							q[3].push((node2){g.wei,r[g.wei].c - r[g.wei].a,1});
						}
					}
					else{
						if(ma >= mc){
							she[1]++;
							q[1].push((node2){i,ma-mc,3});
							ans += ma;	
						}
						else{
							she[3]++;
							q[3].push((node2){i,mc-ma,1});
							ans += mc;
						}
					}
				}
				else{
					she[2]++;
					q[2].push((node2){i,mb-ma,1});
					q[2].push((node2){i,mb-mc,3});
					ans += mb;
				}
				
			}
			else{
				if(she[3] == lt){
					if(mc-q[3].top().x > ma && mc-q[3].top().x > mb){
						node2 g = q[3].top();
						she[g.to]++;
						ans += mc;
						ans -= g.x;
						q[3].pop();
						q[3].push((node2){i,mc-ma,1});
						q[3].push((node2){i,mc-mb,2});
						if(g.to == 1){
							she[1]++;
							q[1].push((node2){g.wei,r[g.wei].a - r[g.wei].b,2});
						}
						else{
							she[2]++;
							q[2].push((node2){g.wei,r[g.wei].b - r[g.wei].a,1});
						}
					}
					else{
						if(mb >= ma){
							she[2]++;
							q[2].push((node2){i,mb-ma,1});
							ans += mb;
						}
						else{
							she[1]++;
							q[1].push((node2){i,ma-mb,2});
							ans += ma;	
						}
					}
				}
				else{
					she[3]++;
					q[3].push((node2){i,mc-ma,1});
					q[3].push((node2){i,mc-mb,2});
					ans += mc;
				}
				
			}
		}
		cout << ans << endl;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
	}
	return 0;
}

