#include<bits/stdc++.h>
#define Spa putchar(' ')
#define Nxt puts("")
#define raed read
namespace FastIO{
	inline int read(int &x){
		x=0;
		char c=getchar();
		bool f=0;
		while(!isdigit(c)){
			if(c=='-')f=1;
			c=getchar();
		}
		while(isdigit(c)){
			x=(x<<3)+(x<<1)+(c-'0');
			c=getchar();
		}
		return x;
	}
	inline void write(int x){
		int top=0;
		int st[25];
		do{
			st[++top]=x%10;
			x/=10;
		}while(x);
		while(top)putchar(st[top--]+'0');
		return ;
	}
	void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=1e5+5;
int n;
int a[N][3];
namespace Subtask1{
int ans;
void dfs(int p,int cnt1,int cnt2,int cnt3,int now){
	if(p==n+1){
		tomax(ans,now);
		return ;
	}
	if(cnt1!=n/2)
		dfs(p+1,cnt1+1,cnt2,cnt3,now+a[p][0]);
	if(cnt2!=n/2)
		dfs(p+1,cnt1,cnt2+1,cnt3,now+a[p][1]);
	if(cnt3!=n/2)
		dfs(p+1,cnt1,cnt2,cnt3+1,now+a[p][2]);
}
void solve(){
	ans=0;
	dfs(1,0,0,0,0);
	write(ans),Nxt;
}
}
namespace Subtask2{
int ans;
int cnt[3];
bool vis[N];
struct Node{
	int idx,pri;
	Node(int _idx=0,int _pri=0){
		idx=_idx,pri=_pri;
	}
	bool operator >(const Node &T)const{
		return pri>T.pri;
	}
	bool operator <(const Node &T)const{
		return pri<T.pri;
	} 
}b[N][3];
priority_queue<Node>q[3];
//考虑反悔贪心
//我们向一个堆中加入后,如果 > n/2 那么其余两个堆一定 < n/2 
//会发现第三大的根本就没有用  
//因为加入次大值,说明了最大值对应的哪个堆的 = n/2
//那么另外一个堆一定可以放下  
//也不会存在 
void solve(){
	for(int i=1;i<=n;i++){
		b[i][0]=Node(0,a[i][0]);
		b[i][1]=Node(1,a[i][1]);
		b[i][2]=Node(2,a[i][2]);
		sort(b[i],b[i]+3,greater<Node>());
	}
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	int ans=0,mx=n/2;
	for(int i=1,idx;i<=n;i++){
		//尝试加入第 i 个,从最大的开始加 
		idx=b[i][0].idx;
		q[idx].push(Node(i,a[i][b[i][1].idx]-a[i][idx]));
		ans+=a[i][idx];
		if(q[idx].size()>mx){
			Node tmp=q[idx].top();
			q[idx].pop();
//			write(i),Spa,write(tmp.idx),Nxt;
			ans+=tmp.pri;
			q[b[tmp.idx][1].idx].push(Node(tmp.idx,-0x3f3f3f3f));
		}
	}
	write(ans),Nxt;
}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i][0]),read(a[i][1]),read(a[i][2]);
//		Subtask1::solve();
		Subtask2::solve();
	}
}
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
18961+16178+19722+17976+16615+9953
10557+15344
8769
*/
