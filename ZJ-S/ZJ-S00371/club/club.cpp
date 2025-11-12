#include <bits/stdc++.h>
using namespace std;
//~ #define calc_time
namespace zyc{
	#define pb push_back
	#define rep(i,l,r) for(int i=l;i<=r;i++)
	#define per(i,r,l) for(int i=r;i>=l;i--)
	const int N=1e5+10;
	int n,a[5],sum,id[5];
	bool cmp(int x,int y){return a[x]>a[y];}
	vector<int>g[5];
	void run(){
		sum=0;
		rep(i,1,3)g[i].clear();
		cin>>n;
		rep(i,1,n){
			rep(j,1,3)cin>>a[j],id[j]=j;
			sort(id+1,id+4,cmp);
			sum+=a[id[1]];
			g[id[1]].pb(a[id[1]]-a[id[2]]);
		}
		if((int)g[2].size()>n/2)swap(g[1],g[2]);
		if((int)g[3].size()>n/2)swap(g[1],g[3]);
		if((int)g[1].size()>n/2){
			sort(g[1].begin(),g[1].end());
			n=g[1].size()-n/2;
			per(i,n-1,0)sum-=g[1][i];
		}
		cout<<sum<<'\n';
	}
	int main(){
		#ifdef calc_time
		auto S=clock();
		#endif
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		int T;cin>>T;
		while(T--)run();
		#ifdef calc_time
		auto E=clock();
		double D=double(E-S)/CLOCKS_PER_SEC*1000;
		cerr<<D<<" ms\n";
		#endif
		return 0;
	}
}
int main(){return zyc::main();}
//Ren5Jie4Di4Ling5%
//先把所有人分到最满意的部门
//然后对于“多于 n/2” 人的部门
//我们要找到最小的满意度差的前(多处的人的个数)个人 分到另一部门

//先从没有正确性的可能方案开始
//找到和第二志愿差最小的人，全部移动到第二志愿，这时如果还不符合条件，对那个组再这样操作

//看看特殊性质
//AB 都好做
//思考一个问题：先按照最大满意度分配完后，一定不可能出现两个组间交换成员的情况
//一旦交换，那么不仅人数调整没有贡献，总满意度必然不增
//这是一个很妙的发现

//好吧其实我唐了
//一旦有一个组人数过半，把多出来的人分到别的组，别的组人数一定不会过半
//唉我反应真慢
