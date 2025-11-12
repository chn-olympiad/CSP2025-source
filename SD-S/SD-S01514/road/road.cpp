#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+500;
#define int long long
int n,m,k;
struct node{
	int to,w;
	int mid;
	node(int to,int w):to(to),w(w),mid(0){
	}
};
vector<node>edge[Maxn];
int c[Maxn];
int c1[11][10001];
bool flag[12];
class cmp{
	public:
		bool operator()(node&x,node &y){
			return x.w>y.w;
		}
};
signed main () {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		edge[x].push_back(node(y,w));
		edge[y].push_back(node(x,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c1[i][j];
			
		}
	}
	priority_queue<node,vector<node>,cmp>q;

	vector<bool>vis(n+1,false);
	q.push(node(4,0));
	int result=0;
	while(q.empty()==0){
		
		int from=q.top().to;
		int mid=q.top().mid;
		//cout<<mid<<"\n";
		int ww=q.top().w;
		q.pop();
		if(vis[from]){
			continue;
		}
		vis[from]=1;
		result+=ww;
		if(mid!=0){
			flag[mid]=true;
		}
		for(auto I:edge[from]){
			int to=I.to;
			int w=I.w;
			int w2=1e9;
			int idx;
			for(int i=1;i<=k;i++){
				if(flag[i]==true){
					if(w2>=c1[i][from]+c1[i][to]){
						idx=i;
						w2=c1[i][from]+c1[i][to];
					}
				}else{
					if(w2>=c1[i][from]+c1[i][to]+c[i]){
						idx=i;
						w2=c1[i][from]+c1[i][to]+c[i];
					}
				}
			}
			if(w2>=w){
				//cout<<idx<<" --\n";
				node temp(to,w2);
				temp.mid=idx;
				q.push(temp);
			}else{
				q.push(node(to,w));
			}
		}
	}
	cout<<result;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/


