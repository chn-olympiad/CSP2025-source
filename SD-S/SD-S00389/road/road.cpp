#include<bits/stdc++.h>

#define ll long long

using namespace std;
/*

//非常像dp
//[i]//第几个
//[j]//占几个位置最大
//[k]//被分到机组
//dp[i][j][k]
//遍历一遍其他组中
//
//先等等
//孤立地看问题
//就是背包
//
//限制：
//同一个数只能取一次
//那就分别算这个数

三个优先队列



*/

int n;
int m;
int k;
int h[11000];
int nex[2100000];
int to[2100000];
int fro[2100000];
int num[2100000];
int idx;


ll ans=0;

struct fu{
	
	ll num;
	int idx;
	
	bool operator <(const fu &a)const{
	
		return a.num<num;
	
	}
	
};

priority_queue<fu> q;
void add(int x,int y,int z){
	
	nex[++idx]=h[x];
	h[x]=idx;
	to[idx]=y;
	fro[idx]=x;
	num[idx]=z;
	q.push({z,idx});
	
}

int b[110000];

int find(int x){
	
	if(b[x]==x)return x;
	return find(b[x]);
	
}

int mer(int x,int y){
	
	x=find(x);
	y=find(y);
	if(x==y)return 0;
	
	b[x]=y;
	
	return 1;
	
}

int main() {

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	
	if(k>0)cout<<0;
	else {
		for(int i=1;i<=n;i++)b[i]=i;
		for(int i=1;i<=m;i++){
			
			ll x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			
		}
		
		while(!q.empty()){
			
			fu w=q.top();
			q.pop();
			
			int k=mer(fro[w.idx],to[w.idx]);
			if(k)ans+=w.num;
			
		}
		
		cout<<ans;
		
	}
	
	
	return 0;
}
