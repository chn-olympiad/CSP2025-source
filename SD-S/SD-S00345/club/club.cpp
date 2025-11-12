/*
弄不死就往死里弄！
不要放弃任何一点分！
先写暴力！发掘特殊性质！
读题读题读题！
int <-> long long 数组大小！ MLE?RE? OK
图论？DP？ 
优化一下？ 
*/

#include <bits/stdc++.h>

#define int long long

#define PII pair<int,int>

#define mkp make_pair

using namespace std;

const int N=1e5+10;

int n;
vector<PII> a[N];//每个a[i]存储三个PII，记得重新定义排序！记得记录编号 OK
priority_queue<PII,vector<PII>,greater<PII> > q[4],empt;//每个PII存储差值和编号，指的是哪个人
int res;//当前的答案 
int point_pla[N];//代表取到了哪里 

void init() {
	q[1]=q[2]=q[3]=empt;
	for(int i=1;i<=n;++i) {
		a[i].clear();
	}
	for(int i=1;i<=n;++i) {
		point_pla[i]=0;
	}
	res=0;
	n=0;
} 

void readin() {
	cin>>n;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=3;++j) {
			PII rd;
			cin>>rd.first;
			rd.second=j;
			a[i].push_back(rd);
		}
	}
}

bool cmp(const PII& pr1,const PII& pr2) {
	if(pr1.first==pr2.first) {
		return pr1.second<pr2.second;
	}
	return pr1.first>pr2.first;//从大到小排序 
}

bool check() {
	if(max(q[1].size(),max(q[2].size(),q[3].size()))<=n/2) return true;
	return false;
}

void preprocess() {
	//预处理，排序，放进最初的堆
	for(int i=1;i<=n;++i) {
		sort(a[i].begin(),a[i].end(),cmp);
		res+=a[i][0].first;//统计微调之前的答案
//		cout<<i<<":\n"; 
//		for(int j=0;j<3;++j) {
//			cout<<a[i][j].first<<" "<<a[i][j].second<<"\n";
//		}
//		cout<<"---------------\n";
	} 
	for(int i=1;i<=n;++i) {
		q[a[i][0].second].push(mkp(a[i][0].first-a[i][1].first,i));//定义差值，放进去 
	}
//	cerr<<"original res:\n"<<res<<"\n";
	while(!check()) {
		for(int i=1;i<=3;++i) {
			//检查每个堆
			if(q[i].size()<=n/2) continue;
//			cerr<<"Here!"<<" "<<i<<"\n";
			//肯定不合法的堆
			while(q[i].size()>n/2) {
				PII p=q[i].top();
				q[i].pop();
//				cerr<<"remove:"<<p.second<<"\n";
				point_pla[p.second]++;
				res-=p.first;//删除原来的贡献 
				//统计差值，放到下一个里面
				point_pla[p.second]++;//放到下一个点上 
				int ord=a[p.second][point_pla[p.second]].second;//统计下一个放到哪里
				int new_diff=a[p.second][point_pla[p.second]].first-
				a[p.second][point_pla[p.second]+1].first;//统计新的差值 
				if(point_pla[p.second]==2) new_diff=1e9;
				else new_diff=new_diff; 
				q[ord].push(mkp(new_diff,p.second)); 
			}

		}
	}
}

void output() {
	cout<<res<<"\n"; 
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		init();
		readin();
		preprocess();
		output();	
	}

	return 0;
} 
