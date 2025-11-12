#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N = 1e5 + 10;
int t , n , ans ;
int s[N][5];
int sum[5] , mi[5][3];
vector<PII> g[4];
priority_queue<PII> q[N];

void cc(int x){
		int c;
		PII t = q[x].top();
		q[x].pop();
		int w = t.first ,d = t.second;
		if(sum[d] < n/2){
			ans+=w;
			sum[d]++;
//			cout<<'a'<<ans<<endl;
			g[d].push_back({w ,x });
		}else{
			for(int j = 0 ; j < g[d].size() ; j++){
				PII t1 = g[d][j];
				int mi = 0x3f3f3f3f, c = -1;
				int x1 = t1.first ,y1 = t1.second;
				if(x1 < mi && x1 <= w){
					c = j;
				}
			}
			int d1 = g[d][c].second , w1 = g[d][c].first;
			if(c != -1){
				ans -= w1;
				ans+=w;
				g[d][c]={w , d};
				cc(d1);
			}else{
				cc(d);
			}
		}	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(g , 0 , sizeof(g));
		memset(sum , 0 , sizeof(sum));
		ans=0;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++){
			int a1,a2,a3;
			scanf("%d%d%d",&a1 , &a2 , &a3);
			q[i].push({a1,1});
			q[i].push({a2,2});
			q[i].push({a3,3});
		}
		for(int i = 1 ; i <= n ; i++){
			int c;
			
			PII t = q[i].top();
			q[i].pop();
			int w = t.first ,d = t.second;
			if(sum[d] < n/2){
				ans+=w;
				sum[d]++;
//				cout<<'a'<<ans<<' '<<d<<' '<<sum[d]<<endl;
				g[d].push_back({ w ,i });
			}else{
				int mi = 0x3f3f3f3f , c=-1;
				for(int j = 0 ; j < g[d].size() ; j++){
					PII t1 = g[d][j];
					
					int x1 = t1.first ,y1 = t1.second;
//					cout<<i<<'x'<<x1<<'y'<<y1<<endl;
					if(x1 < mi){
						mi = x1;
						c = j;
					}
				}
				int d1 = g[d][c].second , w1 = g[d][c].first;
			PII t2 = q[d1].top();
			int w2 = t2.first;
				if(w2 + w > w1){
					ans -= w1;
					ans += w;
					g[d][c]={w , i};
					cc(d1);
				}else{
					cc(i);
				}
			}
		}
		printf("%d\n",ans);
		for(int i = 1 ; i <= n ; i++){
			while(!q[i].empty()) q[i].pop();
		}
	}
	return 0;
}