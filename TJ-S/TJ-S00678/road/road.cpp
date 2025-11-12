//T2
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1e4;
const int MAXM = 1e6;
const int MAXK = 10;
int n,m,k,ans = 0;

struct road{
	int u,v,w;
};

struct uroad{
	int v,w;
};

struct uw{
	int u,w,v;//u的最小权和这个最小权指向的v
};

struct uv{
	int u,v;//u,v对
};

road r[MAXM];

struct town{
	int c,a[MAXN];
};

town t[MAXK];

bool comp_ur(uroad l,uroad r){
	return l.w <= r.w;
}

bool comp_uw(uw l,uw r){
	return l.w <= r.w;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		r[i] = {u-1,v-1,w};
	}
	for(int i=0;i<k;i++){
		cin >> t[i].c;
		for(int j=0;j<n;j++){
			cin >> t[i].a[j];
		}
	}
	if(!k){//情况1(4/25 * 100=16score) 先选代价最小的建第一条边,然后遍历set内的选择能与外界点连同的最小代价
		//需要将每个点对于其他点的建边代价升序排序
		vector<uroad> rwa[MAXN];//rwq[i]的元素是vector<uroad>
		vector<uw> rwauw;

		for(int i=0;i<m;i++){//O(m)
			rwa[r[i].u].push_back({r[i].v,r[i].w});
			rwa[r[i].v].push_back({r[i].u,r[i].w});
		}

		//cout << "1" << endl;

		for(int i=0;i<n;i++){//O(n*O(sortn))
            //cout << "1" << endl;
			sort(rwa[i].begin(),rwa[i].end(),comp_ur);
            //cout << "1" << endl;
            //cout << i << endl << rwa[i][0].w << endl << rwa[i][0].v << endl;
            uw l = {i,int(rwa[i][0].w),int(rwa[i][0].v)};
			//cout << "1" << endl;
			rwauw.push_back(l);
		}

		//cout << "1" << endl;
		sort(rwauw.begin(),rwauw.end(),comp_uw);
		unordered_set<int> fn;
		ans += rwauw[0].w;
		fn.insert(rwauw[0].u);fn.insert(rwauw[0].v);
		for(int rwauw_i = 1;rwauw_i<n;rwauw_i++){//最小又不浪费的边肯定要建上
			if(fn.find(rwauw[rwauw_i].u)!=fn.end()&&fn.find(rwauw[rwauw_i].v)==fn.end()){
				ans += rwauw[rwauw_i].w;
				fn.insert(rwauw[rwauw_i].v);
			}
		}
		while(fn.size()!=n){
			rwauw.clear();//第一梯队的没了
			for(int j=1;;j++){
				int cnt_ex = 0;//索引能到j的rwa[i]数量
				for(int i=0;i<n;i++){
					if(rwa[i].size()>j){
						cnt_ex++;
						if(fn.find(i)==fn.end()||fn.find(rwa[i][j].v)==fn.end()){//俩里至少有一个还没通路
							rwauw.push_back({i,rwa[i][j].w,rwa[i][j].v});
						}
					}
				}
				if(!cnt_ex) break;
			}
			sort(rwauw.begin(),rwauw.end(),comp_uw);
			queue<uv> uvq;
			for(int j=0;;j++){
				if(fn.size()==n&&uvq.empty()) break;
				if(fn.find(rwauw[j].u)!=fn.end()&&fn.find(rwauw[j].v)==fn.end()){
					ans += rwauw[j].w;
					fn.insert(rwauw[j].v);
				}else if(fn.find(rwauw[j].u)==fn.end()&&fn.find(rwauw[j].v)!=fn.end()){
					ans += rwauw[j].w;
					fn.insert(rwauw[j].u);
				}else if(fn.find(rwauw[j].u)==fn.end()&&fn.find(rwauw[j].v)==fn.end()){
					ans += rwauw[j].w;
					fn.insert(rwauw[j].v);fn.insert(rwauw[j].u);//需要记录
					uvq.push({rwauw[j].v,rwauw[j].u});
				}else if(fn.find(rwauw[j].u)!=fn.end()&&fn.find(rwauw[j].v)!=fn.end()&&
					((uvq.front().u==rwauw[j].u&&uvq.front().v==rwauw[j].v)||(uvq.front().v==rwauw[j].u&&uvq.front().u==rwauw[j].v))){
					ans += rwauw[j].w;
					fn.insert(rwauw[j].u);
					uvq.pop();
				}
			}
		}
		cout << ans;
		return 0;
	}

	return 0;
}










