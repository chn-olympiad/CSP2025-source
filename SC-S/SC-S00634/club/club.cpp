#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1e5+5;
const int maxval = 2e4+5;
int n,a[maxn][5],t,limit;
int cnt[5];
long long ans;
struct node{
	int val,id;
	bool operator > (const node& b) const {return val < b.val;}
};//不存在一个部门有超过n/2个成员=>2个部门便可装完所有人 
priority_queue<node,vector<node>,greater<node> > q[5];

inline work(int i){
	int id=0,MAX=-1;
	for(int j=1;j<=3;j++){
		if(a[i][j]>MAX){
			id=j;
			MAX=a[i][j];
		}
	}
	ans+=a[i][id]; cnt[id]++;
	MAX=-1;int idex=0;
	for(int j=1;j<=3;j++){//找到剩下两个中大的一个 
		if(j==id) continue;
		if(MAX<a[i][j]){
			MAX=a[i][j];
			idex=j;
		}
	}
	MAX-=a[i][id];
	q[id].push({MAX,idex}); 
}
/*
先找到其中最大的那个，将其如堆，记录ans
并将其另外两个满意度-=这个最大值
当丢弃此值时可以直接加上另外两值中的较大者 
*/

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		limit=n/2; ans=0;
		for(int i=1;i<=3;i++){
			while(!q[i].empty()) q[i].pop();
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			work(i);
		}
		for(int i=1;i<=3;i++){
			while(cnt[i]>limit){
				node temp=q[i].top(); 
				ans+=temp.val;
				cnt[temp.id]++;
				q[i].pop();
				cnt[i]--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
15:12 贪心显然不行，考虑dp 
15:16 dp是N^2的,应该不行 
15:50 过全部样例了，求求评测姬大发慈悲给过吧 

Ren5Jie4Di4Ling5%

3
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