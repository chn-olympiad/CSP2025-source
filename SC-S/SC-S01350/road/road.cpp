#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,k;
struct edge{
	int u,v,w;
}e[1000050],nd[10050];
bool operator<(edge a,edge b){
	return a.w>b.w;
}
priority_queue<edge>q;
int a[11][10050];
int c[11];
int f[10050];
int find(int x){
	if(f[x]!=x)return find(f[x]);
	return f[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	q.push({0,0,1});
//	q.push({0,0,2});
//	cout<<q.top().w<<endl;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w};
		q.push((edge){u,v,w});
	}
	
	for(int i=1;i<=n;i++)f[i]=i;
	int ans=0;
	int cnt=1;
	while(cnt<n){
		edge o=q.top();
		q.pop();
		int fa=find(o.u),fb=find(o.v);
		if(fa!=fb){
		nd[++t]=o;
			ans+=o.w;
			cnt++;
			f[fa]=fb;
			
		}
	}
	
	int A=1;
	for(int p=1;p<=k;p++){
		cin>>c[p];
		int pd=0;
		if(c[p])A=0;
		for(int j=1;j<=n;j++){
			cin>>a[p][j];
			if(!a[p][j])pd=1;
		}
		if(!pd)A=0;
	}
	
	int st=A?((1<<k)-1):0;
	for(int I=st;I<(1<<k);I++){
//		if(I!=1&&I!=4)continue;
//		cerr<<"---"<<I<<endl;
		int res=0;
		for(int i=1;i<=n+k;i++)f[i]=i;
		while(!q.empty())q.pop();
		for(int i=1;i<=t;i++)q.push(nd[i]);
		int wt=n;
		
		for(int i=1;i<=k;i++){
			int t=1<<(i-1);
			if(t&I){
//				cout<<i<<endl;
				wt++;
				res+=c[i];
				for(int j=1;j<=n;j++){
					q.push({n+i,j,a[i][j]});
//					cerr<<n+i<<" "<<j<<' '<<a[i][j]<<endl;
				}
			}
		}
		int cnt=1;
//		cout<<q.size()<<endl;
		while(cnt<wt){
//			cout<<cnt<<' '<<wt<<' '<<q.size()<<endl;
//			if(!q.size())break;
			edge o=q.top();
			q.pop();
			int fa=find(o.u),fb=find(o.v);
//			cout<<o.u<<' '<<o.v<<endl;
			if(fa!=fb){
				res+=o.w;
//				cout<<res<<endl;
				cnt++;
				f[fa]=fb;
			}
		}
//		cerr<<ans<<endl;
		ans=min(ans,res);
		if(1.0*clock()/CLOCKS_PER_SEC>0.9)break;
	}
		
	cout<<ans<<endl;
	
	return 0;
}
/*
首先乡村可以看作中转站 
然后中转会有费用 
观察到乡村很少 
能不能枚举用或者不用这个乡村的联通的最小值 

有 1024 种选法 
然后接下来复杂度肯定要炸，因为 m 太大了 
先想想 k=0 怎么做 
由于不会走重复的边，最后的一定是树所以。。。 
是最小生成树！！！ 
假如我们先求出来了最小生成树 
没法做 
上面有 48 分 
接着，乡村边就全部加上 c 
如果检测到了用过，就全减去 c 
相当于每用一条乡村边，就重新加入同一乡村的其他边 
再加入一次不影响正确性 
但是时间？ 
还是 10^6 log 10^6 多一点 
等等，但是存不下两两连接的边 
只有 72 分 
所以乡村边怎么解决？ 
如果每一次只记录最小的，然后如果没有连上，就直接换次小的 
这样肯定能被卡，但是相信 ccf 的数据 
算了，先想正解 
如果我们把乡村点也算进树里面？ 不太对啊 
或者开两个优先队列，分乡村边和城市边 
感觉还是需要判断是否要连接乡村 
假如每一次都需要付出重修乡村的费用 这样怎么做？ 不好做 
或者能不能精简一点乡村边 即使这样也要枚举 5*10^8 
等一下，有一个性质，一个乡村最多用 n 条路 
先把能用的处理出来就行了，相当于先对乡村做一遍最小生成树 
还得看写法 
因为边太多了，怎么判断谁是最短的 
但是这时候的连通图就是要包含乡村的了 
不行，还是不能包含乡村 
但是还是有问题，因为可能一个 c 能帮助很多点 
完了。 
能不能这样：判断加入这个乡村后会不会更优，如果会，直接保留 
然后枚举 10 下 
接下来怎么办？ 
不行了 
只能尝试枚举选不选每一个 c 
感觉会 TLE 
那就先选出一定会用的边？ 
感觉也不一定是最小生成树上的边 
好像一定是 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


4 4 10
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
1 1 8 2 4
100 1 3 2 4
1 1 8 2 4
100 1 3 2 4
1 1 8 2 4
100 1 3 2 4
1 1 8 2 4
100 1 3 2 4

现在主要是会 TLE 


*/