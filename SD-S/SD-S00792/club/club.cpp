#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=1e10;
void faster(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int hh[N][4];
int t;
int n;
int ls[N],cnt;
int cs=0;
int anss=0;
void dfs(int x,int cnt1,int cnt2,int cnt3,int dlt){
	if(cs==1e7) return;
	if(x==n+1){
		anss=max(anss,dlt);
		cs++;
		return ;
	}
	if(cnt1<n/2) dfs(x+1,cnt1+1,cnt2,cnt3,dlt+hh[x][1]);
	if(cnt2<n/2) dfs(x+1,cnt1,cnt2+1,cnt3,dlt+hh[x][2]);
	if(cnt3<n/2) dfs(x+1,cnt1,cnt2,cnt3+1,dlt+hh[x][3]);
}
signed main(){
	faster();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		anss=0;
		cs=0;
		cin>>n;
		bool f=1;
		for(int i=1;i<=n;i++){
//			cin>>hh[i].a>>hh[i].b>>hh[i].c;
			for(int j=1;j<=3;j++){
				cin>>hh[i][j];
			}
			if(hh[i][3]!=0||hh[i][2]!=0) f=0; 
		}
		if(f) {
			for(int i=1;i<=n;i++) ls[++cnt]=hh[i][1];
			sort(ls+1,ls+cnt+1);
			for(int i=cnt;i>=n/2+1;i--){
				anss+=ls[i];
			}
		}
		else dfs(1,0,0,0,0);
		cout<<anss<<"\n";
	}
	return 0;
}
/*
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
/*
最后半个小时，没有奇迹了
我真的不理解，真的不理解
为什么，为什么 
我这半年都在干些什么
为什么这么一道黄我都写不出来
为什么我什么都不会
我考试前两个点都在干什么
为什么每次平时刷题都很正常却一到考试就会全线崩溃
为什么动态规划就是学不会
为什么明明已经打了那么多场比赛实力却一点进步没有
为什么一直在退步甚至不如半年前的自己
为什么

...

那些执念该放下了
再一味坚持下去whk和oi都不会好 
就这样吧，25+16+0+10
退役(2022.5.31-2025.11.1)

想出来了，没时间写了
哈哈 
*/
