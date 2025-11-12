//1s 512MB
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int a[N][5];
vector<int> tot[5];
void solve(){
	int n,m;cin >> n;m=3;
	int lim=n/2;//每个部门最多可以得到多少员工
	for (int i=1;i<=m;++i) tot[i].clear();
	int ans=0;
	for (int i=1,mxid;i<=n;++i){
		mxid=0;
		for (int j=1;j<=m;++j)
			cin >> a[i][j],mxid=(a[i][j]>=a[i][mxid]?j:mxid);
		tot[mxid].emplace_back(i);ans+=a[i][mxid];
	}
	int id=-1;
	for (int i=1;i<=m;++i){
		if (tot[i].size()>lim) id=i;
	}
	if (id==-1){
		cout<<ans<<"\n";
		return;
	}
	int k=tot[id].size()-lim;//需要删去多少个人
	vector<int> dx;
	int id1,id2;
	if (id==1) id1=2,id2=3;
	if (id==2) id1=1,id2=3;
	if (id==3) id1=1,id2=2;
	for (int &v:tot[id]){
		dx.emplace_back(max(a[v][id1],a[v][id2])-a[v][id]);
	}
	sort(dx.begin(),dx.end(),greater<int>());
	for (int i=0;i<k;++i)
		ans+=dx[i];
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;cin >> T;
	for (int i=0;i<T;++i) solve();
	cout.flush();
	return 0;
}
//天地萧萧浊浪河滔滔，功过谁道
/*
我是xiaoyang111(890311)和xiaoyang222(1220111)
反悔贪心？那n/2的限制怎么做？
首先对于每个部门，排序
注意到这个数是个非负整数
先考虑没有人数限制怎么做（不对啊直接每个人选自己最喜欢的）
选进去就不能踢出来了（真的吗？错误的吧）
先选出最优的方案，然后再从最大的那个地方丢出来
由于是n/2，所以最多只有一个会重新分配
致庸官那一个部门就可以了
最终这个部门留下n/2
剩下的意味着可以随便丢
怎么这一套题是打工/当官系列的？？？（好神秘的风格）
*/